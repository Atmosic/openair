/*************************************************************************************************/
/*!
 *  \file
 *
 *   Generic Audio (GA) Definitions.
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
#ifndef GA_DEFS_H
#define GA_DEFS_H

#ifdef __cplusplus
extern "C" {
#endif

/*! \addtogroup GENERIC_AUDIO_DEF
 *  \{ */

/**************************************************************************************************
  Macros
**************************************************************************************************/

/*!< \brief Maximum number of the LTV-formatted Codec Specific Configurations supported */
#ifndef GA_CODEC_LTV_MAX
#define GA_CODEC_LTV_MAX                  4
#endif

/*!< \brief Maximum length of LTV-formatted Codec Specific Configuration (excluding length and type fields) value */
#ifndef GA_CODEC_LTV_LEN_MAX
#define GA_CODEC_LTV_LEN_MAX              4
#endif

/*!< \brief Maximum number of the LTV-formatted Metadata supported */
#ifndef GA_METADATA_LTV_MAX
#define GA_METADATA_LTV_MAX               4
#endif

/*!< \brief Maximum length of LTV-formatted Metadata (excluding length and type fields) value */
#ifndef GA_METADATA_LTV_LEN_MAX
#define GA_METADATA_LTV_LEN_MAX           8
#endif

/*!< \brief Maximum length of the Codec Specific Configuration (including length and type fields) value */
#define GA_MAX_CODEC_LEN                  (GA_CODEC_LTV_MAX * (2 + GA_CODEC_LTV_LEN_MAX))

/*!< \brief Maximum length of the Metadata (including length and type fields) value */
#define GA_MAX_METADATA_LEN               (GA_METADATA_LTV_MAX * (2 + GA_METADATA_LTV_LEN_MAX))

/* Audio Location value bits */
#define GA_AUDIO_LOC_NOT_ALLOWED          (0<<0)   /*!< Not Allowed */
#define GA_AUDIO_LOC_FRT_LEFT_BIT         (1<<0)   /*!< Front Left */
#define GA_AUDIO_LOC_FRT_RIGHT_BIT        (1<<1)   /*!< Front Right */
#define GA_AUDIO_LOC_FRT_CENTER_BIT       (1<<2)   /*!< Front Center */
#define GA_AUDIO_LOC_LOW_FREQ_EFF_1_BIT   (1<<3)   /*!< Low Frequency Effects 1 */
#define GA_AUDIO_LOC_BCK_LEFT_BIT         (1<<4)   /*!< Back Left */
#define GA_AUDIO_LOC_BCK_RIGHT_BIT        (1<<5)   /*!< Back Right */
#define GA_AUDIO_LOC_FRT_LEFT_CTR_BIT     (1<<6)   /*!< Front Left of Center */
#define GA_AUDIO_LOC_FRT_RIGHT_CTR_BIT    (1<<7)   /*!< Front Right of Center */
#define GA_AUDIO_LOC_BCK_CTR_BIT          (1<<8)   /*!< Back Center */
#define GA_AUDIO_LOC_LOW_FREQ_EFF_2_BIT   (1<<9)   /*!< Low Frequency Effects 2 */
#define GA_AUDIO_LOC_SIDE_LEFT_BIT        (1<<10)  /*!< Side Left */
#define GA_AUDIO_LOC_SIDE_RIGHT_BIT       (1<<11)  /*!< Side Right */
#define GA_AUDIO_LOC_TOP_FRT_LEFT_BIT     (1<<12)  /*!< Top Front Left */
#define GA_AUDIO_LOC_TOP_FRT_RIGHT_BIT    (1<<13)  /*!< Top Front Right */
#define GA_AUDIO_LOC_TOP_FRT_CTR_BIT      (1<<14)  /*!< Top Front Center */
#define GA_AUDIO_LOC_TOP_CTR_BIT          (1<<15)  /*!< Top Center */
#define GA_AUDIO_LOC_TOP_BCK_LEFT_BIT     (1<<16)  /*!< Top Back Left */
#define GA_AUDIO_LOC_TOP_BCK_RIGHT_BIT    (1<<17)  /*!< Top Back Right */
#define GA_AUDIO_LOC_TOP_SIDE_LEFT_BIT    (1<<18)  /*!< Top Side Left */
#define GA_AUDIO_LOC_TOP_SIDE_RIGHT_BIT   (1<<19)  /*!< Top Side Right */
#define GA_AUDIO_LOC_TOP_BCK_CTR_BIT      (1<<20)  /*!< Top Back Center */
#define GA_AUDIO_LOC_BTM_FRT_CTR_BIT      (1<<21)  /*!< Bottom Front Center  */
#define GA_AUDIO_LOC_BTM_FRT_LEFT_BIT     (1<<22)  /*!< Bottom Front Left */
#define GA_AUDIO_LOC_BTM_FRT_RIGHT_BIT    (1<<23)  /*!< Bottom Front Right */
#define GA_AUDIO_LOC_FRT_LEFT_WIDE_BIT    (1<<24)  /*!< Front Left Wide */
#define GA_AUDIO_LOC_FRT_RIGHT_WIDE_BIT   (1<<25)  /*!< Front Right Wide */
#define GA_AUDIO_LOC_LEFT_SUR_BIT         (1<<26)  /*!< Left Surround */
#define GA_AUDIO_LOC_RIGHT_SUR_BIT        (1<<27)  /*!< Right Surround */
#define GA_AUDIO_LOC_RFU                  (1<<28)  /*!< Reserved for future use */

