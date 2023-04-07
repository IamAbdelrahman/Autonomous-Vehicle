#include <stdio.h>
#include <avr/delay.h>
#include "DIO.h"
#include "TIMER.h"
#include "ADC.h"
#include "IR.h"
#include "LED.h"
#include "ULTRASONIC.h"
#include "MOTOR.h"
#include "IR.h"

int main() {
    uint8_t IR_state;
    IR_init('B', 0);
    LED_Init('C', 0);
    while (1) {
        IR_read('B', 0, &IR_state);
        if (IR_state == HIGH) {
            LED_On('C', 0); // Detect white object
        } else if (IR_state == LOW) {
            LED_Off('C', 0); // Detect black object
        }
    }
}


