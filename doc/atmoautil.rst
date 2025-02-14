.. Define CSS format
.. role:: codebox
   :class: code-box

.. role:: redtext
   :class: red-text

.. role:: bluetext
   :class: blue-text

.. raw:: html

   <style>
      .red-text {
         color: red;
         font-weight: bold;
      }
      .blue-text {
         color: blue;
         font-weight: bold;
      }
      .white-border-table table {
         border-collapse: collapse;
         width: 100%;
      }
      .white-border-table th {
         background-color: #EDEDED;
         color: rgb(37, 37, 37);
         padding: 10px;
         border: 1px solid white !important;
      }
      .white-border-table td {
         background-color: white;
         color: rgb(37, 37, 37);
         padding: 10px;
         border: 1px solid black !important;
      }
      .code-box {
         color: gray;
         border: 1px solid #C4C4C4;
         display: inline-block;
         white-space: pre-wrap;
         background-color: #F5F5F5;
         padding: 10px;
         width: auto;
      }
      body {
         font-family: Arial, sans-serif;
      }
      .black-code-box {
         background-color: black;
         color: white;
         padding: 10px;
         border-radius: 5px;
         white-space: pre-wrap;
         width: auto;
      }
      div.note {
         background-color: #f7f7f7;
         border-left: 5px solid #2d87f0;
         padding: 10px 10px;
         margin: 10px 0;
         font-size: 1rem;
         color: #333;
         box-shadow: 0px 2px 5px rgba(0, 0, 0, 0.1);
         position: relative;
         word-wrap: break-word;
      }
      div.note h4 {
         margin-top: 0;
         font-weight: bold;
         color: #2d87f0;
         position: relative;
         z-index: 1;
         padding: 0px 5px;
      }
      div.note::before {
         content: "";
         position: absolute;
         top: 0;
         left: 0;
         right: 0;
         height: 20%;
         background-color: rgb(205, 226, 250);
         z-index: 0;
      }
      div.note p {
         margin: 0px 0;
         white-space: pre-wrap;
      }
   </style>

Atmosic Open Air Utility
########################
Atmosic Open Air Utility (atmoautil) is an unified tool for Zephyr, and the purpose is reducing the effort for developers to set up the develop environment for Atmosic Open Air SDK. The atmoautil could manage and download the Zephyr toolchain, Python, Git … on the Internet through the URL list at Download section. Please refer to the Commands section to see the complete list of functions.

Download
========
Before setting up the toolchain, please install the available executable for your operating system to ensure proper functionality.

.. list-table::
   :header-rows: 1
   :widths: auto
   :class: white-border-table

   * - Operating System
   * - `Windows <https://atmosic.com/public/atmoautil/Tool/Windows/atmoautil.zip>`_
   * - `Linux <https://atmosic.com/public/atmoautil/Tool/Linux/atmoautil.tgz>`_
   * - MacOS (Not supported)

|

.. raw:: html

   <div class="note">
      <h4>Note (for the Windows users):</h4>
      <p>
         Please add atmoautil.exe to the “Exclusions” due to the atmoautil.exe file not signed yet.

         1. Go to “Settings” / “Privacy & security” / “Windows Security” / “Virus & threat protection”
         2. Click the “Manage settings” of “Virus & threat protection settings” region
         3. Scroll down to the “Exclusions” and click the “Add or remove exclusions”
         4. Click “Add an exclusion” and apply atmoautil.exe to the exclusion list.
      </p>
   </div>

|

Commands
========

The table below lists the available commands of Atmosic Open Air Utility (atmoautil). Detailed descriptions of the commands can be found in the section below.

.. list-table::
   :header-rows: 1
   :widths: auto
   :class: white-border-table

   * - Command
     - Explanation
   * - Basic
     -
   * - -h, --help
     - Show this help message and exit.
   * - -d, --debug
     - Enable debug mode. (Internal Used)
   * - --default_cmd
     - Command to execute before entering CLI loop. (Internal Used)
   * - -s, --show_log
     - Display detailed log information. (For debug)
   * - Manager
     -
   * - ?, help
     - List commands.
   * - toolchain_install
     - Install a specific version of the toolchain.
   * - toolchain_uninstall
     - Uninstall the currently installed toolchain.
   * - toolchain_launch
     - Launch the installed toolchain.
   * - toolchain_list
     - List all available and installed versions of the toolchain.
   * - show_version
     - Show version of the tool.
   * - install_rdi
     - Install RDI driver. (Windows Only)
   * - uninstall_rdi
     - Uninstall RDI driver. (Windows Only)
   * - exit
     - Exit Atmosic Open Air Utility CLI.

|

Basic
-----

