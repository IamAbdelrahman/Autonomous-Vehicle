/*
 * timer.c
 *
 *  Created on: Feb 16, 2023
 *      Author: ak
 
*/
#include "TIMER.h"
#include "math.h"

// Global Structures and Pointers
ST_TIMER_config_t S_TIMER0 = {TIMER0, PWM_MODE_FAST_NON_INVERTED, CLK_1024_PRESCALING};
ST_TIMER_config_t S_TIMER2 = {TIMER2, PWM_MODE_FAST_NON_INVERTED, CLK_1024_PRESCALING};
ST_TIMER_config_t S_TIMER1 = {TIMER1, NORMAL_MODE, CLK_NO_PRESCALING};

volatile U_TCCR0_t*  const pTCCR0    = ADDRESS_TCCR0;
volatile U_TCCR2_t*  const pTCCR2    = ADDRESS_TCCR2;
volatile U_TIFR_t *  const pTIFR     = ADDRESS_TIFR;
volatile U_TCCR1A_t* const pTCCR1A   = ADDRESS_TCCR1A;
volatile U_TCCR1B_t* const pTCCR1B   = ADDRESS_TCCR1B;
volatile U_TIMSK_t*  const pTIMSK    = ADDRESS_TIMSK;

void TIMER_Init(ST_TIMER_config_t* pTIMER)
{   
    pTCCR0->All_Bits = 0x00;
    pTCCR2->All_Bits = 0x00;
    pTCCR1A->All_Bits = 0x00;
    pTCCR1B->All_Bits = 0x00;
    
	if (pTIMER->Timer_Channel == TIMER0)
    {    
        if (pTIMER->Timer_Mode == NORMAL_MODE)
        {    
            pTCCR0->Timer0.WGM00 = 0;
            pTCCR0->Timer0.WGM01 = 0;
            
		    if (pTIMER->Timer_Start_Prescalar == NO_CLK_SRC)
		        pTCCR0->All_Bits = 0x00;
		    
		    else if (pTIMER->Timer_Start_Prescalar == CLK_NO_PRESCALING)
            {
		        pTCCR0->Timer0.CS00 = 1;
		        pTCCR0->Timer0.CS01 = 0;
		        pTCCR0->Timer0.CS02 = 0;
            }                              
		
		    else if (pTIMER->Timer_Start_Prescalar == CLK_8_PRESCALING)
            {
		        pTCCR0->Timer0.CS00 = 0;
		        pTCCR0->Timer0.CS01 = 1;
		        pTCCR0->Timer0.CS02 = 0;
            }
		                      
		    else if (pTIMER->Timer_Start_Prescalar == CLK_64_PRESCALING)
            {
		        pTCCR0->Timer0.CS00 = 1;
		        pTCCR0->Timer0.CS01 = 1;
		        pTCCR0->Timer0.CS02 = 0;
            }                               
		
		    else if (pTIMER->Timer_Start_Prescalar == CLK_256_PRESCALING)
            {
		        pTCCR0->Timer0.CS00 = 0;
		        pTCCR0->Timer0.CS01 = 0;
		        pTCCR0->Timer0.CS02 = 1;
            }                               
		
		    else if (pTIMER->Timer_Start_Prescalar == CLK_1024_PRESCALING)
            {
		        pTCCR0->Timer0.CS00 = 1;
		        pTCCR0->Timer0.CS01 = 0;
		        pTCCR0->Timer0.CS02 = 1;
            }                               
        
        }     
         
        else if (pTIMER->Timer_Mode == PWM_MODE_FAST_NON_INVERTED)
        {
            
            DIO_Init_Pin('B', 3, OUT);
            pTCCR0->Timer0.WGM00 = 1;
            pTCCR0->Timer0.WGM01 = 1;
            pTCCR0->Timer0.COM00 = 0;
            pTCCR0->Timer0.COM01 = 1;
            
            if (pTIMER->Timer_Start_Prescalar == NO_CLK_SRC)
		        pTCCR0->All_Bits = 0x00;
		    
		    else if (pTIMER->Timer_Start_Prescalar == CLK_NO_PRESCALING)
            {
		        pTCCR0->Timer0.CS00 = 1;
		        pTCCR0->Timer0.CS01 = 0;
		        pTCCR0->Timer0.CS02 = 0;
            }                              
		
		    else if (pTIMER->Timer_Start_Prescalar == CLK_8_PRESCALING)
            {
		        pTCCR0->Timer0.CS00 = 0;
		        pTCCR0->Timer0.CS01 = 1;
		        pTCCR0->Timer0.CS02 = 0;
            }
		                      
		    else if (pTIMER->Timer_Start_Prescalar == CLK_64_PRESCALING)
            {
		        pTCCR0->Timer0.CS00 = 1;
		        pTCCR0->Timer0.CS01 = 1;
		        pTCCR0->Timer0.CS02 = 0;
            }                               
		
		    else if (pTIMER->Timer_Start_Prescalar == CLK_256_PRESCALING)
            {
		        pTCCR0->Timer0.CS00 = 0;
		        pTCCR0->Timer0.CS01 = 0;
		        pTCCR0->Timer0.CS02 = 1;
            }                               
		
		    else if (pTIMER->Timer_Start_Prescalar == CLK_1024_PRESCALING)
            {
		        pTCCR0->Timer0.CS00 = 1;
		        pTCCR0->Timer0.CS01 = 0;
		        pTCCR0->Timer0.CS02 = 1;
            }                               
                                      
        }   
      
        
        else if(pTIMER->Timer_Mode == PWM_MODE_FAST_INVERTED) 
        {
        
            DIO_Init_Pin('B', 3, OUT);
            pTCCR0->Timer0.WGM00 = 1;
            pTCCR0->Timer0.WGM01 = 1;
            pTCCR0->Timer0.COM00 = 1;
            pTCCR0->Timer0.COM01 = 1;
            
            if (pTIMER->Timer_Start_Prescalar == NO_CLK_SRC)
		        pTCCR0->All_Bits = 0x00;
		    
		    else if (pTIMER->Timer_Start_Prescalar == CLK_NO_PRESCALING)
            {
		        pTCCR0->Timer0.CS00 = 1;
		        pTCCR0->Timer0.CS01 = 0;
		        pTCCR0->Timer0.CS02 = 0;
            }                              
		
		    else if (pTIMER->Timer_Start_Prescalar == CLK_8_PRESCALING)
            {
		        pTCCR0->Timer0.CS00 = 0;
		        pTCCR0->Timer0.CS01 = 1;
		        pTCCR0->Timer0.CS02 = 0;
            }
		                      
		    else if (pTIMER->Timer_Start_Prescalar == CLK_64_PRESCALING)
            {
		        pTCCR0->Timer0.CS00 = 1;
		        pTCCR0->Timer0.CS01 = 1;
		        pTCCR0->Timer0.CS02 = 0;
            }                               
		
		    else if (pTIMER->Timer_Start_Prescalar == CLK_256_PRESCALING)
            {
		        pTCCR0->Timer0.CS00 = 0;
		        pTCCR0->Timer0.CS01 = 0;
		        pTCCR0->Timer0.CS02 = 1;
            }                               
		
		    else if (pTIMER->Timer_Start_Prescalar == CLK_1024_PRESCALING)
            {
		        pTCCR0->Timer0.CS00 = 1;
		        pTCCR0->Timer0.CS01 = 0;
		        pTCCR0->Timer0.CS02 = 1;
            }                                                                     
        }
 
        
        else if (pTIMER->Timer_Mode == PWM_MODE_PHASE_CORRECT_INVERTED)
        {            
            
            DIO_Init_Pin('B', 3, OUT);
            pTCCR0->Timer0.WGM00 = 1;
            pTCCR0->Timer0.WGM01 = 0;
            pTCCR0->Timer0.COM00 = 1;
            pTCCR0->Timer0.COM01 = 1;
            
            if (pTIMER->Timer_Start_Prescalar == NO_CLK_SRC)
		        pTCCR0->All_Bits = 0x00;
		    
		    else if (pTIMER->Timer_Start_Prescalar == CLK_NO_PRESCALING)
            {
		        pTCCR0->Timer0.CS00 = 1;
		        pTCCR0->Timer0.CS01 = 0;
		        pTCCR0->Timer0.CS02 = 0;
            }                              
		
		    else if (pTIMER->Timer_Start_Prescalar == CLK_8_PRESCALING)
            {
		        pTCCR0->Timer0.CS00 = 0;
		        pTCCR0->Timer0.CS01 = 1;
		        pTCCR0->Timer0.CS02 = 0;
            }
		                      
		    else if (pTIMER->Timer_Start_Prescalar == CLK_64_PRESCALING)
            {
		        pTCCR0->Timer0.CS00 = 1;
		        pTCCR0->Timer0.CS01 = 1;
		        pTCCR0->Timer0.CS02 = 0;
            }                               
		
		    else if (pTIMER->Timer_Start_Prescalar == CLK_256_PRESCALING)
            {
		        pTCCR0->Timer0.CS00 = 0;
		        pTCCR0->Timer0.CS01 = 0;
		        pTCCR0->Timer0.CS02 = 1;
            }                               
		
		    else if (pTIMER->Timer_Start_Prescalar == CLK_1024_PRESCALING)
            {
		        pTCCR0->Timer0.CS00 = 1;
		        pTCCR0->Timer0.CS01 = 0;
		        pTCCR0->Timer0.CS02 = 1;
            }                                                                     
       }
            
        
        else if (pTIMER->Timer_Mode == PWM_MODE_PHASE_CORRECT_NON_INVERTED)
        {
            
            DIO_Init_Pin('B', 3, OUT);
            pTCCR0->Timer0.WGM00 = 1;
            pTCCR0->Timer0.WGM01 = 0;
            pTCCR0->Timer0.COM00 = 0;
            pTCCR0->Timer0.COM01 = 1;
            
            if (pTIMER->Timer_Start_Prescalar == NO_CLK_SRC)
		        pTCCR0->All_Bits = 0x00;
		    
		    else if (pTIMER->Timer_Start_Prescalar == CLK_NO_PRESCALING)
            {
		        pTCCR0->Timer0.CS00 = 1;
		        pTCCR0->Timer0.CS01 = 0;
		        pTCCR0->Timer0.CS02 = 0;
            }                              
		
		    else if (pTIMER->Timer_Start_Prescalar == CLK_8_PRESCALING)
            {
		        pTCCR0->Timer0.CS00 = 0;
		        pTCCR0->Timer0.CS01 = 1;
		        pTCCR0->Timer0.CS02 = 0;
            }
		                      
		    else if (pTIMER->Timer_Start_Prescalar == CLK_64_PRESCALING)
            {
		        pTCCR0->Timer0.CS00 = 1;
		        pTCCR0->Timer0.CS01 = 1;
		        pTCCR0->Timer0.CS02 = 0;
            }                               
		
		    else if (pTIMER->Timer_Start_Prescalar == CLK_256_PRESCALING)
            {
		        pTCCR0->Timer0.CS00 = 0;
		        pTCCR0->Timer0.CS01 = 0;
		        pTCCR0->Timer0.CS02 = 1;
            }                               
		
		    else if (pTIMER->Timer_Start_Prescalar == CLK_1024_PRESCALING)
            {
		        pTCCR0->Timer0.CS00 = 1;
		        pTCCR0->Timer0.CS01 = 0;
		        pTCCR0->Timer0.CS02 = 1;
            }                                  
       }
        
    }
    
    else if (pTIMER->Timer_Channel == TIMER2)
    {       
        if (pTIMER->Timer_Mode == NORMAL_MODE)
        {        
            pTCCR2->Timer2.WGM20 = 0;
            pTCCR2->Timer2.WGM21 = 0;
            
		    if (pTIMER->Timer_Start_Prescalar == NO_CLK_SRC)
                pTCCR2->All_Bits = 0x00;
		    
		    else if (pTIMER->Timer_Start_Prescalar == CLK_NO_PRESCALING)
            {
		        pTCCR2->Timer2.CS20 = 1;
                pTCCR2->Timer2.CS21 = 0;
		        pTCCR2->Timer2.CS22 = 0;
            }                              
		
		    else if (pTIMER->Timer_Start_Prescalar == CLK_8_PRESCALING)
            {
		        pTCCR2->Timer2.CS20 = 0;
		        pTCCR2->Timer2.CS21 = 1;
		        pTCCR2->Timer2.CS22 = 0;
            }
		                      
		    else if (pTIMER->Timer_Start_Prescalar == CLK_64_PRESCALING)
            {
		        pTCCR2->Timer2.CS20 = 1;
		        pTCCR2->Timer2.CS21 = 1;
		        pTCCR2->Timer2.CS22 = 0;
            }                               
		
		    else if (pTIMER->Timer_Start_Prescalar == CLK_256_PRESCALING)
            {
		        pTCCR2->Timer2.CS20 = 0;
		        pTCCR2->Timer2.CS21 = 0;
		        pTCCR2->Timer2.CS22 = 1;
            }                               
		
		    else if (pTIMER->Timer_Start_Prescalar == CLK_1024_PRESCALING)
            {
		        pTCCR2->Timer2.CS20 = 1;
		        pTCCR2->Timer2.CS21 = 0;
		        pTCCR2->Timer2.CS22 = 1;
            }                               
        
        }           
         
        else if (pTIMER->Timer_Mode == PWM_MODE_FAST_NON_INVERTED){
            
            DIO_Init_Pin('D', 7, OUT);
            pTCCR2->Timer2.WGM20 = 1;
            pTCCR2->Timer2.WGM21 = 1;
            pTCCR2->Timer2.COM20 = 0;
            pTCCR2->Timer2.COM21 = 1;
            
            if (pTIMER->Timer_Start_Prescalar == NO_CLK_SRC)
		        pTCCR2->All_Bits = 0x00;
		    
		    else if (pTIMER->Timer_Start_Prescalar == CLK_NO_PRESCALING)
            {
		        pTCCR2->Timer2.CS20 = 1;
                pTCCR2->Timer2.CS21 = 0;
		        pTCCR2->Timer2.CS22 = 0;
            }                              
		
		    else if (pTIMER->Timer_Start_Prescalar == CLK_8_PRESCALING)
            {
		        pTCCR2->Timer2.CS20 = 0;
		        pTCCR2->Timer2.CS21 = 1;
		        pTCCR2->Timer2.CS22 = 0;
            }
		                      
		    else if (pTIMER->Timer_Start_Prescalar == CLK_64_PRESCALING)
            {
		        pTCCR2->Timer2.CS20 = 1;
		        pTCCR2->Timer2.CS21 = 1;
		        pTCCR2->Timer2.CS22 = 0;
            }                               
		
		    else if (pTIMER->Timer_Start_Prescalar == CLK_256_PRESCALING)
            {
		        pTCCR2->Timer2.CS20 = 0;
		        pTCCR2->Timer2.CS21 = 0;
		        pTCCR2->Timer2.CS22 = 1;
            }                               
		
		    else if (pTIMER->Timer_Start_Prescalar == CLK_1024_PRESCALING)
            {
		        pTCCR2->Timer2.CS20 = 1;
		        pTCCR2->Timer2.CS21 = 0;
		        pTCCR2->Timer2.CS22 = 1;
            }                             
        }   
      
        
        else if(pTIMER->Timer_Mode == PWM_MODE_FAST_INVERTED) {
        
            DIO_Init_Pin('D', 7, OUT);
            pTCCR2->Timer2.WGM20 = 1;
            pTCCR2->Timer2.WGM21 = 1;
            pTCCR2->Timer2.COM20 = 1;
            pTCCR2->Timer2.COM21 = 1;
            
            if (pTIMER->Timer_Start_Prescalar == NO_CLK_SRC)
		        pTCCR2->All_Bits = 0x00;
		    
		    else if (pTIMER->Timer_Start_Prescalar == CLK_NO_PRESCALING)
            {
		        pTCCR2->Timer2.CS20 = 1;
                pTCCR2->Timer2.CS21 = 0;
		        pTCCR2->Timer2.CS22 = 0;
            }                              
		
		    else if (pTIMER->Timer_Start_Prescalar == CLK_8_PRESCALING)
            {
		        pTCCR2->Timer2.CS20 = 0;
		        pTCCR2->Timer2.CS21 = 1;
		        pTCCR2->Timer2.CS22 = 0;
            }
		                      
		    else if (pTIMER->Timer_Start_Prescalar == CLK_64_PRESCALING)
            {
		        pTCCR2->Timer2.CS20 = 1;
		        pTCCR2->Timer2.CS21 = 1;
		        pTCCR2->Timer2.CS22 = 0;
            }                               
		
		    else if (pTIMER->Timer_Start_Prescalar == CLK_256_PRESCALING)
            {
		        pTCCR2->Timer2.CS20 = 0;
		        pTCCR2->Timer2.CS21 = 0;
		        pTCCR2->Timer2.CS22 = 1;
            }                               
		
		    else if (pTIMER->Timer_Start_Prescalar == CLK_1024_PRESCALING)
            {
		        pTCCR2->Timer2.CS20 = 1;
		        pTCCR2->Timer2.CS21 = 0;
		        pTCCR2->Timer2.CS22 = 1;
            }                              
        }
 
        
        else if (pTIMER->Timer_Mode == PWM_MODE_PHASE_CORRECT_INVERTED)
        {            
            
            SET_BIT(DDRD, 7); // The OC2 Bit
            pTCCR2->Timer2.WGM20 = 1;
            pTCCR2->Timer2.WGM21 = 0;
            pTCCR2->Timer2.COM20 = 1;
            pTCCR2->Timer2.COM21 = 1;
            
            if (pTIMER->Timer_Start_Prescalar == NO_CLK_SRC)
		        pTCCR2->All_Bits = 0x00;
		    
		    else if (pTIMER->Timer_Start_Prescalar == CLK_NO_PRESCALING)
            {
		        pTCCR2->Timer2.CS20 = 1;
                pTCCR2->Timer2.CS21 = 0;
		        pTCCR2->Timer2.CS22 = 0;
            }                              
		
		    else if (pTIMER->Timer_Start_Prescalar == CLK_8_PRESCALING)
            {
		        pTCCR2->Timer2.CS20 = 0;
		        pTCCR2->Timer2.CS21 = 1;
		        pTCCR2->Timer2.CS22 = 0;
            }
		                      
		    else if (pTIMER->Timer_Start_Prescalar == CLK_64_PRESCALING)
            {
		        pTCCR2->Timer2.CS20 = 1;
		        pTCCR2->Timer2.CS21 = 1;
		        pTCCR2->Timer2.CS22 = 0;
            }                               
		
		    else if (pTIMER->Timer_Start_Prescalar == CLK_256_PRESCALING)
            {
		        pTCCR2->Timer2.CS20 = 0;
		        pTCCR2->Timer2.CS21 = 0;
		        pTCCR2->Timer2.CS22 = 1;
            }                               
		
		    else if (pTIMER->Timer_Start_Prescalar == CLK_1024_PRESCALING)
            {
		        pTCCR2->Timer2.CS20 = 1;
		        pTCCR2->Timer2.CS21 = 0;
		        pTCCR2->Timer2.CS22 = 1;
            }                                                   
        }
            
        
        else if (pTIMER->Timer_Mode == PWM_MODE_PHASE_CORRECT_NON_INVERTED){
            
            SET_BIT(DDRD, 7); // The OC2 Bit.
            pTCCR2->Timer2.WGM20 = 1;
            pTCCR2->Timer2.WGM21 = 0;
            pTCCR2->Timer2.COM20 = 0;
            pTCCR2->Timer2.COM21 = 1;
            
		    if (pTIMER->Timer_Start_Prescalar == NO_CLK_SRC)
		        pTCCR2->All_Bits = 0x00;
		    
		    else if (pTIMER->Timer_Start_Prescalar == CLK_NO_PRESCALING)
            {
		        pTCCR2->Timer2.CS20 = 1;
                pTCCR2->Timer2.CS21 = 0;
		        pTCCR2->Timer2.CS22 = 0;
            }                              
		
		    else if (pTIMER->Timer_Start_Prescalar == CLK_8_PRESCALING)
            {
		        pTCCR2->Timer2.CS20 = 0;
		        pTCCR2->Timer2.CS21 = 1;
		        pTCCR2->Timer2.CS22 = 0;
            }
		                      
		    else if (pTIMER->Timer_Start_Prescalar == CLK_64_PRESCALING)
            {
		        pTCCR2->Timer2.CS20 = 1;
		        pTCCR2->Timer2.CS21 = 1;
		        pTCCR2->Timer2.CS22 = 0;
            }                               
		
		    else if (pTIMER->Timer_Start_Prescalar == CLK_256_PRESCALING)
            {
		        pTCCR2->Timer2.CS20 = 0;
		        pTCCR2->Timer2.CS21 = 0;
		        pTCCR2->Timer2.CS22 = 1;
            }                               
		
		    else if (pTIMER->Timer_Start_Prescalar == CLK_1024_PRESCALING)
            {
		        pTCCR2->Timer2.CS20 = 1;
		        pTCCR2->Timer2.CS21 = 0;
		        pTCCR2->Timer2.CS22 = 1;
            }                  
        }
    
    }
    
    else if (pTIMER->Timer_Channel == TIMER1)
    {
        if (pTIMER->Timer_Mode == NORMAL_MODE)
        {
           pTCCR1A->All_Bits = 0x00;
           
           if (pTIMER->Timer_Start_Prescalar == CLK_NO_PRESCALING)
           {
               pTCCR1B->Timer1B.CS10 = 1;
               pTCCR1B->Timer1B.CS11 = 0;
               pTCCR1B->Timer1B.CS12 = 0;
           }
        }            
    }
}

