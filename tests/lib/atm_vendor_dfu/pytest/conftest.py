# Copyright (c) 2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

"""Pytest fixtures for the atm_vendor_dfu end-to-end DFU swap test."""

from __future__ import annotations

import logging
import os
import re
import shutil
import subprocess
import tempfile
from pathlib import Path

import pytest
import serial
import yaml

from dfu_host import DEFAULT_BAUD_RATE, DEFAULT_RESPONSE_TIMEOUT_S, DfuHost

logger = logging.getLogger(__name__)

V2_VERSION = "2.0.0"
V3_VERSION = "3.0.0"
SKIP_CACHE_KEYS = {
    "TC_NAME",
    "TC_RUNID",
    "EXTRA_GEN_EDT_ARGS",
    "ZEPHYR_TOOLCHAIN_VARIANT",
    "Python3_EXECUTABLE",
}


def pytest_addoption(parser):
    """Add command line options for the DFU pytest harness."""
    parser.addoption("--dfu-mode", choices=["single", "dual"], default="single")
    parser.addoption("--dfu-serial", default=None)
    parser.addoption("--dfu-baud", type=int, default=DEFAULT_BAUD_RATE)
    parser.addoption("--dfu-timeout", type=float, default=DEFAULT_RESPONSE_TIMEOUT_S)
    parser.addoption("--v2-bin", default=None, help="Pre-built v2 image path")
    parser.addoption("--v3-bin", default=None, help="Pre-built v3 image path")


def _board_string(build_info: dict) -> str:
    board = build_info["cmake"]["board"]
    name = board["name"]
    revision = board.get("revision")
    qualifiers = board.get("qualifiers")
    if revision:
        name = f"{name}@{revision}"
    if qualifiers:
        name = f"{name}/{qualifiers}"
    return name


def _parse_sysbuild_args(cache_path: Path) -> list[str]:
    args: list[str] = []
    cli_re = re.compile(r"^CLI_(.+?):INTERNAL=(.*)$")
    user_re = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*):UNINITIALIZED=(.*)$")
    for raw in cache_path.read_text().splitlines():
        m = cli_re.match(raw)
        if m:
            args.append(f"-D{m.group(1)}={m.group(2)}")
            continue
        m = user_re.match(raw)
        if m and m.group(1) not in SKIP_CACHE_KEYS:
            args.append(f"-D{m.group(1)}={m.group(2)}")
    return args


def _override(args: list[str], prefix: str, value: str) -> list[str]:
    kept = [a for a in args if not a.startswith(prefix)]
    kept.append(f"{prefix}{value}")
    return kept


def _find_image(v2_dir: Path, mode: str) -> Path:
    candidates = [
        v2_dir / "atm_vendor_dfu" / "zephyr" / "combined_fw_upd.bin",
        v2_dir / "atm_vendor_dfu" / "zephyr" / "zephyr.signed.bin",
    ]
    if mode == "single":
        candidates.reverse()
    for path in candidates:
        if path.exists():
            return path
    raise FileNotFoundError(f"No v2 image under {v2_dir}")


def _build_versioned_image(request, device_object, version: str) -> Path:
    """Build a signed test image at *version* and return its path."""
    build_dir = Path(device_object.device_config.build_dir)
    info = yaml.safe_load((build_dir / "build_info.yml").read_text())
    src_dir = next(
        Path(img["source-dir"])
        for img in info["cmake"]["images"]
        if img["type"] == "MAIN"
    )
    cache = next(build_dir.glob("*_sysbuild_cache.txt"))
    args = _parse_sysbuild_args(cache)
    args = _override(
        args,
        "-Datm_vendor_dfu_CONFIG_ATM_VENDOR_DFU_TEST_APP_VERSION=",
        f'"{version}"',
    )
    args = _override(
        args,
        "-Dmcuboot_CONFIG_MCUBOOT_IMGTOOL_SIGN_VERSION=",
        f'"{version}"',
    )
    out_dir = Path(tempfile.mkdtemp(prefix=f"atm_dfu_{version}_"))
    cmd = [
        "west",
        "build",
        "-p",
        "always",
        "-d",
        str(out_dir),
        "-b",
        _board_string(info),
        "--sysbuild",
        str(src_dir),
        "--",
        *args,
    ]
    logger.info("Building v%s image: %s", version, " ".join(cmd))
    subprocess.run(cmd, check=True)
    image = _find_image(out_dir, request.config.getoption("--dfu-mode"))
    logger.info("v%s image: %s (%d bytes)", version, image, image.stat().st_size)
    request.addfinalizer(lambda: shutil.rmtree(out_dir, ignore_errors=True))
    return image


@pytest.fixture(scope="session")
def v2_image(request, device_object) -> Path:  # pylint: disable=redefined-outer-name
    """Build (or accept) the v2 signed image for the first swap."""
    explicit = request.config.getoption("--v2-bin")
    if explicit:
        return Path(explicit)
    return _build_versioned_image(request, device_object, V2_VERSION)


@pytest.fixture(scope="session")
def v3_image(request, device_object) -> Path:  # pylint: disable=redefined-outer-name
    """Build (or accept) the v3 signed image for the second consecutive swap."""
    explicit = request.config.getoption("--v3-bin")
    if explicit:
        return Path(explicit)
    return _build_versioned_image(request, device_object, V3_VERSION)


@pytest.fixture(scope="session")
def dfu_serial_port(request) -> str:
    """Resolve the raw DFU UART port (uart0 / if00 on ATM34 EVK)."""
    port = request.config.getoption("--dfu-serial")
    if not port:
        port = os.environ.get("ZEPHYR_DFU_UART") or os.environ.get("ZEPHYR_UART0")
    if not port:
        pytest.skip("DFU UART not provided (--dfu-serial / ZEPHYR_DFU_UART)")
    return port


@pytest.fixture
def dfu_host(request, dfu_serial_port):  # pylint: disable=redefined-outer-name
    """Provide an opened DFU host helper for one test."""
    baud = request.config.getoption("--dfu-baud")
    timeout = request.config.getoption("--dfu-timeout")
    host = DfuHost(dfu_serial_port, baud=baud, timeout=timeout)
    try:
        host.open()
    except (serial.SerialException, OSError) as exc:
        pytest.skip(f"Cannot open DFU UART {dfu_serial_port}: {exc}")
    host.clear_input()
    try:
        yield host
    finally:
        host.close()
