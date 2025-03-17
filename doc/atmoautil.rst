Atmosic Open Air Utility
########################
Atmosic Open Air Utility (atmoautil) is an unified tool for Zephyr, and the purpose is reducing the effort for developers to set up the develop environment for Atmosic Open Air SDK.
The atmoautil could manage and download the Zephyr toolchain, Python, Git.

Table of Contents
=================
.. contents::
   :depth: 2
   :local:

|

Download
--------

.. raw:: html

   <div>
      <table style="border-collapse:collapse;width:auto;border-style:double;font-family: Arial, sans-serif">
         <tr>
            <th style="background-color: #EDEDED;color:rgb(37, 37, 37);padding: 10px;border: 1px solid white !important">Operating System</th>
            <th style="background-color: #EDEDED;color:rgb(37, 37, 37);padding: 10px;border: 1px solid white !important">x64</th>
         </tr>
         <tr>
            <td style="background-color: white; color: rgb(37, 37, 37); padding: 10px;border: 1px solid black !important">Windows 10</a></td>
            <td style="background-color: white; color: rgb(37, 37, 37); padding: 10px;border: 1px solid black !important"><a href="https://atmosic.com/public/atmoautil/Tool/Windows/atmoautil.zip">Download</a></td>
         </tr>
         <tr>
            <td style="background-color: white; color: rgb(37, 37, 37); padding: 10px;border: 1px solid black !important">Linux - Ubuntu 22.04 LTS</td>
            <td style="background-color: white; color: rgb(37, 37, 37); padding: 10px;border: 1px solid black !important"><a href="https://atmosic.com/public/atmoautil/Tool/Linux/atmoautil.tgz">Download</a></td>
         </tr>
         <tr>
            <td style="background-color: white; color: rgb(37, 37, 37); padding: 10px;border: 1px solid black !important">MacOS</td>
            <td style="background-color: white; color: rgb(37, 37, 37); padding: 10px;border: 1px solid black !important">Not supported</td>
         </tr>
      </table>
   </div><br>

   <blockquote style="background-color: #f7f7f7; font-family: Arial, sans-serif; border-left: 5px solid #2d87f0; padding: 10px; margin: 10px 0; font-size: 1rem; color: #333;">
      <h4 style="margin-top: 0; font-weight: bold; color: #0077C8; background-color: #E7EFF4; padding: 10px; margin: -10px -10px 10px -10px; display: block;">Note (for the Windows users)</h4>
      <p>Please add atmoautil.exe to the “Exclusions” due to the atmoautil.exe file not signed yet<br><br>
         1. Go to “Settings” / “Privacy & security” / “Windows Security” / “Virus & threat protection”<br>
         2. Click the “Manage settings” of “Virus & threat protection settings” region<br>
         3. Scroll down to the “Exclusions” and click the “Add or remove exclusions”<br>
         4. Click “Add an exclusion” and apply atmoautil.exe to the exclusion list.</p>
   </blockquote>

|

Commands
--------

The table below lists the available commands of Atmosic Open Air Utility (atmoautil). Detailed descriptions of the commands can be found in the section below.

