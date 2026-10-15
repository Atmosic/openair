#!/usr/bin/env python3
# Copyright (c) 2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

"""
@file pytest/conftest.py

@brief Pytest configuration for APx525 PDM/DMIC bench validation.

This module registers custom command line options for pytest and the
fixtures wrapping the APx500 instrument control module (apx_control.py,
alongside this file).

"""

import pytest

try:
    from apx_control import ApxPdmMonitor

    APX_CONTROL_AVAILABLE = True
except ImportError:
    APX_CONTROL_AVAILABLE = False


def _parse_float_list(text):
    """Parse a comma-separated string of numbers into a list of floats."""
    return [float(x) for x in str(text).split(",") if x.strip() != ""]


def pytest_addoption(parser):
    """Register custom command line options."""
    parser.addoption(
        "--apx-api-dir",
        default=r"C:\Program Files\Audio Precision\APx500 9.3\API",
        help="Path to the APx500 API .NET assemblies (AudioPrecision.API2.dll)",
    )
    parser.addoption(
        "--apx-bit-clk-freq-hz",
        type=float,
        default=1000000.0,
        help="Expected PDM bit clock (Hz) the DUT drives.",
    )
    parser.addoption(
        "--apx-project",
        default=None,
        help="Optional .approjx project to load instead of auto-configuring.",
    )
    parser.addoption(
        "--apx-peak-floor-dbfs",
        type=float,
        default=-80.0,
        help="Minimum DUT-reported peak level (dBFS) to consider a real signal received from APx.",
    )
    parser.addoption(
        "--apx-sweep-freqs-hz",
        default="500,1000,1500",
        help="Comma-separated APx generator tone frequencies (Hz) to sweep.",
    )
    parser.addoption(
        "--apx-sweep-levels-dbfs",
        default="-20,-6",
        help="Comma-separated APx generator levels (dBFS) to sweep.",
    )
    parser.addoption(
        "--apx-max-dropped",
        type=int,
        default=0,
        help="Maximum dmic_read() failures (dropped blocks) tolerated before failing.",
    )
    parser.addoption(
        "--apx-freq-tolerance-pct",
        type=float,
        default=1.0,
        help="Allowed +/- percent deviation of APx-recovered frequency from setpoint.",
    )
    parser.addoption(
        "--apx-max-thdn-pct",
        type=float,
        default=1.0,
        help="Maximum THD+N ratio (%) the APx-recovered tone may exhibit before failing.",
    )
    parser.addoption(
        "--apx-level-tolerance-db",
        type=float,
        default=3.0,
        help="Allowed +/- deviation (dB) of APx-recovered RMS level from setpoint.",
    )
    parser.addoption(
        "--apx-noise-floor-500khz-dbfs",
        type=float,
        default=-68.0,
        help="Maximum allowed noise floor (dBFS) for PDM bit clocks <= 500 kHz.",
    )
    parser.addoption(
        "--apx-noise-floor-2mhz-dbfs",
        type=float,
        default=-80.0,
        help="Maximum allowed noise floor (dBFS) for PDM bit clocks > 500 kHz and <= 2 MHz.",
    )
    parser.addoption(
        "--apx-noise-floor-4mhz-dbfs",
        type=float,
        default=-85.0,
        help="Maximum allowed noise floor (dBFS) for PDM bit clocks > 2 MHz.",
    )
    parser.addoption(
        "--apx-silence-relax-db",
        type=float,
        default=5.0,
        help="Extra margin (dB) added to the noise-floor tier when checking the silence point.",
    )
    parser.addoption(
        "--apx-ready-regex",
        default=r"Bench streaming started",
        help="Regex the DUT prints once PDM capture is actively streaming.",
    )
    parser.addoption(
        "--apx-ready-timeout",
        type=float,
        default=10.0,
        help="Seconds to wait for the DUT ready regex before failing",
    )
    parser.addoption(
        "--apx-capture-timeout",
        type=float,
        default=90.0,
        help="Seconds to wait for the DUT raw-capture markers and hex dump before failing.",
    )


def _noise_floor_dbfs_for_bit_clk(bit_clk_freq_hz, config):
    """Select the noise-floor threshold (dBFS) tier for the given PDM bit
    clock (see --apx-noise-floor-*-dbfs help for the rationale)."""
    if bit_clk_freq_hz <= 500000.0:
        return config.getoption("--apx-noise-floor-500khz-dbfs")
    if bit_clk_freq_hz <= 2000000.0:
        return config.getoption("--apx-noise-floor-2mhz-dbfs")
    return config.getoption("--apx-noise-floor-4mhz-dbfs")


@pytest.fixture(scope="function")
def apx_settings(request):
    """Bundle the APx-related CLI options for the test."""
    bit_clk_freq_hz = request.config.getoption("--apx-bit-clk-freq-hz")
    return {
        "api_dir": request.config.getoption("--apx-api-dir"),
        "project": request.config.getoption("--apx-project"),
        "peak_floor_dbfs": request.config.getoption("--apx-peak-floor-dbfs"),
        "bit_clk_freq_hz": bit_clk_freq_hz,
        "sweep_freqs_hz": _parse_float_list(
            request.config.getoption("--apx-sweep-freqs-hz")
        ),
        "sweep_levels_dbfs": _parse_float_list(
            request.config.getoption("--apx-sweep-levels-dbfs")
        ),
        "max_dropped": request.config.getoption("--apx-max-dropped"),
        "freq_tolerance_pct": request.config.getoption("--apx-freq-tolerance-pct"),
        "level_tolerance_db": request.config.getoption("--apx-level-tolerance-db"),
        "max_thdn_pct": request.config.getoption("--apx-max-thdn-pct"),
        "noise_floor_dbfs": _noise_floor_dbfs_for_bit_clk(
            bit_clk_freq_hz, request.config
        ),
        "silence_relax_db": request.config.getoption("--apx-silence-relax-db"),
        "ready_regex": request.config.getoption("--apx-ready-regex"),
        "ready_timeout": request.config.getoption("--apx-ready-timeout"),
        "capture_timeout": request.config.getoption("--apx-capture-timeout"),
    }


@pytest.fixture(scope="function")
def apx_monitor(apx_settings):  # pylint: disable=redefined-outer-name
    """Initialize (and clean up) the APx500 PDM monitor for one test."""
    if not APX_CONTROL_AVAILABLE:
        pytest.skip("apx_control module not available (pythonnet missing?)")

    monitor = ApxPdmMonitor(
        api_dir=apx_settings["api_dir"],
        target_bit_clk_hz=apx_settings["bit_clk_freq_hz"],
    )
    if not monitor.init(project_path=apx_settings["project"]):
        pytest.skip(
            "Failed to initialize APx500 - is it installed/licensed on this bench?"
        )

    yield monitor

    monitor.disconnect()
