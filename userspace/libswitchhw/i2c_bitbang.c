/*
 * i2c_bitbang.c
 */

#include <stdlib.h>
#include <string.h>
#include <hw/util.h> //for shw_udelay();

#include "i2c_bitbang.h"

#include <sys/time.h>
#include <unistd.h>


 
 
int i2c_bitbang_init_bus(struct i2c_bus *bus)
{
	struct i2c_bitbang *priv;

	if (!bus && !bus->type_specific && bus->type != I2C_TYPE_BITBANG)
		return -1;

	priv = (struct i2c_bitbang *)bus->type_specific;

	shw_pio_configure(priv->scl);
	shw_pio_configure(priv->sda);
	shw_pio_setdir(priv->scl, 0);
	shw_pio_setdir(priv->sda, 0);
	priv->udelay = 50;
	priv->timeout = 100;
	
	//assign functions
	bus->transfer = i2c_bitbang_transfer;
	bus->scan = i2c_bitbang_scan;

	return 0;
}

#define I2C_DELAY 100

void mi2c_pin_out(pio_pin_t* pin, int state)
{
       shw_pio_setdir(pin, state ? 0 : 1);
       shw_udelay(I2C_DELAY);
}

static void mi2c_start(struct i2c_bitbang* bus)
{
       mi2c_pin_out(bus->sda, 0);
       mi2c_pin_out(bus->scl, 0);
}

static void mi2c_restart(struct i2c_bitbang* bus)
{
       mi2c_pin_out(bus->sda, 1);
       mi2c_pin_out(bus->scl, 1);
       mi2c_pin_out(bus->sda, 0);
       mi2c_pin_out(bus->scl, 0);
}


static void mi2c_stop(struct i2c_bitbang* bus)
{
        mi2c_pin_out(bus->sda,0);
        mi2c_pin_out(bus->scl,1);
        mi2c_pin_out(bus->sda,1);
}


static int mi2c_write_byte(struct i2c_bitbang* bus, uint8_t data)
{
       int ack = 0;
       int b;
        
       for (b = 0; b < 8; b++)
       {
       	mi2c_pin_out(bus->sda, data & 0x80);	//set MSB to SDA
       	mi2c_pin_out(bus->scl, 1);			//toggle clock
       	mi2c_pin_out(bus->scl, 0);
       	data <<= 1;
       }
        
       mi2c_pin_out(bus->sda, 1);	//go high
       mi2c_pin_out(bus->scl, 1);	//toggle clock
        
       shw_pio_setdir(bus->sda, PIO_IN);		//let SDA float
       shw_udelay(I2C_DELAY);
       ack = shw_pio_get(bus->sda);
        
       mi2c_pin_out(bus->scl, 0);
    //   shw_pio_setdir(bus->sda, PIO_OUT_1);	//turn on output
       shw_udelay(I2C_DELAY);
        
       return (ack == 0) ? 1: 0;
}



static uint8_t mi2c_get_byte(struct i2c_bitbang *bus, int ack)
{
	int i;
	unsigned char result = 0;

	mi2c_pin_out(bus->scl, 0);
	shw_pio_setdir(bus->sda, PIO_IN);		//let SDA float so we can read it
	
	for (i=0;i<8;i++)
	{
		mi2c_pin_out(bus->scl, 1);
		result <<= 1;
		if (shw_pio_get(bus->sda))
			result |= 0x01;
		mi2c_pin_out(bus->scl, 0);
	}

	//send ACK or NAK
	mi2c_pin_out(bus->sda, ack ? 0 : 1);	
	shw_udelay(I2C_DELAY);
			
	mi2c_pin_out(bus->scl, 1);		//generate SCL pulse for slave to read ACK/NACK
	mi2c_pin_out(bus->scl, 0);
	
	return result;

}

int32_t i2c_bitbang_scan(struct i2c_bus* bus, uint32_t address)
{
	if (!bus)
		return I2C_NULL_PARAM;

	struct i2c_bitbang* ts = (struct i2c_bitbang*)bus->type_specific;

	mi2c_start(ts);
	int   ack = mi2c_write_byte(ts, (address << 1) | 0);

	mi2c_stop(ts);

	return ack ? 1: 0;
}
 
int	i2c_bitbang_transfer(i2c_bus_t* bus, uint32_t address, uint32_t to_write, uint32_t to_read, uint8_t* data)
{
	if (!bus)
		return I2C_NULL_PARAM;
	
	if (bus->type != I2C_TYPE_BITBANG)
		return I2C_BUS_MISMATCH;
	
	struct i2c_bitbang* ts = (struct i2c_bitbang*)bus->type_specific;
	
	int sent = 0;
	int rcvd = 0;
	int ack = 0;
	
	uint32_t i;
	
	if (to_write > 0)
	{
		mi2c_start(ts);
		ack = mi2c_write_byte(ts, address << 1);		//add W bit at the end of address
		if (!ack)
		{
			mi2c_stop(ts);
			return I2C_DEV_NOT_FOUND;				//the device did not ack it's address
		}		
		for (i=0; i < to_write; i++)
		{
			ack = mi2c_write_byte(ts, data[i]);		//write data
			if (!ack)
			{
				mi2c_stop(ts);
				return I2C_NO_ACK_RCVD;
			}
			sent++;
		}
		mi2c_stop(ts);
	}
	
	if (to_read)
	{
		mi2c_start(ts);
		ack = mi2c_write_byte(ts, (address << 1) | 1);		//add R bit at the end of address
		if (!ack)
		{
			mi2c_stop(ts);
			return I2C_DEV_NOT_FOUND;				//the device did not ack it's address
		}

		uint32_t last_byte = to_read - 1;
		
		for (i=0; i < to_read; i++)
		{
			data[i] = mi2c_get_byte(ts, i != last_byte);		//read data, ack until the last byte
			rcvd++;
		}
		mi2c_stop(ts);
	}
	
	return sent+rcvd;
}

