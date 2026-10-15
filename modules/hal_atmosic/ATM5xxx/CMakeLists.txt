# Copyright (c) 2024-2026 Atmosic
#
# SPDX-License-Identifier: LicenseRef-Atmosic

if(CONFIG_SOC_ATM5XXX_2)
  set(PRECOMPILED_DRIVER_DIR "${CMAKE_CURRENT_SOURCE_DIR}/rev-2/drivers" CACHE
    PATH "Directory containing precompiled files")
  zephyr_include_directories(
    rev-2/include
    rev-2/include/arm
    rev-2/include/armgcc
    rev-2/include/reg
  )
endif()

# zephyr_code_relocate does not work with our precompiled object (.po) files
# by default. In order to get it to work, copy the po files as .po.obj files
# to the output directory, so that gen_relocate_app.py can find them. This
# allows us to place those files into RAM for increased execution speed
function(atm_relocate_fast_core_file po_folder fast_po_base)
  set(FAST_PRECOMPILED_DRIVER_DIR ${PROJECT_BINARY_DIR}/CMakeFiles/precompiled.dir)
  set(FAST_PO ${po_folder}/${fast_po_base})

  # Create output in the build directory and copy the precompiled object into
  # it, with a .obj suffix for Zephyr's gen_relocate_app.py script
  file(MAKE_DIRECTORY ${FAST_PRECOMPILED_DRIVER_DIR}/${po_folder}/)
  zephyr_file_copy(${PRECOMPILED_DRIVER_DIR}/${FAST_PO}
    ${FAST_PRECOMPILED_DRIVER_DIR}/${FAST_PO}.obj)

  # Link in the newly copied object
  zephyr_link_libraries(
    ${LINKERFLAGPREFIX},"${FAST_PRECOMPILED_DRIVER_DIR}/${FAST_PO}.obj"
  )

  # Relocate the original object
  zephyr_code_relocate(FILES "${PRECOMPILED_DRIVER_DIR}/${FAST_PO}" LOCATION RAM_TEXT_RODATA NOKEEP)
endfunction()

if(CONFIG_SOC_ATM5XXX_2)
  add_subdirectory(rev-2/drivers)
  add_subdirectory(rev-2/lib)
endif()
add_subdirectory(drivers)
add_subdirectory(src)

zephyr_linker_sources(NOINIT noinit.ld)
zephyr_linker_sources(RAMFUNC_SECTION ramfunc-section.ld)

# relocate HAL NSC functions and cache management into RAM
zephyr_compile_options_ifdef(CONFIG_ATM_HAL_ENABLE_NSC_IN_RAM -DATM_NSC_ENTRY_IN_RAM -DATM_CACHE_FUNC_IN_RAM)

if(CONFIG_ATM_RELOC_SRAM)
  zephyr_code_relocate(FILES
    ${ZEPHYR_BASE}/arch/arm/core/cortex_m/cpu_idle.c
    ${ZEPHYR_BASE}/arch/arm/core/cortex_m/exc_exit.c
    ${ZEPHYR_BASE}/arch/arm/core/cortex_m/irq_manage.c
    ${ZEPHYR_BASE}/arch/arm/core/cortex_m/swap_helper.S
    ${ZEPHYR_BASE}/arch/arm/core/cortex_m/thread.c
    ${ZEPHYR_BASE}/drivers/gpio/gpio_cmsdk_ahb.c
    ${ZEPHYR_BASE}/kernel/idle.c
    ${ZEPHYR_BASE}/kernel/poll.c
    ${ZEPHYR_BASE}/kernel/sched.c
    ${ZEPHYR_BASE}/kernel/sem.c
    ${ZEPHYR_BASE}/kernel/spinlock_validate.c
    ${ZEPHYR_BASE}/kernel/timeout.c
    ${ZEPHYR_BASE}/kernel/timer.c
    ${ZEPHYR_BASE}/kernel/timeslicing.c
    ${ZEPHYR_BASE}/subsys/pm/pm.c
    ${ZEPHYR_BASE}/subsys/pm/policy/policy_default.c
    ${ZEPHYR_BASE}/subsys/pm/policy/policy_events.c
    ${ZEPHYR_BASE}/subsys/pm/policy/policy_state_lock.c
    ${ZEPHYR_BASE}/subsys/pm/state.c
    LOCATION RAM_TEXT_RODATA NOKEEP
  )

  zephyr_code_relocate_ifdef(CONFIG_ENTROPY_GENERATOR
    LIBRARY drivers__entropy LOCATION RAM_TEXT_RODATA NOKEEP
  )
  zephyr_code_relocate(LIBRARY drivers__timer LOCATION RAM_TEXT_RODATA NOKEEP)
  zephyr_code_relocate(LIBRARY drivers__gpio LOCATION RAM_TEXT_RODATA NOKEEP)

  if(CONFIG_SOC_ATM5XXX_2)
    zephyr_code_relocate(FILES
      rev-2/drivers/hw_cfg/hw_cfg.c
      rev-2/drivers/lpc_rcos/lpc_rcos.c
      rev-2/drivers/rep_vec/rep_vec.c
      LOCATION RAM_TEXT_RODATA NOKEEP
    )
  endif()
  zephyr_code_relocate(FILES
    drivers/ble/src/ble_driver.c
    src/power.c
    ${ZEPHYR_OPENAIR_MODULE_DIR}/drivers/gpio/gpio_atm.c
    ${ZEPHYR_OPENAIR_MODULE_DIR}/modules/hal_atmosic/drivers/pc_ctr/pc_ctr.c
    ${ZEPHYR_OPENAIR_MODULE_DIR}/modules/hal_atmosic/drivers/radio_hal_ble/radio_hal_ble.c
    ${ZEPHYR_OPENAIR_MODULE_DIR}/modules/hal_atmosic/drivers/radio_hal_ble_cs/radio_hal_ble_cs.c
    ${ZEPHYR_OPENAIR_MODULE_DIR}/modules/hal_atmosic/drivers/radio_hal_ble_cte/radio_hal_ble_cte.c
    ${ZEPHYR_OPENAIR_MODULE_DIR}/modules/hal_atmosic/drivers/radio_hal_common/radio_hal_common.c
    ${ZEPHYR_OPENAIR_MODULE_DIR}/modules/hal_atmosic/drivers/radio_hal_frc/radio_hal_frc.c
    ${ZEPHYR_OPENAIR_MODULE_DIR}/modules/hal_atmosic/drivers/radio_hal_log/radio_hal_log.c
    ${ZEPHYR_OPENAIR_MODULE_DIR}/modules/hal_atmosic/drivers/radio_hal_prof/radio_hal_prof.c
    LOCATION RAM_TEXT_RODATA NOKEEP
  )
endif()
