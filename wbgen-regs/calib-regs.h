/*
  Register definitions for slave core: DMTD PHY Calibrator

  * File           : calib-regs.h
  * Author         : auto-generated by wbgen2 from wrsw_calibrator_dmtd.wb
  * Created        : Tue Nov 23 13:47:20 2010
  * Standard       : ANSI C

    THIS FILE WAS GENERATED BY wbgen2 FROM SOURCE FILE wrsw_calibrator_dmtd.wb
    DO NOT HAND-EDIT UNLESS IT'S ABSOLUTELY NECESSARY!

*/

#ifndef __WBGEN2_REGDEFS_WRSW_CALIBRATOR_DMTD_WB
#define __WBGEN2_REGDEFS_WRSW_CALIBRATOR_DMTD_WB

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


/* definitions for register: Control Register */

/* definitions for field: Enable in reg: Control Register */
#define DPC_CR_EN                             WBGEN2_GEN_MASK(0, 1)

/* definitions for field: Compare clock select in reg: Control Register */
#define DPC_CR_IN_SEL_MASK                    WBGEN2_GEN_MASK(8, 4)
#define DPC_CR_IN_SEL_SHIFT                   8
#define DPC_CR_IN_SEL_W(value)                WBGEN2_GEN_WRITE(value, 8, 4)
#define DPC_CR_IN_SEL_R(reg)                  WBGEN2_GEN_READ(reg, 8, 4)

/* definitions for field: DMTD averaging samples in reg: Control Register */
#define DPC_CR_N_AVG_MASK                     WBGEN2_GEN_MASK(16, 12)
#define DPC_CR_N_AVG_SHIFT                    16
#define DPC_CR_N_AVG_W(value)                 WBGEN2_GEN_WRITE(value, 16, 12)
#define DPC_CR_N_AVG_R(reg)                   WBGEN2_GEN_READ(reg, 16, 12)

/* definitions for register: Status register */

/* definitions for field: Phase shift value in reg: Status register */
#define DPC_SR_PS_VAL_MASK                    WBGEN2_GEN_MASK(0, 24)
#define DPC_SR_PS_VAL_SHIFT                   0
#define DPC_SR_PS_VAL_W(value)                WBGEN2_GEN_WRITE(value, 0, 24)
#define DPC_SR_PS_VAL_R(reg)                  WBGEN2_GEN_READ(reg, 0, 24)

/* definitions for field: Phase shift value ready in reg: Status register */
#define DPC_SR_PS_RDY                         WBGEN2_GEN_MASK(24, 1)

PACKED struct DPC_WB {
  /* [0x0]: REG Control Register */
  uint32_t CR;
  /* [0x4]: REG Status register */
  uint32_t SR;
};

#endif