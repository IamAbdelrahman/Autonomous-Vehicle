#include <avr/io.h>
#include <util/delay.h>

#define TRIG_PIN PB0 // Trigger pin
#define ECHO_PIN PB1 // Echo pin

int main(void) {
    // Set up TRIG_PIN as output and ECHO_PIN as input
    DDRB |= (1 << TRIG_PIN);
    DDRB &= ~(1 << ECHO_PIN);

    // Initialize timer 1 for measuring the pulse width of the echo signal
    TCCR1B |= (1 << ICES1); // Set input capture to trigger on rising edge
    TCCR1B |= (1 << CS10); // Set prescaler to 1
    TIMSK1 |= (1 << ICIE1); // Enable input capture interrupt
    sei(); // Enable global interrupts

    // Main loop
    while (1) {
        // Send a 10us pulse on the TRIG_PIN to trigger the sensor
        PORTB |= (1 << TRIG_PIN);
        _delay_us(10);
        PORTB &= ~(1 << TRIG_PIN);

        // Wait for the ECHO_PIN to go high
        while (!(PINB & (1 << ECHO_PIN)));

        // Start timer 1
        TCNT1 = 0;

        // Wait for the ECHO_PIN to go low
        while (PINB & (1 << ECHO_PIN));

        // Calculate the pulse width and convert to distance in cm
        float pulse_width = (float)ICR1 * 0.0625; // Each tick of the timer represents 62.5ns
        float distance_cm = pulse_width / 58.0; // Speed of sound is approximately 340 m/s

        // Do something with the distance value
    }
}

ISR(TIMER1_CAPT_vect) {
    // Clear input capture flag
    TIFR1 |= (1 << ICF1);
}
