#
# reg_wrappers.tcl
# API to access device registers
# Copyright (C) Atmosic 2020-2026
#

proc setup_pkg_config {} {
    # Nothing to do here - QSPI flash has dedicated pins
}

#
# SPI
#

array set SPI0 {
    clkdiv	3
    dummy	0
}
set SPI0(ns)			"CMSDK_SPI0_NONSECURE"
set SPI0(base)			[::CMSDK_SPI0_NONSECURE::BASE]

array set SPI1 {
    clkdiv	3
    dummy	0
}
set SPI1(ns)			"CMSDK_SPI1_NONSECURE"
set SPI1(base)			[::CMSDK_SPI1_NONSECURE::BASE]

array set SPI2 {
    clkdiv	3
    dummy	0
}
set SPI2(ns)			"CMSDK_SPI2_NONSECURE"
set SPI2(base)			[::CMSDK_SPI2_NONSECURE::BASE]

array set RADIO {
    clkdiv	0
    dummy	3
}
set RADIO(ns)			"CMSDK_RADIO_NONSECURE"
set RADIO(base)			[::CMSDK_RADIO_NONSECURE::BASE]

array set PMU {
    clkdiv	0
    dummy	3
}
set PMU(ns)			"CMSDK_PMU_NONSECURE"
set PMU(base)			[::CMSDK_PMU_NONSECURE::BASE]
