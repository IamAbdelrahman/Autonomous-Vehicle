
#ifndef INTERRUPT_H_
#define INTERRUPT_H_
#include "Registers.h"
#include "Platform_Types.h"

/* External Interrupt Request 0 */
#define EXT_INT_0 __vector_1
/* External Interrupt Request 1 */
#define EXT_INT_1 __vector_2
/* External Interrupt Request 2 */
#define EXT_INT_2 __vector_3
/* UART Receive Request */
#define USART_RXC __vector_13 

#define SREG    (*(vuint8_t*)0x5F)
#define GICR    (*(vuint8_t*)0x5B)
#define MCUCR   (*(vuint8_t*)0x55)
#define MCUCSR  (*(vuint8_t*)0x54)
#define GIFR	(*(vuint8_t*)0x5A)
#define TIMSK   (*(vuint8_t*)0x59)

#define INT0 	6
#define INT1 	7
#define INT2 	5

/* GIFR bits */
#define INTF1 7
#define INTF0 6
#define INTF2 5

// MCUCR
#define INTF0 6
#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3

// TIMSK bits
#define TOIE0 0
#define OCIE0 1
#define TOIE1 2
#define OCIE1B 3
#define OCIE1A 4
#define TICIE1 5
#define TOIE2 6
#define OCIE2 7

// MCUCSR
#define ISC2 6

// pin SREG enable interrupt
#define enable 7


// interrupt states
#define FALLING 0
#define RISING  1

/* Timer Interrupt Vector */

/* Set Global Interrupt, Set the I-bit in status register to 1 */
#define sei() __asm__ __volatile__ ("sei" ::: "memory")

/* Clear Global Interrupt, Set the I-bit in status register to 0 */
#define cli() __asm__ __volatile__ ("cli" ::: "memory")

/* ISR definition */
#define ISR(INT_VECT)void INT_VECT(void) __attribute__((signal,used));\
void INT_VECT(void)

/* Function Prototypes */
/* Using this function to enable Interrupt 0
 * INPUT : uint8_t --> FALLING OR RISING
 * RETURN OK OR ERROR OF EXCUTE */

/* Brief : Using this function to enable Interrupt
 * INTUPT : //
 * RETURN OK OR ERROR OF EXCUTE */
void Enable_INT(void);

/* Brief : Using this function to enable Interrupt 0
 * INTUPT : u8 --> FAILING OR RISING
 * RETURN OK OR ERROR OF EXCUTE */
void Enable_INT0 (uint8_t INT_STATE);

/* Brief : Using this function to enable Interrupt 1
 * INTUPT : u8 --> FAILING OR RISING
 * RETURN OK OR ERROR OF EXCUTE */
void Enable_INT1 (uint8_t INT_STATE);

/* Brief : Using this function to disable Interrupt 2
 * INTUPT : u8 --> FAILING OR RISING
 * RETURN OK OR ERROR OF EXCUTE */
void Enable_INT2 (uint8_t INT_STATE);

/* Brief : Using this function to disable Interrupt 0
 * INTUPT : //
 * RETURN OK OR ERROR OF EXCUTE */
void Disable_INT(void);

#endif /* INTERRUPT_H_ */