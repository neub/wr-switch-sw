#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

#include <hw/switch_hw.h>
#include <hw/pio.h>

#include <hw/watchdog.h>

static const pio_pin_t PIN_sck[] =  {{PIOB, 14, PIO_MODE_GPIO, PIO_OUT_1}, {0}};
static const pio_pin_t PIN_cs[] =   {{PIOB, 15, PIO_MODE_GPIO, PIO_OUT_1}, {0}};
static const pio_pin_t PIN_sdout[] = {{PIOB, 12, PIO_MODE_GPIO, PIO_OUT_1}, {0}};
static const pio_pin_t PIN_sdin[] = {{PIOB, 13, PIO_MODE_GPIO, PIO_IN}, {0}};

static inline void spi_cs(int val)
{
	shw_pio_set(PIN_cs, val);
}

static inline uint8_t spi_txrx(uint8_t x)
{
	int i;
	uint8_t rval = 0;
	for(i=0;i<8;i++)
	{
		shw_udelay(50);
		shw_pio_set(PIN_sdout, x&0x80 ? 1 :0);
		shw_udelay(50);
		shw_pio_set0(PIN_sck);
		shw_udelay(50);
		rval <<= 1;
		if(shw_pio_get(PIN_sdin)) rval |= 1;
		shw_udelay(50);
		shw_pio_set1(PIN_sck);
		shw_udelay(50);
		x<<=1;
	}

	return rval;
}


static void wd_spi_xfer(uint8_t *buf, int size)
{
	int i;
	spi_cs(0);
	for(i=0;i<size;i++)
		buf[i]=spi_txrx(buf[i]);
	spi_cs(1);
	shw_udelay(50);
}

#define WD_CMD_SET_LED 1
#define WD_CMD_FEEDBACK 2



void shw_mbl_set_leds(int port, int led, int mode)
{
	uint8_t cmd_buf[4];

	cmd_buf[0] = WD_CMD_SET_LED;
	cmd_buf[1] = port;
	cmd_buf[2] = led;
	cmd_buf[3] = mode;

	wd_spi_xfer(cmd_buf, 4);
}


void shw_mbl_cal_feedback(int port, int cmd)
{
	uint8_t cmd_buf[4];

	cmd_buf[0] = WD_CMD_FEEDBACK;
	cmd_buf[1] = port;
	cmd_buf[2] = cmd;
	cmd_buf[3] = 0;

	wd_spi_xfer(cmd_buf, 4);
}

int shw_watchdog_init()
{
	TRACE(TRACE_INFO,"Initializing watchdog SPI link");
 	 shw_pio_configure(PIN_sck);
	 shw_pio_configure(PIN_cs);
	 shw_pio_configure(PIN_sdout);
	 shw_pio_configure(PIN_sdin);
	return 0;
}