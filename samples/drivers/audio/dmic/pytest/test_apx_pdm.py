#!/usr/bin/env python3
# Copyright (c) 2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

"""
@file pytest/test_apx_pdm.py
@brief PDM/DMIC bench capture using an APx525 analyzer.
"""

import json
import logging
import math
import re
import subprocess
import wave
from pathlib import Path

import numpy as np

from twister_harness import DeviceAdapter  # pylint: disable=import-error

from apx_control import (  # pylint: disable=import-error
    PDM_GEN_FREQUENCY_HZ,
    PDM_SILENCE_LEVEL_DBFS,
)

logger = logging.getLogger(__name__)

_BEGIN_RE = re.compile(
    r"PDM_CAPTURE_BEGIN rate=(?P<rate>\d+) bits=(?P<bits>\d+) "
    r"samples=(?P<samples>\d+)"
)
_END_RE = re.compile(
    r"PDM_CAPTURE_END captured=(?P<captured>\d+) " r"dropped=(?P<dropped>\d+)"
)
_HEX_LINE_RE = re.compile(r"^[0-9a-fA-F]{4}(?: [0-9a-fA-F]{4})*$")


def _pct_diff(measured: float, expected: float) -> float:
    """Return the absolute percent deviation of measured from expected."""
    if expected == 0:
        return float("inf") if measured != 0 else 0.0
    return abs(measured - expected) / expected * 100.0


def _decode_hex_samples(lines) -> np.ndarray:
    """Decode DUT hex-dump lines into an int16 PCM array."""
    raw = []
    for line in lines:
        tok = line.strip()
        if not _HEX_LINE_RE.match(tok):
            continue
        raw.extend(int(t, 16) for t in tok.split())
    u16 = np.asarray(raw, dtype=np.uint16)
    return u16.astype(np.int16)


def _reset_dut(dut: DeviceAdapter):  # pylint: disable=redefined-outer-name
    """Reset the DUT via 'west flash --reset_only' (no reflash)."""
    device_config = dut.device_config
    device_id = device_config.id
    if not device_id:
        for arg in device_config.west_flash_extra_args:
            if arg.startswith("--device="):
                device_id = arg.split("=", 1)[1]
                break
    if not device_id:
        raise RuntimeError("Could not determine device id for reset")

    command = [
        dut.west,
        "flash",
        "--no-rebuild",
        "--build-dir",
        str(device_config.build_dir),
        "--",
        f"--device={device_id}",
        "--reset_only",
    ]
    if "--jlink" in device_config.west_flash_extra_args:
        command.append("--jlink")

    logger.info("Resetting DUT: %s", command)
    dut.clear_buffer()
    subprocess.run(command, check=True, timeout=device_config.flash_timeout)


def _capture_once(
    apx_settings, dut: DeviceAdapter
):  # pylint: disable=redefined-outer-name
    """Wait for one DUT capture cycle and return PCM plus its reported rate."""
    dut.readlines_until(
        regex=apx_settings["ready_regex"], timeout=apx_settings["ready_timeout"]
    )
    logger.info("DUT is streaming PDM")

    begin_lines = dut.readlines_until(
        regex=_BEGIN_RE.pattern, timeout=apx_settings["capture_timeout"]
    )
    begin = _BEGIN_RE.search(begin_lines[-1])
    assert begin, f"DUT never started a PDM capture: {begin_lines[-1]!r}"
    logger.info("DUT capture started: %s", begin.group(0))
    rate_hz = int(begin.group("rate"))
    bits = int(begin.group("bits"))
    sample_count = int(begin.group("samples"))
    assert rate_hz > 0, f"DUT reported an invalid PCM sample rate: {rate_hz}"
    assert bits == 16, f"DUT reported unsupported PCM width: {bits} bits"
    assert sample_count > 0, f"DUT reported an invalid sample count: {sample_count}"

    body = dut.readlines_until(
        regex=_END_RE.pattern, timeout=apx_settings["capture_timeout"]
    )
    end = _END_RE.search(body[-1])
    assert end, f"DUT never ended the PDM capture: {body[-1]!r}"
    dropped = int(end.group("dropped"))
    logger.info("DUT capture ended: %s", end.group(0))
    assert dropped <= apx_settings["max_dropped"], (
        f"DUT reported {dropped} dropped/failed PDM reads during capture "
        f"(max allowed {apx_settings['max_dropped']}) - indicates dropouts, "
        f"overflows, or PCM rate drift during sustained capture."
    )

    pcm = _decode_hex_samples(body[:-1])
    assert pcm.size >= sample_count, (
        f"DUT dump contained {pcm.size} PCM samples, fewer than the "
        f"{sample_count} samples promised by PDM_CAPTURE_BEGIN"
    )
    if pcm.size != sample_count:
        logger.warning(
            "DUT dump contained %d samples; using the %d samples declared "
            "by PDM_CAPTURE_BEGIN",
            pcm.size,
            sample_count,
        )
    return pcm[:sample_count], rate_hz


