.. _display_gme_sample:

OLED Text
##########

Overview
********

Prints a centered text string ("Atmosic") on a monochrome OLED
module using the Zephyr character framebuffer (CFB). It selects the
largest built-in CFB font whose rendered string still fits the panel and
centers it on screen.

Requirements
************

* An Atmosic EVK with a GME OLED module wired to the board's ``arduino_i2c`` bus.
  Both the GM009605 (SSD1315) and the GME12864, which carries a bare QG-2864KMBEG39
  COG panel (SSD1306), work from the same configuration.

* External 2.2k-4.7k pull-ups to 3.3V on SDA/SCL. On a bare COG panel these are not
  optional: without them the panel accepts one byte per transfer at 100 kHz and
  nothing usable can be drawn. Do not enable the SoC's own pull-ups on top -- the
  SSD1306 datasheet, section 8.1.5 under "I2C-bus data signal", explains that the ITO
  track resistance and the bus pull-up divide the panel's acknowledge, and measurement
  confirms a stronger pull-up drives the acknowledge rate to zero.

Building and Running
********************

.. code-block:: console

   west build -p always -b <BOARD> openair/samples/drivers/display/gme \
    --sysbuild -T samples.drivers.display.gme.atm
   west flash --no-rebuild --device <DEVICE_ID> [--jlink] --erase_all

Orientation
***********

The ``segment-remap`` and ``com-invdir`` properties in ``app.overlay`` set the
panel orientation. Both enabled gives upright, non-mirrored text on both modules
above; toggle either one if your module is mounted rotated or shows mirrored or
upside-down output.
