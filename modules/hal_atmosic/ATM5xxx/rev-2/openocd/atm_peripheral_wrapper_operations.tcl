source [find regs/all_regs.tcl]

proc enable_dev { wrpr ctlr } {
    namespace eval ::CMSDK_WRPR${wrpr}${::SX}::APB${ctlr}_CTRL {
	mww [REG_ADDR] [CLK_ENABLE::MASK]
    }
}

proc disable_dev { wrpr ctlr } {
    namespace eval ::CMSDK_WRPR${wrpr}${::SX}::APB${ctlr}_CTRL {
	mww [REG_ADDR] 0
    }
}

proc reset_dev { wrpr ctlr } {
    namespace eval ::CMSDK_WRPR${wrpr}${::SX}::APB${ctlr}_CTRL {
	mww [REG_ADDR] [SRESET::MASK]
    }
}

proc enable_pwm {} {
    enable_dev 0 6
}

proc disable_pwm {} {
    disable_dev 0 6
}

proc reset_pwm {} {
    reset_dev 0 6
}

proc enable_spi0 {} {
    enable_dev 0 7
}

proc disable_spi0 {} {
    disable_dev 0 7
}

proc reset_spi0 {} {
    reset_dev 0 7
}

proc enable_ksm {} {
    enable_dev 0 10
}

proc disable_ksm {} {
    disable_dev 0 10
}

proc reset_ksm {} {
    reset_dev 0 10
}

proc enable_spi2 {} {
    enable_dev 0 11
}

proc disable_spi2 {} {
    disable_dev 0 11
}

proc reset_spi2 {} {
    reset_dev 0 11
}

proc enable_qdec {} {
    enable_dev 0 12
}

proc disable_qdec {} {
    disable_dev 0 12
}

proc reset_qdec {} {
    reset_dev 0 12
}

proc enable_spi1 {} {
    enable_dev 0 13
}

proc disable_spi1 {} {
    disable_dev 0 13
}

proc reset_spi1 {} {
    reset_dev 0 13
}

proc enable_slwtimer {} {
    enable_dev 0 14
}

proc disable_slwtimer {} {
    disable_dev 0 14
}

proc reset_slwtimer {} {
    reset_dev 0 14
}

proc enable_qspi {} {
    enable_dev 0 15
}

proc disable_qspi {} {
    disable_dev 0 15
}

proc reset_qspi {} {
    reset_dev 0 15
}

proc enable_i2c0 {} {
    enable_dev 1 0
}

proc disable_i2c0 {} {
    disable_dev 1 0
}

proc reset_i2c0 {} {
    reset_dev 1 0
}

proc enable_i2c1 {} {
    enable_dev 1 1
}

proc disable_i2c1 {} {
    disable_dev 1 1
}

proc reset_i2c1 {} {
    reset_dev 1 1
}

proc enable_nvm {} {
    enable_dev 1 2
}

proc disable_nvm {} {
    disable_dev 1 2
}

proc reset_nvm {} {
    reset_dev 1 2
}

proc enable_rif {} {
    enable_dev 1 4
}

proc disable_rif {} {
    disable_dev 1 4
}

proc reset_rif {} {
    reset_dev 1 4
}

proc enable_radio {} {
    enable_dev 1 5
}

proc disable_radio {} {
    disable_dev 1 5
}

proc reset_radio {} {
    reset_dev 1 5
}

proc enable_mdm {} {
    enable_dev 1 6
}

proc disable_mdm {} {
    disable_dev 1 6
}

proc reset_mdm {} {
    reset_dev 1 6
}

proc enable_pmu {} {
    enable_dev 1 7
}

proc disable_pmu {} {
    disable_dev 1 7
}

proc reset_pmu {} {
    reset_dev 1 7
}

proc enable_pseq {} {
    enable_dev 1 8
}

proc disable_pseq {} {
    disable_dev 1 8
}

proc reset_pseq {} {
    reset_dev 1 8
}

proc enable_swd {} {
    enable_dev 1 9
}

proc disable_swd {} {
    disable_dev 1 9
}

proc reset_swd {} {
    reset_dev 1 9
}

proc enable_gadc {} {
    enable_dev 1 10
}

proc disable_gadc {} {
    disable_dev 1 10
}

proc reset_gadc {} {
    reset_dev 1 10
}

proc enable_trng {} {
    enable_dev 1 11
}

proc disable_trng {} {
    disable_dev 1 11
}

proc reset_trng {} {
    reset_dev 1 11
}

proc enable_rcos_cal {} {
    enable_dev 1 12
}

proc disable_rcos_cal {} {
    disable_dev 1 12
}

proc reset_rcos_cal {} {
    reset_dev 1 12
}

proc enable_shub {} {
    enable_dev 1 13
}

proc disable_shub {} {
    disable_dev 1 13
}

proc reset_shub {} {
    reset_dev 1 13
}

proc enable_pdm0 {} {
    enable_dev 2 0
}

proc disable_pdm0 {} {
    disable_dev 2 0
}

proc reset_pdm0 {} {
    reset_dev 2 0
}

proc enable_pdm1 {} {
    enable_dev 2 1
}

proc disable_pdm1 {} {
    disable_dev 2 1
}

proc reset_pdm1 {} {
    reset_dev 2 1
}

proc enable_i2s {} {
    enable_dev 2 5
}

proc disable_i2s {} {
    disable_dev 2 5
}

proc reset_i2s {} {
    reset_dev 2 5
}

proc enable_clkrstgen {} {
    enable_dev 2 6
}

proc disable_clkrstgen {} {
    disable_dev 2 6
}

proc reset_clkrstgen {} {
    reset_dev 2 6
}
