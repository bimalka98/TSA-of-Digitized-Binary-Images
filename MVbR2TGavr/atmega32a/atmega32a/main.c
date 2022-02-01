/*
  * Interfacing a 16*2 LCD display through I2C
  * Created   : 7/12/2020 3:44:42 PM
  * Author    : Bimalka Piyaruwan Thalagala
  * Github    : https://github.com/bimalka98
  
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
#include <avr/io.h>
#include <util/delay.h>

// Include required custom header files
#include "i2c_lcd.h"
#include "i2cmaster.h"



int main(void)
{
    // Data need to be in "char" data type to display through the LCD.
    // Define global variables to hold char data.
    char *line_1_text = "Today is Tuesday";
    char *line_2_text = "2/1/2022 Its 9am";

    // Initialize the LCD to display
    lcd_init(LCD_BACKLIGHT_ON);
    lcd_cursorOFF();


    while (1)
    {
      // Calling the function to display the line_1_text defined previously.
      lcd_puts(line_1_text);

      // Move the cursor to the beginning of the next line.
      lcd_goto_xy(0,1);

      // Calling the function to display the line_2_text defined previously.
      lcd_puts(line_2_text);

      // Wait for a while before clearing the display.
      _delay_ms(1000);

      // Calling the function to clear the screen
      lcd_clear();

    }
}