/* Audio Input Type Definitions */
#define GA_AUDIO_INPUT_UNSPECIFY          0x00     /*!< Unspecified input */
#define GA_AUDIO_INPUT_BLUETOOTH          0x01     /*!< Bluetooth audio stream */
#define GA_AUDIO_INPUT_MIC                0x02     /*!< Microphone */
#define GA_AUDIO_INPUT_ANALOG             0x03     /*!< Analog interface */
#define GA_AUDIO_INPUT_DIGITAL            0x04     /*!< Digital interface */
#define GA_AUDIO_INPUT_RADIO              0x05     /*!< AM/FM/XM/etc */
#define GA_AUDIO_INPUT_STREAM             0x06     /*!< Streaming audio source */

/* Codec Specific Capabilities Types */
#define GA_CODEC_CAP_SUP_SAMPLE_FREQ      0x01    /*!< Supported Sampling Frequencies */
#define GA_CODEC_CAP_SUP_FRAME_DUR        0x02    /*!< Supported Frame Durations */
#define GA_CODEC_CAP_SUP_AUDIO_CH_CNT     0x03    /*!< Supported Audio Channel Counts */
#define GA_CODEC_CAP_SUP_OCT_PER_FRAME    0x04    /*!< Supported Octets Per Codec Frame */
#define GA_CODEC_CAP_SUP_FRAME_PER_SDU    0x05    /*!< Supported Max Codec Frames Per SDU */

/* BAP Codec Specific Capabilities LTV Length (including size of 'length' field) */
#define GA_CODEC_CAP_LEN_SAMPLE_FREQ      0x03    /*!< Supported Sampling Frequencies LTV length  */
#define GA_CODEC_CAP_LEN_FRAME_DUR        0x02    /*!< Supported Frame Durations LTV length  */
#define GA_CODEC_CAP_LEN_AUDIO_CH_CNT     0x02    /*!< Supported Audio Channel Counts LTV length */
#define GA_CODEC_CAP_LEN_OCT_PER_FRAME    0x05    /*!< Supported Octets Per Codec Frame LTV length */
#define GA_CODEC_CAP_LEN_FRAME_PER_SDU    0x02    /*!< Supported Max Codec Frames Per SDU LTV length */

/* Codec Specific Configuration Types */
#define GA_CODEC_CFG_SAMPLE_FREQ          0x01    /*!< Sampling Frequency */
#define GA_CODEC_CFG_FRAME_DUR            0x02    /*!< Frame Duration */
#define GA_CODEC_CFG_AUDIO_CH_ALLOC       0x03    /*!< Audio Channel Allocation */
#define GA_CODEC_CFG_OCT_PER_FRAME        0x04    /*!< Octets Per Codec Frame */
#define GA_CODEC_CFG_BLOCK_PER_SDU        0x05    /*!< Codec Frame Blocks Per SDU */

/* BAP Codec Specific Configuration LTV Value Length (not including size of 'length' field) */
#define GA_CODEC_CFG_LEN_SAMPLE_FREQ      0x01    /*!< Sampling Frequency value length  */
#define GA_CODEC_CFG_LEN_FRAME_DUR        0x01    /*!< Frame Duration value length  */
#define GA_CODEC_CFG_LEN_AUDIO_CH_ALLOC   0x04    /*!< Audio Channel Allocation value length */
#define GA_CODEC_CFG_LEN_OCT_PER_FRAME    0x02    /*!< Octets Per Codec Frame value length */
#define GA_CODEC_CFG_LEN_BLOCK_PER_SDU    0x01    /*!< Codec Frame Blocks Per SDU value length */

