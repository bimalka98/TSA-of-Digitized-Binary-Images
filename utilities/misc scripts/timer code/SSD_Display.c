/************************************************/
/*					SSD_Display.c				*/
/*												*/
/* Created: 9/9/2021 12:54:29 PM				*/
/* Authors: Aloka Perera, Kapila Jayasinghe		*/
/* LE Robotics (Pvt.) Ltd.						*/
/************************************************/

#include "SSD_Display.h"

void SSD_Init()
{
	// timer interrupt
	TCCR1A  = 0;
	TCCR1B  = 0;
	TCCR1B  = (1 << WGM12); // turn on ctc mode
	TCCR1B |= (0 << CS12) | (1 << CS11) | (1 << CS10); // pre scaler has been set to 64
	OCR1A   = 124; // 1000Hz
	TCNT1   = 0;   /// initialize counter to 0
	TIMSK1  |= (1 << OCIE1A); // compare output interrupt
	
} // Checked - Done