.. raw:: html

   <div>
      <table style="border-collapse: collapse;width:auto;;border-style:double;font-family: Arial, sans-serif">
         <tr>
            <th style="background-color: #EDEDED;color: rgb(37, 37, 37);padding: 10px;border: 1px solid white !important">Command</th>
            <th style="background-color: #EDEDED;color: rgb(37, 37, 37);padding: 10px;border: 1px solid white !important">Explanation</th>
         </tr>
         <tr>
            <td colspan="2" style="background-color: white;font-weight: bold; color: rgb(37, 37, 37); padding: 10px;border: 1px solid black !important"><i>Basic</i></td>
         </tr>
         <tr>
            <td style="background-color: white; color: rgb(37, 37, 37); padding: 10px;border: 1px solid black !important">?, help</td>
            <td style="background-color: white; color: rgb(37, 37, 37); padding: 10px;border: 1px solid black !important">Show this help message and exit.</td>
         </tr>
         <tr>
            <td style="background-color: white; color: rgb(37, 37, 37); padding: 10px;border: 1px solid black !important">-s, --show_log</td>
            <td style="background-color: white; color: rgb(37, 37, 37); padding: 10px;border: 1px solid black !important">Display detailed log information. (For debug)</td>
         </tr>
         <tr>
            <td colspan="2" style="background-color: white;font-weight: bold; color: rgb(37, 37, 37); padding: 10px;border: 1px solid black !important"><i>Manager</i></td>
         </tr>
         <tr>
            <td style="background-color: white; color: rgb(37, 37, 37); padding: 10px;border: 1px solid black !important">?, help</td>
            <td style="background-color: white; color: rgb(37, 37, 37); padding: 10px;border: 1px solid black !important">List commands.</td>
         </tr>
         <tr>
            <td style="background-color: white; color: rgb(37, 37, 37); padding: 10px;border: 1px solid black !important">toolchain_install</td>
            <td style="background-color: white; color: rgb(37, 37, 37); padding: 10px;border: 1px solid black !important">Install a specific version of the toolchain.</td>
         </tr>
         <tr>
            <td style="background-color: white; color: rgb(37, 37, 37); padding: 10px;border: 1px solid black !important">toolchain_uninstall</td>
            <td style="background-color: white; color: rgb(37, 37, 37); padding: 10px;border: 1px solid black !important">Uninstall the currently installed toolchain.</td>
         </tr>
         <tr>
            <td style="background-color: white; color: rgb(37, 37, 37); padding: 10px;border: 1px solid black !important">toolchain_launch</td>
            <td style="background-color: white; color: rgb(37, 37, 37); padding: 10px;border: 1px solid black !important">Launch the installed toolchain.</td>
         </tr>
         <tr>
            <td style="background-color: white; color: rgb(37, 37, 37); padding: 10px;border: 1px solid black !important">toolchain_list</td>
            <td style="background-color: white; color: rgb(37, 37, 37); padding: 10px;border: 1px solid black !important">List all available and installed versions of the toolchain.</td>
         </tr>
         <tr>
            <td style="background-color: white; color: rgb(37, 37, 37); padding: 10px;border: 1px solid black !important">show_version</td>
            <td style="background-color: white; color: rgb(37, 37, 37); padding: 10px;border: 1px solid black !important">Show version of the tool.</td>
         </tr>
         <tr>
            <td style="background-color: white; color: rgb(37, 37, 37); padding: 10px;border: 1px solid black !important">install_rdi</td>
            <td style="background-color: white; color: rgb(37, 37, 37); padding: 10px;border: 1px solid black !important">Install RDI driver. (Windows Only)</td>
         </tr>
         <tr>
            <td style="background-color: white; color: rgb(37, 37, 37); padding: 10px;border: 1px solid black !important">uninstall_rdi</td>
            <td style="background-color: white; color: rgb(37, 37, 37); padding: 10px;border: 1px solid black !important">Uninstall RDI driver. (Windows Only)</td>
         </tr>
         <tr>
            <td style="background-color: white; color: rgb(37, 37, 37); padding: 10px;border: 1px solid black !important">exit</td>
            <td style="background-color: white; color: rgb(37, 37, 37); padding: 10px;border: 1px solid black !important">Exit Atmosic Open Air Utility CLI.</td>
         </tr>
      </table>
   </div><br>

|

Basic
^^^^^

1. **-h, --help**

   Show information about all commands.

   **Syntax**

   atmoautil [-h | --help]

2. **--show_log**

   Command to display detailed log information (For debug)

   **Syntax**

   atmoautil -s

   **Example**

   Enter the command in advance before launching the atmoautil.

   .. raw:: html

      <pre style="background-color:#1E2A47;color:#FFFFFF;padding: 10px;border-radius: 5px;white-space: pre-wrap;width:auto;">
         $ atmoautil -d -s
         ❕❕ Enable Debug Mode ❕❕
         Welcome to Atmosic Open Air Utility CLI. Type 'help' or '?' to list commands.
      </pre>

|

Manager
^^^^^^^

1. **?, help**

   List commands

   **Syntax**

   [? | help]

   **Example**

   .. raw:: html

      <pre style="background-color:#1E2A47;color:#FFFFFF;padding: 10px;border-radius: 5px;white-space: pre-wrap;width:auto;">
      (atmoautil) manager> ?
      ╔════════════════════╗
      ║ Available commands ║
      ╚════════════════════╝
      toolchain_install         Install a specific version of the toolchain.
      toolchain_uninstall       Uninstall the currently installed toolchain.
      toolchain_launch          Launch the installed toolchain
      toolchain_list            List all available and installed versions of the toolchain.
      show_version              Show version of the tool.
      install_rdi               Install RDI driver.
      uninstall_rdi             Uninstall RDI driver.
      exit                      Exit Atmosic Open Air Utility CLI.
      </pre>

