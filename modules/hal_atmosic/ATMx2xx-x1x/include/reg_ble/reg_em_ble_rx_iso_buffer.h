#ifndef _REG_EM_BLE_RX_ISO_BUFFER_H_
#define _REG_EM_BLE_RX_ISO_BUFFER_H_

#include <stdint.h>
#include "_reg_em_ble_rx_iso_buffer.h"
#include "compiler.h"
#include "arch.h"
#include "em_map.h"
#include "reg_access.h"

#define REG_EM_BLE_RX_ISO_BUFFER_COUNT 4

#define REG_EM_BLE_RX_ISO_BUFFER_DECODING_MASK 0x00000007

#define REG_EM_BLE_RX_ISO_BUFFER_ADDR_GET(idx) (EM_BLE_RX_ISO_BUFFER_OFFSET + (idx) * REG_EM_BLE_RX_ISO_BUFFER_SIZE)

/**
 * @brief RXISOBUFSETUP register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  15:14                 INVL   0x0
 *  07:00          RXISOLENGTH   0x0
 * </pre>
 */
#define EM_BLE_RXISOBUFSETUP_ADDR   (0x30008000 + EM_BLE_RX_ISO_BUFFER_OFFSET)
#define EM_BLE_RXISOBUFSETUP_INDEX  0x00000000
#define EM_BLE_RXISOBUFSETUP_RESET  0x00000000

__INLINE uint16_t em_ble_rxisobufsetup_get(int elt_idx)
{
    return EM_BLE_RD(EM_BLE_RXISOBUFSETUP_ADDR + elt_idx * REG_EM_BLE_RX_ISO_BUFFER_SIZE);
}

__INLINE void em_ble_rxisobufsetup_set(int elt_idx, uint16_t value)
{
    EM_BLE_WR(EM_BLE_RXISOBUFSETUP_ADDR + elt_idx * REG_EM_BLE_RX_ISO_BUFFER_SIZE, value);
}

// field definitions
#define EM_BLE_INVL_MASK          ((uint16_t)0x0000C000)
#define EM_BLE_INVL_LSB           14
#define EM_BLE_INVL_WIDTH         ((uint16_t)0x00000002)
#define EM_BLE_RXISOLENGTH_MASK   ((uint16_t)0x000000FF)
#define EM_BLE_RXISOLENGTH_LSB    0
#define EM_BLE_RXISOLENGTH_WIDTH  ((uint16_t)0x00000008)

#define EM_BLE_INVL_RST           0x0
#define EM_BLE_RXISOLENGTH_RST    0x0

__INLINE void em_ble_rxisobufsetup_pack(int elt_idx, uint8_t invl, uint8_t rxisolength)
{
    ASSERT_ERR((((uint16_t)invl << 14) & ~((uint16_t)0x0000C000)) == 0);
    ASSERT_ERR((((uint16_t)rxisolength << 0) & ~((uint16_t)0x000000FF)) == 0);
    EM_BLE_WR(EM_BLE_RXISOBUFSETUP_ADDR + elt_idx * REG_EM_BLE_RX_ISO_BUFFER_SIZE,  ((uint16_t)invl << 14) | ((uint16_t)rxisolength << 0));
}

__INLINE void em_ble_rxisobufsetup_unpack(int elt_idx, uint8_t* invl, uint8_t* rxisolength)
{
    uint16_t localVal = EM_BLE_RD(EM_BLE_RXISOBUFSETUP_ADDR + elt_idx * REG_EM_BLE_RX_ISO_BUFFER_SIZE);

    *invl = (localVal & ((uint16_t)0x0000C000)) >> 14;
    *rxisolength = (localVal & ((uint16_t)0x000000FF)) >> 0;
}

__INLINE uint8_t em_ble_rxisobufsetup_invl_getf(int elt_idx)
{
    uint16_t localVal = EM_BLE_RD(EM_BLE_RXISOBUFSETUP_ADDR + elt_idx * REG_EM_BLE_RX_ISO_BUFFER_SIZE);
    return ((localVal & ((uint16_t)0x0000C000)) >> 14);
}

__INLINE void em_ble_rxisobufsetup_invl_setf(int elt_idx, uint8_t invl)
{
    ASSERT_ERR((((uint16_t)invl << 14) & ~((uint16_t)0x0000C000)) == 0);
    EM_BLE_WR(EM_BLE_RXISOBUFSETUP_ADDR + elt_idx * REG_EM_BLE_RX_ISO_BUFFER_SIZE, (EM_BLE_RD(EM_BLE_RXISOBUFSETUP_ADDR + elt_idx * REG_EM_BLE_RX_ISO_BUFFER_SIZE) & ~((uint16_t)0x0000C000)) | ((uint16_t)invl << 14));
}

