#include "timer0.h"


/**************************************Functions Definitions******************************************/

void Timer0_init(void)
{
	TCCR0=0;
	NO_PRESCALE;

	PWM_MODE;
	TCCR0 |= (1<<COM01);	 //	Non-inverting mode COM01 COM00 1 0

	DDRB  = DDRB | (1<<PB3); // Configure PB3/OC0 as output pin --> pin where the PWM signal is generated from MC

}


void Timer0_PWM_DutyCycle(uint8 set_duty_cycle)
{
	TCNT0 = 0; // Set Timer Initial Value to 0
	OCR0  = set_duty_cycle; //Set Compare value
}