void TIM0_Init (void)
{
    TIMER_Init (&S_TIMER0);
}

void TIM2_Init(void)
{
    TIMER_Init (&S_TIMER2);
}
 
void TIM1_Init(void)
{
    TIMER_Init(&S_TIMER1);
}

void TIM0_Start(void)
{
    TCNT0 = 0X00;
}

void TIM2_Start(void)
{
    TCNT2 = 0X00;
}

void TIM1_Start(void)
{
    TCNT1H = 0;
    TCNT1L = 0;
}

void TIMER_Stop (ST_TIMER_config_t* pTIMER)
{
    
    if (pTIMER->Timer_Channel == TIMER0)
    {
        pTCCR0->Timer0.CS00 = 0;
        pTCCR0->Timer0.CS01 = 0;
        pTCCR0->Timer0.CS02 = 0;
    }
    
    else if (pTIMER->Timer_Channel == TIMER2)
    {
        pTCCR2->Timer2.CS20 = 0;
        pTCCR2->Timer2.CS21 = 0;
        pTCCR2->Timer2.CS22 = 0;
    }
    
    else if (pTIMER->Timer_Channel == TIMER1)
    {
        pTCCR1B->Timer1B.CS10 = 0;
        pTCCR1B->Timer1B.CS11 = 0;
        pTCCR1B->Timer1B.CS12 = 0;
    }
}

