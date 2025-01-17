#!/usr/bin/env python
'''
@file ndk_esl_ap.py

@brief Nordic ESL AP shell commands

Copyright (C) Atmosic 2024-2025
'''

import sys
import serial
import time
import argparse
import subprocess

TIMEOUT = 10
SYNC_TIMEOUT = 20
RESET_TIMEOUT = 3
MAX_RETRIES = 3

ser = None
id_ser_short = None

def reset_device():
    command = ['nrfutil', 'device', 'reset', '--serial-number', id_ser_short]
    try:
        result = subprocess.run(command, capture_output=True, text=True, check=True)
        print("reset_device...")
        time.sleep(RESET_TIMEOUT)
    except subprocess.CalledProcessError as e:
        print(f"Error occurred: {e.stderr}")
        raise Exception("Reset nrf device failed")

def send_and_check_response(command, expected_response, timeout=TIMEOUT):
    tries = 0
    while tries < MAX_RETRIES:
        tries += 1
        start_time = time.time()
        ser.write(command.encode())
        print(f"Sent: {command}")
        while time.time() - start_time < timeout:
            if ser.in_waiting > 0:
                response = ser.readline().decode('utf-8').strip()
                print(f"Received: {response}")

                if expected_response in response:
                    print("Received expected response!")
                    return
            time.sleep(0.1)
        print(f"Retry times: {tries}")
    print(f"Timeout waiting for response. Expected: {expected_response}")
    raise Exception("Timeout")

def exe_cmds(commands):
    for command, expected_response in commands:
        try:
            send_and_check_response(command, expected_response)
        except Exception as e:
            raise Exception(f"Timeout while sending: {command}")

def unbond():
    try:
        reset_device()
        send_and_check_response("esl_c reset_ap\n", "esl_c reset_ap")
    except:
        print(f"Error unbond: {e}")

def discovery(associated=False):
    cmd = "esl_c esl_c tag_state\n"
    if associated:
        expected = "state:unsynchronized"
    else:
        expected = "state:unassociated"
    try:
        send_and_check_response(cmd, expected)
    except Exception as e:
        raise Exception(f"Timeout while sending: {cmd}")

def main():
    parser = argparse.ArgumentParser(description='ESL test')
    parser.add_argument('-p', '--port', dest='port', help='serial port',
        required=True)
    parser.add_argument('-s', '--short', dest='short', help='id serial short',
        required=True)
    args = parser.parse_args()
    global id_ser_short
    id_ser_short = args.short
    global ser
    try:
        ser = serial.Serial(args.port, 115200, timeout=TIMEOUT)
    except serial.SerialException as e:
        print(f"Error opening serial port: {e}")
        sys.exit(1)

    try:
        unbond()
        reset_device()
        discovery(False)
        commands = [
            # turn on auto synchronization
            ("esl_c auto_ap 1\n", "state:synchronized"),
            # turn off auto synchronization
            ("esl_c auto_ap 0\n", "New ESL_AP_AUTO_MODE 0"),
            # read sensor data
            ("esl_c pawr push_sync_buf 0 100000\n", "#SLOT:0,0x0b348e00"),
            # create acl connection
            ("esl_c acl connect_esl 0 0\n", "#DISCOVERY"),
            # upload image data 0
            ("esl_c obj_c write 0 0 0\n", "#OTS_WRITTEN"),
            # upload image data 1
            ("esl_c obj_c write 0 1 1\n", "#OTS_WRITTEN"),
            # update complete cmd
            ("esl_c update_complete 0 0 0\n", "esl_c update_complete 0 0 0"),
            # past procedure
            ("esl_c acl past 0\n", "state:synchronized"),
            # update image
            ("esl_c pawr push_sync_buf 0 20000000\n", "#SLOT:0,0x0434110000"),
            # display timed image w/ abs_time > max
            ("esl_c pawr push_sync_buf 0 60000000FFFFFFFF\n", "#SLOT:0,0x0334000c"),
            # display timed image w/ abs_time = 150s
            ("esl_c pawr push_sync_buf 0 60000000F0480200\n", "#SLOT:0,0x0434110000"),
            # 2nd display timed image cmd -> queue full
            ("esl_c pawr push_sync_buf 0 60000000F0470200\n", "#SLOT:0,0x0334000b"),
            # replace display timed image
            ("esl_c pawr push_sync_buf 0 60000001F0480200\n", "#SLOT:0,0x0434110001"),
            # ping cmd -> basic state = sync bit | pending display bit
            ("esl_c pawr push_sync_buf 0 0000\n", "#SLOT:0,0x0434101200"),
            # delete pending display timed image cmd
            ("esl_c pawr push_sync_buf 0 6000000000000000\n", "#SLOT:0,0x0434110000"),
            # ping cmd -> basic state = sync bit
            ("esl_c pawr push_sync_buf 0 0000\n", "#SLOT:0,0x0434100200"),
            # display timed image
            ("esl_c pawr push_sync_buf 0 60000001F0480200\n", "#SLOT:0,0x0434110001"),
        ]
        exe_cmds(commands)
        reset_device()

        # wait for ESL synchronization state timeout
        time.sleep(SYNC_TIMEOUT)

        discovery(True)
        exe_cmds(commands)
        # unassociate ESL from AP
        send_and_check_response("esl_c pawr push_sync_buf 0 010000\n", "#SLOT:0,0x0434100000")
    except Exception as e:
        print(f"Caught an exception: {e}")
        sys.exit(1)
    finally:
        reset_device()
        if ser:
            ser.close()

if __name__ == "__main__":
    main()
