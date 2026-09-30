# Copyright (c) Atmosic 2026
#
# SPDX-License-Identifier: LicenseRef-Atmosic

"""
@file atm_reset_extension.py

@brief West extension to reset a connected Atmosic EVK.
"""

import argparse
import os
import sys
from textwrap import dedent

from west.commands import (  # pylint: disable=import-error,no-name-in-module
    WestCommand,
    Verbosity,
)

# atm_openocd lives next to the other host tools (openair/tools/scripts).
sys.path.append(
    os.path.join(
        os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "tools", "scripts"
    )
)
# pylint: disable=wrong-import-position,wrong-import-order,import-error
import atm_openocd


class AtmResetCommand(WestCommand):
    """West extension command to reset a connected Atmosic EVK."""

    def __init__(self):
        super().__init__(
            "atm_reset",  # gets stored as self.name
            "Reset a connected Atmosic EVK",  # self.help
            # self.description:
            dedent(
                """
                Reset a connected Atmosic EVK over OpenOCD (no flashing).

                Triggers a hard reset so the firmware already on the device
                re-runs -- equivalent to the reset step of `west flash`.

                The chip-specific OpenOCD target config is located from --board
                (preferred) or supplied directly with --openocd_config.

                Examples:
                  west atm_reset --device ATMEVK10800073 --board ATMEVK-5205-NQK-2
                  west atm_reset --device 000900066446 --jlink \\
                      --board ATMEVK-3405-WQK-5
                """
            ),
        )
        self.openocd = None

    def do_add_parser(self, parser_adder):
        """Add parser for the atm_reset command."""
        parser = parser_adder.add_parser(
            self.name,
            help=self.help,
            description=self.description,
            formatter_class=argparse.RawDescriptionHelpFormatter,
        )
        parser.add_argument(
            "--device",
            required=True,
            help="selects FTDI interface, e.g: ATRDIxxxx / ATMEVKxxxx, "
            "or the J-Link serial",
        )
        parser.add_argument(
            "--jlink",
            required=False,
            action="store_true",
            help="if using JLINK (otherwise FTDI)",
        )
        parser.add_argument(
            "--dl",
            required=False,
            action="store_true",
            help="if using a DL board (FTDI only)",
        )
        parser.add_argument(
            "--board",
            required=False,
            default=None,
            help="board name (with optional revision) used to locate the "
            "OpenOCD config, e.g: ATMEVK-3405-WQK-5",
        )
        parser.add_argument(
            "--openocd_config",
            required=False,
            default=None,
            help="explicit OpenOCD config file (overrides --board lookup)",
        )
        return parser

    def _run_step(self, label, result):
        """Print the (returncode, stdout, stderr) tuple from an AtmOpenOCD call
        and abort on a non-zero return code."""
        returncode, stdout, stderr = result
        if self.verbosity >= Verbosity.DBG:  # -v: show the raw openocd chatter
            if stdout:
                self.inf(stdout.rstrip())
            if stderr:
                self.inf(stderr.rstrip())
        if returncode != 0:
            self.err(f"{label} failed (exit code {returncode})")
            if stderr:
                self.err(stderr.rstrip())
            sys.exit(1)

    def do_run(self, args, unknown_args):  # pylint: disable=unused-argument
        """Execute the atm_reset command."""
        if not args.board and not args.openocd_config:
            self.die(
                "need a target OpenOCD config: pass --board <board> (to look it "
                "up) or --openocd_config <file>."
            )

        # Set up the OpenOCD connection (locates the atm openocd binary, infers
        # the config from --board if needed, and builds the SWDIF / *_SERIAL env).
        try:
            self.openocd = atm_openocd.AtmOpenOCD(
                args.board,
                args.device,
                args.jlink,
                args.dl,
                openocd_cfg=args.openocd_config,
            )
        except Exception as err:  # pylint: disable=broad-exception-caught
            self.die(f"cannot set up OpenOCD for the device: {err}")

        iface = "JLINK" if args.jlink else "FTDI"
        self.inf(f"Resetting device {args.device} ({iface}) ...")

        # FTDI needs an extra step to drive the reset GPIO first (matches the
        # atmisp runner's do_reset_target()); J-Link does not.
        if not args.jlink:
            self._run_step("reset (FTDI GPIO)", self.openocd.reset_target())

        # Connect SWD and trigger a hard reset on exit so the firmware re-runs.
        self._run_step("reset", self.openocd.execute_cmd(["set _RESET_HARD_ON_EXIT 1"]))

        self.inf(f"Device {args.device} reset complete")
