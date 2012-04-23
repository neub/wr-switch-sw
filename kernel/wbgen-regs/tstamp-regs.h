/*
  Register definitions for slave core: Shared TX Timestamping Unit (TXTSU)

  * File           : tstamp-regs.h
  * Author         : auto-generated by wbgen2 from tstamp-regs.wb
  * Standard       : ANSI C

    THIS FILE WAS GENERATED BY wbgen2 FROM SOURCE FILE tstamp-regs.wb
    DO NOT HAND-EDIT UNLESS IT'S ABSOLUTELY NECESSARY!

*/

#ifndef __WBGEN2_REGDEFS_TSTAMP
#define __WBGEN2_REGDEFS_TSTAMP

#include <linux/types.h>

#if defined( __GNUC__)
#define PACKED __attribute__ ((packed))
#else
#error "Unsupported compiler?"
#endif

#ifndef __WBGEN2_MACROS_DEFINED__
#define __WBGEN2_MACROS_DEFINED__
#define WBGEN2_GEN_MASK(offset, size) (((1<<(size))-1) << (offset))
#define WBGEN2_GEN_WRITE(value, offset, size) (((value) & ((1<<(size))-1)) << (offset))
#define WBGEN2_GEN_READ(reg, offset, size) (((reg) >> (offset)) & ((1<<(size))-1))
#define WBGEN2_SIGN_EXTEND(value, bits) (((value) & (1<<bits) ? ~((1<<(bits))-1): 0 ) | (value))
#endif


/* definitions for register: Interrupt disable register */

/* definitions for field: TXTSU fifo not-empty in reg: Interrupt disable register */
#define TXTSU_EIC_IDR_NEMPTY                  WBGEN2_GEN_MASK(0, 1)

/* definitions for register: Interrupt enable register */

/* definitions for field: TXTSU fifo not-empty in reg: Interrupt enable register */
#define TXTSU_EIC_IER_NEMPTY                  WBGEN2_GEN_MASK(0, 1)

/* definitions for register: Interrupt mask register */

/* definitions for field: TXTSU fifo not-empty in reg: Interrupt mask register */
#define TXTSU_EIC_IMR_NEMPTY                  WBGEN2_GEN_MASK(0, 1)

/* definitions for register: Interrupt status register */

/* definitions for field: TXTSU fifo not-empty in reg: Interrupt status register */
#define TXTSU_EIC_ISR_NEMPTY                  WBGEN2_GEN_MASK(0, 1)

/* definitions for register: FIFO 'Timestamp FIFO' data output register 0 */

/* definitions for field: Rising edge timestamp in reg: FIFO 'Timestamp FIFO' data output register 0 */
#define TXTSU_TSF_R0_VAL_R_MASK               WBGEN2_GEN_MASK(0, 28)
#define TXTSU_TSF_R0_VAL_R_SHIFT              0
#define TXTSU_TSF_R0_VAL_R_W(value)           WBGEN2_GEN_WRITE(value, 0, 28)
#define TXTSU_TSF_R0_VAL_R_R(reg)             WBGEN2_GEN_READ(reg, 0, 28)

/* definitions for field: Falling edge timestamp in reg: FIFO 'Timestamp FIFO' data output register 0 */
#define TXTSU_TSF_R0_VAL_F_MASK               WBGEN2_GEN_MASK(28, 4)
#define TXTSU_TSF_R0_VAL_F_SHIFT              28
#define TXTSU_TSF_R0_VAL_F_W(value)           WBGEN2_GEN_WRITE(value, 28, 4)
#define TXTSU_TSF_R0_VAL_F_R(reg)             WBGEN2_GEN_READ(reg, 28, 4)

/* definitions for register: FIFO 'Timestamp FIFO' data output register 1 */

/* definitions for field: Physical port ID in reg: FIFO 'Timestamp FIFO' data output register 1 */
#define TXTSU_TSF_R1_PID_MASK                 WBGEN2_GEN_MASK(0, 5)
#define TXTSU_TSF_R1_PID_SHIFT                0
#define TXTSU_TSF_R1_PID_W(value)             WBGEN2_GEN_WRITE(value, 0, 5)
#define TXTSU_TSF_R1_PID_R(reg)               WBGEN2_GEN_READ(reg, 0, 5)

/* definitions for field: Frame ID in reg: FIFO 'Timestamp FIFO' data output register 1 */
#define TXTSU_TSF_R1_FID_MASK                 WBGEN2_GEN_MASK(16, 16)
#define TXTSU_TSF_R1_FID_SHIFT                16
#define TXTSU_TSF_R1_FID_W(value)             WBGEN2_GEN_WRITE(value, 16, 16)
#define TXTSU_TSF_R1_FID_R(reg)               WBGEN2_GEN_READ(reg, 16, 16)

/* definitions for register: FIFO 'Timestamp FIFO' data output register 2 */

/* definitions for field: Timestamp (possibly) incorrect in reg: FIFO 'Timestamp FIFO' data output register 2 */
#define TXTSU_TSF_R2_INCORRECT                WBGEN2_GEN_MASK(0, 1)

/* definitions for register: FIFO 'Timestamp FIFO' control/status register */

/* definitions for field: FIFO full flag in reg: FIFO 'Timestamp FIFO' control/status register */
#define TXTSU_TSF_CSR_FULL                    WBGEN2_GEN_MASK(16, 1)

/* definitions for field: FIFO empty flag in reg: FIFO 'Timestamp FIFO' control/status register */
#define TXTSU_TSF_CSR_EMPTY                   WBGEN2_GEN_MASK(17, 1)

/* definitions for field: FIFO counter in reg: FIFO 'Timestamp FIFO' control/status register */
#define TXTSU_TSF_CSR_USEDW_MASK              WBGEN2_GEN_MASK(0, 8)
#define TXTSU_TSF_CSR_USEDW_SHIFT             0
#define TXTSU_TSF_CSR_USEDW_W(value)          WBGEN2_GEN_WRITE(value, 0, 8)
#define TXTSU_TSF_CSR_USEDW_R(reg)            WBGEN2_GEN_READ(reg, 0, 8)

PACKED struct TXTSU_WB {
  /* [0x0]: REG Interrupt disable register */
  uint32_t EIC_IDR;
  /* [0x4]: REG Interrupt enable register */
  uint32_t EIC_IER;
  /* [0x8]: REG Interrupt mask register */
  uint32_t EIC_IMR;
  /* [0xc]: REG Interrupt status register */
  uint32_t EIC_ISR;
  /* [0x10]: REG FIFO 'Timestamp FIFO' data output register 0 */
  uint32_t TSF_R0;
  /* [0x14]: REG FIFO 'Timestamp FIFO' data output register 1 */
  uint32_t TSF_R1;
  /* [0x18]: REG FIFO 'Timestamp FIFO' data output register 2 */
  uint32_t TSF_R2;
  /* [0x1c]: REG FIFO 'Timestamp FIFO' control/status register */
  uint32_t TSF_CSR;
};

#endif
