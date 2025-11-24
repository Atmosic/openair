.. _wurx_sample:

WuRx Sample Application
#######################

Overview
********

This sample demonstrates the use of the Atmosic Wake-up Radio eXtended (WuRx) driver.
The WuRx driver provides ultra-low-power wake-up functionality for Atmosic ATM33xx-5
and ATM34xx-5 chips, enabling systems to wake from deep sleep states when specific
radio signals are detected.

The sample shows how to:

* Initialize the WuRx driver
* Set up wake-up event callbacks
* Enable/disable wake-up detection algorithms
* Monitor wake-up events and status

Requirements
************

* An Atmosic ATM33xx-5 or ATM34xx-5 based board
* WuRx hardware support enabled in device tree

Building and Running
********************

This sample can be found under ``openair/samples/drivers/wurx`` in the Zephyr tree.

.. zephyr-app-commands::
   :zephyr-app: samples/drivers/wurx
   :board: ATMEVK-3430e-YQN-5
   :goals: build flash
   :gen-args: --sysbuild
   :compact:

Sample Output
*************

.. code-block:: console

   [00:00:00.000,000] <inf> wurx_sample: WuRx Sample Application Starting
   [00:00:00.001,000] <inf> wurx_sample: WuRx device ready
   [00:00:00.002,000] <inf> wurx_sample: WuRx driver initialized and ready for wake-up detection

Wake-up Events
**************

When a wake-up radio signal is detected, the callback function will be triggered
and log messages will be displayed:

.. code-block:: console

   [00:01:23.456,000] <inf> wurx_sample: WuRx wake-up event received!
   [00:01:23.457,000] <inf> wurx_sample: Status: 0x00000003
   [00:01:23.458,000] <inf> wurx_sample:   - WuRx0 algorithm triggered
   [00:01:23.459,000] <inf> wurx_sample:   - WuRx1 algorithm triggered

Configuration
*************

The WuRx driver is configured through device tree properties defined in the
``atmosic,wurx.yaml`` binding file. All configuration is static and determined
at compile time.

Pre-configured Overlays
=======================

Three pre-configured overlay files are available in ``openair/doc/wurx/`` for different wake-up scenarios:

**bt_inquiry.overlay** - Bluetooth Inquiry Detection
  Optimized for detecting BT inquiry scans from mobile devices (Android/iOS).
  Enables both WuRx0 and WuRx1 algorithms with register values tuned for
  BT inquiry pattern recognition.

**ibeacon.overlay** - iBeacon Advertisement Detection
  Optimized for detecting iBeacon advertisements from mobile devices.
  Uses specialized register configurations for iBeacon signal patterns.

**high_duty_adv.overlay** - High Duty Cycle Advertisement Detection
  Optimized for EVK-to-EVK wake-up using high duty cycle advertisements.
  Primarily uses WuRx0 algorithm for direct device communication.

To use a specific configuration:

.. code-block:: bash

   # For BT inquiry detection
   west build -b ATMEVK-3430e-YQN-5 openair/samples/drivers/wurx --sysbuild -- -DEXTRA_DTC_OVERLAY_FILE="<WEST_TOPDIR>/openair/doc/wurx/bt_inquiry.overlay"

   # For iBeacon detection
   west build -b ATMEVK-3430e-YQN-5 openair/samples/drivers/wurx --sysbuild -- -DEXTRA_DTC_OVERLAY_FILE="<WEST_TOPDIR>/openair/doc/wurx/ibeacon.overlay"

   # For high duty cycle advertisement detection
   west build -b ATMEVK-3430e-YQN-5 openair/samples/drivers/wurx --sysbuild -- -DEXTRA_DTC_OVERLAY_FILE="<WEST_TOPDIR>/openair/doc/wurx/high_duty_adv.overlay"

See :ref:`wurx_documentation` for detailed information about WuRx and these overlay configurations.

Custom Configuration
====================

For custom configurations, create your own overlay file:

.. code-block:: devicetree

   &wurx {
       status = "okay";
       wurx0-enabled;
       wurx1-enabled;
       wake-timeout-ms = <500>;
       consecutive-signals = <4>;
       signal-spacing-ms = <250>;

       /* Custom PMU register values */
       wurx-general-default = <0x00202600>;
       wurx-general2-default = <0x000320c8>;
       wurx0-regs-default = <0x0000aaaa 0x0000aaaa 0x0a0f78d0 0x20100c04 0x08802013>;
       wurx1-regs-default = <0xaaaaaaaa 0xffffffff 0x0c0a515f 0x20100c04 0x0880200f>;
   };

Available device tree properties:

* ``wake-timeout-ms``: Maximum time to wait for wake-up signal (default: 500ms)
* ``consecutive-signals``: Number of consecutive signals required (default: 4)
* ``signal-spacing-ms``: Time spacing between consecutive signals (default: 250ms)
* ``wurx0-enabled``: Enable WuRx algorithm 0 (boolean)
* ``wurx1-enabled``: Enable WuRx algorithm 1 (boolean)
* ``wurx-general-default``: PMU WURX_GENERAL register value
* ``wurx-general2-default``: PMU WURX_GENERAL2 register value
* ``wurx0-regs-default``: Array of 5 PMU WURX0 register values
* ``wurx1-regs-default``: Array of 5 PMU WURX1 register values

Power Management
****************

The WuRx driver integrates with Zephyr's power management subsystem. When the
system enters low-power states, WuRx can wake up the system when radio signals
are detected, enabling ultra-low-power operation.

The driver is stateless and does not require persistent storage. All configuration
is determined at compile time through device tree properties, making it suitable
for resource-constrained applications.

API Usage
*********

Basic usage example:

.. code-block:: c

   #include <zephyr/drivers/wurx.h>

   static void wurx_callback(const struct device *dev, uint32_t status)
   {
       LOG_INF("WuRx wake-up event! Status: 0x%08x", status);

       if (status & WURX_STATUS_WURX0_TRIGGERED) {
           LOG_INF("WuRx0 algorithm triggered");
       }

       if (status & WURX_STATUS_WURX1_TRIGGERED) {
           LOG_INF("WuRx1 algorithm triggered");
       }
   }

   int main(void)
   {
       const struct device *wurx_dev = DEVICE_DT_GET(DT_NODELABEL(wurx));
       int ret;

       if (!device_is_ready(wurx_dev)) {
           LOG_ERR("WuRx device not ready");
           return -ENODEV;
       }

       ret = wurx_set_callback(wurx_dev, wurx_callback);
       if (ret < 0) {
           LOG_ERR("Failed to set callback: %d", ret);
           return ret;
       }

       ret = wurx_enable(wurx_dev);
       if (ret < 0) {
           LOG_ERR("Failed to enable WuRx: %d", ret);
           return ret;
       }

       LOG_INF("WuRx enabled and ready for wake-up detection");
       return 0;
   }
