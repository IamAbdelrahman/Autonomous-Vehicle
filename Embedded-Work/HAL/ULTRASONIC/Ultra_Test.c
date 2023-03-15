#include <stdio.h>
#include <avr/delay.h>
#include "DIO.h"
#include "TIMER.h"
#include "ADC.h"
#include "IR.h"
#include "LED.h"
#include "ULTRASONIC.h"

int main() {
    float distance_value = 0.0;
    Ultra_Trig_Init('D', 5);
    Ultra_Echo_Init('D', 6);
    LED_Init('C', 5);

    while (1) {
        Ultra_Trig_Start('D', 5);
        Ultra_Echo_Start();
        distance_value = Distance();
        if (distance_value == 5.0) {
            LED_On('C', 5);
        }
        else {
            LED_Off('C', 5);
        }
    }
}



