/*
 * Compatibility helper for Sydney testcodes
 */

#pragma once

#include "test_common.h"

static inline void UartStdOutInit(void)
{
    CommonInitCPU();
    CommonInitSystem();
}

static inline void UartEndSimulation(void)
{
    TEST_PASSED();
}

static inline void UartAbortSimulation(void)
{
    TEST_FAILED();
}
