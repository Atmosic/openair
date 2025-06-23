/*************************************************************************************************/
/*!
 *  \file
 *
 *  \brief      IEEE 802.15.4 crypto interface file.
 *
 *  Copyright (c) 2019-2023 Packetcraft, Inc.  All rights reserved.
 *  Packetcraft, Inc. confidential and proprietary.
 *  
 *  IMPORTANT.  Your use of this file is governed by a Software License Agreement
 *  ("Agreement") that must be accepted in order to download or otherwise receive a
 *  copy of this file.  You may not use or copy this file for any purpose other than
 *  as described in the Agreement.  If you do not agree to all of the terms of the
 *  Agreement do not use this file and delete all copies in your possession or control;
 *  if you do not have a copy of the Agreement, you must contact Packetcraft, Inc. prior
 *  to any use, copying or further distribution of this software.
 */
/*************************************************************************************************/

#ifndef PAL_CRYPTO154_H
#define PAL_CRYPTO154_H

#include "pal_types.h"
#include "pal_radio154.h"

#ifdef __cplusplus
extern "C" {
#endif

/*! \addtogroup PAL_CRYPTO154
 *  \{ */

/**************************************************************************************************
  Macros
**************************************************************************************************/

/**************************************************************************************************
  MAC security CCM* key size
  IEEE 802.15.4-2006 Annex B.3.1
**************************************************************************************************/

/*! \brief      CCM-Star mode algorithm symmetric key length - 128 bits. */
#define CCM_STAR_KEY_LEN                      16

/**************************************************************************************************
  MAC security CCM* nonce format
  IEEE 802.15.4-2006 Section 7.6.3.2
**************************************************************************************************/

/*! \brief      CCM-Star mode algorithm nonce length. */
#define CCM_STAR_NONCE_LEN                    13

/**************************************************************************************************
  MAC auxiliary security header format
  IEEE 802.15.4-2006 Section 7.6.2
**************************************************************************************************/

/*! \brief    Size of security control in octets. */
#define PAL_CRYPTO_154_AUX_SEC_CONTROL_LEN     1

/*! \brief    Size of frame counter in octets. */
#define PAL_CRYPTO_154_AUX_FRAME_COUNTER_LEN   4

/*! \brief    Size of key identifiers in octets. */
#define PAL_CRYPTO_154_KEYID_INDEX_LEN         1
#define PAL_CRYPTO_154_KEYID_SOURCE32_LEN      4
#define PAL_CRYPTO_154_KEYID_SOURCE64_LEN      8

/*! \brief    Security control bits and fields. */
#define PAL_CRYPTO_154_SC_SEC_LEVEL_SHIFT      0     /*!< TBD */
#define PAL_CRYPTO_154_SC_SEC_LEVEL_MASK       0x07  /*!< Bitmask. */
#define PAL_CRYPTO_154_SC_SEC_LEVEL(x)         (((x) & PAL_CRYPTO_154_SC_SEC_LEVEL_MASK))

#define PAL_CRYPTO_154_SC_KEYID_MODE_SHIFT     3     /*!< TBD */
#define PAL_CRYPTO_154_SC_KEYID_MODE_MASK      0x18  /*!< Bitmask. */
#define PAL_CRYPTO_154_SC_KEYID_MODE(x)        (((x) & PAL_CRYPTO_154_SC_KEYID_MODE_MASK) >> PAL_CRYPTO_154_SC_KEYID_MODE_SHIFT) /*!< TBD */

/**************************************************************************************************
  MIC lengths and security levels
  IEEE 802.15.4-2006 Table 95
**************************************************************************************************/

/*! \brief    Size of message integrity code in octets. */
#define PAL_CRYPTO_154_MIC32_LEN         4    /*!< Length of MIC-32 field */
#define PAL_CRYPTO_154_MIC64_LEN         8    /*!< Length of MIC-64 field */
#define PAL_CRYPTO_154_MIC128_LEN       16    /*!< Length of MIC-128 field */

/*! \brief    Security levels. */
typedef enum
{
  PAL_CRYPTO_154_SEC_LEVEL_NONE       = 0,
  PAL_CRYPTO_154_SEC_LEVEL_MIC32      = 1,
  PAL_CRYPTO_154_SEC_LEVEL_MIC64      = 2,
  PAL_CRYPTO_154_SEC_LEVEL_MIC128     = 3,
  PAL_CRYPTO_154_SEC_LEVEL_ENC        = 4,
  PAL_CRYPTO_154_SEC_LEVEL_ENC_MIC32  = 5,
  PAL_CRYPTO_154_SEC_LEVEL_ENC_MIC64  = 6,
  PAL_CRYPTO_154_SEC_LEVEL_ENC_MIC128 = 7
} PalRadio154SecLvl_t;

/**************************************************************************************************
  Key identifier modes
  IEEE 802.15.4-2006 Table 96
**************************************************************************************************/

/*! \brief    Key identifier modes. */
typedef enum
{
  PAL_CRYPTO_154_KEYID_MODE_IMPLICIT = 0,
  PAL_CRYPTO_154_KEYID_MODE_INDEX    = 1,
  PAL_CRYPTO_154_KEYID_MODE_SOURCE32 = 2,
  PAL_CRYPTO_154_KEYID_MODE_SOURCE64 = 3
} PalRadio154KeyIdMode_t;

/**************************************************************************************************
  Security frame compatibility
  IEEE 802.15.4-2006 Table 81
**************************************************************************************************/

/*! \brief    Security compatibility frame versions. */
typedef enum
{
  PAL_CRYPTO_154_SEC_FRAME_2003 = 0,
  PAL_CRYPTO_154_SEC_FRAME_2006 = 1
} PalRadio154FrameComp_t;

/**************************************************************************************************
  Crypto operation status
**************************************************************************************************/

/*! \brief    Operation status. */
typedef enum
{
  PAL_CRYPTO_154_SUCCESS,   /*!< Operation completed successfully. */
  PAL_CRYPTO_154_DEC_ERROR,  /*!< Decryption error. */
  PAL_CRYPTO_154_ENC_ERROR   /*!< Encryption error. */
} PalCrypto154Status_t;

/**************************************************************************************************
  Function Declarations
**************************************************************************************************/

/*************************************************************************************************/
/*!
 *  \brief  Initialize CCM-Mode security.
 */
/*************************************************************************************************/
void PalCrypto154Init(void);

/*************************************************************************************************/
/*!
 *  \brief  De-initialize CCM-Mode security.
 */
/*************************************************************************************************/
void PalCrypto154DeInit(void);

/*************************************************************************************************/
/*!
 *  \brief      Set security modes.
 *
 *  \param      level   Security level (0..7)
 *  \param      mode    KeyIdMode (0..3)
 *  \param      index   KeyIndex (0..3)
 */
/*************************************************************************************************/
void PalCrypto154SetSecurityModes(uint8_t level, uint8_t mode, uint8_t index);

/*************************************************************************************************/
/*!
 *  \brief      Set security key.
 *
 *  \param      pKey    Security key.
 */
/*************************************************************************************************/
void PalCrypto154SetSecurityKey(uint8_t *pKey);

/*************************************************************************************************/
/*!
 *  \brief      Set security frame counter.
 *
 *  \param      frmCtr  Frame counter.
 */
/*************************************************************************************************/
void PalCrypto154SetFrameCounter(uint32_t frmCtr);

/*************************************************************************************************/
/*!
 *  \brief      Set device address.
 *
 *  \param      devAdr  Device extended address.
 */
/*************************************************************************************************/
void PalCrypto154SetDeviceAddr(uint64_t devAdr);

/*************************************************************************************************/
/*!
 *  \brief      Perform CCM-Star decryption/authentication.
 *
 *  \param      pOut    Output packet buffer.
 *  \param      pIn     Input packet buffer.
 *
 *  \return     Decryption processing status.
 */
/*************************************************************************************************/
uint8_t PalCrypto154CcmDecrypt(uint8_t *pOut, uint8_t *pIn);

/*************************************************************************************************/
/*!
 *  \brief      Perform CCM-Star authentication/encryption.
 *
 *  \param      pOut    Output packet buffer.
 *  \param      pIn     Input packet buffer.
 *
 *  \return     Encryption processing status.
 */
/*************************************************************************************************/
uint8_t PalCrypto154CcmEncrypt(uint8_t *pOut, uint8_t *pIn);

/*! \} */    /* PAL_CRYPTO154 */

#ifdef __cplusplus
};
#endif

#endif /* PAL_CRYPTO154_H */
