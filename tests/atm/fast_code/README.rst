.. _fast_code:

ATM Fast Code Test
##################

Overview
********

This test demonstrates how to place application code in the fast_code section
(RRAM) on Atmosic ATM34 devices for optimal performance. It shows how to use
a simple linker snippet approach to append application files to the existing
fast_code section.

This test uses the ZTEST framework to verify fast_code functionality.

The test shows how to:

* Place entire application files in fast_code section (RRAM)
* Use a simple linker snippet to append code to existing fast_code
* Verify that functions are correctly placed in RRAM address range using ZTEST assertions
* Easily add more files to fast_code by editing a single snippet file

Key Features
************

* **Simple Linker Snippet**: Uses a custom snippet file (``fast_code_snippet.ld``) to specify which files should be placed in fast_code section
* **Whole File Relocation**: Places entire C files in fast_code section (RRAM)
* **Easy Configuration**: Add new files by editing a single snippet file
* **ZTEST Framework**: Uses ZTEST assertions to verify correct placement in RRAM
* **Address Verification**: Prints function addresses and validates with automated tests

Building and Running
********************

Build command:

.. code-block:: bash

   west build -p always -b <BOARD> openair/tests/atm/fast_code --sysbuild -T tests.atm.fast_code

Flash command:

.. code-block:: bash

   west flash --skip-rebuild --device <DEVICE_ID> --jlink --fast_load [--erase_all]

Requirements
************

To use this fast_code linker approach in your own application, you need:

**1. Enable ATM_APP_FLASH_XIP and CONFIG_ATM_SNIPPETS_FAST_CODE**

Remember to set the DTS_EXTRA_CPPFLAGS environment variable and ``CONFIG_ATM_SNIPPETS_FAST_CODE=y`` to activate fast_code section.
Please refer to prj.conf and sample.yaml for reference.

**2. Create linker snippet file**

The snippet file can be named arbitrarily (e.g., ``fast_code_snippet.ld``, ``my_fast_code.ld``, etc.).

.. code-block:: ld

   /* Include all files that need to be in fast_code section */
   *libapp.a:your_file.c.obj(.text .text.* .rodata .rodata.*)

**3. Copy snippet to generated directory in CMakeLists.txt**

The source file can be named arbitrarily, but the target filename must be ``snippets-fast-code.ld``.

.. code-block:: cmake

   # Copy linker snippet to generated include directory
   # Source file can be any name, but target must be snippets-fast-code.ld
   configure_file(
       ${CMAKE_CURRENT_SOURCE_DIR}/your_snippet_file.ld
       ${CMAKE_BINARY_DIR}/zephyr/include/generated/snippets-fast-code.ld
       COPYONLY
   )

Implementation Details
**********************

The test uses the following key components:

1. **fast_code_snippet.ld**: Simple snippet file listing which files to place in fast_code
2. **CMakeLists.txt**: Uses ``configure_file()`` to copy snippet to generated location
3. **openair/soc/atmosic/ATM34/linker.ld**: Includes ``#include <snippets-fast-code.ld>`` in fast_code section
4. **performance_code.c**: Contains test functions to be placed in fast_code (RRAM)
