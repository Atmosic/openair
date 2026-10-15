.. _fhn_oob_ranging_oob:

===============================================
FMDN Precision Finding - Ranging OOB Guide
===============================================

Overview
========

This document provides a comprehensive guide for implementing and using the Find My Device Network (FMDN) Precision Finding feature with Ranging Out-of-Band (OOB) Data Elements. The implementation supports Ultra-Wideband (UWB) and BLE Channel Sounding (BLE CS) ranging technologies, with full OOB DE v3 support including motion notification.

Features
========

* **UWB and BLE CS Ranging Support**: Ultra-Wideband and BLE Channel Sounding ranging support
* **Protocol Version Negotiation**: Automatic negotiation between v1, v2, and v3 peers
* **Protocol v2 Support**: Technology transition type and device type fields in capability responses
* **Protocol v3 Support**: Motion Notification — asynchronous motion status reporting to the seeker
* **Security Integration**: Configurable security levels for ranging operations
* **Platform Abstraction**: Clean separation between protocol and hardware layers
* **Google FMDN Compatible**: Full compliance with Google's Find My Device Network specification

Architecture
============

The ranging implementation consists of three main layers:

1. **Application Layer** (``applications/multimode_consumer_tag/``)
   - Platform-specific ranging implementations
   - Hardware abstraction callbacks

2. **Middleware Layer** (``lib/atm_gfp/``, ``subsys/bluetooth/services/gfp/fmdn/``)
   - Protocol handling and GATT services
   - Security validation and message processing

3. **Core Library** (``lib/ranging_oob_de/``)
   - Data structure definitions
   - Protocol constants and utilities

Configuration
=============

Kconfig Options
---------------

**Core Configuration:**

.. code-block:: kconfig

   CONFIG_FMDN_PRECISION_FINDING=y

**Technology Support:**

.. code-block:: kconfig

   CONFIG_FMDN_RANGING_OOB_DE_TYPE_UWB_EN=y      # Enable UWB ranging
   CONFIG_FMDN_RANGING_OOB_DE_TYPE_BLE_CS_EN=y   # Enable BLE Channel Sounding


**UWB Capability Parameters:**

See ``openair/subsys/bluetooth/services/gfp/fmdn/Kconfig.fhpf_uwb`` for detailed UWB configuration options:

- ``CONFIG_FMDN_RANGING_UWB_CHANNEL_MASK`` - Supported channels
- ``CONFIG_FMDN_RANGING_UWB_PREAMBLE_MASK`` - Supported preamble indices
- ``CONFIG_FMDN_RANGING_UWB_CONFIG_ID_MASK`` - Supported config IDs
- ``CONFIG_FMDN_RANGING_UWB_MIN_RANGING_INT`` - Minimum ranging interval
- ``CONFIG_FMDN_RANGING_UWB_MIN_SLOT_DUR`` - Minimum slot duration
- ``CONFIG_FMDN_RANGING_UWB_DEVICE_ROLE`` - Device role bitmap

**BLE Channel Sounding Configuration:**

See ``openair/subsys/bluetooth/services/gfp/fmdn/Kconfig.fhpf`` for BLE CS options:

- ``CONFIG_FMDN_RANGING_CS_SECURITY_LEVEL`` - Minimum security level (1-4, default: 2)
- ``CONFIG_FMDN_RANGING_OOB_DE_TYPE_BLE_CS_CAP_FORCE_EN`` - Force CS capability reply

Additional library configuration in ``openair/lib/ranging_oob_de/Kconfig``:

- ``CONFIG_RANGING_OOB_DE_TYPE_BLE_CS_CONFIG_SEC_TYPE`` - Include security type in CS config
- ``CONFIG_RANGING_OOB_DE_TECH_TRANS_TYPE`` - Technology transition type (v2: 0x00=Break-before-make, 0x01=Make-before-break, default: 0x01)
- ``CONFIG_RANGING_OOB_DE_DEV_TYPE`` - Device type reported in capability response (v2: Tag=0x03, default: 0x03)

Dependencies
------------

The ranging feature automatically selects required dependencies:

.. code-block:: kconfig

   CONFIG_FMDN_PRECISION_FINDING=y
   # Automatically enables:
   # - RANGING_OOB_DE=y

API Reference
=============

Core Data Structures
--------------------

**Technology IDs:**

.. code-block:: c

   typedef enum {
       RT_TECH_ID_UWB = 0x00,           // Ultra-Wideband
       RT_TECH_ID_CS,                   // BLE Channel Sounding
       RT_TECH_ID_WIFI_NAN_RTT,         // WiFi NAN RTT
       RT_TECH_ID_RSSI,                 // BLE RSSI
       RT_TECH_ID_RFU,                  // Reserved
   } rt_id_t;

