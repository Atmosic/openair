/**
 *******************************************************************************
 *
 * @file pc_vs_cmd.c
 *
 * @brief Link layer vendor specific command
 *
 * Copyright (C) Atmosic 2023-2024
 *
 *******************************************************************************
 */

#ifdef CONFIG_SOC_FAMILY_ATM
#include <zephyr/kernel.h>
#include <zephyr/sys/util.h>
#include <zephyr/init.h>
#endif
#include "arch.h"
#include "pc_ctr.h"
#include "hci_defs.h"
#include "lhci_api.h"
#include "ll_api.h"
#include "bstream.h"
#include "wsf_msg.h"
#include "at_wrpr.h"
#include "spi.h"
#include "atm_utils_c.h"

// check co_hci.h
#define LHCI_OPCODE_VS_READ_MEM HCI_OPCODE(HCI_OGF_VENDOR_SPEC, 0x01)
#define LHCI_OPCODE_VS_WRITE_MEM HCI_OPCODE(HCI_OGF_VENDOR_SPEC, 0x02)
// Set Peripheral latency
#define LHCI_OPCODE_VS_SET_PERIPHERAL_LATENCY \
    HCI_OPCODE(HCI_OGF_VENDOR_SPEC, 0x13)
#define LHCI_OPCODE_VS_READ_REG HCI_OPCODE(HCI_OGF_VENDOR_SPEC, 0x30)
#define LHCI_OPCODE_VS_WRITE_REG HCI_OPCODE(HCI_OGF_VENDOR_SPEC, 0x31)
#define LHCI_OPCODE_VS_GET_TEST_TX_PKT_NUM HCI_OPCODE(HCI_OGF_VENDOR_SPEC, 0x73)

#define SPI_PMURADIO_BLOCK_MASK 0x0F
#define SPI_PMURADIO_BLOCK_OFFSET 16
#define SPI_PMURADIO_REGADDR_MASK 0xFF
#define SPI_PMURADIO_PMU_MASK 0x1000000

// vendor_cmd: LHCI_OPCODE_VS_READ_MEM
typedef struct {
    // Start address to read
    uint32_t start_addr;
    // Access size
    uint8_t type;
    // Length to read
    uint8_t length;
} __PACKED pc_vs_rd_mem_cmd_t;

// vendor_cmd: LHCI_OPCODE_VS_WRITE_MEM
typedef struct {
    // Start address to write
    uint32_t start_addr;
    // Access size
    uint8_t type;
    // length of buffer
    uint8_t length;
} __PACKED pc_vs_wr_mem_cmd_t;

// vendor_cmd: LHCI_OPCODE_VS_READ_REG
typedef struct {
    // register address
    uint32_t reg_addr;
} pc_vs_rd_reg_cmd_t;

// vendor_cmd: LHCI_OPCODE_VS_WRITE_REG
typedef struct {
    // register address
    uint32_t reg_addr;
    // register value
    uint32_t reg_value;
} pc_vs_wr_reg_cmd_t;

static uint8_t *pc_vs_gen_cmd_cmpl_evt(uint8_t param_len, uint16_t opcode)
{
    uint8_t *cmpl_evt = WsfMsgAlloc(HCI_EVT_HDR_LEN + HCI_LEN_CMD_CMPL +
	param_len);
    UINT8_TO_BSTREAM(cmpl_evt, HCI_CMD_CMPL_EVT);
    UINT8_TO_BSTREAM(cmpl_evt, HCI_LEN_CMD_CMPL + param_len);
    // num of cmd, always 1
    UINT8_TO_BSTREAM(cmpl_evt, 1);
    UINT16_TO_BSTREAM(cmpl_evt, opcode);
    return cmpl_evt;
}

static void pc_vs_send_cmd_cmpl_evt(uint8_t *cmpl_evt)
{
    LhciSendEvent(cmpl_evt - HCI_EVT_HDR_LEN - HCI_LEN_CMD_CMPL);
}

#define PC_VS_CMD_MEM_TYPE_8 8
#define PC_VS_CMD_MEM_TYPE_16 16
#define PC_VS_CMD_MEM_TYPE_32 32
#define PC_VS_CMD_MEM_TYPE_INVALID 0xFF

static uint8_t pc_vs_check_mem_type(uint8_t type)
{
    if ((type != PC_VS_CMD_MEM_TYPE_8) && (type != PC_VS_CMD_MEM_TYPE_16) &&
	(type != PC_VS_CMD_MEM_TYPE_32)) {
	return PC_VS_CMD_MEM_TYPE_INVALID;
    }
    return type;
}

