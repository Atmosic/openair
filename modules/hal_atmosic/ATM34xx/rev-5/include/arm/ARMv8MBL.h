/**************************************************************************//**
 * @file     ARMv8MBL.h
 * @brief    CMSIS Core Peripheral Access Layer Header File for
 *           ARMv8MBL Device
 * @version  V5.3.1
 * @date     09. July 2018
 ******************************************************************************/
/*
 * Copyright (c) 2009-2018 Arm Limited. All rights reserved.
 * Copyright (c) 2024 Atmosic Technologies. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ARMv8MBL_H
#define ARMv8MBL_H

#ifdef __cplusplus
extern "C" {
#endif


/* -------------------------  Interrupt Number Definition  ------------------------ */

typedef enum IRQn
{
/* -------------------  Processor Exceptions Numbers  ----------------------------- */
  NonMaskableInt_IRQn           = -14,     /*  2 Non Maskable Interrupt */
  HardFault_IRQn                = -13,     /*  3 HardFault Interrupt */
  MemManage_IRQn                = -12,      /*  4 MemManage Fault Interrupt */
  BusFault_IRQn                 = -11,      /*  5 BusManage Fault Interrupt */
  UsageFault_IRQn               = -10,      /*  6 UsageManage Fault Interrupt */
  SecureFault_IRQn              =  -9,      /*  7 Secure Fault Interrupt */



  SVCall_IRQn                   =  -5,     /* 11 SVC Interrupt */
  DebugMon_IRQn                 =  -4,      /* 12 Debug Monitor Interrupt */

  PendSV_IRQn                   =  -2,     /* 14 PendSV Interrupt */
  SysTick_IRQn                  =  -1,     /* 15 System Tick Interrupt */

/* -------------------  Processor Interrupt Numbers  ------------------------------ */
  Interrupt0_IRQn               =   0,
  Interrupt1_IRQn               =   1,
  Interrupt2_IRQn               =   2,
  Interrupt3_IRQn               =   3,
  Interrupt4_IRQn               =   4,
  Interrupt5_IRQn               =   5,
  Interrupt6_IRQn               =   6,
  Interrupt7_IRQn               =   7,
  Interrupt8_IRQn               =   8,
  Interrupt9_IRQn               =   9,
  /* Interrupts 10 .. 480 are left out */
/*   NAME                           PORT       DESCRIPTION                         SSE200      SECURE  */
  NSECUREWDOG_RESETREQ_IRQn     =   0,      /* Non-secure watchdog reset request     Y                 */
  NSECUREWDOG_INT_IRQn          =   1,      /* Non-secure watchdog interrupt         Y                 */
  S32K_TIMER_IRQn               =   2,      /* S32K TIMER                            Y                 */
  TIMER0_IRQn                   =   3,      /* TIMER0 irq                                              */
  TIMER1_IRQn                   =   4,      /* TIMER1 irq                                              */
  DUALTIMER_IRQn                =   5,      /* DUALTIMER irq                                           */
  MHU0_CPU0_IRQn                =   6,      /* MHU0 CPU0 Interrupt                                     */
  MHU1_CPU0_IRQn                =   7,      /* MHU1 CPU0 Interrupt                                     */
  CRYPTO_IRQn                   =   8,      /* Cryptocell Interrupt                                    */
  MPC_COMB_SEC_IRQn             =   9,      /* MPC Combined Interrupt                Y          Y      */
  PPC_COMB_SEC_IRQn             =  10,      /* PPC Combined Interrupt                Y          Y      */
  MSC_COMB_SEC_IRQn             =  11,      /* MSC Combined Interrupt                Y          Y      */
  BRD_ERR_COMB_IRQn             =  12,      /* Bridge Error Combined Interrupt       Y          Y      */
  ICACHE_IRQn                   =  13,      /* Icache Invalidate Interrupt                             */
  RESERVED_14_IRQn              =  14,      /* RESERVED                                                */
  SW_0_IRQn                     =  15,      /* Software only                                            */
  SW_1_IRQn                     =  16,      /* Software only                                           */
  SW_2_IRQn                     =  17,      /* Software only                                           */
  CPU0DBG_PPU_IRQn              =  18,      /* CPU0 DBG PPU                                            */
  CPU1DBG_PPU_IRQn              =  19,      /* CPU1 DBG PPU                                            */
  CRYPT_PPU_IRQn                =  20,      /* CRYPT PPU                                               */
  RESERVED_21_IRQn              =  21,      /* RESERVED                                                */
  SW_3_IRQn                     =  22,      /* Software only                                           */
  SW_4_IRQn                     =  23,      /* Software only                                           */
  SW_5_IRQn                     =  24,      /* Software only                                           */
  SW_6_IRQn                     =  25,      /* Software only                                           */
  SW_7_IRQn                     =  26,      /* Software only                                           */
  RESERVED_27_IRQn              =  27,      /* RESERVED                                                */
  SW_8_IRQn                     =  28,      /* Software only                                           */
  SW_9_IRQn                     =  29,      /* Software only                                           */
  RESERVED_30_IRQn              =  30,      /* RESERVED                                                */
  RESERVED_31_IRQn              =  31,      /* RESERVED                                                */
  UARTRX0_IRQn                  =  32,      /* APB0 irq[0]   <-- uart0 rx                              */
  UARTTX0_IRQn                  =  33,      /* APB0 irq[1]   <-- uart0 tx                              */
  UARTRX1_IRQn                  =  34,      /* APB0 irq[2]   <-- uart1 rx                              */
  UARTTX1_IRQn                  =  35,      /* APB0 irq[3]   <-- uart1 tx                              */
  SPI1_IRQn                     =  36,      /* APB0 irq[4]   <-- spi1                                  */
  PORT2_13_IRQn                 =  37,      /* GPIO port 2 bit 13                                      */
  PORT2_14_IRQn                 =  38,      /* GPIO port 2 bit 14                                      */
  PORT2_15_IRQn                 =  39,      /* GPIO port 2 bit 15                                      */
  SPI0_IRQn                     =  40,      /* APB0 irq[8]   <-- spi0                                  */
  UART0_OVERFLOW_IRQn           =  41,      /* APB0 irq[9]   <-- uart0 overflow                        */
  UART1_OVERFLOW_IRQn           =  42,      /* APB0 irq[10]  <-- uart1 overflow                        */
  KSM_IRQn                      =  43,      /* APB0 irq[11]  <-- ksm                                   */
  SLWTIMER_IRQn                 =  44,      /* APB0 irq[12]  <-- slwtimer                              */
  SPI2_IRQn                     =  45,      /* APB0 irq[13]  <-- spi2                                  */
  PWM_IRQn                      =  46,      /* APB0 irq[14]  <-- pwm                                   */
  QSPI_BREAKIN_IRQn		=  47,      /* APB0 irq[15]                                            */
  SPI_RADIO_IRQn                =  48,      /* APB1 irq[0]   <-- radio                                 */
  SPI_PMU_IRQn                  =  49,      /* APB1 irq[1]   <-- pmu                                   */
  I2C0_IRQn                     =  50,      /* APB1 irq[2]   <-- i2c0                                  */
  I2C1_IRQn                     =  51,      /* APB1 irq[3]   <-- i2c1                                  */
  NVM_IRQn                      =  52,      /* APB1 irq[4]   <-- nvm                                   */
  GADC_IRQn                     =  53,      /* APB1 irq[5]   <-- gadc                                  */
  TRNG_IRQn                     =  54,      /* APB1 irq[6]   <-- trng                                  */
  RCOS_IRQn                     =  55,      /* APB1 irq[7]   <-- rcos                                  */
  PDM0_IRQn                     =  56,      /* APB2 irq[0]   <-- pdm0                                  */
  UART2_OVERFLOW_IRQn           =  57,      /* APB2 irq[8]   <-- uart2 overflow                        */
  PORT2_ALL_IRQn                =  58,      /* GPIO port 2 combined interrupt                          */
  PORT3_ALL_IRQn                =  59,      /* GPIO port 3 combined interrupt                          */
  I2S_IRQn                      =  60,      /* APB2 irq[4]   <-- i2s                                   */
  AES_IRQn                      =  61,      /* APB2 irq[5]   <-- aes                                   */
  UARTRX2_IRQn                  =  62,      /* APB2 irq[6]   <-- uart2 rx                              */
  UARTTX2_IRQn                  =  63,      /* APB2 irq[7]   <-- uart2 tx                              */
  MDM_IRQn                      =  64,      /* mdm_irq                                                 */
  PLL_READY_IRQn                =  65,      /*                                                         */
  XTAL_STABLE_IRQn              =  66,      /*                                                         */
  CALTX_DONE_IRQn               =  67,      /*                                                         */
  DMA0_IRQn                     =  68,      /* dma0_done|dma0_err                                      */
  DMA1_IRQn                     =  69,      /* dma1_done|dma1_err                                      */
  DMA2_IRQn                     =  70,      /* dma2_done|dma2_err                                      */
  DMA3_IRQn                     =  71,      /* dma3_done|dma3_err                                      */
  ATLC_FRC_IRQn                 =  72,      /* at_lc_frc_irq                                           */
  PSEQ_FRC0_IRQn                =  73,      /* pseq_frc0_irq                                           */
  PSEQ_CNTDWN_TIMER_IRQn        =  74,      /* cntdown_timer_irq                                       */
  PSEQ_CNTDWN_TIMER_1_IRQn      =  75,      /* cntdown_timer_1_irq                                     */
  PSEQ_FRC1_IRQn                =  76,      /* pseq_frc1_irq                                           */
  WAIT4DBLR_IRQn                =  77,      /* wait4doubler_irq                                        */
  PORT2_0_IRQn                  =  78,      /* GPIO port 2 bit 0                                       */
  PORT2_1_IRQn                  =  79,      /* GPIO port 2 bit 1                                       */
  PORT2_2_IRQn                  =  80,      /* GPIO port 2 bit 2                                       */
  PORT2_3_IRQn                  =  81,      /* GPIO port 2 bit 3                                       */
  PORT2_4_IRQn                  =  82,      /* GPIO port 2 bit 4                                       */
  PORT2_5_IRQn                  =  83,      /* GPIO port 2 bit 5                                       */
  PORT2_6_IRQn                  =  84,      /* GPIO port 2 bit 6                                       */
  PORT2_7_IRQn                  =  85,      /* GPIO port 2 bit 7                                       */
  PORT2_8_IRQn                  =  86,      /* GPIO port 2 bit 8                                       */
  PORT2_9_IRQn                  =  87,      /* GPIO port 2 bit 9                                       */
  PORT2_10_IRQn                 =  88,      /* GPIO port 2 bit 10                                      */
  PORT2_11_IRQn                 =  89,      /* GPIO port 2 bit 11                                      */
  PORT2_12_IRQn                 =  90,      /* GPIO port 2 bit 12                                      */
  PSEQ_IRQn                     =  91,      /* pseq irq                                                */
  PMU_IRQn                      =  92,      /* pmu irq                                                 */
  PORT0_ALL_IRQn                =  93,      /* GPIO port 0 combined interrupt                          */
  PORT1_ALL_IRQn                =  94,      /* GPIO port 1 combined interrupt                          */
  ATLC_IRQn                     =  95,      /* at_lc_irq                                               */
  PORT0_0_IRQn                  =  96,      /* GPIO port 0 bit 0                                       */
  PORT0_1_IRQn                  =  97,      /* GPIO port 0 bit 1                                       */
  PORT0_2_IRQn                  =  98,      /* GPIO port 0 bit 2                                       */
  PORT0_3_IRQn                  =  99,      /* GPIO port 0 bit 3                                       */
  PORT0_4_IRQn                  =  100,     /* GPIO port 0 bit 4                                       */
  PORT0_5_IRQn                  =  101,     /* GPIO port 0 bit 5                                       */
  PORT0_6_IRQn                  =  102,     /* GPIO port 0 bit 6                                       */
  PORT0_7_IRQn                  =  103,     /* GPIO port 0 bit 7                                       */
  PORT0_8_IRQn                  =  104,     /* GPIO port 0 bit 8                                       */
  PORT0_9_IRQn                  =  105,     /* GPIO port 0 bit 9                                       */
  PORT0_10_IRQn                 =  106,     /* GPIO port 0 bit 10                                      */
  PORT0_11_IRQn                 =  107,     /* GPIO port 0 bit 11                                      */
  PORT0_12_IRQn                 =  108,     /* GPIO port 0 bit 12                                      */
  PORT0_13_IRQn                 =  109,     /* GPIO port 0 bit 13                                      */
  PORT0_14_IRQn                 =  110,     /* GPIO port 0 bit 14                                      */
  PORT0_15_IRQn                 =  111,     /* GPIO port 0 bit 15                                      */
  PORT1_0_IRQn                  =  112,     /* GPIO port 1 bit 0                                       */
  PORT1_1_IRQn                  =  113,     /* GPIO port 1 bit 1                                       */
  PORT1_2_IRQn                  =  114,     /* GPIO port 1 bit 2                                       */
  PORT1_3_IRQn                  =  115,     /* GPIO port 1 bit 3                                       */
  PORT1_4_IRQn                  =  116,     /* GPIO port 1 bit 4                                       */
  PORT1_5_IRQn                  =  117,     /* GPIO port 1 bit 5                                       */
  PORT1_6_IRQn                  =  118,     /* GPIO port 1 bit 6                                       */
  PORT1_7_IRQn                  =  119,     /* GPIO port 1 bit 7                                       */
  PORT1_8_IRQn                  =  120,     /* GPIO port 1 bit 8                                       */
  PORT1_9_IRQn                  =  121,     /* GPIO port 1 bit 9                                       */
  PORT1_10_IRQn                 =  122,     /* GPIO port 1 bit 10                                      */
  PORT1_11_IRQn                 =  123,     /* GPIO port 1 bit 11                                      */
  PORT1_12_IRQn                 =  124,     /* GPIO port 1 bit 12                                      */
  PORT1_13_IRQn                 =  125,     /* GPIO port 1 bit 13                                      */
  PORT1_14_IRQn                 =  126,     /* GPIO port 1 bit 14                                      */
  PORT1_15_IRQn                 =  127,     /* GPIO port 1 bit 15                                      */
  EXPIRQn_128                   =  128,     /* RESERVED                                                */
  EXPIRQn_129                   =  129,     /* RESERVED                                                */
  EXPIRQn_130                   =  130,     /* RESERVED                                                */
  EXPIRQn_131                   =  131,     /* RESERVED                                                */
  EXPIRQn_132                   =  132,     /* RESERVED                                                */
  EXPIRQn_133                   =  133,     /* RESERVED                                                */
  EXPIRQn_134                   =  134,     /* RESERVED                                                */
  EXPIRQn_135                   =  135,     /* RESERVED                                                */
  EXPIRQn_136                   =  136,     /* RESERVED                                                */
  EXPIRQn_137                   =  137,     /* RESERVED                                                */
  EXPIRQn_138                   =  138,     /* RESERVED                                                */
  EXPIRQn_139                   =  139,     /* RESERVED                                                */
  EXPIRQn_140                   =  140,     /* RESERVED                                                */
  EXPIRQn_141                   =  141,     /* RESERVED                                                */
  EXPIRQn_142                   =  142,     /* RESERVED                                                */
  EXPIRQn_143                   =  143,     /* RESERVED                                                */
  EXPIRQn_144                   =  144,     /* RESERVED                                                */
  EXPIRQn_145                   =  145,     /* RESERVED                                                */
  EXPIRQn_146                   =  146,     /* RESERVED                                                */
  EXPIRQn_147                   =  147,     /* RESERVED                                                */
  EXPIRQn_148                   =  148,     /* RESERVED                                                */
  EXPIRQn_149                   =  149,     /* RESERVED                                                */
  EXPIRQn_150                   =  150,     /* RESERVED                                                */
  EXPIRQn_151                   =  151,     /* RESERVED                                                */
  EXPIRQn_152                   =  152,     /* RESERVED                                                */
  EXPIRQn_153                   =  153,     /* RESERVED                                                */
  EXPIRQn_154                   =  154,     /* RESERVED                                                */
  EXPIRQn_155                   =  155,     /* RESERVED                                                */
  EXPIRQn_156                   =  156,     /* RESERVED                                                */
  EXPIRQn_157                   =  157,     /* RESERVED                                                */
  EXPIRQn_158                   =  158,     /* RESERVED                                                */
  EXPIRQn_159                   =  159,     /* RESERVED                                                */
  EXPIRQn_160                   =  160,     /* RESERVED                                                */
  EXPIRQn_161                   =  161,     /* RESERVED                                                */
  EXPIRQn_162                   =  162,     /* RESERVED                                                */
  EXPIRQn_163                   =  163,     /* RESERVED                                                */
  EXPIRQn_164                   =  164,     /* RESERVED                                                */
  EXPIRQn_165                   =  165,     /* RESERVED                                                */
  EXPIRQn_166                   =  166,     /* RESERVED                                                */
  EXPIRQn_167                   =  167,     /* RESERVED                                                */
  EXPIRQn_168                   =  168,     /* RESERVED                                                */
  EXPIRQn_169                   =  169,     /* RESERVED                                                */
  EXPIRQn_170                   =  170,     /* RESERVED                                                */
  EXPIRQn_171                   =  171,     /* RESERVED                                                */
  EXPIRQn_172                   =  172,     /* RESERVED                                                */
  EXPIRQn_173                   =  173,     /* RESERVED                                                */
  EXPIRQn_174                   =  174,     /* RESERVED                                                */
  EXPIRQn_175                   =  175,     /* RESERVED                                                */
  EXPIRQn_176                   =  176,     /* RESERVED                                                */
  EXPIRQn_177                   =  177,     /* RESERVED                                                */
  EXPIRQn_178                   =  178,     /* RESERVED                                                */
  EXPIRQn_179                   =  179,     /* RESERVED                                                */
  EXPIRQn_180                   =  180,     /* RESERVED                                                */
  EXPIRQn_181                   =  181,     /* RESERVED                                                */
  EXPIRQn_182                   =  182,     /* RESERVED                                                */
  EXPIRQn_183                   =  183,     /* RESERVED                                                */
  EXPIRQn_184                   =  184,     /* RESERVED                                                */
  EXPIRQn_185                   =  185,     /* RESERVED                                                */
  EXPIRQn_186                   =  186,     /* RESERVED                                                */
  EXPIRQn_187                   =  187,     /* RESERVED                                                */
  EXPIRQn_188                   =  188,     /* RESERVED                                                */
  EXPIRQn_189                   =  189,     /* RESERVED                                                */
  EXPIRQn_190                   =  190,     /* RESERVED                                                */
  EXPIRQn_191                   =  191,     /* RESERVED                                                */
  EXPIRQn_192                   =  192,     /* RESERVED                                                */
  EXPIRQn_193                   =  193,     /* RESERVED                                                */
  EXPIRQn_194                   =  194,     /* RESERVED                                                */
  EXPIRQn_195                   =  195,     /* RESERVED                                                */
  EXPIRQn_196                   =  196,     /* RESERVED                                                */
  EXPIRQn_197                   =  197,     /* RESERVED                                                */
  EXPIRQn_198                   =  198,     /* RESERVED                                                */
  EXPIRQn_199                   =  199,     /* RESERVED                                                */
  EXPIRQn_200                   =  200,     /* RESERVED                                                */
  EXPIRQn_201                   =  201,     /* RESERVED                                                */
  EXPIRQn_202                   =  202,     /* RESERVED                                                */
  EXPIRQn_203                   =  203,     /* RESERVED                                                */
  EXPIRQn_204                   =  204,     /* RESERVED                                                */
  EXPIRQn_205                   =  205,     /* RESERVED                                                */
  EXPIRQn_206                   =  206,     /* RESERVED                                                */
  EXPIRQn_207                   =  207,     /* RESERVED                                                */
  EXPIRQn_208                   =  208,     /* RESERVED                                                */
  EXPIRQn_209                   =  209,     /* RESERVED                                                */
  EXPIRQn_210                   =  210,     /* RESERVED                                                */
  EXPIRQn_211                   =  211,     /* RESERVED                                                */
  EXPIRQn_212                   =  212,     /* RESERVED                                                */
  EXPIRQn_213                   =  213,     /* RESERVED                                                */
  EXPIRQn_214                   =  214,     /* RESERVED                                                */
  EXPIRQn_215                   =  215,     /* RESERVED                                                */
  EXPIRQn_216                   =  216,     /* RESERVED                                                */
  EXPIRQn_217                   =  217,     /* RESERVED                                                */
  EXPIRQn_218                   =  218,     /* RESERVED                                                */
  EXPIRQn_219                   =  219,     /* RESERVED                                                */
  EXPIRQn_220                   =  220,     /* RESERVED                                                */
  EXPIRQn_221                   =  221,     /* RESERVED                                                */
  EXPIRQn_222                   =  222,     /* RESERVED                                                */
  EXPIRQn_223                   =  223,     /* RESERVED                                                */
  EXPIRQn_224                   =  224,     /* RESERVED                                                */
  EXPIRQn_225                   =  225,     /* RESERVED                                                */
  EXPIRQn_226                   =  226,     /* RESERVED                                                */
  EXPIRQn_227                   =  227,     /* RESERVED                                                */
  EXPIRQn_228                   =  228,     /* RESERVED                                                */
  EXPIRQn_229                   =  229,     /* RESERVED                                                */
  EXPIRQn_230                   =  230,     /* RESERVED                                                */
  EXPIRQn_231                   =  231,     /* RESERVED                                                */
  EXPIRQn_232                   =  232,     /* RESERVED                                                */
  EXPIRQn_233                   =  233,     /* RESERVED                                                */
  EXPIRQn_234                   =  234,     /* RESERVED                                                */
  EXPIRQn_235                   =  235,     /* RESERVED                                                */
  EXPIRQn_236                   =  236,     /* RESERVED                                                */
  EXPIRQn_237                   =  237,     /* RESERVED                                                */
  EXPIRQn_238                   =  238,     /* RESERVED                                                */
  EXPIRQn_239                   =  239,     /* RESERVED                                                */
  EXPIRQn_240                   =  240,     /* RESERVED                                                */
  EXPIRQn_241                   =  241,     /* RESERVED                                                */
  EXPIRQn_242                   =  242,     /* RESERVED                                                */
  EXPIRQn_243                   =  243,     /* RESERVED                                                */
  EXPIRQn_244                   =  244,     /* RESERVED                                                */
  EXPIRQn_245                   =  245,     /* RESERVED                                                */
  EXPIRQn_246                   =  246,     /* RESERVED                                                */
  EXPIRQn_247                   =  247,     /* RESERVED                                                */
  EXPIRQn_248                   =  248,     /* RESERVED                                                */
  EXPIRQn_249                   =  249,     /* RESERVED                                                */
  EXPIRQn_250                   =  250,     /* RESERVED                                                */
  EXPIRQn_251                   =  251,     /* RESERVED                                                */
  EXPIRQn_252                   =  252,     /* RESERVED                                                */
  EXPIRQn_253                   =  253,     /* RESERVED                                                */
  EXPIRQn_254                   =  254,     /* RESERVED                                                */
  EXPIRQn_255                   =  255,     /* RESERVED                                                */
  EXPIRQn_256                   =  256,     /* RESERVED                                                */
  EXPIRQn_257                   =  257,     /* RESERVED                                                */
  EXPIRQn_258                   =  258,     /* RESERVED                                                */
  EXPIRQn_259                   =  259,     /* RESERVED                                                */
  EXPIRQn_260                   =  260,     /* RESERVED                                                */
  EXPIRQn_261                   =  261,     /* RESERVED                                                */
  EXPIRQn_262                   =  262,     /* RESERVED                                                */
  EXPIRQn_263                   =  263,     /* RESERVED                                                */
  EXPIRQn_264                   =  264,     /* RESERVED                                                */
  EXPIRQn_265                   =  265,     /* RESERVED                                                */
  EXPIRQn_266                   =  266,     /* RESERVED                                                */
  EXPIRQn_267                   =  267,     /* RESERVED                                                */
  EXPIRQn_268                   =  268,     /* RESERVED                                                */
  EXPIRQn_269                   =  269,     /* RESERVED                                                */
  EXPIRQn_270                   =  270,     /* RESERVED                                                */
  EXPIRQn_271                   =  271,     /* RESERVED                                                */
  EXPIRQn_272                   =  272,     /* RESERVED                                                */
  EXPIRQn_273                   =  273,     /* RESERVED                                                */
  EXPIRQn_274                   =  274,     /* RESERVED                                                */
  EXPIRQn_275                   =  275,     /* RESERVED                                                */
  EXPIRQn_276                   =  276,     /* RESERVED                                                */
  EXPIRQn_277                   =  277,     /* RESERVED                                                */
  EXPIRQn_278                   =  278,     /* RESERVED                                                */
  EXPIRQn_279                   =  279,     /* RESERVED                                                */
  EXPIRQn_280                   =  280,     /* RESERVED                                                */
  EXPIRQn_281                   =  281,     /* RESERVED                                                */
  EXPIRQn_282                   =  282,     /* RESERVED                                                */
  EXPIRQn_283                   =  283,     /* RESERVED                                                */
  EXPIRQn_284                   =  284,     /* RESERVED                                                */
  EXPIRQn_285                   =  285,     /* RESERVED                                                */
  EXPIRQn_286                   =  286,     /* RESERVED                                                */
  EXPIRQn_287                   =  287,     /* RESERVED                                                */
  EXPIRQn_288                   =  288,     /* RESERVED                                                */
  EXPIRQn_289                   =  289,     /* RESERVED                                                */
  EXPIRQn_290                   =  290,     /* RESERVED                                                */
  EXPIRQn_291                   =  291,     /* RESERVED                                                */
  EXPIRQn_292                   =  292,     /* RESERVED                                                */
  EXPIRQn_293                   =  293,     /* RESERVED                                                */
  EXPIRQn_294                   =  294,     /* RESERVED                                                */
  EXPIRQn_295                   =  295,     /* RESERVED                                                */
  EXPIRQn_296                   =  296,     /* RESERVED                                                */
  EXPIRQn_297                   =  297,     /* RESERVED                                                */
  EXPIRQn_298                   =  298,     /* RESERVED                                                */
  EXPIRQn_299                   =  299,     /* RESERVED                                                */
  EXPIRQn_300                   =  300,     /* RESERVED                                                */
  EXPIRQn_301                   =  301,     /* RESERVED                                                */
  EXPIRQn_302                   =  302,     /* RESERVED                                                */
  EXPIRQn_303                   =  303,     /* RESERVED                                                */
  EXPIRQn_304                   =  304,     /* RESERVED                                                */
  EXPIRQn_305                   =  305,     /* RESERVED                                                */
  EXPIRQn_306                   =  306,     /* RESERVED                                                */
  EXPIRQn_307                   =  307,     /* RESERVED                                                */
  EXPIRQn_308                   =  308,     /* RESERVED                                                */
  EXPIRQn_309                   =  309,     /* RESERVED                                                */
  EXPIRQn_310                   =  310,     /* RESERVED                                                */
  EXPIRQn_311                   =  311,     /* RESERVED                                                */
  EXPIRQn_312                   =  312,     /* RESERVED                                                */
  EXPIRQn_313                   =  313,     /* RESERVED                                                */
  EXPIRQn_314                   =  314,     /* RESERVED                                                */
  EXPIRQn_315                   =  315,     /* RESERVED                                                */
  EXPIRQn_316                   =  316,     /* RESERVED                                                */
  EXPIRQn_317                   =  317,     /* RESERVED                                                */
  EXPIRQn_318                   =  318,     /* RESERVED                                                */
  EXPIRQn_319                   =  319,     /* RESERVED                                                */
  EXPIRQn_320                   =  320,     /* RESERVED                                                */
  EXPIRQn_321                   =  321,     /* RESERVED                                                */
  EXPIRQn_322                   =  322,     /* RESERVED                                                */
  EXPIRQn_323                   =  323,     /* RESERVED                                                */
  EXPIRQn_324                   =  324,     /* RESERVED                                                */
  EXPIRQn_325                   =  325,     /* RESERVED                                                */
  EXPIRQn_326                   =  326,     /* RESERVED                                                */
  EXPIRQn_327                   =  327,     /* RESERVED                                                */
  EXPIRQn_328                   =  328,     /* RESERVED                                                */
  EXPIRQn_329                   =  329,     /* RESERVED                                                */
  EXPIRQn_330                   =  330,     /* RESERVED                                                */
  EXPIRQn_331                   =  331,     /* RESERVED                                                */
  EXPIRQn_332                   =  332,     /* RESERVED                                                */
  EXPIRQn_333                   =  333,     /* RESERVED                                                */
  EXPIRQn_334                   =  334,     /* RESERVED                                                */
  EXPIRQn_335                   =  335,     /* RESERVED                                                */
  EXPIRQn_336                   =  336,     /* RESERVED                                                */
  EXPIRQn_337                   =  337,     /* RESERVED                                                */
  EXPIRQn_338                   =  338,     /* RESERVED                                                */
  EXPIRQn_339                   =  339,     /* RESERVED                                                */
  EXPIRQn_340                   =  340,     /* RESERVED                                                */
  EXPIRQn_341                   =  341,     /* RESERVED                                                */
  EXPIRQn_342                   =  342,     /* RESERVED                                                */
  EXPIRQn_343                   =  343,     /* RESERVED                                                */
  EXPIRQn_344                   =  344,     /* RESERVED                                                */
  EXPIRQn_345                   =  345,     /* RESERVED                                                */
  EXPIRQn_346                   =  346,     /* RESERVED                                                */
  EXPIRQn_347                   =  347,     /* RESERVED                                                */
  EXPIRQn_348                   =  348,     /* RESERVED                                                */
  EXPIRQn_349                   =  349,     /* RESERVED                                                */
  EXPIRQn_350                   =  350,     /* RESERVED                                                */
  EXPIRQn_351                   =  351,     /* RESERVED                                                */
  EXPIRQn_352                   =  352,     /* RESERVED                                                */
  EXPIRQn_353                   =  353,     /* RESERVED                                                */
  EXPIRQn_354                   =  354,     /* RESERVED                                                */
  EXPIRQn_355                   =  355,     /* RESERVED                                                */
  EXPIRQn_356                   =  356,     /* RESERVED                                                */
  EXPIRQn_357                   =  357,     /* RESERVED                                                */
  EXPIRQn_358                   =  358,     /* RESERVED                                                */
  EXPIRQn_359                   =  359,     /* RESERVED                                                */
  EXPIRQn_360                   =  360,     /* RESERVED                                                */
  EXPIRQn_361                   =  361,     /* RESERVED                                                */
  EXPIRQn_362                   =  362,     /* RESERVED                                                */
  EXPIRQn_363                   =  363,     /* RESERVED                                                */
  EXPIRQn_364                   =  364,     /* RESERVED                                                */
  EXPIRQn_365                   =  365,     /* RESERVED                                                */
  EXPIRQn_366                   =  366,     /* RESERVED                                                */
  EXPIRQn_367                   =  367,     /* RESERVED                                                */
  EXPIRQn_368                   =  368,     /* RESERVED                                                */
  EXPIRQn_369                   =  369,     /* RESERVED                                                */
  EXPIRQn_370                   =  370,     /* RESERVED                                                */
  EXPIRQn_371                   =  371,     /* RESERVED                                                */
  EXPIRQn_372                   =  372,     /* RESERVED                                                */
  EXPIRQn_373                   =  373,     /* RESERVED                                                */
  EXPIRQn_374                   =  374,     /* RESERVED                                                */
  EXPIRQn_375                   =  375,     /* RESERVED                                                */
  EXPIRQn_376                   =  376,     /* RESERVED                                                */
  EXPIRQn_377                   =  377,     /* RESERVED                                                */
  EXPIRQn_378                   =  378,     /* RESERVED                                                */
  EXPIRQn_379                   =  379,     /* RESERVED                                                */
  EXPIRQn_380                   =  380,     /* RESERVED                                                */
  EXPIRQn_381                   =  381,     /* RESERVED                                                */
  EXPIRQn_382                   =  382,     /* RESERVED                                                */
  EXPIRQn_383                   =  383,     /* RESERVED                                                */
  EXPIRQn_384                   =  384,     /* RESERVED                                                */
  EXPIRQn_385                   =  385,     /* RESERVED                                                */
  EXPIRQn_386                   =  386,     /* RESERVED                                                */
  EXPIRQn_387                   =  387,     /* RESERVED                                                */
  EXPIRQn_388                   =  388,     /* RESERVED                                                */
  EXPIRQn_389                   =  389,     /* RESERVED                                                */
  EXPIRQn_390                   =  390,     /* RESERVED                                                */
  EXPIRQn_391                   =  391,     /* RESERVED                                                */
  EXPIRQn_392                   =  392,     /* RESERVED                                                */
  EXPIRQn_393                   =  393,     /* RESERVED                                                */
  EXPIRQn_394                   =  394,     /* RESERVED                                                */
  EXPIRQn_395                   =  395,     /* RESERVED                                                */
  EXPIRQn_396                   =  396,     /* RESERVED                                                */
  EXPIRQn_397                   =  397,     /* RESERVED                                                */
  EXPIRQn_398                   =  398,     /* RESERVED                                                */
  EXPIRQn_399                   =  399,     /* RESERVED                                                */
  EXPIRQn_400                   =  400,     /* RESERVED                                                */
  EXPIRQn_401                   =  401,     /* RESERVED                                                */
  EXPIRQn_402                   =  402,     /* RESERVED                                                */
  EXPIRQn_403                   =  403,     /* RESERVED                                                */
  EXPIRQn_404                   =  404,     /* RESERVED                                                */
  EXPIRQn_405                   =  405,     /* RESERVED                                                */
  EXPIRQn_406                   =  406,     /* RESERVED                                                */
  EXPIRQn_407                   =  407,     /* RESERVED                                                */
  EXPIRQn_408                   =  408,     /* RESERVED                                                */
  EXPIRQn_409                   =  409,     /* RESERVED                                                */
  EXPIRQn_410                   =  410,     /* RESERVED                                                */
  EXPIRQn_411                   =  411,     /* RESERVED                                                */
  EXPIRQn_412                   =  412,     /* RESERVED                                                */
  EXPIRQn_413                   =  413,     /* RESERVED                                                */
  EXPIRQn_414                   =  414,     /* RESERVED                                                */
  EXPIRQn_415                   =  415,     /* RESERVED                                                */
  EXPIRQn_416                   =  416,     /* RESERVED                                                */
  EXPIRQn_417                   =  417,     /* RESERVED                                                */
  EXPIRQn_418                   =  418,     /* RESERVED                                                */
  EXPIRQn_419                   =  419,     /* RESERVED                                                */
  EXPIRQn_420                   =  420,     /* RESERVED                                                */
  EXPIRQn_421                   =  421,     /* RESERVED                                                */
  EXPIRQn_422                   =  422,     /* RESERVED                                                */
  EXPIRQn_423                   =  423,     /* RESERVED                                                */
  EXPIRQn_424                   =  424,     /* RESERVED                                                */
  EXPIRQn_425                   =  425,     /* RESERVED                                                */
  EXPIRQn_426                   =  426,     /* RESERVED                                                */
  EXPIRQn_427                   =  427,     /* RESERVED                                                */
  EXPIRQn_428                   =  428,     /* RESERVED                                                */
  EXPIRQn_429                   =  429,     /* RESERVED                                                */
  EXPIRQn_430                   =  430,     /* RESERVED                                                */
  EXPIRQn_431                   =  431,     /* RESERVED                                                */
  EXPIRQn_432                   =  432,     /* RESERVED                                                */
  EXPIRQn_433                   =  433,     /* RESERVED                                                */
  EXPIRQn_434                   =  434,     /* RESERVED                                                */
  EXPIRQn_435                   =  435,     /* RESERVED                                                */
  EXPIRQn_436                   =  436,     /* RESERVED                                                */
  EXPIRQn_437                   =  437,     /* RESERVED                                                */
  EXPIRQn_438                   =  438,     /* RESERVED                                                */
  EXPIRQn_439                   =  439,     /* RESERVED                                                */
  EXPIRQn_440                   =  440,     /* RESERVED                                                */
  EXPIRQn_441                   =  441,     /* RESERVED                                                */
  EXPIRQn_442                   =  442,     /* RESERVED                                                */
  EXPIRQn_443                   =  443,     /* RESERVED                                                */
  EXPIRQn_444                   =  444,     /* RESERVED                                                */
  EXPIRQn_445                   =  445,     /* RESERVED                                                */
  EXPIRQn_446                   =  446,     /* RESERVED                                                */
  EXPIRQn_447                   =  447,     /* RESERVED                                                */
  EXPIRQn_448                   =  448      /* RESERVED                                                */
} IRQn_Type;


/* ================================================================================ */
/* ================      Processor and Core Peripheral Section     ================ */
/* ================================================================================ */

/* -------  Start of section using anonymous unions and disabling warnings  ------- */
#if   defined (__CC_ARM)
  #pragma push
  #pragma anon_unions
#elif defined (__ICCARM__)
  #pragma language=extended
#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #pragma clang diagnostic push
  #pragma clang diagnostic ignored "-Wc11-extensions"
  #pragma clang diagnostic ignored "-Wreserved-id-macro"
#elif defined (__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined (__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined (__TASKING__)
  #pragma warning 586
#elif defined (__CSMC__)
  /* anonymous unions are enabled by default */
#else
  #warning Not supported compiler type
#endif


/* --------  Configuration of Core Peripherals  ----------------------------------- */
#define __ARMv8MBL_REV            0x0000U   /* Core revision r0p0 */
#define __SAUREGION_PRESENT       1U        /* SAU regions are present */
#define __MPU_PRESENT             1U        /* MPU present */
#define __VTOR_PRESENT            1U        /* VTOR present */
#define __FPU_PRESENT             1U        /* FPU present */
#define __DSP_PRESENT             1U        /* DSP extension present */
#define __NVIC_PRIO_BITS          4U        /* Number of Bits used for Priority Levels */
#define __Vendor_SysTickConfig    0U        /* Set to 1 if different SysTick Config is used */

#include "core_armv8mml.h"                  /* Processor and core peripherals */
#include "system_ARMv8MBL.h"                /* System Header */



/* ================================================================================ */
/* ================       Device Specific Peripheral Section       ================ */
/* ================================================================================ */

/*----------------------------- Timer (TIMER) -------------------------------*/
typedef struct
{
  __IOM  uint32_t  CTRL;                     /* Offset: 0x000 (R/W) Control Register */
  __IOM  uint32_t  VALUE;                    /* Offset: 0x004 (R/W) Current Value Register */
  __IOM  uint32_t  RELOAD;                   /* Offset: 0x008 (R/W) Reload Value Register */
  union {
    __IM   uint32_t  INTSTATUS;              /* Offset: 0x00C (R/ ) Interrupt Status Register */
    __OM   uint32_t  INTCLEAR;               /* Offset: 0x00C ( /W) Interrupt Clear Register */
    };
  __IOM  uint32_t  PRESCALE;                 /* Offset: 0x010 (R/W) Prescale Value Register */

} CMSDK_TIMER_TypeDef;

/* CMSDK_TIMER CTRL Register Definitions */
#define CMSDK_TIMER_CTRL_IRQEN_Pos          3                                                /* CMSDK_TIMER CTRL: IRQEN Position */
#define CMSDK_TIMER_CTRL_IRQEN_Msk         (0x01UL << CMSDK_TIMER_CTRL_IRQEN_Pos)            /* CMSDK_TIMER CTRL: IRQEN Mask */

#define CMSDK_TIMER_CTRL_SELEXTCLK_Pos      2                                                /* CMSDK_TIMER CTRL: SELEXTCLK Position */
#define CMSDK_TIMER_CTRL_SELEXTCLK_Msk     (0x01UL << CMSDK_TIMER_CTRL_SELEXTCLK_Pos)        /* CMSDK_TIMER CTRL: SELEXTCLK Mask */

#define CMSDK_TIMER_CTRL_SELEXTEN_Pos       1                                                /* CMSDK_TIMER CTRL: SELEXTEN Position */
#define CMSDK_TIMER_CTRL_SELEXTEN_Msk      (0x01UL << CMSDK_TIMER_CTRL_SELEXTEN_Pos)         /* CMSDK_TIMER CTRL: SELEXTEN Mask */

#define CMSDK_TIMER_CTRL_EN_Pos             0                                                /* CMSDK_TIMER CTRL: EN Position */
#define CMSDK_TIMER_CTRL_EN_Msk            (0x01UL /*<< CMSDK_TIMER_CTRL_EN_Pos*/)           /* CMSDK_TIMER CTRL: EN Mask */

/* CMSDK_TIMER VAL Register Definitions */
#define CMSDK_TIMER_VAL_CURRENT_Pos         0                                                /* CMSDK_TIMER VALUE: CURRENT Position */
#define CMSDK_TIMER_VAL_CURRENT_Msk        (0xFFFFFFFFUL /*<< CMSDK_TIMER_VAL_CURRENT_Pos*/) /* CMSDK_TIMER VALUE: CURRENT Mask */

/* CMSDK_TIMER RELOAD Register Definitions */
#define CMSDK_TIMER_RELOAD_VAL_Pos          0                                                /* CMSDK_TIMER RELOAD: RELOAD Position */
#define CMSDK_TIMER_RELOAD_VAL_Msk         (0xFFFFFFFFUL /*<< CMSDK_TIMER_RELOAD_VAL_Pos*/)  /* CMSDK_TIMER RELOAD: RELOAD Mask */

/* CMSDK_TIMER INTSTATUS Register Definitions */
#define CMSDK_TIMER_INTSTATUS_Pos           0                                                /* CMSDK_TIMER INTSTATUS: INTSTATUSPosition */
#define CMSDK_TIMER_INTSTATUS_Msk          (0x01UL /*<< CMSDK_TIMER_INTSTATUS_Pos*/)         /* CMSDK_TIMER INTSTATUS: INTSTATUSMask */

/* CMSDK_TIMER INTCLEAR Register Definitions */
#define CMSDK_TIMER_INTCLEAR_Pos            0                                                /* CMSDK_TIMER INTCLEAR: INTCLEAR Position */
#define CMSDK_TIMER_INTCLEAR_Msk           (0x01UL /*<< CMSDK_TIMER_INTCLEAR_Pos*/)          /* CMSDK_TIMER INTCLEAR: INTCLEAR Mask */


/* CMSDK_TIMER PRESCALE Register Definitions */
#define CMSDK_TIMER_PRESCALE_PRESCALE_Pos          0                                                /* CMSDK_TIMER PRESCALE: PRESCALE Position */
#define CMSDK_TIMER_PRESCALE_PRESCALE_Msk         (0x07UL << CMSDK_TIMER_PRESCALE_PRESCALE_Pos)            /* CMSDK_TIMER PRESCALE: PRESCALE Mask */


/*------------- Timer (TIM) --------------------------------------------------*/
typedef struct
{
  __IOM uint32_t T1LOAD;                     /* Offset: 0x000 (R/W) Timer 1 Load */
  __IM  uint32_t T1VALUE;                    /* Offset: 0x004 (R/ ) Timer 1 Counter Current Value */
  __IOM uint32_t T1CTRL;                     /* Offset: 0x008 (R/W) Timer 1 Control */
  __OM  uint32_t T1INTCLR;                   /* Offset: 0x00C ( /W) Timer 1 Interrupt Clear */
  __IM  uint32_t T1RIS;                      /* Offset: 0x010 (R/ ) Timer 1 Raw Interrupt Status */
  __IM  uint32_t T1MIS;                      /* Offset: 0x014 (R/ ) Timer 1 Masked Interrupt Status */
  __IOM uint32_t T1BGLOAD;                   /* Offset: 0x018 (R/W) Background Load Register */
        uint32_t RESERVED0;
  __IOM uint32_t T2LOAD;                     /* Offset: 0x020 (R/W) Timer 2 Load */
  __IM  uint32_t T2VALUE;                    /* Offset: 0x024 (R/ ) Timer 2 Counter Current Value */
  __IOM uint32_t T2CTRL;                     /* Offset: 0x028 (R/W) Timer 2 Control */
  __OM  uint32_t T2INTCLR;                   /* Offset: 0x02C ( /W) Timer 2 Interrupt Clear */
  __IM  uint32_t T2RIS;                      /* Offset: 0x030 (R/ ) Timer 2 Raw Interrupt Status */
  __IM  uint32_t T2MIS;                      /* Offset: 0x034 (R/ ) Timer 2 Masked Interrupt Status */
  __IOM uint32_t T2BGLOAD;                   /* Offset: 0x038 (R/W) Background Load Register */
        uint32_t RESERVED1[945];
  __IOM uint32_t ITCR;                       /* Offset: 0xF00 (R/W) Integration Test Control Register */
  __OM  uint32_t ITOP;                       /* Offset: 0xF04 ( /W) Integration Test Output Set Register */
} CMSDK_DUALTIMER_BOTH_TypeDef;


typedef struct
{
  __IOM uint32_t LOAD;                       /* Offset: 0x000 (R/W) Timer Load */
  __IM  uint32_t VALUE;                      /* Offset: 0x000 (R/W) Timer Counter Current Value */
  __IOM uint32_t CTRL;                       /* Offset: 0x000 (R/W) Timer Control */
  __OM  uint32_t INTCLR;                     /* Offset: 0x000 (R/W) Timer Interrupt Clear */
  __IM  uint32_t RIS;                        /* Offset: 0x000 (R/W) Timer Raw Interrupt Status */
  __IM  uint32_t MIS;                        /* Offset: 0x000 (R/W) Timer Masked Interrupt Status */
  __IOM uint32_t BGLOAD;                     /* Offset: 0x000 (R/W) Background Load Register */
} CMSDK_DUALTIMER_SINGLE_TypeDef;

/* CMSDK_DUALTIMER_SINGLE LOAD Register Definitions */
#define CMSDK_DUALTIMER_LOAD_Pos             0                                               /* CMSDK_DUALTIMER LOAD: LOAD Position */
#define CMSDK_DUALTIMER_LOAD_Msk            (0xFFFFFFFFUL /*<< CMSDK_DUALTIMER_LOAD_Pos*/)   /* CMSDK_DUALTIMER LOAD: LOAD Mask */

/* CMSDK_DUALTIMER_SINGLE VALUE Register Definitions */
#define CMSDK_DUALTIMER_VALUE_Pos            0                                               /* CMSDK_DUALTIMER VALUE: VALUE Position */
#define CMSDK_DUALTIMER_VALUE_Msk           (0xFFFFFFFFUL /*<< CMSDK_DUALTIMER_VALUE_Pos*/)  /* CMSDK_DUALTIMER VALUE: VALUE Mask */

/* CMSDK_DUALTIMER_SINGLE CTRL Register Definitions */
#define CMSDK_DUALTIMER_CTRL_PRESCALE_Pos    8                                               /* CMSDK_DUALTIMER CTRL_PRESCALE: CTRL PRESCALE Position */
#define CMSDK_DUALTIMER_CTRL_PRESCALE_Msk   (0xFUL << CMSDK_DUALTIMER_CTRL_PRESCALE_Pos)     /* CMSDK_DUALTIMER CTRL_PRESCALE: CTRL PRESCALE Mask */

#define CMSDK_DUALTIMER_CTRL_EN_Pos          7                                               /* CMSDK_DUALTIMER CTRL_EN: CTRL Enable Position */
#define CMSDK_DUALTIMER_CTRL_EN_Msk         (0x1UL << CMSDK_DUALTIMER_CTRL_EN_Pos)           /* CMSDK_DUALTIMER CTRL_EN: CTRL Enable Mask */

#define CMSDK_DUALTIMER_CTRL_MODE_Pos        6                                               /* CMSDK_DUALTIMER CTRL_MODE: CTRL MODE Position */
#define CMSDK_DUALTIMER_CTRL_MODE_Msk       (0x1UL << CMSDK_DUALTIMER_CTRL_MODE_Pos)         /* CMSDK_DUALTIMER CTRL_MODE: CTRL MODE Mask */

#define CMSDK_DUALTIMER_CTRL_INTEN_Pos       5                                               /* CMSDK_DUALTIMER CTRL_INTEN: CTRL Int Enable Position */
#define CMSDK_DUALTIMER_CTRL_INTEN_Msk      (0x1UL << CMSDK_DUALTIMER_CTRL_INTEN_Pos)        /* CMSDK_DUALTIMER CTRL_INTEN: CTRL Int Enable Mask */

#define CMSDK_DUALTIMER_CTRL_SIZE_Pos        1                                               /* CMSDK_DUALTIMER CTRL_SIZE: CTRL SIZE Position */
#define CMSDK_DUALTIMER_CTRL_SIZE_Msk       (0x1UL << CMSDK_DUALTIMER_CTRL_SIZE_Pos)         /* CMSDK_DUALTIMER CTRL_SIZE: CTRL SIZE Mask */

#define CMSDK_DUALTIMER_CTRL_ONESHOOT_Pos    0                                               /* CMSDK_DUALTIMER CTRL_ONESHOOT: CTRL ONESHOOT Position */
#define CMSDK_DUALTIMER_CTRL_ONESHOOT_Msk   (0x1UL /*<< CMSDK_DUALTIMER_CTRL_ONESHOOT_Pos*/) /* CMSDK_DUALTIMER CTRL_ONESHOOT: CTRL ONESHOOT Mask */

/* CMSDK_DUALTIMER_SINGLE INTCLR Register Definitions */
#define CMSDK_DUALTIMER_INTCLR_Pos           0                                               /* CMSDK_DUALTIMER INTCLR: INT Clear Position */
#define CMSDK_DUALTIMER_INTCLR_Msk          (0x1UL /*<< CMSDK_DUALTIMER_INTCLR_Pos*/)        /* CMSDK_DUALTIMER INTCLR: INT Clear  Mask */

/* CMSDK_DUALTIMER_SINGLE RIS Register Definitions */
#define CMSDK_DUALTIMER_RIS_Pos              0                                               /* CMSDK_DUALTIMER RAWINTSTAT: Raw Int Status Position */
#define CMSDK_DUALTIMER_RIS_Msk             (0x1UL /*<< CMSDK_DUALTIMER_RAWINTSTAT_Pos*/)    /* CMSDK_DUALTIMER RAWINTSTAT: Raw Int Status Mask */

/* CMSDK_DUALTIMER_SINGLE MIS Register Definitions */
#define CMSDK_DUALTIMER_MIS_Pos              0                                               /* CMSDK_DUALTIMER MASKINTSTAT: Mask Int Status Position */
#define CMSDK_DUALTIMER_MIS_Msk             (0x1UL /*<< CMSDK_DUALTIMER_MASKINTSTAT_Pos*/)   /* CMSDK_DUALTIMER MASKINTSTAT: Mask Int Status Mask */

/* CMSDK_DUALTIMER_SINGLE BGLOAD Register Definitions */
#define CMSDK_DUALTIMER_BGLOAD_Pos           0                                               /* CMSDK_DUALTIMER BGLOAD: Background Load Position */
#define CMSDK_DUALTIMER_BGLOAD_Msk          (0xFFFFFFFFUL /*<< CMSDK_DUALTIMER_BGLOAD_Pos*/) /* CMSDK_DUALTIMER BGLOAD: Background Load Mask */


/*-------------------- General Purpose Input Output (GPIO) -------------------*/
typedef struct
{
  __IOM  uint32_t  DATA;                     /* Offset: 0x000 (R/W) DATA Register */
  __IOM  uint32_t  DATAOUT;                  /* Offset: 0x004 (R/W) Data Output Latch Register */
  __IO   uint32_t  INENSET;                  /* Offset: 0x008 (R/W) Input  Enable Set Register  (R/W) */
  __IO   uint32_t  INENCLR;                  /* Offset: 0x00C (R/W) Input  Enable clear Register  (R/W) */
  __IOM  uint32_t  OUTENSET;                 /* Offset: 0x010 (R/W) Output Enable Set Register */
  __IOM  uint32_t  OUTENCLR;                 /* Offset: 0x014 (R/W) Output Enable Clear Register */
  __IOM  uint32_t  ALTFUNCSET;               /* Offset: 0x018 (R/W) Alternate Function Set Register */
  __IOM  uint32_t  ALTFUNCCLR;               /* Offset: 0x01C (R/W) Alternate Function Clear Register */
  __IOM  uint32_t  INTENSET;                 /* Offset: 0x020 (R/W) Interrupt Enable Set Register */
  __IOM  uint32_t  INTENCLR;                 /* Offset: 0x024 (R/W) Interrupt Enable Clear Register */
  __IOM  uint32_t  INTTYPESET;               /* Offset: 0x028 (R/W) Interrupt Type Set Register */
  __IOM  uint32_t  INTTYPECLR;               /* Offset: 0x02C (R/W) Interrupt Type Clear Register */
  __IOM  uint32_t  INTPOLSET;                /* Offset: 0x030 (R/W) Interrupt Polarity Set Register */
  __IOM  uint32_t  INTPOLCLR;                /* Offset: 0x034 (R/W) Interrupt Polarity Clear Register */
  union {                                               
    __IM   uint32_t  INTSTATUS;              /* Offset: 0x038 (R/ ) Interrupt Status Register */
    __OM   uint32_t  INTCLEAR;               /* Offset: 0x038 ( /W) Interrupt Clear Register */
    };
         uint32_t  RESERVED0[8];             /* Offset:  ( /W) Interrupt Clear Register */
  __IO   uint32_t  PUENSET;                  /* Offset: 0x05C PU Enable Set Register  (R/W) */
  __IO   uint32_t  PUENCLR;                  /* Offset: 0x060 PU Enable clear Register  (R/W) */
  __IO   uint32_t  PDENSET;                  /* Offset: 0x064 PD Enable Set Register  (R/W) */
  __IO   uint32_t  PDENCLR;                  /* Offset: 0x068 PD Enable clear Register  (R/W) */
         uint32_t  RESERVED1[229];
  __IOM  uint32_t  LB_MASKED[256];            /* Offset: 0x400 - 0x7FC Lower byte Masked Access Register (R/W) */
  __IOM  uint32_t  UB_MASKED[256];            /* Offset: 0x800 - 0xBFC Upper byte Masked Access Register (R/W) */
         uint32_t  RESERVED2[244];
__IM   uint32_t PID4;                  /* Offset: 0xFD0 (read-only) PIDR4 Register    */
__IM   uint32_t PID5;                  /* Offset: 0xFE0 (read-only) PIDR0 Register    */
__IM   uint32_t PID6;                  /* Offset: 0xFE4 (read-only) PIDR1 Register    */
__IM   uint32_t PID7;                  /* Offset: 0xFE8 (read-only) PIDR2 Register    */
__IM   uint32_t PID0;                  /* Offset: 0xFEC (read-only) PIDR3 Register    */
__IM   uint32_t PID1;                  /* Offset: 0xFEC (read-only) PIDR3 Register    */
__IM   uint32_t PID2;                  /* Offset: 0xFEC (read-only) PIDR3 Register    */
__IM   uint32_t PID3;                  /* Offset: 0xFEC (read-only) PIDR3 Register    */
__IM   uint32_t CID0;                  /* Offset: 0xFF0 (read-only) CIDR0 Register    */
__IM   uint32_t CID1;                  /* Offset: 0xFF4 (read-only) CIDR1 Register    */
__IM   uint32_t CID2;                  /* Offset: 0xFF8 (read-only) CIDR2 Register    */
__IM   uint32_t CID3;                  /* Offset: 0xFFC (read-only) CIDR3 Register    */
} CMSDK_GPIO_TypeDef;

/* CMSDK_GPIO DATA Register Definitions */
#define CMSDK_GPIO_DATA_Pos            0                                                     /* CMSDK_GPIO DATA: DATA Position */
#define CMSDK_GPIO_DATA_Msk           (0xFFFFUL /*<< CMSDK_GPIO_DATA_Pos*/)                  /* CMSDK_GPIO DATA: DATA Mask */

/* CMSDK_GPIO DATAOUT Register Definitions */
#define CMSDK_GPIO_DATAOUT_Pos         0                                                     /* CMSDK_GPIO DATAOUT: DATAOUT Position */
#define CMSDK_GPIO_DATAOUT_Msk        (0xFFFFUL /*<< CMSDK_GPIO_DATAOUT_Pos*/)               /* CMSDK_GPIO DATAOUT: DATAOUT Mask */

/* CMSDK_GPIO PUENSET Register Definitions */
#define CMSDK_GPIO_PUENSET_Pos         0                                                     /* CMSDK_GPIO PUEN: PUEN Position */
#define CMSDK_GPIO_PUENSET_Msk        (0xFFFFUL /*<< CMSDK_GPIO_PUEN_Pos*/)                  /* CMSDK_GPIO PUEN: PUEN Mask */

/* CMSDK_GPIO PUENCLR Register Definitions */
#define CMSDK_GPIO_PUENCLR_Pos         0                                                     /* CMSDK_GPIO PUEN: PUEN Position */
#define CMSDK_GPIO_PUENCLR_Msk        (0xFFFFUL /*<< CMSDK_GPIO_PUEN_Pos*/)                   /* CMSDK_GPIO PUEN: PUEN Mask */

/* CMSDK_GPIO INENSET Register Definitions */
#define CMSDK_GPIO_INENSET_Pos         0                                                     /* CMSDK_GPIO INEN: INEN Position */
#define CMSDK_GPIO_INENSET_Msk        (0xFFFFUL /*<< CMSDK_GPIO_INEN_Pos*/)                  /* CMSDK_GPIO INEN: INEN Mask */

/* CMSDK_GPIO INENCLR Register Definitions */
#define CMSDK_GPIO_INENCLR_Pos         0                                                     /* CMSDK_GPIO INEN: INEN Position */
#define CMSDK_GPIO_INENCLR_Msk        (0xFFFFUL /*<< CMSDK_GPIO_INEN_Pos*/)                  /* CMSDK_GPIO INEN: INEN Mask */

/* CMSDK_GPIO OUTENSET Register Definitions */
#define CMSDK_GPIO_OUTENSET_Pos        0                                                     /* CMSDK_GPIO OUTEN: OUTEN Position */
#define CMSDK_GPIO_OUTENSET_Msk       (0xFFFFUL /*<< CMSDK_GPIO_OUTEN_Pos*/)                 /* CMSDK_GPIO OUTEN: OUTEN Mask */

/* CMSDK_GPIO OUTENCLR Register Definitions */
#define CMSDK_GPIO_OUTENCLR_Pos        0                                                     /* CMSDK_GPIO OUTEN: OUTEN Position */
#define CMSDK_GPIO_OUTENCLR_Msk       (0xFFFFUL /*<< CMSDK_GPIO_OUTEN_Pos*/)                 /* CMSDK_GPIO OUTEN: OUTEN Mask */

/* CMSDK_GPIO ALTFUNCSET Register Definitions */
#define CMSDK_GPIO_ALTFUNCSET_Pos      0                                                     /* CMSDK_GPIO ALTFUNC: ALTFUNC Position */
#define CMSDK_GPIO_ALTFUNCSET_Msk     (0xFFFFUL /*<< CMSDK_GPIO_ALTFUNC_Pos*/)               /* CMSDK_GPIO ALTFUNC: ALTFUNC Mask */

/* CMSDK_GPIO ALTFUNCCLR Register Definitions */
#define CMSDK_GPIO_ALTFUNCCLR_Pos      0                                                     /* CMSDK_GPIO ALTFUNC: ALTFUNC Position */
#define CMSDK_GPIO_ALTFUNCCLR_Msk     (0xFFFFUL /*<< CMSDK_GPIO_ALTFUNC_Pos*/)               /* CMSDK_GPIO ALTFUNC: ALTFUNC Mask */

/* CMSDK_GPIO INTENSET Register Definitions */
#define CMSDK_GPIO_INTENSET_Pos        0                                                     /* CMSDK_GPIO INTEN: INTEN Position */
#define CMSDK_GPIO_INTENSET_Msk       (0xFFFFUL /*<< CMSDK_GPIO_INTEN_Pos*/)                 /* CMSDK_GPIO INTEN: INTEN Mask */

/* CMSDK_GPIO INTENCLR Register Definitions */
#define CMSDK_GPIO_INTENCLR_Pos        0                                                     /* CMSDK_GPIO INTEN: INTEN Position */
#define CMSDK_GPIO_INTENCLR_Msk       (0xFFFFUL /*<< CMSDK_GPIO_INTEN_Pos*/)                 /* CMSDK_GPIO INTEN: INTEN Mask */

/* CMSDK_GPIO INTTYPESET Register Definitions */
#define CMSDK_GPIO_INTTYPESET_Pos      0                                                     /* CMSDK_GPIO INTTYPE: INTTYPE Position */
#define CMSDK_GPIO_INTTYPESET_Msk     (0xFFFFUL /*<< CMSDK_GPIO_INTTYPE_Pos*/)               /* CMSDK_GPIO INTTYPE: INTTYPE Mask */

/* CMSDK_GPIO INTTYPECLR Register Definitions */
#define CMSDK_GPIO_INTTYPECLR_Pos      0                                                     /* CMSDK_GPIO INTTYPE: INTTYPE Position */
#define CMSDK_GPIO_INTTYPECLR_Msk     (0xFFFFUL /*<< CMSDK_GPIO_INTTYPE_Pos*/)               /* CMSDK_GPIO INTTYPE: INTTYPE Mask */

/* CMSDK_GPIO INTPOLSET Register Definitions */
#define CMSDK_GPIO_INTPOLSET_Pos       0                                                     /* CMSDK_GPIO INTPOL: INTPOL Position */
#define CMSDK_GPIO_INTPOLSET_Msk      (0xFFFFUL /*<< CMSDK_GPIO_INTPOL_Pos*/)                /* CMSDK_GPIO INTPOL: INTPOL Mask */

/* CMSDK_GPIO INTPOLCLR Register Definitions */
#define CMSDK_GPIO_INTPOLCLR_Pos       0                                                     /* CMSDK_GPIO INTPOL: INTPOL Position */
#define CMSDK_GPIO_INTPOLCLR_Msk      (0xFFFFUL /*<< CMSDK_GPIO_INTPOL_Pos*/)                /* CMSDK_GPIO INTPOL: INTPOL Mask */

/* CMSDK_GPIO INTCLEAR Register Definitions */
#define CMSDK_GPIO_INTSTATUS_Pos       0                                                     /* CMSDK_GPIO INTSTATUS: INTSTATUS Position */
#define CMSDK_GPIO_INTCLEAR_Msk       (0xFFFFUL /*<< CMSDK_GPIO_INTSTATUS_Pos*/)               /* CMSDK_GPIO INTSTATUS: INTSTATUS Mask */

/* CMSDK_GPIO INTCLEAR Register Definitions */
#define CMSDK_GPIO_INTCLEAR_Pos        0                                                     /* CMSDK_GPIO INTCLEAR: INTCLEAR Position */
#define CMSDK_GPIO_INTCLEAR_Msk       (0xFFFFUL /*<< CMSDK_GPIO_INTCLEAR_Pos*/)                /* CMSDK_GPIO INTCLEAR: INTCLEAR Mask */

/* CMSDK_GPIO MASKLOWBYTE Register Definitions */
#define CMSDK_GPIO_MASKLOWBYTE_Pos     0                                                     /* CMSDK_GPIO MASKLOWBYTE: MASKLOWBYTE Position */
#define CMSDK_GPIO_MASKLOWBYTE_Msk    (0x00FFUL /*<< CMSDK_GPIO_MASKLOWBYTE_Pos*/)           /* CMSDK_GPIO MASKLOWBYTE: MASKLOWBYTE Mask */

/* CMSDK_GPIO MASKHIGHBYTE Register Definitions */
#define CMSDK_GPIO_MASKHIGHBYTE_Pos    0                                                     /* CMSDK_GPIO MASKHIGHBYTE: MASKHIGHBYTE Position */
#define CMSDK_GPIO_MASKHIGHBYTE_Msk   (0xFF00UL /*<< CMSDK_GPIO_MASKHIGHBYTE_Pos*/)          /* CMSDK_GPIO MASKHIGHBYTE: MASKHIGHBYTE Mask */


/*---------------- SYS_CTRL_REG_SSE200 ----------------*/
typedef struct
{
__IM   uint32_t SECDBGSTAT;                  /* Offset: 0x0 (read-only) SECDBGSTAT Register    */
__OM   uint32_t SECDBGSET;                  /* Offset: 0x4 (write-only) SECDBGSET Register    */
__OM   uint32_t SECDBGCLR;                  /* Offset: 0x8 (write-only) SECDBGCLR Register    */
__IOM  uint32_t SCSECCTRL;                  /* Offset: 0xC (read-write) SCSECCTRL Register    */
__IOM  uint32_t FCLK_DIV;                  /* Offset: 0x10 (read-write) FCLK_DIV Register    */
__IOM  uint32_t SYSCLK_DIV;                  /* Offset: 0x14 (read-write) SYSCLK_DIV Register    */
__IOM  uint32_t CLOCK_FORCE;                  /* Offset: 0x18 (read-write) CLOCK_FORCE Register    */
       uint32_t RESERVED0[57];
__IOM  uint32_t RESET_SYNDROME;                  /* Offset: 0x100 (read-write) RESET_SYNDROME Register    */
__IOM  uint32_t RESET_MASK;                  /* Offset: 0x104 (read-write) RESET_MASK Register    */
__OM   uint32_t SWRESET;                  /* Offset: 0x108 (write-only) SWRESET Register    */
__IOM  uint32_t GRETREG;                  /* Offset: 0x10C (read-write) GRETREG Register    */
__IOM  uint32_t INITSVTOR0;                  /* Offset: 0x110 (read-write) INITSVTOR0 Register    */
__IOM  uint32_t INITSVTOR1;                  /* Offset: 0x114 (read-write) INITSVTOR1 Register    */
__IOM  uint32_t CPUWAIT;                  /* Offset: 0x118 (read-write) CPUWAIT Register    */
__IOM  uint32_t NMI_ENABLE;                  /* Offset: 0x11C (read-write) NMI_ENABLE Register    */
__IOM  uint32_t WICCTRL;                  /* Offset: 0x120 (read-write) WICCTRL Register    */
__IOM  uint32_t EWCTRL;                  /* Offset: 0x124 (read-write) EWCTRL Register    */
       uint32_t RESERVED1[54];
__IOM  uint32_t PDCM_PD_SYS_SENSE;                  /* Offset: 0x200 (read-write) PDCM_PD_SYS_SENSE Register    */
       uint32_t RESERVED4[2];
__IOM  uint32_t PDCM_PD_SRAM0_SENSE;                  /* Offset: 0x20C (read-write) PDCM_PD_SRAM0_SENSE Register    */
__IOM  uint32_t PDCM_PD_SRAM1_SENSE;                  /* Offset: 0x210 (read-write) PDCM_PD_SRAM1_SENSE Register    */
__IOM  uint32_t PDCM_PD_SRAM2_SENSE;                  /* Offset: 0x214 (read-write) PDCM_PD_SRAM2_SENSE Register    */
__IOM  uint32_t PDCM_PD_SRAM3_SENSE;                  /* Offset: 0x218 (read-write) PDCM_PD_SRAM3_SENSE Register    */
       uint32_t RESERVED2[877];
__IM   uint32_t PIDR4;                  /* Offset: 0xFD0 (read-only) PIDR4 Register    */
       uint32_t RESERVED3[3];
__IM   uint32_t PIDR0;                  /* Offset: 0xFE0 (read-only) PIDR0 Register    */
__IM   uint32_t PIDR1;                  /* Offset: 0xFE4 (read-only) PIDR1 Register    */
__IM   uint32_t PIDR2;                  /* Offset: 0xFE8 (read-only) PIDR2 Register    */
__IM   uint32_t PIDR3;                  /* Offset: 0xFEC (read-only) PIDR3 Register    */
__IM   uint32_t CIDR0;                  /* Offset: 0xFF0 (read-only) CIDR0 Register    */
__IM   uint32_t CIDR1;                  /* Offset: 0xFF4 (read-only) CIDR1 Register    */
__IM   uint32_t CIDR2;                  /* Offset: 0xFF8 (read-only) CIDR2 Register    */
__IM   uint32_t CIDR3;                  /* Offset: 0xFFC (read-only) CIDR3 Register    */
}SYS_CTRL_REG_SSE200_TypeDef;

/* SYS_CTRL_REG_SSE200 SECDBGSTAT Register Definitions */
#define SYS_CTRL_REG_SSE200_SECDBGSTAT_LLCDBGEN_SEL_STATUS_Pos                9                                                          /* SYS_CTRL_REG_SSE200 SECDBGSTAT: LLCDBGEN_SEL_STATUS Positions */
#define SYS_CTRL_REG_SSE200_SECDBGSTAT_LLCDBGEN_SEL_STATUS_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_SECDBGSTAT_LLCDBGEN_SEL_STATUS_Pos)                 /* SYS_CTRL_REG_SSE200 SECDBGSTAT: LLCDBGEN_SEL_STATUS Mask */

#define SYS_CTRL_REG_SSE200_SECDBGSTAT_LLCDBGEN_STATUS_Pos                8                                                          /* SYS_CTRL_REG_SSE200 SECDBGSTAT: LLCDBGEN_STATUS Positions */
#define SYS_CTRL_REG_SSE200_SECDBGSTAT_LLCDBGEN_STATUS_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_SECDBGSTAT_LLCDBGEN_STATUS_Pos)                 /* SYS_CTRL_REG_SSE200 SECDBGSTAT: LLCDBGEN_STATUS Mask */

#define SYS_CTRL_REG_SSE200_SECDBGSTAT_SPNIDEN_SEL_STATUS_Pos                7                                                          /* SYS_CTRL_REG_SSE200 SECDBGSTAT: SPNIDEN_SEL_STATUS Positions */
#define SYS_CTRL_REG_SSE200_SECDBGSTAT_SPNIDEN_SEL_STATUS_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_SECDBGSTAT_SPNIDEN_SEL_STATUS_Pos)                 /* SYS_CTRL_REG_SSE200 SECDBGSTAT: SPNIDEN_SEL_STATUS Mask */

#define SYS_CTRL_REG_SSE200_SECDBGSTAT_SPNIDEN_STATUS_Pos                6                                                          /* SYS_CTRL_REG_SSE200 SECDBGSTAT: SPNIDEN_STATUS Positions */
#define SYS_CTRL_REG_SSE200_SECDBGSTAT_SPNIDEN_STATUS_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_SECDBGSTAT_SPNIDEN_STATUS_Pos)                 /* SYS_CTRL_REG_SSE200 SECDBGSTAT: SPNIDEN_STATUS Mask */

#define SYS_CTRL_REG_SSE200_SECDBGSTAT_SPIDEN_SEL_STATUS_Pos                5                                                          /* SYS_CTRL_REG_SSE200 SECDBGSTAT: SPIDEN_SEL_STATUS Positions */
#define SYS_CTRL_REG_SSE200_SECDBGSTAT_SPIDEN_SEL_STATUS_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_SECDBGSTAT_SPIDEN_SEL_STATUS_Pos)                 /* SYS_CTRL_REG_SSE200 SECDBGSTAT: SPIDEN_SEL_STATUS Mask */

#define SYS_CTRL_REG_SSE200_SECDBGSTAT_SPIDEN_STATUS_Pos                4                                                          /* SYS_CTRL_REG_SSE200 SECDBGSTAT: SPIDEN_STATUS Positions */
#define SYS_CTRL_REG_SSE200_SECDBGSTAT_SPIDEN_STATUS_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_SECDBGSTAT_SPIDEN_STATUS_Pos)                 /* SYS_CTRL_REG_SSE200 SECDBGSTAT: SPIDEN_STATUS Mask */

#define SYS_CTRL_REG_SSE200_SECDBGSTAT_NIDEN_SEL_STATUS_Pos                3                                                          /* SYS_CTRL_REG_SSE200 SECDBGSTAT: NIDEN_SEL_STATUS Positions */
#define SYS_CTRL_REG_SSE200_SECDBGSTAT_NIDEN_SEL_STATUS_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_SECDBGSTAT_NIDEN_SEL_STATUS_Pos)                 /* SYS_CTRL_REG_SSE200 SECDBGSTAT: NIDEN_SEL_STATUS Mask */

#define SYS_CTRL_REG_SSE200_SECDBGSTAT_NIDEN_STATUS_Pos                2                                                          /* SYS_CTRL_REG_SSE200 SECDBGSTAT: NIDEN_STATUS Positions */
#define SYS_CTRL_REG_SSE200_SECDBGSTAT_NIDEN_STATUS_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_SECDBGSTAT_NIDEN_STATUS_Pos)                 /* SYS_CTRL_REG_SSE200 SECDBGSTAT: NIDEN_STATUS Mask */

#define SYS_CTRL_REG_SSE200_SECDBGSTAT_DBGEN_SEL_STATUS_Pos                1                                                          /* SYS_CTRL_REG_SSE200 SECDBGSTAT: DBGEN_SEL_STATUS Positions */
#define SYS_CTRL_REG_SSE200_SECDBGSTAT_DBGEN_SEL_STATUS_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_SECDBGSTAT_DBGEN_SEL_STATUS_Pos)                 /* SYS_CTRL_REG_SSE200 SECDBGSTAT: DBGEN_SEL_STATUS Mask */

#define SYS_CTRL_REG_SSE200_SECDBGSTAT_DBGEN_STATUS_Pos                0                                                          /* SYS_CTRL_REG_SSE200 SECDBGSTAT: DBGEN_STATUS Positions */
#define SYS_CTRL_REG_SSE200_SECDBGSTAT_DBGEN_STATUS_Msk                (0x1UL  /*<< SYS_CTRL_REG_SSE200_SECDBGSTAT_DBGEN_STATUS_Pos*/)                 /* SYS_CTRL_REG_SSE200 SECDBGSTAT: DBGEN_STATUS Mask */

/* SYS_CTRL_REG_SSE200 SECDBGSET Register Definitions */
#define SYS_CTRL_REG_SSE200_SECDBGSET_LLCDBGEN_SEL_SET_Pos                9                                                          /* SYS_CTRL_REG_SSE200 SECDBGSET: LLCDBGEN_SEL_SET Positions */
#define SYS_CTRL_REG_SSE200_SECDBGSET_LLCDBGEN_SEL_SET_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_SECDBGSET_LLCDBGEN_SEL_SET_Pos)                 /* SYS_CTRL_REG_SSE200 SECDBGSET: LLCDBGEN_SEL_SET Mask */

#define SYS_CTRL_REG_SSE200_SECDBGSET_LLCDBGEN_SET_Pos                8                                                          /* SYS_CTRL_REG_SSE200 SECDBGSET: LLCDBGEN_SET Positions */
#define SYS_CTRL_REG_SSE200_SECDBGSET_LLCDBGEN_SET_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_SECDBGSET_LLCDBGEN_SET_Pos)                 /* SYS_CTRL_REG_SSE200 SECDBGSET: LLCDBGEN_SET Mask */

#define SYS_CTRL_REG_SSE200_SECDBGSET_SPNIDEN_SEL_SET_Pos                7                                                          /* SYS_CTRL_REG_SSE200 SECDBGSET: SPNIDEN_SEL_SET Positions */
#define SYS_CTRL_REG_SSE200_SECDBGSET_SPNIDEN_SEL_SET_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_SECDBGSET_SPNIDEN_SEL_SET_Pos)                 /* SYS_CTRL_REG_SSE200 SECDBGSET: SPNIDEN_SEL_SET Mask */

#define SYS_CTRL_REG_SSE200_SECDBGSET_SPNIDEN_SET_Pos                6                                                          /* SYS_CTRL_REG_SSE200 SECDBGSET: SPNIDEN_SET Positions */
#define SYS_CTRL_REG_SSE200_SECDBGSET_SPNIDEN_SET_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_SECDBGSET_SPNIDEN_SET_Pos)                 /* SYS_CTRL_REG_SSE200 SECDBGSET: SPNIDEN_SET Mask */

#define SYS_CTRL_REG_SSE200_SECDBGSET_SPIDEN_SEL_SET_Pos                5                                                          /* SYS_CTRL_REG_SSE200 SECDBGSET: SPIDEN_SEL_SET Positions */
#define SYS_CTRL_REG_SSE200_SECDBGSET_SPIDEN_SEL_SET_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_SECDBGSET_SPIDEN_SEL_SET_Pos)                 /* SYS_CTRL_REG_SSE200 SECDBGSET: SPIDEN_SEL_SET Mask */

#define SYS_CTRL_REG_SSE200_SECDBGSET_SPIDEN_SET_Pos                4                                                          /* SYS_CTRL_REG_SSE200 SECDBGSET: SPIDEN_SET Positions */
#define SYS_CTRL_REG_SSE200_SECDBGSET_SPIDEN_SET_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_SECDBGSET_SPIDEN_SET_Pos)                 /* SYS_CTRL_REG_SSE200 SECDBGSET: SPIDEN_SET Mask */

#define SYS_CTRL_REG_SSE200_SECDBGSET_NIDEN_SEL_SET_Pos                3                                                          /* SYS_CTRL_REG_SSE200 SECDBGSET: NIDEN_SEL_SET Positions */
#define SYS_CTRL_REG_SSE200_SECDBGSET_NIDEN_SEL_SET_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_SECDBGSET_NIDEN_SEL_SET_Pos)                 /* SYS_CTRL_REG_SSE200 SECDBGSET: NIDEN_SEL_SET Mask */

#define SYS_CTRL_REG_SSE200_SECDBGSET_NIDEN_SET_Pos                2                                                          /* SYS_CTRL_REG_SSE200 SECDBGSET: NIDEN_SET Positions */
#define SYS_CTRL_REG_SSE200_SECDBGSET_NIDEN_SET_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_SECDBGSET_NIDEN_SET_Pos)                 /* SYS_CTRL_REG_SSE200 SECDBGSET: NIDEN_SET Mask */

#define SYS_CTRL_REG_SSE200_SECDBGSET_DBGEN_SEL_SET_Pos                1                                                          /* SYS_CTRL_REG_SSE200 SECDBGSET: DBGEN_SEL_SET Positions */
#define SYS_CTRL_REG_SSE200_SECDBGSET_DBGEN_SEL_SET_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_SECDBGSET_DBGEN_SEL_SET_Pos)                 /* SYS_CTRL_REG_SSE200 SECDBGSET: DBGEN_SEL_SET Mask */

#define SYS_CTRL_REG_SSE200_SECDBGSET_DBGEN_SET_Pos                0                                                          /* SYS_CTRL_REG_SSE200 SECDBGSET: DBGEN_SET Positions */
#define SYS_CTRL_REG_SSE200_SECDBGSET_DBGEN_SET_Msk                (0x1UL  /*<< SYS_CTRL_REG_SSE200_SECDBGSET_DBGEN_SET_Pos*/)                 /* SYS_CTRL_REG_SSE200 SECDBGSET: DBGEN_SET Mask */

/* SYS_CTRL_REG_SSE200 SECDBGCLR Register Definitions */
#define SYS_CTRL_REG_SSE200_SECDBGCLR_LLCDBGEN_SEL_CLR_Pos                9                                                          /* SYS_CTRL_REG_SSE200 SECDBGCLR: LLCDBGEN_SEL_CLR Positions */
#define SYS_CTRL_REG_SSE200_SECDBGCLR_LLCDBGEN_SEL_CLR_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_SECDBGCLR_LLCDBGEN_SEL_CLR_Pos)                 /* SYS_CTRL_REG_SSE200 SECDBGCLR: LLCDBGEN_SEL_CLR Mask */

#define SYS_CTRL_REG_SSE200_SECDBGCLR_LLCDBGEN_CLR_Pos                8                                                          /* SYS_CTRL_REG_SSE200 SECDBGCLR: LLCDBGEN_CLR Positions */
#define SYS_CTRL_REG_SSE200_SECDBGCLR_LLCDBGEN_CLR_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_SECDBGCLR_LLCDBGEN_CLR_Pos)                 /* SYS_CTRL_REG_SSE200 SECDBGCLR: LLCDBGEN_CLR Mask */

#define SYS_CTRL_REG_SSE200_SECDBGCLR_SPNIDEN_SEL_CLR_Pos                7                                                          /* SYS_CTRL_REG_SSE200 SECDBGCLR: SPNIDEN_SEL_CLR Positions */
#define SYS_CTRL_REG_SSE200_SECDBGCLR_SPNIDEN_SEL_CLR_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_SECDBGCLR_SPNIDEN_SEL_CLR_Pos)                 /* SYS_CTRL_REG_SSE200 SECDBGCLR: SPNIDEN_SEL_CLR Mask */

#define SYS_CTRL_REG_SSE200_SECDBGCLR_SPNIDEN_CLR_Pos                6                                                          /* SYS_CTRL_REG_SSE200 SECDBGCLR: SPNIDEN_CLR Positions */
#define SYS_CTRL_REG_SSE200_SECDBGCLR_SPNIDEN_CLR_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_SECDBGCLR_SPNIDEN_CLR_Pos)                 /* SYS_CTRL_REG_SSE200 SECDBGCLR: SPNIDEN_CLR Mask */

#define SYS_CTRL_REG_SSE200_SECDBGCLR_SPIDEN_SEL_CLR_Pos                5                                                          /* SYS_CTRL_REG_SSE200 SECDBGCLR: SPIDEN_SEL_CLR Positions */
#define SYS_CTRL_REG_SSE200_SECDBGCLR_SPIDEN_SEL_CLR_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_SECDBGCLR_SPIDEN_SEL_CLR_Pos)                 /* SYS_CTRL_REG_SSE200 SECDBGCLR: SPIDEN_SEL_CLR Mask */

#define SYS_CTRL_REG_SSE200_SECDBGCLR_SPIDEN_CLR_Pos                4                                                          /* SYS_CTRL_REG_SSE200 SECDBGCLR: SPIDEN_CLR Positions */
#define SYS_CTRL_REG_SSE200_SECDBGCLR_SPIDEN_CLR_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_SECDBGCLR_SPIDEN_CLR_Pos)                 /* SYS_CTRL_REG_SSE200 SECDBGCLR: SPIDEN_CLR Mask */

#define SYS_CTRL_REG_SSE200_SECDBGCLR_NIDEN_SEL_CLR_Pos                3                                                          /* SYS_CTRL_REG_SSE200 SECDBGCLR: NIDEN_SEL_CLR Positions */
#define SYS_CTRL_REG_SSE200_SECDBGCLR_NIDEN_SEL_CLR_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_SECDBGCLR_NIDEN_SEL_CLR_Pos)                 /* SYS_CTRL_REG_SSE200 SECDBGCLR: NIDEN_SEL_CLR Mask */

#define SYS_CTRL_REG_SSE200_SECDBGCLR_NIDEN_CLR_Pos                2                                                          /* SYS_CTRL_REG_SSE200 SECDBGCLR: NIDEN_CLR Positions */
#define SYS_CTRL_REG_SSE200_SECDBGCLR_NIDEN_CLR_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_SECDBGCLR_NIDEN_CLR_Pos)                 /* SYS_CTRL_REG_SSE200 SECDBGCLR: NIDEN_CLR Mask */

#define SYS_CTRL_REG_SSE200_SECDBGCLR_DBGEN_SEL_CLR_Pos                1                                                          /* SYS_CTRL_REG_SSE200 SECDBGCLR: DBGEN_SEL_CLR Positions */
#define SYS_CTRL_REG_SSE200_SECDBGCLR_DBGEN_SEL_CLR_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_SECDBGCLR_DBGEN_SEL_CLR_Pos)                 /* SYS_CTRL_REG_SSE200 SECDBGCLR: DBGEN_SEL_CLR Mask */

#define SYS_CTRL_REG_SSE200_SECDBGCLR_DBGEN_CLR_Pos                0                                                          /* SYS_CTRL_REG_SSE200 SECDBGCLR: DBGEN_CLR Positions */
#define SYS_CTRL_REG_SSE200_SECDBGCLR_DBGEN_CLR_Msk                (0x1UL  /*<< SYS_CTRL_REG_SSE200_SECDBGCLR_DBGEN_CLR_Pos*/)                 /* SYS_CTRL_REG_SSE200 SECDBGCLR: DBGEN_CLR Mask */

/* SYS_CTRL_REG_SSE200 SCSECCTRL Register Definitions */
#define SYS_CTRL_REG_SSE200_SCSECCTRL_CERTREADENABLED_Pos                17                                                          /* SYS_CTRL_REG_SSE200 SCSECCTRL: CERTREADENABLED Positions */
#define SYS_CTRL_REG_SSE200_SCSECCTRL_CERTREADENABLED_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_SCSECCTRL_CERTREADENABLED_Pos)                 /* SYS_CTRL_REG_SSE200 SCSECCTRL: CERTREADENABLED Mask */

#define SYS_CTRL_REG_SSE200_SCSECCTRL_CERTDISABLED_Pos                16                                                          /* SYS_CTRL_REG_SSE200 SCSECCTRL: CERTDISABLED Positions */
#define SYS_CTRL_REG_SSE200_SCSECCTRL_CERTDISABLED_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_SCSECCTRL_CERTDISABLED_Pos)                 /* SYS_CTRL_REG_SSE200 SCSECCTRL: CERTDISABLED Mask */

#define SYS_CTRL_REG_SSE200_SCSECCTRL_SCSECCFGLOCK_Pos                2                                                          /* SYS_CTRL_REG_SSE200 SCSECCTRL: SCSECCFGLOCK Positions */
#define SYS_CTRL_REG_SSE200_SCSECCTRL_SCSECCFGLOCK_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_SCSECCTRL_SCSECCFGLOCK_Pos)                 /* SYS_CTRL_REG_SSE200 SCSECCTRL: SCSECCFGLOCK Mask */

#define SYS_CTRL_REG_SSE200_SCSECCTRL_CERTREADEN_Pos                1                                                          /* SYS_CTRL_REG_SSE200 SCSECCTRL: CERTREADEN Positions */
#define SYS_CTRL_REG_SSE200_SCSECCTRL_CERTREADEN_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_SCSECCTRL_CERTREADEN_Pos)                 /* SYS_CTRL_REG_SSE200 SCSECCTRL: CERTREADEN Mask */

#define SYS_CTRL_REG_SSE200_SCSECCTRL_CERTDISABLE_Pos                0                                                          /* SYS_CTRL_REG_SSE200 SCSECCTRL: CERTDISABLE Positions */
#define SYS_CTRL_REG_SSE200_SCSECCTRL_CERTDISABLE_Msk                (0x1UL  /*<< SYS_CTRL_REG_SSE200_SCSECCTRL_CERTDISABLE_Pos*/)                 /* SYS_CTRL_REG_SSE200 SCSECCTRL: CERTDISABLE Mask */

/* SYS_CTRL_REG_SSE200 FCLK_DIV Register Definitions */
#define SYS_CTRL_REG_SSE200_FCLK_DIV_FCLKDIV_CUR_Pos                16                                                          /* SYS_CTRL_REG_SSE200 FCLK_DIV: FCLKDIV_CUR Positions */
#define SYS_CTRL_REG_SSE200_FCLK_DIV_FCLKDIV_CUR_Msk                (0x1FUL  << SYS_CTRL_REG_SSE200_FCLK_DIV_FCLKDIV_CUR_Pos)                 /* SYS_CTRL_REG_SSE200 FCLK_DIV: FCLKDIV_CUR Mask */

#define SYS_CTRL_REG_SSE200_FCLK_DIV_FCLKDIV_Pos                0                                                          /* SYS_CTRL_REG_SSE200 FCLK_DIV: FCLKDIV Positions */
#define SYS_CTRL_REG_SSE200_FCLK_DIV_FCLKDIV_Msk                (0x1FUL  /*<< SYS_CTRL_REG_SSE200_FCLK_DIV_FCLKDIV_Pos*/)                 /* SYS_CTRL_REG_SSE200 FCLK_DIV: FCLKDIV Mask */

/* SYS_CTRL_REG_SSE200 SYSCLK_DIV Register Definitions */
#define SYS_CTRL_REG_SSE200_SYSCLK_DIV_SYSCLKDIV_CUR_Pos                16                                                          /* SYS_CTRL_REG_SSE200 SYSCLK_DIV: SYSCLKDIV_CUR Positions */
#define SYS_CTRL_REG_SSE200_SYSCLK_DIV_SYSCLKDIV_CUR_Msk                (0x1FUL  << SYS_CTRL_REG_SSE200_SYSCLK_DIV_SYSCLKDIV_CUR_Pos)                 /* SYS_CTRL_REG_SSE200 SYSCLK_DIV: SYSCLKDIV_CUR Mask */

#define SYS_CTRL_REG_SSE200_SYSCLK_DIV_SYSCLKDIV_Pos                0                                                          /* SYS_CTRL_REG_SSE200 SYSCLK_DIV: SYSCLKDIV Positions */
#define SYS_CTRL_REG_SSE200_SYSCLK_DIV_SYSCLKDIV_Msk                (0x1FUL  /*<< SYS_CTRL_REG_SSE200_SYSCLK_DIV_SYSCLKDIV_Pos*/)                 /* SYS_CTRL_REG_SSE200 SYSCLK_DIV: SYSCLKDIV Mask */

/* SYS_CTRL_REG_SSE200 CLOCK_FORCE Register Definitions */
#define SYS_CTRL_REG_SSE200_CLOCK_FORCE_FCLKHINTGATE_ENABLE_Pos                8                                                          /* SYS_CTRL_REG_SSE200 CLOCK_FORCE: FCLKHINTGATE_ENABLE Positions */
#define SYS_CTRL_REG_SSE200_CLOCK_FORCE_FCLKHINTGATE_ENABLE_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_CLOCK_FORCE_FCLKHINTGATE_ENABLE_Pos)                 /* SYS_CTRL_REG_SSE200 CLOCK_FORCE: FCLKHINTGATE_ENABLE Mask */

#define SYS_CTRL_REG_SSE200_CLOCK_FORCE_CRYPTOSYSCLK_FORCE_Pos                7                                                          /* SYS_CTRL_REG_SSE200 CLOCK_FORCE: CRYPTOSYSCLK_FORCE Positions */
#define SYS_CTRL_REG_SSE200_CLOCK_FORCE_CRYPTOSYSCLK_FORCE_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_CLOCK_FORCE_CRYPTOSYSCLK_FORCE_Pos)                 /* SYS_CTRL_REG_SSE200 CLOCK_FORCE: CRYPTOSYSCLK_FORCE Mask */

#define SYS_CTRL_REG_SSE200_CLOCK_FORCE_CPUFCLK_FORCE_Pos                6                                                          /* SYS_CTRL_REG_SSE200 CLOCK_FORCE: CPUFCLK_FORCE Positions */
#define SYS_CTRL_REG_SSE200_CLOCK_FORCE_CPUFCLK_FORCE_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_CLOCK_FORCE_CPUFCLK_FORCE_Pos)                 /* SYS_CTRL_REG_SSE200 CLOCK_FORCE: CPUFCLK_FORCE Mask */

#define SYS_CTRL_REG_SSE200_CLOCK_FORCE_CPUSYSCLK_FORCE_Pos                5                                                          /* SYS_CTRL_REG_SSE200 CLOCK_FORCE: CPUSYSCLK_FORCE Positions */
#define SYS_CTRL_REG_SSE200_CLOCK_FORCE_CPUSYSCLK_FORCE_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_CLOCK_FORCE_CPUSYSCLK_FORCE_Pos)                 /* SYS_CTRL_REG_SSE200 CLOCK_FORCE: CPUSYSCLK_FORCE Mask */

#define SYS_CTRL_REG_SSE200_CLOCK_FORCE_SRAMFCLK_FORCE_Pos                4                                                          /* SYS_CTRL_REG_SSE200 CLOCK_FORCE: SRAMFCLK_FORCE Positions */
#define SYS_CTRL_REG_SSE200_CLOCK_FORCE_SRAMFCLK_FORCE_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_CLOCK_FORCE_SRAMFCLK_FORCE_Pos)                 /* SYS_CTRL_REG_SSE200 CLOCK_FORCE: SRAMFCLK_FORCE Mask */

#define SYS_CTRL_REG_SSE200_CLOCK_FORCE_SRAMSYSCLK_FORCE_Pos                3                                                          /* SYS_CTRL_REG_SSE200 CLOCK_FORCE: SRAMSYSCLK_FORCE Positions */
#define SYS_CTRL_REG_SSE200_CLOCK_FORCE_SRAMSYSCLK_FORCE_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_CLOCK_FORCE_SRAMSYSCLK_FORCE_Pos)                 /* SYS_CTRL_REG_SSE200 CLOCK_FORCE: SRAMSYSCLK_FORCE Mask */

#define SYS_CTRL_REG_SSE200_CLOCK_FORCE_SYSFCLK_FORCE_Pos                2                                                          /* SYS_CTRL_REG_SSE200 CLOCK_FORCE: SYSFCLK_FORCE Positions */
#define SYS_CTRL_REG_SSE200_CLOCK_FORCE_SYSFCLK_FORCE_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_CLOCK_FORCE_SYSFCLK_FORCE_Pos)                 /* SYS_CTRL_REG_SSE200 CLOCK_FORCE: SYSFCLK_FORCE Mask */

#define SYS_CTRL_REG_SSE200_CLOCK_FORCE_SYSSYSCLK_FORCE_Pos                1                                                          /* SYS_CTRL_REG_SSE200 CLOCK_FORCE: SYSSYSCLK_FORCE Positions */
#define SYS_CTRL_REG_SSE200_CLOCK_FORCE_SYSSYSCLK_FORCE_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_CLOCK_FORCE_SYSSYSCLK_FORCE_Pos)                 /* SYS_CTRL_REG_SSE200 CLOCK_FORCE: SYSSYSCLK_FORCE Mask */

#define SYS_CTRL_REG_SSE200_CLOCK_FORCE_MAINCLK_FORCE_Pos                0                                                          /* SYS_CTRL_REG_SSE200 CLOCK_FORCE: MAINCLK_FORCE Positions */
#define SYS_CTRL_REG_SSE200_CLOCK_FORCE_MAINCLK_FORCE_Msk                (0x1UL  /*<< SYS_CTRL_REG_SSE200_CLOCK_FORCE_MAINCLK_FORCE_Pos*/)                 /* SYS_CTRL_REG_SSE200 CLOCK_FORCE: MAINCLK_FORCE Mask */

/* SYS_CTRL_REG_SSE200 RESET_SYNDROME Register Definitions */
#define SYS_CTRL_REG_SSE200_RESET_SYNDROME_SWRESETREQ_Pos                9                                                          /* SYS_CTRL_REG_SSE200 RESET_SYNDROME: SWRESETREQ Positions */
#define SYS_CTRL_REG_SSE200_RESET_SYNDROME_SWRESETREQ_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_RESET_SYNDROME_SWRESETREQ_Pos)                 /* SYS_CTRL_REG_SSE200 RESET_SYNDROME: SWRESETREQ Mask */

#define SYS_CTRL_REG_SSE200_RESET_SYNDROME_RESETREQ_Pos                8                                                          /* SYS_CTRL_REG_SSE200 RESET_SYNDROME: RESETREQ Positions */
#define SYS_CTRL_REG_SSE200_RESET_SYNDROME_RESETREQ_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_RESET_SYNDROME_RESETREQ_Pos)                 /* SYS_CTRL_REG_SSE200 RESET_SYNDROME: RESETREQ Mask */

#define SYS_CTRL_REG_SSE200_RESET_SYNDROME_LOCKUP1_Pos                7                                                          /* SYS_CTRL_REG_SSE200 RESET_SYNDROME: LOCKUP1 Positions */
#define SYS_CTRL_REG_SSE200_RESET_SYNDROME_LOCKUP1_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_RESET_SYNDROME_LOCKUP1_Pos)                 /* SYS_CTRL_REG_SSE200 RESET_SYNDROME: LOCKUP1 Mask */

#define SYS_CTRL_REG_SSE200_RESET_SYNDROME_LOCKUP0_Pos                6                                                          /* SYS_CTRL_REG_SSE200 RESET_SYNDROME: LOCKUP0 Positions */
#define SYS_CTRL_REG_SSE200_RESET_SYNDROME_LOCKUP0_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_RESET_SYNDROME_LOCKUP0_Pos)                 /* SYS_CTRL_REG_SSE200 RESET_SYNDROME: LOCKUP0 Mask */

#define SYS_CTRL_REG_SSE200_RESET_SYNDROME_SYSRSTREQ1_Pos                5                                                          /* SYS_CTRL_REG_SSE200 RESET_SYNDROME: SYSRSTREQ1 Positions */
#define SYS_CTRL_REG_SSE200_RESET_SYNDROME_SYSRSTREQ1_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_RESET_SYNDROME_SYSRSTREQ1_Pos)                 /* SYS_CTRL_REG_SSE200 RESET_SYNDROME: SYSRSTREQ1 Mask */

#define SYS_CTRL_REG_SSE200_RESET_SYNDROME_SYSRSTREQ0_Pos                4                                                          /* SYS_CTRL_REG_SSE200 RESET_SYNDROME: SYSRSTREQ0 Positions */
#define SYS_CTRL_REG_SSE200_RESET_SYNDROME_SYSRSTREQ0_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_RESET_SYNDROME_SYSRSTREQ0_Pos)                 /* SYS_CTRL_REG_SSE200 RESET_SYNDROME: SYSRSTREQ0 Mask */

#define SYS_CTRL_REG_SSE200_RESET_SYNDROME_S32KWD_Pos                3                                                          /* SYS_CTRL_REG_SSE200 RESET_SYNDROME: S32KWD Positions */
#define SYS_CTRL_REG_SSE200_RESET_SYNDROME_S32KWD_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_RESET_SYNDROME_S32KWD_Pos)                 /* SYS_CTRL_REG_SSE200 RESET_SYNDROME: S32KWD Mask */

#define SYS_CTRL_REG_SSE200_RESET_SYNDROME_SWD_Pos                2                                                          /* SYS_CTRL_REG_SSE200 RESET_SYNDROME: SWD Positions */
#define SYS_CTRL_REG_SSE200_RESET_SYNDROME_SWD_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_RESET_SYNDROME_SWD_Pos)                 /* SYS_CTRL_REG_SSE200 RESET_SYNDROME: SWD Mask */

#define SYS_CTRL_REG_SSE200_RESET_SYNDROME_NSWD_Pos                1                                                          /* SYS_CTRL_REG_SSE200 RESET_SYNDROME: NSWD Positions */
#define SYS_CTRL_REG_SSE200_RESET_SYNDROME_NSWD_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_RESET_SYNDROME_NSWD_Pos)                 /* SYS_CTRL_REG_SSE200 RESET_SYNDROME: NSWD Mask */

#define SYS_CTRL_REG_SSE200_RESET_SYNDROME_PoR_Pos                0                                                          /* SYS_CTRL_REG_SSE200 RESET_SYNDROME: PoR Positions */
#define SYS_CTRL_REG_SSE200_RESET_SYNDROME_PoR_Msk                (0x1UL  /*<< SYS_CTRL_REG_SSE200_RESET_SYNDROME_PoR_Pos*/)                 /* SYS_CTRL_REG_SSE200 RESET_SYNDROME: PoR Mask */

/* SYS_CTRL_REG_SSE200 RESET_MASK Register Definitions */
#define SYS_CTRL_REG_SSE200_RESET_MASK_SYSRSTREQ1_EN_Pos                5                                                          /* SYS_CTRL_REG_SSE200 RESET_MASK: SYSRSTREQ1_EN Positions */
#define SYS_CTRL_REG_SSE200_RESET_MASK_SYSRSTREQ1_EN_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_RESET_MASK_SYSRSTREQ1_EN_Pos)                 /* SYS_CTRL_REG_SSE200 RESET_MASK: SYSRSTREQ1_EN Mask */

#define SYS_CTRL_REG_SSE200_RESET_MASK_SYSRSTREQ0_EN_Pos                4                                                          /* SYS_CTRL_REG_SSE200 RESET_MASK: SYSRSTREQ0_EN Positions */
#define SYS_CTRL_REG_SSE200_RESET_MASK_SYSRSTREQ0_EN_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_RESET_MASK_SYSRSTREQ0_EN_Pos)                 /* SYS_CTRL_REG_SSE200 RESET_MASK: SYSRSTREQ0_EN Mask */

#define SYS_CTRL_REG_SSE200_RESET_MASK_NSWD_EN_Pos                1                                                          /* SYS_CTRL_REG_SSE200 RESET_MASK: NSWD_EN Positions */
#define SYS_CTRL_REG_SSE200_RESET_MASK_NSWD_EN_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_RESET_MASK_NSWD_EN_Pos)                 /* SYS_CTRL_REG_SSE200 RESET_MASK: NSWD_EN Mask */

/* SYS_CTRL_REG_SSE200 SWRESET Register Definitions */
#define SYS_CTRL_REG_SSE200_SWRESET_SWRESETREQ_Pos                9                                                          /* SYS_CTRL_REG_SSE200 SWRESET: SWRESETREQ Positions */
#define SYS_CTRL_REG_SSE200_SWRESET_SWRESETREQ_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_SWRESET_SWRESETREQ_Pos)                 /* SYS_CTRL_REG_SSE200 SWRESET: SWRESETREQ Mask */

/* SYS_CTRL_REG_SSE200 GRETREG Register Definitions */
#define SYS_CTRL_REG_SSE200_GRETREG_GRETREG_Pos                0                                                          /* SYS_CTRL_REG_SSE200 GRETREG: GRETREG Positions */
#define SYS_CTRL_REG_SSE200_GRETREG_GRETREG_Msk                (0xFFFFUL  /*<< SYS_CTRL_REG_SSE200_GRETREG_GRETREG_Pos*/)                 /* SYS_CTRL_REG_SSE200 GRETREG: GRETREG Mask */

/* SYS_CTRL_REG_SSE200 INITSVTOR0 Register Definitions */
#define SYS_CTRL_REG_SSE200_INITSVTOR0_INITSVRTOR0_Pos                7                                                          /* SYS_CTRL_REG_SSE200 INITSVTOR0: INITSVRTOR0 Positions */
#define SYS_CTRL_REG_SSE200_INITSVTOR0_INITSVRTOR0_Msk                (0x1FFFFFFUL  << SYS_CTRL_REG_SSE200_INITSVTOR0_INITSVRTOR0_Pos)                 /* SYS_CTRL_REG_SSE200 INITSVTOR0: INITSVRTOR0 Mask */

/* SYS_CTRL_REG_SSE200 INITSVTOR1 Register Definitions */
#define SYS_CTRL_REG_SSE200_INITSVTOR1_INITSVRTOR1_Pos                7                                                          /* SYS_CTRL_REG_SSE200 INITSVTOR1: INITSVRTOR1 Positions */
#define SYS_CTRL_REG_SSE200_INITSVTOR1_INITSVRTOR1_Msk                (0x1FFFFFFUL  << SYS_CTRL_REG_SSE200_INITSVTOR1_INITSVRTOR1_Pos)                 /* SYS_CTRL_REG_SSE200 INITSVTOR1: INITSVRTOR1 Mask */

/* SYS_CTRL_REG_SSE200 CPUWAIT Register Definitions */
#define SYS_CTRL_REG_SSE200_CPUWAIT_CPU1WAIT_Pos                1                                                          /* SYS_CTRL_REG_SSE200 CPUWAIT: CPU1WAIT Positions */
#define SYS_CTRL_REG_SSE200_CPUWAIT_CPU1WAIT_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_CPUWAIT_CPU1WAIT_Pos)                 /* SYS_CTRL_REG_SSE200 CPUWAIT: CPU1WAIT Mask */

#define SYS_CTRL_REG_SSE200_CPUWAIT_CPU0WAIT_Pos                0                                                          /* SYS_CTRL_REG_SSE200 CPUWAIT: CPU0WAIT Positions */
#define SYS_CTRL_REG_SSE200_CPUWAIT_CPU0WAIT_Msk                (0x1UL  /*<< SYS_CTRL_REG_SSE200_CPUWAIT_CPU0WAIT_Pos*/)                 /* SYS_CTRL_REG_SSE200 CPUWAIT: CPU0WAIT Mask */

/* SYS_CTRL_REG_SSE200 NMI_ENABLE Register Definitions */
#define SYS_CTRL_REG_SSE200_NMI_ENABLE_CPU1_EXPNMI_ENABLE_Pos                17                                                          /* SYS_CTRL_REG_SSE200 NMI_ENABLE: CPU1_EXPNMI_ENABLE Positions */
#define SYS_CTRL_REG_SSE200_NMI_ENABLE_CPU1_EXPNMI_ENABLE_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_NMI_ENABLE_CPU1_EXPNMI_ENABLE_Pos)                 /* SYS_CTRL_REG_SSE200 NMI_ENABLE: CPU1_EXPNMI_ENABLE Mask */

#define SYS_CTRL_REG_SSE200_NMI_ENABLE_CPU0_EXPNMI_ENABLE_Pos                16                                                          /* SYS_CTRL_REG_SSE200 NMI_ENABLE: CPU0_EXPNMI_ENABLE Positions */
#define SYS_CTRL_REG_SSE200_NMI_ENABLE_CPU0_EXPNMI_ENABLE_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_NMI_ENABLE_CPU0_EXPNMI_ENABLE_Pos)                 /* SYS_CTRL_REG_SSE200 NMI_ENABLE: CPU0_EXPNMI_ENABLE Mask */

#define SYS_CTRL_REG_SSE200_NMI_ENABLE_CPU1_INTNMI_ENABLE_Pos                1                                                          /* SYS_CTRL_REG_SSE200 NMI_ENABLE: CPU1_INTNMI_ENABLE Positions */
#define SYS_CTRL_REG_SSE200_NMI_ENABLE_CPU1_INTNMI_ENABLE_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_NMI_ENABLE_CPU1_INTNMI_ENABLE_Pos)                 /* SYS_CTRL_REG_SSE200 NMI_ENABLE: CPU1_INTNMI_ENABLE Mask */

#define SYS_CTRL_REG_SSE200_NMI_ENABLE_CPU0_INTNMI_ENABLE_Pos                0                                                          /* SYS_CTRL_REG_SSE200 NMI_ENABLE: CPU0_INTNMI_ENABLE Positions */
#define SYS_CTRL_REG_SSE200_NMI_ENABLE_CPU0_INTNMI_ENABLE_Msk                (0x1UL  /*<< SYS_CTRL_REG_SSE200_NMI_ENABLE_CPU0_INTNMI_ENABLE_Pos*/)                 /* SYS_CTRL_REG_SSE200 NMI_ENABLE: CPU0_INTNMI_ENABLE Mask */

/* SYS_CTRL_REG_SSE200 WICCTRL Register Definitions */
#define SYS_CTRL_REG_SSE200_WICCTRL_CPU1WICRDY_Pos                17                                                          /* SYS_CTRL_REG_SSE200 WICCTRL: CPU1WICRDY Positions */
#define SYS_CTRL_REG_SSE200_WICCTRL_CPU1WICRDY_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_WICCTRL_CPU1WICRDY_Pos)                 /* SYS_CTRL_REG_SSE200 WICCTRL: CPU1WICRDY Mask */

#define SYS_CTRL_REG_SSE200_WICCTRL_CPU0WICRDY_Pos                16                                                          /* SYS_CTRL_REG_SSE200 WICCTRL: CPU0WICRDY Positions */
#define SYS_CTRL_REG_SSE200_WICCTRL_CPU0WICRDY_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_WICCTRL_CPU0WICRDY_Pos)                 /* SYS_CTRL_REG_SSE200 WICCTRL: CPU0WICRDY Mask */

#define SYS_CTRL_REG_SSE200_WICCTRL_CPU1WICEN_CLR_Pos                9                                                          /* SYS_CTRL_REG_SSE200 WICCTRL: CPU1WICEN_CLR Positions */
#define SYS_CTRL_REG_SSE200_WICCTRL_CPU1WICEN_CLR_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_WICCTRL_CPU1WICEN_CLR_Pos)                 /* SYS_CTRL_REG_SSE200 WICCTRL: CPU1WICEN_CLR Mask */

#define SYS_CTRL_REG_SSE200_WICCTRL_CPU0WICEN_CLR_Pos                8                                                          /* SYS_CTRL_REG_SSE200 WICCTRL: CPU0WICEN_CLR Positions */
#define SYS_CTRL_REG_SSE200_WICCTRL_CPU0WICEN_CLR_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_WICCTRL_CPU0WICEN_CLR_Pos)                 /* SYS_CTRL_REG_SSE200 WICCTRL: CPU0WICEN_CLR Mask */

#define SYS_CTRL_REG_SSE200_WICCTRL_CPU1WICEN_SET_Pos                5                                                          /* SYS_CTRL_REG_SSE200 WICCTRL: CPU1WICEN_SET Positions */
#define SYS_CTRL_REG_SSE200_WICCTRL_CPU1WICEN_SET_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_WICCTRL_CPU1WICEN_SET_Pos)                 /* SYS_CTRL_REG_SSE200 WICCTRL: CPU1WICEN_SET Mask */

#define SYS_CTRL_REG_SSE200_WICCTRL_CPU0WICEN_SET_Pos                4                                                          /* SYS_CTRL_REG_SSE200 WICCTRL: CPU0WICEN_SET Positions */
#define SYS_CTRL_REG_SSE200_WICCTRL_CPU0WICEN_SET_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_WICCTRL_CPU0WICEN_SET_Pos)                 /* SYS_CTRL_REG_SSE200 WICCTRL: CPU0WICEN_SET Mask */

#define SYS_CTRL_REG_SSE200_WICCTRL_CPU1WICEN_STATUS_Pos                1                                                          /* SYS_CTRL_REG_SSE200 WICCTRL: CPU1WICEN_STATUS Positions */
#define SYS_CTRL_REG_SSE200_WICCTRL_CPU1WICEN_STATUS_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_WICCTRL_CPU1WICEN_STATUS_Pos)                 /* SYS_CTRL_REG_SSE200 WICCTRL: CPU1WICEN_STATUS Mask */

#define SYS_CTRL_REG_SSE200_WICCTRL_CPU0WICEN_STATUS_Pos                0                                                          /* SYS_CTRL_REG_SSE200 WICCTRL: CPU0WICEN_STATUS Positions */
#define SYS_CTRL_REG_SSE200_WICCTRL_CPU0WICEN_STATUS_Msk                (0x1UL  /*<< SYS_CTRL_REG_SSE200_WICCTRL_CPU0WICEN_STATUS_Pos*/)                 /* SYS_CTRL_REG_SSE200 WICCTRL: CPU0WICEN_STATUS Mask */

/* SYS_CTRL_REG_SSE200 EWCTRL Register Definitions */
#define SYS_CTRL_REG_SSE200_EWCTRL_EWC1EN_CLR_Pos                9                                                          /* SYS_CTRL_REG_SSE200 EWCTRL: EWC1EN_CLR Positions */
#define SYS_CTRL_REG_SSE200_EWCTRL_EWC1EN_CLR_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_EWCTRL_EWC1EN_CLR_Pos)                 /* SYS_CTRL_REG_SSE200 EWCTRL: EWC1EN_CLR Mask */

#define SYS_CTRL_REG_SSE200_EWCTRL_EWC0EN_CLR_Pos                8                                                          /* SYS_CTRL_REG_SSE200 EWCTRL: EWC0EN_CLR Positions */
#define SYS_CTRL_REG_SSE200_EWCTRL_EWC0EN_CLR_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_EWCTRL_EWC0EN_CLR_Pos)                 /* SYS_CTRL_REG_SSE200 EWCTRL: EWC0EN_CLR Mask */

#define SYS_CTRL_REG_SSE200_EWCTRL_EWC1EN_SET_Pos                5                                                          /* SYS_CTRL_REG_SSE200 EWCTRL: EWC1EN_SET Positions */
#define SYS_CTRL_REG_SSE200_EWCTRL_EWC1EN_SET_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_EWCTRL_EWC1EN_SET_Pos)                 /* SYS_CTRL_REG_SSE200 EWCTRL: EWC1EN_SET Mask */

#define SYS_CTRL_REG_SSE200_EWCTRL_EWC0EN_SET_Pos                4                                                          /* SYS_CTRL_REG_SSE200 EWCTRL: EWC0EN_SET Positions */
#define SYS_CTRL_REG_SSE200_EWCTRL_EWC0EN_SET_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_EWCTRL_EWC0EN_SET_Pos)                 /* SYS_CTRL_REG_SSE200 EWCTRL: EWC0EN_SET Mask */

#define SYS_CTRL_REG_SSE200_EWCTRL_EWC1EN_STATUS_Pos                1                                                          /* SYS_CTRL_REG_SSE200 EWCTRL: EWC1EN_STATUS Positions */
#define SYS_CTRL_REG_SSE200_EWCTRL_EWC1EN_STATUS_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_EWCTRL_EWC1EN_STATUS_Pos)                 /* SYS_CTRL_REG_SSE200 EWCTRL: EWC1EN_STATUS Mask */

#define SYS_CTRL_REG_SSE200_EWCTRL_EWC0EN_STATUS_Pos                0                                                          /* SYS_CTRL_REG_SSE200 EWCTRL: EWC0EN_STATUS Positions */
#define SYS_CTRL_REG_SSE200_EWCTRL_EWC0EN_STATUS_Msk                (0x1UL  /*<< SYS_CTRL_REG_SSE200_EWCTRL_EWC0EN_STATUS_Pos*/)                 /* SYS_CTRL_REG_SSE200 EWCTRL: EWC0EN_STATUS Mask */

/* SYS_CTRL_REG_SSE200 PDCM_PD_SYS_SENSE Register Definitions */
#define SYS_CTRL_REG_SSE200_PDCM_PD_SYS_SENSE_S_PD_EXP3_IN_Pos                19                                                          /* SYS_CTRL_REG_SSE200 PDCM_PD_SYS_SENSE: S_PD_EXP3_IN Positions */
#define SYS_CTRL_REG_SSE200_PDCM_PD_SYS_SENSE_S_PD_EXP3_IN_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_PDCM_PD_SYS_SENSE_S_PD_EXP3_IN_Pos)                 /* SYS_CTRL_REG_SSE200 PDCM_PD_SYS_SENSE: S_PD_EXP3_IN Mask */

#define SYS_CTRL_REG_SSE200_PDCM_PD_SYS_SENSE_S_PD_EXP2_IN_Pos                18                                                          /* SYS_CTRL_REG_SSE200 PDCM_PD_SYS_SENSE: S_PD_EXP2_IN Positions */
#define SYS_CTRL_REG_SSE200_PDCM_PD_SYS_SENSE_S_PD_EXP2_IN_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_PDCM_PD_SYS_SENSE_S_PD_EXP2_IN_Pos)                 /* SYS_CTRL_REG_SSE200 PDCM_PD_SYS_SENSE: S_PD_EXP2_IN Mask */

#define SYS_CTRL_REG_SSE200_PDCM_PD_SYS_SENSE_S_PD_EXP1_IN_Pos                17                                                          /* SYS_CTRL_REG_SSE200 PDCM_PD_SYS_SENSE: S_PD_EXP1_IN Positions */
#define SYS_CTRL_REG_SSE200_PDCM_PD_SYS_SENSE_S_PD_EXP1_IN_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_PDCM_PD_SYS_SENSE_S_PD_EXP1_IN_Pos)                 /* SYS_CTRL_REG_SSE200 PDCM_PD_SYS_SENSE: S_PD_EXP1_IN Mask */

#define SYS_CTRL_REG_SSE200_PDCM_PD_SYS_SENSE_S_PD_EXP0_IN_Pos                16                                                          /* SYS_CTRL_REG_SSE200 PDCM_PD_SYS_SENSE: S_PD_EXP0_IN Positions */
#define SYS_CTRL_REG_SSE200_PDCM_PD_SYS_SENSE_S_PD_EXP0_IN_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_PDCM_PD_SYS_SENSE_S_PD_EXP0_IN_Pos)                 /* SYS_CTRL_REG_SSE200 PDCM_PD_SYS_SENSE: S_PD_EXP0_IN Mask */

#define SYS_CTRL_REG_SSE200_PDCM_PD_SYS_SENSE_S_PD_CRYPTO_ON_Pos                12                                                          /* SYS_CTRL_REG_SSE200 PDCM_PD_SYS_SENSE: S_PD_CRYPTO_ON Positions */
#define SYS_CTRL_REG_SSE200_PDCM_PD_SYS_SENSE_S_PD_CRYPTO_ON_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_PDCM_PD_SYS_SENSE_S_PD_CRYPTO_ON_Pos)                 /* SYS_CTRL_REG_SSE200 PDCM_PD_SYS_SENSE: S_PD_CRYPTO_ON Mask */

#define SYS_CTRL_REG_SSE200_PDCM_PD_SYS_SENSE_S_PD_SRAM3_ON_Pos                6                                                          /* SYS_CTRL_REG_SSE200 PDCM_PD_SYS_SENSE: S_PD_SRAM3_ON Positions */
#define SYS_CTRL_REG_SSE200_PDCM_PD_SYS_SENSE_S_PD_SRAM3_ON_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_PDCM_PD_SYS_SENSE_S_PD_SRAM3_ON_Pos)                 /* SYS_CTRL_REG_SSE200 PDCM_PD_SYS_SENSE: S_PD_SRAM3_ON Mask */

#define SYS_CTRL_REG_SSE200_PDCM_PD_SYS_SENSE_S_PD_SRAM2_ON_Pos                5                                                          /* SYS_CTRL_REG_SSE200 PDCM_PD_SYS_SENSE: S_PD_SRAM2_ON Positions */
#define SYS_CTRL_REG_SSE200_PDCM_PD_SYS_SENSE_S_PD_SRAM2_ON_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_PDCM_PD_SYS_SENSE_S_PD_SRAM2_ON_Pos)                 /* SYS_CTRL_REG_SSE200 PDCM_PD_SYS_SENSE: S_PD_SRAM2_ON Mask */

#define SYS_CTRL_REG_SSE200_PDCM_PD_SYS_SENSE_S_PD_SRAM1_ON_Pos                4                                                          /* SYS_CTRL_REG_SSE200 PDCM_PD_SYS_SENSE: S_PD_SRAM1_ON Positions */
#define SYS_CTRL_REG_SSE200_PDCM_PD_SYS_SENSE_S_PD_SRAM1_ON_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_PDCM_PD_SYS_SENSE_S_PD_SRAM1_ON_Pos)                 /* SYS_CTRL_REG_SSE200 PDCM_PD_SYS_SENSE: S_PD_SRAM1_ON Mask */

#define SYS_CTRL_REG_SSE200_PDCM_PD_SYS_SENSE_S_PD_SRAM0_ON_Pos                3                                                          /* SYS_CTRL_REG_SSE200 PDCM_PD_SYS_SENSE: S_PD_SRAM0_ON Positions */
#define SYS_CTRL_REG_SSE200_PDCM_PD_SYS_SENSE_S_PD_SRAM0_ON_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_PDCM_PD_SYS_SENSE_S_PD_SRAM0_ON_Pos)                 /* SYS_CTRL_REG_SSE200 PDCM_PD_SYS_SENSE: S_PD_SRAM0_ON Mask */

#define SYS_CTRL_REG_SSE200_PDCM_PD_SYS_SENSE_S_PD_CPU1CORE_ON_Pos                2                                                          /* SYS_CTRL_REG_SSE200 PDCM_PD_SYS_SENSE: S_PD_CPU1CORE_ON Positions */
#define SYS_CTRL_REG_SSE200_PDCM_PD_SYS_SENSE_S_PD_CPU1CORE_ON_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_PDCM_PD_SYS_SENSE_S_PD_CPU1CORE_ON_Pos)                 /* SYS_CTRL_REG_SSE200 PDCM_PD_SYS_SENSE: S_PD_CPU1CORE_ON Mask */

#define SYS_CTRL_REG_SSE200_PDCM_PD_SYS_SENSE_S_PD_CPU0CORE_ON_Pos                1                                                          /* SYS_CTRL_REG_SSE200 PDCM_PD_SYS_SENSE: S_PD_CPU0CORE_ON Positions */
#define SYS_CTRL_REG_SSE200_PDCM_PD_SYS_SENSE_S_PD_CPU0CORE_ON_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_PDCM_PD_SYS_SENSE_S_PD_CPU0CORE_ON_Pos)                 /* SYS_CTRL_REG_SSE200 PDCM_PD_SYS_SENSE: S_PD_CPU0CORE_ON Mask */

#define SYS_CTRL_REG_SSE200_PDCM_PD_SYS_SENSE_S_PD_SYS_ON_Pos                0                                                          /* SYS_CTRL_REG_SSE200 PDCM_PD_SYS_SENSE: S_PD_SYS_ON Positions */
#define SYS_CTRL_REG_SSE200_PDCM_PD_SYS_SENSE_S_PD_SYS_ON_Msk                (0x1UL  /*<< SYS_CTRL_REG_SSE200_PDCM_PD_SYS_SENSE_S_PD_SYS_ON_Pos*/)                 /* SYS_CTRL_REG_SSE200 PDCM_PD_SYS_SENSE: S_PD_SYS_ON Mask */

/* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM0_SENSE Register Definitions */
#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM0_SENSE_S_PD_EXP3_IN_Pos                19                                                          /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM0_SENSE: S_PD_EXP3_IN Positions */
#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM0_SENSE_S_PD_EXP3_IN_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_PDCM_PD_SRAM0_SENSE_S_PD_EXP3_IN_Pos)                 /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM0_SENSE: S_PD_EXP3_IN Mask */

#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM0_SENSE_S_PD_EXP2_IN_Pos                18                                                          /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM0_SENSE: S_PD_EXP2_IN Positions */
#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM0_SENSE_S_PD_EXP2_IN_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_PDCM_PD_SRAM0_SENSE_S_PD_EXP2_IN_Pos)                 /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM0_SENSE: S_PD_EXP2_IN Mask */

#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM0_SENSE_S_PD_EXP1_IN_Pos                17                                                          /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM0_SENSE: S_PD_EXP1_IN Positions */
#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM0_SENSE_S_PD_EXP1_IN_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_PDCM_PD_SRAM0_SENSE_S_PD_EXP1_IN_Pos)                 /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM0_SENSE: S_PD_EXP1_IN Mask */

#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM0_SENSE_S_PD_EXP0_IN_Pos                16                                                          /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM0_SENSE: S_PD_EXP0_IN Positions */
#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM0_SENSE_S_PD_EXP0_IN_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_PDCM_PD_SRAM0_SENSE_S_PD_EXP0_IN_Pos)                 /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM0_SENSE: S_PD_EXP0_IN Mask */

#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM0_SENSE_S_PD_CRYPTO_ON_Pos                12                                                          /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM0_SENSE: S_PD_CRYPTO_ON Positions */
#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM0_SENSE_S_PD_CRYPTO_ON_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_PDCM_PD_SRAM0_SENSE_S_PD_CRYPTO_ON_Pos)                 /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM0_SENSE: S_PD_CRYPTO_ON Mask */

#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM0_SENSE_S_PD_SRAM3_ON_Pos                6                                                          /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM0_SENSE: S_PD_SRAM3_ON Positions */
#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM0_SENSE_S_PD_SRAM3_ON_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_PDCM_PD_SRAM0_SENSE_S_PD_SRAM3_ON_Pos)                 /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM0_SENSE: S_PD_SRAM3_ON Mask */

#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM0_SENSE_S_PD_SRAM2_ON_Pos                5                                                          /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM0_SENSE: S_PD_SRAM2_ON Positions */
#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM0_SENSE_S_PD_SRAM2_ON_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_PDCM_PD_SRAM0_SENSE_S_PD_SRAM2_ON_Pos)                 /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM0_SENSE: S_PD_SRAM2_ON Mask */

#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM0_SENSE_S_PD_SRAM1_ON_Pos                4                                                          /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM0_SENSE: S_PD_SRAM1_ON Positions */
#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM0_SENSE_S_PD_SRAM1_ON_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_PDCM_PD_SRAM0_SENSE_S_PD_SRAM1_ON_Pos)                 /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM0_SENSE: S_PD_SRAM1_ON Mask */

#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM0_SENSE_S_PD_SRAM0_ON_Pos                3                                                          /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM0_SENSE: S_PD_SRAM0_ON Positions */
#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM0_SENSE_S_PD_SRAM0_ON_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_PDCM_PD_SRAM0_SENSE_S_PD_SRAM0_ON_Pos)                 /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM0_SENSE: S_PD_SRAM0_ON Mask */

#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM0_SENSE_S_PD_CPU1CORE_ON_Pos                2                                                          /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM0_SENSE: S_PD_CPU1CORE_ON Positions */
#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM0_SENSE_S_PD_CPU1CORE_ON_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_PDCM_PD_SRAM0_SENSE_S_PD_CPU1CORE_ON_Pos)                 /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM0_SENSE: S_PD_CPU1CORE_ON Mask */

#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM0_SENSE_S_PD_CPU0CORE_ON_Pos                1                                                          /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM0_SENSE: S_PD_CPU0CORE_ON Positions */
#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM0_SENSE_S_PD_CPU0CORE_ON_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_PDCM_PD_SRAM0_SENSE_S_PD_CPU0CORE_ON_Pos)                 /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM0_SENSE: S_PD_CPU0CORE_ON Mask */

#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM0_SENSE_S_PD_SYS_ON_Pos                0                                                          /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM0_SENSE: S_PD_SYS_ON Positions */
#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM0_SENSE_S_PD_SYS_ON_Msk                (0x1UL  /*<< SYS_CTRL_REG_SSE200_PDCM_PD_SRAM0_SENSE_S_PD_SYS_ON_Pos*/)                 /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM0_SENSE: S_PD_SYS_ON Mask */

/* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM1_SENSE Register Definitions */
#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM1_SENSE_S_PD_EXP3_IN_Pos                19                                                          /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM1_SENSE: S_PD_EXP3_IN Positions */
#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM1_SENSE_S_PD_EXP3_IN_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_PDCM_PD_SRAM1_SENSE_S_PD_EXP3_IN_Pos)                 /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM1_SENSE: S_PD_EXP3_IN Mask */

#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM1_SENSE_S_PD_EXP2_IN_Pos                18                                                          /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM1_SENSE: S_PD_EXP2_IN Positions */
#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM1_SENSE_S_PD_EXP2_IN_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_PDCM_PD_SRAM1_SENSE_S_PD_EXP2_IN_Pos)                 /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM1_SENSE: S_PD_EXP2_IN Mask */

#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM1_SENSE_S_PD_EXP1_IN_Pos                17                                                          /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM1_SENSE: S_PD_EXP1_IN Positions */
#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM1_SENSE_S_PD_EXP1_IN_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_PDCM_PD_SRAM1_SENSE_S_PD_EXP1_IN_Pos)                 /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM1_SENSE: S_PD_EXP1_IN Mask */

#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM1_SENSE_S_PD_EXP0_IN_Pos                16                                                          /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM1_SENSE: S_PD_EXP0_IN Positions */
#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM1_SENSE_S_PD_EXP0_IN_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_PDCM_PD_SRAM1_SENSE_S_PD_EXP0_IN_Pos)                 /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM1_SENSE: S_PD_EXP0_IN Mask */

#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM1_SENSE_S_PD_CRYPTO_ON_Pos                12                                                          /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM1_SENSE: S_PD_CRYPTO_ON Positions */
#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM1_SENSE_S_PD_CRYPTO_ON_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_PDCM_PD_SRAM1_SENSE_S_PD_CRYPTO_ON_Pos)                 /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM1_SENSE: S_PD_CRYPTO_ON Mask */

#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM1_SENSE_S_PD_SRAM3_ON_Pos                6                                                          /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM1_SENSE: S_PD_SRAM3_ON Positions */
#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM1_SENSE_S_PD_SRAM3_ON_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_PDCM_PD_SRAM1_SENSE_S_PD_SRAM3_ON_Pos)                 /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM1_SENSE: S_PD_SRAM3_ON Mask */

#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM1_SENSE_S_PD_SRAM2_ON_Pos                5                                                          /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM1_SENSE: S_PD_SRAM2_ON Positions */
#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM1_SENSE_S_PD_SRAM2_ON_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_PDCM_PD_SRAM1_SENSE_S_PD_SRAM2_ON_Pos)                 /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM1_SENSE: S_PD_SRAM2_ON Mask */

#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM1_SENSE_S_PD_SRAM1_ON_Pos                4                                                          /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM1_SENSE: S_PD_SRAM1_ON Positions */
#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM1_SENSE_S_PD_SRAM1_ON_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_PDCM_PD_SRAM1_SENSE_S_PD_SRAM1_ON_Pos)                 /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM1_SENSE: S_PD_SRAM1_ON Mask */

#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM1_SENSE_S_PD_SRAM0_ON_Pos                3                                                          /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM1_SENSE: S_PD_SRAM0_ON Positions */
#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM1_SENSE_S_PD_SRAM0_ON_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_PDCM_PD_SRAM1_SENSE_S_PD_SRAM0_ON_Pos)                 /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM1_SENSE: S_PD_SRAM0_ON Mask */

#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM1_SENSE_S_PD_CPU1CORE_ON_Pos                2                                                          /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM1_SENSE: S_PD_CPU1CORE_ON Positions */
#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM1_SENSE_S_PD_CPU1CORE_ON_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_PDCM_PD_SRAM1_SENSE_S_PD_CPU1CORE_ON_Pos)                 /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM1_SENSE: S_PD_CPU1CORE_ON Mask */

#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM1_SENSE_S_PD_CPU0CORE_ON_Pos                1                                                          /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM1_SENSE: S_PD_CPU0CORE_ON Positions */
#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM1_SENSE_S_PD_CPU0CORE_ON_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_PDCM_PD_SRAM1_SENSE_S_PD_CPU0CORE_ON_Pos)                 /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM1_SENSE: S_PD_CPU0CORE_ON Mask */

#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM1_SENSE_S_PD_SYS_ON_Pos                0                                                          /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM1_SENSE: S_PD_SYS_ON Positions */
#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM1_SENSE_S_PD_SYS_ON_Msk                (0x1UL  /*<< SYS_CTRL_REG_SSE200_PDCM_PD_SRAM1_SENSE_S_PD_SYS_ON_Pos*/)                 /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM1_SENSE: S_PD_SYS_ON Mask */

/* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM2_SENSE Register Definitions */
#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM2_SENSE_S_PD_EXP3_IN_Pos                19                                                          /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM2_SENSE: S_PD_EXP3_IN Positions */
#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM2_SENSE_S_PD_EXP3_IN_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_PDCM_PD_SRAM2_SENSE_S_PD_EXP3_IN_Pos)                 /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM2_SENSE: S_PD_EXP3_IN Mask */

#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM2_SENSE_S_PD_EXP2_IN_Pos                18                                                          /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM2_SENSE: S_PD_EXP2_IN Positions */
#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM2_SENSE_S_PD_EXP2_IN_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_PDCM_PD_SRAM2_SENSE_S_PD_EXP2_IN_Pos)                 /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM2_SENSE: S_PD_EXP2_IN Mask */

#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM2_SENSE_S_PD_EXP1_IN_Pos                17                                                          /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM2_SENSE: S_PD_EXP1_IN Positions */
#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM2_SENSE_S_PD_EXP1_IN_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_PDCM_PD_SRAM2_SENSE_S_PD_EXP1_IN_Pos)                 /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM2_SENSE: S_PD_EXP1_IN Mask */

#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM2_SENSE_S_PD_EXP0_IN_Pos                16                                                          /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM2_SENSE: S_PD_EXP0_IN Positions */
#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM2_SENSE_S_PD_EXP0_IN_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_PDCM_PD_SRAM2_SENSE_S_PD_EXP0_IN_Pos)                 /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM2_SENSE: S_PD_EXP0_IN Mask */

#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM2_SENSE_S_PD_CRYPTO_ON_Pos                12                                                          /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM2_SENSE: S_PD_CRYPTO_ON Positions */
#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM2_SENSE_S_PD_CRYPTO_ON_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_PDCM_PD_SRAM2_SENSE_S_PD_CRYPTO_ON_Pos)                 /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM2_SENSE: S_PD_CRYPTO_ON Mask */

#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM2_SENSE_S_PD_SRAM3_ON_Pos                6                                                          /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM2_SENSE: S_PD_SRAM3_ON Positions */
#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM2_SENSE_S_PD_SRAM3_ON_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_PDCM_PD_SRAM2_SENSE_S_PD_SRAM3_ON_Pos)                 /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM2_SENSE: S_PD_SRAM3_ON Mask */

#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM2_SENSE_S_PD_SRAM2_ON_Pos                5                                                          /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM2_SENSE: S_PD_SRAM2_ON Positions */
#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM2_SENSE_S_PD_SRAM2_ON_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_PDCM_PD_SRAM2_SENSE_S_PD_SRAM2_ON_Pos)                 /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM2_SENSE: S_PD_SRAM2_ON Mask */

#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM2_SENSE_S_PD_SRAM1_ON_Pos                4                                                          /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM2_SENSE: S_PD_SRAM1_ON Positions */
#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM2_SENSE_S_PD_SRAM1_ON_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_PDCM_PD_SRAM2_SENSE_S_PD_SRAM1_ON_Pos)                 /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM2_SENSE: S_PD_SRAM1_ON Mask */

#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM2_SENSE_S_PD_SRAM0_ON_Pos                3                                                          /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM2_SENSE: S_PD_SRAM0_ON Positions */
#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM2_SENSE_S_PD_SRAM0_ON_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_PDCM_PD_SRAM2_SENSE_S_PD_SRAM0_ON_Pos)                 /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM2_SENSE: S_PD_SRAM0_ON Mask */

#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM2_SENSE_S_PD_CPU1CORE_ON_Pos                2                                                          /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM2_SENSE: S_PD_CPU1CORE_ON Positions */
#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM2_SENSE_S_PD_CPU1CORE_ON_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_PDCM_PD_SRAM2_SENSE_S_PD_CPU1CORE_ON_Pos)                 /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM2_SENSE: S_PD_CPU1CORE_ON Mask */

#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM2_SENSE_S_PD_CPU0CORE_ON_Pos                1                                                          /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM2_SENSE: S_PD_CPU0CORE_ON Positions */
#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM2_SENSE_S_PD_CPU0CORE_ON_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_PDCM_PD_SRAM2_SENSE_S_PD_CPU0CORE_ON_Pos)                 /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM2_SENSE: S_PD_CPU0CORE_ON Mask */

#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM2_SENSE_S_PD_SYS_ON_Pos                0                                                          /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM2_SENSE: S_PD_SYS_ON Positions */
#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM2_SENSE_S_PD_SYS_ON_Msk                (0x1UL  /*<< SYS_CTRL_REG_SSE200_PDCM_PD_SRAM2_SENSE_S_PD_SYS_ON_Pos*/)                 /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM2_SENSE: S_PD_SYS_ON Mask */

/* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM3_SENSE Register Definitions */
#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM3_SENSE_S_PD_EXP3_IN_Pos                19                                                          /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM3_SENSE: S_PD_EXP3_IN Positions */
#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM3_SENSE_S_PD_EXP3_IN_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_PDCM_PD_SRAM3_SENSE_S_PD_EXP3_IN_Pos)                 /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM3_SENSE: S_PD_EXP3_IN Mask */

#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM3_SENSE_S_PD_EXP2_IN_Pos                18                                                          /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM3_SENSE: S_PD_EXP2_IN Positions */
#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM3_SENSE_S_PD_EXP2_IN_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_PDCM_PD_SRAM3_SENSE_S_PD_EXP2_IN_Pos)                 /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM3_SENSE: S_PD_EXP2_IN Mask */

#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM3_SENSE_S_PD_EXP1_IN_Pos                17                                                          /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM3_SENSE: S_PD_EXP1_IN Positions */
#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM3_SENSE_S_PD_EXP1_IN_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_PDCM_PD_SRAM3_SENSE_S_PD_EXP1_IN_Pos)                 /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM3_SENSE: S_PD_EXP1_IN Mask */

#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM3_SENSE_S_PD_EXP0_IN_Pos                16                                                          /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM3_SENSE: S_PD_EXP0_IN Positions */
#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM3_SENSE_S_PD_EXP0_IN_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_PDCM_PD_SRAM3_SENSE_S_PD_EXP0_IN_Pos)                 /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM3_SENSE: S_PD_EXP0_IN Mask */

#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM3_SENSE_S_PD_CRYPTO_ON_Pos                12                                                          /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM3_SENSE: S_PD_CRYPTO_ON Positions */
#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM3_SENSE_S_PD_CRYPTO_ON_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_PDCM_PD_SRAM3_SENSE_S_PD_CRYPTO_ON_Pos)                 /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM3_SENSE: S_PD_CRYPTO_ON Mask */

#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM3_SENSE_S_PD_SRAM3_ON_Pos                6                                                          /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM3_SENSE: S_PD_SRAM3_ON Positions */
#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM3_SENSE_S_PD_SRAM3_ON_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_PDCM_PD_SRAM3_SENSE_S_PD_SRAM3_ON_Pos)                 /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM3_SENSE: S_PD_SRAM3_ON Mask */

#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM3_SENSE_S_PD_SRAM2_ON_Pos                5                                                          /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM3_SENSE: S_PD_SRAM2_ON Positions */
#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM3_SENSE_S_PD_SRAM2_ON_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_PDCM_PD_SRAM3_SENSE_S_PD_SRAM2_ON_Pos)                 /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM3_SENSE: S_PD_SRAM2_ON Mask */

#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM3_SENSE_S_PD_SRAM1_ON_Pos                4                                                          /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM3_SENSE: S_PD_SRAM1_ON Positions */
#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM3_SENSE_S_PD_SRAM1_ON_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_PDCM_PD_SRAM3_SENSE_S_PD_SRAM1_ON_Pos)                 /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM3_SENSE: S_PD_SRAM1_ON Mask */

#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM3_SENSE_S_PD_SRAM0_ON_Pos                3                                                          /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM3_SENSE: S_PD_SRAM0_ON Positions */
#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM3_SENSE_S_PD_SRAM0_ON_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_PDCM_PD_SRAM3_SENSE_S_PD_SRAM0_ON_Pos)                 /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM3_SENSE: S_PD_SRAM0_ON Mask */

#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM3_SENSE_S_PD_CPU1CORE_ON_Pos                2                                                          /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM3_SENSE: S_PD_CPU1CORE_ON Positions */
#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM3_SENSE_S_PD_CPU1CORE_ON_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_PDCM_PD_SRAM3_SENSE_S_PD_CPU1CORE_ON_Pos)                 /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM3_SENSE: S_PD_CPU1CORE_ON Mask */

#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM3_SENSE_S_PD_CPU0CORE_ON_Pos                1                                                          /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM3_SENSE: S_PD_CPU0CORE_ON Positions */
#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM3_SENSE_S_PD_CPU0CORE_ON_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_PDCM_PD_SRAM3_SENSE_S_PD_CPU0CORE_ON_Pos)                 /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM3_SENSE: S_PD_CPU0CORE_ON Mask */

#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM3_SENSE_S_PD_SYS_ON_Pos                0                                                          /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM3_SENSE: S_PD_SYS_ON Positions */
#define SYS_CTRL_REG_SSE200_PDCM_PD_SRAM3_SENSE_S_PD_SYS_ON_Msk                (0x1UL  /*<< SYS_CTRL_REG_SSE200_PDCM_PD_SRAM3_SENSE_S_PD_SYS_ON_Pos*/)                 /* SYS_CTRL_REG_SSE200 PDCM_PD_SRAM3_SENSE: S_PD_SYS_ON Mask */

/* SYS_CTRL_REG_SSE200 PIDR4 Register Definitions */
#define SYS_CTRL_REG_SSE200_PIDR4_SIZE_Pos                4                                                          /* SYS_CTRL_REG_SSE200 PIDR4: SIZE Positions */
#define SYS_CTRL_REG_SSE200_PIDR4_SIZE_Msk                (0xFUL  << SYS_CTRL_REG_SSE200_PIDR4_SIZE_Pos)                 /* SYS_CTRL_REG_SSE200 PIDR4: SIZE Mask */

#define SYS_CTRL_REG_SSE200_PIDR4_DES_2_Pos                0                                                          /* SYS_CTRL_REG_SSE200 PIDR4: DES_2 Positions */
#define SYS_CTRL_REG_SSE200_PIDR4_DES_2_Msk                (0xFUL  /*<< SYS_CTRL_REG_SSE200_PIDR4_DES_2_Pos*/)                 /* SYS_CTRL_REG_SSE200 PIDR4: DES_2 Mask */

/* SYS_CTRL_REG_SSE200 PIDR0 Register Definitions */
#define SYS_CTRL_REG_SSE200_PIDR0_PART_0_Pos                0                                                          /* SYS_CTRL_REG_SSE200 PIDR0: PART_0 Positions */
#define SYS_CTRL_REG_SSE200_PIDR0_PART_0_Msk                (0xFFUL  /*<< SYS_CTRL_REG_SSE200_PIDR0_PART_0_Pos*/)                 /* SYS_CTRL_REG_SSE200 PIDR0: PART_0 Mask */

/* SYS_CTRL_REG_SSE200 PIDR1 Register Definitions */
#define SYS_CTRL_REG_SSE200_PIDR1_DES_0_Pos                4                                                          /* SYS_CTRL_REG_SSE200 PIDR1: DES_0 Positions */
#define SYS_CTRL_REG_SSE200_PIDR1_DES_0_Msk                (0xFUL  << SYS_CTRL_REG_SSE200_PIDR1_DES_0_Pos)                 /* SYS_CTRL_REG_SSE200 PIDR1: DES_0 Mask */

#define SYS_CTRL_REG_SSE200_PIDR1_PART_1_Pos                0                                                          /* SYS_CTRL_REG_SSE200 PIDR1: PART_1 Positions */
#define SYS_CTRL_REG_SSE200_PIDR1_PART_1_Msk                (0xFUL  /*<< SYS_CTRL_REG_SSE200_PIDR1_PART_1_Pos*/)                 /* SYS_CTRL_REG_SSE200 PIDR1: PART_1 Mask */

/* SYS_CTRL_REG_SSE200 PIDR2 Register Definitions */
#define SYS_CTRL_REG_SSE200_PIDR2_REVISION_Pos                4                                                          /* SYS_CTRL_REG_SSE200 PIDR2: REVISION Positions */
#define SYS_CTRL_REG_SSE200_PIDR2_REVISION_Msk                (0xFUL  << SYS_CTRL_REG_SSE200_PIDR2_REVISION_Pos)                 /* SYS_CTRL_REG_SSE200 PIDR2: REVISION Mask */

#define SYS_CTRL_REG_SSE200_PIDR2_JEDEC_Pos                3                                                          /* SYS_CTRL_REG_SSE200 PIDR2: JEDEC Positions */
#define SYS_CTRL_REG_SSE200_PIDR2_JEDEC_Msk                (0x1UL  << SYS_CTRL_REG_SSE200_PIDR2_JEDEC_Pos)                 /* SYS_CTRL_REG_SSE200 PIDR2: JEDEC Mask */

#define SYS_CTRL_REG_SSE200_PIDR2_DES_1_Pos                0                                                          /* SYS_CTRL_REG_SSE200 PIDR2: DES_1 Positions */
#define SYS_CTRL_REG_SSE200_PIDR2_DES_1_Msk                (0x7UL  /*<< SYS_CTRL_REG_SSE200_PIDR2_DES_1_Pos*/)                 /* SYS_CTRL_REG_SSE200 PIDR2: DES_1 Mask */

/* SYS_CTRL_REG_SSE200 PIDR3 Register Definitions */
#define SYS_CTRL_REG_SSE200_PIDR3_REVAND_Pos                4                                                          /* SYS_CTRL_REG_SSE200 PIDR3: REVAND Positions */
#define SYS_CTRL_REG_SSE200_PIDR3_REVAND_Msk                (0xFUL  << SYS_CTRL_REG_SSE200_PIDR3_REVAND_Pos)                 /* SYS_CTRL_REG_SSE200 PIDR3: REVAND Mask */

#define SYS_CTRL_REG_SSE200_PIDR3_CMOD_Pos                0                                                          /* SYS_CTRL_REG_SSE200 PIDR3: CMOD Positions */
#define SYS_CTRL_REG_SSE200_PIDR3_CMOD_Msk                (0xFUL  /*<< SYS_CTRL_REG_SSE200_PIDR3_CMOD_Pos*/)                 /* SYS_CTRL_REG_SSE200 PIDR3: CMOD Mask */

/* SYS_CTRL_REG_SSE200 CIDR0 Register Definitions */
#define SYS_CTRL_REG_SSE200_CIDR0_PRMBL_0_Pos                0                                                          /* SYS_CTRL_REG_SSE200 CIDR0: PRMBL_0 Positions */
#define SYS_CTRL_REG_SSE200_CIDR0_PRMBL_0_Msk                (0xFFUL  /*<< SYS_CTRL_REG_SSE200_CIDR0_PRMBL_0_Pos*/)                 /* SYS_CTRL_REG_SSE200 CIDR0: PRMBL_0 Mask */

/* SYS_CTRL_REG_SSE200 CIDR1 Register Definitions */
#define SYS_CTRL_REG_SSE200_CIDR1_CLASS_Pos                4                                                          /* SYS_CTRL_REG_SSE200 CIDR1: CLASS Positions */
#define SYS_CTRL_REG_SSE200_CIDR1_CLASS_Msk                (0xFUL  << SYS_CTRL_REG_SSE200_CIDR1_CLASS_Pos)                 /* SYS_CTRL_REG_SSE200 CIDR1: CLASS Mask */

#define SYS_CTRL_REG_SSE200_CIDR1_PRMBL_1_Pos                0                                                          /* SYS_CTRL_REG_SSE200 CIDR1: PRMBL_1 Positions */
#define SYS_CTRL_REG_SSE200_CIDR1_PRMBL_1_Msk                (0xFUL  /*<< SYS_CTRL_REG_SSE200_CIDR1_PRMBL_1_Pos*/)                 /* SYS_CTRL_REG_SSE200 CIDR1: PRMBL_1 Mask */

/* SYS_CTRL_REG_SSE200 CIDR2 Register Definitions */
#define SYS_CTRL_REG_SSE200_CIDR2_PRMBL_2_Pos                0                                                          /* SYS_CTRL_REG_SSE200 CIDR2: PRMBL_2 Positions */
#define SYS_CTRL_REG_SSE200_CIDR2_PRMBL_2_Msk                (0xFFUL  /*<< SYS_CTRL_REG_SSE200_CIDR2_PRMBL_2_Pos*/)                 /* SYS_CTRL_REG_SSE200 CIDR2: PRMBL_2 Mask */

/* SYS_CTRL_REG_SSE200 CIDR3 Register Definitions */
#define SYS_CTRL_REG_SSE200_CIDR3_PRMBL_3_Pos                0                                                          /* SYS_CTRL_REG_SSE200 CIDR3: PRMBL_3 Positions */
#define SYS_CTRL_REG_SSE200_CIDR3_PRMBL_3_Msk                (0xFFUL  /*<< SYS_CTRL_REG_SSE200_CIDR3_PRMBL_3_Pos*/)                 /* SYS_CTRL_REG_SSE200 CIDR3: PRMBL_3 Mask */


/*---------------- SYSTEM INFO REGISTER (SYSINFO) ----------------*/
typedef struct
{
__IM   uint32_t SYS_VERSION;                  /* Offset: 0x0 (read-only) SYS_VERSION Register    */
__IM   uint32_t SYS_CONFIG;                  /* Offset: 0x4 (read-only) SYS_CONFIG Register    */
       uint32_t RESERVED0[1010];
__IM   uint32_t PIDR4;                  /* Offset: 0xFD0 (read-only) PIDR4 Register    */
       uint32_t RESERVED1[3];
__IM   uint32_t PIDR0;                  /* Offset: 0xFE0 (read-only) PIDR0 Register    */
__IM   uint32_t PIDR1;                  /* Offset: 0xFE4 (read-only) PIDR1 Register    */
__IM   uint32_t PIDR2;                  /* Offset: 0xFE8 (read-only) PIDR2 Register    */
__IM   uint32_t PIDR3;                  /* Offset: 0xFEC (read-only) PIDR3 Register    */
__IM   uint32_t CIDR0;                  /* Offset: 0xFF0 (read-only) CIDR0 Register    */
__IM   uint32_t CIDR1;                  /* Offset: 0xFF4 (read-only) CIDR1 Register    */
__IM   uint32_t CIDR2;                  /* Offset: 0xFF8 (read-only) CIDR2 Register    */
__IM   uint32_t CIDR3;                  /* Offset: 0xFFC (read-only) CIDR3 Register    */
}SYSINFO_TypeDef;

/* SYSINFO SYS_VERSION Register Definitions */
#define SYSINFO_SYS_VERSION_CONFIGURATION_Pos                28                                                          /* SYSINFO SYS_VERSION: CONFIGURATION Positions */
#define SYSINFO_SYS_VERSION_CONFIGURATION_Msk                (0xFUL  << SYSINFO_SYS_VERSION_CONFIGURATION_Pos)                 /* SYSINFO SYS_VERSION: CONFIGURATION Mask */

#define SYSINFO_SYS_VERSION_MAJOR_REVISION_Pos                24                                                          /* SYSINFO SYS_VERSION: MAJOR_REVISION Positions */
#define SYSINFO_SYS_VERSION_MAJOR_REVISION_Msk                (0xFUL  << SYSINFO_SYS_VERSION_MAJOR_REVISION_Pos)                 /* SYSINFO SYS_VERSION: MAJOR_REVISION Mask */

#define SYSINFO_SYS_VERSION_MINOR_REVISION_Pos                20                                                          /* SYSINFO SYS_VERSION: MINOR_REVISION Positions */
#define SYSINFO_SYS_VERSION_MINOR_REVISION_Msk                (0xFUL  << SYSINFO_SYS_VERSION_MINOR_REVISION_Pos)                 /* SYSINFO SYS_VERSION: MINOR_REVISION Mask */

#define SYSINFO_SYS_VERSION_DESIGNER_ID_Pos                12                                                          /* SYSINFO SYS_VERSION: DESIGNER_ID Positions */
#define SYSINFO_SYS_VERSION_DESIGNER_ID_Msk                (0xFFUL  << SYSINFO_SYS_VERSION_DESIGNER_ID_Pos)                 /* SYSINFO SYS_VERSION: DESIGNER_ID Mask */

#define SYSINFO_SYS_VERSION_PART_NUMBER_Pos                0                                                          /* SYSINFO SYS_VERSION: PART_NUMBER Positions */
#define SYSINFO_SYS_VERSION_PART_NUMBER_Msk                (0xFFFUL  /*<< SYSINFO_SYS_VERSION_PART_NUMBER_Pos*/)                 /* SYSINFO SYS_VERSION: PART_NUMBER Mask */

/* SYSINFO SYS_CONFIG Register Definitions */
#define SYSINFO_SYS_CONFIG_CPU1_TYPE_Pos                28                                                          /* SYSINFO SYS_CONFIG: CPU1_TYPE Positions */
#define SYSINFO_SYS_CONFIG_CPU1_TYPE_Msk                (0xFUL  << SYSINFO_SYS_CONFIG_CPU1_TYPE_Pos)                 /* SYSINFO SYS_CONFIG: CPU1_TYPE Mask */

#define SYSINFO_SYS_CONFIG_CPU0_TYPE_Pos                24                                                          /* SYSINFO SYS_CONFIG: CPU0_TYPE Positions */
#define SYSINFO_SYS_CONFIG_CPU0_TYPE_Msk                (0xFUL  << SYSINFO_SYS_CONFIG_CPU0_TYPE_Pos)                 /* SYSINFO SYS_CONFIG: CPU0_TYPE Mask */

#define SYSINFO_SYS_CONFIG_CPU1_TCM_BANK_NUM_Pos                20                                                          /* SYSINFO SYS_CONFIG: CPU1_TCM_BANK_NUM Positions */
#define SYSINFO_SYS_CONFIG_CPU1_TCM_BANK_NUM_Msk                (0xFUL  << SYSINFO_SYS_CONFIG_CPU1_TCM_BANK_NUM_Pos)                 /* SYSINFO SYS_CONFIG: CPU1_TCM_BANK_NUM Mask */

#define SYSINFO_SYS_CONFIG_CPU0_TCM_BANK_NUM_Pos                16                                                          /* SYSINFO SYS_CONFIG: CPU0_TCM_BANK_NUM Positions */
#define SYSINFO_SYS_CONFIG_CPU0_TCM_BANK_NUM_Msk                (0xFUL  << SYSINFO_SYS_CONFIG_CPU0_TCM_BANK_NUM_Pos)                 /* SYSINFO SYS_CONFIG: CPU0_TCM_BANK_NUM Mask */

#define SYSINFO_SYS_CONFIG_HAS_CRYPTO_Pos                12                                                          /* SYSINFO SYS_CONFIG: HAS_CRYPTO Positions */
#define SYSINFO_SYS_CONFIG_HAS_CRYPTO_Msk                (0x1UL  << SYSINFO_SYS_CONFIG_HAS_CRYPTO_Pos)                 /* SYSINFO SYS_CONFIG: HAS_CRYPTO Mask */

#define SYSINFO_SYS_CONFIG_HAS_CORDIO_Pos                11                                                          /* SYSINFO SYS_CONFIG: HAS_CORDIO Positions */
#define SYSINFO_SYS_CONFIG_HAS_CORDIO_Msk                (0x1UL  << SYSINFO_SYS_CONFIG_HAS_CORDIO_Pos)                 /* SYSINFO SYS_CONFIG: HAS_CORDIO Mask */

#define SYSINFO_SYS_CONFIG_CPU1_HAS_TCM_Pos                10                                                          /* SYSINFO SYS_CONFIG: CPU1_HAS_TCM Positions */
#define SYSINFO_SYS_CONFIG_CPU1_HAS_TCM_Msk                (0x1UL  << SYSINFO_SYS_CONFIG_CPU1_HAS_TCM_Pos)                 /* SYSINFO SYS_CONFIG: CPU1_HAS_TCM Mask */

#define SYSINFO_SYS_CONFIG_CPU0_HAS_TCM_Pos                9                                                          /* SYSINFO SYS_CONFIG: CPU0_HAS_TCM Positions */
#define SYSINFO_SYS_CONFIG_CPU0_HAS_TCM_Msk                (0x1UL  << SYSINFO_SYS_CONFIG_CPU0_HAS_TCM_Pos)                 /* SYSINFO SYS_CONFIG: CPU0_HAS_TCM Mask */

#define SYSINFO_SYS_CONFIG_SRAM_ADDR_WIDTH_Pos                4                                                          /* SYSINFO SYS_CONFIG: SRAM_ADDR_WIDTH Positions */
#define SYSINFO_SYS_CONFIG_SRAM_ADDR_WIDTH_Msk                (0x1FUL  << SYSINFO_SYS_CONFIG_SRAM_ADDR_WIDTH_Pos)                 /* SYSINFO SYS_CONFIG: SRAM_ADDR_WIDTH Mask */

#define SYSINFO_SYS_CONFIG_SRAM_NUM_BANK_Pos                0                                                          /* SYSINFO SYS_CONFIG: SRAM_NUM_BANK Positions */
#define SYSINFO_SYS_CONFIG_SRAM_NUM_BANK_Msk                (0xFUL  /*<< SYSINFO_SYS_CONFIG_SRAM_NUM_BANK_Pos*/)                 /* SYSINFO SYS_CONFIG: SRAM_NUM_BANK Mask */

/* SYSINFO PIDR4 Register Definitions */
#define SYSINFO_PIDR4_SIZE_Pos                4                                                          /* SYSINFO PIDR4: SIZE Positions */
#define SYSINFO_PIDR4_SIZE_Msk                (0xFUL  << SYSINFO_PIDR4_SIZE_Pos)                 /* SYSINFO PIDR4: SIZE Mask */

#define SYSINFO_PIDR4_DES_2_Pos                0                                                          /* SYSINFO PIDR4: DES_2 Positions */
#define SYSINFO_PIDR4_DES_2_Msk                (0xFUL  /*<< SYSINFO_PIDR4_DES_2_Pos*/)                 /* SYSINFO PIDR4: DES_2 Mask */

/* SYSINFO PIDR0 Register Definitions */
#define SYSINFO_PIDR0_PART_0_Pos                0                                                          /* SYSINFO PIDR0: PART_0 Positions */
#define SYSINFO_PIDR0_PART_0_Msk                (0xFFUL  /*<< SYSINFO_PIDR0_PART_0_Pos*/)                 /* SYSINFO PIDR0: PART_0 Mask */

/* SYSINFO PIDR1 Register Definitions */
#define SYSINFO_PIDR1_DES_0_Pos                4                                                          /* SYSINFO PIDR1: DES_0 Positions */
#define SYSINFO_PIDR1_DES_0_Msk                (0xFUL  << SYSINFO_PIDR1_DES_0_Pos)                 /* SYSINFO PIDR1: DES_0 Mask */

#define SYSINFO_PIDR1_PART_1_Pos                0                                                          /* SYSINFO PIDR1: PART_1 Positions */
#define SYSINFO_PIDR1_PART_1_Msk                (0xFUL  /*<< SYSINFO_PIDR1_PART_1_Pos*/)                 /* SYSINFO PIDR1: PART_1 Mask */

/* SYSINFO PIDR2 Register Definitions */
#define SYSINFO_PIDR2_REVISION_Pos                4                                                          /* SYSINFO PIDR2: REVISION Positions */
#define SYSINFO_PIDR2_REVISION_Msk                (0xFUL  << SYSINFO_PIDR2_REVISION_Pos)                 /* SYSINFO PIDR2: REVISION Mask */

#define SYSINFO_PIDR2_JEDEC_Pos                3                                                          /* SYSINFO PIDR2: JEDEC Positions */
#define SYSINFO_PIDR2_JEDEC_Msk                (0x1UL  << SYSINFO_PIDR2_JEDEC_Pos)                 /* SYSINFO PIDR2: JEDEC Mask */

#define SYSINFO_PIDR2_DES_1_Pos                0                                                          /* SYSINFO PIDR2: DES_1 Positions */
#define SYSINFO_PIDR2_DES_1_Msk                (0x7UL  /*<< SYSINFO_PIDR2_DES_1_Pos*/)                 /* SYSINFO PIDR2: DES_1 Mask */

/* SYSINFO PIDR3 Register Definitions */
#define SYSINFO_PIDR3_REVAND_Pos                4                                                          /* SYSINFO PIDR3: REVAND Positions */
#define SYSINFO_PIDR3_REVAND_Msk                (0xFUL  << SYSINFO_PIDR3_REVAND_Pos)                 /* SYSINFO PIDR3: REVAND Mask */

#define SYSINFO_PIDR3_CMOD_Pos                0                                                          /* SYSINFO PIDR3: CMOD Positions */
#define SYSINFO_PIDR3_CMOD_Msk                (0xFUL  /*<< SYSINFO_PIDR3_CMOD_Pos*/)                 /* SYSINFO PIDR3: CMOD Mask */

/* SYSINFO CIDR0 Register Definitions */
#define SYSINFO_CIDR0_PRMBL_0_Pos                0                                                          /* SYSINFO CIDR0: PRMBL_0 Positions */
#define SYSINFO_CIDR0_PRMBL_0_Msk                (0xFFUL  /*<< SYSINFO_CIDR0_PRMBL_0_Pos*/)                 /* SYSINFO CIDR0: PRMBL_0 Mask */

/* SYSINFO CIDR1 Register Definitions */
#define SYSINFO_CIDR1_CLASS_Pos                4                                                          /* SYSINFO CIDR1: CLASS Positions */
#define SYSINFO_CIDR1_CLASS_Msk                (0xFUL  << SYSINFO_CIDR1_CLASS_Pos)                 /* SYSINFO CIDR1: CLASS Mask */

#define SYSINFO_CIDR1_PRMBL_1_Pos                0                                                          /* SYSINFO CIDR1: PRMBL_1 Positions */
#define SYSINFO_CIDR1_PRMBL_1_Msk                (0xFUL  /*<< SYSINFO_CIDR1_PRMBL_1_Pos*/)                 /* SYSINFO CIDR1: PRMBL_1 Mask */

/* SYSINFO CIDR2 Register Definitions */
#define SYSINFO_CIDR2_PRMBL_2_Pos                0                                                          /* SYSINFO CIDR2: PRMBL_2 Positions */
#define SYSINFO_CIDR2_PRMBL_2_Msk                (0xFFUL  /*<< SYSINFO_CIDR2_PRMBL_2_Pos*/)                 /* SYSINFO CIDR2: PRMBL_2 Mask */

/* SYSINFO CIDR3 Register Definitions */
#define SYSINFO_CIDR3_PRMBL_3_Pos                0                                                          /* SYSINFO CIDR3: PRMBL_3 Positions */
#define SYSINFO_CIDR3_PRMBL_3_Msk                (0xFFUL  /*<< SYSINFO_CIDR3_PRMBL_3_Pos*/)                 /* SYSINFO CIDR3: PRMBL_3 Mask */


/*------------------- Watchdog ----------------------------------------------*/
typedef struct
{

  __IOM  uint32_t  LOAD;                    /* Offset: 0x000 (R/W) Watchdog Load Register */
  __IM   uint32_t  VALUE;                   /* Offset: 0x004 (R/ ) Watchdog Value Register */
  __IOM  uint32_t  CTRL;                    /* Offset: 0x008 (R/W) Watchdog Control Register */
  __OM   uint32_t  INTCLR;                  /* Offset: 0x00C ( /W) Watchdog Clear Interrupt Register */
  __IM   uint32_t  RAWINTSTAT;              /* Offset: 0x010 (R/ ) Watchdog Raw Interrupt Status Register */
  __IM   uint32_t  MASKINTSTAT;             /* Offset: 0x014 (R/ ) Watchdog Interrupt Status Register */
  __IOM  uint32_t  PRESCALE;                    /* Offset: 0x018 (R/W) Watchdog Prescale Register */
         uint32_t  RESERVED0[761];
  __IOM  uint32_t  LOCK;                    /* Offset: 0xC00 (R/W) Watchdog Lock Register */
         uint32_t  RESERVED1[191];
  __IOM  uint32_t  ITCR;                    /* Offset: 0xF00 (R/W) Watchdog Integration Test Control Register */
  __OM   uint32_t  ITOP;                    /* Offset: 0xF04 ( /W) Watchdog Integration Test Output Set Register */
}CMSDK_WATCHDOG_TypeDef;

/* CMSDK_WATCHDOG LOAD Register Definitions */
#define CMSDK_Watchdog_LOAD_Pos               0                                                /* CMSDK_Watchdog LOAD: LOAD Position */
#define CMSDK_Watchdog_LOAD_Msk              (0xFFFFFFFFUL /*<< CMSDK_Watchdog_LOAD_Pos*/)     /* CMSDK_Watchdog LOAD: LOAD Mask */

/* CMSDK_WATCHDOG VALUE Register Definitions */
#define CMSDK_Watchdog_VALUE_Pos              0                                                /* CMSDK_Watchdog VALUE: VALUE Position */
#define CMSDK_Watchdog_VALUE_Msk             (0xFFFFFFFFUL /*<< CMSDK_Watchdog_VALUE_Pos*/)    /* CMSDK_Watchdog VALUE: VALUE Mask */

/* CMSDK_WATCHDOG CTRL Register Definitions */
#define CMSDK_Watchdog_CTRL_RESEN_Pos         1                                                /* CMSDK_Watchdog CTRL_RESEN: Enable Reset Output Position */
#define CMSDK_Watchdog_CTRL_RESEN_Msk        (0x1UL << CMSDK_Watchdog_CTRL_RESEN_Pos)          /* CMSDK_Watchdog CTRL_RESEN: Enable Reset Output Mask */

#define CMSDK_Watchdog_CTRL_INTEN_Pos         0                                                /* CMSDK_Watchdog CTRL_INTEN: Int Enable Position */
#define CMSDK_Watchdog_CTRL_INTEN_Msk        (0x1UL /*<< CMSDK_Watchdog_CTRL_INTEN_Pos*/)      /* CMSDK_Watchdog CTRL_INTEN: Int Enable Mask */

/* CMSDK_WATCHDOG INTCLR Register Definitions */
#define CMSDK_Watchdog_INTCLR_Pos             0                                                /* CMSDK_Watchdog INTCLR: Int Clear Position */
#define CMSDK_Watchdog_INTCLR_Msk            (0x1UL /*<< CMSDK_Watchdog_INTCLR_Pos*/)          /* CMSDK_Watchdog INTCLR: Int Clear Mask */

/* CMSDK_WATCHDOG RAWINTSTAT Register Definitions */
#define CMSDK_Watchdog_RAWINTSTAT_Pos         0                                                /* CMSDK_Watchdog RAWINTSTAT: Raw Int Status Position */
#define CMSDK_Watchdog_RAWINTSTAT_Msk        (0x1UL /*<< CMSDK_Watchdog_RAWINTSTAT_Pos*/)      /* CMSDK_Watchdog RAWINTSTAT: Raw Int Status Mask */

/* CMSDK_WATCHDOG MASKINTSTAT Register Definitions */
#define CMSDK_Watchdog_MASKINTSTAT_Pos        0                                                /* CMSDK_Watchdog MASKINTSTAT: Mask Int Status Position */
#define CMSDK_Watchdog_MASKINTSTAT_Msk       (0x1UL /*<< CMSDK_Watchdog_MASKINTSTAT_Pos*/)     /* CMSDK_Watchdog MASKINTSTAT: Mask Int Status Mask */

/* CMSDK_WATCHDOG LOCK Register Definitions */
#define CMSDK_Watchdog_LOCK_Pos               0                                                /* CMSDK_Watchdog LOCK: LOCK Position */
#define CMSDK_Watchdog_LOCK_Msk              (0x1UL /*<< CMSDK_Watchdog_LOCK_Pos*/)            /* CMSDK_Watchdog LOCK: LOCK Mask */

/* CMSDK_WATCHDOG INTEGTESTEN Register Definitions */
#define CMSDK_Watchdog_INTEGTESTEN_Pos        0                                                /* CMSDK_Watchdog INTEGTESTEN: Integration Test Enable Position */
#define CMSDK_Watchdog_INTEGTESTEN_Msk       (0x1UL /*<< CMSDK_Watchdog_INTEGTESTEN_Pos*/)     /* CMSDK_Watchdog INTEGTESTEN: Integration Test Enable Mask */

/* CMSDK_WATCHDOG INTEGTESTOUTSET Register Definitions */
#define CMSDK_Watchdog_INTEGTESTOUTSET_Pos    1                                                /* CMSDK_Watchdog INTEGTESTOUTSET: Integration Test Output Set Position */
#define CMSDK_Watchdog_INTEGTESTOUTSET_Msk   (0x1UL /*<< CMSDK_Watchdog_INTEGTESTOUTSET_Pos*/) /* CMSDK_Watchdog INTEGTESTOUTSET: Integration Test Output Set Mask */

/* CMSDK_WATCHDOG PRESCALE Register Definitions */
#define CMSDK_Watchdog_PRESCALE_PRESCALE_Pos         0                                                /* CMSDK_Watchdog PRESCALE_PRESCALE: Enable Reset Output Position */
#define CMSDK_Watchdog_PRESCALE_PRESCALE_Msk        (0x7UL << CMSDK_Watchdog_PRESCALE_PRESCALE_Pos)   /* CMSDK_Watchdog PRESCALE_PRESCALE: Enable Reset Output Mask */

/*------------------- Power Policy Unit ----------------------------------------------*/
typedef struct {
    __IO uint32_t PWPR;              // Offset: 0x000 (R/W) Power Policy Register
    __IO uint32_t PMER;              // Offset: 0x004 (R/W) Power Mode Emulation Register
    __I  uint32_t PWSR;              // Offset: 0x008 (R/ ) Power Status Register
    __I  uint32_t SCSR;              // Offset: 0x00C (R/ ) Static Configuration Status Register - REMOVED because it was redundant, same info as in IDR0
    __I  uint32_t DISR;              // Offset: 0x010 (R/ ) Device Interface Input Current Status Register
    __I  uint32_t MISR;              // Offset: 0x014 (R/ ) Miscellaneous Input Current Status Register
    __I  uint32_t STSR;              // Offset: 0x018 (R/ ) Stored Status Register
    __O  uint32_t UNLK;              // Offset: 0x01C ( /W) OFF and MEM_RET Unlock register
    __IO uint32_t PWCR;              // Offset: 0x020 (R/W) Power Configuration Register
    __IO uint32_t PTCR;              // Offset: 0x024 (R/W) Power Mode Transition Configuration Register
         uint32_t RES0[2];           // Reserved

    __IO uint32_t IMR;               // Offset: 0x030 (R/W) Interrupt Mask Register
    __IO uint32_t AIMR;              // Offset: 0x034 (R/W) Additional Interrupt Mask Register
    __IO uint32_t ISR;               // Offset: 0x038 (R/W) Interrupt Status Register
    __IO uint32_t AISR;              // Offset: 0x03C (R/W) Additional Interrupt Status Register
    __IO uint32_t IESR;              // Offset: 0x040 (R/W) Input Edge Sensitivity Register
         uint32_t RES1[3];           // Reserved

    __IO uint32_t FUNRR;             // Offset: 0x050 (R/W) Functional Retention RAM Configuration Register
    __IO uint32_t FULRR;             // Offset: 0x054 (R/W) Full Retention RAM Configuration Register
    __IO uint32_t MEMRR;             // Offset: 0x058 (R/W) Memory Retention RAM Configuration Register
         uint32_t RES2[65];          // Reserved

    __IO uint32_t EDTR0;             // Offset: 0x160 (R/W) Mode Entry Delay Time Register 0
    __IO uint32_t EDTR1;             // Offset: 0x164 (R/W) Mode Entry Delay Time Register 1
         uint32_t RES3[2];           // Reserved

    __IO uint32_t DCCR0;             // Offset: 0x170 (R/W) Device Control Delay Configuration Register 0
    __IO uint32_t DCCR1;             // Offset: 0x174 (R/W) Device Control Delay Configuration Register 1
         uint32_t RES4[910];         // Reserved

    __I  uint32_t IDR0;              // Offset: 0xFB0 (R/ ) PPU Identification Register 0
    __I  uint32_t IDR1;              // Offset: 0xFB4 (R/ ) PPU Identification Register 1
         uint32_t RES5[4];           // Reserved

    __I  uint32_t IIDR;              // Offset: 0xFC8 (R/ ) Implementation Identification Register
    __I  uint32_t AIDR;              // Offset: 0xFCC (R/ ) Architecture Identification Register

    __I  uint32_t PID4;              // Offset: 0xFD0 (R/ ) Peripheral ID Register 4
    __I  uint32_t PID5;              // Offset: 0xFD4 (R/0) Peripheral ID Register 5 - Reserved
    __I  uint32_t PID6;              // Offset: 0xFD8 (R/0) Peripheral ID Register 6 - Reserved
    __I  uint32_t PID7;              // Offset: 0xFDC (R/0) Peripheral ID Register 7 - Reserved
    __I  uint32_t PID0;              // Offset: 0xFE0 (R/ ) Peripheral ID Register 0
    __I  uint32_t PID1;              // Offset: 0xFE4 (R/ ) Peripheral ID Register 1
    __I  uint32_t PID2;              // Offset: 0xFE8 (R/ ) Peripheral ID Register 2
    __I  uint32_t PID3;              // Offset: 0xFEC (R/0) Peripheral ID Register 3 - Reserved

    __I  uint32_t CID0;              // Offset: 0xFF0 (R/ ) Component  ID Register 0
    __I  uint32_t CID1;              // Offset: 0xFF4 (R/ ) Component  ID Register 1
    __I  uint32_t CID2;              // Offset: 0xFF8 (R/ ) Component  ID Register 2
    __I  uint32_t CID3;              // Offset: 0xFFC (R/ ) Component  ID Register 3
} PPU_TypeDef;

typedef struct {
    __I  uint32_t CPUID;
         uint32_t RES0[1011];
    __I  uint32_t PID4;              // Offset: 0xFD0 (R/ ) Peripheral ID Register 4
    __I  uint32_t PID5;              // Offset: 0xFD4 (RAZ) Peripheral ID Register 5 - Reserved
    __I  uint32_t PID6;              // Offset: 0xFD8 (RAZ) Peripheral ID Register 6 - Reserved
    __I  uint32_t PID7;              // Offset: 0xFDC (RAZ) Peripheral ID Register 7 - Reserved
    __I  uint32_t PID0;              // Offset: 0xFE0 (R/ ) Peripheral ID Register 0
    __I  uint32_t PID1;              // Offset: 0xFE4 (R/ ) Peripheral ID Register 1
    __I  uint32_t PID2;              // Offset: 0xFE8 (R/ ) Peripheral ID Register 2
    __I  uint32_t PID3;              // Offset: 0xFEC (RAZ) Peripheral ID Register 3 - Reserved

    __I  uint32_t CID0;              // Offset: 0xFF0 (R/ ) Component  ID Register 0
    __I  uint32_t CID1;              // Offset: 0xFF4 (R/ ) Component  ID Register 1
    __I  uint32_t CID2;              // Offset: 0xFF8 (R/ ) Component  ID Register 2
    __I  uint32_t CID3;              // Offset: 0xFFC (R/ ) Component  ID Register 3
} CPU_Identity_TypeDef;




/* --------  End of section using anonymous unions and disabling warnings  -------- */
#if   defined (__CC_ARM)
  #pragma pop
#elif defined (__ICCARM__)
  /* leave anonymous unions enabled */
#elif (defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050))
  #pragma clang diagnostic pop
#elif defined (__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined (__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined (__TASKING__)
  #pragma warning restore
#elif defined (__CSMC__)
  /* anonymous unions are enabled by default */
#else
  #warning Not supported compiler type
#endif




/* ================================================================================ */
/* ================              Peripheral memory map             ================ */
/* ================================================================================ */
#ifdef SECURE_MODE
 /* Secure Peripheral and SRAM base address */
 #define CMSDK_FLASH_BASE        (0x10000000UL)
 #define CMSDK_SRAM_BASE         (0x30000000UL)
 #define MASTER_EXP_PORT_0_BASE  (0x38000000UL)
 #define SSE200_PERIPH_BASE      (0x50000000UL)

 #define CMSDK_RAM_BASE          (0x30000000UL)
 #define CMSDK_APB_BASE          (0x50000000UL)
 #define CMSDK_AHB_BASE          (0x50010000UL)

 #define MASTER_EXP_PORT_1_BASE  (0x50100000UL)


 #define RAM_WB_BASE             (0x70000000UL)
 #define RAM_WT_BASE             (0x90000000UL)
 #define DEVICE_SH_BASE          (0xB0000000UL)
 #define DEVICE_NSH_BASE         (0xD0000000UL)
#ifdef __ARMCC_VERSION
#define __secure_flash_size Image$$NS_USER_RRAM$$Base
#endif
#else
 /* Non-secure Peripheral and SRAM base address */
 #define CMSDK_FLASH_BASE        (0x00000000UL)
 #define CMSDK_SRAM_BASE         (0x20000000UL)
 #define MASTER_EXP_PORT_0_BASE  (0x28000000UL)
 #define SSE200_PERIPH_BASE      (0x40000000UL)

 #define CMSDK_RAM_BASE          (0x20000000UL)
 #define CMSDK_APB_BASE          (0x40000000UL)
 #define CMSDK_AHB_BASE          (0x40010000UL)

 #define MASTER_EXP_PORT_1_BASE  (0x40100000UL)

 #define RAM_WB_BASE             (0x60000000UL)
 #define RAM_WT_BASE             (0x80000000UL)
 #define DEVICE_SH_BASE          (0xA0000000UL)
 #define DEVICE_NSH_BASE         (0xC0000000UL)
#ifdef __ARMCC_VERSION
#define __secure_flash_size Load$$LR$$LR_NONSECURE$$Base
#endif
#endif

#define SSE200_PERIPH_NONSECURE_BASE      (0x40000000UL)

#define SYS_PPB_BASE            (0xE0000000UL)
#define SYS_VEND_BASE           (0xF0000000UL)

#define ROM_SIZE                 0x00010000UL
#define RRAM_BASE                (CMSDK_FLASH_BASE + ROM_SIZE)
extern uint32_t __secure_flash_size;
#define FLASH_SECURE_SIZE        ((uint32_t)&__secure_flash_size)
#define ROM_RRAM_SIZE            0x00090000UL
#define RAM_SECURE_SIZE          0x00004000UL
#define RAM_SIZE                 0x00040000UL
#define QSPI_SIZE                0x01000000UL
#define MPC_FLS_BASE             0x50114000UL
#define MPC_QSPI_BASE            0x50115000UL
#define MPC_RAM0_BASE            0x50083000UL
#define MPC_RAM1_BASE            0x50084000UL
#define MPC_RAM2_BASE            0x50085000UL
#define MPC_RAM3_BASE            0x50086000UL

/* APB peripherals */
#define CMSDK_TIMER0_BASE       (SSE200_PERIPH_BASE + 0x0000UL)
#define CMSDK_TIMER1_BASE       (SSE200_PERIPH_BASE + 0x1000UL)
#define CMSDK_DUALTIMER_BASE    (SSE200_PERIPH_BASE + 0x2000UL)
#define CMSDK_DUALTIMER_1_BASE  (CMSDK_DUALTIMER_BASE)
#define CMSDK_DUALTIMER_2_BASE  (CMSDK_DUALTIMER_BASE + 0x20UL)

#define CMSDK_TIMER0_NONSECURE_BASE       (SSE200_PERIPH_NONSECURE_BASE + 0x0000UL)
#define CMSDK_TIMER1_NONSECURE_BASE       (SSE200_PERIPH_NONSECURE_BASE + 0x1000UL)
#define CMSDK_DUALTIMER_NONSECURE_BASE    (SSE200_PERIPH_NONSECURE_BASE + 0x2000UL)
#define CMSDK_DUALTIMER_1_NONSECURE_BASE  (CMSDK_DUALTIMER_NONSECURE_BASE)
#define CMSDK_DUALTIMER_2_NONSECURE_BASE  (CMSDK_DUALTIMER_NONSECURE_BASE + 0x20UL)


#define SECURE_WATCHDOG_BASE    (0x50081000UL)
#define NONSECURE_WATCHDOG_BASE (0x40081000UL)

#define S32_WATCHDOG_BASE       (SSE200_PERIPH_BASE + 0x2E000UL)
#define S32_TIMER_BASE          (SSE200_PERIPH_BASE + 0x2F000UL)
#define S32_TIMER_NONSECURE_BASE          (SSE200_PERIPH_NONSECURE_BASE + 0x2F000UL)

#define SEC_PRIV_CTRL_BASE      0x50080000UL
#define NONSEC_PRIV_CTRL_BASE   0x40080000UL

/* AHB peripherals */
#define CMSDK_GPIO0_BASE        (SSE200_PERIPH_BASE + 0x100000UL)
#define CMSDK_GPIO1_BASE        (SSE200_PERIPH_BASE + 0x101000UL)
#define CMSDK_GPIO2_BASE        (SSE200_PERIPH_BASE + 0x102000UL)
#define CMSDK_GPIO3_BASE        (SSE200_PERIPH_BASE + 0x104000UL)

#define CMSDK_GPIO0_NONSECURE_BASE        (SSE200_PERIPH_NONSECURE_BASE + 0x100000UL)
#define CMSDK_GPIO1_NONSECURE_BASE        (SSE200_PERIPH_NONSECURE_BASE + 0x101000UL)
#define CMSDK_GPIO2_NONSECURE_BASE        (SSE200_PERIPH_NONSECURE_BASE + 0x102000UL)
#define CMSDK_GPIO3_NONSECURE_BASE        (SSE200_PERIPH_NONSECURE_BASE + 0x104000UL)

#define SYSINFO_BASE            (SSE200_PERIPH_BASE + 0x20000UL)
#define SYS_CTRL_BASE           0x50021000UL

#define MHU_0_BASE              (SSE200_PERIPH_BASE + 0x3000UL)
#define MHU_1_BASE              (SSE200_PERIPH_BASE + 0x4000UL)

/* Power Peripherals - Secure Privilege Access only*/
#define SYS_PPU_BASE            0x50022000
#define CPU0CORE_PPU_BASE       0x50023000
#define CPU0DBG_PPU_BASE        0x50024000
#define CPU1CORE_PPU_BASE       0x50025000
#define CPU1DBG_PPU_BASE        0x50026000
#define DBG_PPU_BASE            0x50029000
#define SRAM_BANK0_PPU_BASE     0x5002A000
#define SRAM_BANK1_PPU_BASE     0x5002B000
#define SRAM_BANK2_PPU_BASE     0x5002C000
#define SRAM_BANK3_PPU_BASE     0x5002D000
#define CRYPTO_PPU_BASE         0x50027000
#define CORDIO_PPU_BASE         0x50028000

#define CPU_IDENTITY_BASE       (SSE200_PERIPH_BASE + 0x1F000ul)
#define ICACHE_BASE             (SSE200_PERIPH_BASE + 0x10000ul)


/* ================================================================================ */
/* ================             Peripheral declaration             ================ */
/* ================================================================================ */

#define CMSDK_TIMER0            ((CMSDK_TIMER_TypeDef             *) CMSDK_TIMER0_BASE       )
#define CMSDK_TIMER1            ((CMSDK_TIMER_TypeDef             *) CMSDK_TIMER1_BASE       )
#define CMSDK_DUALTIMER         ((CMSDK_DUALTIMER_BOTH_TypeDef    *) CMSDK_DUALTIMER_BASE    )
#define CMSDK_DUALTIMER1        ((CMSDK_DUALTIMER_SINGLE_TypeDef  *) CMSDK_DUALTIMER_1_BASE  )
#define CMSDK_DUALTIMER2        ((CMSDK_DUALTIMER_SINGLE_TypeDef  *) CMSDK_DUALTIMER_2_BASE  )
#define SECURE_WATCHDOG         ((CMSDK_WATCHDOG_TypeDef          *) SECURE_WATCHDOG_BASE    )
#define NONSECURE_WATCHDOG      ((CMSDK_WATCHDOG_TypeDef          *) NONSECURE_WATCHDOG_BASE )
#define CMSDK_GPIO0             ((CMSDK_GPIO_TypeDef              *) CMSDK_GPIO0_BASE        )
#define CMSDK_GPIO1             ((CMSDK_GPIO_TypeDef              *) CMSDK_GPIO1_BASE        )
#define CMSDK_GPIO2             ((CMSDK_GPIO_TypeDef              *) CMSDK_GPIO2_BASE        )
#define CMSDK_GPIO3		((CMSDK_GPIO_TypeDef              *) CMSDK_GPIO3_BASE        )

#define CMSDK_TIMER0_NONSECURE            ((CMSDK_TIMER_TypeDef             *) CMSDK_TIMER0_NONSECURE_BASE       )
#define CMSDK_TIMER1_NONSECURE            ((CMSDK_TIMER_TypeDef             *) CMSDK_TIMER1_NONSECURE_BASE       )
#define CMSDK_DUALTIMER_NONSECURE         ((CMSDK_DUALTIMER_BOTH_TypeDef    *) CMSDK_DUALTIMER_NONSECURE_BASE    )
#define CMSDK_DUALTIMER1_NONSECURE        ((CMSDK_DUALTIMER_SINGLE_TypeDef  *) CMSDK_DUALTIMER_1_NONSECURE_BASE  )
#define CMSDK_DUALTIMER2_NONSECURE        ((CMSDK_DUALTIMER_SINGLE_TypeDef  *) CMSDK_DUALTIMER_2_NONSECURE_BASE  )
#define CMSDK_GPIO0_NONSECURE   ((CMSDK_GPIO_TypeDef              *) CMSDK_GPIO0_NONSECURE_BASE )
#define CMSDK_GPIO1_NONSECURE   ((CMSDK_GPIO_TypeDef              *) CMSDK_GPIO1_NONSECURE_BASE )
#define CMSDK_GPIO2_NONSECURE   ((CMSDK_GPIO_TypeDef              *) CMSDK_GPIO2_NONSECURE_BASE )
#define CMSDK_GPIO3_NONSECURE   ((CMSDK_GPIO_TypeDef              *) CMSDK_GPIO3_NONSECURE_BASE )

#define S32_TIMER               ((CMSDK_TIMER_TypeDef             *) S32_TIMER_BASE          )
#define S32_TIMER_NONSECURE     ((CMSDK_TIMER_TypeDef             *) S32_TIMER_NONSECURE_BASE )
#define S32_WATCHDOG            ((CMSDK_WATCHDOG_TypeDef          *) S32_WATCHDOG_BASE       )

#define SEC_CTRL_REG            ((SEC_PRIV_CTRL_TypeDef           *) SEC_PRIV_CTRL_BASE      )
#define NONSEC_CTRL_REG         ((NONSEC_PRIV_CTRL_TypeDef        *) NONSEC_PRIV_CTRL_BASE   )

#define SYSINFO                 ((SYSINFO_TypeDef                 *) SYSINFO_BASE            )
#define SYS_CTRL_REG            ((SYS_CTRL_REG_SSE200_TypeDef     *) SYS_CTRL_BASE           )

#define MPC_FLS                 ((MPC_TypeDef                     *) MPC_FLS_BASE            )
#define MPC_QSPI                ((MPC_TypeDef                     *) MPC_QSPI_BASE            )
#define MPC_RAM0                ((MPC_TypeDef                     *) MPC_RAM0_BASE           )
#define MPC_RAM1                ((MPC_TypeDef                     *) MPC_RAM1_BASE           )
#define MPC_RAM2                ((MPC_TypeDef                     *) MPC_RAM2_BASE           )
#define MPC_RAM3                ((MPC_TypeDef                     *) MPC_RAM3_BASE           )

#define MHU_0                   ((MHU_TypeDef                     *) MHU_0_BASE              )
#define MHU_1                   ((MHU_TypeDef                     *) MHU_1_BASE              )

#define SYS_PPU                 ((PPU_TypeDef                     *) SYS_PPU_BASE            )
#define CPU0CORE_PPU            ((PPU_TypeDef                     *) CPU0CORE_PPU_BASE       )
#define CPU1CORE_PPU            ((PPU_TypeDef                     *) CPU1CORE_PPU_BASE       )
#define CPU0DBG_PPU             ((PPU_TypeDef                     *) CPU0DBG_PPU_BASE        )
#define CPU1DBG_PPU             ((PPU_TypeDef                     *) CPU1DBG_PPU_BASE        )
#define DBG_PPU                 ((PPU_TypeDef                     *) DBG_PPU_BASE            )
#define SRAM_BANK0_PPU          ((PPU_TypeDef                     *) SRAM_BANK0_PPU_BASE     )
#define SRAM_BANK1_PPU          ((PPU_TypeDef                     *) SRAM_BANK1_PPU_BASE     )
#define SRAM_BANK2_PPU          ((PPU_TypeDef                     *) SRAM_BANK2_PPU_BASE     )
#define SRAM_BANK3_PPU          ((PPU_TypeDef                     *) SRAM_BANK3_PPU_BASE     )
#define CRYPTO_PPU              ((PPU_TypeDef                     *) CRYPTO_PPU_BASE         )
#define CORDIO_PPU              ((PPU_TypeDef                     *) CORDIO_PPU_BASE         )

#define CPU_IDENTITY            ((CPU_Identity_TypeDef            *) CPU_IDENTITY_BASE       )
#define ICACHE                  ((ICACHE_TypeDef                  *) ICACHE_BASE             )


/*----------------------------- MPC (AHB5 Memory Protection Controller) -------------------------------*/
/**
  * @brief AHB5 MPC Registers
  */
typedef struct
{
  __IO   uint32_t  CTRL;          /*!< Offset: 0x000 Control Register    (R/W) */
  __I    uint32_t  RSVD0[3];
  __I    uint32_t  BLK_MAX;       /*!< Offset: 0x010 Status Register (R/ ) */
  __I    uint32_t  BLK_CFG;       /*!< Offset: 0x014 Status Register (R/ ) */
  __IO   uint32_t  BLK_IDX;       /*!< Offset: 0x018 Control Register (R/W) */
  __IO   uint32_t  BLK_LUT;       /*!< Offset: 0x01C Control Register (R/W) */
  __I    uint32_t  INT_STAT;      /*!< Offset: 0x020 Status Register (R/ ) */
  __O    uint32_t  INT_CLEAR;     /*!< Offset: 0x024 Control Register ( /W) */
  __IO   uint32_t  INT_EN ;       /*!< Offset: 0x028 Control Register (R/W) */
  __I    uint32_t  INT_INFO1;     /*!< Offset: 0x02C Status Register (R/ ) */
  __I    uint32_t  INT_INFO2;     /*!< Offset: 0x030 Status Register (R/ ) */
  __I    uint32_t  RSVD1[999];
  __I    uint32_t  PIDR4;         /*!< Offset: 0xFD0 Status Register (R/ ) */
  __I    uint32_t  PIDR5;         /*!< Offset: 0xFD4 Status Register (R/ ) */
  __I    uint32_t  PIDR6;         /*!< Offset: 0xFD8 Status Register (R/ ) */
  __I    uint32_t  PIDR7;         /*!< Offset: 0xFDC Status Register (R/ ) */
  __I    uint32_t  PIDR0;         /*!< Offset: 0xFE0 Status Register (R/ ) */
  __I    uint32_t  PIDR1;         /*!< Offset: 0xFE4 Status Register (R/ ) */
  __I    uint32_t  PIDR2;         /*!< Offset: 0xFE8 Status Register (R/ ) */
  __I    uint32_t  PIDR3;         /*!< Offset: 0xFEC Status Register (R/ ) */
  __I    uint32_t  CIDR0;         /*!< Offset: 0xFF0 Status Register (R/ ) */
  __I    uint32_t  CIDR1;         /*!< Offset: 0xFF4 Status Register (R/ ) */
  __I    uint32_t  CIDR2;         /*!< Offset: 0xFF8 Status Register (R/ ) */
  __I    uint32_t  CIDR3;         /*!< Offset: 0xFFC Status Register (R/ ) */

} MPC_TypeDef;

/* MPC CTRL Register Definitions */
#define MPC_CTRL_CFG_SEC_RESP_Pos   4                                            /*!< MPC CTRL: CFG_SEC_RESP Position */
#define MPC_CTRL_CFG_SEC_RESP_Msk   (0x1ul << MPC_CTRL_CFG_SEC_RESP_Pos)         /*!< MPC CTRL: CFG_SEC_RESP Mask */

#define MPC_CTRL_DATA_INTERFACE_GATING_REQ_Pos       6                                                  /*!< MPC CTRL: DATA_INTERFACE_GATING_REQ Position */
#define MPC_CTRL_DATA_INTERFACE_GATING_REQ_Msk       (0x1ul << MPC_CTRL_DATA_INTERFACE_GATING_REQ_Pos)  /*!< MPC CTRL: DATA_INTERFACE_GATING_REQ Mask */

#define MPC_CTRL_DATA_INTERFACE_GATING_ACK_Pos       7                                                  /*!< MPC CTRL: DATA_INTERFACE_GATING_ACK Position */
#define MPC_CTRL_DATA_INTERFACE_GATING_ACK_Msk       (0x1ul << MPC_CTRL_DATA_INTERFACE_GATING_ACK_Pos)  /*!< MPC CTRL: DATA_INTERFACE_GATING_ACK Mask */

#define MPC_CTRL_AUTO_INCREMENT_Pos 8                                            /*!< MPC CTRL: AUTO_INCREMENT Position */
#define MPC_CTRL_AUTO_INCREMENT_Msk (0x1ul << MPC_CTRL_AUTO_INCREMENT_Pos)       /*!< MPC CTRL: AUTO_INCREMENT Mask */

#define MPC_CTRL_SEC_LOCK_Pos       31                                           /*!< MPC CTRL: SEC_LOCK Position */
#define MPC_CTRL_SEC_LOCK_Msk       (0x1ul << MPC_CTRL_SEC_LOCK_Pos)             /*!< MPC CTRL: SEC_LOCK Mask */

/* MPC INT_STAT Register Definitions */
#define MPC_INT_STAT_IRQ_TRIGGERED_Pos   0                                          /*!< MPC INT_STAT: IRQ_TRIGGERED Position */
#define MPC_INT_STAT_IRQ_TRIGGERED_Msk   (0x1ul << MPC_INT_STAT_IRQ_TRIGGERED_Pos)  /*!< MPC INT_STAT: IRQ_TRIGGERED Mask */

/* MPC INT_CLEAR Register Definitions */
#define MPC_INT_CLEAR_IRQ_CLEAR_Pos 0                                            /*!< MPC INT_CLEAR: IRQ_CLEAR Position */
#define MPC_INT_CLEAR_IRQ_CLEAR_Msk (0x1ul << MPC_INT_CLEAR_IRQ_CLEAR_Pos)       /*!< MPC INT_CLEAR: IRQ_CLEAR Mask */

/* MPC INT_EN Register Definitions */
#define MPC_INT_EN_IRQ_EN_Pos       0                                            /*!< MPC INT_EN: IRQ_EN Position */
#define MPC_INT_EN_IRQ_EN_Msk       (0x1ul << MPC_INT_EN_IRQ_EN_Pos)             /*!< MPC INT_EN: IRQ_EN Mask */

/* MPC INT_INFO2 Register Definitions */
#define MPC_INT_INFO2_HMASTER_Pos   0                                            /*!< MPC INT_INFO2: HMASTER Position */
#define MPC_INT_INFO2_HMASTER_Msk   (0xFFFFul << MPC_INT_INFO2_HMASTER_Pos)      /*!< MPC INT_INFO2: HMASTER Mask */

#define MPC_INT_INFO2_HNONSEC_Pos   16                                           /*!< MPC INT_INFO2: HNONSEC Position */
#define MPC_INT_INFO2_HNONSEC_Msk   (0x1ul << MPC_INT_INFO2_HNONSEC_Pos)         /*!< MPC INT_INFO2: HNONSEC Mask */

#define MPC_INT_INFO2_CFG_NS_Pos    17                                           /*!< MPC INT_INFO2: CFG_NS Position */
#define MPC_INT_INFO2_CFG_NS_Msk    (0x1ul << MPC_INT_INFO2_CFG_NS_Pos)          /*!< MPC INT_INFO2: CFG_NS Mask */

/* MPC INT_SET Register Definiton */
#define MPC_INT_SET_IRQ_SET_Pos     0                                            /*!< MPC INT_SET: IRQ_SET Position */
#define MPC_INT_SET_IRQ_SET_Msk     (0x1ul << MPC_INT_SET_IRQ_SET_Pos)           /*!< MPC INT_SET: IRQ_SET Mask */

/* MPC PIDR4 Register Definition */
#define MPC_PIDR4_JEP106_C_CODE_Pos 0                                            /*!< MPC PIDR4: JEP106_C_CODE Position */
#define MPC_PIDR4_JEP106_C_CODE_Msk (0xFul << MPC_PIDR4_JEP106_C_CODE_Pos)       /*!< MPC PIDR4: JEP106_C_CODE Mask */

#define MPC_PIDR4_BLK_COUNT_Pos     4                                            /*!< MPC PIDR4: BLK_COUNT Position */
#define MPC_PIDR4_BLK_COUNT_Msk     (0xFul << MPC_PIDR4_BLK_COUNT_Pos)           /*!< MPC PIDR4: BLK_COUNT Mask */

/* MPC PIDR0 Register Definition */
#define MPC_PIDR0_PART_NUM_Pos      0                                            /*!< MPC PIDR0: PART_NUM Position */
#define MPC_PIDR0_PART_NUM_Msk      (0xFFul << MPC_PIDR0_PART_NUM_Pos)           /*!< MPC PIDR0: PART_NUM Mask */

/* MPC PIDR1 Register Definition */
#define MPC_PIDR1_PART_NUM_Pos      0                                            /*!< MPC PIDR1: PART_NUM Position */
#define MPC_PIDR1_PART_NUM_Msk      (0xFul << MPC_PIDR1_PART_NUM_Pos)            /*!< MPC PIDR1: PART_NUM Mask */

#define MPC_PIDR1_JEP106_ID_3_0_Pos      4                                       /*!< MPC PIDR1: JEP106_ID_3_0 Position */
#define MPC_PIDR1_JEP106_ID_3_0_Msk      (0xFul << MPC_PIDR1_JEP106_ID_3_0_Pos)  /*!< MPC PIDR1: JEP106_ID_3_0 Mask */

/* MPC PIDR2 Register Definition*/
#define MPC_PIDR2_JEP106_ID_6_4_Pos      0                                       /*!< MPC PIDR1: JEP106_ID_6_4 Position */
#define MPC_PIDR2_JEP106_ID_6_4_Msk      (0x7ul << MPC_PIDR2_JEP106_ID_6_4_Pos)  /*!< MPC PIDR2: JEP106_ID_6_4 Mask */

#define MPC_PIDR2_JEDEC_Pos         3                                            /*!< MPC PIDR2: JEDEC Position */
#define MPC_PIDR2_JEDEC_Msk         (0x1ul << MPC_PIDR2_JEDEC_Pos)               /*!< MPC PIDR2: JEDEC Mask */

#define MPC_PIDR2_REV_Pos           4                                            /*!< MPC PIDR2: REV Position */
#define MPC_PIDR2_REV_Msk           (0xFul << MPC_PIDR2_REVISION_Pos)            /*!< MPC PIDR2: REV Mask */

/* MPC PIDR3 Register Definition */
#define MPC_PIDR3_CMOD_Pos          0                                            /*!< MPC PIDR3: CMOD Position */
#define MPC_PIDR3_CMOD_Msk          (0xFul << MPC_PIDR3_CMOD_Pos)                /*!< MPC PIDR3: CMOD Mask */

#define MPC_PIDR3_ECO_REV_Pos       4                                            /*!< MPC PIDR3: ECO_REV Position */
#define MPC_PIDR3_ECO_REV_Msk       (0xFul << MPC_PIDR3_ECO_REV_Pos)             /*!< MPC PIDR3: ECO_REV Mask */

/*@}*/ /* end of group MPC */

/*----------------------------- SECURE PRIVILEGE CONTROL REGISTER -------------------------------------------------*/
typedef struct
{
__IOM  uint32_t SPCSECCTRL;                  /* Offset: 0x0 (read-write) SPCSECCTRL Register    */
__IOM  uint32_t BUSWAIT;                  /* Offset: 0x4 (read-write) BUSWAIT Register    */
       uint32_t RESERVED0[2];
__IOM  uint32_t SECRESPCFG;                  /* Offset: 0x10 (read-write) SECRESPCFG Register    */
__IOM  uint32_t NSCCFG;                  /* Offset: 0x14 (read-write) NSCCFG Register    */
       uint32_t RESERVED1[1];
__IM   uint32_t SECMPCINTSTATUS;                  /* Offset: 0x1C (read-only) SECMPCINTSTATUS Register    */
__IM   uint32_t SECPPCINTSTAT;                  /* Offset: 0x20 (read-only) SECPPCINTSTAT Register    */
__OM   uint32_t SECPPCINTCLR;                  /* Offset: 0x24 (write-only) SECPPCINTCLR Register    */
__IOM  uint32_t SECPPCINTEN;                  /* Offset: 0x28 (read-write) SECPPCINTEN Register    */
       uint32_t RESERVED2[1];
__IM   uint32_t SECMSCINTSTAT;                  /* Offset: 0x30 (read-only) SECMSCINTSTAT Register    */
__OM   uint32_t SECMSCINTCLR;                  /* Offset: 0x34 (write-only) SECMSCINTCLR Register    */
__IOM  uint32_t SECMSCINTEN;                  /* Offset: 0x38 (read-write) SECMSCINTEN Register    */
       uint32_t RESERVED3[1];
__IM   uint32_t BRGINTSTAT;                  /* Offset: 0x40 (read-only) BRGINTSTAT Register    */
__OM   uint32_t BRGINTCLR;                  /* Offset: 0x44 (write-only) BRGINTCLR Register    */
__IOM  uint32_t BRGINTEN;                  /* Offset: 0x48 (read-write) BRGINTEN Register    */
       uint32_t RESERVED4[5];
__IOM  uint32_t AHBNSPPCEXP0;                  /* Offset: 0x60 (read-write) AHBNSPPCEXP0 Register    */
__IOM  uint32_t AHBNSPPCEXP1;                  /* Offset: 0x64 (read-write) AHBNSPPCEXP1 Register    */
__IOM  uint32_t AHBNSPPCEXP2;                  /* Offset: 0x68 (read-write) AHBNSPPCEXP2 Register    */
__IOM  uint32_t AHBNSPPCEXP3;                  /* Offset: 0x6C (read-write) AHBNSPPCEXP3 Register    */
__IOM  uint32_t APBNSPPC0;                  /* Offset: 0x70 (read-write) APBNSPPC0 Register    */
__IOM  uint32_t APBNSPPC1;                  /* Offset: 0x74 (read-write) APBNSPPC1 Register    */
       uint32_t RESERVED5[2];
__IOM  uint32_t APBNSPPCEXP0;                  /* Offset: 0x80 (read-write) APBNSPPCEXP0 Register    */
__IOM  uint32_t APBNSPPCEXP1;                  /* Offset: 0x84 (read-write) APBNSPPCEXP1 Register    */
__IOM  uint32_t APBNSPPCEXP2;                  /* Offset: 0x88 (read-write) APBNSPPCEXP2 Register    */
__IOM  uint32_t APBNSPPCEXP3;                  /* Offset: 0x8C (read-write) APBNSPPCEXP3 Register    */
       uint32_t RESERVED6[4];
__IOM  uint32_t AHBSPPPCEXP0;                  /* Offset: 0xA0 (read-write) AHBSPPPCEXP0 Register    */
__IOM  uint32_t AHBSPPPCEXP1;                  /* Offset: 0xA4 (read-write) AHBSPPPCEXP1 Register    */
__IOM  uint32_t AHBSPPPCEXP2;                  /* Offset: 0xA8 (read-write) AHBSPPPCEXP2 Register    */
__IOM  uint32_t AHBSPPPCEXP3;                  /* Offset: 0xAC (read-write) AHBSPPPCEXP3 Register    */
__IOM  uint32_t APBSPPPC0;                  /* Offset: 0xB0 (read-write) APBSPPPC0 Register    */
__IOM  uint32_t APBSPPPC1;                  /* Offset: 0xB4 (read-write) APBSPPPC1 Register    */
       uint32_t RESERVED7[2];
__IOM  uint32_t APBSPPPCEXP0;                  /* Offset: 0xC0 (read-write) APBSPPPCEXP0 Register    */
__IOM  uint32_t APBSPPPCEXP1;                  /* Offset: 0xC4 (read-write) APBSPPPCEXP1 Register    */
__IOM  uint32_t APBSPPPCEXP2;                  /* Offset: 0xC8 (read-write) APBSPPPCEXP2 Register    */
__IOM  uint32_t APBSPPPCEXP3;                  /* Offset: 0xCC (read-write) APBSPPPCEXP3 Register    */
__IOM  uint32_t NSMSCEXP;                  /* Offset: 0xD0 (read-write) NSMSCEXP Register    */
       uint32_t RESERVED8[959];
__IM   uint32_t PIDR4;                  /* Offset: 0xFD0 (read-only) PIDR4 Register    */
       uint32_t RESERVED9[3];
__IM   uint32_t PIDR0;                  /* Offset: 0xFE0 (read-only) PIDR0 Register    */
__IM   uint32_t PIDR1;                  /* Offset: 0xFE4 (read-only) PIDR1 Register    */
__IM   uint32_t PIDR2;                  /* Offset: 0xFE8 (read-only) PIDR2 Register    */
__IM   uint32_t PIDR3;                  /* Offset: 0xFEC (read-only) PIDR3 Register    */
__IM   uint32_t CIDR0;                  /* Offset: 0xFF0 (read-only) CIDR0 Register    */
__IM   uint32_t CIDR1;                  /* Offset: 0xFF4 (read-only) CIDR1 Register    */
__IM   uint32_t CIDR2;                  /* Offset: 0xFF8 (read-only) CIDR2 Register    */
__IM   uint32_t CIDR3;                  /* Offset: 0xFFC (read-only) CIDR3 Register    */
}SEC_PRIV_CTRL_TypeDef;

/* SEC_PRIV_CTRL SPCSECCTRL Register Definitions */
#define SEC_PRIV_CTRL_SPCSECCTRL_SPCSECCFGLOCK_Pos                0                                                          /* SEC_PRIV_CTRL SPCSECCTRL: SPCSECCFGLOCK Positions */
#define SEC_PRIV_CTRL_SPCSECCTRL_SPCSECCFGLOCK_Msk                (0x1UL  /*<< SEC_PRIV_CTRL_SPCSECCTRL_SPCSECCFGLOCK_Pos*/)                 /* SEC_PRIV_CTRL SPCSECCTRL: SPCSECCFGLOCK Mask */

/* SEC_PRIV_CTRL BUSWAIT Register Definitions */
#define SEC_PRIV_CTRL_BUSWAIT_ACC_WAITN_Pos                0                                                          /* SEC_PRIV_CTRL BUSWAIT: ACC_WAITN Positions */
#define SEC_PRIV_CTRL_BUSWAIT_ACC_WAITN_Msk                (0x1UL  /*<< SEC_PRIV_CTRL_BUSWAIT_ACC_WAITN_Pos*/)                 /* SEC_PRIV_CTRL BUSWAIT: ACC_WAITN Mask */

/* SEC_PRIV_CTRL SECRESPCFG Register Definitions */
#define SEC_PRIV_CTRL_SECRESPCFG_SECRESPCFG_Pos                0                                                          /* SEC_PRIV_CTRL SECRESPCFG: SECRESPCFG Positions */
#define SEC_PRIV_CTRL_SECRESPCFG_SECRESPCFG_Msk                (0x1UL  /*<< SEC_PRIV_CTRL_SECRESPCFG_SECRESPCFG_Pos*/)                 /* SEC_PRIV_CTRL SECRESPCFG: SECRESPCFG Mask */

/* SEC_PRIV_CTRL NSCCFG Register Definitions */
#define SEC_PRIV_CTRL_NSCCFG_RAMNSC_Pos                1                                                          /* SEC_PRIV_CTRL NSCCFG: RAMNSC Positions */
#define SEC_PRIV_CTRL_NSCCFG_RAMNSC_Msk                (0x1UL  << SEC_PRIV_CTRL_NSCCFG_RAMNSC_Pos)                 /* SEC_PRIV_CTRL NSCCFG: RAMNSC Mask */

#define SEC_PRIV_CTRL_NSCCFG_CODENSC_Pos                0                                                          /* SEC_PRIV_CTRL NSCCFG: CODENSC Positions */
#define SEC_PRIV_CTRL_NSCCFG_CODENSC_Msk                (0x1UL  /*<< SEC_PRIV_CTRL_NSCCFG_CODENSC_Pos*/)                 /* SEC_PRIV_CTRL NSCCFG: CODENSC Mask */

/* SEC_PRIV_CTRL SECMPCINTSTATUS Register Definitions */
#define SEC_PRIV_CTRL_SECMPCINTSTATUS_S_MPCEXP_STATUS15_Pos                31                                                          /* SEC_PRIV_CTRL SECMPCINTSTATUS: S_MPCEXP_STATUS15 Positions */
#define SEC_PRIV_CTRL_SECMPCINTSTATUS_S_MPCEXP_STATUS15_Msk                (0x1UL  << SEC_PRIV_CTRL_SECMPCINTSTATUS_S_MPCEXP_STATUS15_Pos)                 /* SEC_PRIV_CTRL SECMPCINTSTATUS: S_MPCEXP_STATUS15 Mask */

#define SEC_PRIV_CTRL_SECMPCINTSTATUS_S_MPCEXP_STATUS14_Pos                30                                                          /* SEC_PRIV_CTRL SECMPCINTSTATUS: S_MPCEXP_STATUS14 Positions */
#define SEC_PRIV_CTRL_SECMPCINTSTATUS_S_MPCEXP_STATUS14_Msk                (0x1UL  << SEC_PRIV_CTRL_SECMPCINTSTATUS_S_MPCEXP_STATUS14_Pos)                 /* SEC_PRIV_CTRL SECMPCINTSTATUS: S_MPCEXP_STATUS14 Mask */

#define SEC_PRIV_CTRL_SECMPCINTSTATUS_S_MPCEXP_STATUS13_Pos                29                                                          /* SEC_PRIV_CTRL SECMPCINTSTATUS: S_MPCEXP_STATUS13 Positions */
#define SEC_PRIV_CTRL_SECMPCINTSTATUS_S_MPCEXP_STATUS13_Msk                (0x1UL  << SEC_PRIV_CTRL_SECMPCINTSTATUS_S_MPCEXP_STATUS13_Pos)                 /* SEC_PRIV_CTRL SECMPCINTSTATUS: S_MPCEXP_STATUS13 Mask */

#define SEC_PRIV_CTRL_SECMPCINTSTATUS_S_MPCEXP_STATUS12_Pos                28                                                          /* SEC_PRIV_CTRL SECMPCINTSTATUS: S_MPCEXP_STATUS12 Positions */
#define SEC_PRIV_CTRL_SECMPCINTSTATUS_S_MPCEXP_STATUS12_Msk                (0x1UL  << SEC_PRIV_CTRL_SECMPCINTSTATUS_S_MPCEXP_STATUS12_Pos)                 /* SEC_PRIV_CTRL SECMPCINTSTATUS: S_MPCEXP_STATUS12 Mask */

#define SEC_PRIV_CTRL_SECMPCINTSTATUS_S_MPCEXP_STATUS11_Pos                27                                                          /* SEC_PRIV_CTRL SECMPCINTSTATUS: S_MPCEXP_STATUS11 Positions */
#define SEC_PRIV_CTRL_SECMPCINTSTATUS_S_MPCEXP_STATUS11_Msk                (0x1UL  << SEC_PRIV_CTRL_SECMPCINTSTATUS_S_MPCEXP_STATUS11_Pos)                 /* SEC_PRIV_CTRL SECMPCINTSTATUS: S_MPCEXP_STATUS11 Mask */

#define SEC_PRIV_CTRL_SECMPCINTSTATUS_S_MPCEXP_STATUS10_Pos                26                                                          /* SEC_PRIV_CTRL SECMPCINTSTATUS: S_MPCEXP_STATUS10 Positions */
#define SEC_PRIV_CTRL_SECMPCINTSTATUS_S_MPCEXP_STATUS10_Msk                (0x1UL  << SEC_PRIV_CTRL_SECMPCINTSTATUS_S_MPCEXP_STATUS10_Pos)                 /* SEC_PRIV_CTRL SECMPCINTSTATUS: S_MPCEXP_STATUS10 Mask */

#define SEC_PRIV_CTRL_SECMPCINTSTATUS_S_MPCEXP_STATUS9_Pos                25                                                          /* SEC_PRIV_CTRL SECMPCINTSTATUS: S_MPCEXP_STATUS9 Positions */
#define SEC_PRIV_CTRL_SECMPCINTSTATUS_S_MPCEXP_STATUS9_Msk                (0x1UL  << SEC_PRIV_CTRL_SECMPCINTSTATUS_S_MPCEXP_STATUS9_Pos)                 /* SEC_PRIV_CTRL SECMPCINTSTATUS: S_MPCEXP_STATUS9 Mask */

#define SEC_PRIV_CTRL_SECMPCINTSTATUS_S_MPCEXP_STATUS8_Pos                24                                                          /* SEC_PRIV_CTRL SECMPCINTSTATUS: S_MPCEXP_STATUS8 Positions */
#define SEC_PRIV_CTRL_SECMPCINTSTATUS_S_MPCEXP_STATUS8_Msk                (0x1UL  << SEC_PRIV_CTRL_SECMPCINTSTATUS_S_MPCEXP_STATUS8_Pos)                 /* SEC_PRIV_CTRL SECMPCINTSTATUS: S_MPCEXP_STATUS8 Mask */

#define SEC_PRIV_CTRL_SECMPCINTSTATUS_S_MPCEXP_STATUS7_Pos                23                                                          /* SEC_PRIV_CTRL SECMPCINTSTATUS: S_MPCEXP_STATUS7 Positions */
#define SEC_PRIV_CTRL_SECMPCINTSTATUS_S_MPCEXP_STATUS7_Msk                (0x1UL  << SEC_PRIV_CTRL_SECMPCINTSTATUS_S_MPCEXP_STATUS7_Pos)                 /* SEC_PRIV_CTRL SECMPCINTSTATUS: S_MPCEXP_STATUS7 Mask */

#define SEC_PRIV_CTRL_SECMPCINTSTATUS_S_MPCEXP_STATUS6_Pos                22                                                          /* SEC_PRIV_CTRL SECMPCINTSTATUS: S_MPCEXP_STATUS6 Positions */
#define SEC_PRIV_CTRL_SECMPCINTSTATUS_S_MPCEXP_STATUS6_Msk                (0x1UL  << SEC_PRIV_CTRL_SECMPCINTSTATUS_S_MPCEXP_STATUS6_Pos)                 /* SEC_PRIV_CTRL SECMPCINTSTATUS: S_MPCEXP_STATUS6 Mask */

#define SEC_PRIV_CTRL_SECMPCINTSTATUS_S_MPCEXP_STATUS5_Pos                21                                                          /* SEC_PRIV_CTRL SECMPCINTSTATUS: S_MPCEXP_STATUS5 Positions */
#define SEC_PRIV_CTRL_SECMPCINTSTATUS_S_MPCEXP_STATUS5_Msk                (0x1UL  << SEC_PRIV_CTRL_SECMPCINTSTATUS_S_MPCEXP_STATUS5_Pos)                 /* SEC_PRIV_CTRL SECMPCINTSTATUS: S_MPCEXP_STATUS5 Mask */

#define SEC_PRIV_CTRL_SECMPCINTSTATUS_S_MPCEXP_STATUS4_Pos                20                                                          /* SEC_PRIV_CTRL SECMPCINTSTATUS: S_MPCEXP_STATUS4 Positions */
#define SEC_PRIV_CTRL_SECMPCINTSTATUS_S_MPCEXP_STATUS4_Msk                (0x1UL  << SEC_PRIV_CTRL_SECMPCINTSTATUS_S_MPCEXP_STATUS4_Pos)                 /* SEC_PRIV_CTRL SECMPCINTSTATUS: S_MPCEXP_STATUS4 Mask */

#define SEC_PRIV_CTRL_SECMPCINTSTATUS_S_MPCEXP_STATUS3_Pos                19                                                          /* SEC_PRIV_CTRL SECMPCINTSTATUS: S_MPCEXP_STATUS3 Positions */
#define SEC_PRIV_CTRL_SECMPCINTSTATUS_S_MPCEXP_STATUS3_Msk                (0x1UL  << SEC_PRIV_CTRL_SECMPCINTSTATUS_S_MPCEXP_STATUS3_Pos)                 /* SEC_PRIV_CTRL SECMPCINTSTATUS: S_MPCEXP_STATUS3 Mask */

#define SEC_PRIV_CTRL_SECMPCINTSTATUS_S_MPCEXP_STATUS2_Pos                18                                                          /* SEC_PRIV_CTRL SECMPCINTSTATUS: S_MPCEXP_STATUS2 Positions */
#define SEC_PRIV_CTRL_SECMPCINTSTATUS_S_MPCEXP_STATUS2_Msk                (0x1UL  << SEC_PRIV_CTRL_SECMPCINTSTATUS_S_MPCEXP_STATUS2_Pos)                 /* SEC_PRIV_CTRL SECMPCINTSTATUS: S_MPCEXP_STATUS2 Mask */

#define SEC_PRIV_CTRL_SECMPCINTSTATUS_S_MPCEXP_STATUS1_Pos                17                                                          /* SEC_PRIV_CTRL SECMPCINTSTATUS: S_MPCEXP_STATUS1 Positions */
#define SEC_PRIV_CTRL_SECMPCINTSTATUS_S_MPCEXP_STATUS1_Msk                (0x1UL  << SEC_PRIV_CTRL_SECMPCINTSTATUS_S_MPCEXP_STATUS1_Pos)                 /* SEC_PRIV_CTRL SECMPCINTSTATUS: S_MPCEXP_STATUS1 Mask */

#define SEC_PRIV_CTRL_SECMPCINTSTATUS_S_MPCEXP_STATUS0_Pos                16                                                          /* SEC_PRIV_CTRL SECMPCINTSTATUS: S_MPCEXP_STATUS0 Positions */
#define SEC_PRIV_CTRL_SECMPCINTSTATUS_S_MPCEXP_STATUS0_Msk                (0x1UL  << SEC_PRIV_CTRL_SECMPCINTSTATUS_S_MPCEXP_STATUS0_Pos)                 /* SEC_PRIV_CTRL SECMPCINTSTATUS: S_MPCEXP_STATUS0 Mask */

#define SEC_PRIV_CTRL_SECMPCINTSTATUS_S_MPCSRAM3_STATUS_Pos                3                                                          /* SEC_PRIV_CTRL SECMPCINTSTATUS: S_MPCSRAM3_STATUS Positions */
#define SEC_PRIV_CTRL_SECMPCINTSTATUS_S_MPCSRAM3_STATUS_Msk                (0x1UL  << SEC_PRIV_CTRL_SECMPCINTSTATUS_S_MPCSRAM3_STATUS_Pos)                 /* SEC_PRIV_CTRL SECMPCINTSTATUS: S_MPCSRAM3_STATUS Mask */

#define SEC_PRIV_CTRL_SECMPCINTSTATUS_S_MPCSRAM2_STATUS_Pos                2                                                          /* SEC_PRIV_CTRL SECMPCINTSTATUS: S_MPCSRAM2_STATUS Positions */
#define SEC_PRIV_CTRL_SECMPCINTSTATUS_S_MPCSRAM2_STATUS_Msk                (0x1UL  << SEC_PRIV_CTRL_SECMPCINTSTATUS_S_MPCSRAM2_STATUS_Pos)                 /* SEC_PRIV_CTRL SECMPCINTSTATUS: S_MPCSRAM2_STATUS Mask */

#define SEC_PRIV_CTRL_SECMPCINTSTATUS_S_MPCSRAM1_STATUS_Pos                1                                                          /* SEC_PRIV_CTRL SECMPCINTSTATUS: S_MPCSRAM1_STATUS Positions */
#define SEC_PRIV_CTRL_SECMPCINTSTATUS_S_MPCSRAM1_STATUS_Msk                (0x1UL  << SEC_PRIV_CTRL_SECMPCINTSTATUS_S_MPCSRAM1_STATUS_Pos)                 /* SEC_PRIV_CTRL SECMPCINTSTATUS: S_MPCSRAM1_STATUS Mask */

#define SEC_PRIV_CTRL_SECMPCINTSTATUS_S_MPCSRAM0_STATUS_Pos                0                                                          /* SEC_PRIV_CTRL SECMPCINTSTATUS: S_MPCSRAM0_STATUS Positions */
#define SEC_PRIV_CTRL_SECMPCINTSTATUS_S_MPCSRAM0_STATUS_Msk                (0x1UL  /*<< SEC_PRIV_CTRL_SECMPCINTSTATUS_S_MPCSRAM0_STATUS_Pos*/)                 /* SEC_PRIV_CTRL SECMPCINTSTATUS: S_MPCSRAM0_STATUS Mask */

/* SEC_PRIV_CTRL SECPPCINTSTAT Register Definitions */
#define SEC_PRIV_CTRL_SECPPCINTSTAT_S_AHBPPCEXP_STATUS_Pos                20                                                          /* SEC_PRIV_CTRL SECPPCINTSTAT: S_AHBPPCEXP_STATUS Positions */
#define SEC_PRIV_CTRL_SECPPCINTSTAT_S_AHBPPCEXP_STATUS_Msk                (0xFUL  << SEC_PRIV_CTRL_SECPPCINTSTAT_S_AHBPPCEXP_STATUS_Pos)                 /* SEC_PRIV_CTRL SECPPCINTSTAT: S_AHBPPCEXP_STATUS Mask */

#define SEC_PRIV_CTRL_SECPPCINTSTAT_S_APBPPCEXP_STATUS_Pos                4                                                          /* SEC_PRIV_CTRL SECPPCINTSTAT: S_APBPPCEXP_STATUS Positions */
#define SEC_PRIV_CTRL_SECPPCINTSTAT_S_APBPPCEXP_STATUS_Msk                (0xFUL  << SEC_PRIV_CTRL_SECPPCINTSTAT_S_APBPPCEXP_STATUS_Pos)                 /* SEC_PRIV_CTRL SECPPCINTSTAT: S_APBPPCEXP_STATUS Mask */

#define SEC_PRIV_CTRL_SECPPCINTSTAT_S_APBPPC1PERIP_STATUS_Pos                1                                                          /* SEC_PRIV_CTRL SECPPCINTSTAT: S_APBPPC1PERIP_STATUS Positions */
#define SEC_PRIV_CTRL_SECPPCINTSTAT_S_APBPPC1PERIP_STATUS_Msk                (0x1UL  << SEC_PRIV_CTRL_SECPPCINTSTAT_S_APBPPC1PERIP_STATUS_Pos)                 /* SEC_PRIV_CTRL SECPPCINTSTAT: S_APBPPC1PERIP_STATUS Mask */

#define SEC_PRIV_CTRL_SECPPCINTSTAT_S_APBPPC0PERIP_STATUS_Pos                0                                                          /* SEC_PRIV_CTRL SECPPCINTSTAT: S_APBPPC0PERIP_STATUS Positions */
#define SEC_PRIV_CTRL_SECPPCINTSTAT_S_APBPPC0PERIP_STATUS_Msk                (0x1UL  /*<< SEC_PRIV_CTRL_SECPPCINTSTAT_S_APBPPC0PERIP_STATUS_Pos*/)                 /* SEC_PRIV_CTRL SECPPCINTSTAT: S_APBPPC0PERIP_STATUS Mask */

/* SEC_PRIV_CTRL SECPPCINTCLR Register Definitions */
#define SEC_PRIV_CTRL_SECPPCINTCLR_S_AHBPPCEXP_CLR_Pos                20                                                          /* SEC_PRIV_CTRL SECPPCINTCLR: S_AHBPPCEXP_CLR Positions */
#define SEC_PRIV_CTRL_SECPPCINTCLR_S_AHBPPCEXP_CLR_Msk                (0xFUL  << SEC_PRIV_CTRL_SECPPCINTCLR_S_AHBPPCEXP_CLR_Pos)                 /* SEC_PRIV_CTRL SECPPCINTCLR: S_AHBPPCEXP_CLR Mask */

#define SEC_PRIV_CTRL_SECPPCINTCLR_S_APBPPCEXP_CLR_Pos                4                                                          /* SEC_PRIV_CTRL SECPPCINTCLR: S_APBPPCEXP_CLR Positions */
#define SEC_PRIV_CTRL_SECPPCINTCLR_S_APBPPCEXP_CLR_Msk                (0xFUL  << SEC_PRIV_CTRL_SECPPCINTCLR_S_APBPPCEXP_CLR_Pos)                 /* SEC_PRIV_CTRL SECPPCINTCLR: S_APBPPCEXP_CLR Mask */

#define SEC_PRIV_CTRL_SECPPCINTCLR_S_APBPPC1PERIP_CLR_Pos                1                                                          /* SEC_PRIV_CTRL SECPPCINTCLR: S_APBPPC1PERIP_CLR Positions */
#define SEC_PRIV_CTRL_SECPPCINTCLR_S_APBPPC1PERIP_CLR_Msk                (0x1UL  << SEC_PRIV_CTRL_SECPPCINTCLR_S_APBPPC1PERIP_CLR_Pos)                 /* SEC_PRIV_CTRL SECPPCINTCLR: S_APBPPC1PERIP_CLR Mask */

#define SEC_PRIV_CTRL_SECPPCINTCLR_S_APBPPC0PERIP_CLR_Pos                0                                                          /* SEC_PRIV_CTRL SECPPCINTCLR: S_APBPPC0PERIP_CLR Positions */
#define SEC_PRIV_CTRL_SECPPCINTCLR_S_APBPPC0PERIP_CLR_Msk                (0x1UL  /*<< SEC_PRIV_CTRL_SECPPCINTCLR_S_APBPPC0PERIP_CLR_Pos*/)                 /* SEC_PRIV_CTRL SECPPCINTCLR: S_APBPPC0PERIP_CLR Mask */

/* SEC_PRIV_CTRL SECPPCINTEN Register Definitions */
#define SEC_PRIV_CTRL_SECPPCINTEN_S_AHBPPCEXP_EN_Pos                20                                                          /* SEC_PRIV_CTRL SECPPCINTEN: S_AHBPPCEXP_EN Positions */
#define SEC_PRIV_CTRL_SECPPCINTEN_S_AHBPPCEXP_EN_Msk                (0xFUL  << SEC_PRIV_CTRL_SECPPCINTEN_S_AHBPPCEXP_EN_Pos)                 /* SEC_PRIV_CTRL SECPPCINTEN: S_AHBPPCEXP_EN Mask */

#define SEC_PRIV_CTRL_SECPPCINTEN_S_APBPPCEXP_EN_Pos                4                                                          /* SEC_PRIV_CTRL SECPPCINTEN: S_APBPPCEXP_EN Positions */
#define SEC_PRIV_CTRL_SECPPCINTEN_S_APBPPCEXP_EN_Msk                (0xFUL  << SEC_PRIV_CTRL_SECPPCINTEN_S_APBPPCEXP_EN_Pos)                 /* SEC_PRIV_CTRL SECPPCINTEN: S_APBPPCEXP_EN Mask */

#define SEC_PRIV_CTRL_SECPPCINTEN_S_APBPPC1PERIP_EN_Pos                1                                                          /* SEC_PRIV_CTRL SECPPCINTEN: S_APBPPC1PERIP_EN Positions */
#define SEC_PRIV_CTRL_SECPPCINTEN_S_APBPPC1PERIP_EN_Msk                (0x1UL  << SEC_PRIV_CTRL_SECPPCINTEN_S_APBPPC1PERIP_EN_Pos)                 /* SEC_PRIV_CTRL SECPPCINTEN: S_APBPPC1PERIP_EN Mask */

#define SEC_PRIV_CTRL_SECPPCINTEN_S_APBPPC0PERIP_EN_Pos                0                                                          /* SEC_PRIV_CTRL SECPPCINTEN: S_APBPPC0PERIP_EN Positions */
#define SEC_PRIV_CTRL_SECPPCINTEN_S_APBPPC0PERIP_EN_Msk                (0x1UL  /*<< SEC_PRIV_CTRL_SECPPCINTEN_S_APBPPC0PERIP_EN_Pos*/)                 /* SEC_PRIV_CTRL SECPPCINTEN: S_APBPPC0PERIP_EN Mask */

/* SEC_PRIV_CTRL SECMSCINTSTAT Register Definitions */
#define SEC_PRIV_CTRL_SECMSCINTSTAT_S_MSCEXP_STATUS15_Pos                31                                                          /* SEC_PRIV_CTRL SECMSCINTSTAT: S_MSCEXP_STATUS15 Positions */
#define SEC_PRIV_CTRL_SECMSCINTSTAT_S_MSCEXP_STATUS15_Msk                (0x1UL  << SEC_PRIV_CTRL_SECMSCINTSTAT_S_MSCEXP_STATUS15_Pos)                 /* SEC_PRIV_CTRL SECMSCINTSTAT: S_MSCEXP_STATUS15 Mask */

#define SEC_PRIV_CTRL_SECMSCINTSTAT_S_MSCEXP_STATUS14_Pos                30                                                          /* SEC_PRIV_CTRL SECMSCINTSTAT: S_MSCEXP_STATUS14 Positions */
#define SEC_PRIV_CTRL_SECMSCINTSTAT_S_MSCEXP_STATUS14_Msk                (0x1UL  << SEC_PRIV_CTRL_SECMSCINTSTAT_S_MSCEXP_STATUS14_Pos)                 /* SEC_PRIV_CTRL SECMSCINTSTAT: S_MSCEXP_STATUS14 Mask */

#define SEC_PRIV_CTRL_SECMSCINTSTAT_S_MSCEXP_STATUS13_Pos                29                                                          /* SEC_PRIV_CTRL SECMSCINTSTAT: S_MSCEXP_STATUS13 Positions */
#define SEC_PRIV_CTRL_SECMSCINTSTAT_S_MSCEXP_STATUS13_Msk                (0x1UL  << SEC_PRIV_CTRL_SECMSCINTSTAT_S_MSCEXP_STATUS13_Pos)                 /* SEC_PRIV_CTRL SECMSCINTSTAT: S_MSCEXP_STATUS13 Mask */

#define SEC_PRIV_CTRL_SECMSCINTSTAT_S_MSCEXP_STATUS12_Pos                28                                                          /* SEC_PRIV_CTRL SECMSCINTSTAT: S_MSCEXP_STATUS12 Positions */
#define SEC_PRIV_CTRL_SECMSCINTSTAT_S_MSCEXP_STATUS12_Msk                (0x1UL  << SEC_PRIV_CTRL_SECMSCINTSTAT_S_MSCEXP_STATUS12_Pos)                 /* SEC_PRIV_CTRL SECMSCINTSTAT: S_MSCEXP_STATUS12 Mask */

#define SEC_PRIV_CTRL_SECMSCINTSTAT_S_MSCEXP_STATUS11_Pos                27                                                          /* SEC_PRIV_CTRL SECMSCINTSTAT: S_MSCEXP_STATUS11 Positions */
#define SEC_PRIV_CTRL_SECMSCINTSTAT_S_MSCEXP_STATUS11_Msk                (0x1UL  << SEC_PRIV_CTRL_SECMSCINTSTAT_S_MSCEXP_STATUS11_Pos)                 /* SEC_PRIV_CTRL SECMSCINTSTAT: S_MSCEXP_STATUS11 Mask */

#define SEC_PRIV_CTRL_SECMSCINTSTAT_S_MSCEXP_STATUS10_Pos                26                                                          /* SEC_PRIV_CTRL SECMSCINTSTAT: S_MSCEXP_STATUS10 Positions */
#define SEC_PRIV_CTRL_SECMSCINTSTAT_S_MSCEXP_STATUS10_Msk                (0x1UL  << SEC_PRIV_CTRL_SECMSCINTSTAT_S_MSCEXP_STATUS10_Pos)                 /* SEC_PRIV_CTRL SECMSCINTSTAT: S_MSCEXP_STATUS10 Mask */

#define SEC_PRIV_CTRL_SECMSCINTSTAT_S_MSCEXP_STATUS9_Pos                25                                                          /* SEC_PRIV_CTRL SECMSCINTSTAT: S_MSCEXP_STATUS9 Positions */
#define SEC_PRIV_CTRL_SECMSCINTSTAT_S_MSCEXP_STATUS9_Msk                (0x1UL  << SEC_PRIV_CTRL_SECMSCINTSTAT_S_MSCEXP_STATUS9_Pos)                 /* SEC_PRIV_CTRL SECMSCINTSTAT: S_MSCEXP_STATUS9 Mask */

#define SEC_PRIV_CTRL_SECMSCINTSTAT_S_MSCEXP_STATUS8_Pos                24                                                          /* SEC_PRIV_CTRL SECMSCINTSTAT: S_MSCEXP_STATUS8 Positions */
#define SEC_PRIV_CTRL_SECMSCINTSTAT_S_MSCEXP_STATUS8_Msk                (0x1UL  << SEC_PRIV_CTRL_SECMSCINTSTAT_S_MSCEXP_STATUS8_Pos)                 /* SEC_PRIV_CTRL SECMSCINTSTAT: S_MSCEXP_STATUS8 Mask */

#define SEC_PRIV_CTRL_SECMSCINTSTAT_S_MSCEXP_STATUS7_Pos                23                                                          /* SEC_PRIV_CTRL SECMSCINTSTAT: S_MSCEXP_STATUS7 Positions */
#define SEC_PRIV_CTRL_SECMSCINTSTAT_S_MSCEXP_STATUS7_Msk                (0x1UL  << SEC_PRIV_CTRL_SECMSCINTSTAT_S_MSCEXP_STATUS7_Pos)                 /* SEC_PRIV_CTRL SECMSCINTSTAT: S_MSCEXP_STATUS7 Mask */

#define SEC_PRIV_CTRL_SECMSCINTSTAT_S_MSCEXP_STATUS6_Pos                22                                                          /* SEC_PRIV_CTRL SECMSCINTSTAT: S_MSCEXP_STATUS6 Positions */
#define SEC_PRIV_CTRL_SECMSCINTSTAT_S_MSCEXP_STATUS6_Msk                (0x1UL  << SEC_PRIV_CTRL_SECMSCINTSTAT_S_MSCEXP_STATUS6_Pos)                 /* SEC_PRIV_CTRL SECMSCINTSTAT: S_MSCEXP_STATUS6 Mask */

#define SEC_PRIV_CTRL_SECMSCINTSTAT_S_MSCEXP_STATUS5_Pos                21                                                          /* SEC_PRIV_CTRL SECMSCINTSTAT: S_MSCEXP_STATUS5 Positions */
#define SEC_PRIV_CTRL_SECMSCINTSTAT_S_MSCEXP_STATUS5_Msk                (0x1UL  << SEC_PRIV_CTRL_SECMSCINTSTAT_S_MSCEXP_STATUS5_Pos)                 /* SEC_PRIV_CTRL SECMSCINTSTAT: S_MSCEXP_STATUS5 Mask */

#define SEC_PRIV_CTRL_SECMSCINTSTAT_S_MSCEXP_STATUS4_Pos                20                                                          /* SEC_PRIV_CTRL SECMSCINTSTAT: S_MSCEXP_STATUS4 Positions */
#define SEC_PRIV_CTRL_SECMSCINTSTAT_S_MSCEXP_STATUS4_Msk                (0x1UL  << SEC_PRIV_CTRL_SECMSCINTSTAT_S_MSCEXP_STATUS4_Pos)                 /* SEC_PRIV_CTRL SECMSCINTSTAT: S_MSCEXP_STATUS4 Mask */

#define SEC_PRIV_CTRL_SECMSCINTSTAT_S_MSCEXP_STATUS3_Pos                19                                                          /* SEC_PRIV_CTRL SECMSCINTSTAT: S_MSCEXP_STATUS3 Positions */
#define SEC_PRIV_CTRL_SECMSCINTSTAT_S_MSCEXP_STATUS3_Msk                (0x1UL  << SEC_PRIV_CTRL_SECMSCINTSTAT_S_MSCEXP_STATUS3_Pos)                 /* SEC_PRIV_CTRL SECMSCINTSTAT: S_MSCEXP_STATUS3 Mask */

#define SEC_PRIV_CTRL_SECMSCINTSTAT_S_MSCEXP_STATUS2_Pos                18                                                          /* SEC_PRIV_CTRL SECMSCINTSTAT: S_MSCEXP_STATUS2 Positions */
#define SEC_PRIV_CTRL_SECMSCINTSTAT_S_MSCEXP_STATUS2_Msk                (0x1UL  << SEC_PRIV_CTRL_SECMSCINTSTAT_S_MSCEXP_STATUS2_Pos)                 /* SEC_PRIV_CTRL SECMSCINTSTAT: S_MSCEXP_STATUS2 Mask */

#define SEC_PRIV_CTRL_SECMSCINTSTAT_S_MSCEXP_STATUS1_Pos                17                                                          /* SEC_PRIV_CTRL SECMSCINTSTAT: S_MSCEXP_STATUS1 Positions */
#define SEC_PRIV_CTRL_SECMSCINTSTAT_S_MSCEXP_STATUS1_Msk                (0x1UL  << SEC_PRIV_CTRL_SECMSCINTSTAT_S_MSCEXP_STATUS1_Pos)                 /* SEC_PRIV_CTRL SECMSCINTSTAT: S_MSCEXP_STATUS1 Mask */

#define SEC_PRIV_CTRL_SECMSCINTSTAT_S_MSCEXP_STATUS0_Pos                16                                                          /* SEC_PRIV_CTRL SECMSCINTSTAT: S_MSCEXP_STATUS0 Positions */
#define SEC_PRIV_CTRL_SECMSCINTSTAT_S_MSCEXP_STATUS0_Msk                (0x1UL  << SEC_PRIV_CTRL_SECMSCINTSTAT_S_MSCEXP_STATUS0_Pos)                 /* SEC_PRIV_CTRL SECMSCINTSTAT: S_MSCEXP_STATUS0 Mask */

#define SEC_PRIV_CTRL_SECMSCINTSTAT_S_MSC_CRYPTO_STATUS_Pos                0                                                          /* SEC_PRIV_CTRL SECMSCINTSTAT: S_MSC_CRYPTO_STATUS Positions */
#define SEC_PRIV_CTRL_SECMSCINTSTAT_S_MSC_CRYPTO_STATUS_Msk                (0x1UL  /*<< SEC_PRIV_CTRL_SECMSCINTSTAT_S_MSC_CRYPTO_STATUS_Pos*/)                 /* SEC_PRIV_CTRL SECMSCINTSTAT: S_MSC_CRYPTO_STATUS Mask */

/* SEC_PRIV_CTRL SECMSCINTCLR Register Definitions */
#define SEC_PRIV_CTRL_SECMSCINTCLR_S_MSCEXP_CLR15_Pos                31                                                          /* SEC_PRIV_CTRL SECMSCINTCLR: S_MSCEXP_CLR15 Positions */
#define SEC_PRIV_CTRL_SECMSCINTCLR_S_MSCEXP_CLR15_Msk                (0x1UL  << SEC_PRIV_CTRL_SECMSCINTCLR_S_MSCEXP_CLR15_Pos)                 /* SEC_PRIV_CTRL SECMSCINTCLR: S_MSCEXP_CLR15 Mask */

#define SEC_PRIV_CTRL_SECMSCINTCLR_S_MSCEXP_CLR14_Pos                30                                                          /* SEC_PRIV_CTRL SECMSCINTCLR: S_MSCEXP_CLR14 Positions */
#define SEC_PRIV_CTRL_SECMSCINTCLR_S_MSCEXP_CLR14_Msk                (0x1UL  << SEC_PRIV_CTRL_SECMSCINTCLR_S_MSCEXP_CLR14_Pos)                 /* SEC_PRIV_CTRL SECMSCINTCLR: S_MSCEXP_CLR14 Mask */

#define SEC_PRIV_CTRL_SECMSCINTCLR_S_MSCEXP_CLR13_Pos                29                                                          /* SEC_PRIV_CTRL SECMSCINTCLR: S_MSCEXP_CLR13 Positions */
#define SEC_PRIV_CTRL_SECMSCINTCLR_S_MSCEXP_CLR13_Msk                (0x1UL  << SEC_PRIV_CTRL_SECMSCINTCLR_S_MSCEXP_CLR13_Pos)                 /* SEC_PRIV_CTRL SECMSCINTCLR: S_MSCEXP_CLR13 Mask */

#define SEC_PRIV_CTRL_SECMSCINTCLR_S_MSCEXP_CLR12_Pos                28                                                          /* SEC_PRIV_CTRL SECMSCINTCLR: S_MSCEXP_CLR12 Positions */
#define SEC_PRIV_CTRL_SECMSCINTCLR_S_MSCEXP_CLR12_Msk                (0x1UL  << SEC_PRIV_CTRL_SECMSCINTCLR_S_MSCEXP_CLR12_Pos)                 /* SEC_PRIV_CTRL SECMSCINTCLR: S_MSCEXP_CLR12 Mask */

#define SEC_PRIV_CTRL_SECMSCINTCLR_S_MSCEXP_CLR11_Pos                27                                                          /* SEC_PRIV_CTRL SECMSCINTCLR: S_MSCEXP_CLR11 Positions */
#define SEC_PRIV_CTRL_SECMSCINTCLR_S_MSCEXP_CLR11_Msk                (0x1UL  << SEC_PRIV_CTRL_SECMSCINTCLR_S_MSCEXP_CLR11_Pos)                 /* SEC_PRIV_CTRL SECMSCINTCLR: S_MSCEXP_CLR11 Mask */

#define SEC_PRIV_CTRL_SECMSCINTCLR_S_MSCEXP_CLR10_Pos                26                                                          /* SEC_PRIV_CTRL SECMSCINTCLR: S_MSCEXP_CLR10 Positions */
#define SEC_PRIV_CTRL_SECMSCINTCLR_S_MSCEXP_CLR10_Msk                (0x1UL  << SEC_PRIV_CTRL_SECMSCINTCLR_S_MSCEXP_CLR10_Pos)                 /* SEC_PRIV_CTRL SECMSCINTCLR: S_MSCEXP_CLR10 Mask */

#define SEC_PRIV_CTRL_SECMSCINTCLR_S_MSCEXP_CLR9_Pos                25                                                          /* SEC_PRIV_CTRL SECMSCINTCLR: S_MSCEXP_CLR9 Positions */
#define SEC_PRIV_CTRL_SECMSCINTCLR_S_MSCEXP_CLR9_Msk                (0x1UL  << SEC_PRIV_CTRL_SECMSCINTCLR_S_MSCEXP_CLR9_Pos)                 /* SEC_PRIV_CTRL SECMSCINTCLR: S_MSCEXP_CLR9 Mask */

#define SEC_PRIV_CTRL_SECMSCINTCLR_S_MSCEXP_CLR8_Pos                24                                                          /* SEC_PRIV_CTRL SECMSCINTCLR: S_MSCEXP_CLR8 Positions */
#define SEC_PRIV_CTRL_SECMSCINTCLR_S_MSCEXP_CLR8_Msk                (0x1UL  << SEC_PRIV_CTRL_SECMSCINTCLR_S_MSCEXP_CLR8_Pos)                 /* SEC_PRIV_CTRL SECMSCINTCLR: S_MSCEXP_CLR8 Mask */

#define SEC_PRIV_CTRL_SECMSCINTCLR_S_MSCEXP_CLR7_Pos                23                                                          /* SEC_PRIV_CTRL SECMSCINTCLR: S_MSCEXP_CLR7 Positions */
#define SEC_PRIV_CTRL_SECMSCINTCLR_S_MSCEXP_CLR7_Msk                (0x1UL  << SEC_PRIV_CTRL_SECMSCINTCLR_S_MSCEXP_CLR7_Pos)                 /* SEC_PRIV_CTRL SECMSCINTCLR: S_MSCEXP_CLR7 Mask */

#define SEC_PRIV_CTRL_SECMSCINTCLR_S_MSCEXP_CLR6_Pos                22                                                          /* SEC_PRIV_CTRL SECMSCINTCLR: S_MSCEXP_CLR6 Positions */
#define SEC_PRIV_CTRL_SECMSCINTCLR_S_MSCEXP_CLR6_Msk                (0x1UL  << SEC_PRIV_CTRL_SECMSCINTCLR_S_MSCEXP_CLR6_Pos)                 /* SEC_PRIV_CTRL SECMSCINTCLR: S_MSCEXP_CLR6 Mask */

#define SEC_PRIV_CTRL_SECMSCINTCLR_S_MSCEXP_CLR5_Pos                21                                                          /* SEC_PRIV_CTRL SECMSCINTCLR: S_MSCEXP_CLR5 Positions */
#define SEC_PRIV_CTRL_SECMSCINTCLR_S_MSCEXP_CLR5_Msk                (0x1UL  << SEC_PRIV_CTRL_SECMSCINTCLR_S_MSCEXP_CLR5_Pos)                 /* SEC_PRIV_CTRL SECMSCINTCLR: S_MSCEXP_CLR5 Mask */

#define SEC_PRIV_CTRL_SECMSCINTCLR_S_MSCEXP_CLR4_Pos                20                                                          /* SEC_PRIV_CTRL SECMSCINTCLR: S_MSCEXP_CLR4 Positions */
#define SEC_PRIV_CTRL_SECMSCINTCLR_S_MSCEXP_CLR4_Msk                (0x1UL  << SEC_PRIV_CTRL_SECMSCINTCLR_S_MSCEXP_CLR4_Pos)                 /* SEC_PRIV_CTRL SECMSCINTCLR: S_MSCEXP_CLR4 Mask */

#define SEC_PRIV_CTRL_SECMSCINTCLR_S_MSCEXP_CLR3_Pos                19                                                          /* SEC_PRIV_CTRL SECMSCINTCLR: S_MSCEXP_CLR3 Positions */
#define SEC_PRIV_CTRL_SECMSCINTCLR_S_MSCEXP_CLR3_Msk                (0x1UL  << SEC_PRIV_CTRL_SECMSCINTCLR_S_MSCEXP_CLR3_Pos)                 /* SEC_PRIV_CTRL SECMSCINTCLR: S_MSCEXP_CLR3 Mask */

#define SEC_PRIV_CTRL_SECMSCINTCLR_S_MSCEXP_CLR2_Pos                18                                                          /* SEC_PRIV_CTRL SECMSCINTCLR: S_MSCEXP_CLR2 Positions */
#define SEC_PRIV_CTRL_SECMSCINTCLR_S_MSCEXP_CLR2_Msk                (0x1UL  << SEC_PRIV_CTRL_SECMSCINTCLR_S_MSCEXP_CLR2_Pos)                 /* SEC_PRIV_CTRL SECMSCINTCLR: S_MSCEXP_CLR2 Mask */

#define SEC_PRIV_CTRL_SECMSCINTCLR_S_MSCEXP_CLR1_Pos                17                                                          /* SEC_PRIV_CTRL SECMSCINTCLR: S_MSCEXP_CLR1 Positions */
#define SEC_PRIV_CTRL_SECMSCINTCLR_S_MSCEXP_CLR1_Msk                (0x1UL  << SEC_PRIV_CTRL_SECMSCINTCLR_S_MSCEXP_CLR1_Pos)                 /* SEC_PRIV_CTRL SECMSCINTCLR: S_MSCEXP_CLR1 Mask */

#define SEC_PRIV_CTRL_SECMSCINTCLR_S_MSCEXP_CLR0_Pos                16                                                          /* SEC_PRIV_CTRL SECMSCINTCLR: S_MSCEXP_CLR0 Positions */
#define SEC_PRIV_CTRL_SECMSCINTCLR_S_MSCEXP_CLR0_Msk                (0x1UL  << SEC_PRIV_CTRL_SECMSCINTCLR_S_MSCEXP_CLR0_Pos)                 /* SEC_PRIV_CTRL SECMSCINTCLR: S_MSCEXP_CLR0 Mask */

#define SEC_PRIV_CTRL_SECMSCINTCLR_S_MSC_CRYPTO_CLR_Pos                0                                                          /* SEC_PRIV_CTRL SECMSCINTCLR: S_MSC_CRYPTO_CLR Positions */
#define SEC_PRIV_CTRL_SECMSCINTCLR_S_MSC_CRYPTO_CLR_Msk                (0x1UL  /*<< SEC_PRIV_CTRL_SECMSCINTCLR_S_MSC_CRYPTO_CLR_Pos*/)                 /* SEC_PRIV_CTRL SECMSCINTCLR: S_MSC_CRYPTO_CLR Mask */

/* SEC_PRIV_CTRL SECMSCINTEN Register Definitions */
#define SEC_PRIV_CTRL_SECMSCINTEN_S_MSCEXP_EN15_Pos                31                                                          /* SEC_PRIV_CTRL SECMSCINTEN: S_MSCEXP_EN15 Positions */
#define SEC_PRIV_CTRL_SECMSCINTEN_S_MSCEXP_EN15_Msk                (0x1UL  << SEC_PRIV_CTRL_SECMSCINTEN_S_MSCEXP_EN15_Pos)                 /* SEC_PRIV_CTRL SECMSCINTEN: S_MSCEXP_EN15 Mask */

#define SEC_PRIV_CTRL_SECMSCINTEN_S_MSCEXP_EN14_Pos                30                                                          /* SEC_PRIV_CTRL SECMSCINTEN: S_MSCEXP_EN14 Positions */
#define SEC_PRIV_CTRL_SECMSCINTEN_S_MSCEXP_EN14_Msk                (0x1UL  << SEC_PRIV_CTRL_SECMSCINTEN_S_MSCEXP_EN14_Pos)                 /* SEC_PRIV_CTRL SECMSCINTEN: S_MSCEXP_EN14 Mask */

#define SEC_PRIV_CTRL_SECMSCINTEN_S_MSCEXP_EN13_Pos                29                                                          /* SEC_PRIV_CTRL SECMSCINTEN: S_MSCEXP_EN13 Positions */
#define SEC_PRIV_CTRL_SECMSCINTEN_S_MSCEXP_EN13_Msk                (0x1UL  << SEC_PRIV_CTRL_SECMSCINTEN_S_MSCEXP_EN13_Pos)                 /* SEC_PRIV_CTRL SECMSCINTEN: S_MSCEXP_EN13 Mask */

#define SEC_PRIV_CTRL_SECMSCINTEN_S_MSCEXP_EN12_Pos                28                                                          /* SEC_PRIV_CTRL SECMSCINTEN: S_MSCEXP_EN12 Positions */
#define SEC_PRIV_CTRL_SECMSCINTEN_S_MSCEXP_EN12_Msk                (0x1UL  << SEC_PRIV_CTRL_SECMSCINTEN_S_MSCEXP_EN12_Pos)                 /* SEC_PRIV_CTRL SECMSCINTEN: S_MSCEXP_EN12 Mask */

#define SEC_PRIV_CTRL_SECMSCINTEN_S_MSCEXP_EN11_Pos                27                                                          /* SEC_PRIV_CTRL SECMSCINTEN: S_MSCEXP_EN11 Positions */
#define SEC_PRIV_CTRL_SECMSCINTEN_S_MSCEXP_EN11_Msk                (0x1UL  << SEC_PRIV_CTRL_SECMSCINTEN_S_MSCEXP_EN11_Pos)                 /* SEC_PRIV_CTRL SECMSCINTEN: S_MSCEXP_EN11 Mask */

#define SEC_PRIV_CTRL_SECMSCINTEN_S_MSCEXP_EN10_Pos                26                                                          /* SEC_PRIV_CTRL SECMSCINTEN: S_MSCEXP_EN10 Positions */
#define SEC_PRIV_CTRL_SECMSCINTEN_S_MSCEXP_EN10_Msk                (0x1UL  << SEC_PRIV_CTRL_SECMSCINTEN_S_MSCEXP_EN10_Pos)                 /* SEC_PRIV_CTRL SECMSCINTEN: S_MSCEXP_EN10 Mask */

#define SEC_PRIV_CTRL_SECMSCINTEN_S_MSCEXP_EN9_Pos                25                                                          /* SEC_PRIV_CTRL SECMSCINTEN: S_MSCEXP_EN9 Positions */
#define SEC_PRIV_CTRL_SECMSCINTEN_S_MSCEXP_EN9_Msk                (0x1UL  << SEC_PRIV_CTRL_SECMSCINTEN_S_MSCEXP_EN9_Pos)                 /* SEC_PRIV_CTRL SECMSCINTEN: S_MSCEXP_EN9 Mask */

#define SEC_PRIV_CTRL_SECMSCINTEN_S_MSCEXP_EN8_Pos                24                                                          /* SEC_PRIV_CTRL SECMSCINTEN: S_MSCEXP_EN8 Positions */
#define SEC_PRIV_CTRL_SECMSCINTEN_S_MSCEXP_EN8_Msk                (0x1UL  << SEC_PRIV_CTRL_SECMSCINTEN_S_MSCEXP_EN8_Pos)                 /* SEC_PRIV_CTRL SECMSCINTEN: S_MSCEXP_EN8 Mask */

#define SEC_PRIV_CTRL_SECMSCINTEN_S_MSCEXP_EN7_Pos                23                                                          /* SEC_PRIV_CTRL SECMSCINTEN: S_MSCEXP_EN7 Positions */
#define SEC_PRIV_CTRL_SECMSCINTEN_S_MSCEXP_EN7_Msk                (0x1UL  << SEC_PRIV_CTRL_SECMSCINTEN_S_MSCEXP_EN7_Pos)                 /* SEC_PRIV_CTRL SECMSCINTEN: S_MSCEXP_EN7 Mask */

#define SEC_PRIV_CTRL_SECMSCINTEN_S_MSCEXP_EN6_Pos                22                                                          /* SEC_PRIV_CTRL SECMSCINTEN: S_MSCEXP_EN6 Positions */
#define SEC_PRIV_CTRL_SECMSCINTEN_S_MSCEXP_EN6_Msk                (0x1UL  << SEC_PRIV_CTRL_SECMSCINTEN_S_MSCEXP_EN6_Pos)                 /* SEC_PRIV_CTRL SECMSCINTEN: S_MSCEXP_EN6 Mask */

#define SEC_PRIV_CTRL_SECMSCINTEN_S_MSCEXP_EN5_Pos                21                                                          /* SEC_PRIV_CTRL SECMSCINTEN: S_MSCEXP_EN5 Positions */
#define SEC_PRIV_CTRL_SECMSCINTEN_S_MSCEXP_EN5_Msk                (0x1UL  << SEC_PRIV_CTRL_SECMSCINTEN_S_MSCEXP_EN5_Pos)                 /* SEC_PRIV_CTRL SECMSCINTEN: S_MSCEXP_EN5 Mask */

#define SEC_PRIV_CTRL_SECMSCINTEN_S_MSCEXP_EN4_Pos                20                                                          /* SEC_PRIV_CTRL SECMSCINTEN: S_MSCEXP_EN4 Positions */
#define SEC_PRIV_CTRL_SECMSCINTEN_S_MSCEXP_EN4_Msk                (0x1UL  << SEC_PRIV_CTRL_SECMSCINTEN_S_MSCEXP_EN4_Pos)                 /* SEC_PRIV_CTRL SECMSCINTEN: S_MSCEXP_EN4 Mask */

#define SEC_PRIV_CTRL_SECMSCINTEN_S_MSCEXP_EN3_Pos                19                                                          /* SEC_PRIV_CTRL SECMSCINTEN: S_MSCEXP_EN3 Positions */
#define SEC_PRIV_CTRL_SECMSCINTEN_S_MSCEXP_EN3_Msk                (0x1UL  << SEC_PRIV_CTRL_SECMSCINTEN_S_MSCEXP_EN3_Pos)                 /* SEC_PRIV_CTRL SECMSCINTEN: S_MSCEXP_EN3 Mask */

#define SEC_PRIV_CTRL_SECMSCINTEN_S_MSCEXP_EN2_Pos                18                                                          /* SEC_PRIV_CTRL SECMSCINTEN: S_MSCEXP_EN2 Positions */
#define SEC_PRIV_CTRL_SECMSCINTEN_S_MSCEXP_EN2_Msk                (0x1UL  << SEC_PRIV_CTRL_SECMSCINTEN_S_MSCEXP_EN2_Pos)                 /* SEC_PRIV_CTRL SECMSCINTEN: S_MSCEXP_EN2 Mask */

#define SEC_PRIV_CTRL_SECMSCINTEN_S_MSCEXP_EN1_Pos                17                                                          /* SEC_PRIV_CTRL SECMSCINTEN: S_MSCEXP_EN1 Positions */
#define SEC_PRIV_CTRL_SECMSCINTEN_S_MSCEXP_EN1_Msk                (0x1UL  << SEC_PRIV_CTRL_SECMSCINTEN_S_MSCEXP_EN1_Pos)                 /* SEC_PRIV_CTRL SECMSCINTEN: S_MSCEXP_EN1 Mask */

#define SEC_PRIV_CTRL_SECMSCINTEN_S_MSCEXP_EN0_Pos                16                                                          /* SEC_PRIV_CTRL SECMSCINTEN: S_MSCEXP_EN0 Positions */
#define SEC_PRIV_CTRL_SECMSCINTEN_S_MSCEXP_EN0_Msk                (0x1UL  << SEC_PRIV_CTRL_SECMSCINTEN_S_MSCEXP_EN0_Pos)                 /* SEC_PRIV_CTRL SECMSCINTEN: S_MSCEXP_EN0 Mask */

#define SEC_PRIV_CTRL_SECMSCINTEN_S_MSC_CRYPTO_EN_Pos                0                                                          /* SEC_PRIV_CTRL SECMSCINTEN: S_MSC_CRYPTO_EN Positions */
#define SEC_PRIV_CTRL_SECMSCINTEN_S_MSC_CRYPTO_EN_Msk                (0x1UL  /*<< SEC_PRIV_CTRL_SECMSCINTEN_S_MSC_CRYPTO_EN_Pos*/)                 /* SEC_PRIV_CTRL SECMSCINTEN: S_MSC_CRYPTO_EN Mask */

/* SEC_PRIV_CTRL BRGINTSTAT Register Definitions */
#define SEC_PRIV_CTRL_BRGINTSTAT_BRGEXP_STATUS15_Pos                31                                                          /* SEC_PRIV_CTRL BRGINTSTAT: BRGEXP_STATUS15 Positions */
#define SEC_PRIV_CTRL_BRGINTSTAT_BRGEXP_STATUS15_Msk                (0x1UL  << SEC_PRIV_CTRL_BRGINTSTAT_BRGEXP_STATUS15_Pos)                 /* SEC_PRIV_CTRL BRGINTSTAT: BRGEXP_STATUS15 Mask */

#define SEC_PRIV_CTRL_BRGINTSTAT_BRGEXP_STATUS14_Pos                30                                                          /* SEC_PRIV_CTRL BRGINTSTAT: BRGEXP_STATUS14 Positions */
#define SEC_PRIV_CTRL_BRGINTSTAT_BRGEXP_STATUS14_Msk                (0x1UL  << SEC_PRIV_CTRL_BRGINTSTAT_BRGEXP_STATUS14_Pos)                 /* SEC_PRIV_CTRL BRGINTSTAT: BRGEXP_STATUS14 Mask */

#define SEC_PRIV_CTRL_BRGINTSTAT_BRGEXP_STATUS13_Pos                29                                                          /* SEC_PRIV_CTRL BRGINTSTAT: BRGEXP_STATUS13 Positions */
#define SEC_PRIV_CTRL_BRGINTSTAT_BRGEXP_STATUS13_Msk                (0x1UL  << SEC_PRIV_CTRL_BRGINTSTAT_BRGEXP_STATUS13_Pos)                 /* SEC_PRIV_CTRL BRGINTSTAT: BRGEXP_STATUS13 Mask */

#define SEC_PRIV_CTRL_BRGINTSTAT_BRGEXP_STATUS12_Pos                28                                                          /* SEC_PRIV_CTRL BRGINTSTAT: BRGEXP_STATUS12 Positions */
#define SEC_PRIV_CTRL_BRGINTSTAT_BRGEXP_STATUS12_Msk                (0x1UL  << SEC_PRIV_CTRL_BRGINTSTAT_BRGEXP_STATUS12_Pos)                 /* SEC_PRIV_CTRL BRGINTSTAT: BRGEXP_STATUS12 Mask */

#define SEC_PRIV_CTRL_BRGINTSTAT_BRGEXP_STATUS11_Pos                27                                                          /* SEC_PRIV_CTRL BRGINTSTAT: BRGEXP_STATUS11 Positions */
#define SEC_PRIV_CTRL_BRGINTSTAT_BRGEXP_STATUS11_Msk                (0x1UL  << SEC_PRIV_CTRL_BRGINTSTAT_BRGEXP_STATUS11_Pos)                 /* SEC_PRIV_CTRL BRGINTSTAT: BRGEXP_STATUS11 Mask */

#define SEC_PRIV_CTRL_BRGINTSTAT_BRGEXP_STATUS10_Pos                26                                                          /* SEC_PRIV_CTRL BRGINTSTAT: BRGEXP_STATUS10 Positions */
#define SEC_PRIV_CTRL_BRGINTSTAT_BRGEXP_STATUS10_Msk                (0x1UL  << SEC_PRIV_CTRL_BRGINTSTAT_BRGEXP_STATUS10_Pos)                 /* SEC_PRIV_CTRL BRGINTSTAT: BRGEXP_STATUS10 Mask */

#define SEC_PRIV_CTRL_BRGINTSTAT_BRGEXP_STATUS9_Pos                25                                                          /* SEC_PRIV_CTRL BRGINTSTAT: BRGEXP_STATUS9 Positions */
#define SEC_PRIV_CTRL_BRGINTSTAT_BRGEXP_STATUS9_Msk                (0x1UL  << SEC_PRIV_CTRL_BRGINTSTAT_BRGEXP_STATUS9_Pos)                 /* SEC_PRIV_CTRL BRGINTSTAT: BRGEXP_STATUS9 Mask */

#define SEC_PRIV_CTRL_BRGINTSTAT_BRGEXP_STATUS8_Pos                24                                                          /* SEC_PRIV_CTRL BRGINTSTAT: BRGEXP_STATUS8 Positions */
#define SEC_PRIV_CTRL_BRGINTSTAT_BRGEXP_STATUS8_Msk                (0x1UL  << SEC_PRIV_CTRL_BRGINTSTAT_BRGEXP_STATUS8_Pos)                 /* SEC_PRIV_CTRL BRGINTSTAT: BRGEXP_STATUS8 Mask */

#define SEC_PRIV_CTRL_BRGINTSTAT_BRGEXP_STATUS7_Pos                23                                                          /* SEC_PRIV_CTRL BRGINTSTAT: BRGEXP_STATUS7 Positions */
#define SEC_PRIV_CTRL_BRGINTSTAT_BRGEXP_STATUS7_Msk                (0x1UL  << SEC_PRIV_CTRL_BRGINTSTAT_BRGEXP_STATUS7_Pos)                 /* SEC_PRIV_CTRL BRGINTSTAT: BRGEXP_STATUS7 Mask */

#define SEC_PRIV_CTRL_BRGINTSTAT_BRGEXP_STATUS6_Pos                22                                                          /* SEC_PRIV_CTRL BRGINTSTAT: BRGEXP_STATUS6 Positions */
#define SEC_PRIV_CTRL_BRGINTSTAT_BRGEXP_STATUS6_Msk                (0x1UL  << SEC_PRIV_CTRL_BRGINTSTAT_BRGEXP_STATUS6_Pos)                 /* SEC_PRIV_CTRL BRGINTSTAT: BRGEXP_STATUS6 Mask */

#define SEC_PRIV_CTRL_BRGINTSTAT_BRGEXP_STATUS5_Pos                21                                                          /* SEC_PRIV_CTRL BRGINTSTAT: BRGEXP_STATUS5 Positions */
#define SEC_PRIV_CTRL_BRGINTSTAT_BRGEXP_STATUS5_Msk                (0x1UL  << SEC_PRIV_CTRL_BRGINTSTAT_BRGEXP_STATUS5_Pos)                 /* SEC_PRIV_CTRL BRGINTSTAT: BRGEXP_STATUS5 Mask */

#define SEC_PRIV_CTRL_BRGINTSTAT_BRGEXP_STATUS4_Pos                20                                                          /* SEC_PRIV_CTRL BRGINTSTAT: BRGEXP_STATUS4 Positions */
#define SEC_PRIV_CTRL_BRGINTSTAT_BRGEXP_STATUS4_Msk                (0x1UL  << SEC_PRIV_CTRL_BRGINTSTAT_BRGEXP_STATUS4_Pos)                 /* SEC_PRIV_CTRL BRGINTSTAT: BRGEXP_STATUS4 Mask */

#define SEC_PRIV_CTRL_BRGINTSTAT_BRGEXP_STATUS3_Pos                19                                                          /* SEC_PRIV_CTRL BRGINTSTAT: BRGEXP_STATUS3 Positions */
#define SEC_PRIV_CTRL_BRGINTSTAT_BRGEXP_STATUS3_Msk                (0x1UL  << SEC_PRIV_CTRL_BRGINTSTAT_BRGEXP_STATUS3_Pos)                 /* SEC_PRIV_CTRL BRGINTSTAT: BRGEXP_STATUS3 Mask */

#define SEC_PRIV_CTRL_BRGINTSTAT_BRGEXP_STATUS2_Pos                18                                                          /* SEC_PRIV_CTRL BRGINTSTAT: BRGEXP_STATUS2 Positions */
#define SEC_PRIV_CTRL_BRGINTSTAT_BRGEXP_STATUS2_Msk                (0x1UL  << SEC_PRIV_CTRL_BRGINTSTAT_BRGEXP_STATUS2_Pos)                 /* SEC_PRIV_CTRL BRGINTSTAT: BRGEXP_STATUS2 Mask */

#define SEC_PRIV_CTRL_BRGINTSTAT_BRGEXP_STATUS1_Pos                17                                                          /* SEC_PRIV_CTRL BRGINTSTAT: BRGEXP_STATUS1 Positions */
#define SEC_PRIV_CTRL_BRGINTSTAT_BRGEXP_STATUS1_Msk                (0x1UL  << SEC_PRIV_CTRL_BRGINTSTAT_BRGEXP_STATUS1_Pos)                 /* SEC_PRIV_CTRL BRGINTSTAT: BRGEXP_STATUS1 Mask */

#define SEC_PRIV_CTRL_BRGINTSTAT_BRGEXP_STATUS0_Pos                16                                                          /* SEC_PRIV_CTRL BRGINTSTAT: BRGEXP_STATUS0 Positions */
#define SEC_PRIV_CTRL_BRGINTSTAT_BRGEXP_STATUS0_Msk                (0x1UL  << SEC_PRIV_CTRL_BRGINTSTAT_BRGEXP_STATUS0_Pos)                 /* SEC_PRIV_CTRL BRGINTSTAT: BRGEXP_STATUS0 Mask */

#define SEC_PRIV_CTRL_BRGINTSTAT_BRG_CPU1SYS_STATUS_Pos                0                                                          /* SEC_PRIV_CTRL BRGINTSTAT: BRG_CPU1SYS_STATUS Positions */
#define SEC_PRIV_CTRL_BRGINTSTAT_BRG_CPU1SYS_STATUS_Msk                (0x1UL  /*<< SEC_PRIV_CTRL_BRGINTSTAT_BRG_CPU1SYS_STATUS_Pos*/)                 /* SEC_PRIV_CTRL BRGINTSTAT: BRG_CPU1SYS_STATUS Mask */

/* SEC_PRIV_CTRL BRGINTCLR Register Definitions */
#define SEC_PRIV_CTRL_BRGINTCLR_BRGEXP_CLR15_Pos                31                                                          /* SEC_PRIV_CTRL BRGINTCLR: BRGEXP_CLR15 Positions */
#define SEC_PRIV_CTRL_BRGINTCLR_BRGEXP_CLR15_Msk                (0x1UL  << SEC_PRIV_CTRL_BRGINTCLR_BRGEXP_CLR15_Pos)                 /* SEC_PRIV_CTRL BRGINTCLR: BRGEXP_CLR15 Mask */

#define SEC_PRIV_CTRL_BRGINTCLR_BRGEXP_CLR14_Pos                30                                                          /* SEC_PRIV_CTRL BRGINTCLR: BRGEXP_CLR14 Positions */
#define SEC_PRIV_CTRL_BRGINTCLR_BRGEXP_CLR14_Msk                (0x1UL  << SEC_PRIV_CTRL_BRGINTCLR_BRGEXP_CLR14_Pos)                 /* SEC_PRIV_CTRL BRGINTCLR: BRGEXP_CLR14 Mask */

#define SEC_PRIV_CTRL_BRGINTCLR_BRGEXP_CLR13_Pos                29                                                          /* SEC_PRIV_CTRL BRGINTCLR: BRGEXP_CLR13 Positions */
#define SEC_PRIV_CTRL_BRGINTCLR_BRGEXP_CLR13_Msk                (0x1UL  << SEC_PRIV_CTRL_BRGINTCLR_BRGEXP_CLR13_Pos)                 /* SEC_PRIV_CTRL BRGINTCLR: BRGEXP_CLR13 Mask */

#define SEC_PRIV_CTRL_BRGINTCLR_BRGEXP_CLR12_Pos                28                                                          /* SEC_PRIV_CTRL BRGINTCLR: BRGEXP_CLR12 Positions */
#define SEC_PRIV_CTRL_BRGINTCLR_BRGEXP_CLR12_Msk                (0x1UL  << SEC_PRIV_CTRL_BRGINTCLR_BRGEXP_CLR12_Pos)                 /* SEC_PRIV_CTRL BRGINTCLR: BRGEXP_CLR12 Mask */

#define SEC_PRIV_CTRL_BRGINTCLR_BRGEXP_CLR11_Pos                27                                                          /* SEC_PRIV_CTRL BRGINTCLR: BRGEXP_CLR11 Positions */
#define SEC_PRIV_CTRL_BRGINTCLR_BRGEXP_CLR11_Msk                (0x1UL  << SEC_PRIV_CTRL_BRGINTCLR_BRGEXP_CLR11_Pos)                 /* SEC_PRIV_CTRL BRGINTCLR: BRGEXP_CLR11 Mask */

#define SEC_PRIV_CTRL_BRGINTCLR_BRGEXP_CLR10_Pos                26                                                          /* SEC_PRIV_CTRL BRGINTCLR: BRGEXP_CLR10 Positions */
#define SEC_PRIV_CTRL_BRGINTCLR_BRGEXP_CLR10_Msk                (0x1UL  << SEC_PRIV_CTRL_BRGINTCLR_BRGEXP_CLR10_Pos)                 /* SEC_PRIV_CTRL BRGINTCLR: BRGEXP_CLR10 Mask */

#define SEC_PRIV_CTRL_BRGINTCLR_BRGEXP_CLR9_Pos                25                                                          /* SEC_PRIV_CTRL BRGINTCLR: BRGEXP_CLR9 Positions */
#define SEC_PRIV_CTRL_BRGINTCLR_BRGEXP_CLR9_Msk                (0x1UL  << SEC_PRIV_CTRL_BRGINTCLR_BRGEXP_CLR9_Pos)                 /* SEC_PRIV_CTRL BRGINTCLR: BRGEXP_CLR9 Mask */

#define SEC_PRIV_CTRL_BRGINTCLR_BRGEXP_CLR8_Pos                24                                                          /* SEC_PRIV_CTRL BRGINTCLR: BRGEXP_CLR8 Positions */
#define SEC_PRIV_CTRL_BRGINTCLR_BRGEXP_CLR8_Msk                (0x1UL  << SEC_PRIV_CTRL_BRGINTCLR_BRGEXP_CLR8_Pos)                 /* SEC_PRIV_CTRL BRGINTCLR: BRGEXP_CLR8 Mask */

#define SEC_PRIV_CTRL_BRGINTCLR_BRGEXP_CLR7_Pos                23                                                          /* SEC_PRIV_CTRL BRGINTCLR: BRGEXP_CLR7 Positions */
#define SEC_PRIV_CTRL_BRGINTCLR_BRGEXP_CLR7_Msk                (0x1UL  << SEC_PRIV_CTRL_BRGINTCLR_BRGEXP_CLR7_Pos)                 /* SEC_PRIV_CTRL BRGINTCLR: BRGEXP_CLR7 Mask */

#define SEC_PRIV_CTRL_BRGINTCLR_BRGEXP_CLR6_Pos                22                                                          /* SEC_PRIV_CTRL BRGINTCLR: BRGEXP_CLR6 Positions */
#define SEC_PRIV_CTRL_BRGINTCLR_BRGEXP_CLR6_Msk                (0x1UL  << SEC_PRIV_CTRL_BRGINTCLR_BRGEXP_CLR6_Pos)                 /* SEC_PRIV_CTRL BRGINTCLR: BRGEXP_CLR6 Mask */

#define SEC_PRIV_CTRL_BRGINTCLR_BRGEXP_CLR5_Pos                21                                                          /* SEC_PRIV_CTRL BRGINTCLR: BRGEXP_CLR5 Positions */
#define SEC_PRIV_CTRL_BRGINTCLR_BRGEXP_CLR5_Msk                (0x1UL  << SEC_PRIV_CTRL_BRGINTCLR_BRGEXP_CLR5_Pos)                 /* SEC_PRIV_CTRL BRGINTCLR: BRGEXP_CLR5 Mask */

#define SEC_PRIV_CTRL_BRGINTCLR_BRGEXP_CLR4_Pos                20                                                          /* SEC_PRIV_CTRL BRGINTCLR: BRGEXP_CLR4 Positions */
#define SEC_PRIV_CTRL_BRGINTCLR_BRGEXP_CLR4_Msk                (0x1UL  << SEC_PRIV_CTRL_BRGINTCLR_BRGEXP_CLR4_Pos)                 /* SEC_PRIV_CTRL BRGINTCLR: BRGEXP_CLR4 Mask */

#define SEC_PRIV_CTRL_BRGINTCLR_BRGEXP_CLR3_Pos                19                                                          /* SEC_PRIV_CTRL BRGINTCLR: BRGEXP_CLR3 Positions */
#define SEC_PRIV_CTRL_BRGINTCLR_BRGEXP_CLR3_Msk                (0x1UL  << SEC_PRIV_CTRL_BRGINTCLR_BRGEXP_CLR3_Pos)                 /* SEC_PRIV_CTRL BRGINTCLR: BRGEXP_CLR3 Mask */

#define SEC_PRIV_CTRL_BRGINTCLR_BRGEXP_CLR2_Pos                18                                                          /* SEC_PRIV_CTRL BRGINTCLR: BRGEXP_CLR2 Positions */
#define SEC_PRIV_CTRL_BRGINTCLR_BRGEXP_CLR2_Msk                (0x1UL  << SEC_PRIV_CTRL_BRGINTCLR_BRGEXP_CLR2_Pos)                 /* SEC_PRIV_CTRL BRGINTCLR: BRGEXP_CLR2 Mask */

#define SEC_PRIV_CTRL_BRGINTCLR_BRGEXP_CLR1_Pos                17                                                          /* SEC_PRIV_CTRL BRGINTCLR: BRGEXP_CLR1 Positions */
#define SEC_PRIV_CTRL_BRGINTCLR_BRGEXP_CLR1_Msk                (0x1UL  << SEC_PRIV_CTRL_BRGINTCLR_BRGEXP_CLR1_Pos)                 /* SEC_PRIV_CTRL BRGINTCLR: BRGEXP_CLR1 Mask */

#define SEC_PRIV_CTRL_BRGINTCLR_BRGEXP_CLR0_Pos                16                                                          /* SEC_PRIV_CTRL BRGINTCLR: BRGEXP_CLR0 Positions */
#define SEC_PRIV_CTRL_BRGINTCLR_BRGEXP_CLR0_Msk                (0x1UL  << SEC_PRIV_CTRL_BRGINTCLR_BRGEXP_CLR0_Pos)                 /* SEC_PRIV_CTRL BRGINTCLR: BRGEXP_CLR0 Mask */

#define SEC_PRIV_CTRL_BRGINTCLR_BRG_CPU1SYS_CLR_Pos                0                                                          /* SEC_PRIV_CTRL BRGINTCLR: BRG_CPU1SYS_CLR Positions */
#define SEC_PRIV_CTRL_BRGINTCLR_BRG_CPU1SYS_CLR_Msk                (0x1UL  /*<< SEC_PRIV_CTRL_BRGINTCLR_BRG_CPU1SYS_CLR_Pos*/)                 /* SEC_PRIV_CTRL BRGINTCLR: BRG_CPU1SYS_CLR Mask */

/* SEC_PRIV_CTRL BRGINTEN Register Definitions */
#define SEC_PRIV_CTRL_BRGINTEN_BRGEXP_EN15_Pos                31                                                          /* SEC_PRIV_CTRL BRGINTEN: BRGEXP_EN15 Positions */
#define SEC_PRIV_CTRL_BRGINTEN_BRGEXP_EN15_Msk                (0x1UL  << SEC_PRIV_CTRL_BRGINTEN_BRGEXP_EN15_Pos)                 /* SEC_PRIV_CTRL BRGINTEN: BRGEXP_EN15 Mask */

#define SEC_PRIV_CTRL_BRGINTEN_BRGEXP_EN14_Pos                30                                                          /* SEC_PRIV_CTRL BRGINTEN: BRGEXP_EN14 Positions */
#define SEC_PRIV_CTRL_BRGINTEN_BRGEXP_EN14_Msk                (0x1UL  << SEC_PRIV_CTRL_BRGINTEN_BRGEXP_EN14_Pos)                 /* SEC_PRIV_CTRL BRGINTEN: BRGEXP_EN14 Mask */

#define SEC_PRIV_CTRL_BRGINTEN_BRGEXP_EN13_Pos                29                                                          /* SEC_PRIV_CTRL BRGINTEN: BRGEXP_EN13 Positions */
#define SEC_PRIV_CTRL_BRGINTEN_BRGEXP_EN13_Msk                (0x1UL  << SEC_PRIV_CTRL_BRGINTEN_BRGEXP_EN13_Pos)                 /* SEC_PRIV_CTRL BRGINTEN: BRGEXP_EN13 Mask */

#define SEC_PRIV_CTRL_BRGINTEN_BRGEXP_EN12_Pos                28                                                          /* SEC_PRIV_CTRL BRGINTEN: BRGEXP_EN12 Positions */
#define SEC_PRIV_CTRL_BRGINTEN_BRGEXP_EN12_Msk                (0x1UL  << SEC_PRIV_CTRL_BRGINTEN_BRGEXP_EN12_Pos)                 /* SEC_PRIV_CTRL BRGINTEN: BRGEXP_EN12 Mask */

#define SEC_PRIV_CTRL_BRGINTEN_BRGEXP_EN11_Pos                27                                                          /* SEC_PRIV_CTRL BRGINTEN: BRGEXP_EN11 Positions */
#define SEC_PRIV_CTRL_BRGINTEN_BRGEXP_EN11_Msk                (0x1UL  << SEC_PRIV_CTRL_BRGINTEN_BRGEXP_EN11_Pos)                 /* SEC_PRIV_CTRL BRGINTEN: BRGEXP_EN11 Mask */

#define SEC_PRIV_CTRL_BRGINTEN_BRGEXP_EN10_Pos                26                                                          /* SEC_PRIV_CTRL BRGINTEN: BRGEXP_EN10 Positions */
#define SEC_PRIV_CTRL_BRGINTEN_BRGEXP_EN10_Msk                (0x1UL  << SEC_PRIV_CTRL_BRGINTEN_BRGEXP_EN10_Pos)                 /* SEC_PRIV_CTRL BRGINTEN: BRGEXP_EN10 Mask */

#define SEC_PRIV_CTRL_BRGINTEN_BRGEXP_EN9_Pos                25                                                          /* SEC_PRIV_CTRL BRGINTEN: BRGEXP_EN9 Positions */
#define SEC_PRIV_CTRL_BRGINTEN_BRGEXP_EN9_Msk                (0x1UL  << SEC_PRIV_CTRL_BRGINTEN_BRGEXP_EN9_Pos)                 /* SEC_PRIV_CTRL BRGINTEN: BRGEXP_EN9 Mask */

#define SEC_PRIV_CTRL_BRGINTEN_BRGEXP_EN8_Pos                24                                                          /* SEC_PRIV_CTRL BRGINTEN: BRGEXP_EN8 Positions */
#define SEC_PRIV_CTRL_BRGINTEN_BRGEXP_EN8_Msk                (0x1UL  << SEC_PRIV_CTRL_BRGINTEN_BRGEXP_EN8_Pos)                 /* SEC_PRIV_CTRL BRGINTEN: BRGEXP_EN8 Mask */

#define SEC_PRIV_CTRL_BRGINTEN_BRGEXP_EN7_Pos                23                                                          /* SEC_PRIV_CTRL BRGINTEN: BRGEXP_EN7 Positions */
#define SEC_PRIV_CTRL_BRGINTEN_BRGEXP_EN7_Msk                (0x1UL  << SEC_PRIV_CTRL_BRGINTEN_BRGEXP_EN7_Pos)                 /* SEC_PRIV_CTRL BRGINTEN: BRGEXP_EN7 Mask */

#define SEC_PRIV_CTRL_BRGINTEN_BRGEXP_EN6_Pos                22                                                          /* SEC_PRIV_CTRL BRGINTEN: BRGEXP_EN6 Positions */
#define SEC_PRIV_CTRL_BRGINTEN_BRGEXP_EN6_Msk                (0x1UL  << SEC_PRIV_CTRL_BRGINTEN_BRGEXP_EN6_Pos)                 /* SEC_PRIV_CTRL BRGINTEN: BRGEXP_EN6 Mask */

#define SEC_PRIV_CTRL_BRGINTEN_BRGEXP_EN5_Pos                21                                                          /* SEC_PRIV_CTRL BRGINTEN: BRGEXP_EN5 Positions */
#define SEC_PRIV_CTRL_BRGINTEN_BRGEXP_EN5_Msk                (0x1UL  << SEC_PRIV_CTRL_BRGINTEN_BRGEXP_EN5_Pos)                 /* SEC_PRIV_CTRL BRGINTEN: BRGEXP_EN5 Mask */

#define SEC_PRIV_CTRL_BRGINTEN_BRGEXP_EN4_Pos                20                                                          /* SEC_PRIV_CTRL BRGINTEN: BRGEXP_EN4 Positions */
#define SEC_PRIV_CTRL_BRGINTEN_BRGEXP_EN4_Msk                (0x1UL  << SEC_PRIV_CTRL_BRGINTEN_BRGEXP_EN4_Pos)                 /* SEC_PRIV_CTRL BRGINTEN: BRGEXP_EN4 Mask */

#define SEC_PRIV_CTRL_BRGINTEN_BRGEXP_EN3_Pos                19                                                          /* SEC_PRIV_CTRL BRGINTEN: BRGEXP_EN3 Positions */
#define SEC_PRIV_CTRL_BRGINTEN_BRGEXP_EN3_Msk                (0x1UL  << SEC_PRIV_CTRL_BRGINTEN_BRGEXP_EN3_Pos)                 /* SEC_PRIV_CTRL BRGINTEN: BRGEXP_EN3 Mask */

#define SEC_PRIV_CTRL_BRGINTEN_BRGEXP_EN2_Pos                18                                                          /* SEC_PRIV_CTRL BRGINTEN: BRGEXP_EN2 Positions */
#define SEC_PRIV_CTRL_BRGINTEN_BRGEXP_EN2_Msk                (0x1UL  << SEC_PRIV_CTRL_BRGINTEN_BRGEXP_EN2_Pos)                 /* SEC_PRIV_CTRL BRGINTEN: BRGEXP_EN2 Mask */

#define SEC_PRIV_CTRL_BRGINTEN_BRGEXP_EN1_Pos                17                                                          /* SEC_PRIV_CTRL BRGINTEN: BRGEXP_EN1 Positions */
#define SEC_PRIV_CTRL_BRGINTEN_BRGEXP_EN1_Msk                (0x1UL  << SEC_PRIV_CTRL_BRGINTEN_BRGEXP_EN1_Pos)                 /* SEC_PRIV_CTRL BRGINTEN: BRGEXP_EN1 Mask */

#define SEC_PRIV_CTRL_BRGINTEN_BRGEXP_EN0_Pos                16                                                          /* SEC_PRIV_CTRL BRGINTEN: BRGEXP_EN0 Positions */
#define SEC_PRIV_CTRL_BRGINTEN_BRGEXP_EN0_Msk                (0x1UL  << SEC_PRIV_CTRL_BRGINTEN_BRGEXP_EN0_Pos)                 /* SEC_PRIV_CTRL BRGINTEN: BRGEXP_EN0 Mask */

#define SEC_PRIV_CTRL_BRGINTEN_BRG_CPU1SYS_EN_Pos                0                                                          /* SEC_PRIV_CTRL BRGINTEN: BRG_CPU1SYS_EN Positions */
#define SEC_PRIV_CTRL_BRGINTEN_BRG_CPU1SYS_EN_Msk                (0x1UL  /*<< SEC_PRIV_CTRL_BRGINTEN_BRG_CPU1SYS_EN_Pos*/)                 /* SEC_PRIV_CTRL BRGINTEN: BRG_CPU1SYS_EN Mask */

/* SEC_PRIV_CTRL AHBNSPPCEXP0 Register Definitions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP0_AHBNSPPCEXP015_Pos                15                                                          /* SEC_PRIV_CTRL AHBNSPPCEXP0: AHBNSPPCEXP015 Positions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP0_AHBNSPPCEXP015_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBNSPPCEXP0_AHBNSPPCEXP015_Pos)                 /* SEC_PRIV_CTRL AHBNSPPCEXP0: AHBNSPPCEXP015 Mask */

#define SEC_PRIV_CTRL_AHBNSPPCEXP0_AHBNSPPCEXP014_Pos                14                                                          /* SEC_PRIV_CTRL AHBNSPPCEXP0: AHBNSPPCEXP014 Positions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP0_AHBNSPPCEXP014_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBNSPPCEXP0_AHBNSPPCEXP014_Pos)                 /* SEC_PRIV_CTRL AHBNSPPCEXP0: AHBNSPPCEXP014 Mask */

#define SEC_PRIV_CTRL_AHBNSPPCEXP0_AHBNSPPCEXP013_Pos                13                                                          /* SEC_PRIV_CTRL AHBNSPPCEXP0: AHBNSPPCEXP013 Positions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP0_AHBNSPPCEXP013_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBNSPPCEXP0_AHBNSPPCEXP013_Pos)                 /* SEC_PRIV_CTRL AHBNSPPCEXP0: AHBNSPPCEXP013 Mask */

#define SEC_PRIV_CTRL_AHBNSPPCEXP0_AHBNSPPCEXP012_Pos                12                                                          /* SEC_PRIV_CTRL AHBNSPPCEXP0: AHBNSPPCEXP012 Positions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP0_AHBNSPPCEXP012_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBNSPPCEXP0_AHBNSPPCEXP012_Pos)                 /* SEC_PRIV_CTRL AHBNSPPCEXP0: AHBNSPPCEXP012 Mask */

#define SEC_PRIV_CTRL_AHBNSPPCEXP0_AHBNSPPCEXP011_Pos                11                                                          /* SEC_PRIV_CTRL AHBNSPPCEXP0: AHBNSPPCEXP011 Positions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP0_AHBNSPPCEXP011_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBNSPPCEXP0_AHBNSPPCEXP011_Pos)                 /* SEC_PRIV_CTRL AHBNSPPCEXP0: AHBNSPPCEXP011 Mask */

#define SEC_PRIV_CTRL_AHBNSPPCEXP0_AHBNSPPCEXP010_Pos                10                                                          /* SEC_PRIV_CTRL AHBNSPPCEXP0: AHBNSPPCEXP010 Positions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP0_AHBNSPPCEXP010_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBNSPPCEXP0_AHBNSPPCEXP010_Pos)                 /* SEC_PRIV_CTRL AHBNSPPCEXP0: AHBNSPPCEXP010 Mask */

#define SEC_PRIV_CTRL_AHBNSPPCEXP0_AHBNSPPCEXP09_Pos                9                                                          /* SEC_PRIV_CTRL AHBNSPPCEXP0: AHBNSPPCEXP09 Positions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP0_AHBNSPPCEXP09_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBNSPPCEXP0_AHBNSPPCEXP09_Pos)                 /* SEC_PRIV_CTRL AHBNSPPCEXP0: AHBNSPPCEXP09 Mask */

#define SEC_PRIV_CTRL_AHBNSPPCEXP0_AHBNSPPCEXP08_Pos                8                                                          /* SEC_PRIV_CTRL AHBNSPPCEXP0: AHBNSPPCEXP08 Positions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP0_AHBNSPPCEXP08_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBNSPPCEXP0_AHBNSPPCEXP08_Pos)                 /* SEC_PRIV_CTRL AHBNSPPCEXP0: AHBNSPPCEXP08 Mask */

#define SEC_PRIV_CTRL_AHBNSPPCEXP0_AHBNSPPCEXP07_Pos                7                                                          /* SEC_PRIV_CTRL AHBNSPPCEXP0: AHBNSPPCEXP07 Positions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP0_AHBNSPPCEXP07_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBNSPPCEXP0_AHBNSPPCEXP07_Pos)                 /* SEC_PRIV_CTRL AHBNSPPCEXP0: AHBNSPPCEXP07 Mask */

#define SEC_PRIV_CTRL_AHBNSPPCEXP0_AHBNSPPCEXP06_Pos                6                                                          /* SEC_PRIV_CTRL AHBNSPPCEXP0: AHBNSPPCEXP06 Positions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP0_AHBNSPPCEXP06_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBNSPPCEXP0_AHBNSPPCEXP06_Pos)                 /* SEC_PRIV_CTRL AHBNSPPCEXP0: AHBNSPPCEXP06 Mask */

#define SEC_PRIV_CTRL_AHBNSPPCEXP0_AHBNSPPCEXP05_Pos                5                                                          /* SEC_PRIV_CTRL AHBNSPPCEXP0: AHBNSPPCEXP05 Positions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP0_AHBNSPPCEXP05_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBNSPPCEXP0_AHBNSPPCEXP05_Pos)                 /* SEC_PRIV_CTRL AHBNSPPCEXP0: AHBNSPPCEXP05 Mask */

#define SEC_PRIV_CTRL_AHBNSPPCEXP0_AHBNSPPCEXP04_Pos                4                                                          /* SEC_PRIV_CTRL AHBNSPPCEXP0: AHBNSPPCEXP04 Positions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP0_AHBNSPPCEXP04_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBNSPPCEXP0_AHBNSPPCEXP04_Pos)                 /* SEC_PRIV_CTRL AHBNSPPCEXP0: AHBNSPPCEXP04 Mask */

#define SEC_PRIV_CTRL_AHBNSPPCEXP0_AHBNSPPCEXP03_Pos                3                                                          /* SEC_PRIV_CTRL AHBNSPPCEXP0: AHBNSPPCEXP03 Positions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP0_AHBNSPPCEXP03_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBNSPPCEXP0_AHBNSPPCEXP03_Pos)                 /* SEC_PRIV_CTRL AHBNSPPCEXP0: AHBNSPPCEXP03 Mask */

#define SEC_PRIV_CTRL_AHBNSPPCEXP0_AHBNSPPCEXP02_Pos                2                                                          /* SEC_PRIV_CTRL AHBNSPPCEXP0: AHBNSPPCEXP02 Positions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP0_AHBNSPPCEXP02_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBNSPPCEXP0_AHBNSPPCEXP02_Pos)                 /* SEC_PRIV_CTRL AHBNSPPCEXP0: AHBNSPPCEXP02 Mask */

#define SEC_PRIV_CTRL_AHBNSPPCEXP0_AHBNSPPCEXP01_Pos                1                                                          /* SEC_PRIV_CTRL AHBNSPPCEXP0: AHBNSPPCEXP01 Positions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP0_AHBNSPPCEXP01_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBNSPPCEXP0_AHBNSPPCEXP01_Pos)                 /* SEC_PRIV_CTRL AHBNSPPCEXP0: AHBNSPPCEXP01 Mask */

#define SEC_PRIV_CTRL_AHBNSPPCEXP0_AHBNSPPCEXP00_Pos                0                                                          /* SEC_PRIV_CTRL AHBNSPPCEXP0: AHBNSPPCEXP00 Positions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP0_AHBNSPPCEXP00_Msk                (0x1UL  /*<< SEC_PRIV_CTRL_AHBNSPPCEXP0_AHBNSPPCEXP00_Pos*/)                 /* SEC_PRIV_CTRL AHBNSPPCEXP0: AHBNSPPCEXP00 Mask */

/* SEC_PRIV_CTRL AHBNSPPCEXP1 Register Definitions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP1_AHBNSPPCEXP115_Pos                15                                                          /* SEC_PRIV_CTRL AHBNSPPCEXP1: AHBNSPPCEXP115 Positions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP1_AHBNSPPCEXP115_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBNSPPCEXP1_AHBNSPPCEXP115_Pos)                 /* SEC_PRIV_CTRL AHBNSPPCEXP1: AHBNSPPCEXP115 Mask */

#define SEC_PRIV_CTRL_AHBNSPPCEXP1_GPIO2_Pos                14                                                          /* SEC_PRIV_CTRL AHBNSPPCEXP1: AHBNSPPCEXP114 Positions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP1_GPIO2_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBNSPPCEXP1_GPIO2_Pos)                 /* SEC_PRIV_CTRL AHBNSPPCEXP1: AHBNSPPCEXP114 Mask */

#define SEC_PRIV_CTRL_AHBNSPPCEXP1_GPIO3_Pos                15								/* SEC_PRIV_CTRL AHBNSPPCEXP1: AHBNSPPCEXP114 Positions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP1_GPIO3_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBNSPPCEXP1_GPIO3_Pos)                 /* SEC_PRIV_CTRL AHBNSPPCEXP1: AHBNSPPCEXP114 Mask */

#define SEC_PRIV_CTRL_AHBNSPPCEXP1_AHBNSPPCEXP113_Pos                13                                                          /* SEC_PRIV_CTRL AHBNSPPCEXP1: AHBNSPPCEXP113 Positions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP1_AHBNSPPCEXP113_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBNSPPCEXP1_AHBNSPPCEXP113_Pos)                 /* SEC_PRIV_CTRL AHBNSPPCEXP1: AHBNSPPCEXP113 Mask */

#define SEC_PRIV_CTRL_AHBNSPPCEXP1_AHBNSPPCEXP112_Pos                12                                                          /* SEC_PRIV_CTRL AHBNSPPCEXP1: AHBNSPPCEXP112 Positions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP1_AHBNSPPCEXP112_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBNSPPCEXP1_AHBNSPPCEXP112_Pos)                 /* SEC_PRIV_CTRL AHBNSPPCEXP1: AHBNSPPCEXP112 Mask */

#define SEC_PRIV_CTRL_AHBNSPPCEXP1_AHBNSPPCEXP111_Pos                11                                                          /* SEC_PRIV_CTRL AHBNSPPCEXP1: AHBNSPPCEXP111 Positions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP1_AHBNSPPCEXP111_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBNSPPCEXP1_AHBNSPPCEXP111_Pos)                 /* SEC_PRIV_CTRL AHBNSPPCEXP1: AHBNSPPCEXP111 Mask */

#define SEC_PRIV_CTRL_AHBNSPPCEXP1_AHBNSPPCEXP110_Pos                10                                                          /* SEC_PRIV_CTRL AHBNSPPCEXP1: AHBNSPPCEXP110 Positions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP1_AHBNSPPCEXP110_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBNSPPCEXP1_AHBNSPPCEXP110_Pos)                 /* SEC_PRIV_CTRL AHBNSPPCEXP1: AHBNSPPCEXP110 Mask */

#define SEC_PRIV_CTRL_AHBNSPPCEXP1_BLE52_Pos                9                                                          /* SEC_PRIV_CTRL AHBNSPPCEXP1: AHBNSPPCEXP19 Positions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP1_BLE52_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBNSPPCEXP1_BLE52_Pos)                 /* SEC_PRIV_CTRL AHBNSPPCEXP1: AHBNSPPCEXP19 Mask */

#define SEC_PRIV_CTRL_AHBNSPPCEXP1_I2S_Pos                8                                                          /* SEC_PRIV_CTRL AHBNSPPCEXP1: AHBNSPPCEXP18 Positions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP1_I2S_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBNSPPCEXP1_I2S_Pos)                 /* SEC_PRIV_CTRL AHBNSPPCEXP1: AHBNSPPCEXP18 Mask */

#define SEC_PRIV_CTRL_AHBNSPPCEXP1_AHBNSPPCEXP17_Pos                7                                                          /* SEC_PRIV_CTRL AHBNSPPCEXP1: AHBNSPPCEXP17 Positions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP1_AHBNSPPCEXP17_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBNSPPCEXP1_AHBNSPPCEXP17_Pos)                 /* SEC_PRIV_CTRL AHBNSPPCEXP1: AHBNSPPCEXP17 Mask */

#define SEC_PRIV_CTRL_AHBNSPPCEXP1_PDM0_Pos                6                                                          /* SEC_PRIV_CTRL AHBNSPPCEXP1: AHBNSPPCEXP16 Positions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP1_PDM0_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBNSPPCEXP1_PDM0_Pos)                 /* SEC_PRIV_CTRL AHBNSPPCEXP1: AHBNSPPCEXP16 Mask */

#define SEC_PRIV_CTRL_AHBNSPPCEXP1_AHBNSPPCEXP15_Pos                5                                                          /* SEC_PRIV_CTRL AHBNSPPCEXP1: AHBNSPPCEXP15 Positions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP1_AHBNSPPCEXP15_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBNSPPCEXP1_AHBNSPPCEXP15_Pos)                 /* SEC_PRIV_CTRL AHBNSPPCEXP1: AHBNSPPCEXP15 Mask */

#define SEC_PRIV_CTRL_AHBNSPPCEXP1_AHBNSPPCEXP14_Pos                4                                                          /* SEC_PRIV_CTRL AHBNSPPCEXP1: AHBNSPPCEXP14 Positions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP1_AHBNSPPCEXP14_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBNSPPCEXP1_AHBNSPPCEXP14_Pos)                 /* SEC_PRIV_CTRL AHBNSPPCEXP1: AHBNSPPCEXP14 Mask */

#define SEC_PRIV_CTRL_AHBNSPPCEXP1_DMA_Pos                3                                                          /* SEC_PRIV_CTRL AHBNSPPCEXP1: AHBNSPPCEXP13 Positions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP1_DMA_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBNSPPCEXP1_DMA_Pos)                 /* SEC_PRIV_CTRL AHBNSPPCEXP1: AHBNSPPCEXP13 Mask */

#define SEC_PRIV_CTRL_AHBNSPPCEXP1_SHA2_Pos                2                                                          /* SEC_PRIV_CTRL AHBNSPPCEXP1: AHBNSPPCEXP12 Positions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP1_SHA2_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBNSPPCEXP1_SHA2_Pos)                 /* SEC_PRIV_CTRL AHBNSPPCEXP1: AHBNSPPCEXP12 Mask */

#define SEC_PRIV_CTRL_AHBNSPPCEXP1_GPIO1_Pos                1                                                          /* SEC_PRIV_CTRL AHBNSPPCEXP1: AHBNSPPCEXP11 Positions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP1_GPIO1_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBNSPPCEXP1_GPIO1_Pos)                 /* SEC_PRIV_CTRL AHBNSPPCEXP1: AHBNSPPCEXP11 Mask */

#define SEC_PRIV_CTRL_AHBNSPPCEXP1_GPIO0_Pos                0                                                          /* SEC_PRIV_CTRL AHBNSPPCEXP1: AHBNSPPCEXP10 Positions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP1_GPIO0_Msk                (0x1UL  /*<< SEC_PRIV_CTRL_AHBNSPPCEXP1_GPIO0_Pos*/)                 /* SEC_PRIV_CTRL AHBNSPPCEXP1: AHBNSPPCEXP10 Mask */

/* SEC_PRIV_CTRL AHBNSPPCEXP2 Register Definitions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP2_AHBNSPPCEXP215_Pos                15                                                          /* SEC_PRIV_CTRL AHBNSPPCEXP2: AHBNSPPCEXP215 Positions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP2_AHBNSPPCEXP215_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBNSPPCEXP2_AHBNSPPCEXP215_Pos)                 /* SEC_PRIV_CTRL AHBNSPPCEXP2: AHBNSPPCEXP215 Mask */

#define SEC_PRIV_CTRL_AHBNSPPCEXP2_AHBNSPPCEXP214_Pos                14                                                          /* SEC_PRIV_CTRL AHBNSPPCEXP2: AHBNSPPCEXP214 Positions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP2_AHBNSPPCEXP214_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBNSPPCEXP2_AHBNSPPCEXP214_Pos)                 /* SEC_PRIV_CTRL AHBNSPPCEXP2: AHBNSPPCEXP214 Mask */

#define SEC_PRIV_CTRL_AHBNSPPCEXP2_AHBNSPPCEXP213_Pos                13                                                          /* SEC_PRIV_CTRL AHBNSPPCEXP2: AHBNSPPCEXP213 Positions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP2_AHBNSPPCEXP213_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBNSPPCEXP2_AHBNSPPCEXP213_Pos)                 /* SEC_PRIV_CTRL AHBNSPPCEXP2: AHBNSPPCEXP213 Mask */

#define SEC_PRIV_CTRL_AHBNSPPCEXP2_AHBNSPPCEXP212_Pos                12                                                          /* SEC_PRIV_CTRL AHBNSPPCEXP2: AHBNSPPCEXP212 Positions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP2_AHBNSPPCEXP212_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBNSPPCEXP2_AHBNSPPCEXP212_Pos)                 /* SEC_PRIV_CTRL AHBNSPPCEXP2: AHBNSPPCEXP212 Mask */

#define SEC_PRIV_CTRL_AHBNSPPCEXP2_AHBNSPPCEXP211_Pos                11                                                          /* SEC_PRIV_CTRL AHBNSPPCEXP2: AHBNSPPCEXP211 Positions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP2_AHBNSPPCEXP211_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBNSPPCEXP2_AHBNSPPCEXP211_Pos)                 /* SEC_PRIV_CTRL AHBNSPPCEXP2: AHBNSPPCEXP211 Mask */

#define SEC_PRIV_CTRL_AHBNSPPCEXP2_AHBNSPPCEXP210_Pos                10                                                          /* SEC_PRIV_CTRL AHBNSPPCEXP2: AHBNSPPCEXP210 Positions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP2_AHBNSPPCEXP210_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBNSPPCEXP2_AHBNSPPCEXP210_Pos)                 /* SEC_PRIV_CTRL AHBNSPPCEXP2: AHBNSPPCEXP210 Mask */

#define SEC_PRIV_CTRL_AHBNSPPCEXP2_AHBNSPPCEXP29_Pos                9                                                          /* SEC_PRIV_CTRL AHBNSPPCEXP2: AHBNSPPCEXP29 Positions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP2_AHBNSPPCEXP29_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBNSPPCEXP2_AHBNSPPCEXP29_Pos)                 /* SEC_PRIV_CTRL AHBNSPPCEXP2: AHBNSPPCEXP29 Mask */

#define SEC_PRIV_CTRL_AHBNSPPCEXP2_AHBNSPPCEXP28_Pos                8                                                          /* SEC_PRIV_CTRL AHBNSPPCEXP2: AHBNSPPCEXP28 Positions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP2_AHBNSPPCEXP28_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBNSPPCEXP2_AHBNSPPCEXP28_Pos)                 /* SEC_PRIV_CTRL AHBNSPPCEXP2: AHBNSPPCEXP28 Mask */

#define SEC_PRIV_CTRL_AHBNSPPCEXP2_AHBNSPPCEXP27_Pos                7                                                          /* SEC_PRIV_CTRL AHBNSPPCEXP2: AHBNSPPCEXP27 Positions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP2_AHBNSPPCEXP27_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBNSPPCEXP2_AHBNSPPCEXP27_Pos)                 /* SEC_PRIV_CTRL AHBNSPPCEXP2: AHBNSPPCEXP27 Mask */

#define SEC_PRIV_CTRL_AHBNSPPCEXP2_AHBNSPPCEXP26_Pos                6                                                          /* SEC_PRIV_CTRL AHBNSPPCEXP2: AHBNSPPCEXP26 Positions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP2_AHBNSPPCEXP26_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBNSPPCEXP2_AHBNSPPCEXP26_Pos)                 /* SEC_PRIV_CTRL AHBNSPPCEXP2: AHBNSPPCEXP26 Mask */

#define SEC_PRIV_CTRL_AHBNSPPCEXP2_AHBNSPPCEXP25_Pos                5                                                          /* SEC_PRIV_CTRL AHBNSPPCEXP2: AHBNSPPCEXP25 Positions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP2_AHBNSPPCEXP25_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBNSPPCEXP2_AHBNSPPCEXP25_Pos)                 /* SEC_PRIV_CTRL AHBNSPPCEXP2: AHBNSPPCEXP25 Mask */

#define SEC_PRIV_CTRL_AHBNSPPCEXP2_AHBNSPPCEXP24_Pos                4                                                          /* SEC_PRIV_CTRL AHBNSPPCEXP2: AHBNSPPCEXP24 Positions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP2_AHBNSPPCEXP24_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBNSPPCEXP2_AHBNSPPCEXP24_Pos)                 /* SEC_PRIV_CTRL AHBNSPPCEXP2: AHBNSPPCEXP24 Mask */

#define SEC_PRIV_CTRL_AHBNSPPCEXP2_AHBNSPPCEXP23_Pos                3                                                          /* SEC_PRIV_CTRL AHBNSPPCEXP2: AHBNSPPCEXP23 Positions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP2_AHBNSPPCEXP23_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBNSPPCEXP2_AHBNSPPCEXP23_Pos)                 /* SEC_PRIV_CTRL AHBNSPPCEXP2: AHBNSPPCEXP23 Mask */

#define SEC_PRIV_CTRL_AHBNSPPCEXP2_AHBNSPPCEXP22_Pos                2                                                          /* SEC_PRIV_CTRL AHBNSPPCEXP2: AHBNSPPCEXP22 Positions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP2_AHBNSPPCEXP22_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBNSPPCEXP2_AHBNSPPCEXP22_Pos)                 /* SEC_PRIV_CTRL AHBNSPPCEXP2: AHBNSPPCEXP22 Mask */

#define SEC_PRIV_CTRL_AHBNSPPCEXP2_AHBNSPPCEXP21_Pos                1                                                          /* SEC_PRIV_CTRL AHBNSPPCEXP2: AHBNSPPCEXP21 Positions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP2_AHBNSPPCEXP21_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBNSPPCEXP2_AHBNSPPCEXP21_Pos)                 /* SEC_PRIV_CTRL AHBNSPPCEXP2: AHBNSPPCEXP21 Mask */

#define SEC_PRIV_CTRL_AHBNSPPCEXP2_AHBNSPPCEXP20_Pos                0                                                          /* SEC_PRIV_CTRL AHBNSPPCEXP2: AHBNSPPCEXP20 Positions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP2_AHBNSPPCEXP20_Msk                (0x1UL  /*<< SEC_PRIV_CTRL_AHBNSPPCEXP2_AHBNSPPCEXP20_Pos*/)                 /* SEC_PRIV_CTRL AHBNSPPCEXP2: AHBNSPPCEXP20 Mask */

/* SEC_PRIV_CTRL AHBNSPPCEXP3 Register Definitions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP3_AHBNSPPCEXP315_Pos                15                                                          /* SEC_PRIV_CTRL AHBNSPPCEXP3: AHBNSPPCEXP315 Positions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP3_AHBNSPPCEXP315_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBNSPPCEXP3_AHBNSPPCEXP315_Pos)                 /* SEC_PRIV_CTRL AHBNSPPCEXP3: AHBNSPPCEXP315 Mask */

#define SEC_PRIV_CTRL_AHBNSPPCEXP3_AHBNSPPCEXP314_Pos                14                                                          /* SEC_PRIV_CTRL AHBNSPPCEXP3: AHBNSPPCEXP314 Positions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP3_AHBNSPPCEXP314_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBNSPPCEXP3_AHBNSPPCEXP314_Pos)                 /* SEC_PRIV_CTRL AHBNSPPCEXP3: AHBNSPPCEXP314 Mask */

#define SEC_PRIV_CTRL_AHBNSPPCEXP3_AHBNSPPCEXP313_Pos                13                                                          /* SEC_PRIV_CTRL AHBNSPPCEXP3: AHBNSPPCEXP313 Positions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP3_AHBNSPPCEXP313_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBNSPPCEXP3_AHBNSPPCEXP313_Pos)                 /* SEC_PRIV_CTRL AHBNSPPCEXP3: AHBNSPPCEXP313 Mask */

#define SEC_PRIV_CTRL_AHBNSPPCEXP3_AHBNSPPCEXP312_Pos                12                                                          /* SEC_PRIV_CTRL AHBNSPPCEXP3: AHBNSPPCEXP312 Positions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP3_AHBNSPPCEXP312_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBNSPPCEXP3_AHBNSPPCEXP312_Pos)                 /* SEC_PRIV_CTRL AHBNSPPCEXP3: AHBNSPPCEXP312 Mask */

#define SEC_PRIV_CTRL_AHBNSPPCEXP3_AHBNSPPCEXP311_Pos                11                                                          /* SEC_PRIV_CTRL AHBNSPPCEXP3: AHBNSPPCEXP311 Positions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP3_AHBNSPPCEXP311_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBNSPPCEXP3_AHBNSPPCEXP311_Pos)                 /* SEC_PRIV_CTRL AHBNSPPCEXP3: AHBNSPPCEXP311 Mask */

#define SEC_PRIV_CTRL_AHBNSPPCEXP3_AHBNSPPCEXP310_Pos                10                                                          /* SEC_PRIV_CTRL AHBNSPPCEXP3: AHBNSPPCEXP310 Positions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP3_AHBNSPPCEXP310_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBNSPPCEXP3_AHBNSPPCEXP310_Pos)                 /* SEC_PRIV_CTRL AHBNSPPCEXP3: AHBNSPPCEXP310 Mask */

#define SEC_PRIV_CTRL_AHBNSPPCEXP3_AHBNSPPCEXP39_Pos                9                                                          /* SEC_PRIV_CTRL AHBNSPPCEXP3: AHBNSPPCEXP39 Positions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP3_AHBNSPPCEXP39_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBNSPPCEXP3_AHBNSPPCEXP39_Pos)                 /* SEC_PRIV_CTRL AHBNSPPCEXP3: AHBNSPPCEXP39 Mask */

#define SEC_PRIV_CTRL_AHBNSPPCEXP3_AHBNSPPCEXP38_Pos                8                                                          /* SEC_PRIV_CTRL AHBNSPPCEXP3: AHBNSPPCEXP38 Positions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP3_AHBNSPPCEXP38_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBNSPPCEXP3_AHBNSPPCEXP38_Pos)                 /* SEC_PRIV_CTRL AHBNSPPCEXP3: AHBNSPPCEXP38 Mask */

#define SEC_PRIV_CTRL_AHBNSPPCEXP3_AHBNSPPCEXP37_Pos                7                                                          /* SEC_PRIV_CTRL AHBNSPPCEXP3: AHBNSPPCEXP37 Positions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP3_AHBNSPPCEXP37_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBNSPPCEXP3_AHBNSPPCEXP37_Pos)                 /* SEC_PRIV_CTRL AHBNSPPCEXP3: AHBNSPPCEXP37 Mask */

#define SEC_PRIV_CTRL_AHBNSPPCEXP3_AHBNSPPCEXP36_Pos                6                                                          /* SEC_PRIV_CTRL AHBNSPPCEXP3: AHBNSPPCEXP36 Positions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP3_AHBNSPPCEXP36_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBNSPPCEXP3_AHBNSPPCEXP36_Pos)                 /* SEC_PRIV_CTRL AHBNSPPCEXP3: AHBNSPPCEXP36 Mask */

#define SEC_PRIV_CTRL_AHBNSPPCEXP3_AHBNSPPCEXP35_Pos                5                                                          /* SEC_PRIV_CTRL AHBNSPPCEXP3: AHBNSPPCEXP35 Positions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP3_AHBNSPPCEXP35_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBNSPPCEXP3_AHBNSPPCEXP35_Pos)                 /* SEC_PRIV_CTRL AHBNSPPCEXP3: AHBNSPPCEXP35 Mask */

#define SEC_PRIV_CTRL_AHBNSPPCEXP3_AHBNSPPCEXP34_Pos                4                                                          /* SEC_PRIV_CTRL AHBNSPPCEXP3: AHBNSPPCEXP34 Positions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP3_AHBNSPPCEXP34_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBNSPPCEXP3_AHBNSPPCEXP34_Pos)                 /* SEC_PRIV_CTRL AHBNSPPCEXP3: AHBNSPPCEXP34 Mask */

#define SEC_PRIV_CTRL_AHBNSPPCEXP3_AHBNSPPCEXP33_Pos                3                                                          /* SEC_PRIV_CTRL AHBNSPPCEXP3: AHBNSPPCEXP33 Positions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP3_AHBNSPPCEXP33_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBNSPPCEXP3_AHBNSPPCEXP33_Pos)                 /* SEC_PRIV_CTRL AHBNSPPCEXP3: AHBNSPPCEXP33 Mask */

#define SEC_PRIV_CTRL_AHBNSPPCEXP3_AHBNSPPCEXP32_Pos                2                                                          /* SEC_PRIV_CTRL AHBNSPPCEXP3: AHBNSPPCEXP32 Positions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP3_AHBNSPPCEXP32_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBNSPPCEXP3_AHBNSPPCEXP32_Pos)                 /* SEC_PRIV_CTRL AHBNSPPCEXP3: AHBNSPPCEXP32 Mask */

#define SEC_PRIV_CTRL_AHBNSPPCEXP3_AHBNSPPCEXP31_Pos                1                                                          /* SEC_PRIV_CTRL AHBNSPPCEXP3: AHBNSPPCEXP31 Positions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP3_AHBNSPPCEXP31_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBNSPPCEXP3_AHBNSPPCEXP31_Pos)                 /* SEC_PRIV_CTRL AHBNSPPCEXP3: AHBNSPPCEXP31 Mask */

#define SEC_PRIV_CTRL_AHBNSPPCEXP3_AHBNSPPCEXP30_Pos                0                                                          /* SEC_PRIV_CTRL AHBNSPPCEXP3: AHBNSPPCEXP30 Positions */
#define SEC_PRIV_CTRL_AHBNSPPCEXP3_AHBNSPPCEXP30_Msk                (0x1UL  /*<< SEC_PRIV_CTRL_AHBNSPPCEXP3_AHBNSPPCEXP30_Pos*/)                 /* SEC_PRIV_CTRL AHBNSPPCEXP3: AHBNSPPCEXP30 Mask */

/* SEC_PRIV_CTRL APBNSPPC0 Register Definitions */
#define SEC_PRIV_CTRL_APBNSPPC0_NS_MHU1_Pos                4                                                          /* SEC_PRIV_CTRL APBNSPPC0: NS_MHU1 Positions */
#define SEC_PRIV_CTRL_APBNSPPC0_NS_MHU1_Msk                (0x1UL  << SEC_PRIV_CTRL_APBNSPPC0_NS_MHU1_Pos)                 /* SEC_PRIV_CTRL APBNSPPC0: NS_MHU1 Mask */

#define SEC_PRIV_CTRL_APBNSPPC0_NS_MHU0_Pos                3                                                          /* SEC_PRIV_CTRL APBNSPPC0: NS_MHU0 Positions */
#define SEC_PRIV_CTRL_APBNSPPC0_NS_MHU0_Msk                (0x1UL  << SEC_PRIV_CTRL_APBNSPPC0_NS_MHU0_Pos)                 /* SEC_PRIV_CTRL APBNSPPC0: NS_MHU0 Mask */

#define SEC_PRIV_CTRL_APBNSPPC0_NS_DTIMER_Pos                2                                                          /* SEC_PRIV_CTRL APBNSPPC0: NS_DTIMER Positions */
#define SEC_PRIV_CTRL_APBNSPPC0_NS_DTIMER_Msk                (0x1UL  << SEC_PRIV_CTRL_APBNSPPC0_NS_DTIMER_Pos)                 /* SEC_PRIV_CTRL APBNSPPC0: NS_DTIMER Mask */

#define SEC_PRIV_CTRL_APBNSPPC0_NS_TIMER1_Pos                1                                                          /* SEC_PRIV_CTRL APBNSPPC0: NS_TIMER1 Positions */
#define SEC_PRIV_CTRL_APBNSPPC0_NS_TIMER1_Msk                (0x1UL  << SEC_PRIV_CTRL_APBNSPPC0_NS_TIMER1_Pos)                 /* SEC_PRIV_CTRL APBNSPPC0: NS_TIMER1 Mask */

#define SEC_PRIV_CTRL_APBNSPPC0_NS_TIMER0_Pos                0                                                          /* SEC_PRIV_CTRL APBNSPPC0: NS_TIMER0 Positions */
#define SEC_PRIV_CTRL_APBNSPPC0_NS_TIMER0_Msk                (0x1UL  /*<< SEC_PRIV_CTRL_APBNSPPC0_NS_TIMER0_Pos*/)                 /* SEC_PRIV_CTRL APBNSPPC0: NS_TIMER0 Mask */

/* SEC_PRIV_CTRL APBNSPPC1 Register Definitions */
#define SEC_PRIV_CTRL_APBNSPPC1_NS_S32K_Timer_Pos                0                                                          /* SEC_PRIV_CTRL APBNSPPC1: NS_S32K_Timer Positions */
#define SEC_PRIV_CTRL_APBNSPPC1_NS_S32K_Timer_Msk                (0x1UL  /*<< SEC_PRIV_CTRL_APBNSPPC1_NS_S32K_Timer_Pos*/)                 /* SEC_PRIV_CTRL APBNSPPC1: NS_S32K_Timer Mask */

/* SEC_PRIV_CTRL APBNSPPCEXP0 Register Definitions */
#define SEC_PRIV_CTRL_APBNSPPCEXP0_QSPI_Pos                15                                                          /* SEC_PRIV_CTRL APBNSPPCEXP0: APBNSPPCEXP015 Positions */
#define SEC_PRIV_CTRL_APBNSPPCEXP0_QSPI_Msk                (0x1UL  << SEC_PRIV_CTRL_APBNSPPCEXP0_QSPI_Pos)                 /* SEC_PRIV_CTRL APBNSPPCEXP0: APBNSPPCEXP015 Mask */

#define SEC_PRIV_CTRL_APBNSPPCEXP0_SLWTIMER_Pos                14                                                          /* SEC_PRIV_CTRL APBNSPPCEXP0: APBNSPPCEXP014 Positions */
#define SEC_PRIV_CTRL_APBNSPPCEXP0_SLWTIMER_Msk                (0x1UL  << SEC_PRIV_CTRL_APBNSPPCEXP0_SLWTIMER_Pos)                 /* SEC_PRIV_CTRL APBNSPPCEXP0: APBNSPPCEXP014 Mask */

#define SEC_PRIV_CTRL_APBNSPPCEXP0_SPI1_Pos                13                                                          /* SEC_PRIV_CTRL APBNSPPCEXP0: APBNSPPCEXP013 Positions */
#define SEC_PRIV_CTRL_APBNSPPCEXP0_SPI1_Msk                (0x1UL  << SEC_PRIV_CTRL_APBNSPPCEXP0_SPI1_Pos)                 /* SEC_PRIV_CTRL APBNSPPCEXP0: APBNSPPCEXP013 Mask */

#define SEC_PRIV_CTRL_APBNSPPCEXP0_QDEC_Pos                12                                                          /* SEC_PRIV_CTRL APBNSPPCEXP0: APBNSPPCEXP012 Positions */
#define SEC_PRIV_CTRL_APBNSPPCEXP0_QDEC_Msk                (0x1UL  << SEC_PRIV_CTRL_APBNSPPCEXP0_QDEC_Pos)                 /* SEC_PRIV_CTRL APBNSPPCEXP0: APBNSPPCEXP012 Mask */

#define SEC_PRIV_CTRL_APBNSPPCEXP0_SPI2_Pos                11                                                          /* SEC_PRIV_CTRL APBNSPPCEXP0: APBNSPPCEXP011 Positions */
#define SEC_PRIV_CTRL_APBNSPPCEXP0_SPI2_Msk                (0x1UL  << SEC_PRIV_CTRL_APBNSPPCEXP0_SPI2_Pos)                 /* SEC_PRIV_CTRL APBNSPPCEXP0: APBNSPPCEXP011 Mask */

#define SEC_PRIV_CTRL_APBNSPPCEXP0_KSM_Pos                10                                                          /* SEC_PRIV_CTRL APBNSPPCEXP0: APBNSPPCEXP010 Positions */
#define SEC_PRIV_CTRL_APBNSPPCEXP0_KSM_Msk                (0x1UL  << SEC_PRIV_CTRL_APBNSPPCEXP0_KSM_Pos)                 /* SEC_PRIV_CTRL APBNSPPCEXP0: APBNSPPCEXP010 Mask */

#define SEC_PRIV_CTRL_APBNSPPCEXP0_APBNSPPCEXP09_Pos                9                                                          /* SEC_PRIV_CTRL APBNSPPCEXP0: APBNSPPCEXP09 Positions */
#define SEC_PRIV_CTRL_APBNSPPCEXP0_APBNSPPCEXP09_Msk                (0x1UL  << SEC_PRIV_CTRL_APBNSPPCEXP0_APBNSPPCEXP09_Pos)                 /* SEC_PRIV_CTRL APBNSPPCEXP0: APBNSPPCEXP09 Mask */

#define SEC_PRIV_CTRL_APBNSPPCEXP0_APBNSPPCEXP08_Pos                8                                                          /* SEC_PRIV_CTRL APBNSPPCEXP0: APBNSPPCEXP08 Positions */
#define SEC_PRIV_CTRL_APBNSPPCEXP0_APBNSPPCEXP08_Msk                (0x1UL  << SEC_PRIV_CTRL_APBNSPPCEXP0_APBNSPPCEXP08_Pos)                 /* SEC_PRIV_CTRL APBNSPPCEXP0: APBNSPPCEXP08 Mask */

#define SEC_PRIV_CTRL_APBNSPPCEXP0_SPI0_Pos                7                                                          /* SEC_PRIV_CTRL APBNSPPCEXP0: APBNSPPCEXP07 Positions */
#define SEC_PRIV_CTRL_APBNSPPCEXP0_SPI0_Msk                (0x1UL  << SEC_PRIV_CTRL_APBNSPPCEXP0_SPI0_Pos)                 /* SEC_PRIV_CTRL APBNSPPCEXP0: APBNSPPCEXP07 Mask */

#define SEC_PRIV_CTRL_APBNSPPCEXP0_PWM_Pos                6                                                          /* SEC_PRIV_CTRL APBNSPPCEXP0: APBNSPPCEXP06 Positions */
#define SEC_PRIV_CTRL_APBNSPPCEXP0_PWM_Msk                (0x1UL  << SEC_PRIV_CTRL_APBNSPPCEXP0_PWM_Pos)                 /* SEC_PRIV_CTRL APBNSPPCEXP0: APBNSPPCEXP06 Mask */

#define SEC_PRIV_CTRL_APBNSPPCEXP0_UART1_Pos                5                                                          /* SEC_PRIV_CTRL APBNSPPCEXP0: APBNSPPCEXP05 Positions */
#define SEC_PRIV_CTRL_APBNSPPCEXP0_UART1_Msk                (0x1UL  << SEC_PRIV_CTRL_APBNSPPCEXP0_UART1_Pos)                 /* SEC_PRIV_CTRL APBNSPPCEXP0: APBNSPPCEXP05 Mask */

#define SEC_PRIV_CTRL_APBNSPPCEXP0_UART0_Pos                4                                                          /* SEC_PRIV_CTRL APBNSPPCEXP0: APBNSPPCEXP04 Positions */
#define SEC_PRIV_CTRL_APBNSPPCEXP0_UART0_Msk                (0x1UL  << SEC_PRIV_CTRL_APBNSPPCEXP0_UART0_Pos)                 /* SEC_PRIV_CTRL APBNSPPCEXP0: APBNSPPCEXP04 Mask */

#define SEC_PRIV_CTRL_APBNSPPCEXP0_WRPR_Pos                3                                                          /* SEC_PRIV_CTRL APBNSPPCEXP0: APBNSPPCEXP03 Positions */
#define SEC_PRIV_CTRL_APBNSPPCEXP0_WRPR_Msk                (0x1UL  << SEC_PRIV_CTRL_APBNSPPCEXP0_WRPR_Pos)                 /* SEC_PRIV_CTRL APBNSPPCEXP0: APBNSPPCEXP03 Mask */

#define SEC_PRIV_CTRL_APBNSPPCEXP0_APBNSPPCEXP02_Pos                2                                                          /* SEC_PRIV_CTRL APBNSPPCEXP0: APBNSPPCEXP02 Positions */
#define SEC_PRIV_CTRL_APBNSPPCEXP0_APBNSPPCEXP02_Msk                (0x1UL  << SEC_PRIV_CTRL_APBNSPPCEXP0_APBNSPPCEXP02_Pos)                 /* SEC_PRIV_CTRL APBNSPPCEXP0: APBNSPPCEXP02 Mask */

#define SEC_PRIV_CTRL_APBNSPPCEXP0_APBNSPPCEXP01_Pos                1                                                          /* SEC_PRIV_CTRL APBNSPPCEXP0: APBNSPPCEXP01 Positions */
#define SEC_PRIV_CTRL_APBNSPPCEXP0_APBNSPPCEXP01_Msk                (0x1UL  << SEC_PRIV_CTRL_APBNSPPCEXP0_APBNSPPCEXP01_Pos)                 /* SEC_PRIV_CTRL APBNSPPCEXP0: APBNSPPCEXP01 Mask */

#define SEC_PRIV_CTRL_APBNSPPCEXP0_APBNSPPCEXP00_Pos                0                                                          /* SEC_PRIV_CTRL APBNSPPCEXP0: APBNSPPCEXP00 Positions */
#define SEC_PRIV_CTRL_APBNSPPCEXP0_APBNSPPCEXP00_Msk                (0x1UL  /*<< SEC_PRIV_CTRL_APBNSPPCEXP0_APBNSPPCEXP00_Pos*/)                 /* SEC_PRIV_CTRL APBNSPPCEXP0: APBNSPPCEXP00 Mask */

/* SEC_PRIV_CTRL APBNSPPCEXP1 Register Definitions */
#define SEC_PRIV_CTRL_APBNSPPCEXP1_APBNSPPCEXP115_Pos                15                                                          /* SEC_PRIV_CTRL APBNSPPCEXP1: APBNSPPCEXP115 Positions */
#define SEC_PRIV_CTRL_APBNSPPCEXP1_APBNSPPCEXP115_Msk                (0x1UL  << SEC_PRIV_CTRL_APBNSPPCEXP1_APBNSPPCEXP115_Pos)                 /* SEC_PRIV_CTRL APBNSPPCEXP1: APBNSPPCEXP115 Mask */

#define SEC_PRIV_CTRL_APBNSPPCEXP1_ATLC_Pos                14                                                          /* SEC_PRIV_CTRL APBNSPPCEXP1: APBNSPPCEXP114 Positions */
#define SEC_PRIV_CTRL_APBNSPPCEXP1_ATLC_Msk                (0x1UL  << SEC_PRIV_CTRL_APBNSPPCEXP1_ATLC_Pos)                 /* SEC_PRIV_CTRL APBNSPPCEXP1: APBNSPPCEXP114 Mask */

#define SEC_PRIV_CTRL_APBNSPPCEXP1_SHUB_Pos                13                                                          /* SEC_PRIV_CTRL APBNSPPCEXP1: APBNSPPCEXP113 Positions */
#define SEC_PRIV_CTRL_APBNSPPCEXP1_SHUB_Msk                (0x1UL  << SEC_PRIV_CTRL_APBNSPPCEXP1_SHUB_Pos)                 /* SEC_PRIV_CTRL APBNSPPCEXP1: APBNSPPCEXP113 Mask */

#define SEC_PRIV_CTRL_APBNSPPCEXP1_RCOS_CAL_Pos                12                                                          /* SEC_PRIV_CTRL APBNSPPCEXP1: APBNSPPCEXP112 Positions */
#define SEC_PRIV_CTRL_APBNSPPCEXP1_RCOS_CAL_Msk                (0x1UL  << SEC_PRIV_CTRL_APBNSPPCEXP1_RCOS_CAL_Pos)                 /* SEC_PRIV_CTRL APBNSPPCEXP1: APBNSPPCEXP112 Mask */

#define SEC_PRIV_CTRL_APBNSPPCEXP1_TRNG_Pos                11                                                          /* SEC_PRIV_CTRL APBNSPPCEXP1: APBNSPPCEXP111 Positions */
#define SEC_PRIV_CTRL_APBNSPPCEXP1_TRNG_Msk                (0x1UL  << SEC_PRIV_CTRL_APBNSPPCEXP1_TRNG_Pos)                 /* SEC_PRIV_CTRL APBNSPPCEXP1: APBNSPPCEXP111 Mask */

#define SEC_PRIV_CTRL_APBNSPPCEXP1_GADC_Pos                10                                                          /* SEC_PRIV_CTRL APBNSPPCEXP1: APBNSPPCEXP110 Positions */
#define SEC_PRIV_CTRL_APBNSPPCEXP1_GADC_Msk                (0x1UL  << SEC_PRIV_CTRL_APBNSPPCEXP1_GADC_Pos)                 /* SEC_PRIV_CTRL APBNSPPCEXP1: APBNSPPCEXP110 Mask */

#define SEC_PRIV_CTRL_APBNSPPCEXP1_SWD_Pos                9                                                          /* SEC_PRIV_CTRL APBNSPPCEXP1: APBNSPPCEXP19 Positions */
#define SEC_PRIV_CTRL_APBNSPPCEXP1_SWD_Msk                (0x1UL  << SEC_PRIV_CTRL_APBNSPPCEXP1_SWD_Pos)                 /* SEC_PRIV_CTRL APBNSPPCEXP1: APBNSPPCEXP19 Mask */

#define SEC_PRIV_CTRL_APBNSPPCEXP1_PSEQ_Pos                8                                                          /* SEC_PRIV_CTRL APBNSPPCEXP1: APBNSPPCEXP18 Positions */
#define SEC_PRIV_CTRL_APBNSPPCEXP1_PSEQ_Msk                (0x1UL  << SEC_PRIV_CTRL_APBNSPPCEXP1_PSEQ_Pos)                 /* SEC_PRIV_CTRL APBNSPPCEXP1: APBNSPPCEXP18 Mask */

#define SEC_PRIV_CTRL_APBNSPPCEXP1_PMU_Pos                7                                                          /* SEC_PRIV_CTRL APBNSPPCEXP1: APBNSPPCEXP17 Positions */
#define SEC_PRIV_CTRL_APBNSPPCEXP1_PMU_Msk                (0x1UL  << SEC_PRIV_CTRL_APBNSPPCEXP1_PMU_Pos)                 /* SEC_PRIV_CTRL APBNSPPCEXP1: APBNSPPCEXP17 Mask */

#define SEC_PRIV_CTRL_APBNSPPCEXP1_MDM_Pos                6                                                          /* SEC_PRIV_CTRL APBNSPPCEXP1: APBNSPPCEXP16 Positions */
#define SEC_PRIV_CTRL_APBNSPPCEXP1_MDM_Msk                (0x1UL  << SEC_PRIV_CTRL_APBNSPPCEXP1_MDM_Pos)                 /* SEC_PRIV_CTRL APBNSPPCEXP1: APBNSPPCEXP16 Mask */

#define SEC_PRIV_CTRL_APBNSPPCEXP1_RADIO_Pos                5                                                          /* SEC_PRIV_CTRL APBNSPPCEXP1: APBNSPPCEXP15 Positions */
#define SEC_PRIV_CTRL_APBNSPPCEXP1_RADIO_Msk                (0x1UL  << SEC_PRIV_CTRL_APBNSPPCEXP1_RADIO_Pos)                 /* SEC_PRIV_CTRL APBNSPPCEXP1: APBNSPPCEXP15 Mask */

#define SEC_PRIV_CTRL_APBNSPPCEXP1_RIF_Pos                4                                                          /* SEC_PRIV_CTRL APBNSPPCEXP1: APBNSPPCEXP14 Positions */
#define SEC_PRIV_CTRL_APBNSPPCEXP1_RIF_Msk                (0x1UL  << SEC_PRIV_CTRL_APBNSPPCEXP1_RIF_Pos)                 /* SEC_PRIV_CTRL APBNSPPCEXP1: APBNSPPCEXP14 Mask */

#define SEC_PRIV_CTRL_APBNSPPCEXP1_WRPR_Pos                3                                                          /* SEC_PRIV_CTRL APBNSPPCEXP1: APBNSPPCEXP13 Positions */
#define SEC_PRIV_CTRL_APBNSPPCEXP1_WRPR_Msk                (0x1UL  << SEC_PRIV_CTRL_APBNSPPCEXP1_WRPR_Pos)                 /* SEC_PRIV_CTRL APBNSPPCEXP1: APBNSPPCEXP13 Mask */

#define SEC_PRIV_CTRL_APBNSPPCEXP1_NVM_Pos                2                                                          /* SEC_PRIV_CTRL APBNSPPCEXP1: APBNSPPCEXP12 Positions */
#define SEC_PRIV_CTRL_APBNSPPCEXP1_NVM_Msk                (0x1UL  << SEC_PRIV_CTRL_APBNSPPCEXP1_NVM_Pos)                 /* SEC_PRIV_CTRL APBNSPPCEXP1: APBNSPPCEXP12 Mask */

#define SEC_PRIV_CTRL_APBNSPPCEXP1_I2C1_Pos                1                                                          /* SEC_PRIV_CTRL APBNSPPCEXP1: APBNSPPCEXP11 Positions */
#define SEC_PRIV_CTRL_APBNSPPCEXP1_I2C1_Msk                (0x1UL  << SEC_PRIV_CTRL_APBNSPPCEXP1_I2C1_Pos)                 /* SEC_PRIV_CTRL APBNSPPCEXP1: APBNSPPCEXP11 Mask */

#define SEC_PRIV_CTRL_APBNSPPCEXP1_I2C0_Pos                0                                                          /* SEC_PRIV_CTRL APBNSPPCEXP1: APBNSPPCEXP10 Positions */
#define SEC_PRIV_CTRL_APBNSPPCEXP1_I2C0_Msk                (0x1UL  /*<< SEC_PRIV_CTRL_APBNSPPCEXP1_I2C0_Pos*/)                 /* SEC_PRIV_CTRL APBNSPPCEXP1: APBNSPPCEXP10 Mask */

/* SEC_PRIV_CTRL APBNSPPCEXP2 Register Definitions */
#define SEC_PRIV_CTRL_APBNSPPCEXP2_APBNSPPCEXP215_Pos                15                                                          /* SEC_PRIV_CTRL APBNSPPCEXP2: APBNSPPCEXP215 Positions */
#define SEC_PRIV_CTRL_APBNSPPCEXP2_APBNSPPCEXP215_Msk                (0x1UL  << SEC_PRIV_CTRL_APBNSPPCEXP2_APBNSPPCEXP215_Pos)                 /* SEC_PRIV_CTRL APBNSPPCEXP2: APBNSPPCEXP215 Mask */

#define SEC_PRIV_CTRL_APBNSPPCEXP2_APBNSPPCEXP214_Pos                14                                                          /* SEC_PRIV_CTRL APBNSPPCEXP2: APBNSPPCEXP214 Positions */
#define SEC_PRIV_CTRL_APBNSPPCEXP2_APBNSPPCEXP214_Msk                (0x1UL  << SEC_PRIV_CTRL_APBNSPPCEXP2_APBNSPPCEXP214_Pos)                 /* SEC_PRIV_CTRL APBNSPPCEXP2: APBNSPPCEXP214 Mask */

#define SEC_PRIV_CTRL_APBNSPPCEXP2_APBNSPPCEXP213_Pos                13                                                          /* SEC_PRIV_CTRL APBNSPPCEXP2: APBNSPPCEXP213 Positions */
#define SEC_PRIV_CTRL_APBNSPPCEXP2_APBNSPPCEXP213_Msk                (0x1UL  << SEC_PRIV_CTRL_APBNSPPCEXP2_APBNSPPCEXP213_Pos)                 /* SEC_PRIV_CTRL APBNSPPCEXP2: APBNSPPCEXP213 Mask */

#define SEC_PRIV_CTRL_APBNSPPCEXP2_APBNSPPCEXP212_Pos                12                                                          /* SEC_PRIV_CTRL APBNSPPCEXP2: APBNSPPCEXP212 Positions */
#define SEC_PRIV_CTRL_APBNSPPCEXP2_APBNSPPCEXP212_Msk                (0x1UL  << SEC_PRIV_CTRL_APBNSPPCEXP2_APBNSPPCEXP212_Pos)                 /* SEC_PRIV_CTRL APBNSPPCEXP2: APBNSPPCEXP212 Mask */

#define SEC_PRIV_CTRL_APBNSPPCEXP2_APBNSPPCEXP211_Pos                11                                                          /* SEC_PRIV_CTRL APBNSPPCEXP2: APBNSPPCEXP211 Positions */
#define SEC_PRIV_CTRL_APBNSPPCEXP2_APBNSPPCEXP211_Msk                (0x1UL  << SEC_PRIV_CTRL_APBNSPPCEXP2_APBNSPPCEXP211_Pos)                 /* SEC_PRIV_CTRL APBNSPPCEXP2: APBNSPPCEXP211 Mask */

#define SEC_PRIV_CTRL_APBNSPPCEXP2_APBNSPPCEXP210_Pos                10                                                          /* SEC_PRIV_CTRL APBNSPPCEXP2: APBNSPPCEXP210 Positions */
#define SEC_PRIV_CTRL_APBNSPPCEXP2_APBNSPPCEXP210_Msk                (0x1UL  << SEC_PRIV_CTRL_APBNSPPCEXP2_APBNSPPCEXP210_Pos)                 /* SEC_PRIV_CTRL APBNSPPCEXP2: APBNSPPCEXP210 Mask */

#define SEC_PRIV_CTRL_APBNSPPCEXP2_APBNSPPCEXP29_Pos                9                                                          /* SEC_PRIV_CTRL APBNSPPCEXP2: APBNSPPCEXP29 Positions */
#define SEC_PRIV_CTRL_APBNSPPCEXP2_APBNSPPCEXP29_Msk                (0x1UL  << SEC_PRIV_CTRL_APBNSPPCEXP2_APBNSPPCEXP29_Pos)                 /* SEC_PRIV_CTRL APBNSPPCEXP2: APBNSPPCEXP29 Mask */

#define SEC_PRIV_CTRL_APBNSPPCEXP2_UART2_Pos                8                                                          /* SEC_PRIV_CTRL APBNSPPCEXP2: UART2 Positions */
#define SEC_PRIV_CTRL_APBNSPPCEXP2_UART2_Msk                (0x1UL  << SEC_PRIV_CTRL_APBNSPPCEXP2_UART2_Pos)                 /* SEC_PRIV_CTRL APBNSPPCEXP2: UART2 Mask */

#define SEC_PRIV_CTRL_APBNSPPCEXP2_AES_Pos                7                                                          /* SEC_PRIV_CTRL APBNSPPCEXP2: APBNSPPCEXP27 Positions */
#define SEC_PRIV_CTRL_APBNSPPCEXP2_AES_Msk                (0x1UL  << SEC_PRIV_CTRL_APBNSPPCEXP2_AES_Pos)                 /* SEC_PRIV_CTRL APBNSPPCEXP2: APBNSPPCEXP27 Mask */

#define SEC_PRIV_CTRL_APBNSPPCEXP2_CLKRSTGEN_Pos                6                                                          /* SEC_PRIV_CTRL APBNSPPCEXP2: APBNSPPCEXP26 Positions */
#define SEC_PRIV_CTRL_APBNSPPCEXP2_CLKRSTGEN_Msk                (0x1UL  << SEC_PRIV_CTRL_APBNSPPCEXP2_CLKRSTGEN_Pos)                 /* SEC_PRIV_CTRL APBNSPPCEXP2: APBNSPPCEXP26 Mask */

#define SEC_PRIV_CTRL_APBNSPPCEXP2_I2S_Pos                5                                                          /* SEC_PRIV_CTRL APBNSPPCEXP2: APBNSPPCEXP25 Positions */
#define SEC_PRIV_CTRL_APBNSPPCEXP2_I2S_Msk                (0x1UL  << SEC_PRIV_CTRL_APBNSPPCEXP2_I2S_Pos)                 /* SEC_PRIV_CTRL APBNSPPCEXP2: APBNSPPCEXP25 Mask */

#define SEC_PRIV_CTRL_APBNSPPCEXP2_APBNSPPCEXP24_Pos                4                                                          /* SEC_PRIV_CTRL APBNSPPCEXP2: APBNSPPCEXP24 Positions */
#define SEC_PRIV_CTRL_APBNSPPCEXP2_APBNSPPCEXP24_Msk                (0x1UL  << SEC_PRIV_CTRL_APBNSPPCEXP2_APBNSPPCEXP24_Pos)                 /* SEC_PRIV_CTRL APBNSPPCEXP2: APBNSPPCEXP24 Mask */

#define SEC_PRIV_CTRL_APBNSPPCEXP2_WRPR_Pos                3                                                          /* SEC_PRIV_CTRL APBNSPPCEXP2: APBNSPPCEXP23 Positions */
#define SEC_PRIV_CTRL_APBNSPPCEXP2_WRPR_Msk                (0x1UL  << SEC_PRIV_CTRL_APBNSPPCEXP2_WRPR_Pos)                 /* SEC_PRIV_CTRL APBNSPPCEXP2: APBNSPPCEXP23 Mask */

#define SEC_PRIV_CTRL_APBNSPPCEXP2_APBNSPPCEXP22_Pos                2                                                          /* SEC_PRIV_CTRL APBNSPPCEXP2: APBNSPPCEXP22 Positions */
#define SEC_PRIV_CTRL_APBNSPPCEXP2_APBNSPPCEXP22_Msk                (0x1UL  << SEC_PRIV_CTRL_APBNSPPCEXP2_APBNSPPCEXP22_Pos)                 /* SEC_PRIV_CTRL APBNSPPCEXP2: APBNSPPCEXP22 Mask */

#define SEC_PRIV_CTRL_APBNSPPCEXP2_APBNSPPCEXP21_Pos                1                                                          /* SEC_PRIV_CTRL APBNSPPCEXP2: APBNSPPCEXP21 Positions */
#define SEC_PRIV_CTRL_APBNSPPCEXP2_APBNSPPCEXP21_Msk                (0x1UL  << SEC_PRIV_CTRL_APBNSPPCEXP2_APBNSPPCEXP21_Pos)                 /* SEC_PRIV_CTRL APBNSPPCEXP2: APBNSPPCEXP21 Mask */

#define SEC_PRIV_CTRL_APBNSPPCEXP2_PDM0_Pos                0                                                          /* SEC_PRIV_CTRL APBNSPPCEXP2: APBNSPPCEXP20 Positions */
#define SEC_PRIV_CTRL_APBNSPPCEXP2_PDM0_Msk                (0x1UL  /*<< SEC_PRIV_CTRL_APBNSPPCEXP2_PDM0_Pos*/)                 /* SEC_PRIV_CTRL APBNSPPCEXP2: APBNSPPCEXP20 Mask */

/* SEC_PRIV_CTRL APBNSPPCEXP3 Register Definitions */
#define SEC_PRIV_CTRL_APBNSPPCEXP3_APBNSPPCEXP315_Pos                15                                                          /* SEC_PRIV_CTRL APBNSPPCEXP3: APBNSPPCEXP315 Positions */
#define SEC_PRIV_CTRL_APBNSPPCEXP3_APBNSPPCEXP315_Msk                (0x1UL  << SEC_PRIV_CTRL_APBNSPPCEXP3_APBNSPPCEXP315_Pos)                 /* SEC_PRIV_CTRL APBNSPPCEXP3: APBNSPPCEXP315 Mask */

#define SEC_PRIV_CTRL_APBNSPPCEXP3_APBNSPPCEXP314_Pos                14                                                          /* SEC_PRIV_CTRL APBNSPPCEXP3: APBNSPPCEXP314 Positions */
#define SEC_PRIV_CTRL_APBNSPPCEXP3_APBNSPPCEXP314_Msk                (0x1UL  << SEC_PRIV_CTRL_APBNSPPCEXP3_APBNSPPCEXP314_Pos)                 /* SEC_PRIV_CTRL APBNSPPCEXP3: APBNSPPCEXP314 Mask */

#define SEC_PRIV_CTRL_APBNSPPCEXP3_APBNSPPCEXP313_Pos                13                                                          /* SEC_PRIV_CTRL APBNSPPCEXP3: APBNSPPCEXP313 Positions */
#define SEC_PRIV_CTRL_APBNSPPCEXP3_APBNSPPCEXP313_Msk                (0x1UL  << SEC_PRIV_CTRL_APBNSPPCEXP3_APBNSPPCEXP313_Pos)                 /* SEC_PRIV_CTRL APBNSPPCEXP3: APBNSPPCEXP313 Mask */

#define SEC_PRIV_CTRL_APBNSPPCEXP3_APBNSPPCEXP312_Pos                12                                                          /* SEC_PRIV_CTRL APBNSPPCEXP3: APBNSPPCEXP312 Positions */
#define SEC_PRIV_CTRL_APBNSPPCEXP3_APBNSPPCEXP312_Msk                (0x1UL  << SEC_PRIV_CTRL_APBNSPPCEXP3_APBNSPPCEXP312_Pos)                 /* SEC_PRIV_CTRL APBNSPPCEXP3: APBNSPPCEXP312 Mask */

#define SEC_PRIV_CTRL_APBNSPPCEXP3_APBNSPPCEXP311_Pos                11                                                          /* SEC_PRIV_CTRL APBNSPPCEXP3: APBNSPPCEXP311 Positions */
#define SEC_PRIV_CTRL_APBNSPPCEXP3_APBNSPPCEXP311_Msk                (0x1UL  << SEC_PRIV_CTRL_APBNSPPCEXP3_APBNSPPCEXP311_Pos)                 /* SEC_PRIV_CTRL APBNSPPCEXP3: APBNSPPCEXP311 Mask */

#define SEC_PRIV_CTRL_APBNSPPCEXP3_APBNSPPCEXP310_Pos                10                                                          /* SEC_PRIV_CTRL APBNSPPCEXP3: APBNSPPCEXP310 Positions */
#define SEC_PRIV_CTRL_APBNSPPCEXP3_APBNSPPCEXP310_Msk                (0x1UL  << SEC_PRIV_CTRL_APBNSPPCEXP3_APBNSPPCEXP310_Pos)                 /* SEC_PRIV_CTRL APBNSPPCEXP3: APBNSPPCEXP310 Mask */

#define SEC_PRIV_CTRL_APBNSPPCEXP3_APBNSPPCEXP39_Pos                9                                                          /* SEC_PRIV_CTRL APBNSPPCEXP3: APBNSPPCEXP39 Positions */
#define SEC_PRIV_CTRL_APBNSPPCEXP3_APBNSPPCEXP39_Msk                (0x1UL  << SEC_PRIV_CTRL_APBNSPPCEXP3_APBNSPPCEXP39_Pos)                 /* SEC_PRIV_CTRL APBNSPPCEXP3: APBNSPPCEXP39 Mask */

#define SEC_PRIV_CTRL_APBNSPPCEXP3_APBNSPPCEXP38_Pos                8                                                          /* SEC_PRIV_CTRL APBNSPPCEXP3: APBNSPPCEXP38 Positions */
#define SEC_PRIV_CTRL_APBNSPPCEXP3_APBNSPPCEXP38_Msk                (0x1UL  << SEC_PRIV_CTRL_APBNSPPCEXP3_APBNSPPCEXP38_Pos)                 /* SEC_PRIV_CTRL APBNSPPCEXP3: APBNSPPCEXP38 Mask */

#define SEC_PRIV_CTRL_APBNSPPCEXP3_APBNSPPCEXP37_Pos                7                                                          /* SEC_PRIV_CTRL APBNSPPCEXP3: APBNSPPCEXP37 Positions */
#define SEC_PRIV_CTRL_APBNSPPCEXP3_APBNSPPCEXP37_Msk                (0x1UL  << SEC_PRIV_CTRL_APBNSPPCEXP3_APBNSPPCEXP37_Pos)                 /* SEC_PRIV_CTRL APBNSPPCEXP3: APBNSPPCEXP37 Mask */

#define SEC_PRIV_CTRL_APBNSPPCEXP3_APBNSPPCEXP36_Pos                6                                                          /* SEC_PRIV_CTRL APBNSPPCEXP3: APBNSPPCEXP36 Positions */
#define SEC_PRIV_CTRL_APBNSPPCEXP3_APBNSPPCEXP36_Msk                (0x1UL  << SEC_PRIV_CTRL_APBNSPPCEXP3_APBNSPPCEXP36_Pos)                 /* SEC_PRIV_CTRL APBNSPPCEXP3: APBNSPPCEXP36 Mask */

#define SEC_PRIV_CTRL_APBNSPPCEXP3_APBNSPPCEXP35_Pos                5                                                          /* SEC_PRIV_CTRL APBNSPPCEXP3: APBNSPPCEXP35 Positions */
#define SEC_PRIV_CTRL_APBNSPPCEXP3_APBNSPPCEXP35_Msk                (0x1UL  << SEC_PRIV_CTRL_APBNSPPCEXP3_APBNSPPCEXP35_Pos)                 /* SEC_PRIV_CTRL APBNSPPCEXP3: APBNSPPCEXP35 Mask */

#define SEC_PRIV_CTRL_APBNSPPCEXP3_APBNSPPCEXP34_Pos                4                                                          /* SEC_PRIV_CTRL APBNSPPCEXP3: APBNSPPCEXP34 Positions */
#define SEC_PRIV_CTRL_APBNSPPCEXP3_APBNSPPCEXP34_Msk                (0x1UL  << SEC_PRIV_CTRL_APBNSPPCEXP3_APBNSPPCEXP34_Pos)                 /* SEC_PRIV_CTRL APBNSPPCEXP3: APBNSPPCEXP34 Mask */

#define SEC_PRIV_CTRL_APBNSPPCEXP3_APBNSPPCEXP33_Pos                3                                                          /* SEC_PRIV_CTRL APBNSPPCEXP3: APBNSPPCEXP33 Positions */
#define SEC_PRIV_CTRL_APBNSPPCEXP3_APBNSPPCEXP33_Msk                (0x1UL  << SEC_PRIV_CTRL_APBNSPPCEXP3_APBNSPPCEXP33_Pos)                 /* SEC_PRIV_CTRL APBNSPPCEXP3: APBNSPPCEXP33 Mask */

#define SEC_PRIV_CTRL_APBNSPPCEXP3_APBNSPPCEXP32_Pos                2                                                          /* SEC_PRIV_CTRL APBNSPPCEXP3: APBNSPPCEXP32 Positions */
#define SEC_PRIV_CTRL_APBNSPPCEXP3_APBNSPPCEXP32_Msk                (0x1UL  << SEC_PRIV_CTRL_APBNSPPCEXP3_APBNSPPCEXP32_Pos)                 /* SEC_PRIV_CTRL APBNSPPCEXP3: APBNSPPCEXP32 Mask */

#define SEC_PRIV_CTRL_APBNSPPCEXP3_APBNSPPCEXP31_Pos                1                                                          /* SEC_PRIV_CTRL APBNSPPCEXP3: APBNSPPCEXP31 Positions */
#define SEC_PRIV_CTRL_APBNSPPCEXP3_APBNSPPCEXP31_Msk                (0x1UL  << SEC_PRIV_CTRL_APBNSPPCEXP3_APBNSPPCEXP31_Pos)                 /* SEC_PRIV_CTRL APBNSPPCEXP3: APBNSPPCEXP31 Mask */

#define SEC_PRIV_CTRL_APBNSPPCEXP3_APBNSPPCEXP30_Pos                0                                                          /* SEC_PRIV_CTRL APBNSPPCEXP3: APBNSPPCEXP30 Positions */
#define SEC_PRIV_CTRL_APBNSPPCEXP3_APBNSPPCEXP30_Msk                (0x1UL  /*<< SEC_PRIV_CTRL_APBNSPPCEXP3_APBNSPPCEXP30_Pos*/)                 /* SEC_PRIV_CTRL APBNSPPCEXP3: APBNSPPCEXP30 Mask */

/* SEC_PRIV_CTRL AHBSPPPCEXP0 Register Definitions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP0_AHBSPPPCEXP015_Pos                15                                                          /* SEC_PRIV_CTRL AHBSPPPCEXP0: AHBSPPPCEXP015 Positions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP0_AHBSPPPCEXP015_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBSPPPCEXP0_AHBSPPPCEXP015_Pos)                 /* SEC_PRIV_CTRL AHBSPPPCEXP0: AHBSPPPCEXP015 Mask */

#define SEC_PRIV_CTRL_AHBSPPPCEXP0_AHBSPPPCEXP014_Pos                14                                                          /* SEC_PRIV_CTRL AHBSPPPCEXP0: AHBSPPPCEXP014 Positions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP0_AHBSPPPCEXP014_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBSPPPCEXP0_AHBSPPPCEXP014_Pos)                 /* SEC_PRIV_CTRL AHBSPPPCEXP0: AHBSPPPCEXP014 Mask */

#define SEC_PRIV_CTRL_AHBSPPPCEXP0_AHBSPPPCEXP013_Pos                13                                                          /* SEC_PRIV_CTRL AHBSPPPCEXP0: AHBSPPPCEXP013 Positions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP0_AHBSPPPCEXP013_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBSPPPCEXP0_AHBSPPPCEXP013_Pos)                 /* SEC_PRIV_CTRL AHBSPPPCEXP0: AHBSPPPCEXP013 Mask */

#define SEC_PRIV_CTRL_AHBSPPPCEXP0_AHBSPPPCEXP012_Pos                12                                                          /* SEC_PRIV_CTRL AHBSPPPCEXP0: AHBSPPPCEXP012 Positions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP0_AHBSPPPCEXP012_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBSPPPCEXP0_AHBSPPPCEXP012_Pos)                 /* SEC_PRIV_CTRL AHBSPPPCEXP0: AHBSPPPCEXP012 Mask */

#define SEC_PRIV_CTRL_AHBSPPPCEXP0_AHBSPPPCEXP011_Pos                11                                                          /* SEC_PRIV_CTRL AHBSPPPCEXP0: AHBSPPPCEXP011 Positions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP0_AHBSPPPCEXP011_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBSPPPCEXP0_AHBSPPPCEXP011_Pos)                 /* SEC_PRIV_CTRL AHBSPPPCEXP0: AHBSPPPCEXP011 Mask */

#define SEC_PRIV_CTRL_AHBSPPPCEXP0_AHBSPPPCEXP010_Pos                10                                                          /* SEC_PRIV_CTRL AHBSPPPCEXP0: AHBSPPPCEXP010 Positions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP0_AHBSPPPCEXP010_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBSPPPCEXP0_AHBSPPPCEXP010_Pos)                 /* SEC_PRIV_CTRL AHBSPPPCEXP0: AHBSPPPCEXP010 Mask */

#define SEC_PRIV_CTRL_AHBSPPPCEXP0_AHBSPPPCEXP09_Pos                9                                                          /* SEC_PRIV_CTRL AHBSPPPCEXP0: AHBSPPPCEXP09 Positions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP0_AHBSPPPCEXP09_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBSPPPCEXP0_AHBSPPPCEXP09_Pos)                 /* SEC_PRIV_CTRL AHBSPPPCEXP0: AHBSPPPCEXP09 Mask */

#define SEC_PRIV_CTRL_AHBSPPPCEXP0_AHBSPPPCEXP08_Pos                8                                                          /* SEC_PRIV_CTRL AHBSPPPCEXP0: AHBSPPPCEXP08 Positions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP0_AHBSPPPCEXP08_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBSPPPCEXP0_AHBSPPPCEXP08_Pos)                 /* SEC_PRIV_CTRL AHBSPPPCEXP0: AHBSPPPCEXP08 Mask */

#define SEC_PRIV_CTRL_AHBSPPPCEXP0_AHBSPPPCEXP07_Pos                7                                                          /* SEC_PRIV_CTRL AHBSPPPCEXP0: AHBSPPPCEXP07 Positions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP0_AHBSPPPCEXP07_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBSPPPCEXP0_AHBSPPPCEXP07_Pos)                 /* SEC_PRIV_CTRL AHBSPPPCEXP0: AHBSPPPCEXP07 Mask */

#define SEC_PRIV_CTRL_AHBSPPPCEXP0_AHBSPPPCEXP06_Pos                6                                                          /* SEC_PRIV_CTRL AHBSPPPCEXP0: AHBSPPPCEXP06 Positions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP0_AHBSPPPCEXP06_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBSPPPCEXP0_AHBSPPPCEXP06_Pos)                 /* SEC_PRIV_CTRL AHBSPPPCEXP0: AHBSPPPCEXP06 Mask */

#define SEC_PRIV_CTRL_AHBSPPPCEXP0_AHBSPPPCEXP05_Pos                5                                                          /* SEC_PRIV_CTRL AHBSPPPCEXP0: AHBSPPPCEXP05 Positions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP0_AHBSPPPCEXP05_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBSPPPCEXP0_AHBSPPPCEXP05_Pos)                 /* SEC_PRIV_CTRL AHBSPPPCEXP0: AHBSPPPCEXP05 Mask */

#define SEC_PRIV_CTRL_AHBSPPPCEXP0_AHBSPPPCEXP04_Pos                4                                                          /* SEC_PRIV_CTRL AHBSPPPCEXP0: AHBSPPPCEXP04 Positions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP0_AHBSPPPCEXP04_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBSPPPCEXP0_AHBSPPPCEXP04_Pos)                 /* SEC_PRIV_CTRL AHBSPPPCEXP0: AHBSPPPCEXP04 Mask */

#define SEC_PRIV_CTRL_AHBSPPPCEXP0_AHBSPPPCEXP03_Pos                3                                                          /* SEC_PRIV_CTRL AHBSPPPCEXP0: AHBSPPPCEXP03 Positions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP0_AHBSPPPCEXP03_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBSPPPCEXP0_AHBSPPPCEXP03_Pos)                 /* SEC_PRIV_CTRL AHBSPPPCEXP0: AHBSPPPCEXP03 Mask */

#define SEC_PRIV_CTRL_AHBSPPPCEXP0_AHBSPPPCEXP02_Pos                2                                                          /* SEC_PRIV_CTRL AHBSPPPCEXP0: AHBSPPPCEXP02 Positions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP0_AHBSPPPCEXP02_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBSPPPCEXP0_AHBSPPPCEXP02_Pos)                 /* SEC_PRIV_CTRL AHBSPPPCEXP0: AHBSPPPCEXP02 Mask */

#define SEC_PRIV_CTRL_AHBSPPPCEXP0_AHBSPPPCEXP01_Pos                1                                                          /* SEC_PRIV_CTRL AHBSPPPCEXP0: AHBSPPPCEXP01 Positions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP0_AHBSPPPCEXP01_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBSPPPCEXP0_AHBSPPPCEXP01_Pos)                 /* SEC_PRIV_CTRL AHBSPPPCEXP0: AHBSPPPCEXP01 Mask */

#define SEC_PRIV_CTRL_AHBSPPPCEXP0_AHBSPPPCEXP00_Pos                0                                                          /* SEC_PRIV_CTRL AHBSPPPCEXP0: AHBSPPPCEXP00 Positions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP0_AHBSPPPCEXP00_Msk                (0x1UL  /*<< SEC_PRIV_CTRL_AHBSPPPCEXP0_AHBSPPPCEXP00_Pos*/)                 /* SEC_PRIV_CTRL AHBSPPPCEXP0: AHBSPPPCEXP00 Mask */

/* SEC_PRIV_CTRL AHBSPPPCEXP1 Register Definitions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP1_AHBSPPPCEXP115_Pos                15                                                          /* SEC_PRIV_CTRL AHBSPPPCEXP1: AHBSPPPCEXP115 Positions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP1_AHBSPPPCEXP115_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBSPPPCEXP1_AHBSPPPCEXP115_Pos)                 /* SEC_PRIV_CTRL AHBSPPPCEXP1: AHBSPPPCEXP115 Mask */

#define SEC_PRIV_CTRL_AHBSPPPCEXP1_GPIO2_Pos                14                                                          /* SEC_PRIV_CTRL AHBSPPPCEXP1: AHBSPPPCEXP114 Positions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP1_GPIO2_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBSPPPCEXP1_GPIO2_Pos)                 /* SEC_PRIV_CTRL AHBSPPPCEXP1: AHBSPPPCEXP114 Mask */

#define SEC_PRIV_CTRL_AHBSPPPCEXP1_GPIO3_Pos                15								/* SEC_PRIV_CTRL AHBSPPPCEXP1: AHBSPPPCEXP114 Positions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP1_GPIO3_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBSPPPCEXP1_GPIO3_Pos)                 /* SEC_PRIV_CTRL AHBSPPPCEXP1: AHBSPPPCEXP114 Mask */

#define SEC_PRIV_CTRL_AHBSPPPCEXP1_AHBSPPPCEXP113_Pos                13                                                          /* SEC_PRIV_CTRL AHBSPPPCEXP1: AHBSPPPCEXP113 Positions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP1_AHBSPPPCEXP113_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBSPPPCEXP1_AHBSPPPCEXP113_Pos)                 /* SEC_PRIV_CTRL AHBSPPPCEXP1: AHBSPPPCEXP113 Mask */

#define SEC_PRIV_CTRL_AHBSPPPCEXP1_AHBSPPPCEXP112_Pos                12                                                          /* SEC_PRIV_CTRL AHBSPPPCEXP1: AHBSPPPCEXP112 Positions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP1_AHBSPPPCEXP112_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBSPPPCEXP1_AHBSPPPCEXP112_Pos)                 /* SEC_PRIV_CTRL AHBSPPPCEXP1: AHBSPPPCEXP112 Mask */

#define SEC_PRIV_CTRL_AHBSPPPCEXP1_AHBSPPPCEXP111_Pos                11                                                          /* SEC_PRIV_CTRL AHBSPPPCEXP1: AHBSPPPCEXP111 Positions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP1_AHBSPPPCEXP111_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBSPPPCEXP1_AHBSPPPCEXP111_Pos)                 /* SEC_PRIV_CTRL AHBSPPPCEXP1: AHBSPPPCEXP111 Mask */

#define SEC_PRIV_CTRL_AHBSPPPCEXP1_AHBSPPPCEXP110_Pos                10                                                          /* SEC_PRIV_CTRL AHBSPPPCEXP1: AHBSPPPCEXP110 Positions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP1_AHBSPPPCEXP110_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBSPPPCEXP1_AHBSPPPCEXP110_Pos)                 /* SEC_PRIV_CTRL AHBSPPPCEXP1: AHBSPPPCEXP110 Mask */

#define SEC_PRIV_CTRL_AHBSPPPCEXP1_BLE52_Pos                9                                                          /* SEC_PRIV_CTRL AHBSPPPCEXP1: BLE52 Positions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP1_BLE52_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBSPPPCEXP1_BLE52_Pos)                 /* SEC_PRIV_CTRL AHBSPPPCEXP1: BLE52 Mask */

#define SEC_PRIV_CTRL_AHBSPPPCEXP1_I2S_Pos                8                                                          /* SEC_PRIV_CTRL AHBSPPPCEXP1: I2S Positions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP1_I2S_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBSPPPCEXP1_I2S_Pos)                 /* SEC_PRIV_CTRL AHBSPPPCEXP1: I2S Mask */

#define SEC_PRIV_CTRL_AHBSPPPCEXP1_AHBSPPPCEXP17_Pos                7                                                          /* SEC_PRIV_CTRL AHBSPPPCEXP1: AHBSPPPCEXP17 Positions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP1_AHBSPPPCEXP17_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBSPPPCEXP1_AHBSPPPCEXP17_Pos)                 /* SEC_PRIV_CTRL AHBSPPPCEXP1: AHBSPPPCEXP17 Mask */

#define SEC_PRIV_CTRL_AHBSPPPCEXP1_PDM0_Pos                6                                                          /* SEC_PRIV_CTRL AHBSPPPCEXP1: PDM0 Positions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP1_PDM0_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBSPPPCEXP1_PDM0_Pos)                 /* SEC_PRIV_CTRL AHBSPPPCEXP1: PDM0 Mask */

#define SEC_PRIV_CTRL_AHBSPPPCEXP1_AHBSPPPCEXP15_Pos                5                                                          /* SEC_PRIV_CTRL AHBSPPPCEXP1: AHBSPPPCEXP15 Positions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP1_AHBSPPPCEXP15_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBSPPPCEXP1_AHBSPPPCEXP15_Pos)                 /* SEC_PRIV_CTRL AHBSPPPCEXP1: AHBSPPPCEXP15 Mask */

#define SEC_PRIV_CTRL_AHBSPPPCEXP1_AHBSPPPCEXP14_Pos                4                                                          /* SEC_PRIV_CTRL AHBSPPPCEXP1: AHBSPPPCEXP14 Positions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP1_AHBSPPPCEXP14_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBSPPPCEXP1_AHBSPPPCEXP14_Pos)                 /* SEC_PRIV_CTRL AHBSPPPCEXP1: AHBSPPPCEXP14 Mask */

#define SEC_PRIV_CTRL_AHBSPPPCEXP1_DMA_Pos                3                                                          /* SEC_PRIV_CTRL AHBSPPPCEXP1: DMA Positions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP1_DMA_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBSPPPCEXP1_DMA_Pos)                 /* SEC_PRIV_CTRL AHBSPPPCEXP1: DMA Mask */

#define SEC_PRIV_CTRL_AHBSPPPCEXP1_SHA2_Pos                2                                                          /* SEC_PRIV_CTRL AHBSPPPCEXP1: SHA2 Positions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP1_SHA2_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBSPPPCEXP1_SHA2_Pos)                 /* SEC_PRIV_CTRL AHBSPPPCEXP1: SHA2 Mask */

#define SEC_PRIV_CTRL_AHBSPPPCEXP1_GPIO1_Pos                1                                                          /* SEC_PRIV_CTRL AHBSPPPCEXP1: GPIO1 Positions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP1_GPIO1_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBSPPPCEXP1_GPIO1_Pos)                 /* SEC_PRIV_CTRL AHBSPPPCEXP1: GPIO1 Mask */

#define SEC_PRIV_CTRL_AHBSPPPCEXP1_GPIO0_Pos                0                                                          /* SEC_PRIV_CTRL AHBSPPPCEXP1: GPIO0 Positions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP1_GPIO0_Msk                (0x1UL  /*<< SEC_PRIV_CTRL_AHBSPPPCEXP1_GPIO0_Pos*/)                 /* SEC_PRIV_CTRL AHBSPPPCEXP1: GPIO0 Mask */

/* SEC_PRIV_CTRL AHBSPPPCEXP2 Register Definitions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP2_AHBSPPPCEXP215_Pos                15                                                          /* SEC_PRIV_CTRL AHBSPPPCEXP2: AHBSPPPCEXP215 Positions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP2_AHBSPPPCEXP215_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBSPPPCEXP2_AHBSPPPCEXP215_Pos)                 /* SEC_PRIV_CTRL AHBSPPPCEXP2: AHBSPPPCEXP215 Mask */

#define SEC_PRIV_CTRL_AHBSPPPCEXP2_AHBSPPPCEXP214_Pos                14                                                          /* SEC_PRIV_CTRL AHBSPPPCEXP2: AHBSPPPCEXP214 Positions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP2_AHBSPPPCEXP214_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBSPPPCEXP2_AHBSPPPCEXP214_Pos)                 /* SEC_PRIV_CTRL AHBSPPPCEXP2: AHBSPPPCEXP214 Mask */

#define SEC_PRIV_CTRL_AHBSPPPCEXP2_AHBSPPPCEXP213_Pos                13                                                          /* SEC_PRIV_CTRL AHBSPPPCEXP2: AHBSPPPCEXP213 Positions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP2_AHBSPPPCEXP213_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBSPPPCEXP2_AHBSPPPCEXP213_Pos)                 /* SEC_PRIV_CTRL AHBSPPPCEXP2: AHBSPPPCEXP213 Mask */

#define SEC_PRIV_CTRL_AHBSPPPCEXP2_AHBSPPPCEXP212_Pos                12                                                          /* SEC_PRIV_CTRL AHBSPPPCEXP2: AHBSPPPCEXP212 Positions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP2_AHBSPPPCEXP212_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBSPPPCEXP2_AHBSPPPCEXP212_Pos)                 /* SEC_PRIV_CTRL AHBSPPPCEXP2: AHBSPPPCEXP212 Mask */

#define SEC_PRIV_CTRL_AHBSPPPCEXP2_AHBSPPPCEXP211_Pos                11                                                          /* SEC_PRIV_CTRL AHBSPPPCEXP2: AHBSPPPCEXP211 Positions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP2_AHBSPPPCEXP211_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBSPPPCEXP2_AHBSPPPCEXP211_Pos)                 /* SEC_PRIV_CTRL AHBSPPPCEXP2: AHBSPPPCEXP211 Mask */

#define SEC_PRIV_CTRL_AHBSPPPCEXP2_AHBSPPPCEXP210_Pos                10                                                          /* SEC_PRIV_CTRL AHBSPPPCEXP2: AHBSPPPCEXP210 Positions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP2_AHBSPPPCEXP210_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBSPPPCEXP2_AHBSPPPCEXP210_Pos)                 /* SEC_PRIV_CTRL AHBSPPPCEXP2: AHBSPPPCEXP210 Mask */

#define SEC_PRIV_CTRL_AHBSPPPCEXP2_AHBSPPPCEXP29_Pos                9                                                          /* SEC_PRIV_CTRL AHBSPPPCEXP2: AHBSPPPCEXP29 Positions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP2_AHBSPPPCEXP29_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBSPPPCEXP2_AHBSPPPCEXP29_Pos)                 /* SEC_PRIV_CTRL AHBSPPPCEXP2: AHBSPPPCEXP29 Mask */

#define SEC_PRIV_CTRL_AHBSPPPCEXP2_AHBSPPPCEXP28_Pos                8                                                          /* SEC_PRIV_CTRL AHBSPPPCEXP2: AHBSPPPCEXP28 Positions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP2_AHBSPPPCEXP28_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBSPPPCEXP2_AHBSPPPCEXP28_Pos)                 /* SEC_PRIV_CTRL AHBSPPPCEXP2: AHBSPPPCEXP28 Mask */

#define SEC_PRIV_CTRL_AHBSPPPCEXP2_AHBSPPPCEXP27_Pos                7                                                          /* SEC_PRIV_CTRL AHBSPPPCEXP2: AHBSPPPCEXP27 Positions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP2_AHBSPPPCEXP27_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBSPPPCEXP2_AHBSPPPCEXP27_Pos)                 /* SEC_PRIV_CTRL AHBSPPPCEXP2: AHBSPPPCEXP27 Mask */

#define SEC_PRIV_CTRL_AHBSPPPCEXP2_AHBSPPPCEXP26_Pos                6                                                          /* SEC_PRIV_CTRL AHBSPPPCEXP2: AHBSPPPCEXP26 Positions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP2_AHBSPPPCEXP26_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBSPPPCEXP2_AHBSPPPCEXP26_Pos)                 /* SEC_PRIV_CTRL AHBSPPPCEXP2: AHBSPPPCEXP26 Mask */

#define SEC_PRIV_CTRL_AHBSPPPCEXP2_AHBSPPPCEXP25_Pos                5                                                          /* SEC_PRIV_CTRL AHBSPPPCEXP2: AHBSPPPCEXP25 Positions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP2_AHBSPPPCEXP25_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBSPPPCEXP2_AHBSPPPCEXP25_Pos)                 /* SEC_PRIV_CTRL AHBSPPPCEXP2: AHBSPPPCEXP25 Mask */

#define SEC_PRIV_CTRL_AHBSPPPCEXP2_AHBSPPPCEXP24_Pos                4                                                          /* SEC_PRIV_CTRL AHBSPPPCEXP2: AHBSPPPCEXP24 Positions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP2_AHBSPPPCEXP24_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBSPPPCEXP2_AHBSPPPCEXP24_Pos)                 /* SEC_PRIV_CTRL AHBSPPPCEXP2: AHBSPPPCEXP24 Mask */

#define SEC_PRIV_CTRL_AHBSPPPCEXP2_AHBSPPPCEXP23_Pos                3                                                          /* SEC_PRIV_CTRL AHBSPPPCEXP2: AHBSPPPCEXP23 Positions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP2_AHBSPPPCEXP23_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBSPPPCEXP2_AHBSPPPCEXP23_Pos)                 /* SEC_PRIV_CTRL AHBSPPPCEXP2: AHBSPPPCEXP23 Mask */

#define SEC_PRIV_CTRL_AHBSPPPCEXP2_AHBSPPPCEXP22_Pos                2                                                          /* SEC_PRIV_CTRL AHBSPPPCEXP2: AHBSPPPCEXP22 Positions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP2_AHBSPPPCEXP22_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBSPPPCEXP2_AHBSPPPCEXP22_Pos)                 /* SEC_PRIV_CTRL AHBSPPPCEXP2: AHBSPPPCEXP22 Mask */

#define SEC_PRIV_CTRL_AHBSPPPCEXP2_AHBSPPPCEXP21_Pos                1                                                          /* SEC_PRIV_CTRL AHBSPPPCEXP2: AHBSPPPCEXP21 Positions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP2_AHBSPPPCEXP21_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBSPPPCEXP2_AHBSPPPCEXP21_Pos)                 /* SEC_PRIV_CTRL AHBSPPPCEXP2: AHBSPPPCEXP21 Mask */

#define SEC_PRIV_CTRL_AHBSPPPCEXP2_AHBSPPPCEXP20_Pos                0                                                          /* SEC_PRIV_CTRL AHBSPPPCEXP2: AHBSPPPCEXP20 Positions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP2_AHBSPPPCEXP20_Msk                (0x1UL  /*<< SEC_PRIV_CTRL_AHBSPPPCEXP2_AHBSPPPCEXP20_Pos*/)                 /* SEC_PRIV_CTRL AHBSPPPCEXP2: AHBSPPPCEXP20 Mask */

/* SEC_PRIV_CTRL AHBSPPPCEXP3 Register Definitions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP3_AHBSPPPCEXP315_Pos                15                                                          /* SEC_PRIV_CTRL AHBSPPPCEXP3: AHBSPPPCEXP315 Positions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP3_AHBSPPPCEXP315_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBSPPPCEXP3_AHBSPPPCEXP315_Pos)                 /* SEC_PRIV_CTRL AHBSPPPCEXP3: AHBSPPPCEXP315 Mask */

#define SEC_PRIV_CTRL_AHBSPPPCEXP3_AHBSPPPCEXP314_Pos                14                                                          /* SEC_PRIV_CTRL AHBSPPPCEXP3: AHBSPPPCEXP314 Positions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP3_AHBSPPPCEXP314_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBSPPPCEXP3_AHBSPPPCEXP314_Pos)                 /* SEC_PRIV_CTRL AHBSPPPCEXP3: AHBSPPPCEXP314 Mask */

#define SEC_PRIV_CTRL_AHBSPPPCEXP3_AHBSPPPCEXP313_Pos                13                                                          /* SEC_PRIV_CTRL AHBSPPPCEXP3: AHBSPPPCEXP313 Positions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP3_AHBSPPPCEXP313_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBSPPPCEXP3_AHBSPPPCEXP313_Pos)                 /* SEC_PRIV_CTRL AHBSPPPCEXP3: AHBSPPPCEXP313 Mask */

#define SEC_PRIV_CTRL_AHBSPPPCEXP3_AHBSPPPCEXP312_Pos                12                                                          /* SEC_PRIV_CTRL AHBSPPPCEXP3: AHBSPPPCEXP312 Positions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP3_AHBSPPPCEXP312_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBSPPPCEXP3_AHBSPPPCEXP312_Pos)                 /* SEC_PRIV_CTRL AHBSPPPCEXP3: AHBSPPPCEXP312 Mask */

#define SEC_PRIV_CTRL_AHBSPPPCEXP3_AHBSPPPCEXP311_Pos                11                                                          /* SEC_PRIV_CTRL AHBSPPPCEXP3: AHBSPPPCEXP311 Positions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP3_AHBSPPPCEXP311_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBSPPPCEXP3_AHBSPPPCEXP311_Pos)                 /* SEC_PRIV_CTRL AHBSPPPCEXP3: AHBSPPPCEXP311 Mask */

#define SEC_PRIV_CTRL_AHBSPPPCEXP3_AHBSPPPCEXP310_Pos                10                                                          /* SEC_PRIV_CTRL AHBSPPPCEXP3: AHBSPPPCEXP310 Positions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP3_AHBSPPPCEXP310_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBSPPPCEXP3_AHBSPPPCEXP310_Pos)                 /* SEC_PRIV_CTRL AHBSPPPCEXP3: AHBSPPPCEXP310 Mask */

#define SEC_PRIV_CTRL_AHBSPPPCEXP3_AHBSPPPCEXP39_Pos                9                                                          /* SEC_PRIV_CTRL AHBSPPPCEXP3: AHBSPPPCEXP39 Positions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP3_AHBSPPPCEXP39_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBSPPPCEXP3_AHBSPPPCEXP39_Pos)                 /* SEC_PRIV_CTRL AHBSPPPCEXP3: AHBSPPPCEXP39 Mask */

#define SEC_PRIV_CTRL_AHBSPPPCEXP3_AHBSPPPCEXP38_Pos                8                                                          /* SEC_PRIV_CTRL AHBSPPPCEXP3: AHBSPPPCEXP38 Positions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP3_AHBSPPPCEXP38_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBSPPPCEXP3_AHBSPPPCEXP38_Pos)                 /* SEC_PRIV_CTRL AHBSPPPCEXP3: AHBSPPPCEXP38 Mask */

#define SEC_PRIV_CTRL_AHBSPPPCEXP3_AHBSPPPCEXP37_Pos                7                                                          /* SEC_PRIV_CTRL AHBSPPPCEXP3: AHBSPPPCEXP37 Positions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP3_AHBSPPPCEXP37_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBSPPPCEXP3_AHBSPPPCEXP37_Pos)                 /* SEC_PRIV_CTRL AHBSPPPCEXP3: AHBSPPPCEXP37 Mask */

#define SEC_PRIV_CTRL_AHBSPPPCEXP3_AHBSPPPCEXP36_Pos                6                                                          /* SEC_PRIV_CTRL AHBSPPPCEXP3: AHBSPPPCEXP36 Positions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP3_AHBSPPPCEXP36_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBSPPPCEXP3_AHBSPPPCEXP36_Pos)                 /* SEC_PRIV_CTRL AHBSPPPCEXP3: AHBSPPPCEXP36 Mask */

#define SEC_PRIV_CTRL_AHBSPPPCEXP3_AHBSPPPCEXP35_Pos                5                                                          /* SEC_PRIV_CTRL AHBSPPPCEXP3: AHBSPPPCEXP35 Positions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP3_AHBSPPPCEXP35_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBSPPPCEXP3_AHBSPPPCEXP35_Pos)                 /* SEC_PRIV_CTRL AHBSPPPCEXP3: AHBSPPPCEXP35 Mask */

#define SEC_PRIV_CTRL_AHBSPPPCEXP3_AHBSPPPCEXP34_Pos                4                                                          /* SEC_PRIV_CTRL AHBSPPPCEXP3: AHBSPPPCEXP34 Positions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP3_AHBSPPPCEXP34_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBSPPPCEXP3_AHBSPPPCEXP34_Pos)                 /* SEC_PRIV_CTRL AHBSPPPCEXP3: AHBSPPPCEXP34 Mask */

#define SEC_PRIV_CTRL_AHBSPPPCEXP3_AHBSPPPCEXP33_Pos                3                                                          /* SEC_PRIV_CTRL AHBSPPPCEXP3: AHBSPPPCEXP33 Positions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP3_AHBSPPPCEXP33_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBSPPPCEXP3_AHBSPPPCEXP33_Pos)                 /* SEC_PRIV_CTRL AHBSPPPCEXP3: AHBSPPPCEXP33 Mask */

#define SEC_PRIV_CTRL_AHBSPPPCEXP3_AHBSPPPCEXP32_Pos                2                                                          /* SEC_PRIV_CTRL AHBSPPPCEXP3: AHBSPPPCEXP32 Positions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP3_AHBSPPPCEXP32_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBSPPPCEXP3_AHBSPPPCEXP32_Pos)                 /* SEC_PRIV_CTRL AHBSPPPCEXP3: AHBSPPPCEXP32 Mask */

#define SEC_PRIV_CTRL_AHBSPPPCEXP3_AHBSPPPCEXP31_Pos                1                                                          /* SEC_PRIV_CTRL AHBSPPPCEXP3: AHBSPPPCEXP31 Positions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP3_AHBSPPPCEXP31_Msk                (0x1UL  << SEC_PRIV_CTRL_AHBSPPPCEXP3_AHBSPPPCEXP31_Pos)                 /* SEC_PRIV_CTRL AHBSPPPCEXP3: AHBSPPPCEXP31 Mask */

#define SEC_PRIV_CTRL_AHBSPPPCEXP3_AHBSPPPCEXP30_Pos                0                                                          /* SEC_PRIV_CTRL AHBSPPPCEXP3: AHBSPPPCEXP30 Positions */
#define SEC_PRIV_CTRL_AHBSPPPCEXP3_AHBSPPPCEXP30_Msk                (0x1UL  /*<< SEC_PRIV_CTRL_AHBSPPPCEXP3_AHBSPPPCEXP30_Pos*/)                 /* SEC_PRIV_CTRL AHBSPPPCEXP3: AHBSPPPCEXP30 Mask */

/* SEC_PRIV_CTRL APBSPPPC0 Register Definitions */
#define SEC_PRIV_CTRL_APBSPPPC0_SP_MHU1_Pos                4                                                          /* SEC_PRIV_CTRL APBSPPPC0: SP_MHU1 Positions */
#define SEC_PRIV_CTRL_APBSPPPC0_SP_MHU1_Msk                (0x1UL  << SEC_PRIV_CTRL_APBSPPPC0_SP_MHU1_Pos)                 /* SEC_PRIV_CTRL APBSPPPC0: SP_MHU1 Mask */

#define SEC_PRIV_CTRL_APBSPPPC0_SP_MHU0_Pos                3                                                          /* SEC_PRIV_CTRL APBSPPPC0: SP_MHU0 Positions */
#define SEC_PRIV_CTRL_APBSPPPC0_SP_MHU0_Msk                (0x1UL  << SEC_PRIV_CTRL_APBSPPPC0_SP_MHU0_Pos)                 /* SEC_PRIV_CTRL APBSPPPC0: SP_MHU0 Mask */

#define SEC_PRIV_CTRL_APBSPPPC0_SP_DTIMER_Pos                2                                                          /* SEC_PRIV_CTRL APBSPPPC0: SP_DTIMER Positions */
#define SEC_PRIV_CTRL_APBSPPPC0_SP_DTIMER_Msk                (0x1UL  << SEC_PRIV_CTRL_APBSPPPC0_SP_DTIMER_Pos)                 /* SEC_PRIV_CTRL APBSPPPC0: SP_DTIMER Mask */

#define SEC_PRIV_CTRL_APBSPPPC0_SP_TIMER1_Pos                1                                                          /* SEC_PRIV_CTRL APBSPPPC0: SP_TIMER1 Positions */
#define SEC_PRIV_CTRL_APBSPPPC0_SP_TIMER1_Msk                (0x1UL  << SEC_PRIV_CTRL_APBSPPPC0_SP_TIMER1_Pos)                 /* SEC_PRIV_CTRL APBSPPPC0: SP_TIMER1 Mask */

#define SEC_PRIV_CTRL_APBSPPPC0_SP_TIMER0_Pos                0                                                          /* SEC_PRIV_CTRL APBSPPPC0: SP_TIMER0 Positions */
#define SEC_PRIV_CTRL_APBSPPPC0_SP_TIMER0_Msk                (0x1UL  /*<< SEC_PRIV_CTRL_APBSPPPC0_SP_TIMER0_Pos*/)                 /* SEC_PRIV_CTRL APBSPPPC0: SP_TIMER0 Mask */

/* SEC_PRIV_CTRL APBSPPPC1 Register Definitions */
#define SEC_PRIV_CTRL_APBSPPPC1_SP_S32K_Timer_Pos                0                                                          /* SEC_PRIV_CTRL APBSPPPC1: SP_S32K_Timer Positions */
#define SEC_PRIV_CTRL_APBSPPPC1_SP_S32K_Timer_Msk                (0x1UL  /*<< SEC_PRIV_CTRL_APBSPPPC1_SP_S32K_Timer_Pos*/)                 /* SEC_PRIV_CTRL APBSPPPC1: SP_S32K_Timer Mask */

/* SEC_PRIV_CTRL APBSPPPCEXP0 Register Definitions */
#define SEC_PRIV_CTRL_APBSPPPCEXP0_QSPI_Pos                15                                                          /* SEC_PRIV_CTRL APBSPPPCEXP0: QSPI Positions */
#define SEC_PRIV_CTRL_APBSPPPCEXP0_QSPI_Msk                (0x1UL  << SEC_PRIV_CTRL_APBSPPPCEXP0_QSPI_Pos)                 /* SEC_PRIV_CTRL APBSPPPCEXP0: QSPI Mask */

#define SEC_PRIV_CTRL_APBSPPPCEXP0_SLWTIMER_Pos                14                                                          /* SEC_PRIV_CTRL APBSPPPCEXP0: SLWTIMER Positions */
#define SEC_PRIV_CTRL_APBSPPPCEXP0_SLWTIMER_Msk                (0x1UL  << SEC_PRIV_CTRL_APBSPPPCEXP0_SLWTIMER_Pos)                 /* SEC_PRIV_CTRL APBSPPPCEXP0: SLWTIMER Mask */

#define SEC_PRIV_CTRL_APBSPPPCEXP0_SPI1_Pos                13                                                          /* SEC_PRIV_CTRL APBSPPPCEXP0: SPI1 Positions */
#define SEC_PRIV_CTRL_APBSPPPCEXP0_SPI1_Msk                (0x1UL  << SEC_PRIV_CTRL_APBSPPPCEXP0_SPI1_Pos)                 /* SEC_PRIV_CTRL APBSPPPCEXP0: SPI1 Mask */

#define SEC_PRIV_CTRL_APBSPPPCEXP0_QDEC_Pos                12                                                          /* SEC_PRIV_CTRL APBSPPPCEXP0: QDEC Positions */
#define SEC_PRIV_CTRL_APBSPPPCEXP0_QDEC_Msk                (0x1UL  << SEC_PRIV_CTRL_APBSPPPCEXP0_QDEC_Pos)                 /* SEC_PRIV_CTRL APBSPPPCEXP0: QDEC Mask */

#define SEC_PRIV_CTRL_APBSPPPCEXP0_SPI2_Pos                11                                                          /* SEC_PRIV_CTRL APBSPPPCEXP0: SPI2 Positions */
#define SEC_PRIV_CTRL_APBSPPPCEXP0_SPI2_Msk                (0x1UL  << SEC_PRIV_CTRL_APBSPPPCEXP0_SPI2_Pos)                 /* SEC_PRIV_CTRL APBSPPPCEXP0: SPI2 Mask */

#define SEC_PRIV_CTRL_APBSPPPCEXP0_KSM_Pos                10                                                          /* SEC_PRIV_CTRL APBSPPPCEXP0: KSM Positions */
#define SEC_PRIV_CTRL_APBSPPPCEXP0_KSM_Msk                (0x1UL  << SEC_PRIV_CTRL_APBSPPPCEXP0_KSM_Pos)                 /* SEC_PRIV_CTRL APBSPPPCEXP0: KSM Mask */

#define SEC_PRIV_CTRL_APBSPPPCEXP0_APBSPPPCEXP09_Pos                9                                                          /* SEC_PRIV_CTRL APBSPPPCEXP0: APBSPPPCEXP09 Positions */
#define SEC_PRIV_CTRL_APBSPPPCEXP0_APBSPPPCEXP09_Msk                (0x1UL  << SEC_PRIV_CTRL_APBSPPPCEXP0_APBSPPPCEXP09_Pos)                 /* SEC_PRIV_CTRL APBSPPPCEXP0: APBSPPPCEXP09 Mask */

#define SEC_PRIV_CTRL_APBSPPPCEXP0_APBSPPPCEXP08_Pos                8                                                          /* SEC_PRIV_CTRL APBSPPPCEXP0: APBSPPPCEXP08 Positions */
#define SEC_PRIV_CTRL_APBSPPPCEXP0_APBSPPPCEXP08_Msk                (0x1UL  << SEC_PRIV_CTRL_APBSPPPCEXP0_APBSPPPCEXP08_Pos)                 /* SEC_PRIV_CTRL APBSPPPCEXP0: APBSPPPCEXP08 Mask */

#define SEC_PRIV_CTRL_APBSPPPCEXP0_SPI0_Pos                7                                                          /* SEC_PRIV_CTRL APBSPPPCEXP0: SPI0 Positions */
#define SEC_PRIV_CTRL_APBSPPPCEXP0_SPI0_Msk                (0x1UL  << SEC_PRIV_CTRL_APBSPPPCEXP0_SPI0_Pos)                 /* SEC_PRIV_CTRL APBSPPPCEXP0: SPI0 Mask */

#define SEC_PRIV_CTRL_APBSPPPCEXP0_PWM_Pos                6                                                          /* SEC_PRIV_CTRL APBSPPPCEXP0: PWM Positions */
#define SEC_PRIV_CTRL_APBSPPPCEXP0_PWM_Msk                (0x1UL  << SEC_PRIV_CTRL_APBSPPPCEXP0_PWM_Pos)                 /* SEC_PRIV_CTRL APBSPPPCEXP0: PWM Mask */

#define SEC_PRIV_CTRL_APBSPPPCEXP0_UART1_Pos                5                                                          /* SEC_PRIV_CTRL APBSPPPCEXP0: UART1 Positions */
#define SEC_PRIV_CTRL_APBSPPPCEXP0_UART1_Msk                (0x1UL  << SEC_PRIV_CTRL_APBSPPPCEXP0_UART1_Pos)                 /* SEC_PRIV_CTRL APBSPPPCEXP0: UART1 Mask */

#define SEC_PRIV_CTRL_APBSPPPCEXP0_UART0_Pos                4                                                          /* SEC_PRIV_CTRL APBSPPPCEXP0: UART0 Positions */
#define SEC_PRIV_CTRL_APBSPPPCEXP0_UART0_Msk                (0x1UL  << SEC_PRIV_CTRL_APBSPPPCEXP0_UART0_Pos)                 /* SEC_PRIV_CTRL APBSPPPCEXP0: UART0 Mask */

#define SEC_PRIV_CTRL_APBSPPPCEXP0_WRPR_Pos                3                                                          /* SEC_PRIV_CTRL APBSPPPCEXP0: WRPR Positions */
#define SEC_PRIV_CTRL_APBSPPPCEXP0_WRPR_Msk                (0x1UL  << SEC_PRIV_CTRL_APBSPPPCEXP0_WRPR_Pos)                 /* SEC_PRIV_CTRL APBSPPPCEXP0: WRPR Mask */

#define SEC_PRIV_CTRL_APBSPPPCEXP0_APBSPPPCEXP02_Pos                2                                                          /* SEC_PRIV_CTRL APBSPPPCEXP0: APBSPPPCEXP02 Positions */
#define SEC_PRIV_CTRL_APBSPPPCEXP0_APBSPPPCEXP02_Msk                (0x1UL  << SEC_PRIV_CTRL_APBSPPPCEXP0_APBSPPPCEXP02_Pos)                 /* SEC_PRIV_CTRL APBSPPPCEXP0: APBSPPPCEXP02 Mask */

#define SEC_PRIV_CTRL_APBSPPPCEXP0_APBSPPPCEXP01_Pos                1                                                          /* SEC_PRIV_CTRL APBSPPPCEXP0: APBSPPPCEXP01 Positions */
#define SEC_PRIV_CTRL_APBSPPPCEXP0_APBSPPPCEXP01_Msk                (0x1UL  << SEC_PRIV_CTRL_APBSPPPCEXP0_APBSPPPCEXP01_Pos)                 /* SEC_PRIV_CTRL APBSPPPCEXP0: APBSPPPCEXP01 Mask */

#define SEC_PRIV_CTRL_APBSPPPCEXP0_APBSPPPCEXP00_Pos                0                                                          /* SEC_PRIV_CTRL APBSPPPCEXP0: APBSPPPCEXP00 Positions */
#define SEC_PRIV_CTRL_APBSPPPCEXP0_APBSPPPCEXP00_Msk                (0x1UL  /*<< SEC_PRIV_CTRL_APBSPPPCEXP0_APBSPPPCEXP00_Pos*/)                 /* SEC_PRIV_CTRL APBSPPPCEXP0: APBSPPPCEXP00 Mask */

/* SEC_PRIV_CTRL APBSPPPCEXP1 Register Definitions */
#define SEC_PRIV_CTRL_APBSPPPCEXP1_APBSPPPCEXP115_Pos                15                                                          /* SEC_PRIV_CTRL APBSPPPCEXP1: APBSPPPCEXP115 Positions */
#define SEC_PRIV_CTRL_APBSPPPCEXP1_APBSPPPCEXP115_Msk                (0x1UL  << SEC_PRIV_CTRL_APBSPPPCEXP1_APBSPPPCEXP115_Pos)                 /* SEC_PRIV_CTRL APBSPPPCEXP1: APBSPPPCEXP115 Mask */

#define SEC_PRIV_CTRL_APBSPPPCEXP1_ATLC_Pos                14                                                          /* SEC_PRIV_CTRL APBSPPPCEXP1: ATLC Positions */
#define SEC_PRIV_CTRL_APBSPPPCEXP1_ATLC_Msk                (0x1UL  << SEC_PRIV_CTRL_APBSPPPCEXP1_ATLC_Pos)                 /* SEC_PRIV_CTRL APBSPPPCEXP1: ATLC Mask */

#define SEC_PRIV_CTRL_APBSPPPCEXP1_SHUB_Pos                13                                                          /* SEC_PRIV_CTRL APBSPPPCEXP1: SHUB Positions */
#define SEC_PRIV_CTRL_APBSPPPCEXP1_SHUB_Msk                (0x1UL  << SEC_PRIV_CTRL_APBSPPPCEXP1_SHUB_Pos)                 /* SEC_PRIV_CTRL APBSPPPCEXP1: SHUB Mask */

#define SEC_PRIV_CTRL_APBSPPPCEXP1_RCOS_CAL_Pos                12                                                          /* SEC_PRIV_CTRL APBSPPPCEXP1: RCOS_CAL Positions */
#define SEC_PRIV_CTRL_APBSPPPCEXP1_RCOS_CAL_Msk                (0x1UL  << SEC_PRIV_CTRL_APBSPPPCEXP1_RCOS_CAL_Pos)                 /* SEC_PRIV_CTRL APBSPPPCEXP1: RCOS_CAL Mask */

#define SEC_PRIV_CTRL_APBSPPPCEXP1_TRNG_Pos                11                                                          /* SEC_PRIV_CTRL APBSPPPCEXP1: TRNG Positions */
#define SEC_PRIV_CTRL_APBSPPPCEXP1_TRNG_Msk                (0x1UL  << SEC_PRIV_CTRL_APBSPPPCEXP1_TRNG_Pos)                 /* SEC_PRIV_CTRL APBSPPPCEXP1: TRNG Mask */

#define SEC_PRIV_CTRL_APBSPPPCEXP1_GADC_Pos                10                                                          /* SEC_PRIV_CTRL APBSPPPCEXP1: GADC Positions */
#define SEC_PRIV_CTRL_APBSPPPCEXP1_GADC_Msk                (0x1UL  << SEC_PRIV_CTRL_APBSPPPCEXP1_GADC_Pos)                 /* SEC_PRIV_CTRL APBSPPPCEXP1: GADC Mask */

#define SEC_PRIV_CTRL_APBSPPPCEXP1_SWD_Pos                9                                                          /* SEC_PRIV_CTRL APBSPPPCEXP1: SWD Positions */
#define SEC_PRIV_CTRL_APBSPPPCEXP1_SWD_Msk                (0x1UL  << SEC_PRIV_CTRL_APBSPPPCEXP1_SWD_Pos)                 /* SEC_PRIV_CTRL APBSPPPCEXP1: SWD Mask */

#define SEC_PRIV_CTRL_APBSPPPCEXP1_PSEQ_Pos                8                                                          /* SEC_PRIV_CTRL APBSPPPCEXP1: PSEQ Positions */
#define SEC_PRIV_CTRL_APBSPPPCEXP1_PSEQ_Msk                (0x1UL  << SEC_PRIV_CTRL_APBSPPPCEXP1_PSEQ_Pos)                 /* SEC_PRIV_CTRL APBSPPPCEXP1: PSEQ Mask */

#define SEC_PRIV_CTRL_APBSPPPCEXP1_PMU_Pos                7                                                          /* SEC_PRIV_CTRL APBSPPPCEXP1: PMU Positions */
#define SEC_PRIV_CTRL_APBSPPPCEXP1_PMU_Msk                (0x1UL  << SEC_PRIV_CTRL_APBSPPPCEXP1_PMU_Pos)                 /* SEC_PRIV_CTRL APBSPPPCEXP1: PMU Mask */

#define SEC_PRIV_CTRL_APBSPPPCEXP1_MDM_Pos                6                                                          /* SEC_PRIV_CTRL APBSPPPCEXP1: MDM Positions */
#define SEC_PRIV_CTRL_APBSPPPCEXP1_MDM_Msk                (0x1UL  << SEC_PRIV_CTRL_APBSPPPCEXP1_MDM_Pos)                 /* SEC_PRIV_CTRL APBSPPPCEXP1: MDM Mask */

#define SEC_PRIV_CTRL_APBSPPPCEXP1_RADIO_Pos                5                                                          /* SEC_PRIV_CTRL APBSPPPCEXP1: RADIO Positions */
#define SEC_PRIV_CTRL_APBSPPPCEXP1_RADIO_Msk                (0x1UL  << SEC_PRIV_CTRL_APBSPPPCEXP1_RADIO_Pos)                 /* SEC_PRIV_CTRL APBSPPPCEXP1: RADIO Mask */

#define SEC_PRIV_CTRL_APBSPPPCEXP1_RIF_Pos                4                                                          /* SEC_PRIV_CTRL APBSPPPCEXP1: RIF Positions */
#define SEC_PRIV_CTRL_APBSPPPCEXP1_RIF_Msk                (0x1UL  << SEC_PRIV_CTRL_APBSPPPCEXP1_RIF_Pos)                 /* SEC_PRIV_CTRL APBSPPPCEXP1: RIF Mask */

#define SEC_PRIV_CTRL_APBSPPPCEXP1_WRPR_Pos                3                                                          /* SEC_PRIV_CTRL APBSPPPCEXP1: WRPR Positions */
#define SEC_PRIV_CTRL_APBSPPPCEXP1_WRPR_Msk                (0x1UL  << SEC_PRIV_CTRL_APBSPPPCEXP1_WRPR_Pos)                 /* SEC_PRIV_CTRL APBSPPPCEXP1: WRPR Mask */

#define SEC_PRIV_CTRL_APBSPPPCEXP1_NVM_Pos                2                                                          /* SEC_PRIV_CTRL APBSPPPCEXP1: NVM Positions */
#define SEC_PRIV_CTRL_APBSPPPCEXP1_NVM_Msk                (0x1UL  << SEC_PRIV_CTRL_APBSPPPCEXP1_NVM_Pos)                 /* SEC_PRIV_CTRL APBSPPPCEXP1: NVM Mask */

#define SEC_PRIV_CTRL_APBSPPPCEXP1_I2C1_Pos                1                                                          /* SEC_PRIV_CTRL APBSPPPCEXP1: I2C1 Positions */
#define SEC_PRIV_CTRL_APBSPPPCEXP1_I2C1_Msk                (0x1UL  << SEC_PRIV_CTRL_APBSPPPCEXP1_I2C1_Pos)                 /* SEC_PRIV_CTRL APBSPPPCEXP1: I2C1 Mask */

#define SEC_PRIV_CTRL_APBSPPPCEXP1_I2C0_Pos                0                                                          /* SEC_PRIV_CTRL APBSPPPCEXP1: I2C0 Positions */
#define SEC_PRIV_CTRL_APBSPPPCEXP1_I2C0_Msk                (0x1UL  /*<< SEC_PRIV_CTRL_APBSPPPCEXP1_I2C0_Pos*/)                 /* SEC_PRIV_CTRL APBSPPPCEXP1: I2C0 Mask */

/* SEC_PRIV_CTRL APBSPPPCEXP2 Register Definitions */
#define SEC_PRIV_CTRL_APBSPPPCEXP2_APBSPPPCEXP215_Pos                15                                                          /* SEC_PRIV_CTRL APBSPPPCEXP2: APBSPPPCEXP215 Positions */
#define SEC_PRIV_CTRL_APBSPPPCEXP2_APBSPPPCEXP215_Msk                (0x1UL  << SEC_PRIV_CTRL_APBSPPPCEXP2_APBSPPPCEXP215_Pos)                 /* SEC_PRIV_CTRL APBSPPPCEXP2: APBSPPPCEXP215 Mask */

#define SEC_PRIV_CTRL_APBSPPPCEXP2_APBSPPPCEXP214_Pos                14                                                          /* SEC_PRIV_CTRL APBSPPPCEXP2: APBSPPPCEXP214 Positions */
#define SEC_PRIV_CTRL_APBSPPPCEXP2_APBSPPPCEXP214_Msk                (0x1UL  << SEC_PRIV_CTRL_APBSPPPCEXP2_APBSPPPCEXP214_Pos)                 /* SEC_PRIV_CTRL APBSPPPCEXP2: APBSPPPCEXP214 Mask */

#define SEC_PRIV_CTRL_APBSPPPCEXP2_APBSPPPCEXP213_Pos                13                                                          /* SEC_PRIV_CTRL APBSPPPCEXP2: APBSPPPCEXP213 Positions */
#define SEC_PRIV_CTRL_APBSPPPCEXP2_APBSPPPCEXP213_Msk                (0x1UL  << SEC_PRIV_CTRL_APBSPPPCEXP2_APBSPPPCEXP213_Pos)                 /* SEC_PRIV_CTRL APBSPPPCEXP2: APBSPPPCEXP213 Mask */

#define SEC_PRIV_CTRL_APBSPPPCEXP2_APBSPPPCEXP212_Pos                12                                                          /* SEC_PRIV_CTRL APBSPPPCEXP2: APBSPPPCEXP212 Positions */
#define SEC_PRIV_CTRL_APBSPPPCEXP2_APBSPPPCEXP212_Msk                (0x1UL  << SEC_PRIV_CTRL_APBSPPPCEXP2_APBSPPPCEXP212_Pos)                 /* SEC_PRIV_CTRL APBSPPPCEXP2: APBSPPPCEXP212 Mask */

#define SEC_PRIV_CTRL_APBSPPPCEXP2_APBSPPPCEXP211_Pos                11                                                          /* SEC_PRIV_CTRL APBSPPPCEXP2: APBSPPPCEXP211 Positions */
#define SEC_PRIV_CTRL_APBSPPPCEXP2_APBSPPPCEXP211_Msk                (0x1UL  << SEC_PRIV_CTRL_APBSPPPCEXP2_APBSPPPCEXP211_Pos)                 /* SEC_PRIV_CTRL APBSPPPCEXP2: APBSPPPCEXP211 Mask */

#define SEC_PRIV_CTRL_APBSPPPCEXP2_APBSPPPCEXP210_Pos                10                                                          /* SEC_PRIV_CTRL APBSPPPCEXP2: APBSPPPCEXP210 Positions */
#define SEC_PRIV_CTRL_APBSPPPCEXP2_APBSPPPCEXP210_Msk                (0x1UL  << SEC_PRIV_CTRL_APBSPPPCEXP2_APBSPPPCEXP210_Pos)                 /* SEC_PRIV_CTRL APBSPPPCEXP2: APBSPPPCEXP210 Mask */

#define SEC_PRIV_CTRL_APBSPPPCEXP2_APBSPPPCEXP29_Pos                9                                                          /* SEC_PRIV_CTRL APBSPPPCEXP2: APBSPPPCEXP29 Positions */
#define SEC_PRIV_CTRL_APBSPPPCEXP2_APBSPPPCEXP29_Msk                (0x1UL  << SEC_PRIV_CTRL_APBSPPPCEXP2_APBSPPPCEXP29_Pos)                 /* SEC_PRIV_CTRL APBSPPPCEXP2: APBSPPPCEXP29 Mask */

#define SEC_PRIV_CTRL_APBSPPPCEXP2_UART2_Pos                8                                                          /* SEC_PRIV_CTRL APBSPPPCEXP2: UART2 Positions */
#define SEC_PRIV_CTRL_APBSPPPCEXP2_UART2_Msk                (0x1UL  << SEC_PRIV_CTRL_APBSPPPCEXP2_UART2_Pos)                 /* SEC_PRIV_CTRL APBSPPPCEXP2: UART2 Mask */

#define SEC_PRIV_CTRL_APBSPPPCEXP2_AES_Pos                7                                                          /* SEC_PRIV_CTRL APBSPPPCEXP2: AES Positions */
#define SEC_PRIV_CTRL_APBSPPPCEXP2_AES_Msk                (0x1UL  << SEC_PRIV_CTRL_APBSPPPCEXP2_AES_Pos)                 /* SEC_PRIV_CTRL APBSPPPCEXP2: AES Mask */

#define SEC_PRIV_CTRL_APBSPPPCEXP2_CLKRSTGEN_Pos                6                                                          /* SEC_PRIV_CTRL APBSPPPCEXP2: APBSPPPCEXP26 Positions */
#define SEC_PRIV_CTRL_APBSPPPCEXP2_CLKRSTGEN_Msk                (0x1UL  << SEC_PRIV_CTRL_APBSPPPCEXP2_CLKRSTGEN_Pos)                 /* SEC_PRIV_CTRL APBSPPPCEXP2: APBSPPPCEXP26 Mask */

#define SEC_PRIV_CTRL_APBSPPPCEXP2_I2S_Pos                5                                                          /* SEC_PRIV_CTRL APBSPPPCEXP2: I2S Positions */
#define SEC_PRIV_CTRL_APBSPPPCEXP2_I2S_Msk                (0x1UL  << SEC_PRIV_CTRL_APBSPPPCEXP2_I2S_Pos)                 /* SEC_PRIV_CTRL APBSPPPCEXP2: I2S Mask */

#define SEC_PRIV_CTRL_APBSPPPCEXP2_APBSPPPCEXP24_Pos                4                                                          /* SEC_PRIV_CTRL APBSPPPCEXP2: APBSPPPCEXP24 Positions */
#define SEC_PRIV_CTRL_APBSPPPCEXP2_APBSPPPCEXP24_Msk                (0x1UL  << SEC_PRIV_CTRL_APBSPPPCEXP2_APBSPPPCEXP24_Pos)                 /* SEC_PRIV_CTRL APBSPPPCEXP2: APBSPPPCEXP24 Mask */

#define SEC_PRIV_CTRL_APBSPPPCEXP2_WRPR_Pos                3                                                          /* SEC_PRIV_CTRL APBSPPPCEXP2: WRPR Positions */
#define SEC_PRIV_CTRL_APBSPPPCEXP2_WRPR_Msk                (0x1UL  << SEC_PRIV_CTRL_APBSPPPCEXP2_WRPR_Pos)                 /* SEC_PRIV_CTRL APBSPPPCEXP2: WRPR Mask */

#define SEC_PRIV_CTRL_APBSPPPCEXP2_APBSPPPCEXP22_Pos                2                                                          /* SEC_PRIV_CTRL APBSPPPCEXP2: APBSPPPCEXP22 Positions */
#define SEC_PRIV_CTRL_APBSPPPCEXP2_APBSPPPCEXP22_Msk                (0x1UL  << SEC_PRIV_CTRL_APBSPPPCEXP2_APBSPPPCEXP22_Pos)                 /* SEC_PRIV_CTRL APBSPPPCEXP2: APBSPPPCEXP22 Mask */

#define SEC_PRIV_CTRL_APBSPPPCEXP2_APBSPPPCEXP21_Pos                1                                                          /* SEC_PRIV_CTRL APBSPPPCEXP2: APBSPPPCEXP22 Positions */
#define SEC_PRIV_CTRL_APBSPPPCEXP2_APBSPPPCEXP21_Msk                (0x1UL  << SEC_PRIV_CTRL_APBSPPPCEXP2_APBSPPPCEXP21_Pos)                 /* SEC_PRIV_CTRL APBSPPPCEXP2: APBSPPPCEXP22 Mask */

#define SEC_PRIV_CTRL_APBSPPPCEXP2_PDM0_Pos                0                                                          /* SEC_PRIV_CTRL APBSPPPCEXP2: PDM0 Positions */
#define SEC_PRIV_CTRL_APBSPPPCEXP2_PDM0_Msk                (0x1UL  /*<< SEC_PRIV_CTRL_APBSPPPCEXP2_PDM0_Pos*/)                 /* SEC_PRIV_CTRL APBSPPPCEXP2: PDM0 Mask */

/* SEC_PRIV_CTRL APBSPPPCEXP3 Register Definitions */
#define SEC_PRIV_CTRL_APBSPPPCEXP3_APBSPPPCEXP315_Pos                15                                                          /* SEC_PRIV_CTRL APBSPPPCEXP3: APBSPPPCEXP315 Positions */
#define SEC_PRIV_CTRL_APBSPPPCEXP3_APBSPPPCEXP315_Msk                (0x1UL  << SEC_PRIV_CTRL_APBSPPPCEXP3_APBSPPPCEXP315_Pos)                 /* SEC_PRIV_CTRL APBSPPPCEXP3: APBSPPPCEXP315 Mask */

#define SEC_PRIV_CTRL_APBSPPPCEXP3_APBSPPPCEXP314_Pos                14                                                          /* SEC_PRIV_CTRL APBSPPPCEXP3: APBSPPPCEXP314 Positions */
#define SEC_PRIV_CTRL_APBSPPPCEXP3_APBSPPPCEXP314_Msk                (0x1UL  << SEC_PRIV_CTRL_APBSPPPCEXP3_APBSPPPCEXP314_Pos)                 /* SEC_PRIV_CTRL APBSPPPCEXP3: APBSPPPCEXP314 Mask */

#define SEC_PRIV_CTRL_APBSPPPCEXP3_APBSPPPCEXP313_Pos                13                                                          /* SEC_PRIV_CTRL APBSPPPCEXP3: APBSPPPCEXP313 Positions */
#define SEC_PRIV_CTRL_APBSPPPCEXP3_APBSPPPCEXP313_Msk                (0x1UL  << SEC_PRIV_CTRL_APBSPPPCEXP3_APBSPPPCEXP313_Pos)                 /* SEC_PRIV_CTRL APBSPPPCEXP3: APBSPPPCEXP313 Mask */

#define SEC_PRIV_CTRL_APBSPPPCEXP3_APBSPPPCEXP312_Pos                12                                                          /* SEC_PRIV_CTRL APBSPPPCEXP3: APBSPPPCEXP312 Positions */
#define SEC_PRIV_CTRL_APBSPPPCEXP3_APBSPPPCEXP312_Msk                (0x1UL  << SEC_PRIV_CTRL_APBSPPPCEXP3_APBSPPPCEXP312_Pos)                 /* SEC_PRIV_CTRL APBSPPPCEXP3: APBSPPPCEXP312 Mask */

#define SEC_PRIV_CTRL_APBSPPPCEXP3_APBSPPPCEXP311_Pos                11                                                          /* SEC_PRIV_CTRL APBSPPPCEXP3: APBSPPPCEXP311 Positions */
#define SEC_PRIV_CTRL_APBSPPPCEXP3_APBSPPPCEXP311_Msk                (0x1UL  << SEC_PRIV_CTRL_APBSPPPCEXP3_APBSPPPCEXP311_Pos)                 /* SEC_PRIV_CTRL APBSPPPCEXP3: APBSPPPCEXP311 Mask */

#define SEC_PRIV_CTRL_APBSPPPCEXP3_APBSPPPCEXP310_Pos                10                                                          /* SEC_PRIV_CTRL APBSPPPCEXP3: APBSPPPCEXP310 Positions */
#define SEC_PRIV_CTRL_APBSPPPCEXP3_APBSPPPCEXP310_Msk                (0x1UL  << SEC_PRIV_CTRL_APBSPPPCEXP3_APBSPPPCEXP310_Pos)                 /* SEC_PRIV_CTRL APBSPPPCEXP3: APBSPPPCEXP310 Mask */

#define SEC_PRIV_CTRL_APBSPPPCEXP3_APBSPPPCEXP39_Pos                9                                                          /* SEC_PRIV_CTRL APBSPPPCEXP3: APBSPPPCEXP39 Positions */
#define SEC_PRIV_CTRL_APBSPPPCEXP3_APBSPPPCEXP39_Msk                (0x1UL  << SEC_PRIV_CTRL_APBSPPPCEXP3_APBSPPPCEXP39_Pos)                 /* SEC_PRIV_CTRL APBSPPPCEXP3: APBSPPPCEXP39 Mask */

#define SEC_PRIV_CTRL_APBSPPPCEXP3_APBSPPPCEXP38_Pos                8                                                          /* SEC_PRIV_CTRL APBSPPPCEXP3: APBSPPPCEXP38 Positions */
#define SEC_PRIV_CTRL_APBSPPPCEXP3_APBSPPPCEXP38_Msk                (0x1UL  << SEC_PRIV_CTRL_APBSPPPCEXP3_APBSPPPCEXP38_Pos)                 /* SEC_PRIV_CTRL APBSPPPCEXP3: APBSPPPCEXP38 Mask */

#define SEC_PRIV_CTRL_APBSPPPCEXP3_APBSPPPCEXP37_Pos                7                                                          /* SEC_PRIV_CTRL APBSPPPCEXP3: APBSPPPCEXP37 Positions */
#define SEC_PRIV_CTRL_APBSPPPCEXP3_APBSPPPCEXP37_Msk                (0x1UL  << SEC_PRIV_CTRL_APBSPPPCEXP3_APBSPPPCEXP37_Pos)                 /* SEC_PRIV_CTRL APBSPPPCEXP3: APBSPPPCEXP37 Mask */

#define SEC_PRIV_CTRL_APBSPPPCEXP3_APBSPPPCEXP36_Pos                6                                                          /* SEC_PRIV_CTRL APBSPPPCEXP3: APBSPPPCEXP36 Positions */
#define SEC_PRIV_CTRL_APBSPPPCEXP3_APBSPPPCEXP36_Msk                (0x1UL  << SEC_PRIV_CTRL_APBSPPPCEXP3_APBSPPPCEXP36_Pos)                 /* SEC_PRIV_CTRL APBSPPPCEXP3: APBSPPPCEXP36 Mask */

#define SEC_PRIV_CTRL_APBSPPPCEXP3_APBSPPPCEXP35_Pos                5                                                          /* SEC_PRIV_CTRL APBSPPPCEXP3: APBSPPPCEXP35 Positions */
#define SEC_PRIV_CTRL_APBSPPPCEXP3_APBSPPPCEXP35_Msk                (0x1UL  << SEC_PRIV_CTRL_APBSPPPCEXP3_APBSPPPCEXP35_Pos)                 /* SEC_PRIV_CTRL APBSPPPCEXP3: APBSPPPCEXP35 Mask */

#define SEC_PRIV_CTRL_APBSPPPCEXP3_APBSPPPCEXP34_Pos                4                                                          /* SEC_PRIV_CTRL APBSPPPCEXP3: APBSPPPCEXP34 Positions */
#define SEC_PRIV_CTRL_APBSPPPCEXP3_APBSPPPCEXP34_Msk                (0x1UL  << SEC_PRIV_CTRL_APBSPPPCEXP3_APBSPPPCEXP34_Pos)                 /* SEC_PRIV_CTRL APBSPPPCEXP3: APBSPPPCEXP34 Mask */

#define SEC_PRIV_CTRL_APBSPPPCEXP3_APBSPPPCEXP33_Pos                3                                                          /* SEC_PRIV_CTRL APBSPPPCEXP3: APBSPPPCEXP33 Positions */
#define SEC_PRIV_CTRL_APBSPPPCEXP3_APBSPPPCEXP33_Msk                (0x1UL  << SEC_PRIV_CTRL_APBSPPPCEXP3_APBSPPPCEXP33_Pos)                 /* SEC_PRIV_CTRL APBSPPPCEXP3: APBSPPPCEXP33 Mask */

#define SEC_PRIV_CTRL_APBSPPPCEXP3_APBSPPPCEXP32_Pos                2                                                          /* SEC_PRIV_CTRL APBSPPPCEXP3: APBSPPPCEXP32 Positions */
#define SEC_PRIV_CTRL_APBSPPPCEXP3_APBSPPPCEXP32_Msk                (0x1UL  << SEC_PRIV_CTRL_APBSPPPCEXP3_APBSPPPCEXP32_Pos)                 /* SEC_PRIV_CTRL APBSPPPCEXP3: APBSPPPCEXP32 Mask */

#define SEC_PRIV_CTRL_APBSPPPCEXP3_APBSPPPCEXP31_Pos                1                                                          /* SEC_PRIV_CTRL APBSPPPCEXP3: APBSPPPCEXP31 Positions */
#define SEC_PRIV_CTRL_APBSPPPCEXP3_APBSPPPCEXP31_Msk                (0x1UL  << SEC_PRIV_CTRL_APBSPPPCEXP3_APBSPPPCEXP31_Pos)                 /* SEC_PRIV_CTRL APBSPPPCEXP3: APBSPPPCEXP31 Mask */

#define SEC_PRIV_CTRL_APBSPPPCEXP3_APBSPPPCEXP30_Pos                0                                                          /* SEC_PRIV_CTRL APBSPPPCEXP3: APBSPPPCEXP30 Positions */
#define SEC_PRIV_CTRL_APBSPPPCEXP3_APBSPPPCEXP30_Msk                (0x1UL  /*<< SEC_PRIV_CTRL_APBSPPPCEXP3_APBSPPPCEXP30_Pos*/)                 /* SEC_PRIV_CTRL APBSPPPCEXP3: APBSPPPCEXP30 Mask */

/* SEC_PRIV_CTRL NSMSCEXP Register Definitions */
#define SEC_PRIV_CTRL_NSMSCEXP_NS_MSCEXP15_Pos                31                                                          /* SEC_PRIV_CTRL NSMSCEXP: NS_MSCEXP15 Positions */
#define SEC_PRIV_CTRL_NSMSCEXP_NS_MSCEXP15_Msk                (0x1UL  << SEC_PRIV_CTRL_NSMSCEXP_NS_MSCEXP15_Pos)                 /* SEC_PRIV_CTRL NSMSCEXP: NS_MSCEXP15 Mask */

#define SEC_PRIV_CTRL_NSMSCEXP_NS_MSCEXP14_Pos                30                                                          /* SEC_PRIV_CTRL NSMSCEXP: NS_MSCEXP14 Positions */
#define SEC_PRIV_CTRL_NSMSCEXP_NS_MSCEXP14_Msk                (0x1UL  << SEC_PRIV_CTRL_NSMSCEXP_NS_MSCEXP14_Pos)                 /* SEC_PRIV_CTRL NSMSCEXP: NS_MSCEXP14 Mask */

#define SEC_PRIV_CTRL_NSMSCEXP_NS_MSCEXP13_Pos                29                                                          /* SEC_PRIV_CTRL NSMSCEXP: NS_MSCEXP13 Positions */
#define SEC_PRIV_CTRL_NSMSCEXP_NS_MSCEXP13_Msk                (0x1UL  << SEC_PRIV_CTRL_NSMSCEXP_NS_MSCEXP13_Pos)                 /* SEC_PRIV_CTRL NSMSCEXP: NS_MSCEXP13 Mask */

#define SEC_PRIV_CTRL_NSMSCEXP_NS_MSCEXP12_Pos                28                                                          /* SEC_PRIV_CTRL NSMSCEXP: NS_MSCEXP12 Positions */
#define SEC_PRIV_CTRL_NSMSCEXP_NS_MSCEXP12_Msk                (0x1UL  << SEC_PRIV_CTRL_NSMSCEXP_NS_MSCEXP12_Pos)                 /* SEC_PRIV_CTRL NSMSCEXP: NS_MSCEXP12 Mask */

#define SEC_PRIV_CTRL_NSMSCEXP_NS_MSCEXP11_Pos                27                                                          /* SEC_PRIV_CTRL NSMSCEXP: NS_MSCEXP11 Positions */
#define SEC_PRIV_CTRL_NSMSCEXP_NS_MSCEXP11_Msk                (0x1UL  << SEC_PRIV_CTRL_NSMSCEXP_NS_MSCEXP11_Pos)                 /* SEC_PRIV_CTRL NSMSCEXP: NS_MSCEXP11 Mask */

#define SEC_PRIV_CTRL_NSMSCEXP_NS_MSCEXP10_Pos                26                                                          /* SEC_PRIV_CTRL NSMSCEXP: NS_MSCEXP10 Positions */
#define SEC_PRIV_CTRL_NSMSCEXP_NS_MSCEXP10_Msk                (0x1UL  << SEC_PRIV_CTRL_NSMSCEXP_NS_MSCEXP10_Pos)                 /* SEC_PRIV_CTRL NSMSCEXP: NS_MSCEXP10 Mask */

#define SEC_PRIV_CTRL_NSMSCEXP_NS_MSCEXP9_Pos                25                                                          /* SEC_PRIV_CTRL NSMSCEXP: NS_MSCEXP9 Positions */
#define SEC_PRIV_CTRL_NSMSCEXP_NS_MSCEXP9_Msk                (0x1UL  << SEC_PRIV_CTRL_NSMSCEXP_NS_MSCEXP9_Pos)                 /* SEC_PRIV_CTRL NSMSCEXP: NS_MSCEXP9 Mask */

#define SEC_PRIV_CTRL_NSMSCEXP_NS_MSCEXP8_Pos                24                                                          /* SEC_PRIV_CTRL NSMSCEXP: NS_MSCEXP8 Positions */
#define SEC_PRIV_CTRL_NSMSCEXP_NS_MSCEXP8_Msk                (0x1UL  << SEC_PRIV_CTRL_NSMSCEXP_NS_MSCEXP8_Pos)                 /* SEC_PRIV_CTRL NSMSCEXP: NS_MSCEXP8 Mask */

#define SEC_PRIV_CTRL_NSMSCEXP_NS_MSCEXP7_Pos                23                                                          /* SEC_PRIV_CTRL NSMSCEXP: NS_MSCEXP7 Positions */
#define SEC_PRIV_CTRL_NSMSCEXP_NS_MSCEXP7_Msk                (0x1UL  << SEC_PRIV_CTRL_NSMSCEXP_NS_MSCEXP7_Pos)                 /* SEC_PRIV_CTRL NSMSCEXP: NS_MSCEXP7 Mask */

#define SEC_PRIV_CTRL_NSMSCEXP_NS_MSCEXP6_Pos                22                                                          /* SEC_PRIV_CTRL NSMSCEXP: NS_MSCEXP6 Positions */
#define SEC_PRIV_CTRL_NSMSCEXP_NS_MSCEXP6_Msk                (0x1UL  << SEC_PRIV_CTRL_NSMSCEXP_NS_MSCEXP6_Pos)                 /* SEC_PRIV_CTRL NSMSCEXP: NS_MSCEXP6 Mask */

#define SEC_PRIV_CTRL_NSMSCEXP_NS_MSCEXP5_Pos                21                                                          /* SEC_PRIV_CTRL NSMSCEXP: NS_MSCEXP5 Positions */
#define SEC_PRIV_CTRL_NSMSCEXP_NS_MSCEXP5_Msk                (0x1UL  << SEC_PRIV_CTRL_NSMSCEXP_NS_MSCEXP5_Pos)                 /* SEC_PRIV_CTRL NSMSCEXP: NS_MSCEXP5 Mask */

#define SEC_PRIV_CTRL_NSMSCEXP_NS_MSCEXP4_Pos                20                                                          /* SEC_PRIV_CTRL NSMSCEXP: NS_MSCEXP4 Positions */
#define SEC_PRIV_CTRL_NSMSCEXP_NS_MSCEXP4_Msk                (0x1UL  << SEC_PRIV_CTRL_NSMSCEXP_NS_MSCEXP4_Pos)                 /* SEC_PRIV_CTRL NSMSCEXP: NS_MSCEXP4 Mask */

#define SEC_PRIV_CTRL_NSMSCEXP_NS_MSCEXP3_Pos                19                                                          /* SEC_PRIV_CTRL NSMSCEXP: NS_MSCEXP3 Positions */
#define SEC_PRIV_CTRL_NSMSCEXP_NS_MSCEXP3_Msk                (0x1UL  << SEC_PRIV_CTRL_NSMSCEXP_NS_MSCEXP3_Pos)                 /* SEC_PRIV_CTRL NSMSCEXP: NS_MSCEXP3 Mask */

#define SEC_PRIV_CTRL_NSMSCEXP_NS_MSCEXP2_Pos                18                                                          /* SEC_PRIV_CTRL NSMSCEXP: NS_MSCEXP2 Positions */
#define SEC_PRIV_CTRL_NSMSCEXP_NS_MSCEXP2_Msk                (0x1UL  << SEC_PRIV_CTRL_NSMSCEXP_NS_MSCEXP2_Pos)                 /* SEC_PRIV_CTRL NSMSCEXP: NS_MSCEXP2 Mask */

#define SEC_PRIV_CTRL_NSMSCEXP_NS_MSCEXP1_Pos                17                                                          /* SEC_PRIV_CTRL NSMSCEXP: NS_MSCEXP1 Positions */
#define SEC_PRIV_CTRL_NSMSCEXP_NS_MSCEXP1_Msk                (0x1UL  << SEC_PRIV_CTRL_NSMSCEXP_NS_MSCEXP1_Pos)                 /* SEC_PRIV_CTRL NSMSCEXP: NS_MSCEXP1 Mask */

#define SEC_PRIV_CTRL_NSMSCEXP_NS_MSCEXP0_Pos                16                                                          /* SEC_PRIV_CTRL NSMSCEXP: NS_MSCEXP0 Positions */
#define SEC_PRIV_CTRL_NSMSCEXP_NS_MSCEXP0_Msk                (0x1UL  << SEC_PRIV_CTRL_NSMSCEXP_NS_MSCEXP0_Pos)                 /* SEC_PRIV_CTRL NSMSCEXP: NS_MSCEXP0 Mask */

/* SEC_PRIV_CTRL PIDR4 Register Definitions */
#define SEC_PRIV_CTRL_PIDR4_SIZE_Pos                4                                                          /* SEC_PRIV_CTRL PIDR4: SIZE Positions */
#define SEC_PRIV_CTRL_PIDR4_SIZE_Msk                (0xFUL  << SEC_PRIV_CTRL_PIDR4_SIZE_Pos)                 /* SEC_PRIV_CTRL PIDR4: SIZE Mask */

#define SEC_PRIV_CTRL_PIDR4_DES_2_Pos                0                                                          /* SEC_PRIV_CTRL PIDR4: DES_2 Positions */
#define SEC_PRIV_CTRL_PIDR4_DES_2_Msk                (0xFUL  /*<< SEC_PRIV_CTRL_PIDR4_DES_2_Pos*/)                 /* SEC_PRIV_CTRL PIDR4: DES_2 Mask */

/* SEC_PRIV_CTRL PIDR0 Register Definitions */
#define SEC_PRIV_CTRL_PIDR0_PART_0_Pos                0                                                          /* SEC_PRIV_CTRL PIDR0: PART_0 Positions */
#define SEC_PRIV_CTRL_PIDR0_PART_0_Msk                (0xFFUL  /*<< SEC_PRIV_CTRL_PIDR0_PART_0_Pos*/)                 /* SEC_PRIV_CTRL PIDR0: PART_0 Mask */

/* SEC_PRIV_CTRL PIDR1 Register Definitions */
#define SEC_PRIV_CTRL_PIDR1_DES_0_Pos                4                                                          /* SEC_PRIV_CTRL PIDR1: DES_0 Positions */
#define SEC_PRIV_CTRL_PIDR1_DES_0_Msk                (0xFUL  << SEC_PRIV_CTRL_PIDR1_DES_0_Pos)                 /* SEC_PRIV_CTRL PIDR1: DES_0 Mask */

#define SEC_PRIV_CTRL_PIDR1_PART_1_Pos                0                                                          /* SEC_PRIV_CTRL PIDR1: PART_1 Positions */
#define SEC_PRIV_CTRL_PIDR1_PART_1_Msk                (0xFUL  /*<< SEC_PRIV_CTRL_PIDR1_PART_1_Pos*/)                 /* SEC_PRIV_CTRL PIDR1: PART_1 Mask */

/* SEC_PRIV_CTRL PIDR2 Register Definitions */
#define SEC_PRIV_CTRL_PIDR2_REVISION_Pos                4                                                          /* SEC_PRIV_CTRL PIDR2: REVISION Positions */
#define SEC_PRIV_CTRL_PIDR2_REVISION_Msk                (0xFUL  << SEC_PRIV_CTRL_PIDR2_REVISION_Pos)                 /* SEC_PRIV_CTRL PIDR2: REVISION Mask */

#define SEC_PRIV_CTRL_PIDR2_JEDEC_Pos                3                                                          /* SEC_PRIV_CTRL PIDR2: JEDEC Positions */
#define SEC_PRIV_CTRL_PIDR2_JEDEC_Msk                (0x1UL  << SEC_PRIV_CTRL_PIDR2_JEDEC_Pos)                 /* SEC_PRIV_CTRL PIDR2: JEDEC Mask */

#define SEC_PRIV_CTRL_PIDR2_DES_1_Pos                0                                                          /* SEC_PRIV_CTRL PIDR2: DES_1 Positions */
#define SEC_PRIV_CTRL_PIDR2_DES_1_Msk                (0x7UL  /*<< SEC_PRIV_CTRL_PIDR2_DES_1_Pos*/)                 /* SEC_PRIV_CTRL PIDR2: DES_1 Mask */

/* SEC_PRIV_CTRL PIDR3 Register Definitions */
#define SEC_PRIV_CTRL_PIDR3_REVAND_Pos                4                                                          /* SEC_PRIV_CTRL PIDR3: REVAND Positions */
#define SEC_PRIV_CTRL_PIDR3_REVAND_Msk                (0xFUL  << SEC_PRIV_CTRL_PIDR3_REVAND_Pos)                 /* SEC_PRIV_CTRL PIDR3: REVAND Mask */

#define SEC_PRIV_CTRL_PIDR3_CMOD_Pos                0                                                          /* SEC_PRIV_CTRL PIDR3: CMOD Positions */
#define SEC_PRIV_CTRL_PIDR3_CMOD_Msk                (0xFUL  /*<< SEC_PRIV_CTRL_PIDR3_CMOD_Pos*/)                 /* SEC_PRIV_CTRL PIDR3: CMOD Mask */

/* SEC_PRIV_CTRL CIDR0 Register Definitions */
#define SEC_PRIV_CTRL_CIDR0_PRMBL_0_Pos                0                                                          /* SEC_PRIV_CTRL CIDR0: PRMBL_0 Positions */
#define SEC_PRIV_CTRL_CIDR0_PRMBL_0_Msk                (0xFFUL  /*<< SEC_PRIV_CTRL_CIDR0_PRMBL_0_Pos*/)                 /* SEC_PRIV_CTRL CIDR0: PRMBL_0 Mask */

/* SEC_PRIV_CTRL CIDR1 Register Definitions */
#define SEC_PRIV_CTRL_CIDR1_CLASS_Pos                4                                                          /* SEC_PRIV_CTRL CIDR1: CLASS Positions */
#define SEC_PRIV_CTRL_CIDR1_CLASS_Msk                (0xFUL  << SEC_PRIV_CTRL_CIDR1_CLASS_Pos)                 /* SEC_PRIV_CTRL CIDR1: CLASS Mask */

#define SEC_PRIV_CTRL_CIDR1_PRMBL_1_Pos                0                                                          /* SEC_PRIV_CTRL CIDR1: PRMBL_1 Positions */
#define SEC_PRIV_CTRL_CIDR1_PRMBL_1_Msk                (0xFUL  /*<< SEC_PRIV_CTRL_CIDR1_PRMBL_1_Pos*/)                 /* SEC_PRIV_CTRL CIDR1: PRMBL_1 Mask */

/* SEC_PRIV_CTRL CIDR2 Register Definitions */
#define SEC_PRIV_CTRL_CIDR2_PRMBL_2_Pos                0                                                          /* SEC_PRIV_CTRL CIDR2: PRMBL_2 Positions */
#define SEC_PRIV_CTRL_CIDR2_PRMBL_2_Msk                (0xFFUL  /*<< SEC_PRIV_CTRL_CIDR2_PRMBL_2_Pos*/)                 /* SEC_PRIV_CTRL CIDR2: PRMBL_2 Mask */

/* SEC_PRIV_CTRL CIDR3 Register Definitions */
#define SEC_PRIV_CTRL_CIDR3_PRMBL_3_Pos                0                                                          /* SEC_PRIV_CTRL CIDR3: PRMBL_3 Positions */
#define SEC_PRIV_CTRL_CIDR3_PRMBL_3_Msk                (0xFFUL  /*<< SEC_PRIV_CTRL_CIDR3_PRMBL_3_Pos*/)                 /* SEC_PRIV_CTRL CIDR3: PRMBL_3 Mask */


/*----------------------------- NONSECURE PRIVILEGE CONTROL REGISTER ---------------------------------------------*/
typedef struct
{
       uint32_t RESERVED0[40];
__IOM  uint32_t AHBNSPPPCEXP0;                  /* Offset: 0xA0 (read-write) AHBNSPPPCEXP0 Register    */
__IOM  uint32_t AHBNSPPPCEXP1;                  /* Offset: 0xA4 (read-write) AHBNSPPPCEXP1 Register    */
__IOM  uint32_t AHBNSPPPCEXP2;                  /* Offset: 0xA8 (read-write) AHBNSPPPCEXP2 Register    */
__IOM  uint32_t AHBNSPPPCEXP3;                  /* Offset: 0xAC (read-write) AHBNSPPPCEXP3 Register    */
__IOM  uint32_t APBNSPPPC0;                  /* Offset: 0xB0 (read-write) APBNSPPPC0 Register    */
__IOM  uint32_t APBNSPPPC1;                  /* Offset: 0xB4 (read-write) APBNSPPPC1 Register    */
       uint32_t RESERVED1[2];
__IOM  uint32_t APBNSPPPCEXP0;                  /* Offset: 0xC0 (read-write) APBNSPPPCEXP0 Register    */
__IOM  uint32_t APBNSPPPCEXP1;                  /* Offset: 0xC4 (read-write) APBNSPPPCEXP1 Register    */
__IOM  uint32_t APBNSPPPCEXP2;                  /* Offset: 0xC8 (read-write) APBNSPPPCEXP2 Register    */
__IOM  uint32_t APBNSPPPCEXP3;                  /* Offset: 0xCC (read-write) APBNSPPPCEXP3 Register    */
       uint32_t RESERVED2[960];
__IM   uint32_t PIDR4;                  /* Offset: 0xFD0 (read-only) PIDR4 Register    */
       uint32_t RESERVED3[3];
__IM   uint32_t PIDR0;                  /* Offset: 0xFE0 (read-only) PIDR0 Register    */
__IM   uint32_t PIDR1;                  /* Offset: 0xFE4 (read-only) PIDR1 Register    */
__IM   uint32_t PIDR2;                  /* Offset: 0xFE8 (read-only) PIDR2 Register    */
__IM   uint32_t PIDR3;                  /* Offset: 0xFEC (read-only) PIDR3 Register    */
__IM   uint32_t CIDR0;                  /* Offset: 0xFF0 (read-only) CIDR0 Register    */
__IM   uint32_t CIDR1;                  /* Offset: 0xFF4 (read-only) CIDR1 Register    */
__IM   uint32_t CIDR2;                  /* Offset: 0xFF8 (read-only) CIDR2 Register    */
__IM   uint32_t CIDR3;                  /* Offset: 0xFFC (read-only) CIDR3 Register    */
}NONSEC_PRIV_CTRL_TypeDef;

/* NONSEC_PRIV_CTRL AHBNSPPPCEXP0 Register Definitions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP0_AHBNSPPPCEXP015_Pos                15                                                          /* NONSEC_PRIV_CTRL AHBNSPPPCEXP0: AHBNSPPPCEXP015 Positions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP0_AHBNSPPPCEXP015_Msk                (0x1UL  << NONSEC_PRIV_CTRL_AHBNSPPPCEXP0_AHBNSPPPCEXP015_Pos)                 /* NONSEC_PRIV_CTRL AHBNSPPPCEXP0: AHBNSPPPCEXP015 Mask */

#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP0_AHBNSPPPCEXP014_Pos                14                                                          /* NONSEC_PRIV_CTRL AHBNSPPPCEXP0: AHBNSPPPCEXP014 Positions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP0_AHBNSPPPCEXP014_Msk                (0x1UL  << NONSEC_PRIV_CTRL_AHBNSPPPCEXP0_AHBNSPPPCEXP014_Pos)                 /* NONSEC_PRIV_CTRL AHBNSPPPCEXP0: AHBNSPPPCEXP014 Mask */

#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP0_AHBNSPPPCEXP013_Pos                13                                                          /* NONSEC_PRIV_CTRL AHBNSPPPCEXP0: AHBNSPPPCEXP013 Positions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP0_AHBNSPPPCEXP013_Msk                (0x1UL  << NONSEC_PRIV_CTRL_AHBNSPPPCEXP0_AHBNSPPPCEXP013_Pos)                 /* NONSEC_PRIV_CTRL AHBNSPPPCEXP0: AHBNSPPPCEXP013 Mask */

#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP0_AHBNSPPPCEXP012_Pos                12                                                          /* NONSEC_PRIV_CTRL AHBNSPPPCEXP0: AHBNSPPPCEXP012 Positions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP0_AHBNSPPPCEXP012_Msk                (0x1UL  << NONSEC_PRIV_CTRL_AHBNSPPPCEXP0_AHBNSPPPCEXP012_Pos)                 /* NONSEC_PRIV_CTRL AHBNSPPPCEXP0: AHBNSPPPCEXP012 Mask */

#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP0_AHBNSPPPCEXP011_Pos                11                                                          /* NONSEC_PRIV_CTRL AHBNSPPPCEXP0: AHBNSPPPCEXP011 Positions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP0_AHBNSPPPCEXP011_Msk                (0x1UL  << NONSEC_PRIV_CTRL_AHBNSPPPCEXP0_AHBNSPPPCEXP011_Pos)                 /* NONSEC_PRIV_CTRL AHBNSPPPCEXP0: AHBNSPPPCEXP011 Mask */

#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP0_AHBNSPPPCEXP010_Pos                10                                                          /* NONSEC_PRIV_CTRL AHBNSPPPCEXP0: AHBNSPPPCEXP010 Positions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP0_AHBNSPPPCEXP010_Msk                (0x1UL  << NONSEC_PRIV_CTRL_AHBNSPPPCEXP0_AHBNSPPPCEXP010_Pos)                 /* NONSEC_PRIV_CTRL AHBNSPPPCEXP0: AHBNSPPPCEXP010 Mask */

#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP0_AHBNSPPPCEXP09_Pos                9                                                          /* NONSEC_PRIV_CTRL AHBNSPPPCEXP0: AHBNSPPPCEXP09 Positions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP0_AHBNSPPPCEXP09_Msk                (0x1UL  << NONSEC_PRIV_CTRL_AHBNSPPPCEXP0_AHBNSPPPCEXP09_Pos)                 /* NONSEC_PRIV_CTRL AHBNSPPPCEXP0: AHBNSPPPCEXP09 Mask */

#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP0_AHBNSPPPCEXP08_Pos                8                                                          /* NONSEC_PRIV_CTRL AHBNSPPPCEXP0: AHBNSPPPCEXP08 Positions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP0_AHBNSPPPCEXP08_Msk                (0x1UL  << NONSEC_PRIV_CTRL_AHBNSPPPCEXP0_AHBNSPPPCEXP08_Pos)                 /* NONSEC_PRIV_CTRL AHBNSPPPCEXP0: AHBNSPPPCEXP08 Mask */

#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP0_AHBNSPPPCEXP07_Pos                7                                                          /* NONSEC_PRIV_CTRL AHBNSPPPCEXP0: AHBNSPPPCEXP07 Positions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP0_AHBNSPPPCEXP07_Msk                (0x1UL  << NONSEC_PRIV_CTRL_AHBNSPPPCEXP0_AHBNSPPPCEXP07_Pos)                 /* NONSEC_PRIV_CTRL AHBNSPPPCEXP0: AHBNSPPPCEXP07 Mask */

#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP0_AHBNSPPPCEXP06_Pos                6                                                          /* NONSEC_PRIV_CTRL AHBNSPPPCEXP0: AHBNSPPPCEXP06 Positions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP0_AHBNSPPPCEXP06_Msk                (0x1UL  << NONSEC_PRIV_CTRL_AHBNSPPPCEXP0_AHBNSPPPCEXP06_Pos)                 /* NONSEC_PRIV_CTRL AHBNSPPPCEXP0: AHBNSPPPCEXP06 Mask */

#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP0_AHBNSPPPCEXP05_Pos                5                                                          /* NONSEC_PRIV_CTRL AHBNSPPPCEXP0: AHBNSPPPCEXP05 Positions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP0_AHBNSPPPCEXP05_Msk                (0x1UL  << NONSEC_PRIV_CTRL_AHBNSPPPCEXP0_AHBNSPPPCEXP05_Pos)                 /* NONSEC_PRIV_CTRL AHBNSPPPCEXP0: AHBNSPPPCEXP05 Mask */

#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP0_AHBNSPPPCEXP04_Pos                4                                                          /* NONSEC_PRIV_CTRL AHBNSPPPCEXP0: AHBNSPPPCEXP04 Positions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP0_AHBNSPPPCEXP04_Msk                (0x1UL  << NONSEC_PRIV_CTRL_AHBNSPPPCEXP0_AHBNSPPPCEXP04_Pos)                 /* NONSEC_PRIV_CTRL AHBNSPPPCEXP0: AHBNSPPPCEXP04 Mask */

#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP0_AHBNSPPPCEXP03_Pos                3                                                          /* NONSEC_PRIV_CTRL AHBNSPPPCEXP0: AHBNSPPPCEXP03 Positions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP0_AHBNSPPPCEXP03_Msk                (0x1UL  << NONSEC_PRIV_CTRL_AHBNSPPPCEXP0_AHBNSPPPCEXP03_Pos)                 /* NONSEC_PRIV_CTRL AHBNSPPPCEXP0: AHBNSPPPCEXP03 Mask */

#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP0_AHBNSPPPCEXP02_Pos                2                                                          /* NONSEC_PRIV_CTRL AHBNSPPPCEXP0: AHBNSPPPCEXP02 Positions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP0_AHBNSPPPCEXP02_Msk                (0x1UL  << NONSEC_PRIV_CTRL_AHBNSPPPCEXP0_AHBNSPPPCEXP02_Pos)                 /* NONSEC_PRIV_CTRL AHBNSPPPCEXP0: AHBNSPPPCEXP02 Mask */

#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP0_AHBNSPPPCEXP01_Pos                1                                                          /* NONSEC_PRIV_CTRL AHBNSPPPCEXP0: AHBNSPPPCEXP01 Positions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP0_AHBNSPPPCEXP01_Msk                (0x1UL  << NONSEC_PRIV_CTRL_AHBNSPPPCEXP0_AHBNSPPPCEXP01_Pos)                 /* NONSEC_PRIV_CTRL AHBNSPPPCEXP0: AHBNSPPPCEXP01 Mask */

#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP0_AHBNSPPPCEXP00_Pos                0                                                          /* NONSEC_PRIV_CTRL AHBNSPPPCEXP0: AHBNSPPPCEXP00 Positions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP0_AHBNSPPPCEXP00_Msk                (0x1UL  /*<< NONSEC_PRIV_CTRL_AHBNSPPPCEXP0_AHBNSPPPCEXP00_Pos*/)                 /* NONSEC_PRIV_CTRL AHBNSPPPCEXP0: AHBNSPPPCEXP00 Mask */

/* NONSEC_PRIV_CTRL AHBNSPPPCEXP1 Register Definitions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP1_AHBNSPPPCEXP115_Pos                15                                                          /* NONSEC_PRIV_CTRL AHBNSPPPCEXP1: AHBNSPPPCEXP115 Positions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP1_AHBNSPPPCEXP115_Msk                (0x1UL  << NONSEC_PRIV_CTRL_AHBNSPPPCEXP1_AHBNSPPPCEXP115_Pos)                 /* NONSEC_PRIV_CTRL AHBNSPPPCEXP1: AHBNSPPPCEXP115 Mask */

#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP1_GPIO2_Pos                14                                                          /* NONSEC_PRIV_CTRL AHBNSPPPCEXP1: AHBNSPPPCEXP114 Positions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP1_GPIO2_Msk                (0x1UL  << NONSEC_PRIV_CTRL_AHBNSPPPCEXP1_GPIO2_Pos)                 /* NONSEC_PRIV_CTRL AHBNSPPPCEXP1: AHBNSPPPCEXP114 Mask */

#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP1_GPIO3_Pos                15						            /* NONSEC_PRIV_CTRL AHBNSPPPCEXP1: AHBNSPPPCEXP114 Positions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP1_GPIO3_Msk                (0x1UL  << NONSEC_PRIV_CTRL_AHBNSPPPCEXP1_GPIO3_Pos)                 /* NONSEC_PRIV_CTRL AHBNSPPPCEXP1: AHBNSPPPCEXP114 Mask */

#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP1_AHBNSPPPCEXP113_Pos                13                                                          /* NONSEC_PRIV_CTRL AHBNSPPPCEXP1: AHBNSPPPCEXP113 Positions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP1_AHBNSPPPCEXP113_Msk                (0x1UL  << NONSEC_PRIV_CTRL_AHBNSPPPCEXP1_AHBNSPPPCEXP113_Pos)                 /* NONSEC_PRIV_CTRL AHBNSPPPCEXP1: AHBNSPPPCEXP113 Mask */

#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP1_AHBNSPPPCEXP112_Pos                12                                                          /* NONSEC_PRIV_CTRL AHBNSPPPCEXP1: AHBNSPPPCEXP112 Positions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP1_AHBNSPPPCEXP112_Msk                (0x1UL  << NONSEC_PRIV_CTRL_AHBNSPPPCEXP1_AHBNSPPPCEXP112_Pos)                 /* NONSEC_PRIV_CTRL AHBNSPPPCEXP1: AHBNSPPPCEXP112 Mask */

#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP1_AHBNSPPPCEXP111_Pos                11                                                          /* NONSEC_PRIV_CTRL AHBNSPPPCEXP1: AHBNSPPPCEXP111 Positions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP1_AHBNSPPPCEXP111_Msk                (0x1UL  << NONSEC_PRIV_CTRL_AHBNSPPPCEXP1_AHBNSPPPCEXP111_Pos)                 /* NONSEC_PRIV_CTRL AHBNSPPPCEXP1: AHBNSPPPCEXP111 Mask */

#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP1_AHBNSPPPCEXP110_Pos                10                                                          /* NONSEC_PRIV_CTRL AHBNSPPPCEXP1: AHBNSPPPCEXP110 Positions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP1_AHBNSPPPCEXP110_Msk                (0x1UL  << NONSEC_PRIV_CTRL_AHBNSPPPCEXP1_AHBNSPPPCEXP110_Pos)                 /* NONSEC_PRIV_CTRL AHBNSPPPCEXP1: AHBNSPPPCEXP110 Mask */

#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP1_BLE52_Pos                9                                                          /* NONSEC_PRIV_CTRL AHBNSPPPCEXP1: BLE52 Positions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP1_BLE52_Msk                (0x1UL  << NONSEC_PRIV_CTRL_AHBNSPPPCEXP1_BLE52_Pos)                 /* NONSEC_PRIV_CTRL AHBNSPPPCEXP1: BLE52 Mask */

#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP1_I2S_Pos                8                                                          /* NONSEC_PRIV_CTRL AHBNSPPPCEXP1: I2S Positions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP1_I2S_Msk                (0x1UL  << NONSEC_PRIV_CTRL_AHBNSPPPCEXP1_I2S_Pos)                 /* NONSEC_PRIV_CTRL AHBNSPPPCEXP1: I2S Mask */

#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP1_AHBNSPPPCEXP17_Pos                7                                                          /* NONSEC_PRIV_CTRL AHBNSPPPCEXP1: AHBNSPPPCEXP17 Positions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP1_AHBNSPPPCEXP17_Msk                (0x1UL  << NONSEC_PRIV_CTRL_AHBNSPPPCEXP1_AHBNSPPPCEXP17_Pos)                 /* NONSEC_PRIV_CTRL AHBNSPPPCEXP1: AHBNSPPPCEXP17 Mask */

#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP1_PDM0_Pos                6                                                          /* NONSEC_PRIV_CTRL AHBNSPPPCEXP1: PDM0 Positions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP1_PDM0_Msk                (0x1UL  << NONSEC_PRIV_CTRL_AHBNSPPPCEXP1_PDM0_Pos)                 /* NONSEC_PRIV_CTRL AHBNSPPPCEXP1: PDM0 Mask */

#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP1_AHBNSPPPCEXP15_Pos                5                                                          /* NONSEC_PRIV_CTRL AHBNSPPPCEXP1: AHBNSPPPCEXP15 Positions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP1_AHBNSPPPCEXP15_Msk                (0x1UL  << NONSEC_PRIV_CTRL_AHBNSPPPCEXP1_AHBNSPPPCEXP15_Pos)                 /* NONSEC_PRIV_CTRL AHBNSPPPCEXP1: AHBNSPPPCEXP15 Mask */

#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP1_AHBNSPPPCEXP14_Pos                4                                                          /* NONSEC_PRIV_CTRL AHBNSPPPCEXP1: AHBNSPPPCEXP14 Positions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP1_AHBNSPPPCEXP14_Msk                (0x1UL  << NONSEC_PRIV_CTRL_AHBNSPPPCEXP1_AHBNSPPPCEXP14_Pos)                 /* NONSEC_PRIV_CTRL AHBNSPPPCEXP1: AHBNSPPPCEXP14 Mask */

#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP1_DMA_Pos                3                                                          /* NONSEC_PRIV_CTRL AHBNSPPPCEXP1: DMA Positions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP1_DMA_Msk                (0x1UL  << NONSEC_PRIV_CTRL_AHBNSPPPCEXP1_DMA_Pos)                 /* NONSEC_PRIV_CTRL AHBNSPPPCEXP1: DMA Mask */

#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP1_SHA2_Pos                2                                                          /* NONSEC_PRIV_CTRL AHBNSPPPCEXP1: SHA2 Positions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP1_SHA2_Msk                (0x1UL  << NONSEC_PRIV_CTRL_AHBNSPPPCEXP1_SHA2_Pos)                 /* NONSEC_PRIV_CTRL AHBNSPPPCEXP1: SHA2 Mask */

#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP1_GPIO1_Pos                1                                                          /* NONSEC_PRIV_CTRL AHBNSPPPCEXP1: GPIO1 Positions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP1_GPIO1_Msk                (0x1UL  << NONSEC_PRIV_CTRL_AHBNSPPPCEXP1_GPIO1_Pos)                 /* NONSEC_PRIV_CTRL AHBNSPPPCEXP1: GPIO1 Mask */

#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP1_GPIO0_Pos                0                                                          /* NONSEC_PRIV_CTRL AHBNSPPPCEXP1: GPIO0 Positions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP1_GPIO0_Msk                (0x1UL  /*<< NONSEC_PRIV_CTRL_AHBNSPPPCEXP1_GPIO0_Pos*/)                 /* NONSEC_PRIV_CTRL AHBNSPPPCEXP1: GPIO0 Mask */

/* NONSEC_PRIV_CTRL AHBNSPPPCEXP2 Register Definitions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP2_AHBNSPPPCEXP215_Pos                15                                                          /* NONSEC_PRIV_CTRL AHBNSPPPCEXP2: AHBNSPPPCEXP215 Positions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP2_AHBNSPPPCEXP215_Msk                (0x1UL  << NONSEC_PRIV_CTRL_AHBNSPPPCEXP2_AHBNSPPPCEXP215_Pos)                 /* NONSEC_PRIV_CTRL AHBNSPPPCEXP2: AHBNSPPPCEXP215 Mask */

#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP2_AHBNSPPPCEXP214_Pos                14                                                          /* NONSEC_PRIV_CTRL AHBNSPPPCEXP2: AHBNSPPPCEXP214 Positions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP2_AHBNSPPPCEXP214_Msk                (0x1UL  << NONSEC_PRIV_CTRL_AHBNSPPPCEXP2_AHBNSPPPCEXP214_Pos)                 /* NONSEC_PRIV_CTRL AHBNSPPPCEXP2: AHBNSPPPCEXP214 Mask */

#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP2_AHBNSPPPCEXP213_Pos                13                                                          /* NONSEC_PRIV_CTRL AHBNSPPPCEXP2: AHBNSPPPCEXP213 Positions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP2_AHBNSPPPCEXP213_Msk                (0x1UL  << NONSEC_PRIV_CTRL_AHBNSPPPCEXP2_AHBNSPPPCEXP213_Pos)                 /* NONSEC_PRIV_CTRL AHBNSPPPCEXP2: AHBNSPPPCEXP213 Mask */

#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP2_AHBNSPPPCEXP212_Pos                12                                                          /* NONSEC_PRIV_CTRL AHBNSPPPCEXP2: AHBNSPPPCEXP212 Positions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP2_AHBNSPPPCEXP212_Msk                (0x1UL  << NONSEC_PRIV_CTRL_AHBNSPPPCEXP2_AHBNSPPPCEXP212_Pos)                 /* NONSEC_PRIV_CTRL AHBNSPPPCEXP2: AHBNSPPPCEXP212 Mask */

#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP2_AHBNSPPPCEXP211_Pos                11                                                          /* NONSEC_PRIV_CTRL AHBNSPPPCEXP2: AHBNSPPPCEXP211 Positions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP2_AHBNSPPPCEXP211_Msk                (0x1UL  << NONSEC_PRIV_CTRL_AHBNSPPPCEXP2_AHBNSPPPCEXP211_Pos)                 /* NONSEC_PRIV_CTRL AHBNSPPPCEXP2: AHBNSPPPCEXP211 Mask */

#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP2_AHBNSPPPCEXP210_Pos                10                                                          /* NONSEC_PRIV_CTRL AHBNSPPPCEXP2: AHBNSPPPCEXP210 Positions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP2_AHBNSPPPCEXP210_Msk                (0x1UL  << NONSEC_PRIV_CTRL_AHBNSPPPCEXP2_AHBNSPPPCEXP210_Pos)                 /* NONSEC_PRIV_CTRL AHBNSPPPCEXP2: AHBNSPPPCEXP210 Mask */

#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP2_AHBNSPPPCEXP29_Pos                9                                                          /* NONSEC_PRIV_CTRL AHBNSPPPCEXP2: AHBNSPPPCEXP29 Positions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP2_AHBNSPPPCEXP29_Msk                (0x1UL  << NONSEC_PRIV_CTRL_AHBNSPPPCEXP2_AHBNSPPPCEXP29_Pos)                 /* NONSEC_PRIV_CTRL AHBNSPPPCEXP2: AHBNSPPPCEXP29 Mask */

#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP2_AHBNSPPPCEXP28_Pos                8                                                          /* NONSEC_PRIV_CTRL AHBNSPPPCEXP2: AHBNSPPPCEXP28 Positions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP2_AHBNSPPPCEXP28_Msk                (0x1UL  << NONSEC_PRIV_CTRL_AHBNSPPPCEXP2_AHBNSPPPCEXP28_Pos)                 /* NONSEC_PRIV_CTRL AHBNSPPPCEXP2: AHBNSPPPCEXP28 Mask */

#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP2_AHBNSPPPCEXP27_Pos                7                                                          /* NONSEC_PRIV_CTRL AHBNSPPPCEXP2: AHBNSPPPCEXP27 Positions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP2_AHBNSPPPCEXP27_Msk                (0x1UL  << NONSEC_PRIV_CTRL_AHBNSPPPCEXP2_AHBNSPPPCEXP27_Pos)                 /* NONSEC_PRIV_CTRL AHBNSPPPCEXP2: AHBNSPPPCEXP27 Mask */

#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP2_AHBNSPPPCEXP26_Pos                6                                                          /* NONSEC_PRIV_CTRL AHBNSPPPCEXP2: AHBNSPPPCEXP26 Positions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP2_AHBNSPPPCEXP26_Msk                (0x1UL  << NONSEC_PRIV_CTRL_AHBNSPPPCEXP2_AHBNSPPPCEXP26_Pos)                 /* NONSEC_PRIV_CTRL AHBNSPPPCEXP2: AHBNSPPPCEXP26 Mask */

#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP2_AHBNSPPPCEXP25_Pos                5                                                          /* NONSEC_PRIV_CTRL AHBNSPPPCEXP2: AHBNSPPPCEXP25 Positions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP2_AHBNSPPPCEXP25_Msk                (0x1UL  << NONSEC_PRIV_CTRL_AHBNSPPPCEXP2_AHBNSPPPCEXP25_Pos)                 /* NONSEC_PRIV_CTRL AHBNSPPPCEXP2: AHBNSPPPCEXP25 Mask */

#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP2_AHBNSPPPCEXP24_Pos                4                                                          /* NONSEC_PRIV_CTRL AHBNSPPPCEXP2: AHBNSPPPCEXP24 Positions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP2_AHBNSPPPCEXP24_Msk                (0x1UL  << NONSEC_PRIV_CTRL_AHBNSPPPCEXP2_AHBNSPPPCEXP24_Pos)                 /* NONSEC_PRIV_CTRL AHBNSPPPCEXP2: AHBNSPPPCEXP24 Mask */

#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP2_AHBNSPPPCEXP23_Pos                3                                                          /* NONSEC_PRIV_CTRL AHBNSPPPCEXP2: AHBNSPPPCEXP23 Positions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP2_AHBNSPPPCEXP23_Msk                (0x1UL  << NONSEC_PRIV_CTRL_AHBNSPPPCEXP2_AHBNSPPPCEXP23_Pos)                 /* NONSEC_PRIV_CTRL AHBNSPPPCEXP2: AHBNSPPPCEXP23 Mask */

#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP2_AHBNSPPPCEXP22_Pos                2                                                          /* NONSEC_PRIV_CTRL AHBNSPPPCEXP2: AHBNSPPPCEXP22 Positions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP2_AHBNSPPPCEXP22_Msk                (0x1UL  << NONSEC_PRIV_CTRL_AHBNSPPPCEXP2_AHBNSPPPCEXP22_Pos)                 /* NONSEC_PRIV_CTRL AHBNSPPPCEXP2: AHBNSPPPCEXP22 Mask */

#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP2_AHBNSPPPCEXP21_Pos                1                                                          /* NONSEC_PRIV_CTRL AHBNSPPPCEXP2: AHBNSPPPCEXP21 Positions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP2_AHBNSPPPCEXP21_Msk                (0x1UL  << NONSEC_PRIV_CTRL_AHBNSPPPCEXP2_AHBNSPPPCEXP21_Pos)                 /* NONSEC_PRIV_CTRL AHBNSPPPCEXP2: AHBNSPPPCEXP21 Mask */

#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP2_AHBNSPPPCEXP20_Pos                0                                                          /* NONSEC_PRIV_CTRL AHBNSPPPCEXP2: AHBNSPPPCEXP20 Positions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP2_AHBNSPPPCEXP20_Msk                (0x1UL  /*<< NONSEC_PRIV_CTRL_AHBNSPPPCEXP2_AHBNSPPPCEXP20_Pos*/)                 /* NONSEC_PRIV_CTRL AHBNSPPPCEXP2: AHBNSPPPCEXP20 Mask */

/* NONSEC_PRIV_CTRL AHBNSPPPCEXP3 Register Definitions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP3_AHBNSPPPCEXP315_Pos                15                                                          /* NONSEC_PRIV_CTRL AHBNSPPPCEXP3: AHBNSPPPCEXP315 Positions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP3_AHBNSPPPCEXP315_Msk                (0x1UL  << NONSEC_PRIV_CTRL_AHBNSPPPCEXP3_AHBNSPPPCEXP315_Pos)                 /* NONSEC_PRIV_CTRL AHBNSPPPCEXP3: AHBNSPPPCEXP315 Mask */

#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP3_AHBNSPPPCEXP314_Pos                14                                                          /* NONSEC_PRIV_CTRL AHBNSPPPCEXP3: AHBNSPPPCEXP314 Positions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP3_AHBNSPPPCEXP314_Msk                (0x1UL  << NONSEC_PRIV_CTRL_AHBNSPPPCEXP3_AHBNSPPPCEXP314_Pos)                 /* NONSEC_PRIV_CTRL AHBNSPPPCEXP3: AHBNSPPPCEXP314 Mask */

#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP3_AHBNSPPPCEXP313_Pos                13                                                          /* NONSEC_PRIV_CTRL AHBNSPPPCEXP3: AHBNSPPPCEXP313 Positions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP3_AHBNSPPPCEXP313_Msk                (0x1UL  << NONSEC_PRIV_CTRL_AHBNSPPPCEXP3_AHBNSPPPCEXP313_Pos)                 /* NONSEC_PRIV_CTRL AHBNSPPPCEXP3: AHBNSPPPCEXP313 Mask */

#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP3_AHBNSPPPCEXP312_Pos                12                                                          /* NONSEC_PRIV_CTRL AHBNSPPPCEXP3: AHBNSPPPCEXP312 Positions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP3_AHBNSPPPCEXP312_Msk                (0x1UL  << NONSEC_PRIV_CTRL_AHBNSPPPCEXP3_AHBNSPPPCEXP312_Pos)                 /* NONSEC_PRIV_CTRL AHBNSPPPCEXP3: AHBNSPPPCEXP312 Mask */

#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP3_AHBNSPPPCEXP311_Pos                11                                                          /* NONSEC_PRIV_CTRL AHBNSPPPCEXP3: AHBNSPPPCEXP311 Positions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP3_AHBNSPPPCEXP311_Msk                (0x1UL  << NONSEC_PRIV_CTRL_AHBNSPPPCEXP3_AHBNSPPPCEXP311_Pos)                 /* NONSEC_PRIV_CTRL AHBNSPPPCEXP3: AHBNSPPPCEXP311 Mask */

#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP3_AHBNSPPPCEXP310_Pos                10                                                          /* NONSEC_PRIV_CTRL AHBNSPPPCEXP3: AHBNSPPPCEXP310 Positions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP3_AHBNSPPPCEXP310_Msk                (0x1UL  << NONSEC_PRIV_CTRL_AHBNSPPPCEXP3_AHBNSPPPCEXP310_Pos)                 /* NONSEC_PRIV_CTRL AHBNSPPPCEXP3: AHBNSPPPCEXP310 Mask */

#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP3_AHBNSPPPCEXP39_Pos                9                                                          /* NONSEC_PRIV_CTRL AHBNSPPPCEXP3: AHBNSPPPCEXP39 Positions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP3_AHBNSPPPCEXP39_Msk                (0x1UL  << NONSEC_PRIV_CTRL_AHBNSPPPCEXP3_AHBNSPPPCEXP39_Pos)                 /* NONSEC_PRIV_CTRL AHBNSPPPCEXP3: AHBNSPPPCEXP39 Mask */

#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP3_AHBNSPPPCEXP38_Pos                8                                                          /* NONSEC_PRIV_CTRL AHBNSPPPCEXP3: AHBNSPPPCEXP38 Positions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP3_AHBNSPPPCEXP38_Msk                (0x1UL  << NONSEC_PRIV_CTRL_AHBNSPPPCEXP3_AHBNSPPPCEXP38_Pos)                 /* NONSEC_PRIV_CTRL AHBNSPPPCEXP3: AHBNSPPPCEXP38 Mask */

#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP3_AHBNSPPPCEXP37_Pos                7                                                          /* NONSEC_PRIV_CTRL AHBNSPPPCEXP3: AHBNSPPPCEXP37 Positions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP3_AHBNSPPPCEXP37_Msk                (0x1UL  << NONSEC_PRIV_CTRL_AHBNSPPPCEXP3_AHBNSPPPCEXP37_Pos)                 /* NONSEC_PRIV_CTRL AHBNSPPPCEXP3: AHBNSPPPCEXP37 Mask */

#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP3_AHBNSPPPCEXP36_Pos                6                                                          /* NONSEC_PRIV_CTRL AHBNSPPPCEXP3: AHBNSPPPCEXP36 Positions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP3_AHBNSPPPCEXP36_Msk                (0x1UL  << NONSEC_PRIV_CTRL_AHBNSPPPCEXP3_AHBNSPPPCEXP36_Pos)                 /* NONSEC_PRIV_CTRL AHBNSPPPCEXP3: AHBNSPPPCEXP36 Mask */

#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP3_AHBNSPPPCEXP35_Pos                5                                                          /* NONSEC_PRIV_CTRL AHBNSPPPCEXP3: AHBNSPPPCEXP35 Positions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP3_AHBNSPPPCEXP35_Msk                (0x1UL  << NONSEC_PRIV_CTRL_AHBNSPPPCEXP3_AHBNSPPPCEXP35_Pos)                 /* NONSEC_PRIV_CTRL AHBNSPPPCEXP3: AHBNSPPPCEXP35 Mask */

#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP3_AHBNSPPPCEXP34_Pos                4                                                          /* NONSEC_PRIV_CTRL AHBNSPPPCEXP3: AHBNSPPPCEXP34 Positions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP3_AHBNSPPPCEXP34_Msk                (0x1UL  << NONSEC_PRIV_CTRL_AHBNSPPPCEXP3_AHBNSPPPCEXP34_Pos)                 /* NONSEC_PRIV_CTRL AHBNSPPPCEXP3: AHBNSPPPCEXP34 Mask */

#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP3_AHBNSPPPCEXP33_Pos                3                                                          /* NONSEC_PRIV_CTRL AHBNSPPPCEXP3: AHBNSPPPCEXP33 Positions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP3_AHBNSPPPCEXP33_Msk                (0x1UL  << NONSEC_PRIV_CTRL_AHBNSPPPCEXP3_AHBNSPPPCEXP33_Pos)                 /* NONSEC_PRIV_CTRL AHBNSPPPCEXP3: AHBNSPPPCEXP33 Mask */

#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP3_AHBNSPPPCEXP32_Pos                2                                                          /* NONSEC_PRIV_CTRL AHBNSPPPCEXP3: AHBNSPPPCEXP32 Positions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP3_AHBNSPPPCEXP32_Msk                (0x1UL  << NONSEC_PRIV_CTRL_AHBNSPPPCEXP3_AHBNSPPPCEXP32_Pos)                 /* NONSEC_PRIV_CTRL AHBNSPPPCEXP3: AHBNSPPPCEXP32 Mask */

#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP3_AHBNSPPPCEXP31_Pos                1                                                          /* NONSEC_PRIV_CTRL AHBNSPPPCEXP3: AHBNSPPPCEXP31 Positions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP3_AHBNSPPPCEXP31_Msk                (0x1UL  << NONSEC_PRIV_CTRL_AHBNSPPPCEXP3_AHBNSPPPCEXP31_Pos)                 /* NONSEC_PRIV_CTRL AHBNSPPPCEXP3: AHBNSPPPCEXP31 Mask */

#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP3_AHBNSPPPCEXP30_Pos                0                                                          /* NONSEC_PRIV_CTRL AHBNSPPPCEXP3: AHBNSPPPCEXP30 Positions */
#define NONSEC_PRIV_CTRL_AHBNSPPPCEXP3_AHBNSPPPCEXP30_Msk                (0x1UL  /*<< NONSEC_PRIV_CTRL_AHBNSPPPCEXP3_AHBNSPPPCEXP30_Pos*/)                 /* NONSEC_PRIV_CTRL AHBNSPPPCEXP3: AHBNSPPPCEXP30 Mask */

/* NONSEC_PRIV_CTRL APBNSPPPC0 Register Definitions */
#define NONSEC_PRIV_CTRL_APBNSPPPC0_NSP_MHU1_Pos                4                                                          /* NONSEC_PRIV_CTRL APBNSPPPC0: NSP_MHU1 Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPC0_NSP_MHU1_Msk                (0x1UL  << NONSEC_PRIV_CTRL_APBNSPPPC0_NSP_MHU1_Pos)                 /* NONSEC_PRIV_CTRL APBNSPPPC0: NSP_MHU1 Mask */

#define NONSEC_PRIV_CTRL_APBNSPPPC0_NSP_MHU0_Pos                3                                                          /* NONSEC_PRIV_CTRL APBNSPPPC0: NSP_MHU0 Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPC0_NSP_MHU0_Msk                (0x1UL  << NONSEC_PRIV_CTRL_APBNSPPPC0_NSP_MHU0_Pos)                 /* NONSEC_PRIV_CTRL APBNSPPPC0: NSP_MHU0 Mask */

#define NONSEC_PRIV_CTRL_APBNSPPPC0_NSP_DTIMER_Pos                2                                                          /* NONSEC_PRIV_CTRL APBNSPPPC0: NSP_DTIMER Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPC0_NSP_DTIMER_Msk                (0x1UL  << NONSEC_PRIV_CTRL_APBNSPPPC0_NSP_DTIMER_Pos)                 /* NONSEC_PRIV_CTRL APBNSPPPC0: NSP_DTIMER Mask */

#define NONSEC_PRIV_CTRL_APBNSPPPC0_NSP_TIMER1_Pos                1                                                          /* NONSEC_PRIV_CTRL APBNSPPPC0: NSP_TIMER1 Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPC0_NSP_TIMER1_Msk                (0x1UL  << NONSEC_PRIV_CTRL_APBNSPPPC0_NSP_TIMER1_Pos)                 /* NONSEC_PRIV_CTRL APBNSPPPC0: NSP_TIMER1 Mask */

#define NONSEC_PRIV_CTRL_APBNSPPPC0_NSP_TIMER0_Pos                0                                                          /* NONSEC_PRIV_CTRL APBNSPPPC0: NSP_TIMER0 Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPC0_NSP_TIMER0_Msk                (0x1UL  /*<< NONSEC_PRIV_CTRL_APBNSPPPC0_NSP_TIMER0_Pos*/)                 /* NONSEC_PRIV_CTRL APBNSPPPC0: NSP_TIMER0 Mask */

/* NONSEC_PRIV_CTRL APBNSPPPC1 Register Definitions */
#define NONSEC_PRIV_CTRL_APBNSPPPC1_NSP_S32K_Timer_Pos                0                                                          /* NONSEC_PRIV_CTRL APBNSPPPC1: NSP_S32K_Timer Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPC1_NSP_S32K_Timer_Msk                (0x1UL  /*<< NONSEC_PRIV_CTRL_APBNSPPPC1_NSP_S32K_Timer_Pos*/)                 /* NONSEC_PRIV_CTRL APBNSPPPC1: NSP_S32K_Timer Mask */

/* NONSEC_PRIV_CTRL APBNSPPPCEXP0 Register Definitions */
#define NONSEC_PRIV_CTRL_APBNSPPPCEXP0_QSPI_Pos                15                                                          /* NONSEC_PRIV_CTRL APBNSPPPCEXP0: QSPI Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPCEXP0_QSPI_Msk                (0x1UL  << NONSEC_PRIV_CTRL_APBNSPPPCEXP0_QSPI_Pos)                 /* NONSEC_PRIV_CTRL APBNSPPPCEXP0: QSPI Mask */

#define NONSEC_PRIV_CTRL_APBNSPPPCEXP0_SLWTIMER_Pos                14                                                          /* NONSEC_PRIV_CTRL APBNSPPPCEXP0: SLWTIMER Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPCEXP0_SLWTIMER_Msk                (0x1UL  << NONSEC_PRIV_CTRL_APBNSPPPCEXP0_SLWTIMER_Pos)                 /* NONSEC_PRIV_CTRL APBNSPPPCEXP0: SLWTIMER Mask */

#define NONSEC_PRIV_CTRL_APBNSPPPCEXP0_SPI1_Pos                13                                                          /* NONSEC_PRIV_CTRL APBNSPPPCEXP0: SPI1 Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPCEXP0_SPI1_Msk                (0x1UL  << NONSEC_PRIV_CTRL_APBNSPPPCEXP0_SPI1_Pos)                 /* NONSEC_PRIV_CTRL APBNSPPPCEXP0: SPI1 Mask */

#define NONSEC_PRIV_CTRL_APBNSPPPCEXP0_QDEC_Pos                12                                                          /* NONSEC_PRIV_CTRL APBNSPPPCEXP0: QDEC Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPCEXP0_QDEC_Msk                (0x1UL  << NONSEC_PRIV_CTRL_APBNSPPPCEXP0_QDEC_Pos)                 /* NONSEC_PRIV_CTRL APBNSPPPCEXP0: QDEC Mask */

#define NONSEC_PRIV_CTRL_APBNSPPPCEXP0_SPI2_Pos                11                                                          /* NONSEC_PRIV_CTRL APBNSPPPCEXP0: SPI2 Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPCEXP0_SPI2_Msk                (0x1UL  << NONSEC_PRIV_CTRL_APBNSPPPCEXP0_SPI2_Pos)                 /* NONSEC_PRIV_CTRL APBNSPPPCEXP0: SPI2 Mask */

#define NONSEC_PRIV_CTRL_APBNSPPPCEXP0_KSM_Pos                10                                                          /* NONSEC_PRIV_CTRL APBNSPPPCEXP0: KSM Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPCEXP0_KSM_Msk                (0x1UL  << NONSEC_PRIV_CTRL_APBNSPPPCEXP0_KSM_Pos)                 /* NONSEC_PRIV_CTRL APBNSPPPCEXP0: KSM Mask */

#define NONSEC_PRIV_CTRL_APBNSPPPCEXP0_APBNSPPPCEXP09_Pos                9                                                          /* NONSEC_PRIV_CTRL APBNSPPPCEXP0: APBNSPPPCEXP09 Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPCEXP0_APBNSPPPCEXP09_Msk                (0x1UL  << NONSEC_PRIV_CTRL_APBNSPPPCEXP0_APBNSPPPCEXP09_Pos)                 /* NONSEC_PRIV_CTRL APBNSPPPCEXP0: APBNSPPPCEXP09 Mask */

#define NONSEC_PRIV_CTRL_APBNSPPPCEXP0_APBNSPPPCEXP08_Pos                8                                                          /* NONSEC_PRIV_CTRL APBNSPPPCEXP0: APBNSPPPCEXP08 Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPCEXP0_APBNSPPPCEXP08_Msk                (0x1UL  << NONSEC_PRIV_CTRL_APBNSPPPCEXP0_APBNSPPPCEXP08_Pos)                 /* NONSEC_PRIV_CTRL APBNSPPPCEXP0: APBNSPPPCEXP08 Mask */

#define NONSEC_PRIV_CTRL_APBNSPPPCEXP0_SPI0_Pos                7                                                          /* NONSEC_PRIV_CTRL APBNSPPPCEXP0: SPI0 Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPCEXP0_SPI0_Msk                (0x1UL  << NONSEC_PRIV_CTRL_APBNSPPPCEXP0_SPI0_Pos)                 /* NONSEC_PRIV_CTRL APBNSPPPCEXP0: SPI0 Mask */

#define NONSEC_PRIV_CTRL_APBNSPPPCEXP0_PWM_Pos                6                                                          /* NONSEC_PRIV_CTRL APBNSPPPCEXP0: PWM Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPCEXP0_PWM_Msk                (0x1UL  << NONSEC_PRIV_CTRL_APBNSPPPCEXP0_PWM_Pos)                 /* NONSEC_PRIV_CTRL APBNSPPPCEXP0: PWM Mask */

#define NONSEC_PRIV_CTRL_APBNSPPPCEXP0_UART1_Pos                5                                                          /* NONSEC_PRIV_CTRL APBNSPPPCEXP0: UART1 Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPCEXP0_UART1_Msk                (0x1UL  << NONSEC_PRIV_CTRL_APBNSPPPCEXP0_UART1_Pos)                 /* NONSEC_PRIV_CTRL APBNSPPPCEXP0: UART1 Mask */

#define NONSEC_PRIV_CTRL_APBNSPPPCEXP0_UART0_Pos                4                                                          /* NONSEC_PRIV_CTRL APBNSPPPCEXP0: UART0 Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPCEXP0_UART0_Msk                (0x1UL  << NONSEC_PRIV_CTRL_APBNSPPPCEXP0_UART0_Pos)                 /* NONSEC_PRIV_CTRL APBNSPPPCEXP0: UART0 Mask */

#define NONSEC_PRIV_CTRL_APBNSPPPCEXP0_WRPR_Pos                3                                                          /* NONSEC_PRIV_CTRL APBNSPPPCEXP0: WRPR Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPCEXP0_WRPR_Msk                (0x1UL  << NONSEC_PRIV_CTRL_APBNSPPPCEXP0_WRPR_Pos)                 /* NONSEC_PRIV_CTRL APBNSPPPCEXP0: WRPR Mask */

#define NONSEC_PRIV_CTRL_APBNSPPPCEXP0_APBNSPPPCEXP02_Pos                2                                                          /* NONSEC_PRIV_CTRL APBNSPPPCEXP0: APBNSPPPCEXP02 Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPCEXP0_APBNSPPPCEXP02_Msk                (0x1UL  << NONSEC_PRIV_CTRL_APBNSPPPCEXP0_APBNSPPPCEXP02_Pos)                 /* NONSEC_PRIV_CTRL APBNSPPPCEXP0: APBNSPPPCEXP02 Mask */

#define NONSEC_PRIV_CTRL_APBNSPPPCEXP0_APBNSPPPCEXP01_Pos                1                                                          /* NONSEC_PRIV_CTRL APBNSPPPCEXP0: APBNSPPPCEXP01 Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPCEXP0_APBNSPPPCEXP01_Msk                (0x1UL  << NONSEC_PRIV_CTRL_APBNSPPPCEXP0_APBNSPPPCEXP01_Pos)                 /* NONSEC_PRIV_CTRL APBNSPPPCEXP0: APBNSPPPCEXP01 Mask */

#define NONSEC_PRIV_CTRL_APBNSPPPCEXP0_APBNSPPPCEXP00_Pos                0                                                          /* NONSEC_PRIV_CTRL APBNSPPPCEXP0: APBNSPPPCEXP00 Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPCEXP0_APBNSPPPCEXP00_Msk                (0x1UL  /*<< NONSEC_PRIV_CTRL_APBNSPPPCEXP0_APBNSPPPCEXP00_Pos*/)                 /* NONSEC_PRIV_CTRL APBNSPPPCEXP0: APBNSPPPCEXP00 Mask */

/* NONSEC_PRIV_CTRL APBNSPPPCEXP1 Register Definitions */
#define NONSEC_PRIV_CTRL_APBNSPPPCEXP1_APBNSPPPCEXP115_Pos                15                                                          /* NONSEC_PRIV_CTRL APBNSPPPCEXP1: APBNSPPPCEXP115 Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPCEXP1_APBNSPPPCEXP115_Msk                (0x1UL  << NONSEC_PRIV_CTRL_APBNSPPPCEXP1_APBNSPPPCEXP115_Pos)                 /* NONSEC_PRIV_CTRL APBNSPPPCEXP1: APBNSPPPCEXP115 Mask */

#define NONSEC_PRIV_CTRL_APBNSPPPCEXP1_ATLC_Pos                14                                                          /* NONSEC_PRIV_CTRL APBNSPPPCEXP1: ATLC Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPCEXP1_ATLC_Msk                (0x1UL  << NONSEC_PRIV_CTRL_APBNSPPPCEXP1_ATLC_Pos)                 /* NONSEC_PRIV_CTRL APBNSPPPCEXP1: ATLC Mask */

#define NONSEC_PRIV_CTRL_APBNSPPPCEXP1_SHUB_Pos                13                                                          /* NONSEC_PRIV_CTRL APBNSPPPCEXP1: SHUB Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPCEXP1_SHUB_Msk                (0x1UL  << NONSEC_PRIV_CTRL_APBNSPPPCEXP1_SHUB_Pos)                 /* NONSEC_PRIV_CTRL APBNSPPPCEXP1: SHUB Mask */

#define NONSEC_PRIV_CTRL_APBNSPPPCEXP1_RCOS_CAL_Pos                12                                                          /* NONSEC_PRIV_CTRL APBNSPPPCEXP1: RCOS_CAL Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPCEXP1_RCOS_CAL_Msk                (0x1UL  << NONSEC_PRIV_CTRL_APBNSPPPCEXP1_RCOS_CAL_Pos)                 /* NONSEC_PRIV_CTRL APBNSPPPCEXP1: RCOS_CAL Mask */

#define NONSEC_PRIV_CTRL_APBNSPPPCEXP1_TRNG_Pos                11                                                          /* NONSEC_PRIV_CTRL APBNSPPPCEXP1: TRNG Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPCEXP1_TRNG_Msk                (0x1UL  << NONSEC_PRIV_CTRL_APBNSPPPCEXP1_TRNG_Pos)                 /* NONSEC_PRIV_CTRL APBNSPPPCEXP1: TRNG Mask */

#define NONSEC_PRIV_CTRL_APBNSPPPCEXP1_GADC_Pos                10                                                          /* NONSEC_PRIV_CTRL APBNSPPPCEXP1: GADC Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPCEXP1_GADC_Msk                (0x1UL  << NONSEC_PRIV_CTRL_APBNSPPPCEXP1_GADC_Pos)                 /* NONSEC_PRIV_CTRL APBNSPPPCEXP1: GADC Mask */

#define NONSEC_PRIV_CTRL_APBNSPPPCEXP1_SWD_Pos                9                                                          /* NONSEC_PRIV_CTRL APBNSPPPCEXP1: SWD Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPCEXP1_SWD_Msk                (0x1UL  << NONSEC_PRIV_CTRL_APBNSPPPCEXP1_SWD_Pos)                 /* NONSEC_PRIV_CTRL APBNSPPPCEXP1: SWD Mask */

#define NONSEC_PRIV_CTRL_APBNSPPPCEXP1_PSEQ_Pos                8                                                          /* NONSEC_PRIV_CTRL APBNSPPPCEXP1: PSEQ Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPCEXP1_PSEQ_Msk                (0x1UL  << NONSEC_PRIV_CTRL_APBNSPPPCEXP1_PSEQ_Pos)                 /* NONSEC_PRIV_CTRL APBNSPPPCEXP1: PSEQ Mask */

#define NONSEC_PRIV_CTRL_APBNSPPPCEXP1_PMU_Pos                7                                                          /* NONSEC_PRIV_CTRL APBNSPPPCEXP1: PMU Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPCEXP1_PMU_Msk                (0x1UL  << NONSEC_PRIV_CTRL_APBNSPPPCEXP1_PMU_Pos)                 /* NONSEC_PRIV_CTRL APBNSPPPCEXP1: PMU Mask */

#define NONSEC_PRIV_CTRL_APBNSPPPCEXP1_MDM_Pos                6                                                          /* NONSEC_PRIV_CTRL APBNSPPPCEXP1: MDM Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPCEXP1_MDM_Msk                (0x1UL  << NONSEC_PRIV_CTRL_APBNSPPPCEXP1_MDM_Pos)                 /* NONSEC_PRIV_CTRL APBNSPPPCEXP1: MDM Mask */

#define NONSEC_PRIV_CTRL_APBNSPPPCEXP1_RADIO_Pos                5                                                          /* NONSEC_PRIV_CTRL APBNSPPPCEXP1: RADIO Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPCEXP1_RADIO_Msk                (0x1UL  << NONSEC_PRIV_CTRL_APBNSPPPCEXP1_RADIO_Pos)                 /* NONSEC_PRIV_CTRL APBNSPPPCEXP1: RADIO Mask */

#define NONSEC_PRIV_CTRL_APBNSPPPCEXP1_RIF_Pos                4                                                          /* NONSEC_PRIV_CTRL APBNSPPPCEXP1: RIF Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPCEXP1_RIF_Msk                (0x1UL  << NONSEC_PRIV_CTRL_APBNSPPPCEXP1_RIF_Pos)                 /* NONSEC_PRIV_CTRL APBNSPPPCEXP1: RIF Mask */

#define NONSEC_PRIV_CTRL_APBNSPPPCEXP1_WRPR_Pos                3                                                          /* NONSEC_PRIV_CTRL APBNSPPPCEXP1: WRPR Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPCEXP1_WRPR_Msk                (0x1UL  << NONSEC_PRIV_CTRL_APBNSPPPCEXP1_WRPR_Pos)                 /* NONSEC_PRIV_CTRL APBNSPPPCEXP1: WRPR Mask */

#define NONSEC_PRIV_CTRL_APBNSPPPCEXP1_NVM_Pos                2                                                          /* NONSEC_PRIV_CTRL APBNSPPPCEXP1: NVM Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPCEXP1_NVM_Msk                (0x1UL  << NONSEC_PRIV_CTRL_APBNSPPPCEXP1_NVM_Pos)                 /* NONSEC_PRIV_CTRL APBNSPPPCEXP1: NVM Mask */

#define NONSEC_PRIV_CTRL_APBNSPPPCEXP1_I2C1_Pos                1                                                          /* NONSEC_PRIV_CTRL APBNSPPPCEXP1: I2C1 Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPCEXP1_I2C1_Msk                (0x1UL  << NONSEC_PRIV_CTRL_APBNSPPPCEXP1_I2C1_Pos)                 /* NONSEC_PRIV_CTRL APBNSPPPCEXP1: I2C1 Mask */

#define NONSEC_PRIV_CTRL_APBNSPPPCEXP1_I2C0_Pos                0                                                          /* NONSEC_PRIV_CTRL APBNSPPPCEXP1: I2C0 Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPCEXP1_I2C0_Msk                (0x1UL  /*<< NONSEC_PRIV_CTRL_APBNSPPPCEXP1_I2C0_Pos*/)                 /* NONSEC_PRIV_CTRL APBNSPPPCEXP1: I2C0 Mask */

/* NONSEC_PRIV_CTRL APBNSPPPCEXP2 Register Definitions */
#define NONSEC_PRIV_CTRL_APBNSPPPCEXP2_APBNSPPPCEXP215_Pos                15                                                          /* NONSEC_PRIV_CTRL APBNSPPPCEXP2: APBNSPPPCEXP215 Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPCEXP2_APBNSPPPCEXP215_Msk                (0x1UL  << NONSEC_PRIV_CTRL_APBNSPPPCEXP2_APBNSPPPCEXP215_Pos)                 /* NONSEC_PRIV_CTRL APBNSPPPCEXP2: APBNSPPPCEXP215 Mask */

#define NONSEC_PRIV_CTRL_APBNSPPPCEXP2_APBNSPPPCEXP214_Pos                14                                                          /* NONSEC_PRIV_CTRL APBNSPPPCEXP2: APBNSPPPCEXP214 Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPCEXP2_APBNSPPPCEXP214_Msk                (0x1UL  << NONSEC_PRIV_CTRL_APBNSPPPCEXP2_APBNSPPPCEXP214_Pos)                 /* NONSEC_PRIV_CTRL APBNSPPPCEXP2: APBNSPPPCEXP214 Mask */

#define NONSEC_PRIV_CTRL_APBNSPPPCEXP2_APBNSPPPCEXP213_Pos                13                                                          /* NONSEC_PRIV_CTRL APBNSPPPCEXP2: APBNSPPPCEXP213 Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPCEXP2_APBNSPPPCEXP213_Msk                (0x1UL  << NONSEC_PRIV_CTRL_APBNSPPPCEXP2_APBNSPPPCEXP213_Pos)                 /* NONSEC_PRIV_CTRL APBNSPPPCEXP2: APBNSPPPCEXP213 Mask */

#define NONSEC_PRIV_CTRL_APBNSPPPCEXP2_APBNSPPPCEXP212_Pos                12                                                          /* NONSEC_PRIV_CTRL APBNSPPPCEXP2: APBNSPPPCEXP212 Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPCEXP2_APBNSPPPCEXP212_Msk                (0x1UL  << NONSEC_PRIV_CTRL_APBNSPPPCEXP2_APBNSPPPCEXP212_Pos)                 /* NONSEC_PRIV_CTRL APBNSPPPCEXP2: APBNSPPPCEXP212 Mask */

#define NONSEC_PRIV_CTRL_APBNSPPPCEXP2_APBNSPPPCEXP211_Pos                11                                                          /* NONSEC_PRIV_CTRL APBNSPPPCEXP2: APBNSPPPCEXP211 Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPCEXP2_APBNSPPPCEXP211_Msk                (0x1UL  << NONSEC_PRIV_CTRL_APBNSPPPCEXP2_APBNSPPPCEXP211_Pos)                 /* NONSEC_PRIV_CTRL APBNSPPPCEXP2: APBNSPPPCEXP211 Mask */

#define NONSEC_PRIV_CTRL_APBNSPPPCEXP2_APBNSPPPCEXP210_Pos                10                                                          /* NONSEC_PRIV_CTRL APBNSPPPCEXP2: APBNSPPPCEXP210 Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPCEXP2_APBNSPPPCEXP210_Msk                (0x1UL  << NONSEC_PRIV_CTRL_APBNSPPPCEXP2_APBNSPPPCEXP210_Pos)                 /* NONSEC_PRIV_CTRL APBNSPPPCEXP2: APBNSPPPCEXP210 Mask */

#define NONSEC_PRIV_CTRL_APBNSPPPCEXP2_APBNSPPPCEXP29_Pos                9                                                          /* NONSEC_PRIV_CTRL APBNSPPPCEXP2: APBNSPPPCEXP29 Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPCEXP2_APBNSPPPCEXP29_Msk                (0x1UL  << NONSEC_PRIV_CTRL_APBNSPPPCEXP2_APBNSPPPCEXP29_Pos)                 /* NONSEC_PRIV_CTRL APBNSPPPCEXP2: APBNSPPPCEXP29 Mask */

#define NONSEC_PRIV_CTRL_APBNSPPPCEXP2_UART2_Pos                8                                                          /* NONSEC_PRIV_CTRL APBNSPPPCEXP2: UART2 Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPCEXP2_UART2_Msk                (0x1UL  << NONSEC_PRIV_CTRL_APBNSPPPCEXP2_UART2_Pos)                 /* NONSEC_PRIV_CTRL APBNSPPPCEXP2: UART2 Mask */

#define NONSEC_PRIV_CTRL_APBNSPPPCEXP2_AES_Pos                7                                                          /* NONSEC_PRIV_CTRL APBNSPPPCEXP2: AES Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPCEXP2_AES_Msk                (0x1UL  << NONSEC_PRIV_CTRL_APBNSPPPCEXP2_AES_Pos)                 /* NONSEC_PRIV_CTRL APBNSPPPCEXP2: AES Mask */

#define NONSEC_PRIV_CTRL_APBNSPPPCEXP2_CLKRSTGEN_Pos                6                                                          /* NONSEC_PRIV_CTRL APBNSPPPCEXP2: CLKRSTGEN Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPCEXP2_CLKRSTGEN_Msk                (0x1UL  << NONSEC_PRIV_CTRL_APBNSPPPCEXP2_CLKRSTGEN_Pos)                 /* NONSEC_PRIV_CTRL APBNSPPPCEXP2: CLKRSTGEN Mask */

#define NONSEC_PRIV_CTRL_APBNSPPPCEXP2_I2S_Pos                5                                                          /* NONSEC_PRIV_CTRL APBNSPPPCEXP2: I2S Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPCEXP2_I2S_Msk                (0x1UL  << NONSEC_PRIV_CTRL_APBNSPPPCEXP2_I2S_Pos)                 /* NONSEC_PRIV_CTRL APBNSPPPCEXP2: I2S Mask */

#define NONSEC_PRIV_CTRL_APBNSPPPCEXP2_APBNSPPPCEXP24_Pos                4                                                          /* NONSEC_PRIV_CTRL APBNSPPPCEXP2: APBNSPPPCEXP24 Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPCEXP2_APBNSPPPCEXP24_Msk                (0x1UL  << NONSEC_PRIV_CTRL_APBNSPPPCEXP2_APBNSPPPCEXP24_Pos)                 /* NONSEC_PRIV_CTRL APBNSPPPCEXP2: APBNSPPPCEXP24 Mask */

#define NONSEC_PRIV_CTRL_APBNSPPPCEXP2_WRPR_Pos                3                                                          /* NONSEC_PRIV_CTRL APBNSPPPCEXP2: WRPR Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPCEXP2_WRPR_Msk                (0x1UL  << NONSEC_PRIV_CTRL_APBNSPPPCEXP2_WRPR_Pos)                 /* NONSEC_PRIV_CTRL APBNSPPPCEXP2: WRPR Mask */

#define NONSEC_PRIV_CTRL_APBNSPPPCEXP2_APBNSPPPCEXP22_Pos                2                                                          /* NONSEC_PRIV_CTRL APBNSPPPCEXP2: APBNSPPPCEXP22 Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPCEXP2_APBNSPPPCEXP22_Msk                (0x1UL  << NONSEC_PRIV_CTRL_APBNSPPPCEXP2_APBNSPPPCEXP22_Pos)                 /* NONSEC_PRIV_CTRL APBNSPPPCEXP2: APBNSPPPCEXP22 Mask */

#define NONSEC_PRIV_CTRL_APBNSPPPCEXP2_APBNSPPPCEXP21_Pos                1                                                          /* NONSEC_PRIV_CTRL APBNSPPPCEXP2: APBNSPPPCEXP21 Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPCEXP2_APBNSPPPCEXP21_Msk                (0x1UL  << NONSEC_PRIV_CTRL_APBNSPPPCEXP2_APBNSPPPCEXP21_Pos)                 /* NONSEC_PRIV_CTRL APBNSPPPCEXP2: APBNSPPPCEXP21 Mask */

#define NONSEC_PRIV_CTRL_APBNSPPPCEXP2_PDM0_Pos                0                                                          /* NONSEC_PRIV_CTRL APBNSPPPCEXP2: PDM0 Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPCEXP2_PDM0_Msk                (0x1UL  /*<< NONSEC_PRIV_CTRL_APBNSPPPCEXP2_PDM0_Pos*/)                 /* NONSEC_PRIV_CTRL APBNSPPPCEXP2: PDM0 Mask */

/* NONSEC_PRIV_CTRL APBNSPPPCEXP3 Register Definitions */
#define NONSEC_PRIV_CTRL_APBNSPPPCEXP3_APBNSPPPCEXP315_Pos                15                                                          /* NONSEC_PRIV_CTRL APBNSPPPCEXP3: APBNSPPPCEXP315 Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPCEXP3_APBNSPPPCEXP315_Msk                (0x1UL  << NONSEC_PRIV_CTRL_APBNSPPPCEXP3_APBNSPPPCEXP315_Pos)                 /* NONSEC_PRIV_CTRL APBNSPPPCEXP3: APBNSPPPCEXP315 Mask */

#define NONSEC_PRIV_CTRL_APBNSPPPCEXP3_APBNSPPPCEXP314_Pos                14                                                          /* NONSEC_PRIV_CTRL APBNSPPPCEXP3: APBNSPPPCEXP314 Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPCEXP3_APBNSPPPCEXP314_Msk                (0x1UL  << NONSEC_PRIV_CTRL_APBNSPPPCEXP3_APBNSPPPCEXP314_Pos)                 /* NONSEC_PRIV_CTRL APBNSPPPCEXP3: APBNSPPPCEXP314 Mask */

#define NONSEC_PRIV_CTRL_APBNSPPPCEXP3_APBNSPPPCEXP313_Pos                13                                                          /* NONSEC_PRIV_CTRL APBNSPPPCEXP3: APBNSPPPCEXP313 Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPCEXP3_APBNSPPPCEXP313_Msk                (0x1UL  << NONSEC_PRIV_CTRL_APBNSPPPCEXP3_APBNSPPPCEXP313_Pos)                 /* NONSEC_PRIV_CTRL APBNSPPPCEXP3: APBNSPPPCEXP313 Mask */

#define NONSEC_PRIV_CTRL_APBNSPPPCEXP3_APBNSPPPCEXP312_Pos                12                                                          /* NONSEC_PRIV_CTRL APBNSPPPCEXP3: APBNSPPPCEXP312 Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPCEXP3_APBNSPPPCEXP312_Msk                (0x1UL  << NONSEC_PRIV_CTRL_APBNSPPPCEXP3_APBNSPPPCEXP312_Pos)                 /* NONSEC_PRIV_CTRL APBNSPPPCEXP3: APBNSPPPCEXP312 Mask */

#define NONSEC_PRIV_CTRL_APBNSPPPCEXP3_APBNSPPPCEXP311_Pos                11                                                          /* NONSEC_PRIV_CTRL APBNSPPPCEXP3: APBNSPPPCEXP311 Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPCEXP3_APBNSPPPCEXP311_Msk                (0x1UL  << NONSEC_PRIV_CTRL_APBNSPPPCEXP3_APBNSPPPCEXP311_Pos)                 /* NONSEC_PRIV_CTRL APBNSPPPCEXP3: APBNSPPPCEXP311 Mask */

#define NONSEC_PRIV_CTRL_APBNSPPPCEXP3_APBNSPPPCEXP310_Pos                10                                                          /* NONSEC_PRIV_CTRL APBNSPPPCEXP3: APBNSPPPCEXP310 Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPCEXP3_APBNSPPPCEXP310_Msk                (0x1UL  << NONSEC_PRIV_CTRL_APBNSPPPCEXP3_APBNSPPPCEXP310_Pos)                 /* NONSEC_PRIV_CTRL APBNSPPPCEXP3: APBNSPPPCEXP310 Mask */

#define NONSEC_PRIV_CTRL_APBNSPPPCEXP3_APBNSPPPCEXP39_Pos                9                                                          /* NONSEC_PRIV_CTRL APBNSPPPCEXP3: APBNSPPPCEXP39 Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPCEXP3_APBNSPPPCEXP39_Msk                (0x1UL  << NONSEC_PRIV_CTRL_APBNSPPPCEXP3_APBNSPPPCEXP39_Pos)                 /* NONSEC_PRIV_CTRL APBNSPPPCEXP3: APBNSPPPCEXP39 Mask */

#define NONSEC_PRIV_CTRL_APBNSPPPCEXP3_APBNSPPPCEXP38_Pos                8                                                          /* NONSEC_PRIV_CTRL APBNSPPPCEXP3: APBNSPPPCEXP38 Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPCEXP3_APBNSPPPCEXP38_Msk                (0x1UL  << NONSEC_PRIV_CTRL_APBNSPPPCEXP3_APBNSPPPCEXP38_Pos)                 /* NONSEC_PRIV_CTRL APBNSPPPCEXP3: APBNSPPPCEXP38 Mask */

#define NONSEC_PRIV_CTRL_APBNSPPPCEXP3_APBNSPPPCEXP37_Pos                7                                                          /* NONSEC_PRIV_CTRL APBNSPPPCEXP3: APBNSPPPCEXP37 Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPCEXP3_APBNSPPPCEXP37_Msk                (0x1UL  << NONSEC_PRIV_CTRL_APBNSPPPCEXP3_APBNSPPPCEXP37_Pos)                 /* NONSEC_PRIV_CTRL APBNSPPPCEXP3: APBNSPPPCEXP37 Mask */

#define NONSEC_PRIV_CTRL_APBNSPPPCEXP3_APBNSPPPCEXP36_Pos                6                                                          /* NONSEC_PRIV_CTRL APBNSPPPCEXP3: APBNSPPPCEXP36 Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPCEXP3_APBNSPPPCEXP36_Msk                (0x1UL  << NONSEC_PRIV_CTRL_APBNSPPPCEXP3_APBNSPPPCEXP36_Pos)                 /* NONSEC_PRIV_CTRL APBNSPPPCEXP3: APBNSPPPCEXP36 Mask */

#define NONSEC_PRIV_CTRL_APBNSPPPCEXP3_APBNSPPPCEXP35_Pos                5                                                          /* NONSEC_PRIV_CTRL APBNSPPPCEXP3: APBNSPPPCEXP35 Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPCEXP3_APBNSPPPCEXP35_Msk                (0x1UL  << NONSEC_PRIV_CTRL_APBNSPPPCEXP3_APBNSPPPCEXP35_Pos)                 /* NONSEC_PRIV_CTRL APBNSPPPCEXP3: APBNSPPPCEXP35 Mask */

#define NONSEC_PRIV_CTRL_APBNSPPPCEXP3_APBNSPPPCEXP34_Pos                4                                                          /* NONSEC_PRIV_CTRL APBNSPPPCEXP3: APBNSPPPCEXP34 Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPCEXP3_APBNSPPPCEXP34_Msk                (0x1UL  << NONSEC_PRIV_CTRL_APBNSPPPCEXP3_APBNSPPPCEXP34_Pos)                 /* NONSEC_PRIV_CTRL APBNSPPPCEXP3: APBNSPPPCEXP34 Mask */

#define NONSEC_PRIV_CTRL_APBNSPPPCEXP3_APBNSPPPCEXP33_Pos                3                                                          /* NONSEC_PRIV_CTRL APBNSPPPCEXP3: APBNSPPPCEXP33 Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPCEXP3_APBNSPPPCEXP33_Msk                (0x1UL  << NONSEC_PRIV_CTRL_APBNSPPPCEXP3_APBNSPPPCEXP33_Pos)                 /* NONSEC_PRIV_CTRL APBNSPPPCEXP3: APBNSPPPCEXP33 Mask */

#define NONSEC_PRIV_CTRL_APBNSPPPCEXP3_APBNSPPPCEXP32_Pos                2                                                          /* NONSEC_PRIV_CTRL APBNSPPPCEXP3: APBNSPPPCEXP32 Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPCEXP3_APBNSPPPCEXP32_Msk                (0x1UL  << NONSEC_PRIV_CTRL_APBNSPPPCEXP3_APBNSPPPCEXP32_Pos)                 /* NONSEC_PRIV_CTRL APBNSPPPCEXP3: APBNSPPPCEXP32 Mask */

#define NONSEC_PRIV_CTRL_APBNSPPPCEXP3_APBNSPPPCEXP31_Pos                1                                                          /* NONSEC_PRIV_CTRL APBNSPPPCEXP3: APBNSPPPCEXP31 Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPCEXP3_APBNSPPPCEXP31_Msk                (0x1UL  << NONSEC_PRIV_CTRL_APBNSPPPCEXP3_APBNSPPPCEXP31_Pos)                 /* NONSEC_PRIV_CTRL APBNSPPPCEXP3: APBNSPPPCEXP31 Mask */

#define NONSEC_PRIV_CTRL_APBNSPPPCEXP3_APBNSPPPCEXP30_Pos                0                                                          /* NONSEC_PRIV_CTRL APBNSPPPCEXP3: APBNSPPPCEXP30 Positions */
#define NONSEC_PRIV_CTRL_APBNSPPPCEXP3_APBNSPPPCEXP30_Msk                (0x1UL  /*<< NONSEC_PRIV_CTRL_APBNSPPPCEXP3_APBNSPPPCEXP30_Pos*/)                 /* NONSEC_PRIV_CTRL APBNSPPPCEXP3: APBNSPPPCEXP30 Mask */

/* NONSEC_PRIV_CTRL PIDR4 Register Definitions */
#define NONSEC_PRIV_CTRL_PIDR4_SIZE_Pos                4                                                          /* NONSEC_PRIV_CTRL PIDR4: SIZE Positions */
#define NONSEC_PRIV_CTRL_PIDR4_SIZE_Msk                (0xFUL  << NONSEC_PRIV_CTRL_PIDR4_SIZE_Pos)                 /* NONSEC_PRIV_CTRL PIDR4: SIZE Mask */

#define NONSEC_PRIV_CTRL_PIDR4_DES_2_Pos                0                                                          /* NONSEC_PRIV_CTRL PIDR4: DES_2 Positions */
#define NONSEC_PRIV_CTRL_PIDR4_DES_2_Msk                (0xFUL  /*<< NONSEC_PRIV_CTRL_PIDR4_DES_2_Pos*/)                 /* NONSEC_PRIV_CTRL PIDR4: DES_2 Mask */

/* NONSEC_PRIV_CTRL PIDR0 Register Definitions */
#define NONSEC_PRIV_CTRL_PIDR0_PART_0_Pos                0                                                          /* NONSEC_PRIV_CTRL PIDR0: PART_0 Positions */
#define NONSEC_PRIV_CTRL_PIDR0_PART_0_Msk                (0xFFUL  /*<< NONSEC_PRIV_CTRL_PIDR0_PART_0_Pos*/)                 /* NONSEC_PRIV_CTRL PIDR0: PART_0 Mask */

/* NONSEC_PRIV_CTRL PIDR1 Register Definitions */
#define NONSEC_PRIV_CTRL_PIDR1_DES_0_Pos                4                                                          /* NONSEC_PRIV_CTRL PIDR1: DES_0 Positions */
#define NONSEC_PRIV_CTRL_PIDR1_DES_0_Msk                (0xFUL  << NONSEC_PRIV_CTRL_PIDR1_DES_0_Pos)                 /* NONSEC_PRIV_CTRL PIDR1: DES_0 Mask */

#define NONSEC_PRIV_CTRL_PIDR1_PART_1_Pos                0                                                          /* NONSEC_PRIV_CTRL PIDR1: PART_1 Positions */
#define NONSEC_PRIV_CTRL_PIDR1_PART_1_Msk                (0xFUL  /*<< NONSEC_PRIV_CTRL_PIDR1_PART_1_Pos*/)                 /* NONSEC_PRIV_CTRL PIDR1: PART_1 Mask */

/* NONSEC_PRIV_CTRL PIDR2 Register Definitions */
#define NONSEC_PRIV_CTRL_PIDR2_REVISION_Pos                4                                                          /* NONSEC_PRIV_CTRL PIDR2: REVISION Positions */
#define NONSEC_PRIV_CTRL_PIDR2_REVISION_Msk                (0xFUL  << NONSEC_PRIV_CTRL_PIDR2_REVISION_Pos)                 /* NONSEC_PRIV_CTRL PIDR2: REVISION Mask */

#define NONSEC_PRIV_CTRL_PIDR2_JEDEC_Pos                3                                                          /* NONSEC_PRIV_CTRL PIDR2: JEDEC Positions */
#define NONSEC_PRIV_CTRL_PIDR2_JEDEC_Msk                (0x1UL  << NONSEC_PRIV_CTRL_PIDR2_JEDEC_Pos)                 /* NONSEC_PRIV_CTRL PIDR2: JEDEC Mask */

#define NONSEC_PRIV_CTRL_PIDR2_DES_1_Pos                0                                                          /* NONSEC_PRIV_CTRL PIDR2: DES_1 Positions */
#define NONSEC_PRIV_CTRL_PIDR2_DES_1_Msk                (0x7UL  /*<< NONSEC_PRIV_CTRL_PIDR2_DES_1_Pos*/)                 /* NONSEC_PRIV_CTRL PIDR2: DES_1 Mask */

/* NONSEC_PRIV_CTRL PIDR3 Register Definitions */
#define NONSEC_PRIV_CTRL_PIDR3_REVAND_Pos                4                                                          /* NONSEC_PRIV_CTRL PIDR3: REVAND Positions */
#define NONSEC_PRIV_CTRL_PIDR3_REVAND_Msk                (0xFUL  << NONSEC_PRIV_CTRL_PIDR3_REVAND_Pos)                 /* NONSEC_PRIV_CTRL PIDR3: REVAND Mask */

#define NONSEC_PRIV_CTRL_PIDR3_CMOD_Pos                0                                                          /* NONSEC_PRIV_CTRL PIDR3: CMOD Positions */
#define NONSEC_PRIV_CTRL_PIDR3_CMOD_Msk                (0xFUL  /*<< NONSEC_PRIV_CTRL_PIDR3_CMOD_Pos*/)                 /* NONSEC_PRIV_CTRL PIDR3: CMOD Mask */

/* NONSEC_PRIV_CTRL CIDR0 Register Definitions */
#define NONSEC_PRIV_CTRL_CIDR0_PRMBL_0_Pos                0                                                          /* NONSEC_PRIV_CTRL CIDR0: PRMBL_0 Positions */
#define NONSEC_PRIV_CTRL_CIDR0_PRMBL_0_Msk                (0xFFUL  /*<< NONSEC_PRIV_CTRL_CIDR0_PRMBL_0_Pos*/)                 /* NONSEC_PRIV_CTRL CIDR0: PRMBL_0 Mask */

/* NONSEC_PRIV_CTRL CIDR1 Register Definitions */
#define NONSEC_PRIV_CTRL_CIDR1_CLASS_Pos                4                                                          /* NONSEC_PRIV_CTRL CIDR1: CLASS Positions */
#define NONSEC_PRIV_CTRL_CIDR1_CLASS_Msk                (0xFUL  << NONSEC_PRIV_CTRL_CIDR1_CLASS_Pos)                 /* NONSEC_PRIV_CTRL CIDR1: CLASS Mask */

#define NONSEC_PRIV_CTRL_CIDR1_PRMBL_1_Pos                0                                                          /* NONSEC_PRIV_CTRL CIDR1: PRMBL_1 Positions */
#define NONSEC_PRIV_CTRL_CIDR1_PRMBL_1_Msk                (0xFUL  /*<< NONSEC_PRIV_CTRL_CIDR1_PRMBL_1_Pos*/)                 /* NONSEC_PRIV_CTRL CIDR1: PRMBL_1 Mask */

/* NONSEC_PRIV_CTRL CIDR2 Register Definitions */
#define NONSEC_PRIV_CTRL_CIDR2_PRMBL_2_Pos                0                                                          /* NONSEC_PRIV_CTRL CIDR2: PRMBL_2 Positions */
#define NONSEC_PRIV_CTRL_CIDR2_PRMBL_2_Msk                (0xFFUL  /*<< NONSEC_PRIV_CTRL_CIDR2_PRMBL_2_Pos*/)                 /* NONSEC_PRIV_CTRL CIDR2: PRMBL_2 Mask */

/* NONSEC_PRIV_CTRL CIDR3 Register Definitions */
#define NONSEC_PRIV_CTRL_CIDR3_PRMBL_3_Pos                0                                                          /* NONSEC_PRIV_CTRL CIDR3: PRMBL_3 Positions */
#define NONSEC_PRIV_CTRL_CIDR3_PRMBL_3_Msk                (0xFFUL  /*<< NONSEC_PRIV_CTRL_CIDR3_PRMBL_3_Pos*/)                 /* NONSEC_PRIV_CTRL CIDR3: PRMBL_3 Mask */

/*---------------- MHU ----------------*/
typedef struct
{
__IM   uint32_t CPU0INTR_STAT;                  /* Offset: 0x0 (read-only) CPU0INTR_STAT Register    */
__OM   uint32_t CPU0INTR_SET;                  /* Offset: 0x4 (write-only) CPU0INTR_SET Register    */
__OM   uint32_t CPU0INTR_CLR;                  /* Offset: 0x8 (write-only) CPU0INTR_CLR Register    */
       uint32_t RESERVED0[1];
__IM   uint32_t CPU1INTR_STAT;                  /* Offset: 0x10 (read-only) CPU1INTR_STAT Register    */
__OM   uint32_t CPU1INTR_SET;                  /* Offset: 0x14 (write-only) CPU1INTR_SET Register    */
__OM   uint32_t CPU1INTR_CLR;                  /* Offset: 0x18 (write-only) CPU1INTR_CLR Register    */
       uint32_t RESERVED1[1005];
__IM   uint32_t PIDR4;                  /* Offset: 0xFD0 (read-only) PIDR4 Register    */
       uint32_t RESERVED2[3];
__IM   uint32_t PIDR0;                  /* Offset: 0xFE0 (read-only) PIDR0 Register    */
__IM   uint32_t PIDR1;                  /* Offset: 0xFE4 (read-only) PIDR1 Register    */
__IM   uint32_t PIDR2;                  /* Offset: 0xFE8 (read-only) PIDR2 Register    */
__IM   uint32_t PIDR3;                  /* Offset: 0xFEC (read-only) PIDR3 Register    */
__IM   uint32_t CIDR0;                  /* Offset: 0xFF0 (read-only) CIDR0 Register    */
__IM   uint32_t CIDR1;                  /* Offset: 0xFF4 (read-only) CIDR1 Register    */
__IM   uint32_t CIDR2;                  /* Offset: 0xFF8 (read-only) CIDR2 Register    */
__IM   uint32_t CIDR3;                  /* Offset: 0xFFC (read-only) CIDR3 Register    */
}MHU_TypeDef;

/* MHU CPU0INTR_STAT Register Definitions */
#define MHU_CPU0INTR_STAT_CPU0INTR_STAT_Pos                0                                                          /* MHU CPU0INTR_STAT: CPU0INTR_STAT Positions */
#define MHU_CPU0INTR_STAT_CPU0INTR_STAT_Msk                (0xFUL  /*<< MHU_CPU0INTR_STAT_CPU0INTR_STAT_Pos*/)                 /* MHU CPU0INTR_STAT: CPU0INTR_STAT Mask */

/* MHU CPU0INTR_SET Register Definitions */
#define MHU_CPU0INTR_SET_CPU0INTR_SET_Pos                0                                                          /* MHU CPU0INTR_SET: CPU0INTR_SET Positions */
#define MHU_CPU0INTR_SET_CPU0INTR_SET_Msk                (0xFUL  /*<< MHU_CPU0INTR_SET_CPU0INTR_SET_Pos*/)                 /* MHU CPU0INTR_SET: CPU0INTR_SET Mask */

/* MHU CPU0INTR_CLR Register Definitions */
#define MHU_CPU0INTR_CLR_CPU0INTR_CLR_Pos                0                                                          /* MHU CPU0INTR_CLR: CPU0INTR_CLR Positions */
#define MHU_CPU0INTR_CLR_CPU0INTR_CLR_Msk                (0xFUL  /*<< MHU_CPU0INTR_CLR_CPU0INTR_CLR_Pos*/)                 /* MHU CPU0INTR_CLR: CPU0INTR_CLR Mask */

/* MHU CPU1INTR_STAT Register Definitions */
#define MHU_CPU1INTR_STAT_CPU1INTR_STAT_Pos                0                                                          /* MHU CPU1INTR_STAT: CPU1INTR_STAT Positions */
#define MHU_CPU1INTR_STAT_CPU1INTR_STAT_Msk                (0xFUL  /*<< MHU_CPU1INTR_STAT_CPU1INTR_STAT_Pos*/)                 /* MHU CPU1INTR_STAT: CPU1INTR_STAT Mask */

/* MHU CPU1INTR_SET Register Definitions */
#define MHU_CPU1INTR_SET_CPU1INTR_SET_Pos                0                                                          /* MHU CPU1INTR_SET: CPU1INTR_SET Positions */
#define MHU_CPU1INTR_SET_CPU1INTR_SET_Msk                (0xFUL  /*<< MHU_CPU1INTR_SET_CPU1INTR_SET_Pos*/)                 /* MHU CPU1INTR_SET: CPU1INTR_SET Mask */

/* MHU CPU1INTR_CLR Register Definitions */
#define MHU_CPU1INTR_CLR_CPU1INTR_CLR_Pos                0                                                          /* MHU CPU1INTR_CLR: CPU1INTR_CLR Positions */
#define MHU_CPU1INTR_CLR_CPU1INTR_CLR_Msk                (0xFUL  /*<< MHU_CPU1INTR_CLR_CPU1INTR_CLR_Pos*/)                 /* MHU CPU1INTR_CLR: CPU1INTR_CLR Mask */

/* MHU PIDR4 Register Definitions */
#define MHU_PIDR4_SIZE_Pos                4                                                          /* MHU PIDR4: SIZE Positions */
#define MHU_PIDR4_SIZE_Msk                (0xFUL  << MHU_PIDR4_SIZE_Pos)                 /* MHU PIDR4: SIZE Mask */

#define MHU_PIDR4_DES_2_Pos                0                                                          /* MHU PIDR4: DES_2 Positions */
#define MHU_PIDR4_DES_2_Msk                (0xFUL  /*<< MHU_PIDR4_DES_2_Pos*/)                 /* MHU PIDR4: DES_2 Mask */

/* MHU PIDR0 Register Definitions */
#define MHU_PIDR0_PART_0_Pos                0                                                          /* MHU PIDR0: PART_0 Positions */
#define MHU_PIDR0_PART_0_Msk                (0xFFUL  /*<< MHU_PIDR0_PART_0_Pos*/)                 /* MHU PIDR0: PART_0 Mask */

/* MHU PIDR1 Register Definitions */
#define MHU_PIDR1_DES_0_Pos                4                                                          /* MHU PIDR1: DES_0 Positions */
#define MHU_PIDR1_DES_0_Msk                (0xFUL  << MHU_PIDR1_DES_0_Pos)                 /* MHU PIDR1: DES_0 Mask */

#define MHU_PIDR1_PART_1_Pos                0                                                          /* MHU PIDR1: PART_1 Positions */
#define MHU_PIDR1_PART_1_Msk                (0xFUL  /*<< MHU_PIDR1_PART_1_Pos*/)                 /* MHU PIDR1: PART_1 Mask */

/* MHU PIDR2 Register Definitions */
#define MHU_PIDR2_REVISION_Pos                4                                                          /* MHU PIDR2: REVISION Positions */
#define MHU_PIDR2_REVISION_Msk                (0xFUL  << MHU_PIDR2_REVISION_Pos)                 /* MHU PIDR2: REVISION Mask */

#define MHU_PIDR2_JEDEC_Pos                3                                                          /* MHU PIDR2: JEDEC Positions */
#define MHU_PIDR2_JEDEC_Msk                (0x1UL  << MHU_PIDR2_JEDEC_Pos)                 /* MHU PIDR2: JEDEC Mask */

#define MHU_PIDR2_DES_1_Pos                0                                                          /* MHU PIDR2: DES_1 Positions */
#define MHU_PIDR2_DES_1_Msk                (0x7UL  /*<< MHU_PIDR2_DES_1_Pos*/)                 /* MHU PIDR2: DES_1 Mask */

/* MHU PIDR3 Register Definitions */
#define MHU_PIDR3_REVAND_Pos                4                                                          /* MHU PIDR3: REVAND Positions */
#define MHU_PIDR3_REVAND_Msk                (0xFUL  << MHU_PIDR3_REVAND_Pos)                 /* MHU PIDR3: REVAND Mask */

#define MHU_PIDR3_CMOD_Pos                0                                                          /* MHU PIDR3: CMOD Positions */
#define MHU_PIDR3_CMOD_Msk                (0xFUL  /*<< MHU_PIDR3_CMOD_Pos*/)                 /* MHU PIDR3: CMOD Mask */

/* MHU CIDR0 Register Definitions */
#define MHU_CIDR0_PRMBL_0_Pos                0                                                          /* MHU CIDR0: PRMBL_0 Positions */
#define MHU_CIDR0_PRMBL_0_Msk                (0xFFUL  /*<< MHU_CIDR0_PRMBL_0_Pos*/)                 /* MHU CIDR0: PRMBL_0 Mask */

/* MHU CIDR1 Register Definitions */
#define MHU_CIDR1_CLASS_Pos                4                                                          /* MHU CIDR1: CLASS Positions */
#define MHU_CIDR1_CLASS_Msk                (0xFUL  << MHU_CIDR1_CLASS_Pos)                 /* MHU CIDR1: CLASS Mask */

#define MHU_CIDR1_PRMBL_1_Pos                0                                                          /* MHU CIDR1: PRMBL_1 Positions */
#define MHU_CIDR1_PRMBL_1_Msk                (0xFUL  /*<< MHU_CIDR1_PRMBL_1_Pos*/)                 /* MHU CIDR1: PRMBL_1 Mask */

/* MHU CIDR2 Register Definitions */
#define MHU_CIDR2_PRMBL_2_Pos                0                                                          /* MHU CIDR2: PRMBL_2 Positions */
#define MHU_CIDR2_PRMBL_2_Msk                (0xFFUL  /*<< MHU_CIDR2_PRMBL_2_Pos*/)                 /* MHU CIDR2: PRMBL_2 Mask */

/* MHU CIDR3 Register Definitions */
#define MHU_CIDR3_PRMBL_3_Pos                0                                                          /* MHU CIDR3: PRMBL_3 Positions */
#define MHU_CIDR3_PRMBL_3_Msk                (0xFFUL  /*<< MHU_CIDR3_PRMBL_3_Pos*/)                 /* MHU CIDR3: PRMBL_3 Mask */

/*----------------------------- ICACHE ---------------------------------------------*/
typedef struct
{
__IM   uint32_t ICHWPARAMS;                  /* Offset: 0x0 (read-only) ICHWPARAMS Register    */
__IOM  uint32_t ICCTRL;                  /* Offset: 0x4 (read-write) ICCTRL Register    */
       uint32_t RESERVED1[62];
__IM   uint32_t ICIRQSTAT;                  /* Offset: 0x100 (read-only) ICIRQSTAT Register    */
__OM   uint32_t ICIRQSCLR;                  /* Offset: 0x104 (write-only) ICIRQSCLR Register    */
__IOM  uint32_t ICIRQEN;                  /* Offset: 0x108 (read-write) ICIRQEN Register    */
__IM   uint32_t ICDBGFILLERR;                  /* Offset: 0x10C (read-only) ICDBGFILLERR Register    */
       uint32_t RESERVED2[124];
__IM   uint32_t ICSH;                  /* Offset: 0x300 (read-only) ICSH Register    */
__IM   uint32_t ICSM;                  /* Offset: 0x304 (read-only) ICSM Register    */
__IM   uint32_t ICSUC;                  /* Offset: 0x308 (read-only) ICSUC Register    */
       uint32_t RESERVED3[817];
__IM   uint32_t PIDR4;                  /* Offset: 0xFD0 (read-only) PIDR4 Register    */
       uint32_t RESERVED4[3];
__IM   uint32_t PIDR0;                  /* Offset: 0xFE0 (read-only) PIDR0 Register    */
__IM   uint32_t PIDR1;                  /* Offset: 0xFE4 (read-only) PIDR1 Register    */
__IM   uint32_t PIDR2;                  /* Offset: 0xFE8 (read-only) PIDR2 Register    */
__IM   uint32_t PIDR3;                  /* Offset: 0xFEC (read-only) PIDR3 Register    */
__IM   uint32_t CIDR0;                  /* Offset: 0xFF0 (read-only) CIDR0 Register    */
__IM   uint32_t CIDR1;                  /* Offset: 0xFF4 (read-only) CIDR1 Register    */
__IM   uint32_t CIDR2;                  /* Offset: 0xFF8 (read-only) CIDR2 Register    */
__IM   uint32_t CIDR3;                  /* Offset: 0xFFC (read-only) CIDR3 Register    */
}ICACHE_TypeDef;

/* ICACHE ICHWPARAMS Register Definitions */
#define ICACHE_ICHWPARAMS_COFFSET_Pos                16                                                          /* ICACHE ICHWPARAMS: COFFSET Positions */
#define ICACHE_ICHWPARAMS_COFFSET_Msk                (0xFFFFUL  << ICACHE_ICHWPARAMS_COFFSET_Pos)                 /* ICACHE ICHWPARAMS: COFFSET Mask */

#define ICACHE_ICHWPARAMS_COFFSIZE_Pos                12                                                          /* ICACHE ICHWPARAMS: COFFSIZE Positions */
#define ICACHE_ICHWPARAMS_COFFSIZE_Msk                (0xFUL  << ICACHE_ICHWPARAMS_COFFSIZE_Pos)                 /* ICACHE ICHWPARAMS: COFFSIZE Mask */

#define ICACHE_ICHWPARAMS_INVMAT_Pos                6                                                          /* ICACHE ICHWPARAMS: INVMAT Positions */
#define ICACHE_ICHWPARAMS_INVMAT_Msk                (0x1UL  << ICACHE_ICHWPARAMS_INVMAT_Pos)                 /* ICACHE ICHWPARAMS: INVMAT Mask */

#define ICACHE_ICHWPARAMS_DMA_Pos                5                                                          /* ICACHE ICHWPARAMS: DMA Positions */
#define ICACHE_ICHWPARAMS_DMA_Msk                (0x1UL  << ICACHE_ICHWPARAMS_DMA_Pos)                 /* ICACHE ICHWPARAMS: DMA Mask */

#define ICACHE_ICHWPARAMS_STATS_Pos                4                                                          /* ICACHE ICHWPARAMS: STATS Positions */
#define ICACHE_ICHWPARAMS_STATS_Msk                (0x1UL  << ICACHE_ICHWPARAMS_STATS_Pos)                 /* ICACHE ICHWPARAMS: STATS Mask */

#define ICACHE_ICHWPARAMS_CSIZE_Pos                0                                                          /* ICACHE ICHWPARAMS: CSIZE Positions */
#define ICACHE_ICHWPARAMS_CSIZE_Msk                (0xFUL  /*<< ICACHE_ICHWPARAMS_CSIZE_Pos*/)                 /* ICACHE ICHWPARAMS: CSIZE Mask */

/* ICACHE ICCTRL Register Definitions */
#define ICACHE_ICCTRL_HALLOC_Pos                5                                                          /* ICACHE ICCTRL: HALLOC Positions */
#define ICACHE_ICCTRL_HALLOC_Msk                (0x1UL  << ICACHE_ICCTRL_HALLOC_Pos)                 /* ICACHE ICCTRL: HALLOC Mask */

#define ICACHE_ICCTRL_STATC_Pos                4                                                          /* ICACHE ICCTRL: STATC Positions */
#define ICACHE_ICCTRL_STATC_Msk                (0x1UL  << ICACHE_ICCTRL_STATC_Pos)                 /* ICACHE ICCTRL: STATC Mask */

#define ICACHE_ICCTRL_STATEN_Pos                3                                                          /* ICACHE ICCTRL: STATEN Positions */
#define ICACHE_ICCTRL_STATEN_Msk                (0x1UL  << ICACHE_ICCTRL_STATEN_Pos)                 /* ICACHE ICCTRL: STATEN Mask */

#define ICACHE_ICCTRL_FINV_Pos                2                                                          /* ICACHE ICCTRL: FINV Positions */
#define ICACHE_ICCTRL_FINV_Msk                (0x1UL  << ICACHE_ICCTRL_FINV_Pos)                 /* ICACHE ICCTRL: FINV Mask */

#define ICACHE_ICCTRL_PINV_Pos                1                                                          /* ICACHE ICCTRL: PINV Positions */
#define ICACHE_ICCTRL_PINV_Msk                (0x1UL  << ICACHE_ICCTRL_PINV_Pos)                 /* ICACHE ICCTRL: PINV Mask */

#define ICACHE_ICCTRL_CACHEEN_Pos                0                                                          /* ICACHE ICCTRL: CACHEEN Positions */
#define ICACHE_ICCTRL_CACHEEN_Msk                (0x1UL  /*<< ICACHE_ICCTRL_CACHEEN_Pos*/)                 /* ICACHE ICCTRL: CACHEEN Mask */

/* ICACHE ICIRQSTAT Register Definitions */
#define ICACHE_ICIRQSTAT_DLE_STATUS_Pos                8                                                          /* ICACHE ICIRQSTAT: DLE_STATUS Positions */
#define ICACHE_ICIRQSTAT_DLE_STATUS_Msk                (0x1UL  << ICACHE_ICIRQSTAT_DLE_STATUS_Pos)                 /* ICACHE ICIRQSTAT: DLE_STATUS Mask */

#define ICACHE_ICIRQSTAT_DFA_STATUS_Pos                7                                                          /* ICACHE ICIRQSTAT: DFA_STATUS Positions */
#define ICACHE_ICIRQSTAT_DFA_STATUS_Msk                (0x1UL  << ICACHE_ICIRQSTAT_DFA_STATUS_Pos)                 /* ICACHE ICIRQSTAT: DFA_STATUS Mask */

#define ICACHE_ICIRQSTAT_DFC_STATUS_Pos                6                                                          /* ICACHE ICIRQSTAT: DFC_STATUS Positions */
#define ICACHE_ICIRQSTAT_DFC_STATUS_Msk                (0x1UL  << ICACHE_ICIRQSTAT_DFC_STATUS_Pos)                 /* ICACHE ICIRQSTAT: DFC_STATUS Mask */

#define ICACHE_ICIRQSTAT_SS_STATUS_Pos                5                                                          /* ICACHE ICIRQSTAT: SS_STATUS Positions */
#define ICACHE_ICIRQSTAT_SS_STATUS_Msk                (0x1UL  << ICACHE_ICIRQSTAT_SS_STATUS_Pos)                 /* ICACHE ICIRQSTAT: SS_STATUS Mask */

#define ICACHE_ICIRQSTAT_SV_STATUS_Pos                4                                                          /* ICACHE ICIRQSTAT: SV_STATUS Positions */
#define ICACHE_ICIRQSTAT_SV_STATUS_Msk                (0x1UL  << ICACHE_ICIRQSTAT_SV_STATUS_Pos)                 /* ICACHE ICIRQSTAT: SV_STATUS Mask */

#define ICACHE_ICIRQSTAT_CFE_STATUS_Pos                3                                                          /* ICACHE ICIRQSTAT: CFE_STATUS Positions */
#define ICACHE_ICIRQSTAT_CFE_STATUS_Msk                (0x1UL  << ICACHE_ICIRQSTAT_CFE_STATUS_Pos)                 /* ICACHE ICIRQSTAT: CFE_STATUS Mask */

#define ICACHE_ICIRQSTAT_CEC_STATUS_Pos                2                                                          /* ICACHE ICIRQSTAT: CEC_STATUS Positions */
#define ICACHE_ICIRQSTAT_CEC_STATUS_Msk                (0x1UL  << ICACHE_ICIRQSTAT_CEC_STATUS_Pos)                 /* ICACHE ICIRQSTAT: CEC_STATUS Mask */

#define ICACHE_ICIRQSTAT_CDC_STATUS_Pos                1                                                          /* ICACHE ICIRQSTAT: CDC_STATUS Positions */
#define ICACHE_ICIRQSTAT_CDC_STATUS_Msk                (0x1UL  << ICACHE_ICIRQSTAT_CDC_STATUS_Pos)                 /* ICACHE ICIRQSTAT: CDC_STATUS Mask */

#define ICACHE_ICIRQSTAT_IC_STATUS_Pos                0                                                          /* ICACHE ICIRQSTAT: IC_STATUS Positions */
#define ICACHE_ICIRQSTAT_IC_STATUS_Msk                (0x1UL  /*<< ICACHE_ICIRQSTAT_IC_STATUS_Pos*/)                 /* ICACHE ICIRQSTAT: IC_STATUS Mask */

/* ICACHE ICIRQSCLR Register Definitions */
#define ICACHE_ICIRQSCLR_DLE_CLR_Pos                8                                                          /* ICACHE ICIRQSCLR: DLE_CLR Positions */
#define ICACHE_ICIRQSCLR_DLE_CLR_Msk                (0x1UL  << ICACHE_ICIRQSCLR_DLE_CLR_Pos)                 /* ICACHE ICIRQSCLR: DLE_CLR Mask */

#define ICACHE_ICIRQSCLR_DFA_CLR_Pos                7                                                          /* ICACHE ICIRQSCLR: DFA_CLR Positions */
#define ICACHE_ICIRQSCLR_DFA_CLR_Msk                (0x1UL  << ICACHE_ICIRQSCLR_DFA_CLR_Pos)                 /* ICACHE ICIRQSCLR: DFA_CLR Mask */

#define ICACHE_ICIRQSCLR_DFC_CLR_Pos                6                                                          /* ICACHE ICIRQSCLR: DFC_CLR Positions */
#define ICACHE_ICIRQSCLR_DFC_CLR_Msk                (0x1UL  << ICACHE_ICIRQSCLR_DFC_CLR_Pos)                 /* ICACHE ICIRQSCLR: DFC_CLR Mask */

#define ICACHE_ICIRQSCLR_SS_CLR_Pos                5                                                          /* ICACHE ICIRQSCLR: SS_CLR Positions */
#define ICACHE_ICIRQSCLR_SS_CLR_Msk                (0x1UL  << ICACHE_ICIRQSCLR_SS_CLR_Pos)                 /* ICACHE ICIRQSCLR: SS_CLR Mask */

#define ICACHE_ICIRQSCLR_SV_CLR_Pos                4                                                          /* ICACHE ICIRQSCLR: SV_CLR Positions */
#define ICACHE_ICIRQSCLR_SV_CLR_Msk                (0x1UL  << ICACHE_ICIRQSCLR_SV_CLR_Pos)                 /* ICACHE ICIRQSCLR: SV_CLR Mask */

#define ICACHE_ICIRQSCLR_CFE_CLR_Pos                3                                                          /* ICACHE ICIRQSCLR: CFE_CLR Positions */
#define ICACHE_ICIRQSCLR_CFE_CLR_Msk                (0x1UL  << ICACHE_ICIRQSCLR_CFE_CLR_Pos)                 /* ICACHE ICIRQSCLR: CFE_CLR Mask */

#define ICACHE_ICIRQSCLR_CEC_CLR_Pos                2                                                          /* ICACHE ICIRQSCLR: CEC_CLR Positions */
#define ICACHE_ICIRQSCLR_CEC_CLR_Msk                (0x1UL  << ICACHE_ICIRQSCLR_CEC_CLR_Pos)                 /* ICACHE ICIRQSCLR: CEC_CLR Mask */

#define ICACHE_ICIRQSCLR_CDC_CLR_Pos                1                                                          /* ICACHE ICIRQSCLR: CDC_CLR Positions */
#define ICACHE_ICIRQSCLR_CDC_CLR_Msk                (0x1UL  << ICACHE_ICIRQSCLR_CDC_CLR_Pos)                 /* ICACHE ICIRQSCLR: CDC_CLR Mask */

#define ICACHE_ICIRQSCLR_IC_CLR_Pos                0                                                          /* ICACHE ICIRQSCLR: IC_CLR Positions */
#define ICACHE_ICIRQSCLR_IC_CLR_Msk                (0x1UL  /*<< ICACHE_ICIRQSCLR_IC_CLR_Pos*/)                 /* ICACHE ICIRQSCLR: IC_CLR Mask */

/* ICACHE ICIRQEN Register Definitions */
#define ICACHE_ICIRQEN_DLE_EN_Pos                8                                                          /* ICACHE ICIRQEN: DLE_EN Positions */
#define ICACHE_ICIRQEN_DLE_EN_Msk                (0x1UL  << ICACHE_ICIRQEN_DLE_EN_Pos)                 /* ICACHE ICIRQEN: DLE_EN Mask */

#define ICACHE_ICIRQEN_DFA_EN_Pos                7                                                          /* ICACHE ICIRQEN: DFA_EN Positions */
#define ICACHE_ICIRQEN_DFA_EN_Msk                (0x1UL  << ICACHE_ICIRQEN_DFA_EN_Pos)                 /* ICACHE ICIRQEN: DFA_EN Mask */

#define ICACHE_ICIRQEN_DFC_EN_Pos                6                                                          /* ICACHE ICIRQEN: DFC_EN Positions */
#define ICACHE_ICIRQEN_DFC_EN_Msk                (0x1UL  << ICACHE_ICIRQEN_DFC_EN_Pos)                 /* ICACHE ICIRQEN: DFC_EN Mask */

#define ICACHE_ICIRQEN_SS_EN_Pos                5                                                          /* ICACHE ICIRQEN: SS_EN Positions */
#define ICACHE_ICIRQEN_SS_EN_Msk                (0x1UL  << ICACHE_ICIRQEN_SS_EN_Pos)                 /* ICACHE ICIRQEN: SS_EN Mask */

#define ICACHE_ICIRQEN_SV_EN_Pos                4                                                          /* ICACHE ICIRQEN: SV_EN Positions */
#define ICACHE_ICIRQEN_SV_EN_Msk                (0x1UL  << ICACHE_ICIRQEN_SV_EN_Pos)                 /* ICACHE ICIRQEN: SV_EN Mask */

#define ICACHE_ICIRQEN_CFE_EN_Pos                3                                                          /* ICACHE ICIRQEN: CFE_EN Positions */
#define ICACHE_ICIRQEN_CFE_EN_Msk                (0x1UL  << ICACHE_ICIRQEN_CFE_EN_Pos)                 /* ICACHE ICIRQEN: CFE_EN Mask */

#define ICACHE_ICIRQEN_CEC_EN_Pos                2                                                          /* ICACHE ICIRQEN: CEC_EN Positions */
#define ICACHE_ICIRQEN_CEC_EN_Msk                (0x1UL  << ICACHE_ICIRQEN_CEC_EN_Pos)                 /* ICACHE ICIRQEN: CEC_EN Mask */

#define ICACHE_ICIRQEN_CDC_EN_Pos                1                                                          /* ICACHE ICIRQEN: CDC_EN Positions */
#define ICACHE_ICIRQEN_CDC_EN_Msk                (0x1UL  << ICACHE_ICIRQEN_CDC_EN_Pos)                 /* ICACHE ICIRQEN: CDC_EN Mask */

#define ICACHE_ICIRQEN_IC_EN_Pos                0                                                          /* ICACHE ICIRQEN: IC_EN Positions */
#define ICACHE_ICIRQEN_IC_EN_Msk                (0x1UL  /*<< ICACHE_ICIRQEN_IC_EN_Pos*/)                 /* ICACHE ICIRQEN: IC_EN Mask */

/* ICACHE ICDBGFILLERR Register Definitions */
#define ICACHE_ICDBGFILLERR_ERRADDR_Pos                0                                                          /* ICACHE ICDBGFILLERR: ERRADDR Positions */
#define ICACHE_ICDBGFILLERR_ERRADDR_Msk                (0xFFFFFFFFUL  /*<< ICACHE_ICDBGFILLERR_ERRADDR_Pos*/)                 /* ICACHE ICDBGFILLERR: ERRADDR Mask */

/* ICACHE ICFBSADD Register Definitions */
#define ICACHE_ICFBSADD_FBSADD_Pos                4                                                          /* ICACHE ICFBSADD: FBSADD Positions */
#define ICACHE_ICFBSADD_FBSADD_Msk                (0xFFFFFFFUL  << ICACHE_ICFBSADD_FBSADD_Pos)                 /* ICACHE ICFBSADD: FBSADD Mask */

/* ICACHE ICFBSIZE Register Definitions */
#define ICACHE_ICFBSIZE_FBSIZE_Pos                4                                                          /* ICACHE ICFBSIZE: FBSIZE Positions */
#define ICACHE_ICFBSIZE_FBSIZE_Msk                (0xFFFUL  << ICACHE_ICFBSIZE_FBSIZE_Pos)                 /* ICACHE ICFBSIZE: FBSIZE Mask */

/* ICACHE ICFBSTAT Register Definitions */
#define ICACHE_ICFBSTAT_CURRADR_Pos                2                                                          /* ICACHE ICFBSTAT: CURRADR Positions */
#define ICACHE_ICFBSTAT_CURRADR_Msk                (0x3FFFFFFFUL  << ICACHE_ICFBSTAT_CURRADR_Pos)                 /* ICACHE ICFBSTAT: CURRADR Mask */

#define ICACHE_ICFBSTAT_FIP_Pos                0                                                          /* ICACHE ICFBSTAT: FIP Positions */
#define ICACHE_ICFBSTAT_FIP_Msk                (0x1UL  /*<< ICACHE_ICFBSTAT_FIP_Pos*/)                 /* ICACHE ICFBSTAT: FIP Mask */

/* ICACHE ICFBCTRL Register Definitions */
#define ICACHE_ICFBCTRL_ARBOV_Pos                3                                                          /* ICACHE ICFBCTRL: ARBOV Positions */
#define ICACHE_ICFBCTRL_ARBOV_Msk                (0x1UL  << ICACHE_ICFBCTRL_ARBOV_Pos)                 /* ICACHE ICFBCTRL: ARBOV Mask */

#define ICACHE_ICFBCTRL_ARBS_Pos                2                                                          /* ICACHE ICFBCTRL: ARBS Positions */
#define ICACHE_ICFBCTRL_ARBS_Msk                (0x1UL  << ICACHE_ICFBCTRL_ARBS_Pos)                 /* ICACHE ICFBCTRL: ARBS Mask */

#define ICACHE_ICFBCTRL_SEC_Pos                1                                                          /* ICACHE ICFBCTRL: SEC Positions */
#define ICACHE_ICFBCTRL_SEC_Msk                (0x1UL  << ICACHE_ICFBCTRL_SEC_Pos)                 /* ICACHE ICFBCTRL: SEC Mask */

#define ICACHE_ICFBCTRL_SF_Pos                0                                                          /* ICACHE ICFBCTRL: SF Positions */
#define ICACHE_ICFBCTRL_SF_Msk                (0x1UL  /*<< ICACHE_ICFBCTRL_SF_Pos*/)                 /* ICACHE ICFBCTRL: SF Mask */

/* ICACHE ICSH Register Definitions */
#define ICACHE_ICSH_CSH_Pos                   0                                                          /* ICACHE ICSH: CSH Positions */
#define ICACHE_ICSH_CSH_Msk                   (0xFFFFFFFFUL  /*<< ICACHE_ICSH_CSH_Pos*/)                 /* ICACHE ICSH: CSH Mask */

/* ICACHE ICSM Register Definitions */
#define ICACHE_ICSM_CSM_Pos                0                                                          /* ICACHE ICSM: CSM Positions */
#define ICACHE_ICSM_CSM_Msk                (0xFFFFFFFFUL  /*<< ICACHE_ICSM_CSM_Pos*/)                 /* ICACHE ICSM: CSM Mask */

/* ICACHE CSUC Register Definitions */
#define ICACHE_CSUC_CSUC_Pos                0                                                          /* ICACHE CSUC: CSUC Positions */
#define ICACHE_CSUC_CSUC_Msk                (0xFFFFFFFFUL  /*<< ICACHE_CSUC_CSUC_Pos*/)                 /* ICACHE CSUC: CSUC Mask */

/* ICACHE PIDR4 Register Definitions */
#define ICACHE_PIDR4_SIZE_Pos                4                                                          /* ICACHE PIDR4: SIZE Positions */
#define ICACHE_PIDR4_SIZE_Msk                (0xFUL  << ICACHE_PIDR4_SIZE_Pos)                 /* ICACHE PIDR4: SIZE Mask */

#define ICACHE_PIDR4_DES_2_Pos                0                                                          /* ICACHE PIDR4: DES_2 Positions */
#define ICACHE_PIDR4_DES_2_Msk                (0xFUL  /*<< ICACHE_PIDR4_DES_2_Pos*/)                 /* ICACHE PIDR4: DES_2 Mask */

/* ICACHE PIDR0 Register Definitions */
#define ICACHE_PIDR0_PART_0_Pos                0                                                          /* ICACHE PIDR0: PART_0 Positions */
#define ICACHE_PIDR0_PART_0_Msk                (0xFFUL  /*<< ICACHE_PIDR0_PART_0_Pos*/)                 /* ICACHE PIDR0: PART_0 Mask */

/* ICACHE PIDR1 Register Definitions */
#define ICACHE_PIDR1_DES_0_Pos                4                                                          /* ICACHE PIDR1: DES_0 Positions */
#define ICACHE_PIDR1_DES_0_Msk                (0xFUL  << ICACHE_PIDR1_DES_0_Pos)                 /* ICACHE PIDR1: DES_0 Mask */

#define ICACHE_PIDR1_PART_1_Pos                0                                                          /* ICACHE PIDR1: PART_1 Positions */
#define ICACHE_PIDR1_PART_1_Msk                (0xFUL  /*<< ICACHE_PIDR1_PART_1_Pos*/)                 /* ICACHE PIDR1: PART_1 Mask */

/* ICACHE PIDR2 Register Definitions */
#define ICACHE_PIDR2_REVISION_Pos                4                                                          /* ICACHE PIDR2: REVISION Positions */
#define ICACHE_PIDR2_REVISION_Msk                (0xFUL  << ICACHE_PIDR2_REVISION_Pos)                 /* ICACHE PIDR2: REVISION Mask */

#define ICACHE_PIDR2_JEDEC_Pos                3                                                          /* ICACHE PIDR2: JEDEC Positions */
#define ICACHE_PIDR2_JEDEC_Msk                (0x1UL  << ICACHE_PIDR2_JEDEC_Pos)                 /* ICACHE PIDR2: JEDEC Mask */

#define ICACHE_PIDR2_DES_1_Pos                0                                                          /* ICACHE PIDR2: DES_1 Positions */
#define ICACHE_PIDR2_DES_1_Msk                (0x7UL  /*<< ICACHE_PIDR2_DES_1_Pos*/)                 /* ICACHE PIDR2: DES_1 Mask */

/* ICACHE PIDR3 Register Definitions */
#define ICACHE_PIDR3_REVAND_Pos                4                                                          /* ICACHE PIDR3: REVAND Positions */
#define ICACHE_PIDR3_REVAND_Msk                (0xFUL  << ICACHE_PIDR3_REVAND_Pos)                 /* ICACHE PIDR3: REVAND Mask */

#define ICACHE_PIDR3_CMOD_Pos                0                                                          /* ICACHE PIDR3: CMOD Positions */
#define ICACHE_PIDR3_CMOD_Msk                (0xFUL  /*<< ICACHE_PIDR3_CMOD_Pos*/)                 /* ICACHE PIDR3: CMOD Mask */

/* ICACHE CIDR0 Register Definitions */
#define ICACHE_CIDR0_PRMBL_0_Pos                0                                                          /* ICACHE CIDR0: PRMBL_0 Positions */
#define ICACHE_CIDR0_PRMBL_0_Msk                (0xFFUL  /*<< ICACHE_CIDR0_PRMBL_0_Pos*/)                 /* ICACHE CIDR0: PRMBL_0 Mask */

/* ICACHE CIDR1 Register Definitions */
#define ICACHE_CIDR1_CLASS_Pos                4                                                          /* ICACHE CIDR1: CLASS Positions */
#define ICACHE_CIDR1_CLASS_Msk                (0xFUL  << ICACHE_CIDR1_CLASS_Pos)                 /* ICACHE CIDR1: CLASS Mask */

#define ICACHE_CIDR1_PRMBL_1_Pos                0                                                          /* ICACHE CIDR1: PRMBL_1 Positions */
#define ICACHE_CIDR1_PRMBL_1_Msk                (0xFUL  /*<< ICACHE_CIDR1_PRMBL_1_Pos*/)                 /* ICACHE CIDR1: PRMBL_1 Mask */

/* ICACHE CIDR2 Register Definitions */
#define ICACHE_CIDR2_PRMBL_2_Pos                0                                                          /* ICACHE CIDR2: PRMBL_2 Positions */
#define ICACHE_CIDR2_PRMBL_2_Msk                (0xFFUL  /*<< ICACHE_CIDR2_PRMBL_2_Pos*/)                 /* ICACHE CIDR2: PRMBL_2 Mask */

/* ICACHE CIDR3 Register Definitions */
#define ICACHE_CIDR3_PRMBL_3_Pos                0                                                          /* ICACHE CIDR3: PRMBL_3 Positions */
#define ICACHE_CIDR3_PRMBL_3_Msk                (0xFFUL  /*<< ICACHE_CIDR3_PRMBL_3_Pos*/)                 /* ICACHE CIDR3: PRMBL_3 Mask */

#ifdef __cplusplus
}
#endif

#endif  /* ARMv8MBL_H */