**Ranging Handler Structure:**

.. code-block:: c

   typedef struct {
       atm_gfp_ranging_capability_cb_t capability_cb;  // Capability requests
       atm_gfp_ranging_config_cb_t config_cb;          // Configuration requests
       atm_gfp_ranging_start_cb_t start_cb;            // Start requests
       atm_gfp_ranging_stop_cb_t stop_cb;              // Stop requests
       atm_gfp_ranging_motion_cb_t motion_cb;          // Motion notification (v3 only)
   } atm_gfp_ranging_handler_t;

Callback Functions
------------------

**Capability Callback:**

.. code-block:: c

   int capability_cb(rt_id_t tech_id, void *capability);

   // Purpose: Populate device capabilities for requested technology
   // Parameters:
   //   - tech_id: Technology ID (UWB/CS)
   //   - capability: Capability structure to populate
   // Returns: 0 on success, negative on error

**Configuration Callback:**

.. code-block:: c

   int config_cb(rt_id_t tech_id, void *config, bool start_immediately);

   // Purpose: Apply ranging configuration from peer device
   // Parameters:
   //   - tech_id: Technology being configured
   //   - config: Configuration data
   //   - start_immediately: Whether to start ranging immediately
   // Returns: 0 on success, negative on error

**Start/Stop Callbacks:**

.. code-block:: c

   int start_cb(rt_id_t tech_id);
   int stop_cb(rt_id_t tech_id);

   // Purpose: Start/stop ranging operations
   // Parameters:
   //   - tech_id: Technology to start/stop
   // Returns: 0 on success, negative on error

**Motion Callback (OOB DE v3, optional):**

.. code-block:: c

   typedef ranging_de_motion_status_t (*atm_gfp_ranging_motion_get_status_t)(void);
   typedef int (*atm_gfp_ranging_motion_cb_t)(atm_gfp_ranging_motion_get_status_t *get_status);

See `Motion Detection`_ below for full behavioral specification.

Motion Detection
----------------

Motion Notification is an OOB DE v3 feature. The protocol layer requests motion data
from the seeker via the ``ranging_de_conf_motion_data_t`` field in the Ranging Configuration
message. The responder (tag) sends unsolicited BCNA notifications at a fixed interval.

**Activation**

``motion_cb`` is only invoked at runtime when both peers negotiate OOB DE v3.
The ``get_status`` argument signals intent:

* ``get_status != NULL`` — enable: platform initialises the sensor (once) and writes
  its getter function pointer into ``*get_status``.
* ``get_status == NULL`` — disable: platform stops the sensor. If the sensor was never
  started this is a no-op.

**Polling interval**

The protocol layer (``fp_fhpf_gatt.c``) owns the notification interval. It calls the
getter every **2 seconds** (``MOTION_NOTIFY_INTERVAL_MS``), as recommended by the spec.
The platform does not need to schedule any timers.

**Getter contract**

Each time the getter is called the platform must:

1. Return the **highest-severity** motion status detected since the previous call.
2. **Reset** its internal accumulator so the next polling window starts clean.

This ensures that brief high-severity events are not missed between polls.

**Suppression**

``RANGING_MOTION_NOT_DETECTED`` notifications are normally **not transmitted** to the
seeker. However, there is one exception:

When a previous notification indicated movement (any status other than
``RANGING_MOTION_NOT_DETECTED``), at least **3 follow-up notifications** with
``RANGING_MOTION_NOT_DETECTED`` **must be sent** before suppression resumes. This gives
the seeker a hard signal that the peripheral has returned to a stationary state, rather
than leaving the seeker uncertain about whether motion has stopped.

The sequential number is only incremented on actual transmissions (including the
mandatory ``RANGING_MOTION_NOT_DETECTED`` follow-ups).

**Sequential number**

Each transmitted notification carries a 1-byte sequential number (starting at 0)
that is strictly increasing within a session. The seeker validates that each received
value is greater than the previous. The number wraps at 255 — the seeker handles the
wrap gracefully. In practice this boundary is never reached because a session is
limited to 5 minutes maximum, allowing at most 150 notifications at the 2-second
polling interval.

**Authentication (base nonce)**

Motion notifications are unsolicited (no preceding nonce read). Both peers use the
nonce read before the **first** Ranging Configuration in the session as the base nonce
for HMAC-SHA256. Since OOB v2 introduced technology transitioning, multiple Set
Configuration messages are possible within a single session, but the base nonce must
always come from the nonce read preceding the first one and must not be updated by
any subsequent Set Configuration messages in the same session.

