.. _ss_fmna_tag-application:

Find My Combo Tag: Apple & Samsung SmartThings Compatible
#########################################################

Overview
********

This sample illustrates the functionality of a combo tag compatible with both **Apple Find My Network** and **Samsung SmartThings Find Network**.

Requirements
************

- Atmosic EVK <:ref:`board | serial <atmosic_evk>`>

  .. note::

   Currently, only the **ATM33/e** and **ATM34/e** series of Atmosic devices are supported.

Samsung SmartThings Find Device SDK
***********************************

1. Once you have access to SmartThings Find Device SDK you can request for the integration patch from Atmosic.

2. Create a directory named ``vendor`` under the ``<WEST_TOPDIR>``, and place the unzipped ``TagSDK`` directory under ``vendor``. The path will be ``<WEST_TOPDIR>/vendor/TagSDK``.

3. Place the Atmosic patch file (e.g., ``<patch_name.diff>``) into ``<WEST_TOPDIR>/vendor/TagSDK``.

4. Navigate to ``<WEST_TOPDIR>/vendor/TagSDK``, and apply the patch using the following command:

  .. code-block:: bash

    patch -p1 < <patch_name.diff>

ADK Integration Guide
*********************

See the following link for integration and instructions: `Apple Find My Network Tag <../fmna_tag/README.rst#adk-integration-guide>`_.

Building and Running
********************

This application is built from ``openair/applications/ss_fmna_tag``.

Build Without MCUboot
=====================

Build the Secure Processing Environment (SPE) and application:

  .. code-block:: console

    west build -p always -b <BOARD>//ns openair/applications/ss_fmna_tag --sysbuild -T applications.ss_fmna_tag.atm

Build With MCUboot
==================

Build MCUboot, SPE, and the application:

  .. code-block:: console

    west build -p always -b <BOARD>@mcuboot//ns openair/applications/ss_fmna_tag --sysbuild -T applications.ss_fmna_tag.atm.mcuboot

Programming
===========

To flash the built images:

  .. code-block:: console

    west flash --skip-rebuild --verify --device <DEVICE_ID> --jlink --fast_load [--erase_all]

Button Functions
****************

In order for the button to work, jumpers JP25 and JP27 need to be installed on the EVK.

- Press and hold button2 on EVK for 5 seconds during reboot to unpair and enter pairing mode.
- During the pairing process, the Samsung SmartThings APP will prompt the user to press button2 to continue and complete pairing.