2. **show_version**

   Show the atmoautil version

   **Syntax**

   show_version

   **Example**

   .. raw:: html

      <pre style="background-color:#1E2A47;color:#FFFFFF;padding: 10px;border-radius: 5px;white-space: pre-wrap;width:auto;">
      (atmoautil) manager> show_version
      ╔══════════════════════════╗
      ║ Tool Version: 1.0.0.0.56 ║
      ╚══════════════════════════╝
      </pre>

3. **exit**

   Exit Atmosic Open Air Utility CLI.

   **Syntax**

   exit

   **Example**

   .. raw:: html

      <pre style="background-color:#1E2A47;color:#FFFFFF;padding: 10px;border-radius: 5px;white-space: pre-wrap;width:auto;">
      (atmoautil) manager> exit
      Exiting Atmosic Open Air Utility CLI.
      </pre>

4. **toolchain_list**

   List available toolchain(s) in the server and installed toolchain(s) on local. The atmoautil will download a configure file from server to check the available toolchain(s).

   **Example**

   .. raw:: html

      <pre style="background-color:#1E2A47;color:#FFFFFF;padding: 10px;border-radius: 5px;white-space: pre-wrap;width:auto;">
      (atmoautil) manager> toolchain_list
      ╔════════════════════════╗
      ║ Toolchain Version List ║
      ╚════════════════════════╝
      25.02.0
      </pre>

5. **toolchain_install**

   Install a specific version of the toolchain.

   **Syntax**

   toolchain_install [-v | --version] VERSION
   The VERSION could get from toolchain_list command

   **Example**

   .. raw:: html

      <pre style="background-color:#1E2A47;color:#FFFFFF;padding: 10px;border-radius: 5px;white-space: pre-wrap;width:auto;">
      (atmoautil) manager> toolchain_install -v 25.02.0
      ╔════════════════════╗
      ║ Download Toolchain ║
      ╚════════════════════╝
      Downloading ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ 100% 0:00:00
      ╔═══════════════════╗
      ║ Install Toolchain ║
      ╚═══════════════════╝
      Installing ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╺━━━━━  100% 0:00:00
      </pre>

6. **toolchain_launch**

   Launch the installed toolchain for Zephyr development

   ***Syntax**

   toolchain_launch [-v | --version] VERSION
   The VERSION could get from toolchain_List command and please specify the installed one.

   **Example**

   On Windows, it will invoke new Windows command prompt after launching.

   .. raw:: html

      <pre style="background-color:#1E2A47;color:#FFFFFF;padding: 10px;border-radius: 5px;white-space: pre-wrap;width:auto;">
      ╔═══════════════════════════════════════════╗
      ║     Atmosic Zephyr Develop Environment    ║
      ╚═══════════════════════════════════════════╝
      Type 'exit' to quit...
      (25.02.0) C:\Temp\atmoautil>
      </pre>

7. **toolchain_uninstall**

   Uninstall the currently installed toolchain.
   This command only show the toolchain directory and the developer should manual remove it because the developer may install the require components by themselves.

   **Syntax**

   toolchain_uninstall [-v | --version] VERSION
   The VERSION could get from toolchain_List command and please specify the installed one.

   **Example**

   .. raw:: html

      <pre style="background-color:#1E2A47;color:#FFFFFF;padding: 10px;border-radius: 5px;white-space: pre-wrap;width:auto;">
      (atmoautil) manager> toolchain_uninstall -v 25.02.0
      Please manually remove the toolchain directory under the C:\atmoa\toolchains path.
      </pre>

8. **install_rdi**

   This command only for Windows.
   Install the RDI driver.

   **Syntax**

   install_rdi

   **Example**

   .. raw:: html

      <pre style="background-color:#1E2A47;color:#FFFFFF;padding: 10px;border-radius: 5px;white-space: pre-wrap;width:auto;">
      (atmoautil) manager> install_rdi
      ╔════════════════════╗
      ║ Install RDI driver ║
      ╚════════════════════╝
      Install RDI Done
      </pre>

