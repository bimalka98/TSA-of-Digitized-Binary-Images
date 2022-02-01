/************************************************/
/*					Interrupt.c					*/
/*												*/
/* Created: 9/9/2021 1:56:24 PM					*/
/* Authors: Aloka Perera, Kapila Jayasinghe		*/
/* LE Robotics (Pvt.) Ltd.						*/
/************************************************/

#include "Interrupt.h"


ISR(TIMER1_COMPA_vect)
{
	cli();

	if (Com_Timeout.TimeOutEnable == TRUE)
	{
		Com_Timeout.TimeOutCounter++;
		if (Com_Timeout.TimeOutCounter > MAXTIMEOUTCOUNT)
		{
			Com_Timeout.TimeOutCounter = MAXTIMEOUTCOUNT;
		}
	}
	sei();
}