1. **-h, --help**

   Show information about all commands.

   **Syntax**

   atmoautil [-h | --help]

|

2. **-d, --debug (Internal Used)**

   Enable debug mode.

   **Syntax**

   atmoautil -d

   **Example**
   Please follow the The atmoautil tool - Phase 2 | Why is debug mode required? to generate server_setting.xml file.

   .. raw:: html

      <pre class="black-code-box">
      $ atmoautil.exe -d
      Welcome to Atmosic Open Air Utility CLI. Type 'help' or '?' to list commands.
      </pre>

|

3. **--default_cmd (Internal Used)**

   Command to execute before entering CLI loop

   **Syntax**

   atmoautil --default_cmd DEFAULT_CMD

   **Example**

   Enter the command in advance before launching the atmoautil.

   .. raw:: html

      <pre class="black-code-box">
      $ atmoautil.exe -d --default_cmd "toolchain_launch -v 25.02.0"
      </pre>

|

4. **--show_log**

   Command to display detailed log information (For debug)

   **Syntax**

   atmoautil -s

   **Example**

   Enter the command in advance before launching the atmoautil.

   .. raw:: html

      <pre class="black-code-box">
      $ atmoautil.exe -d -s
      ❕❕ Enable Debug Mode ❕❕
      Welcome to Atmosic Open Air Utility CLI. Type 'help' or '?' to list commands.
      </pre>

|

Manager
-------

1. **?, help**

   List commands

   **Syntax**

   [? | help]

   **Example**

   .. raw:: html

      <pre class="black-code-box">
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

|

2. **show_version**

   Show the atmoautil version

   **Syntax**

   show_version

   **Example**

   .. raw:: html

      <pre class="black-code-box">
      (atmoautil) manager> show_version
      ╔══════════════════════════╗
      ║ Tool Version: 1.0.0.0.56 ║
      ╚══════════════════════════╝
      </pre>

|

3. **exit**

   Exit Atmosic Open Air Utility CLI.

   **Syntax**

   exit

   **Example**

   .. raw:: html

      <pre class="black-code-box">
      (atmoautil) manager> exit
      Exiting Atmosic Open Air Utility CLI.
      </pre>

|

4. **toolchain_list**

   List available toolchain(s) in the server and installed toolchain(s) on local. The atmoautil will download a configure file from server to check the available toolchain(s).

   **Example**

   .. raw:: html

      <pre class="black-code-box">
      (atmoautil) manager> toolchain_list
      ╔════════════════════════╗
      ║ Toolchain Version List ║
      ╚════════════════════════╝
      25.02.0
      </pre>

|

5. **toolchain_install**

   Install a specific version of the toolchain.

   **Syntax**

   toolchain_install [-v | --version] VERSION
   The VERSION could get from toolchain_list command

   **Example**

   .. raw:: html

      <pre class="black-code-box">
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

|

6. **toolchain_launch**

   Launch the installed toolchain for Zephyr development

   ***Syntax**

   toolchain_launch [-v | --version] VERSION
   The VERSION could get from toolchain_List command and please specify the installed one.

   **Example**

   On Windows, it will invoke new Windows command prompt after launching.

   .. raw:: html

      <pre class="black-code-box">
      ╔═══════════════════════════════════════════╗
      ║     Atmosic Zephyr Develop Environment    ║
      ╚═══════════════════════════════════════════╝
      Type 'exit' to quit...
      (25.02.0) C:\Temp\atmoautil>
      </pre>

|

7. **toolchain_uninstall**

   Uninstall the currently installed toolchain.
   This command only show the toolchain directory and the developer should manual remove it because the developer may install the require components by themselves.

   **Syntax**

   toolchain_uninstall [-v | --version] VERSION
   The VERSION could get from toolchain_List command and please specify the installed one.

   **Example**

   .. raw:: html

      <pre class="black-code-box">
      (atmoautil) manager> toolchain_uninstall -v 25.02.0
      Please manually remove the toolchain directory under the C:\atmoa\toolchains path.
      </pre>

|

8. **install_rdi**

   This command only for Windows.
   Install the RDI driver.

   **Syntax**

   install_rdi

   **Example**

   .. raw:: html

      <pre class="black-code-box">
      (atmoautil) manager> install_rdi
      ╔════════════════════╗
      ║ Install RDI driver ║
      ╚════════════════════╝
      Install RDI Done
      </pre>

|

9. **uninstall_rdi**

   This command only for Windows.
   Uninstall the RDI driver.

   **Syntax**

   uninstall_rdi

   **Example**

   .. raw:: html

      <pre class="black-code-box">
      (atmoautil) manager> uninstall_rdi
      ╔══════════════════════╗
      ║ UnInstall RDI driver ║
      ╚══════════════════════╝
      UnInstall RDI driver failed
      </pre>

