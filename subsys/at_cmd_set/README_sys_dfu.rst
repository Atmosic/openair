.. _at_cmd_sys_dfu:

Serial DFU Commands
###################

See :ref:`at_cmd_format` for command syntax.

The serial DFU commands perform a full over-UART firmware upgrade using MCUboot's
image-swap mechanism. The transfer uses RDP (Raw Data Protocol) binary framing
rather than ASCII AT commands. The application must route UART bytes to the DFU
layer while ``at_cmd_sysdfu_is_active()`` returns ``true``.

**Typical upgrade sequence:**

1. Send ``AT+SYSDFU=0,<len>,<crc_en>`` — device replies ``OK`` and enters binary-receive mode.
2. Stream the firmware image as a sequence of RDP packets.
3. Send ``AT+SYSSWITCHBANK=`` — device marks the staged image for upgrade and reboots.
4. After the reboot, the new firmware runs in *unconfirmed* state (MCUboot will revert on the next reboot unless confirmed).
5. Send ``AT+SYSMKBANKGOOD=`` — device confirms the image; MCUboot will no longer roll back.

RDP Packet Format
*****************

Each binary packet carries up to 252 bytes of firmware data:

.. code-block:: text

   TX: | HDR (1 B) | SN (1 B) | LEN (1 B) | DATA (0–252 B) |
   RX: | HDR (1 B) | SN (1 B) | ERR (1 B) |

HDR op-codes (bits [7:5]):

.. list-table::
   :header-rows: 1
   :widths: 20 20 60

   * - HDR value
     - Name
     - Meaning
   * - ``0x00``
     - START
     - First packet of a multi-packet transfer
   * - ``0x80``
     - CONT
     - Continuation packet (not the last)
   * - ``0x20``
     - END
     - Last packet of a multi-packet transfer
   * - ``0xA0``
     - CONT+END
     - Continuation packet that is also the last
   * - ``0x20``
     - END (single)
     - Single-packet transfer (only packet, also the last)

The device ACKs each packet. ``ERR != 0`` in the ACK indicates a transfer error;
the host must abort and restart from ``AT+SYSDFU``.

AT+SYSDFU — Initiate Serial Firmware Upgrade
*********************************************

:Kconfig:   ``CONFIG_AT_CMD_SYSDFU``
:Depends:   ``CONFIG_ATM_VENDOR_DFU``
:Execute:   ``AT+SYSDFU=<type>,<length>,<crc_en>``
:Query:     not supported

.. list-table::
   :header-rows: 1
   :widths: 20 80

   * - Parameter
     - Description
   * - ``type``
     - Partition type. Only ``0`` (firmware) is supported.
   * - ``length``
     - Total firmware image size in bytes (must be > 0).
   * - ``crc_en``
     - ``1`` to enable per-packet CRC-8 check, ``0`` to disable.

Responds ``OK`` and immediately enters binary-receive mode. Subsequent UART bytes
are interpreted as RDP packets until the full image has been received (``END`` or
``CONT+END`` packet). Returns ``ERR`` if the DFU subsystem cannot be initialised or
if ``type != 0``.

.. code-block:: text

   AT+SYSDFU=0,131072,0
   OK
   <binary RDP stream follows>

AT+SYSSWITCHBANK — Apply Staged Firmware and Reboot
****************************************************

:Kconfig:   ``CONFIG_AT_CMD_SYSDFU``
:Execute:   ``AT+SYSSWITCHBANK=``
:Query:     not supported

Calls ``atm_vendor_dfu_request_upgrade()`` to mark the staged image as pending
upgrade in MCUboot's swap state, then schedules a cold reboot. The ``OK`` response
is transmitted before the reboot occurs.

Returns ``ERR`` if the RDP transfer is not complete (``AT+SYSDFU`` was not run or
the ``END``/``CONT+END`` packet was not yet received).

.. code-block:: text

   AT+SYSSWITCHBANK=
   OK
   <device reboots and applies the new image>

AT+SYSMKBANKGOOD — Confirm Running Image
*****************************************

:Kconfig:   ``CONFIG_AT_CMD_SYSMKBANKGOOD``
:Depends:   ``CONFIG_BOOTLOADER_MCUBOOT``
:Execute:   ``AT+SYSMKBANKGOOD=``
:Query:     not supported

After an MCUboot swap the new image runs in *unconfirmed* state. If the device
reboots again before confirmation, MCUboot will revert to the previous image.
This command calls ``boot_set_confirmed_multi()`` for every image slot that is
pending revert, marking them as permanent.

Send this command after verifying that the new firmware is operating correctly.

.. code-block:: text

   AT+SYSMKBANKGOOD=
   OK
