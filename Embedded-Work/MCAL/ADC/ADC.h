/* 
 * File:   ADC.h
 * Author: ak
 *
 * Created on February 27, 2023, 7:14 PM
 */

#ifndef ADC_h
#define	ADC_h
#include "Platform_Types.h"
#include "Registers.h"
#include "DIO.h"
#include "TIMER.h"

/* ADC Registers */
#define ADMUX   *(vuint8_t*)0x27
#define AD_MUX  0x27

#define ADCSRA  *(vuint8_t*)0x26
#define ADC_SRA 0x26

#define ADCH    *(vuint16_t*)0x25
#define ADC_H   0x25

#define ADCL    *(vuint16_t*)0x24
#define ADC_L   0x24

#define SFIOR   *(vuint8_t*)0x50
#define SFIOR_R 0x50

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
    
    vuint8_t ADPS0 :1;
    vuint8_t ADPS1 :1;
    vuint8_t ADPS2 :1;
    vuint8_t ADIE  :1;
    vuint8_t ADIF  :1;
    vuint8_t ADATE :1;
    vuint8_t ADSC  :1;
    vuint8_t ADEN  :1;
    
}ST_ADCSRA;

typedef union{
    
    vuint8_t All_Bits;
    ST_ADCSRA ADC_ADCSRA;
    
}U_ADCSRA;

#define ADDRESS_ADMUX   (U_ADMUX*)AD_MUX
#define ADDRESS_ADCSRA  (U_ADCSRA*)ADC_SRA


#endif	/* ADC_h */

