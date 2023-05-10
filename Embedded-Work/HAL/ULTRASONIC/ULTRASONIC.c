#include "ULTRASONIC.h"
uint16_t distance;
uint16_t pulse_width;
void Ultra_Trig_Init(uint8_t portName, uint8_t pinNumber) {
    DIO_Init_Pin(portName, pinNumber, OUT);
}

void Ultra_Echo_Init(uint8_t portName, uint8_t pinNumber) {
    DIO_Init_Pin(portName, pinNumber, IN);
    DIO_Init_Pin(portName, pinNumber, LOW);
}

void Ultra_Init(void) {
    Ultra_Trig_Init('C', 0);
    Ultra_Echo_Init('C', 1);
}

void Ultra_Trig_Start(uint8_t portName, uint8_t pinNumber) {
    DIO_Write_Pin(portName, pinNumber, HIGH);
    _delay_us(15);
    DIO_Write_Pin(portName, pinNumber, LOW);
}

void Ultra_Echo_Start() {
    TIM1_Set();
    SET_BIT(TCCR1B_R, 6);   // Rising Edge
    SET_BIT(TIFR_R, 5);     // Set ICF1
    SET_BIT(TIFR_R, 2);     // Set TOV1
    while (CHECK_BIT(TIFR_R, 5) == 0);
    TIM1_Set();
    CLR_BIT(TCCR1B_R, 6);   // Falling Edge
    SET_BIT(TIFR_R, 5);     // Set ICF1
    SET_BIT(TIFR_R, 2);     // Set TOV1
   // timerOvfCounter = 0;
    while (READ_BIT(TIFR_R, 5) == 0);
}

float Distance() {
    float pulse_width = (float) ICR1L * 0.0625;
    float distance_cm = pulse_width / 58.0;
    return distance_cm;
}


uint16_t GetUltrasonicDistance(void)
{
    // Configure Trigger Pin
    Ultra_Trig_Init('B', 0);

    // Configure Echo Pin
    Ultra_Echo_Init('B', 1);

    // Generate Trigger Pulse
    Ultra_Trig_Start('B', 0);

    // Wait for Echo Pulse
    uint16_t pulse_width = 0;
    while (!(PINB & (1 << ECHO_PIN))); // wait for the pulse to start
    TCNT1H = 0; // reset high byte of the counter
    TCNT1L = 0; // reset low byte of the counter
    while (PINB & (1 << ECHO_PIN)) // count the pulse width
    {
        if (TCNT1L > 23200) // max pulse width is 23200us
        {
            return 0; // return 0 if the pulse width is too long
        }
    }
    pulse_width = (TCNT1H << 8) | TCNT1L; // calculate the pulse width

    // Convert Pulse Width to Distance
    uint16_t distance_cm = pulse_width / 58; // calculate distance in cm
    return distance_cm;
}

uint16_t GetPulseWidth()
{
	uint32_t i, result;

	for(i=0;i < 600000;i++)
	{
		if(!(PINC & (1<<ECHO_PIN)))
		continue;	//Line is still low, so wait
		else
		break;		//High edge detected, so break.
	}

	if(i==600000)
	return US_ERROR;	//Indicates time out

	//Setup Timer1
	TCCR1A_Reg = 0X00;
	TCCR1B_Reg = (1<<1);
	TCNT1L=0x00;			

	for(i=0;i<600000;i++)               
	{
		if(PINC & (1<<ECHO_PIN))
		{
			if(TCNT1L > 60000) break; else continue;
		}
		else
		break;
	}

	if(i==600000)
	return US_NO_OBSTACLE;	

	result=TCNT1L;         
	
	//Stop Timer
	TCCR1B_Reg = 0x00;

	if(result > 60000)
	return US_NO_OBSTACLE;	//No obstacle
	else
	return (result>>1);
}

// ---------------------------------------------------------------------------------- //

/*
 * 
int TimerOverflow = 0;

ISR(TIMER1_OVF_vect)
{
	TimerOverflow++;	/* Increment Timer Overflow count 
}

int main(void)
{
	char string[10];
	long count;
	double distance;
	
	DDRA = 0x01;		/* Make trigger pin as output 
	PORTD = 0xFF;		/* Turn on Pull-up 
	
	LCD_Init();
	LCD_String_xy(1, 0, "Ultrasonic");
	
	sei();			/* Enable global interrupt 
	TIMSK = (1 << TOIE1);	/* Enable Timer1 overflow interrupts 
	TCCR1A = 0;		/* Set all bit to zero Normal operation



		while ((TIFR & (1 << ICF1)) == 0);/* Wait for falling edge 
		count = ICR1 + (65535 * TimerOverflow);	/* Take count 
		/* 8MHz Timer freq, sound speed =343 m/s 
		distance = (double)count / 466.47;
         * 
         * dtostrf(distance, 2, 2, string);/* distance to string 
		strcat(string, " cm   ");	/* Concat unit i.e.cm 
		LCD_String_xy(2, 0, "Dist = ");
		LCD_String_xy(2, 7, string);	/* Print distance 
		_delay_ms(200);
        
        */