**Motion status values**

.. list-table::
   :header-rows: 1
   :widths: 40 15 45

   * - Constant
     - Value
     - Orientation change threshold
   * - ``RANGING_MOTION_NOT_DETECTED``
     - 0x00
     - < 5° (not transmitted)
   * - ``RANGING_MOTION_SLIGHT_MOVEMENT``
     - 0x01
     - 5° – 7°
   * - ``RANGING_MOTION_MODERATE_MOVEMENT``
     - 0x02
     - 7° – 10°
   * - ``RANGING_MOTION_LARGE_MOVEMENT``
     - 0x03
     - > 10°

Protocol Version Compatibility
===============================

The ranging implementation supports protocol version negotiation to ensure compatibility
between devices with different firmware versions.

Version Compatibility Matrix
----------------------------

.. list-table:: Protocol Version Support
   :header-rows: 1
   :widths: 10 15 25 50

   * - Version
     - Kconfig flag
     - Features
     - Compatibility Notes
   * - 0x01
     - Supported
     - UWB ranging, BLE CS framework, full OOB support
     - Legacy; negotiated down to when peer advertises v1
   * - 0x02
     - Supported
     - Technology transition type, device type fields added to capability response
     - Negotiated when peer advertises v2 but not v3
   * - 0x03
     - Current
     - Motion Notification support added (``RANGING_MSG_ID_MOTION_NOTIFICATION``)
     - Recommended version; ``RANGING_PROTOCOL_VERSION_CURRENT``
   * - 0x04+
     - Future
     - Reserved for future enhancements
     - Forward compatibility via version negotiation

Version Negotiation
-------------------

The implementation automatically handles version negotiation using ``RANGING_OOB_DE_SUPPORT_VERSION()``:

* **Current Version**: ``RANGING_PROTOCOL_VERSION_CURRENT = 0x03``

When a peer requests a higher version than supported, the implementation automatically
falls back to the highest supported version. When a peer requests v1 or v2, the
implementation responds with the negotiated version and omits features from newer versions.

Implementation Guide
====================

Step 1: Use Existing Platform Implementation
--------------------------------------------

The multimode_consumer_tag application provides a complete platform implementation in:

* ``src/platform/fp_tag_platform_ranging.h`` - Platform interface definitions
* ``src/platform/fp_tag_platform_ranging.c`` - Complete callback implementations

The platform layer implements the following callbacks:

* **Capability callback** - Reports device ranging capabilities (UWB/CS parameters)
* **Configuration callback** - Applies ranging configuration from peer device
* **Start callback** - Initiates ranging operations
* **Stop callback** - Terminates ranging operations
* **Motion callback** *(optional, OOB DE v3)* - Enables/disables motion detection and delivers
  status changes to the seeker via BCNA notification. Only invoked at runtime when both peers
  negotiate OOB DE v3; leaving the field ``NULL`` silently disables motion reporting.

For custom hardware integration, modify the TODO sections in the platform callbacks to interface with your actual ranging hardware drivers.

Step 2: Handler Registration
----------------------------

Register your ranging handlers with the middleware. The handlers are automatically registered
during ``atm_gfp_init()`` if provided in the handlers structure:

.. code-block:: c

   // File: applications/your_app/src/main.c

   #include "atm_gfp.h"
   #include "fp_tag_platform_ranging.h"

   // Define ranging handler structure
   static const atm_gfp_ranging_handler_t ranging_handlers = {
       .capability_cb = fp_platform_ranging_capability_cb,
       .config_cb     = fp_platform_ranging_config_cb,
       .start_cb      = fp_platform_ranging_start_cb,
       .stop_cb       = fp_platform_ranging_stop_cb,
       .motion_cb     = fp_platform_ranging_motion_cb,
   };

   int main(void)
   {
       // Recommended: Initialize with ranging handlers (automatic registration)
       atm_gfp_hdlrs_t gfp_handlers = {
           .ranging_handlers = &ranging_handlers,
           // ... other handlers (battery, ring, etc.)
       };
       atm_gfp_init(&gfp_handlers);
       // Ranging handlers are automatically registered during init

       // Alternative: Register ranging handlers separately (for dynamic replacement)
       // atm_gfp_ranging_handler_register(&ranging_handlers);

       return 0;
   }

Step 3: Reference Implementation
--------------------------------

The ``applications/fp_tag/`` provides a complete working example:

