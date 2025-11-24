.. _multimode_consumer_tag-application:

Multimode Consumer Tag
######################

Overview
********

This application demonstrates a multimode locator tag with all three networks enabled by default:

- Apple Find My Network Accessory (FMNA)
- Google Find Hub Network (FHN / Fast Pair + FMDN)
- Samsung SmartThings Find (STF)

It is built with Zephyr Sysbuild (MCUboot variants where noted).

Requirements
************
- Atmosic EVK <:ref:`board | serial <atmosic_evk>`>
- Zephyr toolchain and west
- For STF builds: the Samsung SmartThings Device SDK integrated per vendor/TagSDK instructions (EXTRA_CONF_FILE includes ``stf_tag.conf``)


Device State Transitions
************************

.. note::
   This chapter highlights the key behavioral difference between the **multimode_consumer_tag** and the single-mode **fhn_tag**, **fmna_tag**, or **stf_tag**.

- **Step 1**: When the device is **unpaired**, it automatically enters pairing mode upon boot. In this mode, the device is discoverable and can be paired using either the **Apple Find My**, **Google Find Hub** app or the **Samsung SmartThings Find** app.
- **Step 2**: Once the device is successfully **paired** with any supported app, it switches to single-mode operation, functioning as either an **FMNA tag** (Apple), **FHN tag** (Google), or **STF tag** (Samsung).
- **Step 3**: If the device is **unpaired** via the app or a physical button, it returns to the **unpaired** state and behaves as described in **Step 1**.

Buttons and user actions (Summary)
**********************************

- EVK hardware:
  - Install jumpers JP25 and JP27 for Button2 to function.
- Common behavior:
  - Long-press Button2 during reboot (~3 seconds) to unpair and reset the device (default behavior). On ATMBTCSTAG-3405, this gesture is overridden by board-specific MMI.

FMNA (Apple Find My Network Accessory)
======================================
- Unpaired: Use the Apple Find My app to add the tag (pairing flow starts automatically on boot).
- Provisioned: Use the app to play/stop sound; Button2 long-press during reboot to unpair.
- Log MFi token: Short-press Button2 8 times to log the current MFi token for debugging purposes.

FHN (Google Find Hub Network)
=============================
- Unpaired: **In single mode**, Press Button2 to start FP Discoverable advertising (Model ID).
- Provisioned: Press Button2 to stop "Play Sound" triggered by the app.
- UTP (Unwanted Tracker Protection): Press Button2 to enable "Identifier Read State" for DULT GATT write requests; it must remain enabled for 5 minutes.

STF (Samsung SmartThings Find)
==============================
- Onboarding/locate: Follow the SmartThings app prompts.

OTA (Over-The-Air Update)
=========================
For builds with MCUboot and OTA enabled (targets with ``.mcuboot.ota`` suffix, see build items below):

- **Enter OTA mode**: Short-press Button2 **10 times** to enter OTA mode. The system will reboot and start advertising with device name "Atmosic OTA". ATMBTCSTAG-3405 have a red LED blink every 1 second to indicate OTA mode is active.
- **OTA mode behavior**: All ecosystem-specific behaviors (FMNA/FHN/STF) are suspended. Only OTA functionality is available.
- **Exit OTA mode**: Power off/on or reset or OTA complete the device to automatically exit OTA mode and return to normal operation.

Build items (targets)
*********************
Each item below can be built with west by selecting the sysbuild target name via ``-T``. Replace ``<BOARD>`` with your EVK (e.g. ``ATMEVK-3405-YBV-5``). For MCUboot builds, use the ``@mcuboot`` board alias.

1) Default triple-mode (FMNA + FHN + STF)
=========================================
Target: ``applications.multimode_consumer_tag.atm``
- Purpose: Baseline multimode with all three stacks.

Example::

  west build -p always -b <BOARD> openair/applications/multimode_consumer_tag \
    --sysbuild -T applications.multimode_consumer_tag.atm

2) Google only (FHN)
====================
Target: ``applications.multimode_consumer_tag.atm.fhn_only``
- Purpose: Google Fast Pair + FMDN only.
- Disables: ``CONFIG_STF_TAG``, ``CONFIG_FMNA_TAG``.