def _write_wav(path, pcm, rate_hz):
    """Write int16 mono PCM to a WAV file at the given rate."""
    # pylint: disable=no-member
    with wave.open(str(path), "wb") as wav:
        wav.setnchannels(1)
        wav.setsampwidth(2)  # 16-bit
        wav.setframerate(int(round(rate_hz)))
        wav.writeframes(pcm.astype("<i2").tobytes())


# APx File Analysis doubles recovered frequencies for WAVs tagged below this rate.
_APX_FREQ_ANALYSIS_FLOOR_HZ = 4000.0


def _freq_doubling_factor(sample_rate_hz: float) -> float:
    """Return APx's low-rate frequency-doubling factor."""
    if sample_rate_hz <= 0:
        return 1.0
    factor = 1.0
    rate = sample_rate_hz
    while rate < _APX_FREQ_ANALYSIS_FLOOR_HZ:
        rate *= 2.0
        factor *= 2.0
    return factor


def _expected_freq_hz(freq_hz: float, sample_rate_hz: float) -> float:
    """Return expected APx frequency, accounting for low-rate doubling."""
    return freq_hz * _freq_doubling_factor(sample_rate_hz)


# pylint: disable=too-many-arguments,too-many-positional-arguments,too-many-locals
def _check_reading(wav_path, readings, freq_hz, level_dbfs, rate_hz, apx_settings):
    """Assert frequency, level, and THD+N are within range."""
    raw_freq = readings["freq_hz"]
    got_level = readings["level_dbfs"]
    thdn_pct = readings["thdn_ratio_pct"]
    expected_freq_hz = _expected_freq_hz(freq_hz, rate_hz)
    freq_dev_pct = _pct_diff(raw_freq, expected_freq_hz)
    level_dev_db = got_level - level_dbfs
    logger.info(
        "APx %s: freq=%.1f Hz (exp %.1f), level=%.1f dBFS (exp %.1f), " "THD+N=%.4f%%",
        wav_path,
        raw_freq,
        expected_freq_hz,
        got_level,
        level_dbfs,
        thdn_pct,
    )

    freq_tol = apx_settings["freq_tolerance_pct"]
    assert freq_dev_pct <= freq_tol, (
        f"APx-recovered tone frequency {raw_freq:.2f} Hz differs from the "
        f"expected reading {expected_freq_hz:.2f} Hz (generator setpoint "
        f"{freq_hz:.2f} Hz) by {freq_dev_pct:.1f}% (allowed "
        f"+/-{freq_tol}%) - the captured pitch is wrong, pointing to a "
        f"PCM rate/decimator fault in the capture path."
    )
    level_tol = apx_settings["level_tolerance_db"]
    assert abs(level_dev_db) <= level_tol, (
        f"APx-recovered level {got_level:.2f} dBFS differs from the "
        f"generator setpoint {level_dbfs:.2f} dBFS by {level_dev_db:+.2f} dB "
        f"(allowed +/-{level_tol} dB) - the captured amplitude is wrong, "
        f"pointing to a gain/attenuation fault in the capture path."
    )
    max_thdn = apx_settings["max_thdn_pct"]
    assert thdn_pct <= max_thdn, (
        f"APx-recovered THD+N {thdn_pct:.4f}% exceeds the maximum "
        f"{max_thdn}% - the captured tone is distorted/noisy beyond the "
        f"acceptable bench threshold."
    )