.. code-block::

   applications/fp_tag/
   ├── src/platform/
   │   ├── fp_tag_platform_ranging.h      # Platform interface
   │   └── fp_tag_platform_ranging.c      # Complete implementation
   └── src/
       └── main.c                         # Handler registration example

Key features of the reference implementation:

* **Complete callback implementations** for all ranging operations
* **Proper error handling** and return codes
* **Technology-specific configuration** with conditional compilation
* **Hardware abstraction** ready for actual hardware integration
* **Logging and debugging** support


Debugging and Logging
=====================

Enable debug logging for ranging operations:

.. code-block:: kconfig

   CONFIG_LOG=y
   CONFIG_LOG_MODE_IMMEDIATE=y
   CONFIG_ATM_GFP_LOG_LEVEL_DBG=y
   CONFIG_FP_FMDN_GATT_LOG_LEVEL_DBG=y

Log messages include:

* Protocol message handling
* Security validation results
* Platform callback invocations
* Error conditions and status

Building and Testing
====================

Build with UWB Ranging Support
-------------------------------

To build the fp_tag application with UWB ranging support, use the specific test configuration:

.. code-block:: bash

   # Build with UWB ranging OOB support
   west build -p always -b <BOARD>//ns openair/applications/fp_tag -T applications.fp_tag.atm.oob_de.uwb

This test configuration automatically enables:

* ``CONFIG_FMDN_PRECISION_FINDING=y``
* ``CONFIG_FMDN_RANGING_OOB_DE_TYPE_UWB_EN=y``
* Required dependencies for ranging operations

Build with BLE CS Ranging Support
----------------------------------

To build the fp_tag application with UWB and BLE Channel Sounding ranging support:

The ``sample.yaml`` file defines several test configurations:

.. code-block:: yaml

   tests:
     applications.multimode_consumer_tag.atm.fhn_only.oob_de:
       # UWB and BLE CS ranging support configuration
       extra_args: CONFIG_FMDN_PRECISION_FINDING=y CONFIG_FMDN_RANGING_OOB_DE_TYPE_UWB_EN=y CONFIG_FMDN_RANGING_OOB_DE_TYPE_BLE_CS_EN=y CONFIG_BT_CHANNEL_SOUNDING=y CONFIG_BT_RAS=y

.. code-block:: bash

   # Build with BLE CS ranging OOB support
   west build -p always -b <BOARD>//ns openair/applications/multimode_consumer_tag -T applications.multimode_consumer_tag.atm.fhn_only.oob_de
   west flash --no-rebuild --verify --device <DEVICE_ID> --jlink [--erase_all]

This test item configuration automatically enables:

* ``CONFIG_FMDN_PRECISION_FINDING=y``
* ``CONFIG_FMDN_RANGING_OOB_DE_TYPE_UWB_EN=y``
* ``CONFIG_FMDN_RANGING_OOB_DE_TYPE_BLE_CS_EN=y``
* ``CONFIG_BT_RAS=y`` (Bluetooth GATT Ranging Service)
* ``CONFIG_BT_CHANNEL_SOUNDING=y`` (Bluetooth Channel Sounding support)
* Required Bluetooth bonding and security features

**Prerequisites for BLE CS:**

* Zephyr kernel with Bluetooth 5.4+ Channel Sounding support (``CONFIG_BT_CHANNEL_SOUNDING=y``)
* Hardware platform with BLE CS capability
* Proper Bluetooth controller firmware

**Note:** BLE CS ranging is currently in framework/testing phase. Full functionality
requires compatible peer devices and complete CS implementation in the Bluetooth stack.

Build with OOB DE v3 Motion Notification Support
-------------------------------------------------

OOB DE v3 is negotiated automatically at runtime via ``RANGING_OOB_DE_SUPPORT_VERSION()``.
No Kconfig option is required — enable precision finding and at least one ranging technology:

.. code-block:: kconfig

   CONFIG_FMDN_PRECISION_FINDING=y
   CONFIG_FMDN_RANGING_OOB_DE_TYPE_UWB_EN=y

.. code-block:: bash

   west build -p always -b <BOARD>//ns openair/applications/multimode_consumer_tag \
       -- -DCONFIG_FMDN_PRECISION_FINDING=y \
          -DCONFIG_FMDN_RANGING_OOB_DE_TYPE_UWB_EN=y

Motion Detection Thresholds
^^^^^^^^^^^^^^^^^^^^^^^^^^^

The platform reference implementation in ``fp_tag_platform_ranging.c`` converts raw
sensor data to the four OOB DE v3 motion status levels:

