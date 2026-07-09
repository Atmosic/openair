.. _at_cmd_errors:

Error Code Reference
####################

The AT command set uses a two-layer error scheme.  The outer layer (``at_cmd_err_t``,
defined in ``openair/lib/at_cmd/at_cmd.h``) indicates how the AT framework processed the
command.  The inner layer (``at_cmd_app_err_t``, defined in
``openair/subsys/at_cmd_set/at_cmd_set.h``) carries domain-specific detail when the outer
code is ``AT_CMD_ERR_SPECIFIC_ERR`` (``0x80``).

Error Response Format
*********************

:Generic errors:
   ``ERR:<code>`` — decimal value of ``at_cmd_err_t`` (1–7).

:Specific errors:
   ``+<CMD>:<hex_app_err>`` on one line, then ``ERR`` on the next.

.. code-block:: text

   # Generic — wrong argument count
   AT+BLEADVENABLE=
   ERR:2

   # Specific — advertising set already enabled
   AT+BLEADVENABLE=0,ON
   +BLEADVENABLE:11
   ERR

Framework Error Codes (``at_cmd_err_t``)
*****************************************

Defined in ``openair/lib/at_cmd/at_cmd.h``.

.. list-table::
   :widths: 10 38 52
   :header-rows: 1

   * - Code
     - Constant
     - Description
   * - ``0``
     - ``AT_CMD_ERR_NO_ERROR``
     - No error; command executed successfully (``OK`` response).
   * - ``1``
     - ``AT_CMD_ERR_NOT_SUPPORT``
     - Command not supported — Kconfig symbol disabled or operation not implemented.
   * - ``2``
     - ``AT_CMD_ERR_WRONG_ARGU_CNT``
     - Wrong number of arguments supplied.
   * - ``3``
     - ``AT_CMD_ERR_WRONG_ARGU_RANGE``
     - One or more argument values are outside the permitted range.
   * - ``4``
     - ``AT_CMD_ERR_WRONG_ARGU_TYPE``
     - An argument has an unexpected type.
   * - ``5``
     - ``AT_CMD_ERR_WRONG_ARGU_TYPE_OR_RANGE``
     - An argument has the wrong type or is out of range.
   * - ``6``
     - ``AT_CMD_ERR_WRONG_ARGU_CONTENT``
     - Argument content is syntactically valid but semantically rejected.
   * - ``7``
     - ``AT_CMD_ERR_WRONG_EXECUTE_TYPE``
     - The command form used (test / query / execute) is not supported.
   * - ``0x80``
     - ``AT_CMD_ERR_SPECIFIC_ERR``
     - Command-specific error; the ``+<CMD>:<hex_app_err>`` prefix carries the
       ``at_cmd_app_err_t`` value described in the next section.

Application Error Codes (``at_cmd_app_err_t``)
***********************************************

Defined in ``openair/subsys/at_cmd_set/at_cmd_set.h``.  These values appear in the
``+<CMD>:<hex_app_err>`` response line that precedes ``ERR`` whenever the framework
code is ``AT_CMD_ERR_SPECIFIC_ERR``.

Value ranges
============

.. list-table::
   :widths: 20 80
   :header-rows: 1

   * - Range
     - Domain
   * - ``0x00``
     - No error
   * - ``0x01``–``0x05``
     - GAP — role / identity-address errors (legacy, wire-compatible)
   * - ``0x10``–``0x1F``
     - Advertising
   * - ``0x20``–``0x2F``
     - Context
   * - ``0x30``–``0x3F``
     - Parameter validation
   * - ``0x40``–``0x4F``
     - BLE / Zephyr errno mapping
   * - ``0x50``–``0x5F``
     - GPIO / FIO
   * - ``0x60``–``0x6F``
     - System
   * - ``0x70``–``0x7F``
     - GATT / ATT
   * - ``0x80``–``0x8F``
     - Dynamic GATT staging

Code table
==========

