#include "DIO.h"

void DIO_Init_Pin(uint8_t portName, uint8_t pinNumber, uint8_t direction) {
    
    switch (portName) {
        
        case 'A':
            
            if (direction == OUT)
                SET_BIT(DDRA, pinNumber);

            else if (direction == IN)
                CLR_BIT(DDRA, pinNumber);

            break;

        case 'B':
            
            if (direction == OUT)
                SET_BIT(DDRB, pinNumber);

            else if (direction == IN)
                CLR_BIT(DDRB, pinNumber);

            break;

        case 'C':
            
            if (direction == OUT)
                SET_BIT(DDRC, pinNumber);

            else if (direction == IN)
                CLR_BIT(DDRC, pinNumber);

            break;

        case 'D':
            
            if (direction == OUT)
                SET_BIT(DDRD, pinNumber);

            else if (direction == IN)
                CLR_BIT(DDRD, pinNumber);

            break;

        default:
            break;
    }
}

void DIO_Write_Pin(uint8_t portName, uint8_t pinNumber, uint8_t value) {
    
    switch (portName) {
        
        case 'A':
            
            if (value == HIGH)
                SET_BIT(PORTA, pinNumber);

            else if (value == LOW)
                CLR_BIT(PORTA, pinNumber);

            break;

        case 'B':
            
            if (value == HIGH)
                SET_BIT(PORTB, pinNumber);

            else if (value == LOW)
                CLR_BIT(PORTB, pinNumber);

            break;

        case 'C':
            
            if (value == HIGH)
                SET_BIT(PORTC, pinNumber);

            else if (value == LOW)
                CLR_BIT(PORTC, pinNumber);

            break;

        case 'D':
            
            if (value == HIGH)
                SET_BIT(PORTD, pinNumber);

            else if (value == LOW)
                CLR_BIT(PORTD, pinNumber);

            break;

        default:
            break;
    }
}

void DIO_Toggle_Pin(uint8_t portName, uint8_t pinNumber){
    
    switch (portName) {
        
        case 'A':
            
            TOGGLE_BIT(PORTA, pinNumber);
            break;

        case 'B':
            
            TOGGLE_BIT(PORTB, pinNumber);
            break;

        case 'C':
            
            TOGGLE_BIT(PORTC, pinNumber);
            break;

        case 'D':
            
            TOGGLE_BIT(PORTD, pinNumber);
            break;

        default:
            break;
    }
}

void DIO_Read_Pin(uint8_t portName, uint8_t pinNumber, uint8_t* pinValue) {
    
    switch (portName) {
        
        case 'A':
            
            *pinValue = READ_BIT(PINA, pinNumber);
            break;

        case 'B':
            
            *pinValue = READ_BIT(PINB, pinNumber);
            break;

        case 'C':
            
            *pinValue = READ_BIT(PINC, pinNumber);
            break;

        case 'D':
            
            *pinValue = READ_BIT(PIND, pinNumber);
            break;

        default:
            break;
    }
}

void DIO_Port_Direction(UGPIO_t* Ptr, uint8_t portDirection) {
    
    if (portDirection == OUT)
        Ptr-> All_Bits = 0xFF;

    else if (portDirection == IN)
        Ptr-> All_Bits = 0x00;
}

void DIO_Port_Write(UGPIO_t* Ptr, uint8_t portValue) {
    
    if (portValue == LOW)
        Ptr-> All_Bits = 0x00;

    else if (portValue == HIGH)
        Ptr-> All_Bits = 0xFF;
}

void DIO_Port_Read(uint8_t portName, uint8_t* portValue) {
    
    switch (portName) {
        
        case 'A':
            
            *portValue = PINA;
            break;

        case 'B':
            
            *portValue = PINB;
            break;

        case 'C':
            
            *portValue = PINC;
            break;

        case 'D':
            
            *portValue = PIND;
            break;

        default:
            break;
    }
}

