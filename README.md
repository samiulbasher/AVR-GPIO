# AVR-GPIO-Macro
A little easier to read and write of the GPIO register for an AVR microcontroller.

## Macros list:

Set bit, Clear bit
* SBI(TCCR1A,WGM10) //WGM10 bit HIGH "set bit"
* CIB(TCCR1A,WGM10) //WGM10 bit LOW  "clear bit"
# Example
 //Set waveform generation. Mode 10: 1010 [PWM, Phase correct, Top ICR1]
  SBI(TCCR1B,WGM13);
  CBI(TCCR1B,WGM12);
  SBI(TCCR1A,WGM11);
  CBI(TCCR1A,WGM10);

  //Set timer output mode "Normal port operation" = 00 (Disconnected)
  CBI(TCCR1A,COM1C0);
  CBI(TCCR1A,COM1C1);

  //Set timer pre-scaler [Prescaler clk/8 = 010]
  CBI(TCCR1B,CS12);
  SBI(TCCR1B,CS11);
  CBI(TCCR1B,CS10);
  
  //start timer in compare output mode, Phase Correct "Clear when up-counting, Set down-counting  = 10"
  SBI(TCCR1A,COM1C1);

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