.. list-table::
   :widths: 10 35 55
   :header-rows: 1

   * - Code
     - Constant
     - Description
   * - ``0x00``
     - ``AT_ERR_NONE``
     - No error.
   * - ``0x01``
     - ``AT_ERR_GAP_ROLE_INITIALIZED``
     - GAP role is already initialised; cannot re-initialise.
   * - ``0x02``
     - ``AT_ERR_GAP_ROLE_NOT_SUPPORTED``
     - Requested GAP role is not supported by this build.
   * - ``0x03``
     - ``AT_ERR_GAP_SET_BEFORE_INIT``
     - Parameter must be configured before ``bt_enable()``.
   * - ``0x04``
     - ``AT_ERR_GAP_SET_AFTER_INIT``
     - Parameter must be configured after ``bt_enable()``.
   * - ``0x05``
     - ``AT_ERR_GAP_ONLY_STATIC_RND_ADDR``
     - Only static random addresses are supported.
   * - ``0x10``
     - ``AT_ERR_ADV_INVALID_INDEX``
     - Advertising set index is out of range (≥ ``AT_CMD_ADV_MAX_INST``).
   * - ``0x11``
     - ``AT_ERR_ADV_ALREADY_ENABLED``
     - Advertising is already active on the specified set.
   * - ``0x12``
     - ``AT_ERR_ADV_NOT_ENABLED``
     - Advertising is not currently active on the specified set.
   * - ``0x13``
     - ``AT_ERR_ADV_SET_NOT_CREATED``
     - Extended advertising set has not been created yet.
   * - ``0x14``
     - ``AT_ERR_ADV_INVALID_PARAM``
     - One or more advertising parameters are invalid.
   * - ``0x15``
     - ``AT_ERR_ADV_DATA_TOO_LONG``
     - Advertisement payload exceeds ``AT_CMD_MAX_ADV_DATA_LEN``.
   * - ``0x16``
     - ``AT_ERR_ADV_SCAN_DATA_TOO_LONG``
     - Scan-response payload exceeds ``AT_CMD_MAX_ADV_DATA_LEN``.
   * - ``0x20``
     - ``AT_ERR_CTX_NULL``
     - AT command context pointer is ``NULL``.
   * - ``0x21``
     - ``AT_ERR_CTX_NOT_INITIALIZED``
     - AT command context has not been initialised.
   * - ``0x30``
     - ``AT_ERR_PARAM_INVALID``
     - Parameter value is invalid for this operation.
   * - ``0x31``
     - ``AT_ERR_PARAM_OUT_OF_RANGE``
     - Parameter value is outside the accepted range.
   * - ``0x32``
     - ``AT_ERR_PARAM_INVALID_LENGTH``
     - Parameter length is invalid (too short or too long).
   * - ``0x40``
     - ``AT_ERR_BLE_EINVAL``
     - Maps ``EINVAL`` — invalid argument passed to a BLE/Zephyr API.
   * - ``0x41``
     - ``AT_ERR_BLE_EBUSY``
     - Maps ``EBUSY`` — BLE device or resource is busy.
   * - ``0x42``
     - ``AT_ERR_BLE_ENOMEM``
     - Maps ``ENOMEM`` — out of memory in the BLE stack.
   * - ``0x43``
     - ``AT_ERR_BLE_ENOTSUP``
     - Maps ``ENOTSUP`` — operation not supported by the BLE stack.
   * - ``0x44``
     - ``AT_ERR_BLE_EACCES``
     - Maps ``EACCES`` — permission denied (e.g. insufficient security).
   * - ``0x45``
     - ``AT_ERR_BLE_ENODEV``
     - Maps ``ENODEV`` — BLE device not found or not ready.
   * - ``0x46``
     - ``AT_ERR_BLE_ETIMEDOUT``
     - Maps ``ETIMEDOUT`` — BLE operation timed out.
   * - ``0x47``
     - ``AT_ERR_BLE_ECONNREFUSED``
     - Maps ``ECONNREFUSED`` — connection request was refused.
   * - ``0x48``
     - ``AT_ERR_BLE_ECONNRESET``
     - Maps ``ECONNRESET`` — connection was reset by the remote peer.
   * - ``0x49``
     - ``AT_ERR_BLE_EPIPE``
     - Maps ``EPIPE`` — broken pipe / write on a closed connection.
   * - ``0x4A``
     - ``AT_ERR_BLE_EALREADY``
     - Maps ``EALREADY`` — operation already in progress, or address already set.
   * - ``0x4F``
     - ``AT_ERR_BLE_UNKNOWN``
     - Unrecognised BLE/Zephyr errno (catch-all).
   * - ``0x50``
     - ``AT_ERR_GPIO_NOT_READY``
     - GPIO device (``gpio0``) is not ready. Used by ``SYSFUNCPIN`` and ``SYSPM``.
   * - ``0x51``
     - ``AT_ERR_GPIO_CONFIG``
     - ``gpio_pin_configure()`` or ``gpio_pin_interrupt_configure()`` failed.
       Used by ``SYSFUNCPIN`` and ``SYSPM``.
   * - ``0x60``
     - ``AT_ERR_SYS_NEED_REBOOT``
     - A reboot is required for the requested setting to take effect.
   * - ``0x61``
     - ``AT_ERR_SYS_NOT_READY``
     - System subsystem is not ready.
   * - ``0x62``
     - ``AT_ERR_SYS_UART_NOT_READY``
     - Console UART device is not ready. Used by ``SYSUARTBR`` and ``SYSUARTFC``.
   * - ``0x63``
     - ``AT_ERR_SYS_UART_CONFIG``
     - ``uart_configure()`` or ``uart_config_get()`` failed. Used by ``SYSUARTFC``.
   * - ``0x70``
     - ``AT_ERR_GATT_INVALID_HANDLE``
     - GATT attribute handle is invalid or out of range.
   * - ``0x71``
     - ``AT_ERR_GATT_READ_NOT_PERMITTED``
     - Read operation is not permitted on this attribute.
   * - ``0x72``
     - ``AT_ERR_GATT_WRITE_NOT_PERMITTED``
     - Write operation is not permitted on this attribute.
   * - ``0x73``
     - ``AT_ERR_GATT_INVALID_PDU``
     - Received GATT PDU is invalid.
   * - ``0x74``
     - ``AT_ERR_GATT_INSUFF_AUTHEN``
     - Insufficient authentication to access this attribute.
   * - ``0x75``
     - ``AT_ERR_GATT_REQUEST_NOT_SUPPORTED``
     - GATT request opcode is not supported.
   * - ``0x76``
     - ``AT_ERR_GATT_INVALID_OFFSET``
     - Attribute value offset is beyond the end of the value.
   * - ``0x77``
     - ``AT_ERR_GATT_INSUFF_AUTHOR``
     - Insufficient authorization to access this attribute.
   * - ``0x78``
     - ``AT_ERR_GATT_PREPARE_QUEUE_FULL``
     - Prepare-write queue is full.
   * - ``0x79``
     - ``AT_ERR_GATT_ATTRIBUTE_NOT_FOUND``
     - No attribute found within the handle range.
   * - ``0x7A``
     - ``AT_ERR_GATT_ATTRIBUTE_NOT_LONG``
     - Attribute is not a long attribute; long read/write not applicable.
   * - ``0x7B``
     - ``AT_ERR_GATT_INSUFF_ENC_KEY_SIZE``
     - Encryption key size is insufficient for this attribute.
   * - ``0x7C``
     - ``AT_ERR_GATT_INVALID_ATTR_VAL_LEN``
     - Attribute value length is invalid for a write operation.
   * - ``0x7D``
     - ``AT_ERR_GATT_UNLIKELY``
     - Unlikely GATT error (catch-all for unexpected ATT errors).
   * - ``0x7E``
     - ``AT_ERR_GATT_INSUFF_ENC``
     - Insufficient encryption level for this attribute.
   * - ``0x7F``
     - ``AT_ERR_GATT_UNSUPPORTED_GRP_TYPE``
     - Attribute group type is not supported.
   * - ``0x80``
     - ``AT_ERR_GATT_DYN_SVC_ACTIVE``
     - Service is already active; characteristics/descriptors cannot be added.
       Used by ``BLEGATTADDCHAR`` and ``BLEGATTADDDESC``.
   * - ``0x83``
     - ``AT_ERR_GATT_DYN_NO_SVC``
     - No ``BLEGATTADDSERVICE`` has been issued, or all staged services are
       already active. Returned by ``BLEGATTADDCHAR``.
   * - ``0x84``
     - ``AT_ERR_GATT_DYN_NO_CHAR``
     - No ``BLEGATTADDCHAR`` has been issued before ``BLEGATTADDDESC``.

