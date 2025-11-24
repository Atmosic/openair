.. _fhpf_module:
# FMDN Find Hub Precision Finding (FHPF) Module

This document describes the organization and usage of the FMDN Precision Finding functionality.

## File Organization

The precision finding functionality has been separated into its own module for better organization:

### Core Files
- **`fp_fhpf_gatt.c`** - Main precision finding implementation
- **`fp_fhpf_gatt.h`** - Precision finding header file
- **`Kconfig.fhpf`** - Precision finding configuration options

### Configuration
- **`Kconfig`** - Main FMDN configuration (includes Kconfig.fhpf)

### Documentation
- **`README_FHPF.md`** - This file

## Configuration Options

All precision finding related configurations are now in `Kconfig.fhpf`:

### Main Configuration
```kconfig
CONFIG_FMDN_PRECISION_FINDING=y    # Enable precision finding
```

### Ranging Technologies
```kconfig
CONFIG_FMDN_RANGING_OOB_DE_TYPE_UWB_EN=y      # Enable UWB ranging
CONFIG_FMDN_RANGING_OOB_DE_TYPE_BLE_CS_EN=y   # Enable BLE CS ranging
```

### BLE CS Specific Options
```kconfig
CONFIG_FMDN_RANGING_CS_SECURITY_LEVEL=2                    # Security level (1-4)
CONFIG_FMDN_RANGING_OOB_DE_TYPE_BLE_CS_CAP_FORCE_EN=n     # Force CS capability reply
```

## Integration

The FHPF module is automatically integrated into the FMDN GATT service and handles precision finding operations internally.

## Usage Example

### Basic Precision Finding with BLE CS
```kconfig
# Enable FMDN and precision finding
CONFIG_ATM_FMDN=y
CONFIG_FMDN_PRECISION_FINDING=y

# Enable BLE CS ranging
CONFIG_FMDN_RANGING_OOB_DE_TYPE_BLE_CS_EN=y
CONFIG_FMDN_RANGING_CS_SECURITY_LEVEL=2

# Required Bluetooth configurations (auto-selected)
CONFIG_BT_SMP=y
CONFIG_BT_BONDABLE=y
CONFIG_BT_BONDABLE_PER_CONNECTION=y
```

### With UWB Support
```kconfig
# Add UWB ranging support
CONFIG_FMDN_RANGING_OOB_DE_TYPE_UWB_EN=y
```

## Benefits of This Organization

1. **Separation of Concerns:** Precision finding logic is isolated from main GATT implementation
2. **Modular Configuration:** All precision finding options are in one place
3. **Easier Maintenance:** Changes to precision finding don't affect main FMDN code
4. **Better Testing:** Precision finding can be tested independently
5. **Clean Integration:** GATT service handles precision finding operations seamlessly

## Migration Notes

If you were previously using precision finding configurations directly in the main Kconfig:

- **Old:** Configurations were mixed with main FMDN options
- **New:** All precision finding configurations are in `Kconfig.fhpf`
- **Migration:** No changes needed - configurations are automatically included

The FMDN functionality remains the same, but the implementation is now better organized and more maintainable.
