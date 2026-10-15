#!/usr/bin/env python3
# Copyright (c) 2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic
"""
@file pytest/apx_control.py
@brief APx500 API wrapper for PDM/DMIC bench validation.

Bench topology: EVK drives PDM bit clock (master), APx525 generates
synthetic microphone signal via PDM Output connector.
"""

import logging
import time
from pathlib import Path
from typing import Optional

logger = logging.getLogger(__name__)

DEFAULT_API_DIR = Path(r"C:\Program Files\Audio Precision\APx500 9.3\API")

# APx PDM generator: Interpolation x DecimatedRate = PDM bit clock.
# DecimatedRate = target_bit_clk_hz / PDM_DECIMATION.
PDM_DECIMATION = 64
PDM_LOGIC_LEVEL_V = 3.3
PDM_GEN_FREQUENCY_HZ = 1000
PDM_GEN_LEVEL_DBFS = -20.0

# Near-silence level for noise-floor check (generator has no mute state).
PDM_SILENCE_LEVEL_DBFS = -90.0

# Mono single-edge PDM; "Rising" is the common convention.
PDM_GEN_DATA_EDGE = "Rising"

# Settle time after turning the APx PDM generator on. The sigma-delta
# modulator has a startup transient that corrupts the first ~100 ms of
# output; without this delay the first sweep point shows 100x higher
# THD+N than subsequent points at the same frequency.
PDM_GEN_SETTLE_S = 0.2


