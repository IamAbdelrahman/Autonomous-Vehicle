#include "IR.h"
/* Start of Code 1 */
ST_ADC_config_t S_IR1 = {ADC_CHANNEL4, AVCC_ON, RIGHT_JUSTIFIED, DIVISION_FACTOR_128};
//ST_ADC_config_t S_IR2 = {ADC_CHANNEL1, AVCC_ON, RIGHT_JUSTIFIED, DIVISION_FACTOR_128};
//ST_ADC_config_t S_IR3 = {ADC_CHANNEL2, AVCC_ON, RIGHT_JUSTIFIED, DIVISION_FACTOR_128};
//ST_ADC_config_t S_IR4 = {ADC_CHANNEL3, AVCC_ON, RIGHT_JUSTIFIED, DIVISION_FACTOR_128};

void IR_Config(void) {
    ADC_Config(&S_IR1);
    // ADC_Config(&S_IR1);
    // ADC_Config(&S_IR1);
    // ADC_Config(&S_IR1);
    
}

void IR_Init(uint8_t portName, uint8_t pinNumber) {
    ADC_Init(portName, pinNumber);
    IR_Config();
}

uint8_t IR_Read(uint8_t portName, uint8_t pinNumber) {
    return ADC_Read(pinNumber);
}
/* End of Code 1 */

/*****************************************************************/

/* Start of Code 2 */
void IR_init(uint8_t portName, uint8_t pinNumber){
    DIO_Init_Pin(portName, pinNumber, IN);
}
void IR_read (uint8_t portName, uint8_t pinNumber, uint8_t* State){
    DIO_Read_Pin(portName, pinNumber, State);
}

/* End of Code 2 */
