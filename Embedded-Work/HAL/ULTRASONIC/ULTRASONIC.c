#include "ULTRASONIC.h"

uint16_t pulse_width;
uint64_t distance_cm;

void Ultra_Trig_Init(uint8_t portName, uint8_t pinNumber) {
    DIO_Init_Pin(portName, pinNumber, OUT);
}

void Ultra_Echo_Init(uint8_t portName, uint8_t pinNumber) {
    DIO_Init_Pin(portName, pinNumber, IN);
}

void Ultra_Init(void) {
    Ultra_Trig_Init('C', 4);
    Ultra_Echo_Init('D', 6);
    TIM1_Init();
}

void Ultra_Trig_Start(uint8_t portName, uint8_t pinNumber) {
    DIO_Write_Pin(portName, pinNumber, HIGH);
    _delay_us(10);
    DIO_Write_Pin(portName, pinNumber, LOW);
}

void Ultra_Echo_Start() {
    TIM1_Start();
    SET_BIT(TCCR1B_R, 6);   // Rising Edge
    SET_BIT(TIFR_R, 5);     // Set ICF1
    SET_BIT(TIFR_R, 2);     // Set TOV1
    while (READ_BIT(TIFR_R, 5) == 0);
    TIM1_Start();
    CLR_BIT(TCCR1B_R, 6);   // Falling Edge
    SET_BIT(TIFR_R, 5);     // Set ICF1
    SET_BIT(TIFR_R, 2);     // Set TOV1
    while (READ_BIT(TIFR_R, 5) == 0);
}

float Distance() {
    float pulse_width = (float) ICR1L * 0.0625;
    float distance_cm = pulse_width / 58.0;
    return distance_cm;
}
