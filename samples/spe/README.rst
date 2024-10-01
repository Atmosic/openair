.. _spe:

Bluetooth: Secure Processing Environment sample
###############################################

Overview
********

Secure bootloader and secure processing environment for TrustZone-enabled
Atmosic chips. Configures hardware settings and allocates memory and
peripherals to secure and non-secure regions.

Requirements
************

* An Atmosic board that supports TrustZone (atm33evk, atm34evk)

Configuring the Memory Protection Controller (MPC)
**************************************************
Zephyr uses a dtsi binding called fixed-partitions to help allocate the memory
map to different memory regions. These regions are freely define-able by the
user and they offer the ability to allocate memory easily without modifying a
linker script.

Atmosic created a custom support partition binding called
atmosic,tz-fixed-parititions which stands for "TrustZone fixed partitions".
This binding is TrustZone-aware in that the user is able to dictate if the
partition should live in the secure or non-secure space. Additionally, it
supports nested partitions.

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

In the above code segment,  the spe_partition is indicated to be a secure
partition. The nspe_partition does not contain the flag and is presumed non-secure.

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

In the above code segment, the boot partition and the spe_partition (nested in
the slot0_partition) are treated as secure.

Build and Run
*************

atm33evk
--------

A convenient support script is provided in the Zephyr repository to build and
program this application. Please refer to::

   zephyr/boards/atmosic/atm33evk/doc/index.rst

Below are the steps for building and programming this application without
MCUBoot using ``west build`` and ``west flash`` directly.

Shell environment setup::

  APP=openair/hci_vendor
  BOARD=<chip>
  JLINK_SN=<"serial number">
  SPE=openair/samples/spe

Build commands:
  west build -p -s ${SPE} -b ${BOARD} -d build/${BOARD}/${SPE}
  west build -p -s ${HCI_UART} -b ${BOARD}_ns \
  -d build/${BOARD}_ns/${HCI_UART} \
  -- -DCONFIG_SPE_PATH=\"build/${BOARD}/${SPE}\"
