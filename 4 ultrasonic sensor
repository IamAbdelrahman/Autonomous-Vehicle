#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRIG1_PIN PB0 // Trigger pin for sensor 1
#define ECHO1_PIN PB1 // Echo pin for sensor 1
#define TRIG2_PIN PB2 // Trigger pin for sensor 2
#define ECHO2_PIN PB3 // Echo pin for sensor 2
#define TRIG3_PIN PB4 // Trigger pin for sensor 3
#define ECHO3_PIN PB5 // Echo pin for sensor 3
#define TRIG4_PIN PB6 // Trigger pin for sensor 4
#define ECHO4_PIN PB7 // Echo pin for sensor 4

volatile uint16_t pulse_width1 = 0; // Pulse width for sensor 1
volatile uint16_t pulse_width2 = 0; // Pulse width for sensor 2
volatile uint16_t pulse_width3 = 0; // Pulse width for sensor 3
volatile uint16_t pulse_width4 = 0; // Pulse width for sensor 4

ISR(TIMER1_CAPT_vect) {
    // Check which sensor triggered the interrupt and capture the pulse width
    if (TCCR1B & (1 << ICES1)) {
        pulse_width1 = ICR1;
    } else if (TCCR1B & (1 << ICES1)) {
        pulse_width2 = ICR1;
    } else if (TCCR1B & (1 << ICES1)) {
        pulse_width3 = ICR1;
    } else {
        pulse_width4 = ICR1;
    }

    // Toggle the edge detection for the input capture
    TCCR1B ^= (1 << ICES1);
}

void init_sensor(uint8_t trig_pin, uint8_t echo_pin) {
    // Set up trigger and echo pins for the sensor
    DDRB |= (1 << trig_pin);
    DDRB &= ~(1 << echo_pin);

    // Initialize timer 1 for measuring the pulse width of the echo signal
    TCCR1B |= (1 << ICES1); // Set input capture to trigger on rising edge
    TCCR1B |= (1 << CS10); // Set prescaler to 1
    TIMSK1 |= (1 << ICIE1); // Enable input capture interrupt
    sei(); // Enable global interrupts
}

int main(void) {
    // Initialize all four sensors
    init_sensor(TRIG1_PIN, ECHO1_PIN);
    init_sensor(TRIG2_PIN, ECHO2_PIN);
    init_sensor(TRIG3_PIN, ECHO3_PIN);
    init_sensor(TRIG4_PIN, ECHO4_PIN);

    // Main loop
    while (1) {
        // Trigger each sensor in turn and wait for the echo signal
        PORTB |= (1 << TRIG1_PIN);
        _delay_us(10);
        PORTB &= ~(1 << TRIG1_PIN);
        _delay_ms(50);

        PORTB |= (1 << TRIG2_PIN);
        _delay_us(10);
        PORTB &= ~(1 << TRIG2_PIN);
        _delay_ms(50);

        PORTB |= (1 << TRIG3_PIN);
        _delay_us(10);
        PORTB &= ~(1 << TRIG3_PIN);
        _delay_ms(50);

        PORTB |= (1 << TRIG4_PIN);
        _delay_us(10);
        PORTB &= ~(1 << TRIG4_PIN);
        _delay_ms(50);

        // Wait for the interrupt to capture the pulse width for each sensor
        while (pulse_width1 == 0  pulse_width2 == 0  pulse_width3 == 0 || pulse_width4 == 0) {}

        // Calculate the distance for each sensor
        float distance1 = pulse_width1 * 0.01715;
        float distance2 = pulse_width2 * 0.01715;
        float distance3 = pulse_width3 * 0.01715;
        float distance4 = pulse_width4 * 0.01715;

        // Clear the pulse widths for the next loop
        pulse_width1 = 0;
        pulse_width2 = 0;
        pulse_width3 = 0;
        pulse_width4 = 0;

        // Print the distances for each sensor
        printf("Distance 1: %.2f cm\n", distance1);
        printf("Distance 2: %.2f cm\n", distance2);
        printf("Distance 3: %.2f cm\n", distance3);
        printf("Distance 4: %.2f cm\n", distance4);
    }
}
