/**
 ****************************************************************************************
 *
 * @file aes.h
 *
 * @brief Header file for AES crypto module
 *
 * Copyright (C) RivieraWaves 2017-2018
 *
 ****************************************************************************************
 */

#ifndef AES_H_
#define AES_H_

/**
 ****************************************************************************************
 * @defgroup AES Crypto module
 * @ingroup ROOT
 * @brief  AES Crypto module
 * @{
 ****************************************************************************************
 */

/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include "rwip_config.h"

#include "co_bt.h"        // Common defines

/*
 * TYPE DEFINITIONS
 ****************************************************************************************
 */

/**
 ****************************************************************************************
 * @brief Call back definition of the function that can handle result of an AES based algorithm
 *
 * @param[in] status       Execution status
 * @param[in] aes_res      16 bytes block result
 * @param[in] src_info     Information provided by requester
 ****************************************************************************************
 */
typedef void (*aes_func_result_cb) (uint8_t status, const uint8_t* aes_res, uint32_t src_info);

/**
 ****************************************************************************************
 * @brief Call back definition of the function that can handle result of AES-CCM Cipher/Decipher
 *
 * @param[in] mic_error  True if a MIC error detected when Decipher, False else
 *                       In case of MIC error output message is considered invalid
 * @param[in] src_info     Information provided by requester
 ****************************************************************************************
 */
typedef void (*aes_ccm_func_result_cb) (bool mic_error, uint32_t src_info);

/*
 * FUNCTION DECLARATIONS
 ****************************************************************************************
 */

/**
 ****************************************************************************************
 * @brief Initialize AES function management
 *
 * @param reset True if a reset must be perform, False means boot initialization
 ****************************************************************************************
 */
void aes_init(bool reset);

/**
 ****************************************************************************************
 * @brief Handler of AES execution (HW accelerator if BLE controller present, HCI Encrypt for BLE Host Stack)
 *
 * @param[in] status  Status of AES execution
 * @param[in] result  16 bytes result of AES execution
 ****************************************************************************************
 */
void aes_result_handler(uint8_t status, uint8_t* result);

/**
 ****************************************************************************************
 * @brief Perform an AES encryption - result within callback
 * @param[in] key      Key used for the encryption
 * @param[in] val      Value to encrypt using AES
 * @param[in] copy     Copy parameters because source is destroyed
 * @param[in] res_cb   Function that will handle the AES based result (16 bytes)
 * @param[in] src_info Information used retrieve requester
 ****************************************************************************************
 */
void aes_encrypt(const uint8_t* key, const uint8_t *val, bool copy, aes_func_result_cb res_cb, uint32_t src_info);

/**
 ****************************************************************************************
 * @brief Generate a random number using AES encryption - result within callback
 *
 * @param[in] res_cb   Function that will handle the AES based result (16 bytes)
 * @param[in] src_info Information used retrieve requester
 ****************************************************************************************
 */
void aes_rand(aes_func_result_cb res_cb, uint32_t src_info);

#if (BLE_EMB_PRESENT || BLE_HOST_PRESENT)

/**
 ****************************************************************************************
 * @brief Start the AES CMAC crypto function. Allocate memory for the CMAC and
 *        begins the subkey generation
 *
 * @param[in] key          Pointer to the Key to be used
 * @param[in] message      Pointer to the block of data the data on which the CMAC is performed
 * @param[in] message_len  Length (in bytes) of the block of data M
 * @param[in] res_cb       Function that will handle the AES based result (16 bytes)
 * @param[in] src_info     Information used retrieve requester
 ****************************************************************************************
 */
void aes_cmac(const uint8_t* key, const uint8_t* message, uint16_t message_len,
              aes_func_result_cb res_cb, uint32_t src_info);

#if (BLE_MESH)

/**
 ****************************************************************************************
 * @brief Start the AES S1 crypto function.
 *
 * @param[in] message      Message used to generate Salted key
 * @param[in] message_len  Length (in bytes) of the block of data M
 * @param[in] res_cb       Function that will handle the AES based result (16 bytes)
 * @param[in] src_info     Information used retrieve requester
 ****************************************************************************************
 */
void aes_s1(const uint8_t* message, uint8_t message_len, aes_func_result_cb res_cb, uint32_t src_info);

