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
#include <avr/delay.h>
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
 
#define ADDRESS_PORTA   (UGPIO_t*)PORT_A
#define ADDRESS_DDRA    (UGPIO_t*)DDR_A
#define ADDRESS_PINA    (UGPIO_t*)PIN_A

#define ADDRESS_PORTB   (UGPIO_t*)PORT_B
#define ADDRESS_DDRB    (UGPIO_t*)DDR_B
#define ADDRESS_PINB    (UGPIO_t*)PIN_B

#define ADDRESS_PORTC   (UGPIO_t*)PORT_C
#define ADDRESS_DDRC    (UGPIO_t*)DDR_C
#define ADDRESS_PINC    (UGPIO_t*)PIN_C

#define ADDRESS_PORTD   (UGPIO_t*)PORT_D
#define ADDRESS_DDRD    (UGPIO_t*)DDR_D
#define ADDRESS_PIND    (UGPIO_t*)PIN_D
   
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
/*________________________________________________________________________________
________________________________________________________________________________*/

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
/*________________________________________________________________________________
________________________________________________________________________________*/

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
/*________________________________________________________________________________
________________________________________________________________________________*/

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
/*________________________________________________________________________________
________________________________________________________________________________*/

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
extern void DIO_Port_Init (UGPIO_t* pGPIO, uint8_t portDirection);
/*________________________________________________________________________________
________________________________________________________________________________*/

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
/*________________________________________________________________________________
________________________________________________________________________________*/

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
/*________________________________________________________________________________
________________________________________________________________________________*/

/***************************DDRX_Out/In**********************************
 * This function can make the whole register to be data in or data out
 * through calling the DIO_Port_Init().
 *
 * Inputs: It takes nothing
 * 
 * Return: Void
***************************DDRX_Out/In**********************************/
void DDRA_Out(void);
void DDRA_In(void);
void DDRB_Out(void);
void DDRB_In(void);
void DDRC_Out(void);
void DDRC_In(void);
void DDRD_Out(void);
void DDRD_In(void);
/*________________________________________________________________________________
________________________________________________________________________________*/

/***************************PORTX_High/Low**********************************
 * This function can make the whole register(port) to be high or low
 * through calling the DIO_Port_Write().
 *
 * Inputs: It takes nothing
 * 
 * Return: Void
***************************PORTX_High/Low**********************************/
void PORTA_High(void);
void PORTA_Low(void);
void PORTB_High(void);
void PORTB_Low(void);
void PORTC_High(void);
void PORTC_Low(void);
void PORTD_High(void);
void PORTD_Low(void);
/*________________________________________________________________________________
________________________________________________________________________________*/


#endif	/* DIO_H */
