/*
 * avr_gpio_macro.cpp
 *
 * Created: 30/08/2021 9:45:30 AM
 * Author : basher_samiul
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "avrgpio.h"


int main(void)
{	
    PIN_MODE(PB7,OUTPUT);
    PIN_MODE(PB6,INPUT_PULLUP);
	  
    while (1) 
    {
	//TOGGLE(PB7);
	if(!READ(PB6))
	{
	     WRITE(PB7,HIGH);
	     _delay_ms(30);
	     WRITE(PB7,LOW);
	     _delay_ms(30);
	}
    }
}

