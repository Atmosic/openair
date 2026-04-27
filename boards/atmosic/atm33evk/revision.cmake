# Copyright (c) 2022-2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

set(ATM33_VARIANT "normal" "mcuboot" "mcuboot_bl")
if(DEFINED BOARD_REVISION)
  if(NOT BOARD_REVISION IN_LIST ATM33_VARIANT)
    message(FATAL_ERROR "${BOARD_REVISION} is not a valid variant for ATMEVK33xx. Accepted revisions: ${ATM33_VARIANT}")
  endif()
endif()
