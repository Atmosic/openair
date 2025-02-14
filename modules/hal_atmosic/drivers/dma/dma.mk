################################################################################
#
# @file dma.mk
#
# @brief Atmosic GNU Make file header for DMA driver
#
# Copyright (C) Atmosic 2025
#
################################################################################

dma.C_SRCS += dma.c
ifndef CFG_NO_DMA_FIFO_RX
CFLAGS += -DCONFIG_ATM_DMA_FIFO_RX
endif
