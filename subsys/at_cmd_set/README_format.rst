.. _at_cmd_format:

AT Command Format
#################

.. code-block:: text

   AT+<CMD>=<param1>,<param2>,...   Execute
   AT+<CMD>?                        Query current state

.. note::
   Commands that do not support execute have no ``=`` form.
   Use ``AT+<CMD>?`` to query their current state.

Responses:

.. code-block:: text

   +<CMD>:<field1>,<field2>,...
   OK

   ERR[:<app_err_code>]

Address bytes are always passed **MSB-first** without colons (e.g. ``C00102030405``).

Parameter Types
***************

Parameters in command format strings (``fmt``) use single-letter type specifiers with an
optional range constraint ``(#~@)``, where ``#`` is the minimum and ``@`` is the maximum.
Omitting a bound keeps the type default.

.. list-table::
   :header-rows: 1
   :widths: 12 14 20 54

   * - Specifier
     - C type
     - Default range
     - Notes / examples
   * - ``b(#~@)``
     - ``int8_t``
     - −128 to 127
     - | ``b`` — any signed byte
       | ``b(-10~10)`` — range −10 to 10
   * - ``B(#~@)``
     - ``uint8_t``
     - 0 to 255
     - | ``B`` — any unsigned byte
       | ``B(1~2)`` — value 1 or 2
   * - ``w(#~@)``
     - ``int16_t``
     - −32768 to 32767
     - | ``w`` — any signed 16-bit integer
       | ``w(-100~100)``
   * - ``W(#~@)``
     - ``uint16_t``
     - 0 to 65535
     - | ``W`` — any unsigned 16-bit integer
       | ``W(~5)`` — 0 to 5
   * - ``d(#~@)``
     - ``int32_t``
     - −2147483648 to 2147483647
     - | ``d`` — any signed 32-bit integer
       | ``d(-3~10)`` — −3 to 10
       | ``d(~1000)`` — up to 1000
   * - ``D(#~@)``
     - ``uint32_t``
     - 0 to 4294967295
     - | ``D`` — any unsigned 32-bit integer
       | ``D(30~)`` — 30 and above
   * - ``A(#~@)``
     - byte array (hex)
     - 0 to 255 bytes
     - | ``A`` — any length hex string
       | ``A(6~6)`` — exactly 6 bytes (e.g. BD address)
       | ``A(3~)`` — at least 3 bytes
       | ``A(2~5)`` — 2 to 5 bytes
   * - ``S(#~@)``
     - ``char *`` (UTF-8)
     - 0 to 4095 bytes
     - | ``S`` — any string up to 255 octets
       | ``S(3~)`` — at least 3 octets
       | ``S(2~5)`` — 2 to 5 octets

.. note::
   ``A`` parameters are passed as hex-encoded strings without separators
   (e.g. ``020106`` for a 3-byte array). Each pair of hex digits is one byte.
   ``S`` parameters are passed as plain ASCII/UTF-8 text.
