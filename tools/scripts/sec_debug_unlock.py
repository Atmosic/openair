#!/usr/bin/env python
"""
@file sec_debug_unlock.py

@brief Secure Debug Authentication tool

Copyright (C) Atmosic 2023-2025
"""

import serial
import argparse
import base64
import sys
from cryptography.hazmat.backends import default_backend
from cryptography.hazmat.primitives import serialization
from cryptography.hazmat.primitives.asymmetric import ec
from cryptography.hazmat.primitives.hashes import SHA256
from cryptography.hazmat.primitives.asymmetric.utils import decode_dss_signature

MAX_RETRIES = 5
TIMEOUT = 1

DEVICE_STRING_UNLOCKED = b"Debug unlocked"
DEVICE_STRING_CHALLENGE = b"Challenge:"
DEVICE_STRING_STATIC_CHALLENGE = b"Static Challenge:"

DEVICE_COMMAND_REQUEST = b"DBG REQUEST\n"
DEVICE_COMMAND_RESPONSE = b"DBG RESPONSE"
DEVICE_COMMAND_STATIC_RESPONSE = b"DBG STATIC_RESPONSE"

verbose = False


# helper functions
def verbose_print(*args, **kwargs):
    global verbose
    if verbose:
        print(*args, **kwargs)


def send(ser, command):
    tries = 0
    ser.reset_input_buffer()
    ser.reset_output_buffer()
    verbose_print("Sending:", command)
    while tries < MAX_RETRIES:
        ser.write(command)
        response = ser.readline()
        # all commands respond in a string ending in a newline
        if response and b"\n" in response:
            verbose_print("Received:", response)
            return response
        tries += 1
    raise Exception("Timeout")


def load_key(keyfile, passwd):
    raw_key = keyfile.read()
    key = serialization.load_pem_private_key(
        raw_key, password=passwd, backend=default_backend()
    )
    if isinstance(key, ec.EllipticCurvePrivateKey):
        if key.curve.name != "secp256r1":
            raise Exception("Unsupported EC curve: " + key.curve.name)
        if key.key_size != 256:
            raise Exception("Unsupported EC size: " + key.key_size)
    return key


def sign(key, challenge):
    sig = key.sign(data=challenge, signature_algorithm=ec.ECDSA(SHA256()))
    r, s = decode_dss_signature(sig)
    signature = r.to_bytes(int(key.key_size / 8), "big") + s.to_bytes(
        int(key.key_size / 8), "big"
    )
    return signature


# Device interfacing functions
def unlock(ser, key, response, static=False):
    challenge = base64.b64decode(response.strip().split()[-1])
    signature = sign(key, challenge)
    if static:
        cmd_rsp = DEVICE_COMMAND_STATIC_RESPONSE
    else:
        cmd_rsp = DEVICE_COMMAND_RESPONSE
    status = send(ser, cmd_rsp + b" " + base64.b64encode(signature) + b"\n")
    return status.strip() == DEVICE_STRING_UNLOCKED


def command_unlock(args):
    with serial.Serial(args.port, args.baud, timeout=TIMEOUT) as ser:
        key = load_key(args.key, args.passwd)
        # request a challenge
        response = send(ser, DEVICE_COMMAND_REQUEST)
        if response[0 : len(DEVICE_STRING_CHALLENGE)] == DEVICE_STRING_CHALLENGE:
            print("Unlock Challenge")
            return unlock(ser, key, response)
        elif (
            response[0 : len(DEVICE_STRING_STATIC_CHALLENGE)]
            == DEVICE_STRING_STATIC_CHALLENGE
        ):
            print("Unlock Static Challenge")
            return unlock(ser, key, response, True)
        else:
            print("Unknow Unlock Type")
            return False


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Unlock device debug port")
    parser.add_argument(
        "-k",
        "--key",
        dest="key",
        help="debug private key pem file",
        required=True,
        type=argparse.FileType("rb"),
    )
    parser.add_argument("--password", dest="passwd", help="private key password")
    parser.add_argument("-p", "--port", dest="port", help="serial port", required=True)
    parser.add_argument(
        "-b",
        "--baud",
        dest="baud",
        help="baud rate",
        required=False,
        default=115200,
        type=int,
    )
    parser.add_argument(
        "-v",
        "--verbose",
        dest="verbose",
        help="show device traffic",
        action="store_true",
    )
    args = parser.parse_args()
    if hasattr(args, "verbose") and args.verbose:
        verbose = True
    if not command_unlock(args):
        sys.exit(1)
