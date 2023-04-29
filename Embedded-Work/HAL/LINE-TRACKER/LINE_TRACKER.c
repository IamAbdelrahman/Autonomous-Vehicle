#include "LINE_TRACKER.h"

void lineTrackerInit(uint8_t portName, uint8_t pinNumber) {
    DIO_Init_Pin(portName, pinNumber, IN);
}

void lineTrackerRead(uint8_t portName, uint8_t pinNumber, uint8_t* State) {
    DIO_Read_Pin(portName, pinNumber, State);
}