/* Codec Specific Configuration data element indexes. */
#define GA_CODEC_CFG_LEN_IDX                 0    /*!< Configuration data element len */
#define GA_CODEC_CFG_TYPE_IDX                1    /*!< Configuration data element type */
#define GA_CODEC_CFG_DATA_IDX                2    /*!< Configuration data element data */

/* Supported Sampling Frequency bits (Hz)*/
#define GA_CODEC_CAP_SAMPLE_FREQ_8_BIT    (1<<0)  /*!< 8000 Hz */
#define GA_CODEC_CAP_SAMPLE_FREQ_11_BIT   (1<<1)  /*!< 11025 Hz */
#define GA_CODEC_CAP_SAMPLE_FREQ_16_BIT   (1<<2)  /*!< 16000 Hz */
#define GA_CODEC_CAP_SAMPLE_FREQ_22_BIT   (1<<3)  /*!< 22050 Hz */
#define GA_CODEC_CAP_SAMPLE_FREQ_24_BIT   (1<<4)  /*!< 24000 Hz */
#define GA_CODEC_CAP_SAMPLE_FREQ_32_BIT   (1<<5)  /*!< 32000 Hz */
#define GA_CODEC_CAP_SAMPLE_FREQ_44_BIT   (1<<6)  /*!< 44100 Hz */
#define GA_CODEC_CAP_SAMPLE_FREQ_48_BIT   (1<<7)  /*!< 48000 Hz */
#define GA_CODEC_CAP_SAMPLE_FREQ_88_BIT   (1<<8)  /*!< 88200 Hz */
#define GA_CODEC_CAP_SAMPLE_FREQ_96_BIT   (1<<9)  /*!< 96000 Hz */
#define GA_CODEC_CAP_SAMPLE_FREQ_176_BIT  (1<<10) /*!< 176400 Hz */
#define GA_CODEC_CAP_SAMPLE_FREQ_192_BIT  (1<<11) /*!< 192000 Hz */
#define GA_CODEC_CAP_SAMPLE_FREQ_384_BIT  (1<<12) /*!< 384000 Hz */

/* Selected Codec Sampling Frequency (Hz) */
#define GA_CODEC_CFG_SAMPLE_FREQ_8        0x01    /*!< 8000 Hz */
#define GA_CODEC_CFG_SAMPLE_FREQ_11       0x02    /*!< 11025 Hz */
#define GA_CODEC_CFG_SAMPLE_FREQ_16       0x03    /*!< 16000 Hz */
#define GA_CODEC_CFG_SAMPLE_FREQ_22       0x04    /*!< 22050 Hz */
#define GA_CODEC_CFG_SAMPLE_FREQ_24       0x05    /*!< 24000 Hz */
#define GA_CODEC_CFG_SAMPLE_FREQ_32       0x06    /*!< 32000 Hz */
#define GA_CODEC_CFG_SAMPLE_FREQ_44       0x07    /*!< 44100 Hz */
#define GA_CODEC_CFG_SAMPLE_FREQ_48       0x08    /*!< 48000 Hz */
#define GA_CODEC_CFG_SAMPLE_FREQ_88       0x09    /*!< 88200 Hz */
#define GA_CODEC_CFG_SAMPLE_FREQ_96       0x0A    /*!< 96000 Hz */
#define GA_CODEC_CFG_SAMPLE_FREQ_176      0x0B    /*!< 176400 Hz */
#define GA_CODEC_CFG_SAMPLE_FREQ_192      0x0C    /*!< 192000 Hz */
#define GA_CODEC_CFG_SAMPLE_FREQ_384      0x0D    /*!< 384000 Hz */

/* Supported Frame and Preferred Duration bits */
#define GA_CODEC_CAP_FRAME_DUR_75_BIT     (1<<0)  /*!< 7.5 ms frame duration supported */
#define GA_CODEC_CAP_FRAME_DUR_10_BIT     (1<<1)  /*!< 10 ms frame duration supported */
#define GA_CODEC_CAP_PF_FRAME_DUR_75_BIT  (1<<4)  /*!< 7.5 ms frame duration preferred (valid only when bit 0 is set) */
#define GA_CODEC_CAP_PF_FRAME_DUR_10_BIT  (1<<5)  /*!< 10 ms frame duration preferred (valid only when bit 1 is set) */
  /* VS Supported Frame bits */
