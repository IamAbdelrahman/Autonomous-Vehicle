#include "MOTORS.h"

void motor1Init(void) {
    DIO_Init_Pin('B', 0, OUT);
    DIO_Init_Pin('B', 1, OUT);
}

void motor2Init(void) {
    DIO_Init_Pin('B', 2, OUT);
    DIO_Init_Pin('B', 4, OUT);
}

void motor3Init(void) {
    DIO_Init_Pin('C', 0, OUT);
    DIO_Init_Pin('C', 1, OUT);
}

void motor4Init(void) {
    DIO_Init_Pin('C', 2, OUT);
    DIO_Init_Pin('C', 3, OUT);
}

void leftmotorsInit() {
    motor1Init();
    motor2Init();
}

void rightmotorsInit() {
    motor3Init();
    motor4Init();
}

void motorsInit(void) {
    /* Initialize All Motors*/
    leftmotorsInit();
    rightmotorsInit();
    /* Initialize Timer0 for PWM Generation */
    TIM0_Init();
    TIM0_Start();
    /* Initialize Sensors for controlling movement */
    lineTrackerInit('D', 1);
    /* Clearing The pins connected to Motors */
    DIO_Write_Pin('B', 0, LOW); // Motor1
    DIO_Write_Pin('B', 1, LOW);

    DIO_Write_Pin('B', 2, LOW); // Motor2
    DIO_Write_Pin('B', 4, LOW);

    DIO_Write_Pin('C', 0, LOW); // Motor3
    DIO_Write_Pin('C', 1, LOW);

    DIO_Write_Pin('C', 2, LOW); // Motor4
    DIO_Write_Pin('C', 3, LOW);
}

void motor1Forward() {
    DIO_Write_Pin('B', 0, HIGH);
    DIO_Write_Pin('B', 1, LOW);
}

void motor1Backward() {
    DIO_Write_Pin('B', 0, LOW);
    DIO_Write_Pin('B', 1, HIGH);
}

void motor1Stop() {
    DIO_Write_Pin('B', 0, LOW);
    DIO_Write_Pin('B', 1, LOW);
}

void motor2Forward() {
    DIO_Write_Pin('B', 2, HIGH);
    DIO_Write_Pin('B', 4, LOW);
}

void motor2Backward() {
    DIO_Write_Pin('B', 2, LOW);
    DIO_Write_Pin('B', 4, HIGH);
}

void motor2Stop() {
    DIO_Write_Pin('B', 2, LOW);
    DIO_Write_Pin('B', 4, LOW);
}

void motor3Forward() {
    DIO_Write_Pin('C', 0, HIGH);
    DIO_Write_Pin('C', 1, LOW);
}

void motor3Backward() {
    DIO_Write_Pin('C', 0, LOW);
    DIO_Write_Pin('C', 1, HIGH);
}

void motor3Stop() {
    DIO_Write_Pin('C', 0, LOW);
    DIO_Write_Pin('C', 1, LOW);
}

void motor4Forward() {
    DIO_Write_Pin('C', 2, HIGH);
    DIO_Write_Pin('C', 3, LOW);
}

void motor4Backward() {
    DIO_Write_Pin('C', 2, LOW);
    DIO_Write_Pin('C', 3, HIGH);
}

void motor4Stop() {
    DIO_Write_Pin('C', 2, LOW);
    DIO_Write_Pin('C', 3, LOW);
}

void leftMotorsForward() {
    motor1Forward();
    motor2Forward();
}

void leftMotorsBackward() {
    motor1Backward();
    motor2Backward();
}

void leftMotorsStop() {
    motor1Stop();
    motor2Stop();
}

void rightMotorsForward() {
    motor3Forward();
    motor4Forward();
}

void rightMotorsBackward() {
    motor3Backward();
    motor4Backward();
}

void rightMotorsStop() {
    motor3Stop();
    motor4Stop();
}

