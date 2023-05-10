/* 
 * File:   APP.h
 * Author: ak
 *
 * Created on March 6, 2023, 8:07 AM
 */

#ifndef APP_H
#define	APP_H
#include "DIO.h"
#include "ADC.h"
#include "INTERRUPT.h"
#include "TIMER.h"
#include "UART.h"
#include "MOTORS.h"
#include "BUTTON.h"
#include "BLUETOOTH.h"
#include "LCD.h"
#include "LED.h"
#include "LINE_TRACKER.h"
#include "ULTRASONIC.h"

void appInit(void);
void MCAL_Init(void);
void HAL_Init(void);
void appStart(void);
void freeControlMode(void);
void roomMode(void);

#endif	/* APP_H */