Example::

  west build -p always -b <BOARD> openair/applications/multimode_consumer_tag \
    --sysbuild -T applications.multimode_consumer_tag.atm.fhn_only

3) Apple only (FMNA)
====================
Target: ``applications.multimode_consumer_tag.atm.fmna_only``
- Purpose: Apple Find My only.
- Disables: ``CONFIG_STF_TAG``, ``CONFIG_FHN_TAG``.

Example::

  west build -p always -b <BOARD> openair/applications/multimode_consumer_tag \
    --sysbuild -T applications.multimode_consumer_tag.atm.fmna_only

4) Samsung only (STF, minimal)
==============================
Target: ``applications.multimode_consumer_tag.atm.stf_only``
- Purpose: SmartThings Find only, minimal footprint.
- Disables: ``CONFIG_FHN_TAG``, ``CONFIG_FMNA_TAG``.

Example::

  west build -p always -b <BOARD> openair/applications/multimode_consumer_tag \
    --sysbuild -T applications.multimode_consumer_tag.atm.stf_only

5) Dual-mode: Google + Apple
============================
Target: ``applications.multimode_consumer_tag.atm.fhn_fmna_tag``
- Purpose: FHN + FMNA (no STF).

Example::

  west build -p always -b <BOARD> openair/applications/multimode_consumer_tag \
    --sysbuild -T applications.multimode_consumer_tag.atm.fhn_fmna_tag

6) Dual-mode: Samsung + Apple
=============================
Target: ``applications.multimode_consumer_tag.atm.stf_fmna_tag``
- Purpose: STF + FMNA (no FHN).

Example::

  west build -p always -b <BOARD> openair/applications/multimode_consumer_tag \
    --sysbuild -T applications.multimode_consumer_tag.atm.stf_fmna_tag

7) Dual-mode: Samsung + Google
==============================
Target: ``applications.multimode_consumer_tag.atm.stf_fhn_tag``
- Purpose: STF + FHN (no FMNA).

Example::

  west build -p always -b <BOARD> openair/applications/multimode_consumer_tag \
    --sysbuild -T applications.multimode_consumer_tag.atm.stf_fhn_tag

8) Triple-mode with MCUboot + OTA over BLE
==========================================
Target: ``applications.multimode_consumer_tag.atm.mcuboot.ota``
- Purpose: Adds MCUboot and OTA (MCUmgr SMP) on top of triple-mode.
- Extras: MCUboot ECDSA P-256, swap-scratch, ``basic_ota_bt.conf;stf_tag.conf``; tuned logging.

Example::

  west build -p always -b <BOARD>@mcuboot openair/applications/multimode_consumer_tag \
    --sysbuild -T applications.multimode_consumer_tag.atm.mcuboot.ota

9) Google only (FHN) with MCUboot + OTA
=======================================
Target: ``applications.multimode_consumer_tag.atm.fhn_only.mcuboot.ota``
- Purpose: Google Fast Pair + FMDN only, with MCUboot and OTA.

Example::

  west build -p always -b <BOARD>@mcuboot openair/applications/multimode_consumer_tag \
    --sysbuild -T applications.multimode_consumer_tag.atm.fhn_only.mcuboot.ota

10) Apple only (FMNA) with MCUboot + UARP
=========================================
Target: ``applications.multimode_consumer_tag.atm.fmna_only.mcuboot.uarp``
- Purpose: Apple Find My only, with MCUboot and UARP enabled.

Example::

  west build -p always -b <BOARD>@mcuboot openair/applications/multimode_consumer_tag \
    --sysbuild -T applications.multimode_consumer_tag.atm.fmna_only.mcuboot.uarp

11) Samsung only (STF, minimal) with MCUboot + OTA
==================================================
Target: ``applications.multimode_consumer_tag.atm.stf_only.mcuboot.ota``
- Purpose: SmartThings Find only (minimal footprint), with MCUboot and OTA.

Example::

  west build -p always -b <BOARD>@mcuboot openair/applications/multimode_consumer_tag \
    --sysbuild -T applications.multimode_consumer_tag.atm.stf_only.mcuboot.ota

12) Dual-mode: Google + Apple with MCUboot + OTA
=================================================
Target: ``applications.multimode_consumer_tag.atm.fhn_fmna_tag.mcuboot.ota``
- Purpose: FHN + FMNA, with MCUboot and OTA.