void motorsForward() {
    motor1Forward();
    motor2Forward();
    motor3Forward();
    motor4Forward();
}

void motorsBackward() {
    motor1Backward();
    motor2Backward();
    motor3Backward();
    motor4Backward();
}

void motorsStop() {
    motor1Stop();
    motor2Stop();
    motor3Stop();
    motor4Stop();
    TIM0_Stop();
}

void Stop() {
    motorsStop();
    _delay_ms(100);
}

/* Directions Functions */

void moveForward() {
    motorsForward();
}

void moveBackward() {
    motorsBackward();
}

void moveForwardRight() {
    rightMotorsStop();
    leftMotorsForward();
}

void moveBackwardRight() {
    leftMotorsStop();
    rightMotorsBackward();
}

void moveForwardLeft() {
    leftMotorsStop();
    rightMotorsForward();
}
void moveBackwardLeft() {
    rightMotorsStop();
    leftMotorsBackward();
}

void rotateForwardRight() {
    moveForwardRight();
    _delay_ms(750);
    Stop();
}

void rotateBackwardRight() {
    moveBackwardRight();
    _delay_ms(750);
    Stop();
}

void rotateForwardLeft() {
    moveForwardLeft();
    _delay_ms(750);
    Stop();
}

void rotateBackwardLeft() {
    moveBackwardLeft();
    _delay_ms(750);
    Stop();
}

void turnAroundForwardRight(){
    moveForwardRight();
    _delay_ms(1500);
    Stop();
}

void turnAroundBackwardRight(){
    moveBackwardRight();
    _delay_ms(1500);
    Stop();
}

void turnAroundForwardLeft(){
    moveForwardLeft();
    _delay_ms(1500);
    Stop();
}

void turnAroundBackwardLeft(){
    moveBackwardLeft();
    _delay_ms(1500);
    Stop();
}

void stopAtDistance(float distance_cm) {
    float d = Distance();
    if (d <= distance_cm) {
        Stop();
        _delay_ms(1000);
    }
}

uint8_t detectBlackLine () {
    uint8_t lineState = 1;
    lineTrackerRead('D', 1, &lineState);
    if (lineState == LOW) {
        return 1;
    }
    else if (lineState == HIGH) {
        return 0;
    }        
}

void goToRoom1() {
    moveForward();
    stopAtDistance(10);
}
void returnFromRoom1() {       
    turnAroundForwardRight();    
    moveForward();
    stopAtDistance(10);
    turnAroundForwardLeft();
}

void goToRoom2(){
    moveForward();
    if (detectBlackLine()){
       rotateForwardRight(); 
    }
    moveForward();
    stopAtDistance(20);
    rotateForwardLeft();
    moveForward();
    stopAtDistance(10);
    rotateForwardRight();    
}
void returnFromRoom2(){
    
}
void goToRoom3(void){
    rotateForwardRight();
    moveForward();
    stopAtDistance(10);    
}
void returnFromRoom3() {
    turnAroundForwardLeft();
    moveForward();
    stopAtDistance(10); 
    rotateForwardRight();    
}

void goToRoom1_2(void){
    goToRoom1();
    rotateForwardRight();
    moveForward();
    // rotateForwardLeft();
    stopAtDistance(10);
}
void goToRoom2_3(void){
    goToRoom2();
    rotateForwardRight();
    moveForward();
    stopAtDistance(10);
}
void goToRoom1_3(void){
    goToRoom1_2();
    rotateForwardRight();
    moveForward();
    stopAtDistance(10);    
}
void goToRoom1_2_3(void){
    goToRoom1_2();
    
}

void MOTOR_Speed(uint8_t speed) {
    if (speed > 0 && speed <= 100)
        PWM_Start(speed); // Fixed Speed.
    else
        PWM_Start(0);

}

void MOTOR_Variable_Speed() {
    PWM_Start(ADC_Read(ADC_CHANNEL3)); // Variable Speed.
}