#define GA_CODEC_CAP_FRAME_DUR_25_BIT     (1<<6)  /*!< 2.5 ms frame duration supported */
#define GA_CODEC_CAP_FRAME_DUR_05_BIT     (1<<7)  /*!< 5 ms frame duration supported */

/* Selected codec frame duration (ms) */
#define GA_CODEC_CFG_FRAME_DUR_75         0x00    /*!< Use 7.5 ms codec frames */
#define GA_CODEC_CFG_FRAME_DUR_10         0x01    /*!< Use 10 ms codec frames */
/* VS Supported Frame bits */
#define GA_CODEC_CFG_FRAME_DUR_25         (1<<6)  /*!< Use 2.5 ms codec frames */
#define GA_CODEC_CFG_FRAME_DUR_05         (1<<7)  /*!< Use 5 ms codec frames */

/* Supported Audio Channel Counts bits */
#define GA_CODEC_CAP_AUDIO_CH_CNT_1_BIT   (1<<0)  /*!< Channel count: 1 */
#define GA_CODEC_CAP_AUDIO_CH_CNT_2_BIT   (1<<1)  /*!< Channel count: 2 */
#define GA_CODEC_CAP_AUDIO_CH_CNT_3_BIT   (1<<2)  /*!< Channel count: 3 */
#define GA_CODEC_CAP_AUDIO_CH_CNT_4_BIT   (1<<3)  /*!< Channel count: 4 */
#define GA_CODEC_CAP_AUDIO_CH_CNT_5_BIT   (1<<4)  /*!< Channel count: 5 */
#define GA_CODEC_CAP_AUDIO_CH_CNT_6_BIT   (1<<5)  /*!< Channel count: 6 */
#define GA_CODEC_CAP_AUDIO_CH_CNT_7_BIT   (1<<6)  /*!< Channel count: 7 */
#define GA_CODEC_CAP_AUDIO_CH_CNT_8_BIT   (1<<7)  /*!< Channel count: 8 */

/* Octets Per Codec Frame (octets) - Bit rates calculated based on Sample Frequency and Frame Duration */
#define GA_CODEC_OCT_PER_FRAME_26         0x1A    /*!< 27.734 kbps */
#define GA_CODEC_OCT_PER_FRAME_30         0x1E    /*!< 24 or 32 kbps  */
#define GA_CODEC_OCT_PER_FRAME_40         0x28    /*!< 32 kbps */
#define GA_CODEC_OCT_PER_FRAME_45         0x2D    /*!< 48 kbps */
#define GA_CODEC_OCT_PER_FRAME_60         0x3C    /*!< 48 or 64 kbps */
#define GA_CODEC_OCT_PER_FRAME_80         0x50    /*!< 64 kbps */
#define GA_CODEC_OCT_PER_FRAME_97         0x61    /*!< 95.06 kbps */
#define GA_CODEC_OCT_PER_FRAME_130        0x82    /*!< 95.55 kbps */
#define GA_CODEC_OCT_PER_FRAME_75         0x4B    /*!< 80 kbps */
#define GA_CODEC_OCT_PER_FRAME_100        0x64    /*!< 80 kbps */
#define GA_CODEC_OCT_PER_FRAME_90         0x5A    /*!< 96 kbps */
#define GA_CODEC_OCT_PER_FRAME_120        0x78    /*!< 96 kbps */
#define GA_CODEC_OCT_PER_FRAME_117        0x75    /*!< 124.8 kbps */
#define GA_CODEC_OCT_PER_FRAME_155        0x9B    /*!< 124 kbps */
/* VS Supported Frame bits */
#define GA_CODEC_OCT_PER_FRAME_25         0x19    /*!< 80 kbps for 2.5 ms frames */
#define GA_CODEC_OCT_PER_FRAME_50         0x32    /*!< 80 kbps for 5 ms frames */

/* Codec frame blocks per SDU */
#define GA_CODEC_BLOCK_PER_SDU_1          0x01    /*!< One codec frame block per SDU */

