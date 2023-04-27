/* 
 * File:   Macros.h
 * Author: ak
 *
 * Created on April 26, 2023, 8:15 AM
 */

#ifndef MACROS_H
#define	MACROS_H
#include "Platform_Types.h"

#define F_CPU  16000000UL
#define SET_BIT(X, BIT_NO)      (X |= (1 << BIT_NO))
#define CLR_BIT(X, BIT_NO)      (X &= ~(1 << BIT_NO))
#define TOGGLE_BIT(X, BIT_NO)   (X ^= (1 << BIT_NO))
#define READ_BIT(X, BIT_NO)     ((X & (1 << BIT_NO)) >> BIT_NO)
#define CHECK_BIT(X, BIT_NO)    ((X & (1 << BIT_NO)))

#define IN 0
#define OUT 1

#define HIGH 1
#define LOW 0


#endif	/* MACROS_H */

