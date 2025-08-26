.. _atmsdk:

Atmosic Zephyr SDK
#########################################

Overview
********
This is the top-level repository for the Atmosic SDK.  It contains the west manifest for the SDK dependencies as well as applications developed by Atmosic showcasing its extreme low-power SoC solutions.

Supported Platforms
*******************

    * `ATM33/e <boards/atmosic/atm33evk/doc/index.rst>`_
    * `ATM34/e <boards/atmosic/atm34evk/doc/index.rst>`_

Starting 25.07.0 release, support for ATMx2xx(ATM2/3) platforms are deprecated.

OpenAir branches
****************

The main branch is used for development and to integrate all new features and bug fixes. It reflects the latest state of development.

For Production Use

If you need a stable version of this project, please use the code from one of the official releases_.

.. _releases: https://github.com/Atmosic/openair/releases/

For Contributors

Please base all pull requests on the main branch.

Creating a Workspace
********************

To create an Atmosic SDK workspace, first follow the instructions_ from the official Zephyr documentation on setting up the tooling for your host operating system.  Then use ``west init`` and ``west update`` as follows::

  west init -m https://github.com/Atmosic/openair.git --mr rel_25.07.1 zephyrproject
  cd zephyrproject
  west update

.. _instructions: https://docs.zephyrproject.org/latest/develop/getting_started/index.html

For details about how to build and program an application, see the following sections:

 * `ATM33/e programming and debugging </boards/atmosic/atm33evk/doc/index.rst#programming-and-debugging>`_
 * `ATM34/e programming and debugging </boards/atmosic/atm34evk/doc/index.rst#programming-and-debugging>`_

For more information, see `Atmosic OpenAir Documentation <https://atmosic.com/public/OpenAir_SDK_doc/index.html>`_.
