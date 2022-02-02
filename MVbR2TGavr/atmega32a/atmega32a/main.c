/*
  * Interfacing a 16*2 LCD display through I2C
  * Created			: 7/12/2020 3:44:42 PM
  * Author			: Bimalka Piyaruwan Thalagala
  * Github			: https://github.com/bimalka98
  * Last Modified	: 02/02/2022
  
  *************************\Functional Description\***************************
  * In order to use the following code, you need to attach a
  I2C Serial Interface Board Module Port for your 16*2 LCD.
  * Connect PC1(SDA) and PC0(SCL) pins of the ATMEGA32A to the SDA and SCL
  pins of the interface board module respectively.
  * Connect other pins of the interface board module to GND and 5V supply
  accordingly.
  * The LCD can display only 16 characters in a single line.
  If the defined text overflows 16 characters,
  Cursor of the LCD must be moved to the beginning of the next line.
  * Data need to be in "char" data type to display through the LCD
  */


// In order to use the delay function F_CPU must be defined at first.
#ifndef F_CPU
#define F_CPU 1000000UL
#endif

// Include required built-in header files
#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

// user defined libraries
#include "tsa.h"
#include "dsa.h"


// Include required custom header files
#include "i2c_lcd.h"
#include "i2cmaster.h"
#include "image32.h"

// global variables to be changed inside even in the ISR
volatile unsigned int OverflowCount = 0;
volatile unsigned int ClockTicks = 0;

ISR(TIMER1_OVF_vect)
{
	cli(); // Disable Global Interrupts
	OverflowCount++;
	/* 
	When an overflow happens Timer Overflow Flag(TOV0) in TIFR is automatically set to 1.
	Now, we need to Reset the TOV0 flag back to zero in order to identify another overflow.
	Unlike other registers, in order to reset it to zero, We need to make it one. Not zero.
	
	TOV1 is automatically cleared when the Timer/Counter1 Overflow interrupt vector is executed. Alternatively, TOV1
	can be cleared by writing a logic one to its bit location.	
	*/
	TIFR = 0x01;
	sei(); // Enable Global Interrupts
	TCNT1 = 0; // Resetting the counter to 1 at each overflow
}

/*
uint8_t BinaryImage[IMG_HEIGHT][IMG_WIDTH] = {
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
	{0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
	{0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
	{0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

*/
int main(void)
{
	//cli ; // Disable Global Interrupts
    TCCR1A = 0;
    TCCR1B = 0;	
	TCCR1B |= (1 << CS00);   // clock (No pre-scaling and take the oscillating frequency of the system clock source)
	/*
	See Page 117: Atmega32A data sheet for TIMSK
	• Bit 2 – TOIE1: Timer/Counter1, Overflow Interrupt Enable
	When this bit is written to one, and the I-flag in the Status Register is set (interrupts globally enabled), the
	Timer/Counter1 Overflow Interrupt is enabled. The corresponding Interrupt Vector (See “Interrupts” on page 51) is
	executed when the TOV1 Flag, located in TIFR, is set.
	*/
	TIMSK  |= (1 << TOIE1);   // Timer/Counter1, Overflow Interrupt Enable
	
	//lcd_puts("Start");
	//_delay_ms(1000);
	//while(1){}
	//==================================================================================================
	sei(); // Enable Global Interrupts
	TCNT1 = 0; // initialize counter to 0	
	// your function goes here.
	/* some function*/
	struct Node* contours = findContours (BinaryImage32, IMG_WIDTH, IMG_HEIGHT);
	//_delay_ms(1000);
	//cli ; // Disable Global Interrupts
	ClockTicks = TCNT1;
	//==================================================================================================
	
	// Data need to be in "char" data type to display through the LCD.
    // Define global variables to hold char data.
    char *_line1txt1 = "Overflows,";
	char *_line2txt1 = "Ticks,";
	
	// converting overflow count in to a stream of chars to display
	int length = snprintf( NULL, 0, "%d",  OverflowCount);
	char *_line1txt2 = malloc( length + 1 );
	snprintf( _line1txt2, length + 1, "%d",  OverflowCount);
	
	// converting clock tics count in to a stream of chars to display
	length = snprintf( NULL, 0, "%d",  ClockTicks);
	char *_line2txt2 = malloc( length + 1 );
	snprintf( _line2txt2, length + 1, "%d",  ClockTicks);
	
    // Initialize the LCD to display
    lcd_init(LCD_BACKLIGHT_ON);
    lcd_cursorOFF();

    while (1)
    {
      // Calling the function to display the _line1txt1
      lcd_puts(_line1txt1);
      // Move the cursor
      lcd_goto_xy(10,0);
      // Calling the function to display _line1txt2
      lcd_puts(_line1txt2);
	  	  	  
	  // Move the cursor to second line
	  lcd_goto_xy(0,1);		
	  lcd_puts(_line2txt1);
	  lcd_goto_xy(10,1);
	  lcd_puts(_line2txt2);
      // Wait for a while before clearing the display.
      _delay_ms(1000);
      // Calling the function to clear the screen
      lcd_clear();

    }
}