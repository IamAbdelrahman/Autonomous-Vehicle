#include "BLUETOOTH.h"

void BLUETOOTH_Init(uint16_t Baud_Rate) {
    UART_Init(Baud_Rate);
}

void BLUETOOTH_Read(uint8_t Data_In) {
    Data_In = UART_ReceiveChar();
    if (Data_In == 'w' || Data_In == 'W' || Data_In == '1') {
        moveCar(MOVE_FORWARD);
    } else if (Data_In == 's' || Data_In == 'S' || Data_In == '2') {
        moveCar(MOVE_BACKWARD);
    } else if (Data_In == 'd' || Data_In == 'D' || Data_In == '3') {
        rotateCar(TURN_FORWARD_RIGHT, 90);
    } else if (Data_In == 'a' || Data_In == 'A' || Data_In == '4') {
        rotateCar(TURN_FORWARD_LEFT, 90);
    } else if (Data_In == 'x' || Data_In == 'X' || Data_In == '0') {
        motorsState(STOP);
    }
}

void roomMode() {
    ;
}
