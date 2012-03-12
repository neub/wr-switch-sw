/*
  Register definitions for slave core: Routing Table Unit (RTU)

  * File           : rtu_regs.h
  * Author         : auto-generated by wbgen2 from rtu_wishbone_slave.wb
  * Created        : Fri Mar  9 16:11:34 2012
  * Standard       : ANSI C

    THIS FILE WAS GENERATED BY wbgen2 FROM SOURCE FILE rtu_wishbone_slave.wb
    DO NOT HAND-EDIT UNLESS IT'S ABSOLUTELY NECESSARY!

*/

#ifndef __WBGEN2_REGDEFS_RTU_WISHBONE_SLAVE_WB
#define __WBGEN2_REGDEFS_RTU_WISHBONE_SLAVE_WB

#include <inttypes.h>

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


/* definitions for register: RTU Global Control Register */

/* definitions for field: RTU Global Enable in reg: RTU Global Control Register */
#define RTU_GCR_G_ENA                         WBGEN2_GEN_MASK(0, 1)

/* definitions for field: MFIFO Trigger in reg: RTU Global Control Register */
#define RTU_GCR_MFIFOTRIG                     WBGEN2_GEN_MASK(1, 1)

/* definitions for field: Hash Poly in reg: RTU Global Control Register */
#define RTU_GCR_POLY_VAL_MASK                 WBGEN2_GEN_MASK(8, 16)
#define RTU_GCR_POLY_VAL_SHIFT                8
#define RTU_GCR_POLY_VAL_W(value)             WBGEN2_GEN_WRITE(value, 8, 16)
#define RTU_GCR_POLY_VAL_R(reg)               WBGEN2_GEN_READ(reg, 8, 16)

/* definitions for register: Port Select Register */

/* definitions for field: Port Select in reg: Port Select Register */
#define RTU_PSR_PORT_SEL_MASK                 WBGEN2_GEN_MASK(0, 8)
#define RTU_PSR_PORT_SEL_SHIFT                0
#define RTU_PSR_PORT_SEL_W(value)             WBGEN2_GEN_WRITE(value, 0, 8)
#define RTU_PSR_PORT_SEL_R(reg)               WBGEN2_GEN_READ(reg, 0, 8)

/* definitions for field: Number of ports in reg: Port Select Register */
#define RTU_PSR_N_PORTS_MASK                  WBGEN2_GEN_MASK(8, 8)
#define RTU_PSR_N_PORTS_SHIFT                 8
#define RTU_PSR_N_PORTS_W(value)              WBGEN2_GEN_WRITE(value, 8, 8)
#define RTU_PSR_N_PORTS_R(reg)                WBGEN2_GEN_READ(reg, 8, 8)

/* definitions for register: Port Control Register */

/* definitions for field: Learning enable in reg: Port Control Register */
#define RTU_PCR_LEARN_EN                      WBGEN2_GEN_MASK(0, 1)

/* definitions for field: Pass all packets in reg: Port Control Register */
#define RTU_PCR_PASS_ALL                      WBGEN2_GEN_MASK(1, 1)

/* definitions for field: Pass BPDUs in reg: Port Control Register */
#define RTU_PCR_PASS_BPDU                     WBGEN2_GEN_MASK(2, 1)

/* definitions for field: Fix priority in reg: Port Control Register */
#define RTU_PCR_FIX_PRIO                      WBGEN2_GEN_MASK(3, 1)

/* definitions for field: Priority value in reg: Port Control Register */
#define RTU_PCR_PRIO_VAL_MASK                 WBGEN2_GEN_MASK(4, 3)
#define RTU_PCR_PRIO_VAL_SHIFT                4
#define RTU_PCR_PRIO_VAL_W(value)             WBGEN2_GEN_WRITE(value, 4, 3)
#define RTU_PCR_PRIO_VAL_R(reg)               WBGEN2_GEN_READ(reg, 4, 3)

/* definitions for field: Unrecognized request behaviour in reg: Port Control Register */
#define RTU_PCR_B_UNREC                       WBGEN2_GEN_MASK(7, 1)

