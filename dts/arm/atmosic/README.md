# Atmosic Board Device Tree Flags

This document describes the device tree preprocessor flags used in Atmosic board configurations.

## Overview

These flags control how the device tree is processed and compiled for different build configurations and security modes on Atmosic platforms.

## Flags

### ATM_NO_TZ

**Purpose:** Disables TrustZone security features and runs the application as a single secure image without SPE (Secure Processing Environment) partition.

**Usage:**
- Removes both the SPE partition and TrustZone application isolation features
- Runs a single application as a secure image
- TrustZone protection mechanisms are not enabled and minimally initialized

**Example:**
```
   -DDTS_EXTRA_CPPFLAGS=-DATM_NO_TZ
```

**Device Tree Impact:**
- Uses `app_partition` as the code partition
- Assigns SOC and board resources to the single secure image where there is no SPE/NSPE domain separation.

---

### ATM_NS_APP

**Purpose:** Indicates that the device tree is being processed for a non-secure application in a TrustZone-enabled system.

**Usage:**
- Used in TrustZone configurations where the application runs in non-secure mode
- Enables non-secure peripheral access and memory mapping
- Allows independent operation of secure and non-secure images
- This option is only intended for the user application and must not be used when building the SPE or MCUBOOT images.

**Device Tree Impact:**
- Uses `nspe_partition` as the code partition
- Resources are mapped for non-secure use and adjusted due to the SPE/NSPE image domains.

**Example:**
```
   -DDTS_EXTRA_CPPFLAGS=-DATM_NS_APP
```

---

### ATM_SPE_APP

**Purpose:** Indicates that the device tree is being processed for a secure application in a TrustZone-enabled system.

**Usage:**
- Used in TrustZone configurations where the application runs in secure mode (SPE)
- Enables secure peripheral access and memory mapping
- Allows independent operation of secure and non-secure images
- This option is only intended for sample SPE application.
- This option should be set when building MCUBOOT since it uses the same board file.

**Device Tree Impact:**
- Uses `spe_partition` as the code partition
- Resources are mapped for secure use and adjusted due to the SPE/NSPE image domains.

**Example:**
```
   -DDTS_EXTRA_CPPFLAGS=-DATM_SPE_APP
```

---

### ATM_DTS_USER_APP

**Purpose:** Indicates that the device tree is being processed as the user application in either a no-TZ (no TrustZone) or NS (non-secure) image configuration.

**Usage:**
- Enables user application-specific device tree resources (e.g., I2C configurations)
- Controls which peripherals and resources are available to the user application
- Automatically set if ATM_NO_TZ or ATM_NS_APP is set.
- Will not be set for the SPE image.
- Since MCUBOOT shares the same board file a no-TZ image can set ``ATM_DTS_MCUBOOT`` to limit the visibility of user application resources.

---

### ATM_DTS_MCUBOOT

**Purpose:** Indicates that the device tree is being processed for the MCUboot bootloader build.

**Usage:**
- Set automatically during sysbuild to prevent user application resources from being visible to MCUBOOT.
- Prevents unecessary resource additions to the bootloader since the same board file is used with the main image.

**Example:**
```
   -DDTS_EXTRA_CPPFLAGS=-DATM_DTS_MCUBOOT
```

---

### USE_ATM_SECURE_DEBUG

**Purpose:** Enables secure debug authentication features in MCUboot, allowing authenticated UART-based debug access.

**Usage:**
- Passed as a device tree preprocessor flag during MCUboot builds
- Enables UART0 as a bi-directional console port for authentication
- Works in conjunction with `CONFIG_ATM_MCUBOOT_SECURE_DEBUG` Kconfig option
- Requires an ECC-P256 private key for signing debug sessions

**Example:**
```
  -DCONFIG_ATM_MCUBOOT_SECURE_DEBUG=y -DDTS_EXTRA_CPPFLAGS="-DUSE_ATM_SECURE_DEBUG"
```
