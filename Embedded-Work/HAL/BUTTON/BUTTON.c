#include "BUTTON.h"

void BUTTON_Init(uint8_t portName, uint8_t pinNumber) {
    DIO_Init_Pin(portName, pinNumber, IN);
}

void BUTTON_Read(uint8_t portName, uint8_t pinNumber, uint8_t* value) {
    DIO_Read_Pin(portName, pinNumber, value);
}

