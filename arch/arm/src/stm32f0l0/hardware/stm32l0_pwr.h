/************************************************************************************
 * arch/arm/src/stm32/chip/stm32l0_pwr.h
 *
 *   Copyright (C) 2018 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ************************************************************************************/

#ifndef __ARCH_ARM_SRC_STM32F0L0_HARDWARE_STM32L0_PWR_H
#define __ARCH_ARM_SRC_STM32F0L0_HARDWARE_STM32L0_PWR_H

/************************************************************************************
 * Included Files
 ************************************************************************************/

#include <nuttx/config.h>
#include "chip.h"

/************************************************************************************
 * Pre-processor Definitions
 ************************************************************************************/

#define HAVE_PWR_WKUP2         1
#define HAVE_PWR_WKUP3         1

/* Register Offsets *****************************************************************/

#define STM32_PWR_CR_OFFSET    0x0000  /* Power control register */
#define STM32_PWR_CSR_OFFSET   0x0004  /* Power control/status register */

/* Register Addresses ***************************************************************/

#define STM32_PWR_CR           (STM32_PWR_BASE+STM32_PWR_CR_OFFSET)
#define STM32_PWR_CSR          (STM32_PWR_BASE+STM32_PWR_CSR_OFFSET)

/* Register Bitfield Definitions ****************************************************/

/* Power control register */

#define PWR_CR_LPDS            (1 << 0)  /* Bit 0:  Low-Power Deepsleep/sleep; low power run */
#define PWR_CR_PDDS            (1 << 1)  /* Bit 1:  Power Down Deepsleep */
#define PWR_CR_CWUF            (1 << 2)  /* Bit 2:  Clear Wakeup Flag */
#define PWR_CR_CSBF            (1 << 3)  /* Bit 3:  Clear Standby Flag */
#define PWR_CR_PVDE            (1 << 4)  /* Bit 4:  Power Voltage Detector Enable */

#define PWR_CR_PLS_SHIFT       (5)       /* Bits 7-5: PVD Level Selection */
#define PWR_CR_PLS_MASK        (7 << PWR_CR_PLS_SHIFT)
#  define PWR_CR_2p2V          (0 << PWR_CR_PLS_SHIFT) /* 000: 2.2V */
#  define PWR_CR_2p3V          (1 << PWR_CR_PLS_SHIFT) /* 001: 2.3V */
#  define PWR_CR_2p4V          (2 << PWR_CR_PLS_SHIFT) /* 010: 2.4V */
#  define PWR_CR_2p5V          (3 << PWR_CR_PLS_SHIFT) /* 011: 2.5V */
#  define PWR_CR_2p6V          (4 << PWR_CR_PLS_SHIFT) /* 100: 2.6V */
#  define PWR_CR_2p7V          (5 << PWR_CR_PLS_SHIFT) /* 101: 2.7V */
#  define PWR_CR_2p8V          (6 << PWR_CR_PLS_SHIFT) /* 110: 2.8V */
#  define PWR_CR_2p9V          (7 << PWR_CR_PLS_SHIFT) /* 111: 2.9V */
#define PWR_CR_DBP             (1 << 8)  /* Bit 8:  Disable Backup Domain write protection */
#define PWR_CR_ULP             (1 << 9)  /* Bit 9:  Ultralow power mode */
#define PWR_CR_FWU             (1 << 10) /* Bit 10: Fast wake-up */
#define PWR_CR_VOS_MASK        (3 << 11) /* Bits 11-12: Regulator voltage scaling output selection */
#  define PWR_CR_VOS_SCALE_1   (1 << 11) /* 1.8 V (range 1) PLL VCO Max = 96MHz */
#  define PWR_CR_VOS_SCALE_2   (2 << 11) /* 1.5 V (range 2) PLL VCO Max = 64MHz */
#  define PWR_CR_VOS_SCALE_3   (3 << 11) /* 1.2 V (range 3) PLL VCO Max = 24MHz */
#define PWR_CR_DSEEKOFF        (1 << 13) /* Bit 13: Deepsleep mode with non-volatile memory kept off */
#define PWR_CR_LPRUN           (1 << 14) /* Bit 14: Low power run mode */

/* Power control/status register */

#define PWR_CSR_WUF            (1 << 0)  /* Bit 0:  Wakeup Flag */
#define PWR_CSR_SBF            (1 << 1)  /* Bit 1:  Standby Flag */
#define PWR_CSR_PVDO           (1 << 2)  /* Bit 2:  PVD Output */
#define PWR_CSR_VREFINTRDYF    (1 << 3)  /* Bit 3:  Internal voltage reference (VREFINT) ready flag */
#define PWR_CSR_VOSF           (1 << 4)  /* Bit 4:  Voltage Scaling select flag */
#define PWR_CSR_REGLPF         (1 << 5)  /* Bit 5:  Regulator LP flag */
#define PWR_CSR_EWUP1          (1 << 8)  /* Bit 8:  Enable WKUP1 pin */
#define PWR_CSR_EWUP2          (1 << 9)  /* Bit 9:  Enable WKUP2 pin */
#define PWR_CSR_EWUP3          (1 << 10) /* Bit 10: Enable WKUP3 pin */

#endif /* __ARCH_ARM_SRC_STM32F0L0_HARDWARE_STM32L0_PWR_H */