class ApxPdmMonitor:  # pylint: disable=too-many-instance-attributes,invalid-name
    """Controls an APx500 analyzer to validate a PDM/DMIC signal path.

    Attribute names like ``_APxOperatingMode`` mirror the .NET enum names
    from the AudioPrecision.API assembly and are intentionally not
    snake_case.
    """

    def __init__(
        self, api_dir: Path = DEFAULT_API_DIR, target_bit_clk_hz: float = 1000000.0
    ):
        self._api_dir = Path(api_dir)
        self._apx = None
        self._connected = False
        self._target_bit_clk_hz = target_bit_clk_hz
        self._gen_freq_hz = PDM_GEN_FREQUENCY_HZ
        self._gen_level_dbfs = PDM_GEN_LEVEL_DBFS
        self._pdm_input_kind = "PDM"
        self._pdm_input_connector_type = None
        # APx500 API enums/types - loaded lazily in init() from the .NET
        # assemblies, declared here so pylint sees them in __init__.
        self._System = None
        self._APxOperatingMode = None
        self._ClockDirection = None
        self._FileAnalysisSampleRateMode = None
        self._InputConnectorType = None
        self._MeasurementResultType = None
        self._MeasurementType = None
        self._FilterTuningType = None
        self._PdmDataEdge = None
        self._PdmInterpolationRatio = None
        self._ScalePdmOutputFreqBy = None
        self._OutputConnectorType = None
        self._OutputChannelIndex = None

    def init(
        self, project_path: Optional[str] = None
    ) -> bool:  # pylint: disable=too-many-locals
        """Start/attach to APx500 and configure the PDM signal path."""
        try:
            import clr  # pythonnet  # pylint: disable=import-outside-toplevel,import-error

            clr.AddReference(  # pylint: disable=no-member
                str(self._api_dir / "AudioPrecision.API2.dll")
            )
            clr.AddReference(  # pylint: disable=no-member
                str(self._api_dir / "AudioPrecision.API.dll")
            )
            import System  # noqa: E501 pylint: disable=import-outside-toplevel,import-error

            # pylint: disable=import-outside-toplevel,import-error
            from AudioPrecision.API import (
                APx500_Application,
                APxOperatingMode,
                ClockDirection,
                FilterTuningType,
                FileAnalysisSampleRateMode,
                InputConnectorType,
                MeasurementResultType,
                MeasurementType,
                OutputChannelIndex,
                OutputConnectorType,
                PdmDataEdge,
                PdmInterpolationRatio,
                ScalePdmOutputFreqBy,
            )

            self._System = System
            self._APxOperatingMode = APxOperatingMode
            self._ClockDirection = ClockDirection
            self._FileAnalysisSampleRateMode = FileAnalysisSampleRateMode
            self._InputConnectorType = InputConnectorType
            self._MeasurementResultType = MeasurementResultType
            self._MeasurementType = MeasurementType
            self._FilterTuningType = FilterTuningType
            self._PdmDataEdge = PdmDataEdge
            self._PdmInterpolationRatio = PdmInterpolationRatio
            self._ScalePdmOutputFreqBy = ScalePdmOutputFreqBy
            self._OutputConnectorType = OutputConnectorType
            self._OutputChannelIndex = OutputChannelIndex
        except Exception as exc:  # pylint: disable=broad-exception-caught
            logger.error(
                "Failed to load APx500 API assemblies from %s: %s", self._api_dir, exc
            )
            return False

        try:
            self._apx = APx500_Application()
            self._apx.Visible = True

            if project_path:
                logger.info("Opening APx project: %s", project_path)
                self._apx.OpenProject(project_path, False)
            else:
                logger.info("Configuring PDM signal path from scratch")
                self._configure_pdm_signal_path()

            self._connected = True
            return True
        except Exception as exc:  # pylint: disable=broad-exception-caught
            logger.error("Failed to initialize APx500: %s", exc)
            return False

    def _configure_pdm_signal_path(self):
        """Configure APx BenchMode: sense EVK bit clock, generate PDM signal."""
        self._apx.OperatingMode = self._APxOperatingMode.BenchMode
        self._apx.SignalMonitorsEnabled = True

        bset = self._apx.BenchMode.Setup
        self._resolve_pdm_input(bset)
        bset.InputConnector.Type = self._pdm_input_connector_type
        self._pdm_input().BitClkDir = self._ClockDirection.In

        bset.OutputConnector.Type = self._OutputConnectorType.PDM
        pdm_out = bset.PdmOutput
        pdm_out.BitClkDir = self._ClockDirection.In
        pdm_out.DataEdge = getattr(self._PdmDataEdge, PDM_GEN_DATA_EDGE)
        pdm_out.Interpolation = getattr(
            self._PdmInterpolationRatio, f"X{PDM_DECIMATION}"
        )
        pdm_out.ScaleFreqBy = self._ScalePdmOutputFreqBy.DecimatedRate
        pdm_out.DecimatedRate.Value = self._target_bit_clk_hz / PDM_DECIMATION
        pdm_out.VddLevel.Value = PDM_LOGIC_LEVEL_V
        pdm_out.LogicLevel.Value = PDM_LOGIC_LEVEL_V
        pdm_out.VddOn = False
        pdm_out.EnableOutputs = True

        gen = self._apx.BenchMode.Generator
        gen.On = False
        gen.Frequency.Value = self._gen_freq_hz
        gen.Levels.SetValue(self._OutputChannelIndex.Ch1, f"{self._gen_level_dbfs}dBFS")
        gen.On = True
        time.sleep(PDM_GEN_SETTLE_S)

    def set_generator(self, freq_hz: float, level_dbfs: float):
        """Retune the PDM generator to a new tone frequency and level."""
        gen = self._apx.BenchMode.Generator
        gen.On = False
        gen.Frequency.Value = freq_hz
        gen.Levels.SetValue(self._OutputChannelIndex.Ch1, f"{level_dbfs}dBFS")
        gen.On = True
        time.sleep(PDM_GEN_SETTLE_S)
        self._gen_freq_hz = freq_hz
        self._gen_level_dbfs = level_dbfs
        logger.info("APx generator: %.1f Hz @ %.1f dBFS", freq_hz, level_dbfs)

    def _resolve_pdm_input(self, bset):
        """Detect PDM input connector (PDM-16 POD if present, else classic PDM)."""
        self._pdm_input_kind = "PDM"
        self._pdm_input_connector_type = self._InputConnectorType.PDM
        try:
            pdm16 = bset.PDM16Input
            if pdm16 is not None and bool(pdm16.IsPodPresent):
                self._pdm_input_kind = "PDM16"
                self._pdm_input_connector_type = self._InputConnectorType.PDM16
        except Exception:  # pylint: disable=broad-exception-caught
            pass
        logger.info("Using APx %s input connector", self._pdm_input_kind)

    def _pdm_input(self):
        """Return the resolved PDM input settings object."""
        bset = self._apx.BenchMode.Setup
        if self._pdm_input_kind == "PDM16":
            return bset.PDM16Input
        return bset.PdmInput

    # pylint: disable=too-many-locals,too-many-statements
    def get_file_analysis_readings_batch(self, wav_paths, retries: int = 5) -> list:
        """Analyze multiple WAVs in one APx File Analysis batch call."""
        wavs = [str(Path(p)) for p in wav_paths]
        System = self._System  # pylint: disable=invalid-name
        ict = self._InputConnectorType
        srm = self._FileAnalysisSampleRateMode
        mrt = self._MeasurementResultType
        mt = self._MeasurementType

        try:
            self._apx.OperatingMode = self._APxOperatingMode.SequenceMode

            setup = self._apx.SignalPathSetup
            setup.InputConnector.Type = ict.DigitalFile

            seq = self._apx.Sequence
            sp = seq.GetSignalPath("Signal Path1")
            names = [sp[i].Name for i in range(sp.Count)]
            if "Frequency" not in names:
                self._apx.AddMeasurement("Signal Path1", mt.Frequency)
            if "Level and Gain" not in names:
                self._apx.AddMeasurement("Signal Path1", mt.LevelAndGain)

            def _run_and_read_all(meas_name, result_types):
                meas = seq.GetMeasurement("Signal Path1", meas_name)
                meas.Show()
                if meas_name == "THD+N":
                    meas.NotchTuningMode = self._FilterTuningType.MeasuredFrequency
                    # File captures are finite; avoid APx waiting for a
                    # settling interval that extends past the WAV end.
                    setup.Settling.ThdN.Enabled = False
                elif meas_name == "Level and Gain":
                    # The default level settling can consume the finite file
                    # stream before APx returns all batch-file readings.
                    setup.Settling.Level.Enabled = False
                active = self._apx.ActiveMeasurement
                active.ClearData()
                last_exc = None
                for _ in range(max(1, retries)):
                    try:
                        active.FileAnalysisSettings.WavFiles = System.Array[
                            System.String
                        ](wavs)
                        active.FileAnalysisSettings.SampleRateMode = (
                            srm.UseRatesFromFiles
                        )
                        last_exc = None
                        break
                    except Exception as exc:  # pylint: disable=broad-exception-caught
                        last_exc = exc
                        time.sleep(1.5)
                if last_exc is not None:
                    raise RuntimeError(
                        f"Failed to assign WAVs to APx file analysis: {last_exc}"
                    )
                active.AnalyzeFiles()
                # AnalyzeFiles imports the finite WAV data but does not
                # populate SequenceResults.  Running the checked measurement
                # finalizes one result set per input file.
                meas.Checked = True
                meas.Run()
                _run_and_read_all.meas_by_name[meas_name] = meas
                readings = [
                    list(meas.SequenceResults[rt].GetMeterValues())
                    for rt in result_types
                ]
                if any(len(values) != len(wavs) for values in readings):
                    raise RuntimeError(
                        f"APx returned incomplete {meas_name} results: "
                        f"expected {len(wavs)} files, got "
                        f"{[len(values) for values in readings]}"
                    )
                return readings

            _run_and_read_all.meas_by_name = {}

            def _read_derived_result_all(
                meas, result_name, meas_name="THD+N"
            ):  # pylint: disable=unused-argument
                """Read 'Noise Level' derived result for all channels."""
                if not hasattr(meas, "SequenceResults"):
                    return []
                try:
                    for i in range(meas.SequenceResults.Count):
                        result = meas.SequenceResults[i]
                        if hasattr(result, "GetMeterReadingNames"):
                            meter_names = result.GetMeterReadingNames()
                            if result_name in meter_names:
                                values = result.GetMeterValues(result_name)
                                return list(values) if values else []
                except Exception as e:  # pylint: disable=broad-exception-caught
                    logger.warning(
                        "Failed to read derived result '%s': %s",
                        result_name,
                        type(e).__name__,
                    )
                return []

            freq_list = _run_and_read_all("Frequency", [mrt.FrequencyMeter])[0]
            thdn_ratio_list = _run_and_read_all("THD+N", [mrt.ThdNRatioMeter])[0]
            level_list = _run_and_read_all("Level and Gain", [mrt.LevelMeter])[0]
            noise_level_list = _read_derived_result_all(
                _run_and_read_all.meas_by_name["THD+N"], "Noise Level"
            )
        finally:
            self._configure_pdm_signal_path()

        results = []
        for i, wav in enumerate(wavs):
            freq_hz = freq_list[i] if i < len(freq_list) else float("nan")
            level_dbfs = level_list[i] if i < len(level_list) else float("nan")
            thdn_ratio_pct = (
                thdn_ratio_list[i] if i < len(thdn_ratio_list) else float("nan")
            )
            noise_level_dbfs = (
                noise_level_list[i] if i < len(noise_level_list) else float("nan")
            )
            logger.info(
                "APx analysis %s: freq=%.2f Hz, level=%.2f dBFS, "
                "THD+N=%.4f%%, noise=%.2f dBFS",
                wav,
                freq_hz,
                level_dbfs,
                thdn_ratio_pct,
                noise_level_dbfs,
            )
            results.append(
                {
                    "freq_hz": freq_hz,
                    "level_dbfs": level_dbfs,
                    "thdn_ratio_pct": thdn_ratio_pct,
                    "thdn_noise_level_dbfs": noise_level_dbfs,
                }
            )
        return results

    def disconnect(self):
        """Stop generator and release APx500 session."""
        try:
            if self._apx is not None:
                self._apx.BenchMode.Generator.On = False
        except Exception as exc:  # pylint: disable=broad-exception-caught
            logger.warning("Failed to stop APx generator: %s", exc)
        self._apx = None
        self._connected = False
