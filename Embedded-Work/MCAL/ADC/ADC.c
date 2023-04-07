#include "ADC.h"

ST_ADC_config_t S_ADC_config = {ADC_CHANNEL3, AVCC_ON, RIGHT_JUSTIFIED, DIVISION_FACTOR_128};
volatile U_ADMUX * const pADMUX = ADDRESS_ADMUX;

void ADC_Config(ST_ADC_config_t* pADC) {
    if (pADC->Adjust_Result == RIGHT_JUSTIFIED) {
        pADMUX->ADC_MUX.ADLAR = 0;

        /* Start of Choosing the Pre-scaler */
        if (pADC->ADC_Start_Prescalar == DIVISION_FACTOR_2) {
            CLR_BIT(ADCSRA, ADPS0);
            CLR_BIT(ADCSRA, ADPS1);
            CLR_BIT(ADCSRA, ADPS2);
        } else if (pADC->ADC_Start_Prescalar == DIVISION_FACTOR_4) {
            CLR_BIT(ADCSRA, ADPS0);
            SET_BIT(ADCSRA, ADPS1);
            CLR_BIT(ADCSRA, ADPS2);
        } else if (pADC->ADC_Start_Prescalar == DIVISION_FACTOR_8) {
            SET_BIT(ADCSRA, ADPS0);
            SET_BIT(ADCSRA, ADPS1);
            CLR_BIT(ADCSRA, ADPS2);
        } else if (pADC->ADC_Start_Prescalar == DIVISION_FACTOR_16) {
            CLR_BIT(ADCSRA, ADPS0);
            CLR_BIT(ADCSRA, ADPS1);
            SET_BIT(ADCSRA, ADPS2);
        } else if (pADC->ADC_Start_Prescalar == DIVISION_FACTOR_32) {
            SET_BIT(ADCSRA, ADPS0);
            CLR_BIT(ADCSRA, ADPS1);
            SET_BIT(ADCSRA, ADPS2);
        } else if (pADC->ADC_Start_Prescalar == DIVISION_FACTOR_64) {
            CLR_BIT(ADCSRA, ADPS0);
            SET_BIT(ADCSRA, ADPS1);
            SET_BIT(ADCSRA, ADPS2);
        } else if (pADC->ADC_Start_Prescalar == DIVISION_FACTOR_128) {
            SET_BIT(ADCSRA, ADPS0);
            SET_BIT(ADCSRA, ADPS1);
            SET_BIT(ADCSRA, ADPS2);
        }
        /* End of Choosing the Pre-scaler*/

        /* Start of determining the reference selection */
        if (pADC->Reference_Selection == AVCC_ON) {
            pADMUX->ADC_MUX.REFS0 = 1;
            pADMUX->ADC_MUX.REFS1 = 0;
        } else if (pADC->Reference_Selection == AREFF_OFF) {
            pADMUX->ADC_MUX.REFS0 = 0;
            pADMUX->ADC_MUX.REFS1 = 0;
        } else if (pADC->Reference_Selection == AREFF_ON) {
            pADMUX->ADC_MUX.REFS0 = 1;
            pADMUX->ADC_MUX.REFS1 = 1;
        }
        /* End of determining the reference selection */

        /* Start of determining the ADC channel*/
        if (pADC->ADC_Channel == ADC_CHANNEL0) {
            pADMUX->ADC_MUX.MUX0 = 0;
            pADMUX->ADC_MUX.MUX1 = 0;
            pADMUX->ADC_MUX.MUX2 = 0;
            pADMUX->ADC_MUX.MUX3 = 0;
            pADMUX->ADC_MUX.MUX4 = 0;
        } else if (pADC->ADC_Channel == ADC_CHANNEL1) {
            pADMUX->ADC_MUX.MUX0 = 1;
            pADMUX->ADC_MUX.MUX1 = 0;
            pADMUX->ADC_MUX.MUX2 = 0;
            pADMUX->ADC_MUX.MUX3 = 0;
            pADMUX->ADC_MUX.MUX4 = 0;
        } else if (pADC->ADC_Channel == ADC_CHANNEL2) {
            pADMUX->ADC_MUX.MUX0 = 0;
            pADMUX->ADC_MUX.MUX1 = 1;
            pADMUX->ADC_MUX.MUX2 = 0;
            pADMUX->ADC_MUX.MUX3 = 0;
            pADMUX->ADC_MUX.MUX4 = 0;
        } else if (pADC->ADC_Channel == ADC_CHANNEL3) {
            pADMUX->ADC_MUX.MUX0 = 1;
            pADMUX->ADC_MUX.MUX1 = 1;
            pADMUX->ADC_MUX.MUX2 = 0;
            pADMUX->ADC_MUX.MUX3 = 0;
            pADMUX->ADC_MUX.MUX4 = 0;
        } else if (pADC->ADC_Channel == ADC_CHANNEL4) {
            pADMUX->ADC_MUX.MUX0 = 0;
            pADMUX->ADC_MUX.MUX1 = 0;
            pADMUX->ADC_MUX.MUX2 = 1;
            pADMUX->ADC_MUX.MUX3 = 0;
            pADMUX->ADC_MUX.MUX4 = 0;
        } else if (pADC->ADC_Channel == ADC_CHANNEL5) {
            pADMUX->ADC_MUX.MUX0 = 1;
            pADMUX->ADC_MUX.MUX1 = 0;
            pADMUX->ADC_MUX.MUX2 = 1;
            pADMUX->ADC_MUX.MUX3 = 0;
            pADMUX->ADC_MUX.MUX4 = 0;
        } else if (pADC->ADC_Channel == ADC_CHANNEL6) {
            pADMUX->ADC_MUX.MUX0 = 0;
            pADMUX->ADC_MUX.MUX1 = 1;
            pADMUX->ADC_MUX.MUX2 = 1;
            pADMUX->ADC_MUX.MUX3 = 0;
            pADMUX->ADC_MUX.MUX4 = 0;
        } else if (pADC->ADC_Channel == ADC_CHANNEL7) {
            pADMUX->ADC_MUX.MUX0 = 1;
            pADMUX->ADC_MUX.MUX1 = 1;
            pADMUX->ADC_MUX.MUX2 = 1;
            pADMUX->ADC_MUX.MUX3 = 0;
            pADMUX->ADC_MUX.MUX4 = 0;
        }
        /* End of determining the ADC channel*/

    } else if (pADC->Adjust_Result == LEFT_JUSTIFIED) {
        pADMUX->ADC_MUX.ADLAR = 1;

        /* Start of Choosing the Pre-scaler */
        if (pADC->ADC_Start_Prescalar == DIVISION_FACTOR_2) {
            CLR_BIT(ADCSRA, ADPS0);
            CLR_BIT(ADCSRA, ADPS1);
            CLR_BIT(ADCSRA, ADPS2);
        } else if (pADC->ADC_Start_Prescalar == DIVISION_FACTOR_4) {
            CLR_BIT(ADCSRA, ADPS0);
            SET_BIT(ADCSRA, ADPS1);
            CLR_BIT(ADCSRA, ADPS2);
        } else if (pADC->ADC_Start_Prescalar == DIVISION_FACTOR_8) {
            SET_BIT(ADCSRA, ADPS0);
            SET_BIT(ADCSRA, ADPS1);
            CLR_BIT(ADCSRA, ADPS2);
        } else if (pADC->ADC_Start_Prescalar == DIVISION_FACTOR_16) {
            CLR_BIT(ADCSRA, ADPS0);
            CLR_BIT(ADCSRA, ADPS1);
            SET_BIT(ADCSRA, ADPS2);
        } else if (pADC->ADC_Start_Prescalar == DIVISION_FACTOR_32) {
            SET_BIT(ADCSRA, ADPS0);
            CLR_BIT(ADCSRA, ADPS1);
            SET_BIT(ADCSRA, ADPS2);
        } else if (pADC->ADC_Start_Prescalar == DIVISION_FACTOR_64) {
            CLR_BIT(ADCSRA, ADPS0);
            SET_BIT(ADCSRA, ADPS1);
            SET_BIT(ADCSRA, ADPS2);
        } else if (pADC->ADC_Start_Prescalar == DIVISION_FACTOR_128) {
            SET_BIT(ADCSRA, ADPS0);
            SET_BIT(ADCSRA, ADPS1);
            SET_BIT(ADCSRA, ADPS2);
        }
        /* End of Choosing the Pre-scaler*/

        /* Start of determining the reference selection */
        if (pADC->Reference_Selection == AVCC_ON) {
            pADMUX->ADC_MUX.REFS0 = 1;
            pADMUX->ADC_MUX.REFS1 = 0;
        } else if (pADC->Reference_Selection == AREFF_OFF) {
            pADMUX->ADC_MUX.REFS0 = 0;
            pADMUX->ADC_MUX.REFS1 = 0;
        } else if (pADC->Reference_Selection == AREFF_ON) {
            pADMUX->ADC_MUX.REFS0 = 1;
            pADMUX->ADC_MUX.REFS1 = 1;
        }
        /* End of determining the reference selection */

        /* Start of determining the ADC channel*/
        if (pADC->ADC_Channel == ADC_CHANNEL0) {
            pADMUX->ADC_MUX.MUX0 = 0;
            pADMUX->ADC_MUX.MUX1 = 0;
            pADMUX->ADC_MUX.MUX2 = 0;
            pADMUX->ADC_MUX.MUX3 = 0;
            pADMUX->ADC_MUX.MUX4 = 0;
        } else if (pADC->ADC_Channel == ADC_CHANNEL1) {
            pADMUX->ADC_MUX.MUX0 = 1;
            pADMUX->ADC_MUX.MUX1 = 0;
            pADMUX->ADC_MUX.MUX2 = 0;
            pADMUX->ADC_MUX.MUX3 = 0;
            pADMUX->ADC_MUX.MUX4 = 0;
        } else if (pADC->ADC_Channel == ADC_CHANNEL2) {
            pADMUX->ADC_MUX.MUX0 = 0;
            pADMUX->ADC_MUX.MUX1 = 1;
            pADMUX->ADC_MUX.MUX2 = 0;
            pADMUX->ADC_MUX.MUX3 = 0;
            pADMUX->ADC_MUX.MUX4 = 0;
        } else if (pADC->ADC_Channel == ADC_CHANNEL3) {
            pADMUX->ADC_MUX.MUX0 = 1;
            pADMUX->ADC_MUX.MUX1 = 1;
            pADMUX->ADC_MUX.MUX2 = 0;
            pADMUX->ADC_MUX.MUX3 = 0;
            pADMUX->ADC_MUX.MUX4 = 0;
        } else if (pADC->ADC_Channel == ADC_CHANNEL4) {
            pADMUX->ADC_MUX.MUX0 = 0;
            pADMUX->ADC_MUX.MUX1 = 0;
            pADMUX->ADC_MUX.MUX2 = 1;
            pADMUX->ADC_MUX.MUX3 = 0;
            pADMUX->ADC_MUX.MUX4 = 0;
        } else if (pADC->ADC_Channel == ADC_CHANNEL5) {
            pADMUX->ADC_MUX.MUX0 = 1;
            pADMUX->ADC_MUX.MUX1 = 0;
            pADMUX->ADC_MUX.MUX2 = 1;
            pADMUX->ADC_MUX.MUX3 = 0;
            pADMUX->ADC_MUX.MUX4 = 0;
        } else if (pADC->ADC_Channel == ADC_CHANNEL6) {
            pADMUX->ADC_MUX.MUX0 = 0;
            pADMUX->ADC_MUX.MUX1 = 1;
            pADMUX->ADC_MUX.MUX2 = 1;
            pADMUX->ADC_MUX.MUX3 = 0;
            pADMUX->ADC_MUX.MUX4 = 0;
        } else if (pADC->ADC_Channel == ADC_CHANNEL7) {
            pADMUX->ADC_MUX.MUX0 = 1;
            pADMUX->ADC_MUX.MUX1 = 1;
            pADMUX->ADC_MUX.MUX2 = 1;
            pADMUX->ADC_MUX.MUX3 = 0;
            pADMUX->ADC_MUX.MUX4 = 0;
        }
        /* End of determining the ADC channel*/
    }
}

void ADC_Config_Pot(void) {
    ADC_Config(&S_ADC_config);
}

void ADC_Enable(void) {
    SET_BIT(ADCSRA, ADEN);
}

void ADC_Init(uint8_t portName, uint8_t pinNumber) {
    DIO_Init_Pin(portName, pinNumber, IN);
    ADC_Enable();
}

uint8_t ADC_Read(uint8_t pinNumber) {
    uint8_t digitalVoltageValue;
    ADMUX = 0x40 | (pinNumber & 0x0F);
    SET_BIT(ADCSRA, ADSC);
    while (READ_BIT(ADCSRA, ADIF) == 0);
    SET_BIT(ADCSRA, ADIF);
    _delay_ms(1);
    digitalVoltageValue = ADCL;
    return digitalVoltageValue;
}

