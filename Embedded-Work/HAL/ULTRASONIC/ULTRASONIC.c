/*
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
    }
}
*/