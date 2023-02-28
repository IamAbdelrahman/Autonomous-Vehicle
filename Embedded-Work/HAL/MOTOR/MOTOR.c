#include "MOTOR.h"
UGPIO_t* pGPIO = ADDRESS_PORTB;
void MOTOR_Init (void)
{   
    DDRB_Out();
    PWM_Start (254);
}

void MOTOR_Clkwise (void)
{   
    pGPIO->PORTS.pin0 = 0;
    pGPIO->PORTS.pin1 = 1;
}

void MOTOR_Stop (void)
{
    PORTB_Low();
}

void MOTOR_Anticlkwise (void)
{    
    pGPIO->PORTS.pin5 = 0;
    pGPIO->PORTS.pin6 = 1;
}
