#include "MOTOR.h"

UGPIO_t* pGPIO = ADDRESS_PORTB;
void MOTOR_Init (void)
{   
    DDRB_Out();
    TIM0_Init();
    PWM_Start (50);
    pGPIO->PORTS.pin0 = 0;
    pGPIO->PORTS.pin1 = 0;
    pGPIO->PORTS.pin5 = 0;
    pGPIO->PORTS.pin6 = 0;    
}

void MOTOR_Clkwise (void)
{   
    pGPIO->PORTS.pin0 = 1;
    pGPIO->PORTS.pin1 = 0;
    _delay_ms(2000);
}

void MOTOR_Stop (void)
{
    pGPIO->PORTS.pin0 = 0;
    pGPIO->PORTS.pin1 = 0;
    pGPIO->PORTS.pin5 = 0;
    pGPIO->PORTS.pin6 = 0;  
    TIM0_Stop();
}

void MOTOR_Anticlkwise (void)
{    
    pGPIO->PORTS.pin5 = 0;
    pGPIO->PORTS.pin6 = 1;
    _delay_ms(2000);
}
