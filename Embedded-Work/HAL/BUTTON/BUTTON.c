#include "BUTTON.h"

void BUTTON_Init(uint8_t buttonPort, uint8_t buttonPin) {
    DIO_Init_Pin(buttonPort, buttonPin, IN);
}

void BUTTON_Read(uint8_t buttonPort, uint8_t buttonPin, uint8_t* value) {
    DIO_Read_Pin(buttonPort, buttonPin, value);
}