/* definitions for register: Interrupt disable register */

/* definitions for field: UFIFO Not Empty IRQ in reg: Interrupt disable register */
#define RTU_EIC_IDR_NEMPTY                    WBGEN2_GEN_MASK(0, 1)

/* definitions for register: Interrupt enable register */

/* definitions for field: UFIFO Not Empty IRQ in reg: Interrupt enable register */
#define RTU_EIC_IER_NEMPTY                    WBGEN2_GEN_MASK(0, 1)

/* definitions for register: Interrupt mask register */

/* definitions for field: UFIFO Not Empty IRQ in reg: Interrupt mask register */
#define RTU_EIC_IMR_NEMPTY                    WBGEN2_GEN_MASK(0, 1)

/* definitions for register: Interrupt status register */

/* definitions for field: UFIFO Not Empty IRQ in reg: Interrupt status register */
#define RTU_EIC_ISR_NEMPTY                    WBGEN2_GEN_MASK(0, 1)

/* definitions for register: FIFO 'Unrecognized request FIFO (UFIFO)' data output register 0 */

/* definitions for field: Destination MAC address least-significant part in reg: FIFO 'Unrecognized request FIFO (UFIFO)' data output register 0 */
#define RTU_UFIFO_R0_DMAC_LO_MASK             WBGEN2_GEN_MASK(0, 32)
#define RTU_UFIFO_R0_DMAC_LO_SHIFT            0
#define RTU_UFIFO_R0_DMAC_LO_W(value)         WBGEN2_GEN_WRITE(value, 0, 32)
#define RTU_UFIFO_R0_DMAC_LO_R(reg)           WBGEN2_GEN_READ(reg, 0, 32)

/* definitions for register: FIFO 'Unrecognized request FIFO (UFIFO)' data output register 1 */

/* definitions for field: Destination MAC address most-significant part in reg: FIFO 'Unrecognized request FIFO (UFIFO)' data output register 1 */
#define RTU_UFIFO_R1_DMAC_HI_MASK             WBGEN2_GEN_MASK(0, 16)
#define RTU_UFIFO_R1_DMAC_HI_SHIFT            0
#define RTU_UFIFO_R1_DMAC_HI_W(value)         WBGEN2_GEN_WRITE(value, 0, 16)
#define RTU_UFIFO_R1_DMAC_HI_R(reg)           WBGEN2_GEN_READ(reg, 0, 16)

/* definitions for register: FIFO 'Unrecognized request FIFO (UFIFO)' data output register 2 */

/* definitions for field: Source MAC address least-significant part in reg: FIFO 'Unrecognized request FIFO (UFIFO)' data output register 2 */
#define RTU_UFIFO_R2_SMAC_LO_MASK             WBGEN2_GEN_MASK(0, 32)
#define RTU_UFIFO_R2_SMAC_LO_SHIFT            0
#define RTU_UFIFO_R2_SMAC_LO_W(value)         WBGEN2_GEN_WRITE(value, 0, 32)
#define RTU_UFIFO_R2_SMAC_LO_R(reg)           WBGEN2_GEN_READ(reg, 0, 32)

/* definitions for register: FIFO 'Unrecognized request FIFO (UFIFO)' data output register 3 */

/* definitions for field: Source MAC address most-significant part in reg: FIFO 'Unrecognized request FIFO (UFIFO)' data output register 3 */
#define RTU_UFIFO_R3_SMAC_HI_MASK             WBGEN2_GEN_MASK(0, 16)
#define RTU_UFIFO_R3_SMAC_HI_SHIFT            0
#define RTU_UFIFO_R3_SMAC_HI_W(value)         WBGEN2_GEN_WRITE(value, 0, 16)
#define RTU_UFIFO_R3_SMAC_HI_R(reg)           WBGEN2_GEN_READ(reg, 0, 16)

/* definitions for register: FIFO 'Unrecognized request FIFO (UFIFO)' data output register 4 */

