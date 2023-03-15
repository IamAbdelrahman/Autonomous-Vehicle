/* 
 * File:   BUTTON.h
 * Author: ak
 *
 * Created on March 15, 2023, 10:43 PM
 */

#ifndef BUTTON_H
#define	BUTTON_H
#include "Platform_Types.h"
#include "Registers.h"
#include "DIO.h"
void BUTTON_Init (uint8_t portName, uint8_t pinNumber);

void BUTTON_Read (uint8_t portName, uint8_t pinNumber, uint8_t* value);

#endif	/* BUTTON_H */