9. **uninstall_rdi**

   This command only for Windows.
   Uninstall the RDI driver.

   **Syntax**

   uninstall_rdi

   **Example**

   .. raw:: html

      <pre style="background-color:#1E2A47;color:#FFFFFF;padding: 10px;border-radius: 5px;white-space: pre-wrap;width:auto;">
      (atmoautil) manager> uninstall_rdi
      ╔══════════════════════╗
      ║ UnInstall RDI driver ║
      ╚══════════════════════╝
      UnInstall RDI driver failed
      </pre>

|

Installation
------------

Atmosic provides Open Air Utility (atmoautil) to manage the Zephyr development environment by command line. The following steps install Atmosic Open Air SDK source code and toolchain.
This includes everything that is required by Zephyr’s Getting Started Guide together with additional tools and Python dependencies that Atmosic Open Air SDK uses.

1) Update operating system
^^^^^^^^^^^^^^^^^^^^^^^^^^
Before setting up the toolchain, please install the available executable for your operating system to make sure it supports Atmosic Open Air SDK firmware.
Please refer to the `Download`_ section for more details.

2) Install prerequisites
^^^^^^^^^^^^^^^^^^^^^^^^
Depending on your preferred development environment, install the following software tools.

- **All operating systems**:

The latest version of atmoautil, a unified command-line utility for Atmosic products. Check operating system versions that support this tool and download the installer.

.. raw:: html

      <blockquote style="background-color: #f7f7f7; font-family: Arial, sans-serif; border-left: 5px solid #2d87f0; padding: 10px; margin: 10px 0; font-size: 1rem; color: #333;">
         <h4 style="margin-top: 0; font-weight: bold; color: #0077C8; background-color: #E7EFF4; padding: 10px; margin: -10px -10px 10px -10px; display: block;">Note</h4>
         <p>
         After downloading the atmoautil executable, move it to a directory that is in the system PATH. On Linux, the downloaded file also needs to be given execute permission by typing chmod +x atmoautil or by checking the checkbox in the file properties.
         </p> 
      </blockquote>

- Download SEGGER J-Link from the `J-Link Software and Documentation Pack <https://www.segger.com/downloads/jlink>`_ page.

3) Install Atmosic Open Air SDK toolchain
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

1. Open a terminal window and execute atmoautil command.

   .. raw:: html

      <pre style="margin: 5; padding: 5px; white-space: pre-wrap; display: block; color: gray; border: 1px solid #C4C4C4; background-color: #F5F5F5;width: auto">
      atmoautil
      </pre>

