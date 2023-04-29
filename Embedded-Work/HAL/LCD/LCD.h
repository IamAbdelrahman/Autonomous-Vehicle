/* 
 * File:   LCD.h
 * Author: ak
 *
 * Created on April 29, 2023, 7:06 AM
 */

#ifndef LCD_H
#define	LCD_H
#include "Registers.h"

#define LCD_Data_Dir DDRB		    /* Define LCD data port direction */
#define LCD_Command_Dir DDRC		/* Define LCD command port direction register */
#define LCD_Data_Port PORTB		    /* Define LCD data port */
#define LCD_Command_Port PORTC		/* Define LCD data port */
#define RS 0                      /* Define Register Select (data/command reg.)pin */
#define RW 1                      /* Define Read/Write signal pin */
#define EN 2                      /* Define Enable signal pin */

void LCD_Command(uint8_t cmnd);
void LCD_Char (uint8_t char_data);
void LCD_Init (void);
void LCD_String (char *str);
void LCD_String_xy (char row, char pos, char *str);
void LCD_Clear();
#endif	/* LCD_H */