Example::

  west build -p always -b <BOARD>@mcuboot openair/applications/multimode_consumer_tag \
    --sysbuild -T applications.multimode_consumer_tag.atm.fhn_fmna_tag.mcuboot.ota

13) Dual-mode: Samsung + Apple with MCUboot + OTA
==================================================
Target: ``applications.multimode_consumer_tag.atm.stf_fmna_tag.mcuboot.ota``
- Purpose: STF + FMNA, with MCUboot and OTA.

Example::

  west build -p always -b <BOARD>@mcuboot openair/applications/multimode_consumer_tag \
    --sysbuild -T applications.multimode_consumer_tag.atm.stf_fmna_tag.mcuboot.ota

14) Dual-mode: Samsung + Google with MCUboot + OTA
===================================================
Target: ``applications.multimode_consumer_tag.atm.stf_fhn_tag.mcuboot.ota``
- Purpose: STF + FHN, with MCUboot and OTA.

Example::

  west build -p always -b <BOARD>@mcuboot openair/applications/multimode_consumer_tag \
    --sysbuild -T applications.multimode_consumer_tag.atm.stf_fhn_tag.mcuboot.ota


15) ATM34: MCUboot + Flash XIP (triple-mode)
=============================================
Target: ``applications.multimode_consumer_tag.atm.atm34.mcuboot.flash_xip``
- Purpose: ATM34 SoC: app executes in external flash XIP with MCUboot.

Example::

  west build -p always -b <BOARD>@mcuboot openair/applications/multimode_consumer_tag \
    --sysbuild -T applications.multimode_consumer_tag.atm.atm34.mcuboot.flash_xip

16) ATM34: MCUboot + Flash XIP (overwrite-only)
================================================
Target: ``applications.multimode_consumer_tag.atm.atm34.mcuboot.flash_xip.overwrite``
- Purpose: Similar to (15) but MCUboot overwrite-only (no scratch).
- Extras: ``SB_CONFIG_MCUBOOT_MODE_OVERWRITE_ONLY=y``, scratch size 0, verify img addr off.

Example::

  west build -p always -b <BOARD>@mcuboot openair/applications/multimode_consumer_tag \
    --sysbuild -T applications.multimode_consumer_tag.atm.atm34.mcuboot.flash_xip.overwrite

17) Google only (FHN) with Channel Sounding
============================================
Target: ``applications.multimode_consumer_tag.atm.fhn_cs_tag``
- Purpose: Google Find Hub Network, with Channel Sounding.
- Extras: ``basic_cs_pd50.conf``; ``CONFIG_ATM_CS=y``; larger LL heap; STF + FMNA disabled.

Example::

  west build -p always -b <BOARD>@mcuboot openair/applications/multimode_consumer_tag \
    --sysbuild -T applications.multimode_consumer_tag.atm.fhn_cs_tag

18) Dual-mode (Google + Apple) with Channel Sounding
=====================================================
Target: ``applications.multimode_consumer_tag.atm.fhn_fmna_cs_tag``
- Purpose: Enable Atmosic Channel Sounding alongside FHN + FMNA.
- Extras: ``basic_cs_pd50.conf``; ``CONFIG_ATM_CS=y``; larger LL heap; STF disabled.

Example::

  west build -p always -b <BOARD> openair/applications/multimode_consumer_tag \
    --sysbuild -T applications.multimode_consumer_tag.atm.fhn_fmna_cs_tag

19) Google only (FHN) with Channel Sounding and MCUboot + OTA
==============================================================
Target: ``applications.multimode_consumer_tag.atm.fhn_cs_tag.mcuboot.ota``
- Purpose: Google Find Hub Network with Channel Sounding, MCUboot and OTA.
- Extras: ``basic_ota_bt.conf;basic_cs_pd50.conf``; ``CONFIG_ATM_CS=y``; larger LL heap; STF + FMNA disabled.

Example::

  west build -p always -b <BOARD>@mcuboot openair/applications/multimode_consumer_tag \
    --sysbuild -T applications.multimode_consumer_tag.atm.fhn_cs_tag.mcuboot.ota

