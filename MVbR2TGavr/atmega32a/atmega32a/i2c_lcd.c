/*
 * This library drives a 16x2 or 40x4 LCD from a I2C data bus.
 *
 * Created: on 29 September 2013
 * Author: Vassilis Serasidis
 *
 * Home: http://www.serasidis.gr
 * e-mail: avrsite@yahoo.gr, info@serasidis.gr
 *;
 */ 


#include "i2c_lcd.h"

unsigned char backlight = 0;

void lcd_init (unsigned char command)
{
	backlight = command;	//Turn ON or OFF the LCD backlight pin.	
	lcd_sendData(0x30);
	lcd_sendData(0x30);
	lcd_sendData(0x30);
	lcd_sendData(0x20);		//Enable LCD four-bit mode (D7-D4).
	_delay_ms(20);

	lcd_sendCommand(0x28);	//Function Set: 4-bit, 2 Line, 5x7 Dots.
	lcd_sendCommand(0x0c);	//Display on Cursor off.
	lcd_sendCommand(0x06);	//Entry Mode.
	lcd_sendCommand(0x01);	//Clear Display (also clear DDRAM content).
}	

//=================================================================
// Sends Command to LCD. Sends first the most higher 4-bit nibble
// and after that sends the lower 4-bit nibble. 
//=================================================================
void lcd_sendCommand(unsigned char cmd)	
{
	unsigned char data;
	
	i2c_start(PCF8574_ADDR + I2C_WRITE);
	
	data = cmd & 0b11110000;
	data |= (0b00000100 | backlight);
	i2c_write(data);
	_delay_ms(1);
		
	data = (cmd & 0b11110000);
	data |= backlight;
	i2c_write(data);
	_delay_ms(1);
		
	data = ((cmd & 0b00001111)<<4);
	data |= (0b00000100 | backlight);
	i2c_write(data);
	_delay_ms(1);
		
	data = ((cmd & 0b00001111)<<4);
	data |= backlight;
	i2c_write(data);
	_delay_ms(1);
	
	i2c_stop();	
}

//=================================================================
// Sends a byte to PCF8574. That byte includes the Higher 4-bit
// nibble and the control bits (RS, RW and E).
//=================================================================
void lcd_sendData(unsigned char data)
{
	unsigned char tmp;
	
	i2c_start(PCF8574_ADDR + I2C_WRITE);
	
	tmp = (data & 0b11110000);
	tmp |= (0b00000100 | backlight);
	i2c_write(tmp);
	_delay_ms(1);
		
	tmp = (data & 0b11110000);
	tmp |= backlight;
	i2c_write(tmp);
	_delay_ms(1);
	
	i2c_stop();	
}
//=================================================================
// Sends a Character to LCD.
//=================================================================
void lcd_putc(unsigned char ch)	
{
	unsigned char data;
	
	i2c_start(PCF8574_ADDR + I2C_WRITE);
	
	data=((ch&0b11110000)|backlight);
	data|= 1<<LCD_RS;
	data|= 1<<LCD_E;	
	i2c_write(data);	
	
	data &= ~(1<<LCD_E);	
	data &= ~(1<<LCD_RS);
	data |= backlight;
	i2c_write(data);

	data = ((ch&0b00001111)<<4);
	data|= 1<<LCD_RS;
	data|= 1<<LCD_E;	
	data |= backlight;
	i2c_write(data);	
	
	data &=~ (1<<LCD_E);	
	data &=~ (1<<LCD_RS);
	data |= backlight;
	i2c_write(data);
	
	i2c_stop();	
}	
//=================================================================
// Goes the Cursor to x,y position on LCD.
// x=0 is the most left character on the LCD screen.
// y=0 is the upper first line on the LCD screen.
//=================================================================
void lcd_goto_xy(uint8_t x, uint8_t y)
{
	register uint8_t RAMAddr;
	// remap lines into proper order
	switch(y)
	{
	case 0: RAMAddr = LCD_LINE0_RAMADDR+x; break;
	case 1: RAMAddr = LCD_LINE1_RAMADDR+x; break;
	case 2: RAMAddr = LCD_LINE2_RAMADDR+x; break;
	case 3: RAMAddr = LCD_LINE3_RAMADDR+x; break;
	default: RAMAddr = LCD_LINE0_RAMADDR+x;
	}
	// set data address
	lcd_sendCommand(1<<7 | RAMAddr);	
}

//=================================================================
// Displays LCD cursor
//=================================================================
void lcd_puts_at(const char* str, uint8_t x, uint8_t y)
{
	lcd_goto_xy(x, y);
	lcd_puts(str);
}

//=================================================================
// Displays LCD cursor
//=================================================================
void lcd_cursorOn(void) 
{
	lcd_sendCommand(0x0E);
}
//=================================================================
// Displays LCD blinking cursor
//=================================================================
void lcd_cursorOnBlink(void)	
{
	lcd_sendCommand(0x0F);
}	
//=================================================================
// Turns OFF cursor
//=================================================================
void lcd_cursorOFF(void)	
{
	lcd_sendCommand(0x0C);
}
//=================================================================
// Clears LCD
//=================================================================
void lcd_clear(void)				
{
	lcd_sendCommand(1<<LCD_CLR);
}
//=================================================================
// Outputs string to LCD
//=================================================================
void lcd_puts(char* data)	
{
	register uint8_t i;

	// check to make sure we have a good pointer
	if (!data) return;

	// print data
	for(i=0; i<(strlen(data)); i++)
	{
		lcd_putc(data[i]);
	}
}

//=================================================================
// Put a string from flash memory on LCD at x,y position.
//=================================================================	
void lcd_puts_P(const char *FlashLoc)
{
	uint8_t i;
	for(i=0;(uint8_t)pgm_read_byte(&FlashLoc[i]);i++)
		lcd_putc((uint8_t)pgm_read_byte(&FlashLoc[i]));
}