# pylint: disable=redefined-outer-name,too-many-arguments
# pylint: disable=too-many-positional-arguments,too-many-locals
def _save_and_check_signal(pcm, rate_hz, freq_hz, level_dbfs, apx_settings, dut):
    """Save PCM to .bin/.wav and assert a real signal was captured."""
    stem = f"pdm_f{int(round(freq_hz))}_lvl{int(round(level_dbfs))}"
    build_dir = Path(dut.device_config.build_dir)
    bin_path = build_dir / f"{stem}.bin"
    wav_path = build_dir / f"{stem}.wav"
    bin_path.write_bytes(pcm.astype("<i2").tobytes())

    _write_wav(wav_path, pcm, rate_hz)
    logger.info("Wrote %d samples to %s and %s", pcm.size, bin_path, wav_path)

    full_scale = float(np.iinfo(np.int16).max)
    peak = int(np.max(np.abs(pcm.astype(np.int32))))
    peak_dbfs = 20 * math.log10(peak / full_scale) if peak > 0 else float("-inf")
    floor = apx_settings["peak_floor_dbfs"]
    logger.info("Peak level: %.1f dBFS", peak_dbfs)
    assert peak_dbfs > floor, (
        f"Captured peak level {peak_dbfs:.1f} dBFS is at/near the "
        f"digital-silence floor (threshold {floor} dBFS): the DUT's PDM "
        f"clock is running but it is not receiving the APx-generated tone "
        f"(check data wiring: APx PDM Output -> EVK)."
    )
    return wav_path, rate_hz


def _capture_silence_point(
    apx_monitor, apx_settings, dut
):  # pylint: disable=redefined-outer-name
    """Capture a near-silence point for noise-floor checking. Returns the .wav path."""
    apx_monitor.set_generator(PDM_GEN_FREQUENCY_HZ, PDM_SILENCE_LEVEL_DBFS)
    logger.info("Resetting DUT for silence capture point")
    _reset_dut(dut)

    pcm, rate_hz = _capture_once(apx_settings, dut)

    build_dir = Path(dut.device_config.build_dir)
    wav_path = build_dir / "pdm_silence.wav"
    _write_wav(wav_path, pcm, rate_hz)
    logger.info("Wrote %d samples to %s", pcm.size, wav_path)
    return wav_path, rate_hz


def _check_silence_reading(readings, apx_settings):
    """Assert silence-point THD+N noise is within the relaxed threshold."""
    noise_dbfs = readings["thdn_noise_level_dbfs"]
    base_max_dbfs = apx_settings["noise_floor_dbfs"]
    relax_db = apx_settings["silence_relax_db"]
    max_dbfs = base_max_dbfs + relax_db
    logger.info(
        "Silence THD+N noise=%.1f dBFS (threshold %.1f dBFS)", noise_dbfs, max_dbfs
    )
    assert noise_dbfs <= max_dbfs, (
        f"APx-measured silence THD+N noise {noise_dbfs:.2f} dBFS exceeds "
        f"the noise-floor threshold {max_dbfs} dBFS - indicates excess "
        f"noise in the PDM capture path."
    )


