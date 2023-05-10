#include "MOTORS.h"

void motorsInit(EN_motor_t m) {
    switch (m) {
        case MOTOR1:
            DIO_Init_Pin('B', 0, OUT);
            DIO_Init_Pin('B', 1, OUT);
            break;
        case MOTOR2:
            DIO_Init_Pin('B', 0, OUT);
            DIO_Init_Pin('B', 1, OUT);
            break;
        case MOTOR3:
            DIO_Init_Pin('B', 2, OUT);
            DIO_Init_Pin('B', 4, OUT);
            break;
        case MOTOR4:
            DIO_Init_Pin('B', 2, OUT);
            DIO_Init_Pin('B', 4, OUT);
            break;
        case LEFT_MOTORS:
            DIO_Init_Pin('B', 0, OUT);
            DIO_Init_Pin('B', 1, OUT);
            break;
        case RIGHT_MOTORS:
            DIO_Init_Pin('B', 2, OUT);
            DIO_Init_Pin('B', 4, OUT);
            break;
        case MOTORS:
            DIO_Init_Pin('B', 0, OUT);
            DIO_Init_Pin('B', 1, OUT);
            DIO_Init_Pin('B', 2, OUT);
            DIO_Init_Pin('B', 4, OUT);

        default:
            break;
    }
    TIM0_Init();
    TIM0_Start();
    /* Initialize Sensors for controlling movement */
    lineTrackerInit('D', 1);
    /* Clearing The pins connected to Motors */
    DIO_Write_Pin('B', 0, LOW); // Motor 1 - Motor 2
    DIO_Write_Pin('B', 1, LOW);
    DIO_Write_Pin('B', 2, LOW); // Motor 3 - Motor 4
    DIO_Write_Pin('B', 4, LOW);
}

void motorsState(EN_motorsState_t state) {
    switch (state) {
        case LEFT_MOTORS_FORWARD:
            DIO_Write_Pin('B', 0, HIGH);
            DIO_Write_Pin('B', 1, LOW);
            break;
        case RIGHT_MOTORS_FORWARD:
            DIO_Write_Pin('B', 2, HIGH);
            DIO_Write_Pin('B', 4, LOW);
            break;
        case MOTORS_FORWARD:
            DIO_Write_Pin('B', 0, HIGH);
            DIO_Write_Pin('B', 1, LOW);
            DIO_Write_Pin('B', 2, HIGH);
            DIO_Write_Pin('B', 4, LOW);
            break;
        case LEFT_MOTORS_BACKWARD:
            DIO_Write_Pin('B', 0, LOW);
            DIO_Write_Pin('B', 1, HIGH);
            break;
        case RIGHT_MOTORS_BACKWARD:
            DIO_Write_Pin('B', 2, LOW);
            DIO_Write_Pin('B', 4, HIGH);
            break;
        case MOTORS_BACKWARD:
            DIO_Write_Pin('B', 0, LOW);
            DIO_Write_Pin('B', 1, HIGH);
            DIO_Write_Pin('B', 2, LOW);
            DIO_Write_Pin('B', 4, HIGH);
            break;
        case LEFT_MOTORS_STOP:
            DIO_Write_Pin('B', 0, LOW);
            DIO_Write_Pin('B', 1, LOW);
            break;
        case RIGHT_MOTORS_STOP:
            DIO_Write_Pin('B', 2, LOW);
            DIO_Write_Pin('B', 4, LOW);
            break;
        case STOP:
            DIO_Write_Pin('B', 0, LOW);
            DIO_Write_Pin('B', 1, LOW);
            DIO_Write_Pin('B', 2, LOW);
            DIO_Write_Pin('B', 4, LOW);
            TIM0_Stop();
            break;
        default:
            break;
    }
}

