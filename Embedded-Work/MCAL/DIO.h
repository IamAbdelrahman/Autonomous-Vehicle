/* 
 * File:   DIO.h
 * Author: ak
 *
 * Created on February 12, 2023, 12:16 AM
 */

#ifndef DIO_H
#define	DIO_H

#include "Registers.h"
#include "Platform_Types.h"

#define IN 0
#define OUT 1

#define HIGH 1
#define LOW 0

typedef struct{
   
        vuint8_t pin0 : 1;
        vuint8_t pin1 : 1;
        vuint8_t pin2 : 1;
        vuint8_t pin3 : 1;
        vuint8_t pin4 : 1;
        vuint8_t pin5 : 1;
        vuint8_t pin6 : 1;
        vuint8_t pin7 : 1;
        
    }SGPIO_t;
    
typedef union{
        
        vuint8_t All_Bits;
        SGPIO_t PORTS;
        
    }UGPIO_t;
    
    
/***************************DIO_Init_Pin**********************************
 * This function initialize the pins of the port registers
 * through configuring the pin as an output pin or an input pin
 *
 * Inputs: (portName): This is a character. It must be one of 
 * these characters 'A', 'B', 'C', and 'D' as they represent the
 * name of the ports of the microcontroller.
 *(pinNumber): It represents the pin number of each port
 * and takes a number from 0 : 7.
 * (pinDirection): It represents the state of the pin
 * whether it's OUT or IN and you can use numbers 0 or 1
 * otherwise you can use the macro directly for well-readability
 * 
 * Return: Void
 ***************************DIO_Init_Pin**********************************/
void DIO_Init_Pin (uint8_t portName, uint8_t pinNumber, uint8_t pinDirection);	


/***************************DIO_Write_Pin**********************************
 * This function is used to pull each pin high or low of the port registers
 * through writing on it 1(high) or 0(low).
 *
 * Inputs: (portName): This is a character. It must be one of 
 * these characters 'A', 'B', 'C', and 'D' as they represent the
 * name of the ports of the microcontroller.
 * 
 *(pinNumber): It represents the pin number of each port
 * and takes a number from 0 : 7.
 * 
 * (pinValue): It represents the state of the pin
 * whether it's HIGH or LOW and you can use numbers 0 or 1
 * otherwise you can use the macro directly for well-readability
 * 
 * Return: Void
***************************DIO_Write_Pin**********************************/
void DIO_Write_Pin (uint8_t portName, uint8_t pinNumber, uint8_t pinValue); 


/***************************DIO_Toggle_Pin**********************************
 * This function is used to toggle each pin from high to low and vice versa
 * through using the toggle_bit equation (defined in registers file).
 *
 * Inputs: (portName): This is a character. It must be one of 
 * these characters 'A', 'B', 'C', and 'D' as they represent the
 * name of the ports of the microcontroller.
 * 
 *(pinNumber): It represents the pin number of each port
 * and takes a number from 0 : 7.
 * 
 * Return: Void
***************************DIO_Toggle_Pin**********************************/
void DIO_Toggle_Pin (uint8_t portName, uint8_t pinNumber); 


/***************************DIO_Read_Pin**********************************
 * This function is used to know the status of each pin high or low of the 
 * port registers through reading from it 1(high) or 0(low).
 *
 * Inputs: (portName): This is a character. It must be one of 
 * these characters 'A', 'B', 'C', and 'D' as they represent the
 * name of the ports of the microcontroller.
 * 
 *(pinNumber): It represents the pin number of each port
 * and takes a number from 0 : 7.
 * 
 * (pinValue): This pointer will store the state of the pin
 * whether it's HIGH or LOW ( 0 or 1) by reading from each pin
 * 
 * Return: Void
***************************DIO_Read_Pin**********************************/
void DIO_Read_Pin (uint8_t portName, uint8_t pinNumber, uint8_t* pinValue); 


/***************************DIO_Port_Init**********************************
 * This function initializes the entire ddrx registers
 * through configuring the all pins as output pins or input pins
 * by using the structures, unions, and bit-fields method to access
 * the register.
 *
 * Inputs: (pGPIO): pGPIO is a pointer to union, and this union
 * includes a structure that includes all the bits of any I/O port
 * in the gpio section in the microcontroller in addition that including
 * a variable (all-bits).
 * 
 * (portDirection): It represents the state of the port
 * whether it's OUT or IN and you can use numbers 0 or 1
 * otherwise you can use the macro directly for well-readability
 * 
 * Return: Void
***************************DIO_Port_Init**********************************/
void DIO_Port_Init (UGPIO_t* pGPIO, uint8_t portDirection);


/***************************DIO_Port_Write**********************************
 * This function writes on the entire port registers
 * through writing on the all pins as high pins or low pins
 * by using the structures, unions, and bit-fields method to access
 * the register.
 *
 * Inputs: (pGPIO): pGPIO is a pointer to union, and this union
 * includes a structure that includes all the bits of any I/O port
 * in the GPIO section in the microcontroller in addition that including
 * a variable (all-bits).
 * 
 * (portValue): It represents the state of the port
 * whether it's HIGH or LOW as an output or an input 
 * and you can use numbers 0 or 1, otherwise you can use the 
 * macro directly for well-readability
 * 
 * Return: Void
***************************DIO_Port_Write**********************************/
void DIO_Port_Write (UGPIO_t* pGPIO, uint8_t portValue);


/***************************DIO_Port_Read**********************************
 * This function reads from the entire pinx registers
 * through reading the all pins as high pins or low pins
 * by using the structures, unions, and bit-fields method to access
 * the register.
 *
 * Inputs: (portName): This is a character. It must be one of 
 * these characters 'A', 'B', 'C', and 'D' as they represent the
 * name of the ports of the microcontroller.
 * 
 * (portValue): This pointer will store the state of the pinx
 * whether it's HIGH or LOW ( 0 or 1) by reading it totally
 * 
 * Return: Void
***************************DIO_Port_Read**********************************/
void DIO_Port_Read (uint8_t portName, uint8_t* portValue);
#endif	/* DIO_H */

