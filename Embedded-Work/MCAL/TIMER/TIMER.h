/*
 * timer.h
 *
 *  Created on: Nov 11, 2022
 *      Author: ak
 */

#ifndef MCAL_TIMER_TIMER_H_
#define MCAL_TIMER_TIMER_H_
#include "DIO.h"
#include "INTERRUPT.h"

#define T_TICK  (1024.0 / F_CPU)
#define T_MAX_DELAY  (256.0 * T_TICK)

// Timer Channels
#define TIMER0  0
#define TIMER1  1
#define TIMER2  2


// Timers Overflow Values
#define TIMER0_OVERFLOW 256
#define TIMER1_OVERFLOW 65536
#define TIMER2_OVERFLOW 256

// Timer Modes
#define NORMAL_MODE                         0
#define PWM_MODE_FAST_NON_INVERTED          1
#define PWM_MODE_FAST_INVERTED              2
#define PWM_MODE_PHASE_CORRECT_NON_INVERTED 3
#define PWM_MODE_PHASE_CORRECT_INVERTED     4

// TIMER0 & TIMER1 & TIMER2 - PRESCALER
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
    vuint8_t WGM01 : 1;
    vuint8_t COM00 : 1;
    vuint8_t COM01 : 1;
    vuint8_t WGM00 : 1;
    vuint8_t FOC0 : 1;

} ST_TCCR0_t;

typedef union {
    vuint8_t All_Bits;
    ST_TCCR0_t Timer0;

} U_TCCR0_t;

typedef struct {
    vuint8_t WGM10 : 1;
    vuint8_t WGM11 : 1;
    vuint8_t FOC1B : 1;
    vuint8_t FOC1A : 1;
    vuint8_t COM1B0 : 1;
    vuint8_t COM1B1 : 1;
    vuint8_t COM1A0 : 1;
    vuint8_t COM1A1 : 1;

} ST_TCCR1A_t;

typedef union {
    vuint8_t All_Bits;
    ST_TCCR1A_t Timer1A;

} U_TCCR1A_t;

typedef struct {
    vuint8_t CS10 : 1;
    vuint8_t CS11 : 1;
    vuint8_t CS12 : 1;
    vuint8_t WGM12 : 1;
    vuint8_t WGM13 : 1;
    vuint8_t reserved : 1;
    vuint8_t ICES1 : 1;
    vuint8_t ICNC1 : 1;

} ST_TCCR1B_t;

typedef union {
    vuint8_t All_Bits;
    ST_TCCR1B_t Timer1B;

} U_TCCR1B_t;

typedef struct {
    vuint8_t CS20 : 1;
    vuint8_t CS21 : 1;
    vuint8_t CS22 : 1;
    vuint8_t WGM21 : 1;
    vuint8_t COM20 : 1;
    vuint8_t COM21 : 1;
    vuint8_t WGM20 : 1;
    vuint8_t FOC2 : 1;

} ST_TCCR2_t;

typedef union {
    vuint8_t All_Bits;
    ST_TCCR2_t Timer2;

} U_TCCR2_t;

typedef struct {
    vuint8_t TOV0 : 1;
    vuint8_t OCF0 : 1;
    vuint8_t TOV1 : 1;
    vuint8_t OCF1B : 1;
    vuint8_t OCF1A : 1;
    vuint8_t ICF1 : 1;
    vuint8_t TOV2 : 1;
    vuint8_t OCF2 : 1;

} ST_TIFR_t;

typedef union {
    vuint8_t All_Bits;
    ST_TIFR_t TIFR_Reg;

} U_TIFR_t;

typedef struct {
    vuint8_t Timer_Channel;
    vuint8_t Timer_Mode;
    vuint8_t Timer_Start_Prescalar;

} ST_TIMER_config_t;

#define ADDRESS_TCCR0    (U_TCCR0_t*)(TCCR0)
#define ADDRESS_TCCR2    (U_TCCR2_t*)(TCCR2)
#define ADDRESS_TCCR1A   (U_TCCR1A_t*)(TCCR1A)
#define ADDRESS_TCCR1B   (U_TCCR1B_t*)(TCCR1B)
#define ADDRESS_TIFR     (U_TIFR_t*)(TIFR)

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
void TIMER_Start(ST_TIMER_config_t* pTIMER);
void TIM0_Init(void);
void TIM1_Init(void);
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
void TIM0_Set(void);
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
void TIM2_Set(void);
/*________________________________________________________________________________
________________________________________________________________________________*/

/***************************TIM1_Start**********************************
 * This function starts the Timer/Count1 register by assigning an initial
 * value to the TCNT1L and TCNT1H by zero.
 *
 * Inputs: It takes nothing
 * 
 * Return: Void
 ***************************TIM1_Start**********************************/
void TIM1_Set(void);
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
void TIMER_Stop(ST_TIMER_config_t* pTIMER);
void TIM0_Stop(void);
void TIM2_Stop(void);
void TIM1_Stop(void);
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
void delay_s(float Time_delay_s);
/*________________________________________________________________________________
________________________________________________________________________________*/

/***************************PWM_Start**********************************
 * This function is used to generate PWM signals depending on the calculations
 * of FAST_PWM signals, then assign the result in the OCRn register
 *
 * Inputs: It takes the value of the duty cycle (0 : 100) hence the 
 * overflow is 256
 * 
 * Return: Void
 ***************************PWM_Start**********************************/
void PWM_Start(uint8_t dutyCycle);
/*________________________________________________________________________________
________________________________________________________________________________*/

/***************************TIMER_checkStatus**********************************
 * This function is used to get the status of any timer and store it
 * in a status variable
 *
 * Inputs: It takes the pTIMER pointer to access the general Timer structures
 * to get the Timer channel in order to get its status. It also takes a pointer 
 * to unsigned character to store the status in
 * 
 * Return: Void
 ***************************TIMER_checkStatus**********************************/
void TIMER_checkStatus(ST_TIMER_config_t* pTIMER, uint8_t *status);
/*________________________________________________________________________________
________________________________________________________________________________*/

/***************************TIMER_Reset**********************************
 * This function is used to reset the Timer
 *
 * Inputs: It takes the pTIMER pointer to access the general Timer structures
 * to get the Timer channel in order to reset it through start it from the 
 * zero and set the timer overflow flag.
 * 
 * Return: Void
 ***************************TIMER_Reset**********************************/
void TIMER_Reset(ST_TIMER_config_t* pTIMER);
void TIM0_Reset(void);
void TIM1_Reset(void);
void TIM2_Reset(void);
/*________________________________________________________________________________
________________________________________________________________________________*/

#endif /* MCAL_TIMER_TIMER_H_ */
