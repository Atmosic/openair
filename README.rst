.. _atmsdk:

Atmosic Zephyr SDK
#########################################

Overview
********
This is the top-level repository for the Atmosic SDK.  It contains the west manifest for the SDK dependencies as well as applications developed by Atmosic showcasing its extreme low-power SoC solutions.

Supported Platforms
*******************

* ATMx2xx_
* ATM33xx_

.. _ATMx2xx: boards/atmosic/atmevk-02/doc/index.rst
.. _ATM33xx: boards/atmosic/atm33evk/doc/index.rst

Creating a Workspace
********************

To create an Atmosic SDK workspace, first follow the instructions_ from the official Zephyr documentation on setting up the tooling for your host operating system.  Then use ``west init`` and ``west update`` as follows::

  west init -m https://github.com/Atmosic/openair.git zephyrproject
  cd zephyrproject
  west update

.. _instructions: https://docs.zephyrproject.org/latest/develop/getting_started/index.html

Refer to the `Supported Platforms`_ documentation for details on how to build and program an application.  For example, see the section on `programming and debugging an ATM33xx </boards/atmosic/atm33evk/doc/index.rst#programming-and-debugging>`_ EVK.
