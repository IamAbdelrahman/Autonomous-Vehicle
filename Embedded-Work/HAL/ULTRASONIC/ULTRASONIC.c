#include "ULTRASONIC.h"
uint16_t pulse_width;
uint64_t distance;

void Ultra_Trig_Init(uint8_t portName, uint8_t pinNumber)
{
    DIO_Init_Pin(portName, pinNumber, OUT);
}

void Ultra_Echo_Init(uint8_t portName, uint8_t pinNumber)
{
    DIO_Init_Pin(portName, pinNumber, IN);   
}

void Ultra_Init(void)
{
    Ultra_Trig_Init('B', 5);
    Ultra_Echo_Init('D', 6);
    TIM1_Init();
    TIM1_Start();
    pTCCR1B->Timer1B.ICES1 = 1;
    pTIMSK->TIMSK_Reg.TICIE1 = 1;
}

void Ultra_Trig_Start(uint8_t portName, uint8_t pinNumber)
{
    DIO_Write_Pin(portName, pinNumber, HIGH);
    _delay_us(10);
    DIO_Write_Pin(portName, pinNumber, LOW);
}

void Ultra_Echo_Start(uint8_t portName, uint8_t pinNumber)
{
    
}








/*

        // Wait for the ECHO_PIN to go high
        while (!(PINB & (1 << ECHO_PIN)));
 // Start Timer1
        // Wait for the ECHO_PIN to go low
        while (PINB & (1 << ECHO_PIN));

        // Calculate the pulse width and convert to distance in cm
        float pulse_width = (float)ICR1 * 0.0625; // Each tick of the timer represents 62.5ns
        float distance_cm = pulse_width / 58.0; // Speed of sound is approximately 340 m/s
 * 
ISR(TIMER1_CAPT_vect) {
    // Clear input capture flag
    TIFR1 |= (1 << ICF1);
}

ISR(TIMER1_CAPT_vect) {
    // Check which sensor triggered the interrupt and capture the pulse width
    if (TCCR1B & (1 << ICES1)) {
        pulse_width1 = ICR1;
 
    // Toggle the edge detection for the input capture
    TCCR1B ^= (1 << ICES1);
}
    // Initialize timer 1 for measuring the pulse width of the echo signal
    TCCR1B |= (1 << ICES1); // Set input capture to trigger on rising edge
    TCCR1B |= (1 << CS10); // Set prescaler to 1
    TIMSK1 |= (1 << ICIE1); // Enable input capture interrupt
    sei(); // Enable global interrupts
}

    // Initialize all four sensors
    init_sensor(TRIG1_PIN, ECHO1_PIN);

        // Wait for the interrupt to capture the pulse width for each sensor
        while (pulse_width1 == 0  pulse_width2 == 0  pulse_width3 == 0 || pulse_width4 == 0) {}

        // Calculate the distance for each sensor
        float distance1 = pulse_width1 * 0.01715;
*/