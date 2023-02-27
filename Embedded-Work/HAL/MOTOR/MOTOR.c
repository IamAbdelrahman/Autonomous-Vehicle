#include "MOTOR.h"

void MOTOR_Init (void)
{   
    DDRB_Out();
    PWM_Start (254);
}

void MOTOR_Clkwise (void)
{
    UGPIO_t* pGPIO = ADDRESS_PORTB;
    pGPIO->All_Bits = 0x05;
}

void MOTOR_Stop (void)
{
    PORTB_Low();
}

void MOTOR_Anticlkwise (void)
{
    UGPIO_t* pGPIO = ADDRESS_PORTB;
    pGPIO->All_Bits = 0x0A;
}