__INLINE uint8_t em_ble_rxisobufsetup_rxisolength_getf(int elt_idx)
{
    uint16_t localVal = EM_BLE_RD(EM_BLE_RXISOBUFSETUP_ADDR + elt_idx * REG_EM_BLE_RX_ISO_BUFFER_SIZE);
    return ((localVal & ((uint16_t)0x000000FF)) >> 0);
}

__INLINE void em_ble_rxisobufsetup_rxisolength_setf(int elt_idx, uint8_t rxisolength)
{
    ASSERT_ERR((((uint16_t)rxisolength << 0) & ~((uint16_t)0x000000FF)) == 0);
    EM_BLE_WR(EM_BLE_RXISOBUFSETUP_ADDR + elt_idx * REG_EM_BLE_RX_ISO_BUFFER_SIZE, (EM_BLE_RD(EM_BLE_RXISOBUFSETUP_ADDR + elt_idx * REG_EM_BLE_RX_ISO_BUFFER_SIZE) & ~((uint16_t)0x000000FF)) | ((uint16_t)rxisolength << 0));
}

/**
 * @brief RXISOBUFLBL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  12:08         RXBUFLINKLBL   0x0
 *  07:05      RXBUFSTREAM_LBL   0x0
 *  04:00     RXBUFCHANNEL_LBL   0x0
 * </pre>
 */
#define EM_BLE_RXISOBUFLBL_ADDR   (0x30008002 + EM_BLE_RX_ISO_BUFFER_OFFSET)
#define EM_BLE_RXISOBUFLBL_INDEX  0x00000001
#define EM_BLE_RXISOBUFLBL_RESET  0x00000000

__INLINE uint16_t em_ble_rxisobuflbl_get(int elt_idx)
{
    return EM_BLE_RD(EM_BLE_RXISOBUFLBL_ADDR + elt_idx * REG_EM_BLE_RX_ISO_BUFFER_SIZE);
}

__INLINE void em_ble_rxisobuflbl_set(int elt_idx, uint16_t value)
{
    EM_BLE_WR(EM_BLE_RXISOBUFLBL_ADDR + elt_idx * REG_EM_BLE_RX_ISO_BUFFER_SIZE, value);
}

// field definitions
#define EM_BLE_RXBUFLINKLBL_MASK       ((uint16_t)0x00001F00)
#define EM_BLE_RXBUFLINKLBL_LSB        8
#define EM_BLE_RXBUFLINKLBL_WIDTH      ((uint16_t)0x00000005)
#define EM_BLE_RXBUFSTREAM_LBL_MASK    ((uint16_t)0x000000E0)
#define EM_BLE_RXBUFSTREAM_LBL_LSB     5
#define EM_BLE_RXBUFSTREAM_LBL_WIDTH   ((uint16_t)0x00000003)
#define EM_BLE_RXBUFCHANNEL_LBL_MASK   ((uint16_t)0x0000001F)
#define EM_BLE_RXBUFCHANNEL_LBL_LSB    0
#define EM_BLE_RXBUFCHANNEL_LBL_WIDTH  ((uint16_t)0x00000005)

#define EM_BLE_RXBUFLINKLBL_RST        0x0
#define EM_BLE_RXBUFSTREAM_LBL_RST     0x0
#define EM_BLE_RXBUFCHANNEL_LBL_RST    0x0

__INLINE void em_ble_rxisobuflbl_pack(int elt_idx, uint8_t rxbuflinklbl, uint8_t rxbufstreamlbl, uint8_t rxbufchannellbl)
{
    ASSERT_ERR((((uint16_t)rxbuflinklbl << 8) & ~((uint16_t)0x00001F00)) == 0);
    ASSERT_ERR((((uint16_t)rxbufstreamlbl << 5) & ~((uint16_t)0x000000E0)) == 0);
    ASSERT_ERR((((uint16_t)rxbufchannellbl << 0) & ~((uint16_t)0x0000001F)) == 0);
    EM_BLE_WR(EM_BLE_RXISOBUFLBL_ADDR + elt_idx * REG_EM_BLE_RX_ISO_BUFFER_SIZE,  ((uint16_t)rxbuflinklbl << 8) | ((uint16_t)rxbufstreamlbl << 5) | ((uint16_t)rxbufchannellbl << 0));
}