void TIM0_Stop (void)
{   
    TIMER_Stop (&S_TIMER0);
}

void TIM2_Stop (void)
{
    TIMER_Stop (&S_TIMER2);
}

void TIM1_Stop (void)
{
    TIMER_Stop (&S_TIMER1);
}

void delay_s (float Time_delay_s)
{  
    TIM0_Init();
    uint32_t Number_of_Overflow = 0;
    uint8_t overflow_counter = 0;
    
    if (Time_delay_s < T_MAX_DELAY)
    {       
        TCNT0 = (T_MAX_DELAY - Time_delay_s) / T_TICK;
        Number_of_Overflow = 1;
        
        while (overflow_counter < Number_of_Overflow)
		{
			while (pTIFR->TIFR_Reg.TOV0 == 0); // Busy wait
			pTIFR->TIFR_Reg.TOV0 = 1;
			overflow_counter++;
		}

        overflow_counter = 0;
        TIM0_Stop();
        
    }
    
    else if (Time_delay_s == T_MAX_DELAY)
    {
        TCNT0 = 0x00;
        Number_of_Overflow = 1;
                
        while (overflow_counter < Number_of_Overflow)
		{
			while (pTIFR->TIFR_Reg.TOV0 == 0); // Busy wait
			pTIFR->TIFR_Reg.TOV0 = 1;
			overflow_counter++;
		}

        overflow_counter = 0;
        TIM0_Stop();
    }
    
    else 
    {
        Number_of_Overflow = ceil(Time_delay_s / T_MAX_DELAY);
        TCNT0 = ceil( 256 - ((Time_delay_s / T_TICK) / Number_of_Overflow) );        
         
        while (overflow_counter < Number_of_Overflow)
		{
			while (pTIFR->TIFR_Reg.TOV0 == 0); // Busy wait
			pTIFR->TIFR_Reg.TOV0 = 1;
			overflow_counter++;
		}

        overflow_counter = 0;
        TIM0_Stop();
        
    }
        
}

