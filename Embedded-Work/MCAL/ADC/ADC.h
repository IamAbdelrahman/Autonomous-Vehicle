/* 
 * File:   ADC.h
 * Author: ak
 *
 * Created on February 27, 2023, 7:14 PM
 */

#ifndef ADC_h
#define	ADC_h
#include "DIO.h"
#include "TIMER.h"

/* ADC Calculations */
#define VREF    5
#define ADC_STEP    VREF / 256.0

/* ADC Registers */
#define ADMUX   (*(vuint8_t*)0x27)
#define AD_MUX  0x27

#define ADCSRA  *((vuint8_t*)0x26)
/* ADCSRA Bits Configuration*/
#define ADPS0   0
#define ADPS1   1
#define ADPS2   2
#define ADIE    3
#define ADIF    4
#define ADATE   5
#define ADSC    6
#define ADEN    7

#define ADCH    *(vuint16_t*)0x25
#define ADC_H   0x25

#define ADCL    *(vuint16_t*)0x24
#define ADC_L   0x24

/* ADC Configurations */
#define ADC_CHANNEL0    0
#define ADC_CHANNEL1    1
#define ADC_CHANNEL2    2
#define ADC_CHANNEL3    3
#define ADC_CHANNEL4    4
#define ADC_CHANNEL5    5
#define ADC_CHANNEL6    6
#define ADC_CHANNEL7    7

#define AREFF_OFF       8
#define AVCC_ON         9
#define AREFF_ON        10

#define LEFT_JUSTIFIED  11
#define RIGHT_JUSTIFIED  12

/* ADC Prescaler Selections */
#define DIVISION_FACTOR_2    1
#define DIVISION_FACTOR_4    2
#define DIVISION_FACTOR_8    3
#define DIVISION_FACTOR_16   4
#define DIVISION_FACTOR_32   5
#define DIVISION_FACTOR_64   6
#define DIVISION_FACTOR_128  7

/* Structures of the Registers Bits */
typedef struct{
    
    vuint8_t MUX0 :1;
    vuint8_t MUX1 :1;
    vuint8_t MUX2 :1;
    vuint8_t MUX3 :1;
    vuint8_t MUX4 :1;
    vuint8_t ADLAR:1;
    vuint8_t REFS0:1;
    vuint8_t REFS1:1;
    
}ST_ADMUX;

typedef union{
    
    vuint8_t All_Bits;
    ST_ADMUX ADC_MUX;
    
}U_ADMUX;

typedef struct{
    
    vuint8_t ADC_Channel;
    vuint8_t Reference_Selection;
    vuint8_t Adjust_Result;
    vuint8_t ADC_Start_Prescalar;
    
}ST_ADC_config_t;

#define ADDRESS_ADMUX   (U_ADMUX*)AD_MUX

void ADC_Config(ST_ADC_config_t* pADC);
void ADC_Enalbe(void);
void ADC_Init (uint8_t portName, uint8_t pinNumber);
uint8_t ADC_Read(void); 

#endif	/* ADC_h */

