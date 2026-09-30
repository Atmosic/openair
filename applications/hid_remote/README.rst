.. _hid_remote:

BLE HID Remote Controller
##########################

Overview
********

The ``hid_remote`` application implements a Bluetooth LE Remote Controller on a
single Atmosic SoC. It provides:

* **HOGP** - HID over GATT Profile (keyboard + consumer control reports)
* **ATVV** - Android TV Voice over BLE (DMIC -> IMA ADPCM -> GATT voice stream)
* **IR/NEC** - Infrared blaster driven by the Atmosic PWM FIFO driver
* **BAS** - Battery Service
* **DIS** - Device Information Service (PnP VID/PID)
* **OTA** - MCUmgr firmware upgrade over BLE (optional, via ``basic_ota_bt.conf``)

The application uses two cooperating SMF (Zephyr State Machine Framework) instances:

* **MMI state machine** - user-facing states (idle, pairing, connected, HID ready, streaming)
* **GAP state machine** - advertising lifecycle (reconnect, pairing, stop)

Supported Boards
****************

- **ATMEVK-5205-NQK-2**

Key Combinations
****************

Press both keys:

* **HOME + BACK** - immediately enter undirected pairing mode. Pairing mode
  remains active until the next cold boot; hibernation wakeup does not switch
  back to reconnect mode.
* **OK + VOL+** - delete all bonds and perform a cold reboot.

The LED stays on while a combination is active, and the individual key events
are suppressed. The pairing combination does not reboot the remote.

Building
********

Default build:

.. code-block:: bash

west build -p always -b <BOARD> openair/applications/hid_remote --sysbuild -T applications.hid_remote.atm


With MCUboot OTA support:

.. code-block:: bash

   west build -p always -b <BOARD> openair/applications/hid_remote --sysbuild -T applications.hid_remote.atm.mcuboot.ota

Flashing
********

.. code-block:: bash

   west flash --no-rebuild --device <DEVICE_ID> [--jlink] [--erase_all/--erase_flash]

Configuration
*************

Key Kconfig options (``prj.conf``):

.. list-table::
   :header-rows: 1
   :widths: 40 60

   * - Kconfig
     - Purpose
   * - ``CONFIG_ATM_HOGP``
     - HID over GATT Profile
   * - ``CONFIG_RC_VOICE``
     - Enable ATVV GATT service + ADPCM encoder; implies ``DMIC_ATM``
   * - ``CONFIG_DMIC_ATM``
     - Atmosic DMIC (PDM microphone) driver (implied by ``RC_VOICE``)
   * - ``CONFIG_AUDIO_ADPCM_ENC``
     - IMA ADPCM encoder library
   * - ``CONFIG_ATM_ATVV``
     - Android TV Voice GATT service
   * - ``CONFIG_IR_NEC``
     - NEC infrared blaster
   * - ``CONFIG_BT_BAS``
     - Battery Service
   * - ``CONFIG_BT_DIS``
     - Device Information Service
   * - ``CONFIG_BT_SETTINGS``
     - Bond persistence via NVS flash
   * - ``CONFIG_RETAINED_MEM``
     - Retain the forced-pairing marker across hibernation wakeup
   * - ``CONFIG_BT_ID_MAX``
     - Number of local Bluetooth identities (configured as 1)
   * - ``CONFIG_BT_MAX_PAIRED``
     - Maximum bonded hosts (configured as 2)
   * - ``CONFIG_BT_MAX_CONN``
     - Maximum simultaneous BLE connections (configured as 3)
   * - ``CONFIG_BT_EXT_ADV_MAX_ADV_SET``
     - Extended advertising sets for two reconnect targets and one pairing set
   * - ``CONFIG_INPUT_ATM_KBD_MATRIX``
     - Atmosic keyboard matrix input driver

Key timing constants (``Kconfig``):

.. list-table::
   :header-rows: 1
   :widths: 40 20 40

   * - Constant
     - Default
     - Description
   * - ``RC_CONNECTION_IDLE_TIMEOUT_CS``
     - 60000 cs
     - Disconnect after idle (600 s)
   * - ``RC_CONNECTION_READY_TIMEOUT_CS``
     - 3000 cs
     - HID ready watchdog (30 s)
   * - ``RC_ENABLE_SLAVE_LAT_TIMEOUT_CS``
     - 3000 cs
     - Slave latency enable delay (30 s)
   * - ``RC_AUDIO_STREAM_TIMEOUT_CS``
     - 1000 cs
     - Maximum voice stream duration (10 s)
   * - ``CONFIG_RC_ADV0_DURATION_MS``
     - 30000 ms
     - Reconnect advertising window; converted to Zephyr's 10 ms timeout units
   * - ``CONFIG_RC_ADV1_DURATION_MS``
     - 6000 ms
     - Pairing advertising window; converted to Zephyr's 10 ms timeout units

Advertising
***********

The application uses one BT identity (``CONFIG_BT_ID_MAX=1``), supports up to
two bonded hosts and up to three simultaneous BLE connections. It selects
between two advertising modes:

* **Reconnect** - low-duty directed advertising for each bonded host
* **Pairing** - undirected, connectable, scannable advertising that broadcasts
  the device name

On a normal cold boot, the application starts reconnect advertising when a bond
exists; otherwise it starts undirected pairing advertising. Pressing
``HOME + BACK`` overrides this selection and keeps pairing advertising active
until a cold boot. The forced-pairing marker is stored in Atmosic
hibernation-retained memory. Advertising interval defaults to 40 ms
(``0x0040`` x 625 us) and is configurable via
``CONFIG_RC_ADV_INTERVAL_MIN`` / ``CONFIG_RC_ADV_INTERVAL_MAX`` in ``Kconfig``.

Voice Pipeline
**************

When ATVV is enabled the voice data path is:

.. code-block:: text

   PDM microphone -> DMIC driver -> PCM samples -> IMA ADPCM encoder -> ATVV GATT notify

The host opens the microphone by writing ``MIC_OPEN`` to the ATVV control point.
The MMI transitions to ``MMI_S_STREAMING`` and calls ``rc_audio_stream_start()``.
On ``MIC_CLOSE`` or ATVV disconnect the stream stops automatically.
