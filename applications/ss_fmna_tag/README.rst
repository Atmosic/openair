.. _ss_fmna_tag-application:

Samsung SmartThings Apple Find My Combo Tag
###########################################

Overview
********

This sample demonstrates the **Samsung SmartThings Apple Find My Combo Tag** functionality.

Requirements
************

- Atmosic EVK <:ref:`board | serial <atmosic_evk>`>

  .. note::

   Currently, only the **ATM33/e** and **ATM34/e** series of Atmosic devices are supported.

Samsung SmartThings Find Device SDK
***********************************

1. Once you have access to SmartThings Find Device SDK you can request access to git@github.com:Atmosic/TagSDK.git

2. Add following entry to the `projects` section of `west.yml`:

  .. code-block:: yaml
    - name: TagSDK
      url: git@github.com:Atmosic/TagSDK.git
      revision: main
      path: vendor/TagSDK

3. Run `west update` to fetch the project.

ADK Integration Guide
*********************

The ADK core is provided as the binary library ``libatm_fmna.a``, making it easy for users to integrate the Apple FindMy function into their applications without needing the source code.
For access to the Atmosic ADK Zephyr source code, please contact Atmosic and provide the MFi Program ID.

Once you have access to the private Atmosic Zephyr ADK GitHub repository, follow the instructions in the repository's README to include the ADK source in your project build.

  .. note::
    For detailed behavior, configuration, and instructions for **fmna_tag**, please refer to its documentation:
    <:ref:`Apple Find My Network Tag <fmna_tag-application>`>.

Button Functions
****************

- Press and hold button2 on EVK for 5 seconds during reboot to unpair and enter pairing mode.
- During the pairing process, the Samsung SmartThings APP will prompt the user to press button2 to continue and complete pairing.

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