__INLINE void em_ble_rxisobuflbl_unpack(int elt_idx, uint8_t* rxbuflinklbl, uint8_t* rxbufstreamlbl, uint8_t* rxbufchannellbl)
{
    uint16_t localVal = EM_BLE_RD(EM_BLE_RXISOBUFLBL_ADDR + elt_idx * REG_EM_BLE_RX_ISO_BUFFER_SIZE);

    *rxbuflinklbl = (localVal & ((uint16_t)0x00001F00)) >> 8;
    *rxbufstreamlbl = (localVal & ((uint16_t)0x000000E0)) >> 5;
    *rxbufchannellbl = (localVal & ((uint16_t)0x0000001F)) >> 0;
}

__INLINE uint8_t em_ble_rxisobuflbl_rxbuflinklbl_getf(int elt_idx)
{
    uint16_t localVal = EM_BLE_RD(EM_BLE_RXISOBUFLBL_ADDR + elt_idx * REG_EM_BLE_RX_ISO_BUFFER_SIZE);
    return ((localVal & ((uint16_t)0x00001F00)) >> 8);
}

__INLINE void em_ble_rxisobuflbl_rxbuflinklbl_setf(int elt_idx, uint8_t rxbuflinklbl)
{
    ASSERT_ERR((((uint16_t)rxbuflinklbl << 8) & ~((uint16_t)0x00001F00)) == 0);
    EM_BLE_WR(EM_BLE_RXISOBUFLBL_ADDR + elt_idx * REG_EM_BLE_RX_ISO_BUFFER_SIZE, (EM_BLE_RD(EM_BLE_RXISOBUFLBL_ADDR + elt_idx * REG_EM_BLE_RX_ISO_BUFFER_SIZE) & ~((uint16_t)0x00001F00)) | ((uint16_t)rxbuflinklbl << 8));
}

__INLINE uint8_t em_ble_rxisobuflbl_rxbufstream_lbl_getf(int elt_idx)
{
    uint16_t localVal = EM_BLE_RD(EM_BLE_RXISOBUFLBL_ADDR + elt_idx * REG_EM_BLE_RX_ISO_BUFFER_SIZE);
    return ((localVal & ((uint16_t)0x000000E0)) >> 5);
}

__INLINE void em_ble_rxisobuflbl_rxbufstream_lbl_setf(int elt_idx, uint8_t rxbufstreamlbl)
{
    ASSERT_ERR((((uint16_t)rxbufstreamlbl << 5) & ~((uint16_t)0x000000E0)) == 0);
    EM_BLE_WR(EM_BLE_RXISOBUFLBL_ADDR + elt_idx * REG_EM_BLE_RX_ISO_BUFFER_SIZE, (EM_BLE_RD(EM_BLE_RXISOBUFLBL_ADDR + elt_idx * REG_EM_BLE_RX_ISO_BUFFER_SIZE) & ~((uint16_t)0x000000E0)) | ((uint16_t)rxbufstreamlbl << 5));
}

__INLINE uint8_t em_ble_rxisobuflbl_rxbufchannel_lbl_getf(int elt_idx)
{
    uint16_t localVal = EM_BLE_RD(EM_BLE_RXISOBUFLBL_ADDR + elt_idx * REG_EM_BLE_RX_ISO_BUFFER_SIZE);
    return ((localVal & ((uint16_t)0x0000001F)) >> 0);
}

__INLINE void em_ble_rxisobuflbl_rxbufchannel_lbl_setf(int elt_idx, uint8_t rxbufchannellbl)
{
    ASSERT_ERR((((uint16_t)rxbufchannellbl << 0) & ~((uint16_t)0x0000001F)) == 0);
    EM_BLE_WR(EM_BLE_RXISOBUFLBL_ADDR + elt_idx * REG_EM_BLE_RX_ISO_BUFFER_SIZE, (EM_BLE_RD(EM_BLE_RXISOBUFLBL_ADDR + elt_idx * REG_EM_BLE_RX_ISO_BUFFER_SIZE) & ~((uint16_t)0x0000001F)) | ((uint16_t)rxbufchannellbl << 0));
}

/**
 * @brief RXISOSUBEVTCNT register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  07:00            SUBEVTCNT   0x0
 * </pre>
 */
#define EM_BLE_RXISOSUBEVTCNT_ADDR   (0x30008004 + EM_BLE_RX_ISO_BUFFER_OFFSET)
#define EM_BLE_RXISOSUBEVTCNT_INDEX  0x00000002
#define EM_BLE_RXISOSUBEVTCNT_RESET  0x00000000