/* Metadata LTV Types */
#define GA_METADATA_PRF_AUD_CONTEXT       0x01    /*!< Preferred Audio Contexts */
#define GA_METADATA_STREAM_AUD_CONTEXT    0x02    /*!< Streaming Audio Contexts */
#define GA_METADATA_PROGRAM_INFO          0x03    /*!< Program Info */
#define GA_METADATA_LANGUAGE              0x04    /*!< Streaming Language */
#define GA_METADATA_CCID_LIST             0x05    /*!< CCID List */
#define GA_METADATA_PARENTAL_RATING       0x06    /*!< Parental Rating */
#define GA_METADATA_PROGRAM_INFO_URI      0x07    /*!< Program Info URI */
#define GA_METADATA_EXT_METADATA          0xFE    /*!< Extended Metadata */
#define GA_METADATA_VS                    0xFF    /*!< Vendor-specific Metadata */

/* BAP Metadata LTV Length */
#define GA_METADATA_LEN_PRF_AUD_CTX       0x02    /*!< Preferred Audio Contexts LTV length  */
#define GA_METADATA_LEN_STREAM_AUD_CTX    0x02    /*!< Streaming Audio Contexts LTV length  */
#define GA_METADATA_LEN_LANGUAGE          0x03    /*!< Streaming Language LTV length  */
#define GA_METADATA_LEN_PARENTAL_RATING   0x01    /*!< Parental Rating LTV length */

/* Context Type value bits */
#define GA_CTX_TYPE_PROHIBITED            0x0000  /*!< Prohibited */
#define GA_CTX_TYPE_UNSPECIFY_BIT         (1<<0)  /*!< Unspecified. Matches any audio context */
#define GA_CTX_TYPE_CONVERSAT_BIT         (1<<1)  /*!< Conversation between humans (telephony or video calls) */
#define GA_CTX_TYPE_MEDIA_BIT             (1<<2)  /*!< Media (music, public radio, podcast or video soundtracks, or tv audio) */
#define GA_CTX_TYPE_GAME_BIT              (1<<3)  /*!< Video gaming audio (gaming media, gaming effects, music and in-game voice chat between participants, or mix of all) */
#define GA_CTX_TYPE_INSTRUCT_BIT          (1<<4)  /*!< Instructional audio (navigation, traffic announcements or user guidance) */
#define GA_CTX_TYPE_VOICE_ASST_BIT        (1<<5)  /*!< Man-machine communication (with voice recognition or virtual assistants) */
#define GA_CTX_TYPE_LIVE_BIT              (1<<6)  /*!< Live audio (from microphone where audio is perceived both through direct acoustic path and through LE Audio Stream) */
#define GA_CTX_TYPE_SOUND_EFX_BIT         (1<<7)  /*!< Sound effects including keyboard and touch feedback, menu and user interface sounds, and other system sounds */
#define GA_CTX_TYPE_NTF_BIT               (1<<8)  /*!< Notification and reminder sounds; attention-seeking audio, for example, in beeps signaling the arrival of a message */
#define GA_CTX_TYPE_RINGTONE_BIT          (1<<9)  /*!< Alerts user to incoming call (incoming telephony or video call, including traditional cellular as well as VoIP and Push-to-Talk) */
#define GA_CTX_TYPE_ALERT_BIT             (1<<10) /*!< Alarms and timers, immediate alerts (in  critical battery alarm, timer expiry or alarm clock, toaster, cooker, kettle, etc.) */
#define GA_CTX_TYPE_EMER_ALARM_BIT        (1<<11) /*!< Emergency alarm (fire alarms or other urgent alerts) */

#define GA_CTX_TYPE_MAX_BIT               12      /*!< Maximum number of Context Type bits */

/* Language types. 3-byte, lower case language code as defined in ISO 639-3 */
#define GA_LANG_ENGLISH                   "eng"  /*!< English */
#define GA_LANG_FRENCH                    "fre"  /*!< French */
#define GA_LANG_GERMAN                    "deu"  /*!< German */
#define GA_LANG_CHINESE                   "zho"  /*!< Chinese */
#define GA_LANG_SPANISH                   "spa"  /*!< Spanish (Castilian) */

/* Parental_Rating. Bits 0 - 3 Value representing the parental rating:
                    0x00 - no rating, 0x01 - recommended for listeners of any age.
                    Other values - recommended for listeners of age Y years, where Y = value + 3 years. e.g. 0x05 = recommended for listeners of 8 years or older */
#define GA_PARENTAL_RATING_NO_RATING      0x00    /*!< No rating */
#define GA_PARENTAL_RATING_ANY_AGE        0x01    /*!< Recommended for listeners of any age */

/*! \} */    /* GENERIC_AUDIO_DEF */

#ifdef __cplusplus
};
#endif

#endif /* GA_DEFS_H */
