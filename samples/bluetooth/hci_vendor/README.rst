.. _hci_vendor:

Bluetooth: Atmosic HCI vendor sample
####################################

Overview
********

Expose the Zephyr Bluetooth controller support over UART to another device/CPU
using the H:4 HCI transport protocol (requires HW flow control from the UART).

Requirements
************

* A board with BLE support

Default UART(UART0) settings
****************************

By default the controller builds use the following settings:

* ATMx2 series baudrate: 460800 bit/s
* ATM33 and ATM34 series baudrate: 2000000 bit/s
* 8 bits, no parity, 1 stop bit
* Hardware Flow Control (RTS/CTS) enabled

Building and Running
********************

This sample is built as a Atmosic HCI vendor application.
For more details about the state machine tables, please refer to the
application note.

Debug log(UART1)
****************

By default, the log feature was enabled by setting prj.conf file
P33 is the UART1_TX pin for output the log. 115200 is the default baud rate.
Monitor the console output with a favorite terminal program.

Run time enable feature of HCI_vendor
********************************************

By default, the run time enable HCI vendor was disabled. The sample can be
configured to enable feature:
* add CONFIG_RUNTIME_EN_HCI_VENDOR=y to configuration file.
* west build command with -DCONFIG_RUNTIME_EN_HCI_VENDOR=y

Build and Run
*************

atm33evk
--------

The atm33evk family of boards are based on ARM® Cortex® M33 with TrustZone
support, which require a SPE to be programmed in addition to the application.
DFU also requires MCUboot adding up to a total of three images to be built.
MCUboot and the signed, merged application have to be programmed separately.
In the case of this HID keyboard application, a fixed BLE controller image may
also be needed, thereby requiring up to three images to be programmed. The
default configuration uses the fixed BLE controller image.  Refer to the README
in modules/hal/atmosic/ATM33xx-5/drivers/ble for information on the controller
images and library options.

A convenient support script is provided in the Zephyr repository to build and
program this application. Please refer to::

   openair/boards/arm/atm33evk/doc/index.rst

Below are the steps for building and programming this application without
MCUBoot using ``west build`` and ``west flash`` directly.

Shell environment setup::

  APP=openair/samples/bluetooth/hci_vendor
  BOARD=<chip>
  JLINK_SN=<"serial number">
  SPE=openair/samples/spe
  WEST_TOPDIR=$PWD

Build commands:
  west build -p -s ${SPE} -b ${BOARD} -d build/${BOARD}/${SPE}
  west build -p -s ${APP} -b ${BOARD}_ns \
  -d build/${BOARD}_ns/${APP} \
  -- -DCONFIG_SPE_PATH=\"build/${BOARD}/${SPE}\"

Program commands:
  west flash --skip-rebuild --verify --device=${JLINK_SN} --jlink \
  -d build/${BOARD}/${SPE} --noreset
  west flash --skip-rebuild --verify --device=${JLINK_SN} --jlink \
  -d build/${BOARD}_ns/${APP}
