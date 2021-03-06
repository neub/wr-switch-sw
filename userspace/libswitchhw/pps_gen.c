/* PPS Generator driver */

/* Warning: references to "UTC" in the registers DO NOT MEAN actual UTC time, it's just a plain second counter
	 It doesn't care about leap seconds. */

#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <inttypes.h>
#include <sys/time.h>

#include <fpga_io.h>
#include <regs/ppsg-regs.h>

#include <switch_hw.h>
#include <trace.h>

/* Default width (in 8ns units) of the pulses on the PPS output */
#define PPS_WIDTH 100000

#define ppsg_write(reg, val) \
	_fpga_writel(FPGA_BASE_PPS_GEN + offsetof(struct PPSG_WB, reg), val)

#define ppsg_read(reg) \
	_fpga_readl(FPGA_BASE_PPS_GEN + offsetof(struct PPSG_WB, reg))

int shw_pps_gen_init()
{
	uint32_t cr;

	cr = PPSG_CR_CNT_EN | PPSG_CR_PWIDTH_W(PPS_WIDTH);
  TRACE(TRACE_INFO, "Initializing PPS generator...");

  ppsg_write(CR, cr);

  ppsg_write(ADJ_UTCLO, 0);
  ppsg_write(ADJ_UTCHI, 0);
  ppsg_write(ADJ_NSEC, 0);

  ppsg_write(CR, cr | PPSG_CR_CNT_SET);
  ppsg_write(CR, cr);
  ppsg_write(ESCR, 0x6); /* enable PPS output */
}

/* Adjusts the nanosecond (refclk cycle) counter by atomically adding (how_much) cycles. */
int shw_pps_gen_adjust(int counter, int64_t how_much)
{
  uint32_t cr;

  TRACE(TRACE_INFO, "Adjust: counter = %s [%c%lld]", 
  	counter == PPSG_ADJUST_SEC ? "seconds" : "nanoseconds", how_much<0?'-':'+', abs(how_much));

	if(counter == PPSG_ADJUST_NSEC)
	{
 		ppsg_write(ADJ_UTCLO, 0);
  	ppsg_write(ADJ_UTCHI, 0);
		ppsg_write(ADJ_NSEC, (int32_t) ((int64_t) how_much * 1000LL / (int64_t)REF_CLOCK_PERIOD_PS));
	} else {
 		ppsg_write(ADJ_UTCLO, (uint32_t ) (how_much & 0xffffffffLL));
  	ppsg_write(ADJ_UTCHI, (uint32_t ) (how_much >> 32) & 0xff);
		ppsg_write(ADJ_NSEC, 0);
	}

  ppsg_write(CR, ppsg_read(CR) | PPSG_CR_CNT_ADJ);
	return 0;
}

/* Returns 1 when the adjustment operation is not yet finished */
int shw_pps_gen_busy()
{
	uint32_t cr = ppsg_read(CR);
  return cr & PPSG_CR_CNT_ADJ ? 0 : 1;
}

/* Enables/disables PPS output */
int shw_pps_gen_enable_output(int enable)
{
    uint32_t escr = ppsg_read(ESCR);
    if(enable)
        ppsg_write(ESCR, escr | PPSG_ESCR_PPS_VALID)
    else
        ppsg_write(ESCR, escr & ~PPSG_ESCR_PPS_VALID);

    return 0;
}

void shw_pps_gen_read_time(uint64_t *seconds, uint32_t *nanoseconds)
{
	uint32_t ns_cnt;
	uint64_t sec1, sec2;
	
	do {
		sec1 = (uint64_t)ppsg_read(CNTR_UTCLO) | (uint64_t)ppsg_read(CNTR_UTCHI) << 32;
		ns_cnt = ppsg_read(CNTR_NSEC);
		sec2 = (uint64_t)ppsg_read(CNTR_UTCLO) | (uint64_t)ppsg_read(CNTR_UTCHI) << 32;
	}	while(sec2 != sec1);

	if(seconds) *seconds = sec2;
	if(nanoseconds) *nanoseconds = ns_cnt;
}