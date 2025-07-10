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
import threading

TIMEOUT = 10
SYNC_TIMEOUT = 20
RESET_TIMEOUT = 3
MAX_RETRIES = 3

ser = None
ser_log = None
id_ser_short = None
terminate_event = threading.Event()

exception_list = [
    "<err> esl_display: esl_display_write_ctx ",
    "<err> esl_display: esl_display_image display error:-128",
    "<err> bt_esls: esls_display_handler err:-128",
    "<err> bt_esls: unexp opcode:0",
    "<err> bt_scan: Unknown handle 0x0000 for periodic advertising report",
    "<err> bt_esls: Security failed",
]

esl_c_test_commands = [
    # turn on auto synchronization
    ("esl_c auto_ap 1\n", "state:synchronized"),
    # turn off auto synchronization
    ("esl_c auto_ap 0\n", "New ESL_AP_AUTO_MODE 0"),
    # read sensor data (esl_c pawr push_sync_buf <group_id)> <OPCODE ESL_ID Sensor_Index>)
    ("esl_c pawr push_sync_buf 0 100000\n", "#SLOT:0,0x0b348e00"),
    # create acl connection (esl_c acl connect_esl <group_id ESL_ID>)
    ("esl_c acl connect_esl 0000\n", "#DISCOVERY"),
    # upload image data 0 (esl_c obj_c write <conn_idx> <tag_img_idx> <stored image idx>)
    ("esl_c obj_c write 0 0 0\n", "#OTS_WRITTEN"),
    # upload image data 1
    ("esl_c obj_c write 0 1 1\n", "#OTS_WRITTEN"),
    # update complete cmd (esl_c update_complete <conn_idx> <group_id ESL_ID>)
    ("esl_c update_complete 0 0000\n", "esl_c update_complete 0 0000"),
    # past procedure (esl_c acl past <conn_idx>)
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
    # delete pending display timed image cmd
    ("esl_c pawr push_sync_buf 0 6000000000000000\n", "#SLOT:0,0x0434110000"),
    # LED control led0 always ON
    ("esl_c pawr push_sync_buf 0 B0000033000000000000000100\n", "#SLOT:0,0x03340100"),
    # ping cmd -> basic state = sync bit | active LED
    ("esl_c pawr push_sync_buf 0 0000\n", "#SLOT:0,0x0434100600"),
    # LED control led0 OFF
    ("esl_c pawr push_sync_buf 0 B0000033000000000000000000\n", "#SLOT:0,0x03340100"),
    # ping cmd -> basic state = sync bit
    ("esl_c pawr push_sync_buf 0 0000\n", "#SLOT:0,0x0434100200"),
    # LED control led0 repeat 30 times
    ("esl_c pawr push_sync_buf 0 B0000033AA00AA00AA02153200\n", "#SLOT:0,0x03340100"),
    # ping cmd -> basic state = sync bit | active LED
    ("esl_c pawr push_sync_buf 0 0000\n", "#SLOT:0,0x0434100600"),
    # LED control led0 OFF
    ("esl_c pawr push_sync_buf 0 B0000033000000000000000000\n", "#SLOT:0,0x03340100"),
    # LED control led0 timed control w/ abs_time > max
    ("esl_c pawr push_sync_buf 0 F0000033000000000000000100FFFFFFFF\n", "#SLOT:0,0x0334000c"),
    # LED control led0 timed control
    ("esl_c pawr push_sync_buf 0 F0000033000000000000000100400D0300\n", "#SLOT:0,0x03340100"),
    # ping cmd -> basic state = sync bit | pending LED bit
    ("esl_c pawr push_sync_buf 0 0000\n", "#SLOT:0,0x0434100a00"),
    # LED control 2nd LED0 timed control cmd -> queue full
    ("esl_c pawr push_sync_buf 0 F000003300000000000000010050340300\n", "#SLOT:0,0x0334000b"),
    # LED control delete pending LED0 timed control cmd
    ("esl_c pawr push_sync_buf 0 F000003300000000000000010000000000\n", "#SLOT:0,0x03340100"),
    # ping cmd -> basic state = sync bit
    ("esl_c pawr push_sync_buf 0 0000\n", "#SLOT:0,0x0434100200"),
]