def test_pdm_capture_sweep(
    apx_monitor, apx_settings, dut: DeviceAdapter
):  # pylint: disable=redefined-outer-name,too-many-locals
    """Sweep APx generator over frequency/level, capture each point, and verify signal presence."""
    freqs = apx_settings["sweep_freqs_hz"]
    levels = apx_settings["sweep_levels_dbfs"]
    assert freqs and levels, "Sweep frequency/level lists must be non-empty"

    points = []  # [(freq_hz, level_dbfs, wav_path, rate_hz), ...]
    capture_rate_hz = None
    for freq_hz in freqs:
        for level_dbfs in levels:
            apx_monitor.set_generator(freq_hz, level_dbfs)
            logger.info(
                "Resetting DUT for sweep point %.0f Hz @ %.0f dBFS", freq_hz, level_dbfs
            )
            _reset_dut(dut)

            pcm, rate_hz = _capture_once(apx_settings, dut)
            if capture_rate_hz is None:
                capture_rate_hz = rate_hz
            assert rate_hz == capture_rate_hz, (
                f"DUT PCM rate changed during sweep: first capture reported "
                f"{capture_rate_hz} Hz, current capture reported {rate_hz} Hz"
            )
            wav_path, rate_hz = _save_and_check_signal(
                pcm, rate_hz, freq_hz, level_dbfs, apx_settings, dut
            )
            points.append((freq_hz, level_dbfs, wav_path, rate_hz))

    silence_wav_path, silence_rate_hz = _capture_silence_point(
        apx_monitor, apx_settings, dut
    )
    if capture_rate_hz is None:
        capture_rate_hz = silence_rate_hz
    assert silence_rate_hz == capture_rate_hz, (
        f"DUT PCM rate changed for silence capture: sweep reported "
        f"{capture_rate_hz} Hz, silence reported {silence_rate_hz} Hz"
    )

    logger.info("All sweep points captured")

    wav_paths = [str(p) for _, _, p, _ in points] + [str(silence_wav_path)]
    readings_list = apx_monitor.get_file_analysis_readings_batch(wav_paths)
    sweep_readings_list = readings_list[: len(points)]
    silence_readings = readings_list[len(points)]

    build_dir = Path(dut.device_config.build_dir)
    max_noise_dbfs = apx_settings["noise_floor_dbfs"]
    relax_db = apx_settings["silence_relax_db"]

    sweep_report = []
    for (freq_hz, level_dbfs, wav_path, rate_hz), readings in zip(
        points, sweep_readings_list
    ):
        sweep_report.append(
            {
                "set_freq_hz": freq_hz,
                "set_level_dbfs": level_dbfs,
                "wav_path": str(wav_path),
                "pcm_rate_hz": rate_hz,
                **readings,
                "expected_freq_hz": _expected_freq_hz(freq_hz, rate_hz),
                "noise_floor_threshold_dbfs": max_noise_dbfs,
            }
        )

    silence_report = {
        "set_level_dbfs": PDM_SILENCE_LEVEL_DBFS,
        "wav_path": str(silence_wav_path),
        "pcm_rate_hz": silence_rate_hz,
        "level_dbfs": silence_readings["level_dbfs"],
        "thdn_noise_level_dbfs": silence_readings["thdn_noise_level_dbfs"],
        "noise_floor_base_threshold_dbfs": max_noise_dbfs,
        "silence_relax_db": relax_db,
        "noise_floor_threshold_dbfs": max_noise_dbfs + relax_db,
    }

    report_path = build_dir / "pdm_apx.json"
    report_path.write_text(
        json.dumps(
            {
                "sweep": sweep_report,
                "silence": silence_report,
            },
            indent=2,
        )
    )
    logger.info(
        "Wrote %d sweep + silence readings to %s", len(sweep_report), report_path
    )

    for (freq_hz, level_dbfs, wav_path, rate_hz), readings in zip(
        points, sweep_readings_list
    ):
        _check_reading(wav_path, readings, freq_hz, level_dbfs, rate_hz, apx_settings)

    _check_silence_reading(silence_readings, apx_settings)

    logger.info("All points captured and analyzed - PASS")
