#include <stdio.h>
#include <avr/delay.h>
#include "DIO.h"
#include "TIMER.h"
#include "ADC.h"
#include "IR.h"
#include "LED.h"
#include "ULTRASONIC.h"
#include "MOTOR.h"

int main() {
    MOTORS_Init();
    MOTOR_Speed();
    while (1) {
        Move_Forward();

    }
}


// avrdude -c usbasp -p m32 -u -U flash:w:Motors_Test
.hex