/**
 ****************************************************************************************
 * @brief Start the AES K1 crypto function.
 *
 * @param[in] salt         Salted Key to use
 * @param[in] n            Value of N
 * @param[in] n_len        Length of N
 * @param[in] p            Value of P
 * @param[in] p_len        Length of P
 * @param[in] res_cb       Function that will handle the AES based result (16 bytes)
 * @param[in] src_info     Information used retrieve requester
 ****************************************************************************************
 */
void aes_k1(const uint8_t* salt, const uint8_t* n, uint8_t n_len, const uint8_t* p, uint8_t p_len,
            aes_func_result_cb res_cb, uint32_t src_info);

/**
 ****************************************************************************************
 * @brief Start the AES K2 crypto function.
 *
 * @param[in] n            Value of N - 128 bits
 * @param[in] p            Value of P
 * @param[in] p_len        Length of P
 * @param[in] res_cb       Function that will handle the AES based result (33 bytes)
 * @param[in] src_info     Information used retrieve requester
 ****************************************************************************************
 */
void aes_k2(const uint8_t* n, const uint8_t* p, uint8_t p_len, aes_func_result_cb res_cb, uint32_t src_info);


/**
 ****************************************************************************************
 * @brief Start the AES K3 crypto function.
 *
 * @param[in] n            Value of N - 128 bits
 * @param[in] res_cb       Function that will handle the AES based result (8 bytes)
 * @param[in] src_info     Information used retrieve requester
 ****************************************************************************************
 */
void aes_k3(const uint8_t* n, aes_func_result_cb res_cb, uint32_t src_info);

/**
 ****************************************************************************************
 * @brief Start the AES K4 crypto function.
 *
 * @param[in] n            Value of N - 128 bits
 * @param[in] res_cb       Function that will handle the AES based result (1 byte)
 * @param[in] src_info     Information used retrieve requester
 ****************************************************************************************
 */
void aes_k4(const uint8_t* n, aes_func_result_cb res_cb, uint32_t src_info);


/**
 ****************************************************************************************
 * @brief Start the AES CCM crypto function. Allocate memory for the CCM and start processing it
 *        Execute result callback at end of function execution
 *
 * @param[in]  key               Pointer to the Key to be used
 * @param[in]  nonce             13 Bytes Nonce to use for cipher/decipher
 * @param[in]  in_message        Input message for AES-CCM exectuion
 * @param[out] out_message       Output message that will contain cipher+mic or decipher data
 * @param[in]  message_len       Length of Input/Output message without mic
 * @param[in]  mic_len           Length of the mic to use (2, 4, 6, 8, 10, 12, 14, 16 valid)
 * @param[in]  cipher            True to encrypt message, False to decrypt it.
 * @param[in]  add_auth_data     Additional Authentication data used for computation of MIC
 * @param[in]  add_auth_data_len Length of Additional Authentication data
 * @param[in]  res_cb            Function that will handle the AES CCM result
 * @param[in]  src_info          Information used retrieve requester
 ****************************************************************************************
 */
void aes_ccm(const uint8_t* key, const uint8_t* nonce, const uint8_t* in_message,
             uint8_t* out_message, uint16_t message_len, uint8_t mic_len, bool cipher,
             const uint8_t* add_auth_data, uint8_t add_auth_data_len, aes_ccm_func_result_cb res_cb, uint32_t src_info);
#endif // (BLE_MESH)


#if (BLE_HW_50_ISO == 1)
/**
 ****************************************************************************************
 * @brief Group Session Key Derivation Function h8
 *
 * @param[in] k            K is a 128bits data
 * @param[in] s            S is a 128bits key
 * @param[in] keyId        KeyID is a 32 bits  data
 * @param[in] res_cb       Function that will handle the AES CCM result
 * @param[in] src_info     Information used retrieve requester
 ****************************************************************************************
 */
void aes_h8(const uint8_t* k, const uint8_t* s, const uint8_t* key_id, aes_func_result_cb res_cb, uint32_t src_info);

/**
 ****************************************************************************************
 * @brief Group Long Term Key Generation Function h9
 *
 * @param[in] w            W is a 128bits data
 * @param[in] keyId        KeyID is a 32 bits  data
 * @param[in] res_cb       Function that will handle the AES CCM result
 * @param[in] src_info     Information used retrieve requester
 ****************************************************************************************
 */
void aes_h9(const uint8_t* w, const uint8_t* key_id, aes_func_result_cb res_cb, uint32_t src_info);
#endif // (BLE_HW_50_ISO == 1)

#endif // (BLE_EMB_PRESENT || BLE_HOST_PRESENT)

/// @} AES
///
#endif /* AES_H_ */