factory_reset_commands = [
    # create acl connection
    ("esl_c acl connect_esl 0000\n", "#DISCOVERY"),
    # factory reset (esl_c factory <conn_idx>)
    ("esl_c factory 0\n", "Disconnected"),
]

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
        if terminate_event.is_set():
            return
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

test_cmd_list = [
    lambda: unbond(),
    lambda: reset_device(),
    lambda: discovery(False),
    lambda: exe_cmds(esl_c_test_commands),
    lambda: exe_cmds(factory_reset_commands),
    lambda: unbond(),
     #---------------------------------------------
    lambda: reset_device(),
    lambda: discovery(False),
    lambda: exe_cmds(esl_c_test_commands),
     #---------------------------------------------
    lambda: reset_device(),
    # wait for ESL synchronization state timeout
    lambda: time.sleep(SYNC_TIMEOUT),
    lambda: discovery(True),
    lambda: exe_cmds(esl_c_test_commands),
    lambda: send_and_check_response("esl_c pawr push_sync_buf 0 010000\n", "#SLOT:0,0x0434100000")
]

def esl_test_task():
    for command_lambda in test_cmd_list:
        if terminate_event.is_set():
            return False
        try:
            command_lambda()
        except Exception as e:
            print(f"Caught an exception: {e}")
            return False
    return True

def monitor_serial_port(ser, exception_list):
    """Monitor the serial port for output and detect errors."""
    while not terminate_event.is_set():
        try:
            line = ser.readline().decode('utf-8', errors='ignore').strip()
            if not line:
                continue
            print(f"{line}")
            line_lower = line.lower()
            has_err_tag = '<err>' in line_lower
            if has_err_tag:
                is_exception = any(ex.lower() in line_lower for ex in exception_list)
                if not is_exception:
                    print(f"Error log >>>>>>>>>>> '{line}'\n")
                    terminate_event.set()
                    break
        except Exception as read_err:
            print(f"monitor_serial_port read error: {read_err}")

def close_serials():
    if ser:
        ser.close()
    if ser_log:
        ser_log.close()

def parsing_args():
    parser = argparse.ArgumentParser(description='ESL test')
    parser.add_argument('-p', '--port', dest='port', help='serial port',
        required=True)
    parser.add_argument('-s', '--short', dest='short', help='id serial short',
        required=True)
    parser.add_argument('-e', '--esltaglogport', dest='esltaglogport', help='ESL tag console log port',
        required=True)
    return parser.parse_args()

if __name__ == "__main__":
    # Parsing arguments
    args = parsing_args()

    # Set arguments values
    id_ser_short = args.short
    try:
        ser = serial.Serial(args.port, 115200, timeout=TIMEOUT)
    except serial.SerialException as e:
        print(f"Error opening serial port: {e}")
        sys.exit(1)

    try:
        ser_log = serial.Serial(args.esltaglogport, 115200, timeout=TIMEOUT)
    except serial.SerialException as e:
        print(f"Error opening serial port (ser_log): {e}")
        close_serials()
        sys.exit(1)

    # Initialize the monitoring thread
    monitor_thread = threading.Thread(
        target=monitor_serial_port,
        args=(ser_log, exception_list),
        daemon=True
    )
    monitor_thread.start()
    time.sleep(0.5)

    # Start main ESL test task
    result = esl_test_task()

    reset_device()

    # Stop all threads
    terminate_event.set()
    monitor_thread.join()

    # Close serial ports
    close_serials()

    if not result:
        print("ESL test failed! \n")
        sys.exit(1)
