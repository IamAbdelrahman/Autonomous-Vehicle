#include "MOTOR.h"

void MOTOR1_Init(void) {
    DIO_Init_Pin('B', 0, OUT);
    DIO_Init_Pin('B', 1, OUT);
}

void MOTOR2_Init(void) {
    DIO_Init_Pin('B', 2, OUT);
    DIO_Init_Pin('B', 4, OUT);
}

void MOTOR3_Init(void) {
    DIO_Init_Pin('C', 0, OUT);
    DIO_Init_Pin('C', 1, OUT);
}

void MOTOR4_Init(void) {
    DIO_Init_Pin('C', 2, OUT);
    DIO_Init_Pin('C', 3, OUT);
}

void MOTORS_Left_Init()
{
    MOTOR1_Init();
    MOTOR2_Init();
}

void MOTORS_Right_Init()
{
    MOTOR3_Init();
    MOTOR4_Init();
}
void MOTORS_Init(void) {
    /* Initialize All Motors*/
    MOTORS_Left_Init();
    MOTORS_Right_Init();
    /* Initialize Timer0 for PWM Generation */
    TIM0_Init();
    TIM0_Start();

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

void MOTOR1_Clkwise() {
    DIO_Write_Pin('B', 0, HIGH);
    DIO_Write_Pin('B', 1, LOW);
}

void MOTOR2_Clkwise() {
    DIO_Write_Pin('B', 2, HIGH);
    DIO_Write_Pin('B', 4, LOW);
}

void MOTOR3_Clkwise() {
    DIO_Write_Pin('C', 0, HIGH);
    DIO_Write_Pin('C', 1, LOW);
}

void MOTOR4_Clkwise() {
    DIO_Write_Pin('C', 2, HIGH);
    DIO_Write_Pin('C', 3, LOW);
}

void MOTORS_Left_Clkwise()
{
    MOTOR1_Clkwise();
    MOTOR2_Clkwise();
    MOTOR_Speed();
}

void MOTORS_Right_Clkwise()
{
    MOTOR3_Clkwise();
    MOTOR4_Clkwise();
    MOTOR_Speed();
}

void MOTORS_Clkwise() {
    MOTOR1_Clkwise();
    MOTOR2_Clkwise();
    MOTOR3_Clkwise();
    MOTOR4_Clkwise();
    MOTOR_Speed();
}

void MOTOR1_Anticlkwise() {
    DIO_Write_Pin('B', 0, LOW);
    DIO_Write_Pin('B', 1, HIGH);
    MOTOR_Speed();
}

void MOTOR2_Anticlkwise() {
    DIO_Write_Pin('B', 2, LOW);
    DIO_Write_Pin('B', 4, HIGH);
    MOTOR_Speed();
}

void MOTOR3_Anticlkwise() {
    DIO_Write_Pin('C', 0, LOW);
    DIO_Write_Pin('C', 1, HIGH);
    MOTOR_Speed();
}

void MOTOR4_Anticlkwise() {
    DIO_Write_Pin('C', 2, LOW);
    DIO_Write_Pin('C', 3, HIGH);
    MOTOR_Speed();
}

void MOTORS_Left_Anticlkwise()
{
    MOTOR1_Anticlkwise();
    MOTOR2_Anticlkwise();
    MOTOR_Speed();
}

void MOTORS_Right_Anticlkwise()
{
    MOTOR3_Anticlkwise();
    MOTOR4_Anticlkwise();
    MOTOR_Speed();
}

void MOTORS_Anticlkwise() {
    MOTOR1_Anticlkwise();
    MOTOR2_Anticlkwise();
    MOTOR3_Anticlkwise();
    MOTOR4_Anticlkwise();
    MOTOR_Speed();
}

void MOTOR1_Stop() {
    DIO_Write_Pin('B', 0, LOW);
    DIO_Write_Pin('B', 1, LOW);
}

void MOTOR2_Stop() {
    DIO_Write_Pin('B', 2, LOW);
    DIO_Write_Pin('B', 4, LOW);
}

void MOTOR3_Stop() {
    DIO_Write_Pin('C', 0, LOW);
    DIO_Write_Pin('C', 1, LOW);
}

void MOTOR4_Stop() {
    DIO_Write_Pin('C', 2, LOW);
    DIO_Write_Pin('C', 3, LOW);
}

void MOTORS_Left_Stop()
{
    MOTOR1_Stop();
    MOTOR2_Stop();
}

void MOTORS_Right_Stop()
{
    MOTOR3_Stop();
    MOTOR4_Stop();
}
void MOTORS_Stop() {
    MOTOR1_Stop();
    MOTOR2_Stop();
    MOTOR3_Stop();
    MOTOR4_Stop();
    TIM0_Stop();
}

void Move_Forward() {
    MOTORS_Right_Anticlkwise();
    MOTORS_Left_Clkwise();
}

void Move_Backward() {
    MOTORS_Right_Clkwise();
    MOTORS_Left_Anticlkwise();
}

void Move_Right() {
    MOTORS_Right_Stop();
    MOTORS_Left_Anticlkwise();
}

void Move_Left() {
    MOTORS_Left_Stop();
    MOTORS_Right_Anticlkwise();
}

void MOTOR_Speed() {
    /* PWM_Start (50);  */ // Fixed Speed.
    PWM_Start(ADC_Read()); // Variable Speed.

}