/* definitions for field: VLAN Identifier in reg: FIFO 'Unrecognized request FIFO (UFIFO)' data output register 4 */
#define RTU_UFIFO_R4_VID_MASK                 WBGEN2_GEN_MASK(0, 12)
#define RTU_UFIFO_R4_VID_SHIFT                0
#define RTU_UFIFO_R4_VID_W(value)             WBGEN2_GEN_WRITE(value, 0, 12)
#define RTU_UFIFO_R4_VID_R(reg)               WBGEN2_GEN_READ(reg, 0, 12)

/* definitions for field: Priority in reg: FIFO 'Unrecognized request FIFO (UFIFO)' data output register 4 */
#define RTU_UFIFO_R4_PRIO_MASK                WBGEN2_GEN_MASK(12, 3)
#define RTU_UFIFO_R4_PRIO_SHIFT               12
#define RTU_UFIFO_R4_PRIO_W(value)            WBGEN2_GEN_WRITE(value, 12, 3)
#define RTU_UFIFO_R4_PRIO_R(reg)              WBGEN2_GEN_READ(reg, 12, 3)

/* definitions for field: Port ID in reg: FIFO 'Unrecognized request FIFO (UFIFO)' data output register 4 */
#define RTU_UFIFO_R4_PID_MASK                 WBGEN2_GEN_MASK(16, 4)
#define RTU_UFIFO_R4_PID_SHIFT                16
#define RTU_UFIFO_R4_PID_W(value)             WBGEN2_GEN_WRITE(value, 16, 4)
#define RTU_UFIFO_R4_PID_R(reg)               WBGEN2_GEN_READ(reg, 16, 4)

/* definitions for field: VID valid in reg: FIFO 'Unrecognized request FIFO (UFIFO)' data output register 4 */
#define RTU_UFIFO_R4_HAS_VID                  WBGEN2_GEN_MASK(20, 1)

/* definitions for field: PRIO valid in reg: FIFO 'Unrecognized request FIFO (UFIFO)' data output register 4 */
#define RTU_UFIFO_R4_HAS_PRIO                 WBGEN2_GEN_MASK(21, 1)

/* definitions for register: FIFO 'Unrecognized request FIFO (UFIFO)' control/status register */

/* definitions for field: FIFO empty flag in reg: FIFO 'Unrecognized request FIFO (UFIFO)' control/status register */
#define RTU_UFIFO_CSR_EMPTY                   WBGEN2_GEN_MASK(17, 1)

/* definitions for field: FIFO counter in reg: FIFO 'Unrecognized request FIFO (UFIFO)' control/status register */
#define RTU_UFIFO_CSR_USEDW_MASK              WBGEN2_GEN_MASK(0, 7)
#define RTU_UFIFO_CSR_USEDW_SHIFT             0
#define RTU_UFIFO_CSR_USEDW_W(value)          WBGEN2_GEN_WRITE(value, 0, 7)
#define RTU_UFIFO_CSR_USEDW_R(reg)            WBGEN2_GEN_READ(reg, 0, 7)

/* definitions for register: FIFO 'Main hashtable CPU access FIFO (MFIFO)' data input register 0 */

/* definitions for field: Address/data select in reg: FIFO 'Main hashtable CPU access FIFO (MFIFO)' data input register 0 */
#define RTU_MFIFO_R0_AD_SEL                   WBGEN2_GEN_MASK(0, 1)

/* definitions for register: FIFO 'Main hashtable CPU access FIFO (MFIFO)' data input register 1 */

/* definitions for field: Address/data value in reg: FIFO 'Main hashtable CPU access FIFO (MFIFO)' data input register 1 */
#define RTU_MFIFO_R1_AD_VAL_MASK              WBGEN2_GEN_MASK(0, 32)
#define RTU_MFIFO_R1_AD_VAL_SHIFT             0
#define RTU_MFIFO_R1_AD_VAL_W(value)          WBGEN2_GEN_WRITE(value, 0, 32)
#define RTU_MFIFO_R1_AD_VAL_R(reg)            WBGEN2_GEN_READ(reg, 0, 32)

/* definitions for register: FIFO 'Main hashtable CPU access FIFO (MFIFO)' control/status register */

