.. _spe:

Basic: spe
##########

Overview
********

The SPE (Secure Processing Environment) sample implements a light weight secure application for Atmosic ARM (TM) Cortex-M (TM) based SoCs with TrustZone-M (TM) technology.  The SPE is a separate application from the regular Zephyr application.  The regular (or user) application is also referred to as the non-secure processing environment (NSPE) application.  The NSPE can have a significant attack surface since it runs the full application stack and interacts with the outside world through wireless interfaces and I/O devices.  The PSA (Platform Security Architecture, https://www.psacertified.org/) trade group defines the SPE/NSPE application architecture and its benefits for securing IoT products.

The role of the SPE is to configure TrustZone (TM) hardware settings, partition memory and I/O resources (secure/nonsecure) and bootstrap the NSPE application.  This isolates the SPE and NSPE in separate security domains and allows them to operate concurrently. The SPE, as a separate application, has its own memory areas (bss, stack, heap, data, code) isolated in the secure domain with various protection mechanisms.  To facilitate this, the SPE is installed to boot first from the built-in ROM bootloader or an installed secure bootloader such as MCUBOOT.  Note that MCUBOOT is not a SPE but rather a secondary bootloader that is bootstrapped by the ROM.   The boot process: `ROM->MCUBOOT->SPE->NSPE` form the secure bootchain for a typical secure application.  When secure boot is not used or during early application development, the boot chain can be reduced to simply: `ROM->SPE->NSPE`.

Unlike a bootloader, the SPE remains active and resident along with the NSPE application.  The SPE shares the same CPU core however the secure domain has a separate hardware context (registers, secure peripherals) for secure operation.  The NSPE can communicate with the SPE using Non-Secure Callable APIs (NSC APIs). These calls operate through compiler generated veneers to target a special region of memory in the SPE to transition to secure mode and redirect the entry point to the secure API.  Some functions such as cache management can only be done in secure mode and the SPE provides NSC cache management APIs for this purpose. The SPE has additional features to lock down devices and areas of memory. Security lockdowns are done in early boot before the NSPE starts.

The example SPE is sufficient to bootstrap any NSPE application. An example custom NSC function example is provided in the `openair/samples/spe/src/cust_sec_func/` folder.  NSC APIs are used to add services implemented in the SPE.

When developing custom NSC APIs in the SPE environment these guidelines should be followed:

* Functionality should be kept small, the larger the SPE the less memory is provided for the NSPE.
* The SPE should minimize console logging to avoid leaking secrets while also keeping the SPE small.
* The function should not use kernal APIs or threading primitives and only implement function calls that run to completion with no asynchronous behavior (i.e. avoid callbacks and interrupts).  The SPE does not support any form of inter-application communications mechanism that would allow for blocking or asynchronous behavior.
* The SPE should limit the use of hardware in the secure space.  Any HW in secure mode will isolate it from the non-secure side and will require additional NSC accessor functions for the NSPE to perform I/O.

Secure Fault Storage
********************

The SPE includes optional secure fault storage functionality that preserves fault information across system resets for debugging secure faults.

**Configuration:**

Controlled by ``ATM_SEC_FAULT_STORAGE`` definition and ``spe_fault_storage`` device tree node. When enabled:

1. **Allocates ATM_SEC_FAULT_STORAGE_SIZE bytes** at end of SRAM for fault storage
2. **Reduces main SRAM** by fault storage size
3. **Keeps fault storage secure**, main SRAM becomes non-secure
4. **Auto-records** fault data when secure faults occur

The SPE includes optional secure fault storage functionality that preserves fault information across system resets for debugging secure faults.

**Memory Layout:**

- Main SRAM: ``0x30000000`` to ``0x30000000 + (SRAM_SIZE - ATM_SEC_FAULT_STORAGE_SIZE)``
- Fault Storage: ``0x30000000 + SRAM_SIZE - ATM_SEC_FAULT_STORAGE_SIZE`` (``ATM_SEC_FAULT_STORAGE_SIZE`` bytes)

**Usage:**

``CONFIG_ATM_SPE_FAULT_STORAGE`` automatically enabled when ``spe_fault_storage`` device tree node exists.

Requirements
************

* An Atmosic board that supports TrustZone (atm33evk, atm34evk)


Configuring the Memory Protection Controller (MPC)
**************************************************
Zephyr uses a dtsi binding called ``fixed-partitions`` to configure non-volatile memory into separate labeled partitions that can be referenced in code and KConfigs. These regions are freely define-able by the user and they offer the ability to allocate memory easily without modifying a linker script.

Atmosic has created a custom partition binding called ``atmosic,tz-fixed-parititions`` which stands for "TrustZone fixed partitions". This binding is TrustZone-aware in that the user is able to dictate if the partition should live operate in the secure or non-secure domains. Additionally, it supports nested partitions in an upgradeable partition scheme.

Defining a Partition as Secure
-------------------------------

By default, all partitions are defaulted to non-secure.
To secure a partition, add the ``secure;`` flag to the partition in the dtsi file::

	&rram0 {
	    partitions {
		compatible = "atmosic,tz-fixed-partitions", "fixed-partitions";
		#address-cells = <1>;
		#size-cells = <1>;
		spe_partition: partition@ATM_SPE_NODE_ID {
		    label = "spe_partition";
		    secure;
		    reg = <ATM_SPE_OFFSET ATM_SPE_SIZE>;
		};
		    nspe_partition: partition@ATM_NSPE_NODE_ID {
		    label = "nspe_partition";
		    reg = <ATM_NSPE_OFFSET ATM_NSPE_SIZE>;
		};
	...

In the above code segment,  the spe_partition is indicated to be a secure partition. The nspe_partition does not contain the flag and is presumed non-secure.

Nested Partitions
-------------------------------
In practice, nested partitions are functionally the same to the user. See code segment below::

	&rram0 {
	    partitions {
		compatible = "atmosic,tz-fixed-partitions", "fixed-partitions";
		#address-cells = <1>;
		#size-cells = <1>;
		boot_partition: partition@0 {
		    label = "mcuboot";
		    secure;
		    reg = <0x00000 0xc000>;
		};
		slot0_partition: partition@10000 {
		    label = "image-0";
		    reg = <0x10000 0x6f800>;
		    partitions {
		    	#address-cells = <1>;
		    	#size-cells = <1>;
		    	spe_partition: partition@10000 {
			    label = "spe_partition";
			    secure;
			    reg = <0x10000 0x5800>;
		    	};
		    	nspe_partition: partition@15800 {
			    label = "nspe_partition";
			    reg = <0x15800 0x6a000>;
		    	};
		    };
		};

In the above code segment, the boot partition and the spe_partition (nested in the ``slot0_partition``) are treated as secure.  A system with upgradeable firmware through MCUBOOT utilizes nested partition.


Build and Run
*************

Running an application (NSPE) on a TrustZone enabled platform requires an extra SPE build/install step.  The SPE needs to be built first and its build output supplied to the application during its build process.  NSC API invocations in NSPE code are resolved by references in the SPE build.  There are sysbuild enabled examples in openair that can automatically build the SPE and provide this build to the application.  Sysbuild can also flash both the SPE and NSPE.

See :ref:`spe_nspe_architecture` for details on SPE/NSPE builds.

Increasing the Size of the SPE
------------------------------

The code partition size of the SPE can be increased through a device tree (DTS) flag: ``ATM_SPE_SIZE``.  This flag must be passed to all images including the NSPE and MCUBOOT (if used).  All images for a given board must have the same partition layout view.  The DTS flag will expand the SPE partition size and adjust other partitions accordingly.

Passing the DTS flag to an application::

  west build ... -- -DDTS_EXTRA_CPPFLAGS="-DATM_SPE_SIZE=0x10000;"


MCUBOOT Usage
*************

When using MCUBOOT, the SPE and NSPE binaries are merged together to form a single image upgrade unit.  In the final build steps of the NSPE application, the SPE image (previously built) is combined with the NSPE image and prepared for signing.  The SPE is offset by an MCUBOOT image header that contains image version and signature data.  The resulting merged binary is digitally signed by MCUBOOT image signing tools.  The signed image binary can be programmed by west (as a single image) and can be securely verified by MCUBOOT on startup or applied as an upgrade if the signed image is placed in the designated upgrade partition of the system.  Refer to sysbuild or MCUBOOT documentation on the build and flash commands when MCUBOOT is used.


Note on TF-M
************

Zephyr has been continually improving its security posture and security related features.  It has adopted a reference PSA implementation called TF-M (Trusted Firmware-M).  TF-M targets ARM Cortex-M platforms with TrustZone and for a time was available only as a separate project maintained outside of Zephyr.  TF-M consists of MCUBOOT as the secure bootloader (BL2) and a TF-M specific SPE application that forms the PSA upgradeable root of trust. The TF-M SPE has an extensive set of APIs and a collection of driver definitions/interfaces outside of Zephyr. Official support of TF-M on Atmosic platforms may be available in future releases.