void moveCar(EN_directions_t direction) {
    switch (direction) {
        case MOVE_FORWARD:
            motorsState(MOTORS_FORWARD);
            break;
        case MOVE_BACKWARD:
            motorsState(MOTORS_BACKWARD);
            break;
        case MOVE_FORWARD_RIGHT:
            motorsState(RIGHT_MOTORS_STOP);
            motorsState(LEFT_MOTORS_FORWARD);
            break;
        case MOVE_BACKWARD_RIGHT:
            motorsState(LEFT_MOTORS_STOP);
            motorsState(RIGHT_MOTORS_BACKWARD);
            break;
        case MOVE_FORWARD_LEFT:
            motorsState(LEFT_MOTORS_STOP);
            motorsState(RIGHT_MOTORS_FORWARD);
            break;
        case MOVE_BACKWARD_LEFT:
            motorsState(RIGHT_MOTORS_STOP);
            motorsState(LEFT_MOTORS_BACKWARD);
            break;
    }
}

void degree(uint64_t deg) {
    switch (deg) {
        case 90:
            TURN_90;
            break;
        case 180:
            TURN_180;
            break;
        case 270:
            TURN_270;
            break;
        case 360:
            TURN_360;
            break;
        default:
            break;
    }
}

void rotateCar(EN_directions_t direction, uint64_t degreeValue) {
    switch (direction) {
        case TURN_FORWARD_RIGHT:
            moveCar(MOVE_FORWARD_RIGHT);
            degree(degreeValue);
            break;
        case TURN_FORWARD_LEFT:
            moveCar(MOVE_FORWARD_LEFT);
            degree(degreeValue);
            break;
        case TURN_BACKWARD_RIGHT:
            moveCar(MOVE_BACKWARD_RIGHT);
            degree(degreeValue);
            break;
        case TURN_BACKWARD_LEFT:
            moveCar(MOVE_BACKWARD_LEFT);
            degree(degreeValue);
            break;
        default:
            break;
    }
}

void stopAtDistance(float distance_cm) {
    float d = Distance();
    if (d <= distance_cm) {
        motorsState(STOP);
    }
}

uint8_t detectBlackLine() {
    uint8_t lineState = 1;
    lineTrackerRead('D', 3, &lineState);
    if (lineState == LOW) {
        return 1;
    } else if (lineState == HIGH) {
        return 0;
    }
}

void goToRoom1() {
    moveCar(MOVE_FORWARD);
    stopAtDistance(10);
}

void goToRoom2() {
    moveCar(MOVE_FORWARD);
    if (detectBlackLine()) {
        rotateCar(TURN_FORWARD_RIGHT, 90);
    }
    moveCar(MOVE_FORWARD);
    stopAtDistance(20);
    rotateCar(TURN_FORWARD_LEFT, 90);
    moveCar(MOVE_FORWARD);
    stopAtDistance(10);
    rotateCar(TURN_FORWARD_RIGHT, 90);
}

void goToRoom3(void) {
    rotateCar(TURN_FORWARD_RIGHT, 90);
    moveCar(MOVE_FORWARD);
    stopAtDistance(10);
}

void goToRoom1_2(void) {
    rotateCar(TURN_FORWARD_RIGHT, 90);
    moveCar(MOVE_FORWARD);
    rotateCar(TURN_FORWARD_LEFT, 90);
    stopAtDistance(10);
}

void goToRoom2_3(void) {
    rotateCar(TURN_FORWARD_RIGHT, 90);
    moveCar(MOVE_FORWARD);
    stopAtDistance(10);
}

void goToRoom1_3(void) {
    rotateCar(TURN_FORWARD_RIGHT, 90);
    moveCar(MOVE_FORWARD);
    stopAtDistance(10);
}

void goToRoom1_2_3(void) {
    goToRoom1_2();
    goToRoom2_3();
}

void returnFromRoom1() {
    rotateCar(TURN_FORWARD_RIGHT, 180);
    moveCar(MOVE_FORWARD);
    stopAtDistance(10);
    rotateCar(TURN_FORWARD_LEFT, 180);
}

void returnFromRoom2() {
    ;
}

void returnFromRoom3() {
    rotateCar(TURN_FORWARD_LEFT, 180);
    moveCar(MOVE_FORWARD);
    stopAtDistance(10);
    rotateCar(TURN_FORWARD_RIGHT, 90);
}

void motorSpeed(uint8_t speed) {
    if (speed > 0 && speed <= 100)
        PWM_Start(speed); // Fixed Speed.
    else
        PWM_Start(0);

}

void motorVariableSpeed() {
    PWM_Start(ADC_Read(ADC_CHANNEL3)); // Variable Speed.
}