20) Dual-mode (Google + Apple) with Channel Sounding and MCUboot + OTA
=======================================================================
Target: ``applications.multimode_consumer_tag.atm.fhn_fmna_cs_tag.mcuboot.ota``
- Purpose: Enable Atmosic Channel Sounding alongside FHN + FMNA, with MCUboot and OTA.
- Extras: ``basic_ota_bt.conf;basic_cs_pd50.conf``; ``CONFIG_ATM_CS=y``; larger LL heap; STF disabled.

Example::

  west build -p always -b <BOARD>@mcuboot openair/applications/multimode_consumer_tag \
    --sysbuild -T applications.multimode_consumer_tag.atm.fhn_fmna_cs_tag.mcuboot.ota

21) Google only (FHN) with Ranging OOB Data Element (Precision Finding)
========================================================================
Target: ``applications.multimode_consumer_tag.atm.fhn_only.oob_de``
- Purpose: Google Fast Pair + FMDN with Precision Finding using Ranging OOB Data Elements.
- Extras: ``basic_cs_pd50.conf``; UWB and BLE CS ranging enabled; STF + FMNA disabled.
- Features: Enables precise device location using UWB and BLE Channel Sounding ranging capabilities.
- Configuration: See :ref:`fhn_oob_ranging_oob` for detailed Kconfig options and setup instructions.

Example::

  west build -p always -b <BOARD> openair/applications/multimode_consumer_tag \
    --sysbuild -T applications.multimode_consumer_tag.atm.fhn_only.oob_de


Storage Size Configuration
**************************

The ``SB_ATM_DTS_EXTRA_CPPFLAGS`` parameter in ``sample.yaml`` is used to configure the ATM storage size for various build targets.

.. note::

   The default storage size is ``0x1000`` (4 KB) for most builds, with the exception of FMNA-only builds which use ``0x2000`` (8 KB).
   If necessary, you may need to change ``SB_ATM_DTS_EXTRA_CPPFLAGS="-DATM_STORAGE_SIZE=0x1000"`` to a different size based on your application's storage requirements.

   Common storage sizes:
   - ``0x1000`` (4 KB): Default for multimode and most single-mode builds
   - ``0x2000`` (8 KB): Used for FMNA-only builds to accommodate additional Apple Find My data
   - Larger sizes may be required for applications with extensive provisioning or configuration data

   To adjust the storage size for a specific build target, modify the corresponding ``SB_ATM_DTS_EXTRA_CPPFLAGS`` value in ``sample.yaml``.


Google Find Hub Network (FHN) details
*************************************

Adoption and approval
=====================
- Partners must submit a Project Proposal Form and receive approval prior to integrating GFPS (see GPFS_developers_).
- If logged in with a non-developer account, the Find My Device app will NOT proceed with FMDN provisioning and will show an error pop-up.

.. _GPFS_developers: https://developers.google.com/nearby/fast-pair

Model ID and Anti-Spoofing key
==============================
Configuration options:

.. code-block:: console

   CONFIG_FAST_PAIR_MODEL_ID=<Model ID>
   CONFIG_FAST_PAIR_AS_KEY=<Anti-Spoofing Key>
   CONFIG_FAST_PAIR_AS_KEY_TAG=<Secure Journal Tag>

Secure Journal support
======================
The Fast Pair service supports loading the anti-spoofing key from the Secure Journal with automatic fallback to Kconfig defaults.

Key loading priority:
1. Secure Journal (Production): 32-byte binary key stored at ``CONFIG_FAST_PAIR_AS_KEY_TAG`` (default: 0xdf)
2. Kconfig fallback (Development): Base64-encoded key from ``CONFIG_FAST_PAIR_AS_KEY``

Add key to Secure Journal:

.. code-block:: console

   west secjrnl append --device <DEVICE_ID> --board <BOARD> --jlink \
     --tag 0xdf --data "\x<32-bytes-hex>" [--locked]

Verification logs:

.. code-block:: console

   [INF] fp: Model ID [0xXXXXXX] AS Key loaded from Secure Journal
   # or
   [INF] fp: Model ID [0xXXXXXX] AS Key loaded from Kconfig default

.. note::

   - Secure Journal keys must be exactly 32 bytes of binary data.
   - Invalid Secure Journal entries automatically fall back to Kconfig defaults.
   - You can place these configs in prj.conf or pass them via west build ``--`` extra args.

