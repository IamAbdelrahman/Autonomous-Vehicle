#include <stdio.h>
#include <avr/delay.h>
#include "DIO.h"
#include "LED.h"
#include "BUTTON.h"
int main() {
    uint8_t button_state;
    BUTTON_Init('B', 0);
    LED_Init('C', 0);
    while (1) {
        BUTTON_Read('B', 0, &button_state);
        if (button_state == HIGH) {
            LED_On('C', 0);
        } else if (button_state == LOW) {
            LED_Off('C', 0);
        }
    }
}


// avrdude -c usbasp -p m32 -u -U flash:w:Button_Test.hex
