/*
 * timer.h
 *
 *  Created on: Nov 11, 2022
 *      Author: ak
*/

#ifndef MCAL_TIMER_TIMER_H_
#define MCAL_TIMER_TIMER_H_

#include "../Utilities/Registers.h"
#include "../Utilities/Platform_Types.h"

#define F_CPU   16000000
#define T_TICK  (1024.0 / F_CPU)
#define T_MAX_DELAY  (256 * T_TICK)


// Timers Overflow Values
#define TIMER0_OVERFLOW 256
#define TIMER2_OVERFLOW 256

// Timer Channels
#define TIMER0  0
#define TIMER2  2

// Timer Modes
#define NORMAL_MODE                         0
#define PWM_MODE_FAST_NON_INVERTED          1
#define PWM_MODE_FAST_INVERTED              2
#define PWM_MODE_PHASE_CORRECT_NON_INVERTED 3
#define PWM_MODE_PHASE_CORRECT_INVERTED     4

// TIMER0 & TIMER2 - PRESCALER
#define NO_CLK_SRC               0
#define CLK_NO_PRESCALING        1
#define CLK_8_PRESCALING         2
#define CLK_64_PRESCALING        3
#define CLK_256_PRESCALING       4
#define CLK_1024_PRESCALING      5
#define EX_CLK_SRC_FALLING_EDGE  6
#define EX_CLK_SRC_RISING_EDGE   7

typedef struct {
    
    vuint8_t CS00 : 1;
    vuint8_t CS01 : 1;
    vuint8_t CS02 : 1;
    vuint8_t WGM01: 1;
    vuint8_t COM00: 1;
    vuint8_t COM01: 1;
    vuint8_t WGM00: 1;
    vuint8_t FOC0 : 1;
    
}ST_TCCR0_t;

typedef struct {
    
    vuint8_t CS20 : 1;
    vuint8_t CS21 : 1;
    vuint8_t CS22 : 1;
    vuint8_t WGM21: 1;
    vuint8_t COM20: 1;
    vuint8_t COM21: 1;
    vuint8_t WGM20: 1;
    vuint8_t FOC2 : 1;
    
}ST_TCCR2_t;

typedef union {
        
    vuint8_t All_Bits;
    ST_TCCR0_t Timer0;  
    
}U_TCCR0_t;

typedef union{
    
    vuint8_t All_Bits;
    ST_TCCR2_t Timer2;
    
}U_TCCR2_t;

typedef struct{
    
    vuint8_t Timer_Channel;
    vuint8_t Timer_Mode;
    vuint8_t Timer_Start_Prescalar;
    
}ST_TIMER_config_t;

#define ADDRESS_TCCR0   (U_TCCR0_t*)(TCCR0)
#define ADDRESS_TCCR2   (U_TCCR2_t*)(TCCR2)

/***************************TIMER_Init**********************************
 * This function initializes the Timer register by configuring it
 * through its channel, mode and the pre-scaler too.
 *
 * Inputs: It takes pointer to structure, the structure includes
 * unsigned characters of three variables all of them represent 
 * the timer configuration and they are the mode, channel and pre-scaler
 * 
 * Return: Void
 ***************************TIMER_Init**********************************/
void TIMER_Init(ST_TIMER_config_t* pTIMER);	
/*________________________________________________________________________________
________________________________________________________________________________*/

/***************************TIM0_Init**********************************
 * This function initializes the Timer0 register TCCR0 by configuring it
 * through its channel, mode and the pre-scaler too and this is done by
 * calling the function TIMER_Init() inside it. And so the channel will be
 * TIMER0, and the mode will be NORMAL_MODE, and finally the pre-scaler will
 * be 1024 always
 *
 * Inputs: It takes nothing
 * 
 * Return: Void
 ***************************TIM0_Init**********************************/
void TIM0_Init (void);
/*________________________________________________________________________________
________________________________________________________________________________*/

/***************************TIM2_PWM_Init**********************************
 * This function initializes the Timer2 register TCCR2 by configuring it
 * through its channel, mode and the pre-scaler too and this is done by
 * calling the function TIMER_Init() inside it. And so the channel will be
 * TIMER2, and the mode will be PWM_PHASE_CORRECT_NON_INVERTED
 * and finally the pre-scaler will be 1024 always.
 *
 * Inputs: It takes nothing
 * 
 * Return: Void
 ***************************TIM2_PWM_Init**********************************/
void TIM2_Init(void);
/*________________________________________________________________________________
________________________________________________________________________________*/

/***************************TIM0_Start**********************************
 * This function starts the Timer/Count0 register by assigning an initial
 * value to the TCNT0 and this value is 0
 *
 * Inputs: It takes nothing
 * 
 * Return: Void
 ***************************TIM0_Start**********************************/
void TIM0_Start(void);
/*________________________________________________________________________________
________________________________________________________________________________*/

/***************************TIM2_Start**********************************
 * This function starts the Timer/Count2 register by assigning an initial
 * value to the TCNT2 and this value is 0
 *
 * Inputs: It takes nothing
 * 
 * Return: Void
 ***************************TIM2_Start**********************************/
void TIM2_Start(void);
/*________________________________________________________________________________
________________________________________________________________________________*/

/***************************TIMER_Stop**********************************
 * This function is used to stop the Timer registers
 *
 * Inputs: It takes pointer to structure, the structure includes
 * unsigned characters of three variables all of them represent 
 * the timer configuration and they are the mode, channel and pre-scaler
 * however, it only checks the timer channel to stop it
 * 
 * Return: Void
 ***************************TIMER_Stop**********************************/
void TIMER_Stop (ST_TIMER_config_t* pTIMER);
/*________________________________________________________________________________
________________________________________________________________________________*/

/***************************TIM0_Stop**********************************
 * This function is used to stop the Timer0 (TCCR0) registers, by 
 * initializing a structure of timer configuration and then calling
 * the Timer_Stop() function and passing the address of that structure
 * to it
 *
 * Inputs: It takes nothing
 * 
 * Return: Void
 ***************************TIM0_Stop**********************************/
void TIM0_Stop (void);
/*________________________________________________________________________________
________________________________________________________________________________*/

/***************************TIM2_Stop**********************************
 * This function is used to stop the Timer0 (TCCR2) registers, by 
 * initializing a structure of timer configuration and then calling
 * the Timer_Stop() function and passing the address of that structure
 * to it
 *
 * Inputs: It takes nothing
 * 
 * Return: Void
 ***************************TIM2_Stop**********************************/
void TIM2_Stop(void);
/*________________________________________________________________________________
________________________________________________________________________________*/

/***************************delay_s**********************************
 * This function is used to generate delays by initializing the timer0/2
 * and set an initial value to the TCNT0/2 depending on the time delay
 * given by the user and the fixed values of the pre-scaler and FCPU
 *
 * Inputs: It takes the time delays in seconds
 * 
 * Return: Void
 ***************************delay_s**********************************/
void delay_s(uint64_t Time_delay_s);
/*________________________________________________________________________________
________________________________________________________________________________*/

/***************************PWM_Start**********************************
 * This function is used to generate PWM signals depending on the calculations
 * of FAST_PWM signals, then assign the result in the OCRn register
 *
 * Inputs: It takes the value of the duty cycle (0 : 255)
 * 
 * Return: Void
 ***************************PWM_Start**********************************/
void PWM_Start(uint8_t dutyCycle);
/*________________________________________________________________________________
________________________________________________________________________________*/

void TIMER_checkStatus(uint8_t *status);

#endif /* MCAL_TIMER_TIMER_H_ */
