.. _fhn_v2_module:

FMDN Find Hub Network (FHN) v2 Module
######################################

This document describes the FHN v2 implementation, new features, and migration guide from FMDN v1.

Overview
********

FHN v2 (Find Hub Network version 2) is an update to the Fast Pair Find My Device Network specification that introduces:
- **Persistent Connection** - Allows Seekers to maintain long-term connections with Providers
- **Reverse Ringing** - Enables Providers to initiate ringing on Seekers (e.g., via button press)
- **Enhanced Security** - Client ID ownership protection across power cycles
- **Improved Scalability** - Support for up to 16 account keys (vs 5 in v1)

Protocol Version
****************

The protocol major version is controlled by `CONFIG_FAST_PAIR_FMDN_V2`:
- **v2 (0x02)**: When `CONFIG_FAST_PAIR_FMDN_V2=y` (FHN v2 features enabled)
- **v1 (0x01)**: When `CONFIG_FAST_PAIR_FMDN_V2=n` (legacy FMDN v1 mode)

**Important**: Current Google Play services and Find Hub app only support v1. v2 support will be added in future updates.

File Organization
*****************

Core FHN v2 Files
=================
- **`fp_fmdn_persistent_conn.c`** - Persistent connection management
- **`fp_fmdn_persistent_conn.h`** - Persistent connection API
- **`fp_fmdn_sba_gatt.c`** - Secure Beacon Actions GATT service (v2 only)
- **`fp_fmdn_sba_gatt.h`** - Secure Beacon Actions API
- **`fp_fmdn_reverse_ringing.c`** - Reverse ringing implementation
- **`fp_fmdn_reverse_ringing.h`** - Reverse ringing API

### Shared Files (v1 and v2)
- **`fp_fmdn_gatt.c`** - Main FMDN GATT service (Beacon Actions)
- **`fp_fmdn_key.c`** - EID key management and clock
- **`fp_fmdn_ring.c`** - Ring request handling
- **`fp_fmdn_internal.h`** - Internal definitions and version control

### Configuration
- **`Kconfig`** - Main FMDN configuration
- **`Kconfig.fhpf`** - Precision finding configuration (optional)

### Documentation
- **`README_FHN_V2.md`** - This file
- **`README_FHPF.md`** - Precision finding documentation

## Configuration Options

### Enable FHN v2
```kconfig
CONFIG_FAST_PAIR_FMDN_V2=y                    # Enable FHN v2 features
CONFIG_FAST_PAIR_MAX_ACCOUNT_KEY_COUNT=16     # Support up to 16 account keys
```

### Persistent Connection
```kconfig
CONFIG_FMDN_PERSISTENT_CONNECTION=y           # Enable persistent connection feature
```

**Features:**
- Allows Seeker to maintain long-term connection with Provider
- Five connection types (see table below)
- Client ID ownership protection across power cycles
- Force bit mechanism for ownership takeover
- Connection interval negotiation support

### Reverse Ringing
```kconfig
CONFIG_FMDN_REVERSE_RINGING=y                 # Enable reverse ringing feature
```

**Features:**
- Provider can initiate ringing on Seeker (e.g., button press)
- Configurable ringing timeout (default: 30 seconds)
- Automatic stop on timeout or Seeker acknowledgment
- Requires persistent connection to be active

## Key Features

### 1. Persistent Connection

**Purpose**: Allows Seeker to maintain a long-term connection with the Provider for faster operations.

**Client ID Ownership Protection**:
- When a Seeker configures persistent connection with **force bit (0x01)**, the Provider saves the Client ID to NVS
- After power loss/restart, only that Seeker (or a new Seeker with force bit) can configure persistent connection
- This prevents unauthorized takeover after power cycles

**Connection Types** (per FHN v2 spec):
| Type | Value | Connection Interval | Advertisement Interval | Connectable |
|------|-------|---------------------|----------------------|-------------|
| Non-persistent | 0x00 | 30-100ms | Default (≥2s) | Yes |
| Persistent Interactive | 0x01 | 30-100ms | ≥30s | Yes |
| Persistent Connectable | 0x02 | ≤800ms | ≥3s | Yes |
| Persistent Detectable | 0x03 | ≤800ms | ≥30s | No |
| Persistent Undetectable | 0x04 | ≤800ms | None | No |

**Configuration Flags**:
- **Force bit (0x01)**: Disconnect existing persistent connection and take over
- **Negotiate bit (0x02)**: Provider should negotiate connection interval

**After Power Loss**:
- Provider does NOT remember connection configuration
- Provider DOES remember Client ID (if force bit was used)
- Seeker must reconnect and reconfigure features
- Provider advertises FHN frame every 2 seconds when not connected

### 2. Reverse Ringing

**Purpose**: Allows Provider to initiate ringing on the Seeker (e.g., user presses button on tag to find phone).

