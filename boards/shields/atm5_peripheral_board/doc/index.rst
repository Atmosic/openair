.. _atm5-peripheral-board:

ATM5/e Peripheral Board
########################

Overview
********

The ATM5/e Peripheral Board is an Atmosic add-on board used to exercise the
peripheral interfaces (I2C, SPI, I2S, PWM, UART, ADC) of an ATM5/e EVK,
such as the ATMEVK-5305-NQK-2. The board is defined in Zephyr as three separate
shields, each of which configures the peripheral board's pinout for a different
use case. The SPI and mikroBUS variants may be used together, however the
I2C/I2S variant cannot be used with the mikroBUS variant due to overlapping
use of pins. All of the variants can be used independently.

+-----------------------------------+-------------------------------------------------------+----------------------+
| Shield name                       | Full name                                              | Supported features   |
+===================================+=========================================================+======================+
| ``atm5_peripheral_board_i2c_i2s`` | ATM5/e Peripheral Board Configured for I2C + I2S       | audio, sensor        |
+-----------------------------------+-------------------------------------------------------+----------------------+
| ``atm5_peripheral_board_mikro_bus``| ATM5/e Peripheral Board Configured for the Mikro Bus  | mikrobus             |
|                                    | socket                                                 |                      |
+-----------------------------------+-------------------------------------------------------+----------------------+
| ``atm5_peripheral_board_spi``     | ATM5/e Peripheral Board Configured for SPI             | sensor               |
+-----------------------------------+-------------------------------------------------------+----------------------+

Requirements
************

* Atmosic ATM5/e EVK (e.g. ATMEVK-5305-NQK-2)
* ATM5/e Peripheral Board installed on the reference design

atm5_peripheral_board_i2c_i2s
******************************

Requires the physical switch on the peripheral board be in the I2C postion.

Configures the peripheral board's I2C0 and I2S peripherals:

* I2C0 (SDA/SCL) with a BME280 environmental sensor at address ``0x76``
* I2S configured with a MAX98357A Audio Amplifier. Usage requires 3V VDDIO on the EVK.

atm5_peripheral_board_spi
***************************

Requires the physical switch on the peripheral board be in the SPI postion.

Configures the peripheral board's SPI0 peripheral with a BME280 environmental
sensor connected via SPI (device address ``0``, max frequency 1 MHz).

atm5_peripheral_board_mikro_bus
**********************************

Requires the physical switch on the peripheral board be in the SPI postion.

Configures the peripheral board to expose a mikroBUS socket, allowing a
MikroE click board to be plugged directly into the ATM5/e reference design.
The mikroBUS socket is wired to the following ATM5/e resources:

+---------------+----------------------+
| mikroBUS pin  | ATM5/e resource      |
+===============+======================+
| AN            | ADC channel 9 (P37)  |
+---------------+----------------------+
| RST           | GPIO (P47)           |
+---------------+----------------------+
| CS            | SPI1 CS (P12)        |
+---------------+----------------------+
| SCK           | SPI1 CLK (P13)       |
+---------------+----------------------+
| MISO          | SPI1 MISO (P15)      |
+---------------+----------------------+
| MOSI          | SPI1 MOSI (P14)      |
+---------------+----------------------+
| PWM           | PWM1 (P38)           |
+---------------+----------------------+
| INT           | GPIO (P39)           |
+---------------+----------------------+
| RX            | UART0 RX (P28)       |
+---------------+----------------------+
| TX            | UART0 TX (P29)       |
+---------------+----------------------+
| SCL           | I2C0 SCL (P16)       |
+---------------+----------------------+
| SDA           | I2C0 SDA (P17)       |
+---------------+----------------------+

Building and Running
*********************

Any of the three shields can be selected for a given application by adding
``--shield <shield name>`` to the build command, for example:

.. code-block:: bash

   west build -p always -b ATMEVK-5305-NQK-2 --shield atm5_peripheral_board_i2c_i2s <app>

.. code-block:: bash

   west build -p always -b ATMEVK-5305-NQK-2 --shield atm5_peripheral_board_spi <app>

.. code-block:: bash

   west build -p always -b ATMEVK-5305-NQK-2 --shield atm5_peripheral_board_mikro_bus <app>

The SPI and Mikro Bus shields can be used together by defining both in the build command:

.. code-block:: bash

   west build -p always -b ATMEVK-5305-NQK-2 --shield atm5_peripheral_board_spi --shield atm5_peripheral_board_mikro_bus <app>

References
**********

See :ref:`shields` for more details on Zephyr's shield support.

* `BME280 Sensor Datasheet (Bosch Sensotec) <https://www.bosch-sensortec.com/media/boschsensortec/downloads/datasheets/bst-bme280-ds002.pdf>`_