/* definitions for field: FIFO full flag in reg: FIFO 'Main hashtable CPU access FIFO (MFIFO)' control/status register */
#define RTU_MFIFO_CSR_FULL                    WBGEN2_GEN_MASK(16, 1)

/* definitions for field: FIFO empty flag in reg: FIFO 'Main hashtable CPU access FIFO (MFIFO)' control/status register */
#define RTU_MFIFO_CSR_EMPTY                   WBGEN2_GEN_MASK(17, 1)

/* definitions for field: FIFO counter in reg: FIFO 'Main hashtable CPU access FIFO (MFIFO)' control/status register */
#define RTU_MFIFO_CSR_USEDW_MASK              WBGEN2_GEN_MASK(0, 6)
#define RTU_MFIFO_CSR_USEDW_SHIFT             0
#define RTU_MFIFO_CSR_USEDW_W(value)          WBGEN2_GEN_WRITE(value, 0, 6)
#define RTU_MFIFO_CSR_USEDW_R(reg)            WBGEN2_GEN_READ(reg, 0, 6)
/* definitions for RAM: Aging bitmap for main hashtable */
#define RTU_ARAM_BASE 0x00004000 /* base address */                                
#define RTU_ARAM_BYTES 0x00000400 /* size in bytes */                               
#define RTU_ARAM_WORDS 0x00000100 /* size in 32-bit words, 32-bit aligned */        
/* definitions for RAM: VLAN table (VLAN_TAB) */
#define RTU_VLAN_TAB_BASE 0x00008000 /* base address */                                
#define RTU_VLAN_TAB_BYTES 0x00004000 /* size in bytes */                               
#define RTU_VLAN_TAB_WORDS 0x00001000 /* size in 32-bit words, 32-bit aligned */        
/* [0x0]: REG RTU Global Control Register */
#define RTU_REG_GCR 0x00000000
/* [0x4]: REG Port Select Register */
#define RTU_REG_PSR 0x00000004
/* [0x8]: REG Port Control Register */
#define RTU_REG_PCR 0x00000008
/* [0x20]: REG Interrupt disable register */
#define RTU_REG_EIC_IDR 0x00000020
/* [0x24]: REG Interrupt enable register */
#define RTU_REG_EIC_IER 0x00000024
/* [0x28]: REG Interrupt mask register */
#define RTU_REG_EIC_IMR 0x00000028
/* [0x2c]: REG Interrupt status register */
#define RTU_REG_EIC_ISR 0x0000002c
/* [0x30]: REG FIFO 'Unrecognized request FIFO (UFIFO)' data output register 0 */
#define RTU_REG_UFIFO_R0 0x00000030
/* [0x34]: REG FIFO 'Unrecognized request FIFO (UFIFO)' data output register 1 */
#define RTU_REG_UFIFO_R1 0x00000034
/* [0x38]: REG FIFO 'Unrecognized request FIFO (UFIFO)' data output register 2 */
#define RTU_REG_UFIFO_R2 0x00000038
/* [0x3c]: REG FIFO 'Unrecognized request FIFO (UFIFO)' data output register 3 */
#define RTU_REG_UFIFO_R3 0x0000003c
/* [0x40]: REG FIFO 'Unrecognized request FIFO (UFIFO)' data output register 4 */
#define RTU_REG_UFIFO_R4 0x00000040
/* [0x44]: REG FIFO 'Unrecognized request FIFO (UFIFO)' control/status register */
#define RTU_REG_UFIFO_CSR 0x00000044
/* [0x48]: REG FIFO 'Main hashtable CPU access FIFO (MFIFO)' data input register 0 */
#define RTU_REG_MFIFO_R0 0x00000048
/* [0x4c]: REG FIFO 'Main hashtable CPU access FIFO (MFIFO)' data input register 1 */
#define RTU_REG_MFIFO_R1 0x0000004c
/* [0x50]: REG FIFO 'Main hashtable CPU access FIFO (MFIFO)' control/status register */
#define RTU_REG_MFIFO_CSR 0x00000050
#endif