|

Install toolchain
=================

1. Download and extract the atmoautil from website. (`The atmoautil User Guide | Download <https://atmosic.atlassian.net/wiki/spaces/ST/pages/edit-v2/1008959532#Download>`_)
2. Open a terminal window and execute atmoautil command.

   :codebox:`atmoautil.exe`

3. Run the following command to install the toolchain.

   :codebox:`toolchain_install -v 25.02.0`

4. Launch develop environment through atmoautil by “toolchain_launch” command. It will pop-up a new Windows command prompt which the window title shows “Atmosic Zephyr” for Windows user. Subsequently, go to the atmoa directory and create zephyrproject folder. (For the Windows user, “cd C:\atmoa”, for the Linux user,  “cd ~/atmoa”)

   :codebox:`toolchain_launch -v 25.02.0`

5. Checkout source code from internal or public. Please make sure add you account before the domain name if the OS login user not using your Atmosic account.

- :bluetext:`Internal repository`: login user use Atmosic account

   :codebox:`west init -m ssh://git.sj.atmosic.com/prj/digital/db/zephyrproject-rtos/apps-internal.git
   west update`

- :bluetext:`Internal repository`: login user :redtext:`NOT` use Atmosic account. Please modify the "atmosic-internal/west.yml" file as well after "west init".

   :codebox:`west init -m ssh://<account>@git.sj.atmosic.com/prj/digital/db/zephyrproject-rtos/apps-internal.git
   # modify zephyproject/atmosic-internal/west.yml
   west update`

   - Console log

   .. raw:: html

      <pre class="black-code-box">
      (25.02.0) C:\atmoa\zephyrproject>west init -m ssh://thsieh@git.sj.atmosic.com/prj/digital/db/zephyrproject-rtos/apps-internal.git
      === Initializing in C:\atmoa\zephyrproject
      --- Cloning manifest repository from ssh://thsieh@git.sj.atmosic.com/prj/digital/db/zephyrproject-rtos/apps-internal.git
      Cloning into 'C:\atmoa\zephyrproject\.west\manifest-tmp'...
      warning: templates not found in C:\atmoa/toolchains/25.02.0/git/share/git-core/templates
      (thsieh@git.sj.atmosic.com) Password:
      remote: Enumerating objects: 5523, done.
      remote: Counting objects: 100% (59/59), done.
      remote: Compressing objects: 100% (52/52), done.
      remote: Total 5523 (delta 8), reused 0 (delta 0), pack-reused 5464
      Receiving objects: 100% (5523/5523), 170.52 MiB | 5.38 MiB/s, done.
      Resolving deltas: 100% (3268/3268), done.
      --- setting manifest.path to atmosic-internal
      === Initialized. Now run "west update" inside C:\atmoa\zephyrproject.
      </pre>

   |

   - zephyproject/atmosic-internal/west.yml (Modify the <account> section)

   .. raw:: html

      <pre class="black-code-box">
      # This is a copy of the west file in the openair repository with differences:
      #
      # 1) Internal repositories in atmosic/west.yml are redirected.  (Unfortunately,
      #    as of west v1.1.0, the entire content of a "project", including the
      #    name-allow lists, has to be replicated.  There's no "inheritance" rule or
      #    partial override capability.)
      #
      # 2) openair is imported (obviously)

      manifest:
      version: "0.10"
      group-filter: [-optional]
      remotes:
         - name: atm_internal
            url-base: ssh://account@git.sj.atmosic.com/prj/digital/db
      defaults:
         remote: atm_internal
      </pre>

- :bluetext:`Public repository`:

   :codebox:`west init -m https://github.com/Atmosic/openair.git
   west update`

6. Build sample - hello_world in openair.

   :codebox:`west build -p always --sysbuild openair/samples/sysbuild/hello_world -b ATMEVK-3330e-QN-5//ns -T samples.sysbuild.hello_world.atm`

   For Example:

   .. raw:: html

      <pre class="black-code-box">
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

   .. raw:: html

      <div class="note">
         <h4>Note</h4>
         <p>The Zephyr stock samples support System Build (sysbuild) as well. Please apply following commands to apply test cast to stock samples.

            $ cd zephyrproject
            $ python3 openair/tools/scripts/sysbuild_utils.py -r zephyr gen
         </p>
      </div>

|

7. [Windows] Install RDI driver if need
8. Program firmware to EVK

   :codebox:`west flash --skip-rebuild --fast_load --device=<JLINK_SERIAL> --jlink`

   For Example:

   .. raw:: html

      <pre class="black-code-box">
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
      </pre>