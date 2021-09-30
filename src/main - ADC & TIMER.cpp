#include <Arduino.h>
#include "avrgpio.h"

#define ADC_PIN A3
#define MAX_ADC_Value 1023
#define MIN_ADC_Value 0

#define ISR_TOP_Value 1000 //max 1.0 KHz, value 1000

void mappingPWM();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  PIN_MODE(PB7,OUTPUT);

  /*-----------------use to make PWM signal for the controlling duty cycle --------------------------------*/
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

  //freq = FCPU/(2*prescaler*ICR_TOP)
  //125Hz = 16000000Hz/(2*8*1000))
  ICR1 = ISR_TOP_Value;  // max 1.0 KHz, value 1000

  //start timer in compare output mode, Phase Correct "Clear when up-counting, Set down-counting  = 10"
  SBI(TCCR1A,COM1C1); 
}

void loop() {
  // put your main code here, to run repeatedly:

  mappingPWM();
}


void mappingPWM()
{
  uint16_t adc_data = analogRead(ADC_PIN);
  //map motor speed (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
  uint16_t pump_speed = (long)(adc_data - MIN_ADC_Value) * (long)((ISR_TOP_Value-2) - 0) / (long)(MAX_ADC_Value - MIN_ADC_Value) + 0; //998 is max pwm value instend of 1000
  //Serial.println(pump_speed);
  OCR1C = pump_speed; //pwm update
  Serial.println(OCR1C);
}