Pairing and provisioning procedure
==================================
1. On an unpaired device, press Button2 to start FP Discoverable Advertisement (Model ID).
2. The Find My Device app detects the device; tap Connect to initiate Fast Pairing.
3. After successful pairing, the device starts FP Non-discoverable Advertisement (with encrypted account key list).
4. Tap Agree in the app to start FMDN provisioning.
5. After successful provisioning, the device starts FMDN Advertisement (encrypted EID) and stops FP Non-discoverable Advertisement by default.
6. The device appears in the user's device list with its location on the map.

.. note::

   After pairing, the Agree icon must be pressed within 5 minutes, otherwise the device will revert to unpaired mode.

Precision Finding (FHPF) with Ranging OOB Data Elements
=======================================================

Precision Finding enables accurate device location using advanced ranging technologies. This feature is available through the ``applications.multimode_consumer_tag.atm.fhn_only.oob_de`` build target.

.. note::

   For comprehensive technical details, implementation guide, and API reference, see :ref:`fhn_oob_ranging_oob`.

   For FHPF module architecture and configuration details, see :ref:`_fhpf_module`.

Supported Ranging Technologies
-------------------------------

**UWB (Ultra-Wideband) Ranging**
  - Provides high-accuracy ranging (typically 10-30 cm accuracy)
  - Requires UWB hardware support on both device and seeker
  - Enabled via ``CONFIG_FMDN_RANGING_OOB_DE_TYPE_UWB_EN=y``

**BLE Channel Sounding (CS) Ranging**
  - Provides medium-accuracy ranging using BLE physical layer measurements
  - Works with standard BLE hardware
  - Enabled via ``CONFIG_FMDN_RANGING_OOB_DE_TYPE_BLE_CS_EN=y``
  - Security level configurable via ``CONFIG_FMDN_RANGING_CS_SECURITY_LEVEL`` (1-4)

Configuration for Precision Finding
------------------------------------

To enable Precision Finding in your build, refer to :ref:`fhn_oob_ranging_oob` for detailed Kconfig options and configuration instructions.

These options are automatically included in the ``applications.multimode_consumer_tag.atm.fhn_only.oob_de`` build target.

Usage with Google Find My Device App
-------------------------------------

1. Build and flash the device with Precision Finding enabled
2. Pair the device using the Google Find My Device app (same as standard FMDN)
3. After provisioning, the app will display ranging capabilities
4. When locating the device, the app will use available ranging technologies for precise positioning
5. Ranging accuracy depends on hardware capabilities and environmental conditions


Apple Find My Network Accessory (FMNA) details
**********************************************

ADK Integration Guide
=====================

Option1 (recommended)
---------------------

The Atmosic Zephyr ADK core is provided as the binary library ``libatm_fmna.a`` and included in the public release, so no additional effort or ADK source code is required to build this application.
Customization can still be performed through configuration settings or application-level modifications, such as button behavior and buzzer customization.

Option2
-------

If modification of the ADK source code is truly required, please contact Atmosic and provide the MFi Program ID. Atmosic will provide a patch to apply the Atmosic Zephyr porting changes to the ADK source code.

Follow the steps as below:

1. Download the ADK source code archive ``Find My network ADK 1.0.zip`` from the Apple MFi Content Center.
2. Extract it and place the ``findmy_network_adk`` directory under ``<WEST_TOPDIR>/vendor``.
3. Place the Atmosic patch file (e.g., ``<patch_name.diff>``) into ``<WEST_TOPDIR>/vendor/findmy_network_adk``.
4. Navigate to ``<WEST_TOPDIR>/vendor/findmy_network_adk`` and execute the following command:

   .. code-block:: bash

      patch -p1 < <patch_name.diff>

5. Add the following entry to the ``projects`` section of ``openair/west.yml``:

   .. code-block:: yaml

      - name: fmna
        url: "ignore://local-only"
        revision: <revision>  # e.g. rc/25.05.0
        path: vendor/findmy_network_adk

6. **Do not run** ``west update`` when using this local source approach.

7. Build the application with the following Kconfig option disabled to compile the ADK source code instead of linking the binary library:

   .. code-block:: bash

      CONFIG_ATM_FMNA_LIB=n


Device Manufacturer Settings
============================

Edit ``tag_data/factory.yml`` to configure device factory data:

- **serial_number**: Unique identifier for the device.
- **auth_uuid**: Authentication UUID.
- **auth_token**: First token for device authentication.

.. note::
    These values are used to authenticate the device and provided by the Apple MFi Program.

.. warning::
    The latest updated **auth_token** can be found in the boot-up console log.
    Alternatively, tap Button2 8 times to immediately print it to the console.
    It is recommended to **back up** this value before erasing RRAM or flash,
    especially when the token is intended to be reused for development purposes.
    To reuse the token, overwrite the **auth_token** field with the previously backed-up value.

    Example log::

      [00:00:00.762,000] <inf> fmna: auth_token
      tag_value: 0x0027E41A26AA24549ACD43B0DC051A9AB9100401010267010219E7...


FMNA Configuration Settings
===========================

Below are the FMNA device configurations. These settings can be added to ``prj.conf`` based on FMNA customization or development requirements; otherwise, default parameters will be used.

Custom Bluetooth Device Address
-------------------------------

Enable a custom Bluetooth device address for testing or development purposes.
If not specified, the device's default EUI-48 MAC address will be used.
Once pairing is successful, this address will be bound to the MFi token.
Back up this address together with the token for future reuse.

Example::

  CONFIG_FMNA_DEV_CUSTOM_BT_ADDR=y
  CONFIG_FMNA_DEV_CUSTOM_BT_ADDR_VALUE="ED:15:48:87:6E:EF"


FMNA Accessory Information
--------------------------

Example::

  CONFIG_FMNA_PRODUCT_DATA="DFECEFF1E1FF54DB"
  CONFIG_FMNA_ACCESSORY_CATEGORY=129
  CONFIG_FMNA_ACCESSORY_CAPABILITY=31
  CONFIG_FMNA_BATTERY_TYPE=1
  CONFIG_FMNA_PID=51966
  CONFIG_FMNA_MANUFACTURER_NAME="Osprey"
  CONFIG_FMNA_MODEL_NAME="Bike"
  CONFIG_FMNA_HARDWARE_VERSION="1"


FMNA Firmware Version
---------------------

Example::

  CONFIG_FMNA_VERSION_MAJOR=1
  CONFIG_FMNA_VERSION_MINOR=0
  CONFIG_FMNA_VERSION_REVISION=18


Samsung SmartThings Find (STF) details
**************************************

SmartThings Find Device SDK integration
=======================================
1. Once you have access to the SmartThings Find Device SDK, request the integration patch from Atmosic.
2. Create a directory named ``vendor`` under ``<WEST_TOPDIR>``, and place the unzipped ``TagSDK`` directory under ``vendor``. The path becomes ``<WEST_TOPDIR>/vendor/TagSDK``.
3. Place the Atmosic patch file (e.g., ``<patch_name.diff>``) into ``<WEST_TOPDIR>/vendor/TagSDK``.
4. Navigate to ``<WEST_TOPDIR>/vendor/TagSDK`` and apply the patch using the following command:

   .. code-block:: bash

      patch -p1 < <patch_name.diff>

Build integration notes
=======================
- This application expects the SDK at ``<WEST_TOPDIR>/vendor/TagSDK``. CMake uses a relative path to include headers and add the SDK subdirectory.
- Enable multi-mode STF with ``CONFIG_ATM_STF_MULTI_MODE=y`` (default in triple-mode builds).
- Several targets append ``EXTRA_CONF_FILE=\"stf_tag.conf\"`` to bring in STF-specific Kconfig.
- For a minimal STF-only build, see the ``.stf_only`` target in this README.


Flashing
========
Use west to flash the combined sysbuild images and factory data:

::

  west flash --skip-rebuild -d build --verify --device <DEVICE_ID> --jlink --fast_load [--erase_all]

.. note::
    - Use the ``--erase_all`` option cautiously, as it may erase critical updated token information.


Additional Notes
================
- PWM Buzzer: add ``CONFIG_ATM_BUZZER=y`` and map a PWM channel in the board overlay (``boards/<BOARD>.overlay``). The buzzer binding requires both ``pwms`` and ``pulse`` properties.
- For STF, ensure the TagSDK integration is complete and that ``stf_tag.conf`` is provided via EXTRA_CONF_FILE as shown in the build items.
