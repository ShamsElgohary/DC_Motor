#ifndef TIMER0_H_
#define TIMER0_H_

#include "micro_config.h"
#include "std_types.h"
#include "common_macros.h"

/************************************   Preprocessor    ******************************/

//TIMER 0 MODES
#define NORMAL_MODE 	CLEAR_BIT(TCCR0,WGM01); CLEAR_BIT(TCCR0,WGM00); SET_BIT(TCCR0,FOC0) //WGM01 WGM00 0 0
#define PWM_MODE 		CLEAR_BIT(TCCR0,WGM01); SET_BIT(TCCR0,WGM00)  						//WGM01 WGM00 0 1
#define CTC_MODE 		SET_BIT(TCCR0,WGM01); CLEAR_BIT(TCCR0,WGM00); SET_BIT(TCCR0,WGM00)  //WGM01 WGM00 1 0
#define FAST_PWM_MODE   SET_BIT(TCCR0,WGM01); SET_BIT(TCCR0,WGM00)  						//WGM01 WGM00 1 1

//TIMER0 PRESCALE BITS
#define TIMER_STOP      TCCR0 &= ~ (0b00000111) 	                        //CS02 CS01 CS00 0 0 0
#define NO_PRESCALE	    SET_BIT(TCCR0,CS00)			                        //CS02 CS01 CS00 0 0 1
#define PRESCALE_8		SET_BIT(TCCR0,CS01)									//CS02 CS01 CS00 0 1 0
#define PRESCALE_64		SET_BIT(TCCR0,CS01); SET_BIT(TCCR0,CS00) 			//CS02 CS01 CS00 0 1 1
#define PRESCALE_256	SET_BIT(TCCR0,CS02)									//CS02 CS01 CS00 1 0 0
#define PRESCALE_1024	SET_BIT(TCCR0,CS02); SET_BIT(TCCR0,CS00) 			//CS02 CS01 CS00 1 0 1


/************************************ Function Prototypes ******************************/

void Timer0_init(void);

void Timer0_PWM_DutyCycle(uint8 set_duty_cycle);

#endif
