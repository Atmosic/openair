.. _dmic-sample:

DMIC (PDM Microphone)
#####################

Overview
********

This application demonstrates the Zephyr DMIC API with the Atmosic
``dmic_atm`` PDM controller. The local application configures one mono,
left-channel stream, performs a one-second warm-up, captures a fixed-duration
PCM buffer, and then dumps the captured samples as hexadecimal values over the
console. The dump is intended for offline analysis and for the APx525 bench
validation in ``pytest/``.

The application is intentionally a local replacement for the upstream Zephyr
DMIC sample. It is built by ``CMakeLists.txt`` from ``src/main.c`` so that the
bench-capture behavior and output markers are maintained in this repository.

For full API and algorithm details refer to
``zephyr/samples/drivers/audio/dmic/README.rst``.

Atmosic driver constraints
**************************

The Atmosic ``dmic_atm`` driver (``openair/drivers/audio/dmic_atm.c``) supports:

- PCM rates: 8 000 Hz and 16 000 Hz
- PCM widths: 16-bit, 20-bit, or 24-bit
- Channels: **mono only** (LEFT microphone)
- PDM clock: 500 kHz – 4 MHz (default 1 MHz)
- Hardware ping-pong depth: 16 32-bit words per buffer (fixed)

This sample currently requests 16-bit PCM. Its hardware DMA block contains 16
32-bit words, which the driver exposes as 32 16-bit samples; therefore each
sample block dumped by the application is 64 bytes.

The sample-specific defaults are:

- PCM rate: 16 000 Hz (select 8 000 Hz with ``CONFIG_SAMPLE_RATE_8KHZ=y``)
- PDM controller: ``pdm0`` (``CONFIG_HW_CHANNEL_INDEX=0``)
- Capture duration: 2 seconds (``CONFIG_DMIC_BENCH_DURATION_S``)
- Warm-up duration: 1 second, to discard startup transients

The capture buffer is sized for ``rate * duration`` samples. A read failure is
reported in the ``dropped`` counter; the application stops after 50 consecutive
read failures.

Requirements
************

- Atmosic EVK with either a PDM microphone or the APx525 PDM output connected.

  **ATMEVK-3405-WQK-5** (ATM34, 5×5 package):

  +-----------+---------+-----------+-------------+
  | Signal    | GPIO    | EVK pin   | PDM mic pin |
  +===========+=========+===========+=============+
  | PDM_CLK   | 20      | J-header  | CLK         |
  +-----------+---------+-----------+-------------+
  | PDM_DATA  | 21      | J-header  | DATA / SDO  |
  +-----------+---------+-----------+-------------+
  | Power     | —       | 3.3 V     | VCC         |
  +-----------+---------+-----------+-------------+
  | Ground    | —       | GND       | GND         |
  +-----------+---------+-----------+-------------+

  **ATMEVK-5205-NQK-2** (ATM52):

  +-----------+---------+-----------+-------------+
  | Signal    | GPIO    | EVK pin   | PDM mic pin |
  +===========+=========+===========+=============+
  | PDM_CLK   | 16      | J-header  | CLK         |
  +-----------+---------+-----------+-------------+
  | PDM_DATA  | 13      | J-header  | DATA / SDO  |
  +-----------+---------+-----------+-------------+
  | Power     | —       | 3.3 V     | VCC         |
  +-----------+---------+-----------+-------------+
  | Ground    | —       | GND       | GND         |
  +-----------+---------+-----------+-------------+

  GPIO 16 and 13 conflict with the default I2C0 and SPI1 assignments.
  The board overlay disables both. Disconnect any I2C/SPI devices from
  those pins before running.

APx525 bench wiring
*******************

For the APx tests, the EVK is the PDM clock master and the APx525 emulates the
microphone:

- EVK ``PDM_CLK`` -> APx PDM Input Bit Clk and APx PDM Output Bit Clk
  (both analyzer clock inputs are sense-only).
- APx PDM Output Data -> EVK ``PDM_DATA``.
- Connect a common ground between the EVK and APx525.

Do not connect a physical microphone to ``PDM_DATA`` during the APx test. For
standalone microphone use, the EVK supplies the PDM clock and the microphone
supplies data using the same board pins listed above.

Building and Running
********************

This sample is built from ``openair/samples/drivers/audio/dmic``.
The source code lives in ``openair/samples/drivers/audio/dmic/src/main.c``
(the fixed-duration capture application used by the pytest/APx525 bench
validation in ``pytest/``).

ATM34 — ATMEVK-3405-WQK-5:

.. code-block:: bash

   west build -p always -b ATMEVK-3405-WQK-5 openair/samples/drivers/audio/dmic \
     --sysbuild -T samples.drivers.audio.dmic.atm

   west flash --no-rebuild --device <JLINK_SERIAL> --jlink --erase_all

ATM52 — ATMEVK-5205-NQK-2:

.. code-block:: bash

   west build -p always -b ATMEVK-5205-NQK-2 openair/samples/drivers/audio/dmic \
     --sysbuild -T samples.drivers.audio.dmic.atm

   west flash --no-rebuild --device <FTDI_SERIAL> --erase_all

.. note::
   For ATMEVK-5205-NQK-2 always power-cycle the board (USB disconnect/reconnect)
   after flashing to ensure a Cold Boot. Confirm ``boot_status=1000001`` on the
   UART console before testing.

The default build uses a 16 kHz PCM rate and a 1 MHz PDM clock. The alternate
rates and clocks are selected by the APx test cases in ``sample.yaml``. The
clock overlays can also be supplied to a direct build with, for example,
``-DEXTRA_DTC_OVERLAY_FILE=bitclk_2mhz.overlay``.

