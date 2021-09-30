/*
 * avrgpio.h
 *
 * Created: 30/08/2021 9:47:24 AM
 *  Author: basher_samiul
 
 * The idea for this code is taken from the marlin firmware "fastio.h" and rewritten by samiul
 * Why double ## on these macros? see https://gcc.gnu.org/onlinedocs/gcc-4.8.5/cpp/Stringification.html
 * Work with both avr and arduino(must use avr pin eg:PB7)
 *
 *
 * When the mode is INPUT
	make the bit of DDR to 0, and the bit of PORT to 0
 * When the mode is INPUT_PULLUP
    make the bit of DDR to 0, and the bit of PORT to 1
 * When the mode is OUTPUT(actually the mode is not INPUT or INPUT_PULLUP)
	make the bit of DDR to 1
  *
 */ 


#ifndef AVRGPIO_H_
#define AVRGPIO_H_


 #include <avr/io.h>
 /*
    I/O routines
    
    SBI(TCCR1A,WGM10) //WGM10 bit HIGH "set bit"
    CIB(TCCR1A,WGM10) //WGM10 bit LOW  "clear bit"

    //Individual pin mode settings
    SET_OUTPUT(PB7); 
    SET_INPUT(PB7)
    PULLUP(PB7)
    --------------------------------

    //pin mode settings as a function
    PIN_MODE(PB7,OUTPUT);
    PIN_MODE(PB7,INPUT);
    PIN_MODE(PB7,INPUT_PULLUP);
    --------------------------------

    WRITE(PB7, HIGH); 
    WRITE(PB7, LOW);
    READ(PB7);
    TOGGLE(PB7);
 */
 #if defined(ARDUINO) && ARDUINO >= 100
    #include "Arduino.h"
 #else
    //#include <WProgram.h>  
    #define HIGH 0x1
    #define LOW  0x0

    #define INPUT 0x0
    #define OUTPUT 0x1
    #define INPUT_PULLUP 0x2
 #endif


 #ifndef CBI
    //clear bit
    #define   CBI(sfr, bit)           (_SFR_BYTE(sfr) &= ~_BV(bit))
 #endif
 #ifndef SBI
    //set bit
    #define   SBI(sfr, bit)           (_SFR_BYTE(sfr) |= _BV(bit))
 #endif

 // set pin as input
 #define     SET_INPUT(bit)          (bit ## _DDR &= ~(1 << bit))
 // set pin as output
 #define	 SET_OUTPUT(bit)         (bit ## _DDR |=  (1 << bit))
 // set pin as pullup
 #define     PULLUP(bit)             (bit ## _PORT |= (1 << bit))
 // set pin as input, output & input pullup
 #define     PIN_MODE(bit, m)        switch(m) { \
                                        case INPUT:         (bit ## _DDR &= ~(1 << bit)); break;  \
                                        case OUTPUT:        (bit ## _DDR |=  (1 << bit)); break;  \
                                        case INPUT_PULLUP:  (bit ## _DDR &= ~(1 << bit));  (bit ## _PORT |= (1 << bit));  break;  \
									 }
 /*
 #define     PIN_MODE(bit, m)        if(m==0) (bit ## _DDR &= ~(1 << bit));  \
                                    else if(m==1)(bit ## _DDR |=  (1 << bit));  \
                                    else (bit ## _DDR &= ~(1 << bit));  (bit ## _PORT |= (1 << bit));
 */

    
 // Read a pin 
 #define	READ(bit)				(bit ## _PIN & (1 << bit))
 // write to a pin 
 #define	WRITE(bit, v)			if(v) (bit ## _PORT |= (1 << bit));  else (bit ## _PORT &= ~(1 << bit));
 // toggle a pin
 #define	TOGGLE(bit)             (bit ## _PIN |= (1 << bit))
    

 // enable pin change interrupt
 #define   ENABLE_PCINT(pin)	    (pin ## _PCMSK |= (1 << pin ## _PCINT))
 // enable pin change interrupt
 #define   DISABLE_PCINT(pin)		(pin ## _PCMSK &= ~(1<< pin ## _PCINT))


 /* example
 #define PB7_PIN		PINB
 #define PB7_PORT		PORTB
 #define PB7_DDR		DDRB
 #define PB7_PWM		&OCR0A
 #define PB7_PCINT		PCINT7 
 #define PB7_PCMSK		PCMSK0 
 */

 #if defined (__AVR_ATmega168__) || defined (__AVR_ATmega328__) || defined (__AVR_ATmega328P__)
    #define PB0_PIN			PINB
    #define PB0_PORT		PORTB
    #define PB0_DDR			DDRB
    #define PB0_PWM			NULL

    #define PB1_PIN			PINB
    #define PB1_PORT		PORTB
    #define PB1_DDR			DDRB
    #define PB1_PWM			NULL

    #define PB2_PIN			PINB
    #define PB2_PORT		PORTB
    #define PB2_DDR			DDRB
    #define PB2_PWM			NULL

    #define PB3_PIN	  		PINB
    #define PB3_PORT		PORTB
    #define PB3_DDR			DDRB
    #define PB3_PWM			&OCR2A

    #define PB4_PIN	  		PINB
    #define PB4_PORT		PORTB
    #define PB4_DDR			DDRB
    #define PB4_PWM			NULL

    #define PB5_PIN			PINB
    #define PB5_PORT		PORTB
    #define PB5_DDR			DDRB
    #define PB5_PWM			NULL

    #define PB6_PIN	  		PINB
    #define PB6_PORT		PORTB
    #define PB6_DDR			DDRB
    #define PB6_PWM			NULL

    #define PB7_PIN			PINB
    #define PB7_PORT		PORTB
    #define PB7_DDR			DDRB
    #define PB7_PWM			NULL

    #define PC0_PIN		  	PINC
    #define PC0_PORT		PORTC
    #define PC0_DDR			DDRC
    #define PC0_PWM			NULL

    #define PC1_PIN			PINC
    #define PC1_PORT		PORTC
    #define PC1_DDR			DDRC
    #define PC1_PWM			NULL

    #define PC2_PIN			PINC
    #define PC2_PORT		PORTC
    #define PC2_DDR			DDRC
    #define PC2_PWM			NULL

    #define PC3_PIN	  		PINC
    #define PC3_PORT		PORTC
    #define PC3_DDR			DDRC
    #define PC3_PWM			NULL

    #define PC4_PIN			PINC
    #define PC4_PORT		PORTC
    #define PC4_DDR			DDRC
    #define PC4_PWM			NULL

    #define PC5_PIN			PINC
    #define PC5_PORT		PORTC
    #define PC5_DDR			DDRC
    #define PC5_PWM			NULL

    #define PC6_PIN	  		PINC
    #define PC6_PORT		PORTC
    #define PC6_DDR			DDRC
    #define PC6_PWM			NULL

    #define PC7_PIN			PINC
    #define PC7_PORT		PORTC
    #define PC7_DDR			DDRC
    #define PC7_PWM			NULL

    #define PD0_PIN	  		PIND
    #define PD0_PORT		PORTD
    #define PD0_DDR			DDRD
    #define PD0_PWM			NULL

    #define PD1_PIN			PIND
    #define PD1_PORT		PORTD
    #define PD1_DDR			DDRD
    #define PD1_PWM			NULL

    #define PD2_PIN		  	PIND
    #define PD2_PORT		PORTD
    #define PD2_DDR			DDRD
    #define PD2_PWM			NULL

    #define PD3_PIN			PIND
    #define PD3_PORT		PORTD
    #define PD3_DDR			DDRD
    #define PD3_PWM			&OCR2B

    #define PD4_PIN	  		PIND
    #define PD4_PORT		PORTD
    #define PD4_DDR			DDRD
    #define PD4_PWM			NULL

    #define PD5_PIN 		PIND
    #define PD5_PORT		PORTD
    #define PD5_DDR			DDRD
    #define PD5_PWM			&OCR0B

    #define PD6_PIN			PIND
    #define PD6_PORT		PORTD
    #define PD6_DDR			DDRD
    #define PD6_PWM			&OCR0A

    #define PD7_PIN			PIND
    #define PD7_PORT		PORTD
    #define PD7_DDR			DDRD
    #define PD7_PWM			NULL
 #endif	/*	_AVR_ATmega{168,328,328P}__ */

 #if defined (__AVR_ATmega644__) || defined (__AVR_ATmega644P__) || defined (__AVR_ATmega644PA__) || defined(__AVR_ATmega1284P__)
    #define PA0_PIN  		PINA
    #define PA0_PORT		PORTA
    #define PA0_DDR			DDRA
    #define PA0_PWM			NULL

    #define PA1_PIN  		PINA
    #define PA1_PORT		PORTA
    #define PA1_DDR			DDRA
    #define PA1_PWM			NULL

    #define PA2_PIN  		PINA
    #define PA2_PORT		PORTA
    #define PA2_DDR			DDRA
    #define PA2_PWM			NULL

    #define PA3_PIN  		PINA
    #define PA3_PORT		PORTA
    #define PA3_DDR			DDRA
    #define PA3_PWM			NULL

    #define PA4_PIN  		PINA
    #define PA4_PORT		PORTA
    #define PA4_DDR			DDRA
    #define PA4_PWM			NULL

    #define PA5_PIN  		PINA
    #define PA5_PORT		PORTA
    #define PA5_DDR			DDRA
    #define PA5_PWM			NULL

    #define PA6_PIN  		PINA
    #define PA6_PORT		PORTA
    #define PA6_DDR			DDRA
    #define PA6_PWM			NULL

    #define PA7_PIN  		PINA
    #define PA7_PORT		PORTA
    #define PA7_DDR			DDRA
    #define PA7_PWM			NULL

    #define PB0_PIN  		PINB
    #define PB0_PORT		PORTB
    #define PB0_DDR			DDRB
    #define PB0_PWM			NULL

    #define PB1_PIN  		PINB
    #define PB1_PORT		PORTB
    #define PB1_DDR			DDRB
    #define PB1_PWM			NULL

    #define PB2_PIN  		PINB
    #define PB2_PORT		PORTB
    #define PB2_DDR			DDRB
    #define PB2_PWM			NULL

    #define PB3_PIN  		PINB
    #define PB3_PORT		PORTB
    #define PB3_DDR			DDRB
    #define PB3_PWM			&OCR0A

    #define PB4_PIN  		PINB
    #define PB4_PORT		PORTB
    #define PB4_DDR			DDRB
    #define PB4_PWM			&OCR0B

    #define PB5_PIN  		PINB
    #define PB5_PORT		PORTB
    #define PB5_DDR			DDRB
    #define PB5_PWM			NULL

    #define PB6_PIN  		PINB
    #define PB6_PORT		PORTB
    #define PB6_DDR			DDRB
    #define PB6_PWM			NULL

    #define PB7_PIN  		PINB
    #define PB7_PORT		PORTB
    #define PB7_DDR			DDRB
    #define PB7_PWM			NULL

    #define PC0_PIN  		PINC
    #define PC0_PORT		PORTC
    #define PC0_DDR			DDRC
    #define PC0_PWM			NULL

    #define PC1_PIN  		PINC
    #define PC1_PORT		PORTC
    #define PC1_DDR			DDRC
    #define PC1_PWM			NULL

    #define PC2_PIN  		PINC
    #define PC2_PORT		PORTC
    #define PC2_DDR			DDRC
    #define PC2_PWM			NULL

    #define PC3_PIN  		PINC
    #define PC3_PORT		PORTC
    #define PC3_DDR			DDRC
    #define PC3_PWM			NULL

    #define PC4_PIN  		PINC
    #define PC4_PORT		PORTC
    #define PC4_DDR			DDRC
    #define PC4_PWM			NULL

    #define PC5_PIN  		PINC
    #define PC5_PORT		PORTC
    #define PC5_DDR			DDRC
    #define PC5_PWM			NULL

    #define PC6_PIN  		PINC
    #define PC6_PORT		PORTC
    #define PC6_DDR			DDRC
    #define PC6_PWM			NULL

    #define PC7_PIN  		PINC
    #define PC7_PORT		PORTC
    #define PC7_DDR			DDRC
    #define PC7_PWM			NULL

    #define PD0_PIN  		PIND
    #define PD0_PORT		PORTD
    #define PD0_DDR			DDRD
    #define PD0_PWM			NULL

    #define PD1_PIN  		PIND
    #define PD1_PORT		PORTD
    #define PD1_DDR			DDRD
    #define PD1_PWM			NULL

    #define PD2_PIN  		PIND
    #define PD2_PORT		PORTD
    #define PD2_DDR			DDRD
    #define PD2_PWM			NULL

    #define PD3_PIN  		PIND
    #define PD3_PORT		PORTD
    #define PD3_DDR			DDRD
    #define PD3_PWM			NULL

    #define PD4_PIN  		PIND
    #define PD4_PORT		PORTD
    #define PD4_DDR			DDRD
    #define PD4_PWM			NULL

    #define PD5_PIN  		PIND
    #define PD5_PORT		PORTD
    #define PD5_DDR			DDRD
    #define PD5_PWM			NULL

    #define PD6_PIN  		PIND
    #define PD6_PORT		PORTD
    #define PD6_DDR			DDRD
    #define PD6_PWM			&OCR2B

    #define PD7_PIN  		PIND
    #define PD7_PORT		PORTD
    #define PD7_DDR			DDRD
    #define PD7_PWM			&OCR2A
 #endif	/*	_AVR_ATmega{644,644P,644PA,1284P}__ */

 #if defined (__AVR_ATmega1280__) || defined (__AVR_ATmega2560__)
    #define PA0_PIN  		PINA
    #define PA0_PORT		PORTA
    #define PA0_DDR			DDRA
    #define PA0_PWM			NULL

    #define PA1_PIN  		PINA
    #define PA1_PORT		PORTA
    #define PA1_DDR			DDRA
    #define PA1_PWM			NULL

    #define PA2_PIN  		PINA
    #define PA2_PORT		PORTA
    #define PA2_DDR			DDRA
    #define PA2_PWM			NULL

    #define PA3_PIN  		PINA
    #define PA3_PORT		PORTA
    #define PA3_DDR			DDRA
    #define PA3_PWM			NULL

    #define PA4_PIN  		PINA
    #define PA4_PORT		PORTA
    #define PA4_DDR			DDRA
    #define PA4_PWM			NULL
  
    #define PA5_PIN  		PINA
    #define PA5_PORT		PORTA
    #define PA5_DDR			DDRA
    #define PA5_PWM			NULL

    #define PA6_PIN  		PINA
    #define PA6_PORT		PORTA
    #define PA6_DDR			DDRA
    #define PA6_PWM			NULL

    #define PA7_PIN  		PINA
    #define PA7_PORT		PORTA
    #define PA7_DDR			DDRA
    #define PA7_PWM			NULL

    #define PB0_PIN  		PINB
    #define PB0_PORT		PORTB
    #define PB0_DDR			DDRB
    #define PB0_PWM			NULL

    #define PB1_PIN  		PINB
    #define PB1_PORT		PORTB
    #define PB1_DDR			DDRB
    #define PB1_PWM			NULL

    #define PB2_PIN  		PINB
    #define PB2_PORT		PORTB
    #define PB2_DDR			DDRB
    #define PB2_PWM			NULL

    #define PB3_PIN  		PINB
    #define PB3_PORT		PORTB
    #define PB3_DDR			DDRB
    #define PB3_PWM			NULL

    #define PB4_PIN  		PINB
    #define PB4_PORT		PORTB
    #define PB4_DDR			DDRB
    #define PB4_PWM			&OCR2A

    #define PB5_PIN  		PINB
    #define PB5_PORT		PORTB
    #define PB5_DDR			DDRB
    #define PB5_PWM			NULL

    #define PB6_PIN  		PINB
    #define PB6_PORT		PORTB
    #define PB6_DDR			DDRB
    #define PB6_PWM			NULL

    #define PB7_PIN  		PINB
    #define PB7_PORT		PORTB
    #define PB7_DDR			DDRB
    #define PB7_PWM			&OCR0A
    #define PB7_PCINT		PCINT7 
    #define PB7_PCMSK		PCMSK0 

    #define PC0_PIN  		PINC
    #define PC0_PORT		PORTC
    #define PC0_DDR			DDRC
    #define PC0_PWM			NULL

    #define PC1_PIN  		PINC
    #define PC1_PORT		PORTC
    #define PC1_DDR			DDRC
    #define PC1_PWM			NULL

    #define PC2_PIN  		PINC
    #define PC2_PORT		PORTC
    #define PC2_DDR			DDRC
    #define PC2_PWM			NULL

    #define PC3_PIN  		PINC
    #define PC3_PORT		PORTC
    #define PC3_DDR			DDRC
    #define PC3_PWM			NULL

    #define PC4_PIN  		PINC
    #define PC4_PORT		PORTC
    #define PC4_DDR			DDRC
    #define PC4_PWM			NULL

    #define PC5_PIN  		PINC
    #define PC5_PORT		PORTC
    #define PC5_DDR			DDRC
    #define PC5_PWM			NULL

    #define PC6_PIN  		PINC
    #define PC6_PORT		PORTC
    #define PC6_DDR			DDRC
    #define PC6_PWM			NULL

    #define PC7_PIN  		PINC
    #define PC7_PORT		PORTC
    #define PC7_DDR			DDRC
    #define PC7_PWM			NULL

    #define PD0_PIN  		PIND
    #define PD0_PORT		PORTD
    #define PD0_DDR			DDRD
    #define PD0_PWM			NULL

    #define PD1_PIN  		PIND
    #define PD1_PORT		PORTD
    #define PD1_DDR			DDRD
    #define PD1_PWM			NULL

    #define PD2_PIN  		PIND
    #define PD2_PORT		PORTD
    #define PD2_DDR			DDRD
    #define PD2_PWM			NULL

    #define PD3_PIN  		PIND
    #define PD3_PORT		PORTD
    #define PD3_DDR			DDRD
    #define PD3_PWM			NULL

    #define PD4_PIN  		PIND
    #define PD4_PORT		PORTD
    #define PD4_DDR			DDRD
    #define PD4_PWM			NULL

    #define PD5_PIN  		PIND
    #define PD5_PORT		PORTD
    #define PD5_DDR			DDRD
    #define PD5_PWM			NULL

    #define PD6_PIN  		PIND
    #define PD6_PORT		PORTD
    #define PD6_DDR			DDRD
    #define PD6_PWM			NULL

    #define PD7_PIN  		PIND
    #define PD7_PORT		PORTD
    #define PD7_DDR			DDRD
    #define PD7_PWM			NULL

    #define PE0_PIN  		PINE
    #define PE0_PORT		PORTE
    #define PE0_DDR			DDRE
    #define PE0_PWM			NULL

    #define PE1_PIN  		PINE
    #define PE1_PORT		PORTE
    #define PE1_DDR			DDRE
    #define PE1_PWM			NULL

    #define PE2_PIN  		PINE
    #define PE2_PORT		PORTE
    #define PE2_DDR			DDRE
    #define PE2_PWM			NULL

    #define PE3_PIN  		PINE
    #define PE3_PORT		PORTE
    #define PE3_DDR			DDRE
    #define PE3_PWM			&OCR3AL

    #define PE4_PIN  		PINE
    #define PE4_PORT		PORTE
    #define PE4_DDR			DDRE
    #define PE4_PWM			&OCR3BL

    #define PE5_PIN  		PINE
    #define PE5_PORT		PORTE
    #define PE5_DDR			DDRE
    #define PE5_PWM			&OCR3CL

    #define PE6_PIN  		PINE
    #define PE6_PORT		PORTE
    #define PE6_DDR			DDRE
    #define PE6_PWM			NULL

    #define PE7_PIN  		PINE
    #define PE7_PORT		PORTE
    #define PE7_DDR			DDRE
    #define PE7_PWM			NULL

    #define PF0_PIN  		PINF
    #define PF0_PORT		PORTF
    #define PF0_DDR			DDRF
    #define PF0_PWM			NULL

    #define PF1_PIN  		PINF
    #define PF1_PORT		PORTF
    #define PF1_DDR			DDRF
    #define PF1_PWM			NULL

    #define PF2_PIN  		PINF
    #define PF2_PORT		PORTF
    #define PF2_DDR			DDRF
    #define PF2_PWM			NULL

    #define PF3_PIN  		PINF
    #define PF3_PORT		PORTF
    #define PF3_DDR			DDRF
    #define PF3_PWM			NULL

    #define PF4_PIN  		PINF
    #define PF4_PORT		PORTF
    #define PF4_DDR			DDRF
    #define PF4_PWM			NULL

    #define PF5_PIN  		PINF
    #define PF5_PORT		PORTF
    #define PF5_DDR			DDRF
    #define PF5_PWM			NULL

    #define PF6_PIN  		PINF
    #define PF6_PORT		PORTF
    #define PF6_DDR			DDRF
    #define PF6_PWM			NULL

    #define PF7_PIN  		PINF
    #define PF7_PORT		PORTF
    #define PF7_DDR			DDRF
    #define PF7_PWM			NULL

    #define PG0_PIN  		PING
    #define PG0_PORT		PORTG
    #define PG0_DDR			DDRG
    #define PG0_PWM			NULL

    #define PG1_PIN  		PING
    #define PG1_PORT		PORTG
    #define PG1_DDR			DDRG
    #define PG1_PWM			NULL

    #define PG2_PIN  		PING
    #define PG2_PORT		PORTG
    #define PG2_DDR			DDRG
    #define PG2_PWM			NULL

    #define PG3_PIN  		PING
    #define PG3_PORT		PORTG
    #define PG3_DDR			DDRG
    #define PG3_PWM			NULL

    #define PG4_PIN  		PING
    #define PG4_PORT		PORTG
    #define PG4_DDR			DDRG
    #define PG4_PWM			NULL

    #define PG5_PIN  		PING
    #define PG5_PORT		PORTG
    #define PG5_DDR			DDRG
    #define PG5_PWM			&OCR0B

    #define PG6_PIN  		PING
    #define PG6_PORT		PORTG
    #define PG6_DDR			DDRG
    #define PG6_PWM			NULL

    #define PG7_PIN  		PING
    #define PG7_PORT		PORTG
    #define PG7_DDR			DDRG
    #define PG7_PWM			NULL

    #define PH0_PIN  		PINH
    #define PH0_PORT		PORTH
    #define PH0_DDR			DDRH
    #define PH0_PWM			NULL

    #define PH1_PIN  		PINH
    #define PH1_PORT		PORTH
    #define PH1_DDR			DDRH
    #define PH1_PWM			NULL

    #define PH2_PIN  		PINH
    #define PH2_PORT		PORTH
    #define PH2_DDR			DDRH
    #define PH2_PWM			NULL

    #define PH3_PIN  		PINH
    #define PH3_PORT		PORTH
    #define PH3_DDR			DDRH
    #define PH3_PWM			&OCR4AL

    #define PH4_PIN  		PINH
    #define PH4_PORT		PORTH
    #define PH4_DDR			DDRH
    #define PH4_PWM			&OCR4BL

    #define PH5_PIN  		PINH
    #define PH5_PORT		PORTH
    #define PH5_DDR			DDRH
    #define PH5_PWM			&OCR4CL

    #define PH6_PIN  		PINH
    #define PH6_PORT		PORTH
    #define PH6_DDR			DDRH
    #define PH6_PWM			&OCR2B
  
    #define PH7_PIN  		PINH
    #define PH7_PORT		PORTH
    #define PH7_DDR			DDRH
    #define PH7_PWM			NULL

    #define PJ0_PIN  		PINJ
    #define PJ0_PORT		PORTJ
    #define PJ0_DDR			DDRJ
    #define PJ0_PWM			NULL

    #define PJ1_PIN  		PINJ
    #define PJ1_PORT		PORTJ
    #define PJ1_DDR			DDRJ
    #define PJ1_PWM			NULL

    #define PJ2_PIN  		PINJ
    #define PJ2_PORT		PORTJ
    #define PJ2_DDR			DDRJ
    #define PJ2_PWM			NULL

    #define PJ3_PIN  		PINJ
    #define PJ3_PORT		PORTJ
    #define PJ3_DDR			DDRJ
    #define PJ3_PWM			NULL

    #define PJ4_PIN  		PINJ
    #define PJ4_PORT		PORTJ
    #define PJ4_DDR			DDRJ
    #define PJ4_PWM			NULL

    #define PJ5_PIN  		PINJ
    #define PJ5_PORT		PORTJ
    #define PJ5_DDR			DDRJ
    #define PJ5_PWM			NULL

    #define PJ6_PIN  		PINJ
    #define PJ6_PORT		PORTJ
    #define PJ6_DDR			DDRJ
    #define PJ6_PWM			NULL

    #define PJ7_PIN  		PINJ
    #define PJ7_PORT		PORTJ
    #define PJ7_DDR			DDRJ
    #define PJ7_PWM			NULL

    #define PK0_PIN  		PINK
    #define PK0_PORT		PORTK
    #define PK0_DDR			DDRK
    #define PK0_PWM			NULL

    #define PK1_PIN  		PINK
    #define PK1_PORT		PORTK
    #define PK1_DDR			DDRK
    #define PK1_PWM			NULL

    #define PK2_PIN  		PINK
    #define PK2_PORT		PORTK
    #define PK2_DDR			DDRK
    #define PK2_PWM			NULL

    #define PK3_PIN  		PINK
    #define PK3_PORT		PORTK
    #define PK3_DDR			DDRK
    #define PK3_PWM			NULL

    #define PK4_PIN  		PINK
    #define PK4_PORT		PORTK
    #define PK4_DDR			DDRK
    #define PK4_PWM			NULL

    #define PK5_PIN  		PINK
    #define PK5_PORT		PORTK
    #define PK5_DDR			DDRK
    #define PK5_PWM			NULL

    #define PK6_PIN  		PINK
    #define PK6_PORT		PORTK
    #define PK6_DDR			DDRK
    #define PK6_PWM			NULL

    #define PK7_PIN  		PINK
    #define PK7_PORT		PORTK
    #define PK7_DDR			DDRK
    #define PK7_PWM			NULL

    #define PL0_PIN  		PINL
    #define PL0_PORT		PORTL
    #define PL0_DDR			DDRL
    #define PL0_PWM			NULL

    #define PL1_PIN  		PINL
    #define PL1_PORT		PORTL
    #define PL1_DDR			DDRL
    #define PL1_PWM			NULL

    #define PL2_PIN  		PINL
    #define PL2_PORT		PORTL
    #define PL2_DDR			DDRL
    #define PL2_PWM			NULL

    #define PL3_PIN  		PINL
    #define PL3_PORT		PORTL
    #define PL3_DDR			DDRL
    #define PL3_PWM			&OCR5AL

    #define PL4_PIN  		PINL
    #define PL4_PORT		PORTL
    #define PL4_DDR			DDRL
    #define PL4_PWM			&OCR5BL

    #define PL5_PIN  		PINL
    #define PL5_PORT		PORTL
    #define PL5_DDR			DDRL
    #define PL5_PWM			&OCR5CL

    #define PL6_PIN  		PINL
    #define PL6_PORT		PORTL
    #define PL6_DDR			DDRL
    #define PL6_PWM			NULL

    #define PL7_PIN  		PINL
    #define PL7_PORT		PORTL
    #define PL7_DDR			DDRL
    #define PL7_PWM			NULL
 #endif /*	_AVR_ATmega{1280,2560}__ */
#endif /* AVRGPIO_H_ */