**Configuration**:
- Seeker sends configuration with timeout value (seconds)
- Provider stores configuration and can trigger ringing later

**Triggering**:
- Provider calls `fp_fmdn_reverse_ringing_trigger()` (e.g., from button handler)
- Provider sends indication to Seeker via Secure Beacon Actions characteristic
- Seeker starts ringing and sends acknowledgment
- Ringing stops on timeout or Seeker acknowledgment

**Requirements**:
- Persistent connection must be active
- Seeker must have configured reverse ringing

### 3. Capabilities Bitmap

The capabilities bitmap (octet 8 of Beacon Parameters) indicates supported features:

| Bit | Feature | Value |
|-----|---------|-------|
| 0 | Persistent Connection | 0x01 |
| 1 | Reverse Ringing | 0x02 |
| 2-7 | Reserved | 0x00 |

**Automatic Calculation**:
```c
// Calculated at compile-time based on Kconfig
#define FP_FMDN_V2_CAPABILITIES_BITMAP \
    (0 \
     | (IS_ENABLED(CONFIG_FMDN_PERSISTENT_CONNECTION) ? 0x01 : 0x00) \
     | (IS_ENABLED(CONFIG_FMDN_REVERSE_RINGING) ? 0x02 : 0x00))
```

## Storage and Persistence

### NVS Storage Keys

FHN v2 adds the following NVS storage:

| Key | Purpose | Persists Across Power Loss |
|-----|---------|----------------------------|
| `pc_client_id` | Persistent connection client ID | ✅ Yes |
| `fmdn_clock` | FMDN clock value (seconds) | ✅ Yes |
| `eid_key` | EID key | ✅ Yes |
| `utp_mode` | Unwanted Tracking Protection mode | ✅ Yes |

### Flash Partition Sizing

NVS reserves one full sector for garbage collection, so the **usable** space is always
`ATM_STORAGE_SIZE − one_sector`. Atmosic devices use 1 KB NVS sectors (0x400 bytes each).

| Configuration | ATM_STORAGE_SIZE | Usable NVS | Rationale |
|---|---|---|---|
| FHN v2 only (16 bonds) | `0x2000` (8 KB) | 7 KB (7 of 8 sectors) | ~3.4 KB required; 3.7 KB headroom |
| FHN v2 + FMNA combined (16 bonds) | `0x3000` (12 KB) | 11 KB (11 of 12 sectors) | ~4.6 KB required (FHN ~3.4 KB + FMNA ~1.2 KB); 6.4 KB headroom |

**Storage footprint breakdown for FHN v2 with 16 bonds:**

| Component | Size |
|---|---|
| BT bond keys (16 × 121 B) | ~1.9 KB |
| CCC blobs (16 × 57 B) | ~0.9 KB |
| Account key list (16 × 16 B + overhead) | ~302 B |
| Fixed overhead (EID key, IRK, clock, PC client ID, etc.) | ~276 B |
| **Total required** | **~3.4 KB** |

`0x2000` provides 7 KB usable (7 of 8 sectors), leaving ~3.7 KB of headroom over the worst-case
16-bond footprint. In practice, 16 concurrent bonds is unlikely, making this budget more than
sufficient.

### Factory Reset

Factory reset (`atm_gfp_reset()`) clears:
- ✅ All 16 account keys
- ✅ Persistent connection client ID
- ✅ FMDN clock
- ✅ EID key
- ✅ UTP mode
- ✅ All Bluetooth bonds

## Migration from FMDN v1 to FHN v2

### Configuration Changes

**Old (FMDN v1)**:
```kconfig
CONFIG_ATM_FMDN=y
CONFIG_FAST_PAIR_MAX_ACCOUNT_KEY_COUNT=5      # v1 limit
```

**New (FHN v2)**:
```kconfig
CONFIG_ATM_FMDN=y
CONFIG_FAST_PAIR_FMDN_V2=y                    # Enable v2 features
CONFIG_FAST_PAIR_MAX_ACCOUNT_KEY_COUNT=16     # v2 limit
CONFIG_FMDN_PERSISTENT_CONNECTION=y           # Optional: Enable persistent connection
CONFIG_FMDN_REVERSE_RINGING=y                 # Optional: Enable reverse ringing
```

### Code Changes

**No code changes required** - The implementation is backward compatible:
- v1 Seekers will work with v2 Providers (when `BCNA_MJR_VER=0x01`)
- v2 features are only enabled when `CONFIG_FAST_PAIR_FMDN_V2=y`
- Account key storage automatically handles up to 16 keys

### Testing Checklist

- [ ] Verify protocol version in Beacon Actions read response (octet 0)
- [ ] Verify capabilities bitmap (octet 8) matches enabled features
- [ ] Test persistent connection configuration with force bit
- [ ] Test power cycle with saved client ID
- [ ] Test factory reset clears all data including client ID
- [ ] Verify account key limit increased to 64
- [ ] Test reverse ringing trigger and acknowledgment