__INLINE uint16_t em_ble_rxisosubevtcnt_get(int elt_idx)
{
    return EM_BLE_RD(EM_BLE_RXISOSUBEVTCNT_ADDR + elt_idx * REG_EM_BLE_RX_ISO_BUFFER_SIZE);
}

__INLINE void em_ble_rxisosubevtcnt_set(int elt_idx, uint16_t value)
{
    EM_BLE_WR(EM_BLE_RXISOSUBEVTCNT_ADDR + elt_idx * REG_EM_BLE_RX_ISO_BUFFER_SIZE, value);
}

// field definitions
#define EM_BLE_SUBEVTCNT_MASK   ((uint16_t)0x000000FF)
#define EM_BLE_SUBEVTCNT_LSB    0
#define EM_BLE_SUBEVTCNT_WIDTH  ((uint16_t)0x00000008)

#define EM_BLE_SUBEVTCNT_RST    0x0

__INLINE uint8_t em_ble_rxisosubevtcnt_subevtcnt_getf(int elt_idx)
{
    uint16_t localVal = EM_BLE_RD(EM_BLE_RXISOSUBEVTCNT_ADDR + elt_idx * REG_EM_BLE_RX_ISO_BUFFER_SIZE);
    ASSERT_ERR((localVal & ~((uint16_t)0x000000FF)) == 0);
    return (localVal >> 0);
}

__INLINE void em_ble_rxisosubevtcnt_subevtcnt_setf(int elt_idx, uint8_t subevtcnt)
{
    ASSERT_ERR((((uint16_t)subevtcnt << 0) & ~((uint16_t)0x000000FF)) == 0);
    EM_BLE_WR(EM_BLE_RXISOSUBEVTCNT_ADDR + elt_idx * REG_EM_BLE_RX_ISO_BUFFER_SIZE, (uint16_t)subevtcnt << 0);
}

/**
 * @brief RXISODATABUFF register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  15:00            RXISODATA   0x0
 * </pre>
 */
#define EM_BLE_RXISODATABUFF_ADDR   (0x30008006 + EM_BLE_RX_ISO_BUFFER_OFFSET)
#define EM_BLE_RXISODATABUFF_INDEX  0x00000003
#define EM_BLE_RXISODATABUFF_RESET  0x00000000
#define EM_BLE_RXISODATABUFF_COUNT  128

__INLINE uint16_t em_ble_rxisodatabuff_get(int elt_idx, int reg_idx)
{
    ASSERT_ERR(reg_idx <= 127);
    return EM_BLE_RD(EM_BLE_RXISODATABUFF_ADDR + elt_idx * REG_EM_BLE_RX_ISO_BUFFER_SIZE + reg_idx * 2);
}

__INLINE void em_ble_rxisodatabuff_set(int elt_idx, int reg_idx, uint16_t value)
{
    ASSERT_ERR(reg_idx <= 127);
    EM_BLE_WR(EM_BLE_RXISODATABUFF_ADDR + elt_idx * REG_EM_BLE_RX_ISO_BUFFER_SIZE + reg_idx * 2, value);
}

// field definitions
#define EM_BLE_RXISODATA_MASK   ((uint16_t)0x0000FFFF)
#define EM_BLE_RXISODATA_LSB    0
#define EM_BLE_RXISODATA_WIDTH  ((uint16_t)0x00000010)

#define EM_BLE_RXISODATA_RST    0x0

__INLINE uint16_t em_ble_rxisodatabuff_rxisodata_getf(int elt_idx, int reg_idx)
{
    ASSERT_ERR(reg_idx <= 127);
    uint16_t localVal = EM_BLE_RD(EM_BLE_RXISODATABUFF_ADDR + elt_idx * REG_EM_BLE_RX_ISO_BUFFER_SIZE + reg_idx * 2);
    ASSERT_ERR((localVal & ~((uint16_t)0x0000FFFF)) == 0);
    return (localVal >> 0);
}

__INLINE void em_ble_rxisodatabuff_rxisodata_setf(int elt_idx, int reg_idx, uint16_t rxisodata)
{
    ASSERT_ERR(reg_idx <= 127);
    ASSERT_ERR((((uint16_t)rxisodata << 0) & ~((uint16_t)0x0000FFFF)) == 0);
    EM_BLE_WR(EM_BLE_RXISODATABUFF_ADDR + elt_idx * REG_EM_BLE_RX_ISO_BUFFER_SIZE + reg_idx * 2, (uint16_t)rxisodata << 0);
}


#endif // _REG_EM_BLE_RX_ISO_BUFFER_H_