.. list-table::
   :header-rows: 1
   :widths: 35 20 45

   * - Status
     - Value
     - Orientation change threshold
   * - ``RANGING_MOTION_NOT_DETECTED``
     - 0x00
     - < 5° along any two axes
   * - ``RANGING_MOTION_SLIGHT_MOVEMENT``
     - 0x01
     - 5° – 7°
   * - ``RANGING_MOTION_MODERATE_MOVEMENT``
     - 0x02
     - 7° – 10°
   * - ``RANGING_MOTION_LARGE_MOVEMENT``
     - 0x03
     - > 10°

The single constant ``MOTION_RAW_PER_DEG`` in ``fp_tag_platform_ranging.c`` maps raw
sensor units to degrees. Tune this value for your sensor before production.


Performance Optimizations
=========================

The implementation includes several performance optimizations:

* **Static Buffers**: Reduced stack usage in GATT handlers
* **Lookup Tables**: Fast technology support checking
* **Macro Consolidation**: Reduced code duplication
* **Optimized Registration**: Efficient handler registration


File Structure
==============

Key files in the implementation:

.. code-block::

   openair/
   ├── applications/multimode_consumer_tag/src/platform/
   │   ├── fp_tag_platform_ranging.h      # Platform interface (capability/config/start/stop/motion)
   │   └── fp_tag_platform_ranging.c      # Platform implementation incl. motion polling (v3)
   ├── lib/atm_gfp/
   │   ├── atm_gfp.h                      # Main API (atm_gfp_ranging_handler_t, motion types)
   │   └── atm_gfp.c                      # Implementation (wrapper + motion forwarding)
   ├── lib/ranging_oob_de/
   │   └── ranging_oob_de.h               # Data structures, message IDs, version enum
   └── subsys/bluetooth/services/gfp/fmdn/
       ├── fp_fhpf_gatt.h                 # FHPF interface (motion notify fn registration)
       ├── fp_fhpf_gatt.c                 # FHPF implementation (config parsing, motion dispatch)
       ├── fp_fmdn_gatt.h                 # BCNA GATT service interface
       ├── fp_fmdn_gatt.c                 # BCNA GATT implementation (motion notification send)
       ├── fp_fmdn_internal.h             # Internal BCNA opcodes and data structures
       └── Kconfig                        # Configuration options

Component Descriptions
----------------------

**Core Library (lib/ranging_oob_de/)**
  * **ranging_oob_de.h**: Protocol data structures, enums, and constants for ranging OOB data elements. Defines message formats, technology IDs, and validation macros.

**GATT Service Layer (subsys/bluetooth/services/gfp/fmdn/)**
  * **fp_fhpf_gatt.h/.c**: FMDN Find Hub Precision Finding GATT service implementation. Handles ranging capability negotiation, configuration, and start/stop operations over Bluetooth.
  * **Kconfig.fhpf**: Configuration options for precision finding features, technology enablement, and security settings.

**Platform Abstraction (applications/multimode_consumer_tag/src/platform/)**
  * **fp_tag_platform_ranging.h/.c**: Hardware abstraction layer providing callback implementations for ranging operations. Interfaces between middleware and actual ranging hardware drivers.

**Middleware Integration (lib/atm_gfp/)**
  * **atm_gfp.h/.c**: Main Google Fast Pair library with ranging handler registration and management. Provides unified API for all Fast Pair features including ranging.

**Configuration Files**
  * **sample.yaml**: Test configurations for different ranging scenarios (UWB, BLE CS)
  * **README_RANGING_OOB.rst**: Comprehensive documentation and implementation guide

Troubleshooting
===============

Common Issues
-------------

**Build Errors:**
- Ensure ``CONFIG_FMDN_PRECISION_FINDING=y`` is set
- Check that at least one technology is enabled
- Verify all required dependencies are met

**Runtime Issues:**
- Check Bluetooth connection security level
- Verify platform callbacks are properly implemented
- Enable debug logging for detailed diagnostics
- Ensure ranging handlers are registered via ``atm_gfp_init()`` with ``ranging_handlers`` field populated
- Verify handler structure remains valid for the application lifetime

**Performance Issues:**
- Monitor stack usage in platform callbacks
- Check for blocking operations in callbacks
- Verify optimal configuration settings

Support
=======

For additional support and documentation:

* Check the ``applications/multimode_consumer_tag/`` example implementation
* Review the Kconfig options in ``subsys/bluetooth/services/gfp/fmdn/Kconfig``
* Enable debug logging for detailed operation traces

Copyright (C) Atmosic 2025-2026
