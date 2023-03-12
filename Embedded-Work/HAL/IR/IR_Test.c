#include <stdio.h>
#include <avr/delay.h>
#include "DIO.h"
#include "TIMER.h"
#include "ADC.h"
#include "IR.h"
#include "LED.h"

int main() {

    uint8_t IR_Value = 0;
    IR_Config();
    IR_Init('A', 0);
    LED_init('D', 0); // Led1
    LED_init('D', 1); // Led2
    DIO_Init_Pin('D', 2, OUT); // Buzzer

    while (1) {
        IR_Value = IR_Read('A', 0);
        if (IR_Value > 0) {
            LED_on('D', 0); // Led1 on
            LED_off('D', 1); // Led2 off
            DIO_Init_Pin('D', 2, LOW); // Buzzer off
        }
        else if (IR_Value == 0) {
            LED_off('D', 0); // Led1 off
            LED_on('D', 1); // Led2 on
            DIO_Init_Pin('D', 2, HIGH); // Buzzer on
        }
    }
}