BLE / Zephyr Errno Mapping
***************************

When a BLE or Zephyr API returns a standard errno, ``at_cmd_map_errno()``
(defined in ``at_cmd_set_common.h``) translates it to the corresponding
``AT_ERR_BLE_*`` application error code automatically.

.. list-table::
   :widths: 18 38 44
   :header-rows: 1

   * - Zephyr errno
     - App error code
     - Meaning
   * - ``EINVAL``
     - ``AT_ERR_BLE_EINVAL`` (``0x40``)
     - Invalid argument
   * - ``EBUSY``
     - ``AT_ERR_BLE_EBUSY`` (``0x41``)
     - Device or resource busy
   * - ``ENOMEM``
     - ``AT_ERR_BLE_ENOMEM`` (``0x42``)
     - Out of memory
   * - ``ENOTSUP``
     - ``AT_ERR_BLE_ENOTSUP`` (``0x43``)
     - Operation not supported
   * - ``EACCES``
     - ``AT_ERR_BLE_EACCES`` (``0x44``)
     - Permission denied
   * - ``ENODEV``
     - ``AT_ERR_BLE_ENODEV`` (``0x45``)
     - No such device
   * - ``ETIMEDOUT``
     - ``AT_ERR_BLE_ETIMEDOUT`` (``0x46``)
     - Operation timed out
   * - ``ECONNREFUSED``
     - ``AT_ERR_BLE_ECONNREFUSED`` (``0x47``)
     - Connection refused
   * - ``ECONNRESET``
     - ``AT_ERR_BLE_ECONNRESET`` (``0x48``)
     - Connection reset by peer
   * - ``EPIPE``
     - ``AT_ERR_BLE_EPIPE`` (``0x49``)
     - Broken pipe
   * - ``EALREADY``
     - ``AT_ERR_BLE_EALREADY`` (``0x4A``)
     - Already in progress / address already set
   * - (other)
     - ``AT_ERR_BLE_UNKNOWN`` (``0x4F``)
     - Unrecognised errno value

