#include "LED.h"

void LED_Init(uint8_t ledport, uint8_t ledpin) {
    DIO_Init_Pin(ledport, ledpin, OUT);
}

void LED_On(uint8_t ledport, uint8_t ledpin) {
    DIO_Write_Pin(ledport, ledpin, HIGH);
}

void LED_Off(uint8_t ledport, uint8_t ledpin) {
    DIO_Write_Pin(ledport, ledpin, LOW);
}

void LED_Toggle(uint8_t ledport, uint8_t ledpin) {
    DIO_Toggle_Pin(ledport, ledpin);
}