## API Reference

### Persistent Connection

```c
/**
 * @brief Initialize persistent connection module
 * Loads saved client ID from NVS (if any)
 */
int fp_fmdn_persistent_conn_init(void);

/**
 * @brief Configure persistent connection
 * @param conn BLE connection handle
 * @param flags Configuration flags (force bit, negotiate bit)
 * @param client_id Client ID from Seeker
 * @param conn_type Connection type (0x00-0x02)
 * @return PC_RESULT_SUCCESS or error code
 */
pc_result_t fp_fmdn_persistent_conn_configure(struct bt_conn *conn, uint8_t flags,
                                               uint8_t client_id, uint8_t conn_type);

/**
 * @brief Get current persistent connection state
 */
const fp_fmdn_persistent_conn_state_t *fp_fmdn_persistent_conn_get_state(void);

/**
 * @brief Handle disconnection event
 */
void fp_fmdn_persistent_conn_on_disconnect(struct bt_conn *conn);
```

### Reverse Ringing

```c
/**
 * @brief Initialize reverse ringing module
 */
int fp_fmdn_reverse_ringing_init(void);

/**
 * @brief Configure reverse ringing
 * @param timeout Ringing timeout in seconds
 */
int fp_fmdn_reverse_ringing_configure(uint16_t timeout);

/**
 * @brief Trigger reverse ringing (e.g., from button press)
 * @return 0 on success, negative error code on failure
 */
int fp_fmdn_reverse_ringing_trigger(void);

/**
 * @brief Stop reverse ringing
 */
void fp_fmdn_reverse_ringing_stop(void);
```

### Storage

```c
/**
 * @brief Save persistent connection client ID to NVS
 */
void fp_storage_pc_client_id_save(uint8_t client_id);

/**
 * @brief Get saved persistent connection client ID
 * @return 0 on success, -ENOENT if not saved
 */
int fp_storage_pc_client_id_get(uint8_t *client_id);

/**
 * @brief Check if client ID is saved
 */
bool fp_storage_pc_client_id_valid(void);
```

## Troubleshooting

### Issue: Seeker cannot configure persistent connection after restart

**Cause**: Provider has saved client ID from previous session, but Seeker is not using force bit.

**Solution**: Seeker must use force bit (0x01) to reconfigure after Provider restart.

### Issue: Capabilities bitmap shows 0x00 instead of 0x03

**Cause**: `CONFIG_FAST_PAIR_FMDN_V2` is not enabled, or features are not enabled in Kconfig.

**Solution**:
```kconfig
CONFIG_FAST_PAIR_FMDN_V2=y
CONFIG_FMDN_PERSISTENT_CONNECTION=y
CONFIG_FMDN_REVERSE_RINGING=y
```

### Issue: Factory reset does not clear client ID

**Cause**: `fp_storage_pc_client_id_delete()` not called in reset flow.

**Solution**: Verify `fp_storage_eid_reset()` includes client ID deletion (already implemented).

### Issue: Protocol version shows 0x01 instead of 0x02

**Cause**: `CONFIG_FAST_PAIR_FMDN_V2` is not enabled.

**Solution**: Enable in `prj.conf`:
```kconfig
CONFIG_FAST_PAIR_FMDN_V2=y
```

## Implementation Notes

### Ownership Protection Logic

The persistent connection ownership protection works as follows:

1. **First Configuration** (no saved client ID):
   - Without force bit: Accept, don't save client ID
   - With force bit: Accept, save client ID to NVS

2. **After Restart** (saved client ID exists):
   - Without force bit: **REJECT** (ownership protection)
   - With force bit: Accept, save new client ID to NVS

3. **Active Connection** (connection already persistent):
   - Same connection: Reconfigure
   - Different connection without force bit: **REJECT**
   - Different connection with force bit: Disconnect old, accept new

### Connection Interval Negotiation

When negotiate bit (0x02) is set:
- Provider should negotiate connection interval with Seeker
- Recommended intervals: 30ms - 50ms for persistent connection
- Implementation is application-specific

### Reverse Ringing Timeout

- Default timeout: 30 seconds
- Configurable by Seeker during configuration
- Provider automatically stops ringing on timeout
- Seeker can stop ringing by sending acknowledgment

## References

- **FHN v2 Specification**: Google Fast Pair Find My Device Network v2
- **FMDN v1 Specification**: Google Fast Pair Find My Device Network v1
- **Zephyr Bluetooth**: https://docs.zephyrproject.org/latest/connectivity/bluetooth/
- **Atmosic FMDN Implementation**: `openair/subsys/bluetooth/services/gfp/fmdn/`

## Copyright

Copyright (C) Atmosic 2026
