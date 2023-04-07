#include "LINE_TRACKER.h"

void lineTracker_Init(uint8_t portName, uint8_t pinNumber) {
    DIO_Init_Pin(portName, pinNumber, IN);
}

void lineTracker_Read(uint8_t portName, uint8_t pinNumber, uint8_t* State) {
    DIO_Read_Pin(portName, pinNumber, State);
}