Tag Error Codes (``at_cmd_tag_err_t``)
***************************************

Defined in ``openair/subsys/at_cmd_set/at_cmd_tag.h``.  These codes are used
exclusively by tag command callbacks (``CONFIG_AT_CMD_TAG_SET``) and are reported
directly in the ``+<CMD>:<hex_code>`` specific-error response.

.. list-table::
   :widths: 10 38 52
   :header-rows: 1

   * - Code
     - Constant
     - Description
   * - ``0``
     - ``AT_CMD_TAG_NO_ERR``
     - Operation completed successfully.
   * - ``1``
     - ``AT_CMD_TAG_ERR_INVALID_PARAM``
     - Invalid parameter (e.g. ``NULL`` pointer passed to callback).
   * - ``2``
     - ``AT_CMD_TAG_ERR_NOT_ALLOWED``
     - Operation not allowed in the current tag state.
   * - ``3``
     - ``AT_CMD_TAG_ERR_INTERNAL``
     - Internal or platform-level error.
   * - ``4``
     - ``AT_CMD_TAG_ERR_BLE_INIT``
     - BLE stack initialisation failed.
   * - ``5``
     - ``AT_CMD_TAG_ERR_MOTION_SENSOR``
     - Motion sensor error.
   * - ``6``
     - ``AT_CMD_TAG_ERR_BUTTON``
     - Button configuration error.
   * - ``7``
     - ``AT_CMD_TAG_ERR_WDOG``
     - Watchdog configuration error.
   * - ``8``
     - ``AT_CMD_TAG_ERR_BUZZER``
     - Buzzer configuration error.