2. Run the following command to install the toolchain.

   .. raw:: html

      <pre style="margin: 5; padding: 5px; white-space: pre-wrap; display: block; color: gray; border: 1px solid #C4C4C4; background-color: #F5F5F5;width: auto">
      toolchain_install -v 25.02.0
      </pre>

      With the default location to install the toolchain (C&#58;/atmoa/toolchains on Windows, ~/atmoa/toolchains/ on Linux), your directory structure now looks similar to this:

      <pre style="margin: 5; padding: 5px; white-space: pre-wrap; display: block; color: gray; border: 1px solid #C4C4C4; background-color: #F5F5F5;width: auto">
      atmoa
      └─── toolchains
            └───&lt;toolchain-installation&gt;
      </pre>

   In this simplified structure preview, <toolchain-installation> corresponds to the version name you installed

3. Launch develop environment through atmoautil by “toolchain_launch” command. It will pop-up a new Windows command prompt which the window title shows “Atmosic Zephyr” for Windows user. Subsequently, go to the atmoa directory and create zephyrproject folder. (For the Windows user, “cd C:\atmoa”, for the Linux user,  “cd ~/atmoa”)

   .. raw:: html

      <pre style="margin: 5; padding: 5px; white-space: pre-wrap; display: block; color: gray; border: 1px solid #C4C4C4; background-color: #F5F5F5;width: auto">
      toolchain_launch -v 25.02.0
      </pre>

4. Checkout source code from internal or public. Please make sure add you account before the domain name if the OS login user not using your Atmosic account.

   .. raw:: html

      <pre style="margin: 5; padding: 5px; white-space: pre-wrap; display: block; color: gray; border: 1px solid #C4C4C4; background-color: #F5F5F5;width: auto">
      west init -m https://github.com/Atmosic/openair.git
      west update
      </pre>


5. Build sample - hello_world in openair.

   .. raw:: html

      <pre style="margin: 5; padding: 5px; white-space: pre-wrap; display: block; color: gray; border: 1px solid #C4C4C4; background-color: #F5F5F5;width: auto">
      west build -p always --sysbuild openair/samples/sysbuild/hello_world -b ATMEVK-3330e-QN-5//ns -T samples.sysbuild.hello_world.atm
      </pre>

   For Example:

   .. raw:: html

      <pre style="background-color:#1E2A47;color:#FFFFFF;padding: 10px;border-radius: 5px;white-space: pre-wrap;width:auto;">
      (25.02.0) C:\atmoa\zephyrproject> west build -p always --sysbuild openair/samples/sysbuild/hello_world -b ATMEVK-3330e-QN-5//ns -T samples.sysbuild.hello_world.atm
      -- west build: generating a build system
      Loading Zephyr module(s) (Zephyr base): sysbuild_default
      -- Found Python3: C:/atmoa/toolchains/25.02.0/python/python.exe (found suitable version "3.10.11", minimum required is "3.10") found components: Interpreter
      -- Cache files will be written to: C:\atmoa\zephyrproject/zephyr/.cache
      -- Found west (found suitable version "1.3.0", minimum required is "0.14.0")
      -- Board: ATMEVK-3330e-QN-5, qualifiers: ATM33xx-5/ns
      Parsing D:/Project/zephyr/zephyrproject/zephyr/share/sysbuild/Kconfig
      Loaded configuration 'C:\atmoa\zephyrproject/build/_sysbuild/empty.conf'
      Merged configuration 'C:\atmoa\zephyrproject/build/_sysbuild/empty.conf'
      Merged configuration 'C:\atmoa\zephyrproject/build/zephyr/misc/generated/extra_kconfig_options.conf'
      Configuration saved to 'C:\atmoa\zephyrproject/build/zephyr/.config'
      Kconfig header saved to 'C:\atmoa\zephyrproject/build/_sysbuild/autoconf.h'
      --
         *************************
         * Running CMake for spe *
         *************************
      </pre>

      <blockquote style="background-color: #f7f7f7; font-family: Arial, sans-serif; border-left: 5px solid #2d87f0; padding: 10px; margin: 10px 0; font-size: 1rem; color: #333;">
      <h4 style="margin-top: 0; font-weight: bold; color: #0077C8; background-color: #E7EFF4; padding: 10px; margin: -10px -10px 10px -10px; display: block;">Note</h4>
         <p>The Zephyr stock samples support System Build (sysbuild) as well. Please apply following commands to apply test cast to stock samples.<br><br>
            $ cd zephyrproject<br>
            $ python3 openair/tools/scripts/sysbuild_utils.py -r zephyr gen
         </p>
      </blockquote>

6. [Windows] Install RDI driver if need
7. Program firmware to EVK

   .. raw:: html

      <pre style="margin: 5; padding: 5px; white-space: pre-wrap; display: block; color: gray; border: 1px solid #C4C4C4; background-color: #F5F5F5;width: auto">
      west flash --skip-rebuild --fast_load --device=&lt;JLINK_SERIAL&gt; --jlink
      </pre>

   For Example:

   .. raw:: html

      <pre style="background-color:#1E2A47;color:#FFFFFF;padding: 10px;border-radius: 5px;white-space: pre-wrap;width:auto;">
      (25.02.0) d:\atmoa\zephyrproject>west flash --skip-rebuild --fast_load --device=900036842 --jlink
      WARNING: Specifying runner options for multiple domains is experimental.
      If problems are experienced, please specify a single domain using '--domain <domain>'
      -- west flash: using runner atmisp
      -- runners.atmisp: <fast_load> program address: 0x10000
      Open On-Chip Debugger 0.12.0-00020-gaf2e30d6d (2024-04-23-16:10)
      Licensed under GNU GPL v2
      For bug reports, read
            http://openocd.org/doc/doxygen/bugs.html
      Using JLINK
      JLINK serial 900036842
      Info : J-Link OB-K22-Cortex-M compiled Oct  9 2024 11:01:11
      Info : Hardware version: 1.00
      Info : GPIO supported
      Info : VTarget = 3.300 V
      Info : clock speed 100 kHz
      Warn : gdb services need one or more targets defined
      Open On-Chip Debugger 0.12.0-00020-gaf2e30d6d (2024-04-23-16:10)
      Licensed under GNU GPL v2
      For bug reports, read
      </pre><br>
