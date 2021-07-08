#include "motor.h"


volatile uint8 g_MOTOR_flag=0;

/************************************** ISR   ******************************************/

ISR(INT1_vect)
{
	g_MOTOR_flag=1;
	MOTOR_PORT^=(1<<A);
	MOTOR_PORT^=(1<<B);
}

/**************************************Functions Definitions******************************************/

void MOTOR_init(void)
{
	/* A , B Outputs of MICROCONTROLLER */
	SET_BIT(MOTOR_PORT_DIR,A);
	SET_BIT(MOTOR_PORT_DIR,B);

	/* Motor Moves clockwise by default */
	MOTOR_clockw;
}


void INT1_init(void)
{
	CLEAR_BIT(DDRD,PD3); 	// PD3 INPUT
	CLEAR_BIT(PORTD,PD3); 	// PD3 default value =0

	MCUCR |= (1<<ISC11) | (1<<ISC10); // INT1 GENERATES INT REQ. ON RISING EDGE
	GICR |= (1<<INT1);	// ENABLED INT1 INTERRUPT
}
