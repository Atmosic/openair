/*************************************************************************************************/
/*!
 *  \file
 *
 *  \brief      Crypto driver definition for uecc implementation of crypto.
 *
 *  Copyright (c) 2018-2019 ARM Ltd. All Rights Reserved.
 *
 *  Copyright (c) 2019-2024 Packetcraft, Inc.  All rights reserved.
 *  Packetcraft, Inc. confidential and proprietary.
 *  
 *  IMPORTANT.  Your use of this file is governed by a Software License Agreement
 *  ("Agreement") that must be accepted in order to download or otherwise receive a
 *  copy of this file.  You may not use or copy this file for any purpose other than
 *  as described in the Agreement.  If you do not agree to all of the terms of the
 *  Agreement do not use this file and delete all copies in your possession or control;
 *  if you do not have a copy of the Agreement, you must contact Atmosic, Inc. prior
 *  to any use, copying or further distribution of this software.
 */
/*************************************************************************************************/

#ifndef PAL_CRYPTO_UECC_H
#define PAL_CRYPTO_UECC_H

#include "pal_types.h"
#include "pal_crypto.h"
#include "uECC_ll.h"


#ifdef __cplusplus
extern "C" {
#endif


/*! \addtogroup PAL_CRYPTO
 *  \{ */

/**************************************************************************************************
  Macros
**************************************************************************************************/

void palCryptoUeccInit(palCryptoEcc_t *eccCb);

/*! \brief Pal crypto operation complete callback. */


/**************************************************************************************************
  Function Declarations
**************************************************************************************************/

/* Initialization */


/* Key generation */



/*! \} */    /* PAL_CRYPTO */

#ifdef __cplusplus
};
#endif

#endif /* PAL_CRYPTO_H */
