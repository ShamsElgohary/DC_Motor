# DC_Motor

Using AVR Microcontroller (ATmega16) and a potentiometer connected to the MCU through ADC to control the speed of the DC Motor.  
The speed is controlled through a PWM signal,and the ADC value is displayed on the LCD.  
The motor is reversed if the switch is pressed through an external interrupt.

Implemented drivers:  Timer1 ( PWM mode ), LCD display , Motor, internal ADC with 1 interrupt

![image](https://user-images.githubusercontent.com/68311964/124159483-81f47600-da9b-11eb-834e-3acaf4c2ab85.png)
