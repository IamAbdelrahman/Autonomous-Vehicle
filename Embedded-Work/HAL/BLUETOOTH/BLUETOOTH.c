#include "BLUETOOTH.h"

void BLUETOOTH_Init(void) {
    USART_Init(USART_BAUDRATE);
}

void BLUETOOTH_Read(uint8_t Data_In) {
    Data_In = USART_Receive();
    USART_Transmit(Data_In);
    if (Data_In == 'w' || Data_In == 'W' || Data_In == '1') {
        Move_Forward();
    } else if (Data_In == 's' || Data_In == 'S' || Data_In == '2') {
        Move_Backward();
    } else if (Data_In == 'd' || Data_In == 'D' || Data_In == '3') {
        Turn_Right();
    } else if (Data_In == 'a' || Data_In == 'A' || Data_In == '4') {
        Turn_Left();
    } else if (Data_In == 'x' || Data_In == 'X' || Data_In == '0') {
        MOTORS_Stop();
    }
}