Sample Output
*************

.. code-block:: console

   [00:00:01.xxx,000] <inf> dmic_sample: Bench streaming started
   PDM_CAPTURE_BEGIN rate=16000 bits=16 samples=32000
   fc68 ffa0 030d 04b3 0392 005e fcf4 fb52 fc6b ff9f 030b 04af 038f 0062 fcf4 fb50
   ...
   PDM_CAPTURE_END captured=32000 dropped=0

``PDM_CAPTURE_BEGIN`` is the authoritative metadata for the dump. The
``rate``, ``bits``, and ``samples`` values are read by the pytest harness and
are also used to construct the APx WAV file. Each four-digit hexadecimal token
is one signed 16-bit PCM sample; the console decoder converts the values from
unsigned hexadecimal notation to ``int16_t`` samples.

If the capture is interrupted by repeated read failures, ``captured`` can be
shorter than the requested duration and ``dropped`` will be non-zero. The APx
test defaults to zero tolerated dropped reads.

APx525 bench validation
************************

The APx tests are hardware-in-the-loop pytest tests registered by
``sample.yaml``. They require:

- An APx525/APx500 installation with the API assemblies installed at the
  default path (APx500 9.3), or an alternate path passed with
  ``--apx-api-dir``.
- A licensed APx analyzer with the PDM Output option and a connected EVK.
- The ``pythonnet`` Python package in the Python environment used by Twister.
- The APx fixture named ``apx525`` and a serial/device configuration for the
  target EVK.

For each sweep point, the harness configures the APx PDM generator, resets the
DUT without reflashing, captures the console dump, and checks that no PDM
read failures occurred. It writes both raw and WAV forms of every capture:

``pdm_f<frequency>_lvl<level>.bin``
    Raw signed 16-bit PCM for tools such as Audacity or NumPy.

``pdm_f<frequency>_lvl<level>.wav``
    Mono, 16-bit PCM with the sample rate reported by
    ``PDM_CAPTURE_BEGIN``. These WAV files, rather than the raw ``.bin`` files,
    are imported into APx File Analysis because they carry the required audio
    metadata.

The harness then analyzes all sweep WAVs and the near-silence WAV in one APx
File Analysis batch. The finite-file settling algorithms are disabled, and
each APx measurement is finalized with ``AnalyzeFiles()``, ``Checked = True``,
and one ``Run()`` before its results are read. This avoids stale or
positionally misaligned ``SequenceResults`` values.

The generated ``pdm_apx.json`` contains, for each sweep point:

- Requested frequency and level (``set_freq_hz`` and ``set_level_dbfs``).
- PCM rate from the DUT marker (``pcm_rate_hz``).
- APx frequency (``freq_hz``), RMS level (``level_dbfs``), THD+N ratio
  (``thdn_ratio_pct``), and THD+N noise level
  (``thdn_noise_level_dbfs``).
- The applicable noise-floor threshold.

The silence entry records RMS and noise levels. A THD+N ratio is not meaningful
for the silence point because there is no fundamental tone; ``NaN`` for
tone-dependent silence fields is expected.

Test Cases
**********

The sample defines the following test cases in ``sample.yaml``:

``samples.drivers.audio.dmic.atm``
    Basic build/boot test (console harness). Verifies the sample compiles and
    the PDM capture loop runs to completion (``PDM_CAPTURE_END`` line appears).

``samples.drivers.audio.dmic.atm.apx``
    APx525 bench test with 16 kHz PCM rate and 1 MHz PDM bit clock (defaults).
    Sweeps 500, 1 000, and 1 500 Hz at -20 and -6 dBFS, then captures a
    near-silence point.

``samples.drivers.audio.dmic.atm.apx.rate_8khz``
    Same validation at 8 kHz PCM. Sweeps 250, 500, and 750 Hz at -20 and
    -6 dBFS, then captures a near-silence point.

``samples.drivers.audio.dmic.atm.apx.bitclk_500khz``
    Uses a 500 kHz PDM bit clock overlay and sweeps 500 Hz at -20 and
    -6 dBFS, then captures a near-silence point.

``samples.drivers.audio.dmic.atm.apx.bitclk_2mhz``
    Uses a 2 MHz PDM bit clock overlay and runs the default 500/1 000/1 500 Hz
    sweep.

``samples.drivers.audio.dmic.atm.apx.bitclk_4mhz``
    Uses a 4 MHz PDM bit clock overlay and runs the default 500/1 000/1 500 Hz
    sweep.

All APx tests use -20 and -6 dBFS sweep levels, add one -90 dBFS near-silence
capture, and require the ``apx525`` audio-analyzer fixture. They run the pytest
suite in ``pytest/`` and have a 600-second Twister timeout.

Useful pytest options
*********************

The most commonly adjusted APx options are:

``--apx-api-dir=<path>``
    Override the APx500 .NET API directory.
``--apx-bit-clk-freq-hz=<Hz>``
    Select the expected PDM bit-clock noise-floor tier.
``--apx-sweep-freqs-hz=<f1,f2,...>``
    Override the comma-separated generator frequency list.
``--apx-sweep-levels-dbfs=<l1,l2,...>``
    Override the comma-separated generator level list.
``--apx-project=<path>``
    Open an existing APx project instead of auto-configuring the PDM path.

Frequency, level, and THD+N checks default to +/-1 percent, +/-3 dB, and 1
percent respectively. The noise-floor limit is selected by PDM bit clock:
-68 dBFS for 500 kHz, -78 dBFS through 2 MHz, and -82 dBFS above 2 MHz. The
silence check adds the default 5 dB relaxation margin.
