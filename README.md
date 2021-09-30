# AVR-GPIO-Macro
A little easier to read and write of the GPIO register for an AVR microcontroller.

## Macros list:

Set bit, Clear bit
* SBI(TCCR1A,WGM10) //WGM10 bit HIGH "set bit"
* CIB(TCCR1A,WGM10) //WGM10 bit LOW  "clear bit"

Individual pin mode settings
* SET_OUTPUT(PB7); 
* SET_INPUT(PB7);
* PULLUP(PB7);

Pin mode settings as a function
* PIN_MODE(PB7,OUTPUT);
* PIN_MODE(PB7,INPUT);
* PIN_MODE(PB7,INPUT_PULLUP);

Read and write of a GPIO
* WRITE(PB7, HIGH); 
* WRITE(PB7, LOW);
* READ(PB7);
* TOGGLE(PB7);