void PWM_Start(uint8_t dutyCycle)
{     
	if((dutyCycle <= 100) && (dutyCycle > 0))
	{
		OCR0 = (dutyCycle * 256)/100 - 1;
	}
        
	else if(dutyCycle == 0)
	{
		OCR0 = 0;
	}
}

void TIMER_checkStatus(ST_TIMER_config_t* pTIMER, uint8_t *status)
{
    if (pTIMER->Timer_Channel == NORMAL_MODE)
    {
        if (pTIMER->Timer_Mode == TIMER0)
        {
            *status = pTIFR->TIFR_Reg.TOV0;
        }
        
        else if (pTIMER->Timer_Mode == TIMER1)
        {
            *status = pTIFR->TIFR_Reg.TOV1;
        }
        
        else
        {
            *status = pTIFR->TIFR_Reg.TOV2;
        }
    }
}

void Timer_Reset(ST_TIMER_config_t* pTIMER)
{
	if(pTIMER->Timer_Channel == TIMER0)
	{
		TCNT0 = 0x00;
		pTIFR->TIFR_Reg.TOV0 = 1;
	}

	else if(pTIMER->Timer_Channel == TIMER1)
	{
		TCNT1H = 0x00;
		TCNT1L = 0x00;
		pTIFR->TIFR_Reg.TOV1 = 1;
	}

	else if(pTIMER->Timer_Channel == TIMER2)
	{
		TCNT2 = 0x00;
		pTIFR->TIFR_Reg.TOV2 = 1;
	}
}