#define _PC_VS_READ_EVT(P, R, T) do { \
    uint32_t value = 0; \
    for (uint8_t i = 0; i < P->length; \
	i += (PC_VS_CMD_MEM_TYPE_##T / PC_VS_CMD_MEM_TYPE_8)) { \
        value = (*(uint##T##_t volatile *)(P->start_addr + i)); \
        UINT##T##_TO_BSTREAM(R, value); \
    } \
} while (0)
#define PC_VS_READ_EVT(P, R, T) _PC_VS_READ_EVT(P, R, T)

#define _PC_VS_WRITE_EVT(P, B, T) do { \
    uint32_t value = 0; \
    for (uint8_t i = 0; i < P->length; \
	i += (PC_VS_CMD_MEM_TYPE_##T / PC_VS_CMD_MEM_TYPE_8)) { \
	BSTREAM_TO_UINT##T(value, B); \
	(*(uint##T##_t volatile *)(P->start_addr + i)) = value; \
    } \
} while (0)
#define PC_VS_WRITE_EVT(P, B, T) _PC_VS_WRITE_EVT(P, B, T)

static void pc_vs_read_mem_handler(pc_vs_rd_mem_cmd_t const *cmd_para)
{
    if (!cmd_para->length ||
	(pc_vs_check_mem_type(cmd_para->type) == PC_VS_CMD_MEM_TYPE_INVALID)) {
	uint8_t *cmpl_evt =
	    pc_vs_gen_cmd_cmpl_evt(sizeof(uint8_t), LHCI_OPCODE_VS_READ_MEM);
	*cmpl_evt = HCI_ERR_INVALID_PARAM;
	pc_vs_send_cmd_cmpl_evt(cmpl_evt);
	return;
    }

    uint8_t *cmpl_evt = pc_vs_gen_cmd_cmpl_evt(sizeof(uint8_t) +
	sizeof(cmd_para->length) + cmd_para->length, LHCI_OPCODE_VS_READ_MEM);
    uint8_t *evt_param = cmpl_evt;
    UINT8_TO_BSTREAM(evt_param, HCI_SUCCESS);
    UINT8_TO_BSTREAM(evt_param, cmd_para->length);
    if (cmd_para->type == PC_VS_CMD_MEM_TYPE_8) {
	PC_VS_READ_EVT(cmd_para, evt_param, PC_VS_CMD_MEM_TYPE_8);
    } else if (cmd_para->type == PC_VS_CMD_MEM_TYPE_16) {
	PC_VS_READ_EVT(cmd_para, evt_param, PC_VS_CMD_MEM_TYPE_16);
    } else if (cmd_para->type == PC_VS_CMD_MEM_TYPE_32) {
	PC_VS_READ_EVT(cmd_para, evt_param, PC_VS_CMD_MEM_TYPE_32);
    }
    pc_vs_send_cmd_cmpl_evt(cmpl_evt);
}

static void pc_vs_wr_mem_handler(pc_vs_wr_mem_cmd_t const *cmd_para,
    uint8_t const *pBuf)
{
    uint8_t *cmpl_evt =
	pc_vs_gen_cmd_cmpl_evt(sizeof(uint8_t), LHCI_OPCODE_VS_WRITE_MEM);

    if (!cmd_para->length ||
	(pc_vs_check_mem_type(cmd_para->type) == PC_VS_CMD_MEM_TYPE_INVALID)) {
	*cmpl_evt = HCI_ERR_INVALID_PARAM;
	pc_vs_send_cmd_cmpl_evt(cmpl_evt);
	return;
    }

    if (cmd_para->type == PC_VS_CMD_MEM_TYPE_8) {
	PC_VS_WRITE_EVT(cmd_para, pBuf, PC_VS_CMD_MEM_TYPE_8);
    } else if (cmd_para->type == PC_VS_CMD_MEM_TYPE_16) {
	PC_VS_WRITE_EVT(cmd_para, pBuf, PC_VS_CMD_MEM_TYPE_16);
    } else if (cmd_para->type == PC_VS_CMD_MEM_TYPE_32) {
	PC_VS_WRITE_EVT(cmd_para, pBuf, PC_VS_CMD_MEM_TYPE_32);
    }
    *cmpl_evt = HCI_SUCCESS;
    pc_vs_send_cmd_cmpl_evt(cmpl_evt);
}

static bool pc_vs_is_wrpr_ctrl(uint32_t addr)
{
    static uint32_t const wrpr_base[] = {
	CMSDK_WRPR0_NONSECURE_BASE,
	CMSDK_WRPR1_NONSECURE_BASE,
	CMSDK_WRPR2_NONSECURE_BASE,
	CMSDK_WRPR0_SECURE_BASE,
	CMSDK_WRPR1_SECURE_BASE,
	CMSDK_WRPR2_SECURE_BASE
    };

    for (uint8_t i = 0; i < ARRAY_LEN(wrpr_base); i++) {
        if ((addr >= wrpr_base[i]) && (addr < (wrpr_base[i] + APB_MOD_SIZE))) {
            return true;
        }
    }
    return false;
}

static void pc_vs_read_reg_handler(pc_vs_rd_reg_cmd_t const *cmd_para)
{
    uint32_t reg_val;

    uint32_t volatile *ctrl_ptr =
	module_to_ctrl((void volatile const *)cmd_para->reg_addr);
    if (ctrl_ptr) {
	// Enable WRPR clock
	if (!pc_vs_is_wrpr_ctrl(cmd_para->reg_addr)) {
	    *ctrl_ptr = WRPR_CTRL__CLK_ENABLE;
	}
	// Read register data
	reg_val = (*(uint32_t volatile *)(cmd_para->reg_addr));
    } else if (cmd_para->reg_addr >= SYS_PPB_BASE) {
	// Enable related WRPR and read by SPI
	bool is_pmureg =
	    (cmd_para->reg_addr & SPI_PMURADIO_PMU_MASK) ? true : false;
	spi_dev_t const *reg_spi = is_pmureg ? &spi_pmu : &spi_radio;
	uint8_t spi_block = (cmd_para->reg_addr >> SPI_PMURADIO_BLOCK_OFFSET) &
	    SPI_PMURADIO_BLOCK_MASK;
	uint8_t spi_addr = cmd_para->reg_addr & SPI_PMURADIO_REGADDR_MASK;
	void volatile const *wrpr_addr = is_pmureg ? CMSDK_PMU : CMSDK_RADIO;

	WRPR_CTRL_PUSH(wrpr_addr, WRPR_CTRL__CLK_ENABLE) {
	    reg_val = spi_pmuradio_read_word(reg_spi, spi_block, spi_addr);
	} WRPR_CTRL_POP();
    } else {
	reg_val = (*(uint32_t volatile *)(cmd_para->reg_addr));
    }

    uint8_t *cmpl_evt = pc_vs_gen_cmd_cmpl_evt(sizeof(uint8_t) +
	sizeof(cmd_para->reg_addr) + sizeof(reg_val), LHCI_OPCODE_VS_READ_REG);
    uint8_t *evt_param = cmpl_evt;
    UINT8_TO_BSTREAM(evt_param, HCI_SUCCESS);
    UINT32_TO_BSTREAM(evt_param, cmd_para->reg_addr);
    UINT32_TO_BSTREAM(evt_param, reg_val);
    pc_vs_send_cmd_cmpl_evt(cmpl_evt);
}

static void pc_vs_write_reg_handler(pc_vs_wr_reg_cmd_t const *cmd_para)
{
    uint32_t volatile *ctrl_ptr =
	module_to_ctrl((void volatile const *)cmd_para->reg_addr);
    if (ctrl_ptr) {
	// Enable WRPR clock
	if (!pc_vs_is_wrpr_ctrl(cmd_para->reg_addr)) {
	    *ctrl_ptr = WRPR_CTRL__CLK_ENABLE;
	}
	// Write register data
	*(uint32_t volatile *)(cmd_para->reg_addr) = cmd_para->reg_value;
    } else if (cmd_para->reg_addr >= SYS_PPB_BASE) {
	// Enable related WRPR and read by SPI
	bool is_pmureg =
	    (cmd_para->reg_addr & SPI_PMURADIO_PMU_MASK) ? true : false;
	spi_dev_t const *reg_spi = is_pmureg ? &spi_pmu : &spi_radio;
	uint8_t spi_block = (cmd_para->reg_addr >> SPI_PMURADIO_BLOCK_OFFSET) &
	    SPI_PMURADIO_BLOCK_MASK;
	uint8_t spi_addr = cmd_para->reg_addr & SPI_PMURADIO_REGADDR_MASK;
	void volatile const *wrpr_addr = is_pmureg ? CMSDK_PMU : CMSDK_RADIO;

	WRPR_CTRL_PUSH(wrpr_addr, WRPR_CTRL__CLK_ENABLE) {
	    spi_pmuradio_write_word(reg_spi, spi_block, spi_addr,
		cmd_para->reg_value);
	} WRPR_CTRL_POP();
    } else {
	*(uint32_t volatile *)(cmd_para->reg_addr) = cmd_para->reg_value;
    }

    uint8_t *cmpl_evt = pc_vs_gen_cmd_cmpl_evt(sizeof(uint8_t) +
	sizeof(cmd_para->reg_addr), LHCI_OPCODE_VS_WRITE_REG);
    uint8_t *evt_param = cmpl_evt;
    UINT8_TO_BSTREAM(evt_param, HCI_SUCCESS);
    UINT32_TO_BSTREAM(evt_param, cmd_para->reg_addr);
    pc_vs_send_cmd_cmpl_evt(cmpl_evt);
}

#define PC_VS_CHECK_CMDHDR(P, T) do { \
    if (P->len < sizeof(pc_vs_##T##_cmd_t)) { \
	uint8_t *cmpl_evt = pc_vs_gen_cmd_cmpl_evt(sizeof(uint8_t), \
	    P->opCode); \
	*cmpl_evt = HCI_ERR_INVALID_PARAM; \
	pc_vs_send_cmd_cmpl_evt(cmpl_evt); \
	return true; \
    } \
} while (0)

static bool pc_vs_decode_cmd(LhciHdr_t *pHdr, uint8_t *pBuf)
{
    switch (pHdr->opCode) {
	case LHCI_OPCODE_VS_SET_PERIPHERAL_LATENCY: {
	    uint16_t handle;
	    uint16_t latency;
	    BSTREAM_TO_UINT16(handle, pBuf);
	    BSTREAM_TO_UINT16(latency, pBuf);
	    uint8_t status = LlSetPeripheralLatency(handle, latency);
	    uint8_t *cmpl_evt = pc_vs_gen_cmd_cmpl_evt(sizeof(status) +
		sizeof(handle), pHdr->opCode);
	    uint8_t *evt_param = cmpl_evt;
	    UINT8_TO_BSTREAM(evt_param, status);
	    UINT16_TO_BSTREAM(evt_param, handle);
	    pc_vs_send_cmd_cmpl_evt(cmpl_evt);
	} break;
	case LHCI_OPCODE_VS_READ_MEM: {
	    PC_VS_CHECK_CMDHDR(pHdr, rd_mem);
	    pc_vs_rd_mem_cmd_t cmd_para;
	    BSTREAM_TO_UINT32(cmd_para.start_addr, pBuf);
	    BSTREAM_TO_UINT8(cmd_para.type, pBuf);
	    BSTREAM_TO_UINT8(cmd_para.length, pBuf);
	    pc_vs_read_mem_handler(&cmd_para);
	} break;
	case LHCI_OPCODE_VS_WRITE_MEM: {
	    PC_VS_CHECK_CMDHDR(pHdr, wr_mem);
	    pc_vs_wr_mem_cmd_t cmd_para;
	    BSTREAM_TO_UINT32(cmd_para.start_addr, pBuf);
	    BSTREAM_TO_UINT8(cmd_para.type, pBuf);
	    BSTREAM_TO_UINT8(cmd_para.length, pBuf);
	    pc_vs_wr_mem_handler(&cmd_para, pBuf);
	} break;
	case LHCI_OPCODE_VS_READ_REG: {
	    PC_VS_CHECK_CMDHDR(pHdr, rd_reg);
	    pc_vs_rd_reg_cmd_t cmd_para;
	    BSTREAM_TO_UINT32(cmd_para.reg_addr, pBuf);
	    pc_vs_read_reg_handler(&cmd_para);
	} break;
	case LHCI_OPCODE_VS_WRITE_REG: {
	    PC_VS_CHECK_CMDHDR(pHdr, wr_reg);
	    pc_vs_wr_reg_cmd_t cmd_para;
	    BSTREAM_TO_UINT32(cmd_para.reg_addr, pBuf);
	    BSTREAM_TO_UINT32(cmd_para.reg_value, pBuf);
	    pc_vs_write_reg_handler(&cmd_para);
	} break;
	case LHCI_OPCODE_VS_GET_TEST_TX_PKT_NUM: {
	    uint32_t test_tx_pkt_num = LlGetTestTxPktNum();
	    uint8_t *cmpl_evt = pc_vs_gen_cmd_cmpl_evt(sizeof(uint8_t) +
		sizeof(test_tx_pkt_num), pHdr->opCode);
	    uint8_t *evt_param = cmpl_evt;
	    UINT8_TO_BSTREAM(evt_param, HCI_SUCCESS);
	    UINT32_TO_BSTREAM(evt_param, test_tx_pkt_num);
	    pc_vs_send_cmd_cmpl_evt(cmpl_evt);
	} break;
	default:
	    return false;
    }

    return true;
}

#ifdef CONFIG_SOC_FAMILY_ATM
static int
#else
static rep_vec_err_t
#endif
pc_vs_cmd_init(void)
{
    LhciVsExtInit(pc_vs_decode_cmd);
#ifdef CONFIG_SOC_FAMILY_ATM
    return 0;
#else
    return RV_NEXT;
#endif
}

#ifdef CONFIG_SOC_FAMILY_ATM
SYS_INIT(pc_vs_cmd_init, APPLICATION, CONFIG_KERNEL_INIT_PRIORITY_DEVICE);
#else
__attribute__((constructor))
static void pc_vs_cmd_init_constructor(void)
{
    RV_APPM_INIT_ADD(pc_vs_cmd_init);
}
#endif
