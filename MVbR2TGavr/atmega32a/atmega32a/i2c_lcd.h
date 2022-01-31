
/*
 * This library drives a 16x2 or 20x4 LCD from a I2C data bus.
 *
 * Created: on 29 September 2013
 * Author: Vassilis Serasidis
 *
 * Home: http://www.serasidis.gr
 * e-mail: avrsite@yahoo.gr, info@serasidis.gr
 */

#define PCF8574_ADDR 0x4E

#define LCD_LINE0_RAMADDR		0x00
#define LCD_LINE1_RAMADDR		0x40
#define LCD_LINE2_RAMADDR		0x14
#define LCD_LINE3_RAMADDR		0x54
#define LCD_BACKLIGHT_ON        0b00001000
#define LCD_BACKLIGHT_OFF       0
#define LCD_CLR                 0

#define LCD_RS	0 	//Pin RS from LCD is connected to pin D0 of PCF8574 chip.
#define LCD_RW	1 	//Pin RW from LCD is connected to pin D1 of PCF8574 chip.
#define LCD_E	2	
#define LCD_D4	4	
#define LCD_D5	5	
#define LCD_D6	6	
#define LCD_D7	7	

#define LINE_1  0
#define LINE_2  1
#define LINE_3  2
#define LINE_4  3

#include <avr/io.h>
#include <util/delay.h>
#include <avr/pgmspace.h>
#include <string.h>
#include "i2cmaster.h"

void lcd_init (unsigned char command);
void lcd_sendCommand(unsigned char cmd);	//Sends Command to LCD
void lcd_sendData(unsigned char data);
void lcd_putc(unsigned char ch);		//Sends Char to LCD
void lcd_goto_xy(uint8_t x, uint8_t y);
void lcd_puts_at(const char* str, uint8_t x, uint8_t y);
void lcd_cursorOn(void);					//Underline cursor ON
void lcd_cursorOnBlink(void);			//Underline blinking cursor ON
void lcd_cursorOFF(void);				//Cursor OFF
void lcd_clear(void);					//Clears LCD
void lcd_puts(char*);					//Outputs string to LCD
void lcd_puts_P(const char*);		//copies flash string to LCD at x,y