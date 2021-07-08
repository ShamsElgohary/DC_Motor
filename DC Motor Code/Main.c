#include "lcd.h"
#include "adc.h"
#include "timer0.h"
#include "motor.h"

int main(void)
{
	uint32 result;

	/* initialize drivers */
	LCD_init();
	ADC_init();
	Timer0_init();
	MOTOR_init();

	INT1_init();
	SREG|=(1<<7); //ENABLING I-BIT

	LCD_clearScreen(); /* clear LCD at the beginning */
	LCD_displayString("ADC Value = ");
    while(1)
    {
    	LCD_goToRowColumn(0 , 12);
    	result=ADC_readChannel(0);
    	LCD_intgerToString(result);

    	result=((result*255)/1023); //be careful result isn't float so if result/1023 and result<1023 o/p = 0
    	Timer0_PWM_DutyCycle(result);
    }
}
