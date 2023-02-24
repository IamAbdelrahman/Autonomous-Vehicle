/*
 * timer.c
 *
 *  Created on: Feb 16, 2023
 *      Author: ak
 
*/
#include "TIMER.h"
#include "math.h"

void TIMER_Init(ST_TIMER_config_t* pTIMER)
{   
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
            
            SET_BIT(DDRB, 3); // The OC0 Bit.
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
        
            SET_BIT(DDRB, 3); // The OC0 Bit.
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
            
            SET_BIT(DDRB, 3); // The OC0 Bit.
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
            
            SET_BIT(DDRB, 3); // The OC0 Bit.
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
            
            SET_BIT(DDRD, 7); // The OC2 Bit
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
        
            SET_BIT(DDRD, 7); // The OC2 Bit
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
}

void TIM0_Init (void)
{
    ST_TIMER_config_t S_TIMER0 = {TIMER0, NORMAL_MODE, CLK_1024_PRESCALING};
    TIMER_Init (&S_TIMER0);
}

void TIM2_Init(void)
{
    ST_TIMER_config_t S_TIMER2 = {TIMER2, PWM_MODE_FAST_NON_INVERTED, CLK_1024_PRESCALING};
    TIMER_Init (&S_TIMER2);
}
 
void TIM0_Start(void)
{
    TCNT0 = 0X00;
}

void TIM2_Start(void)
{
    TCNT2 = 0X00;
}

void TIMER_Stop (ST_TIMER_config_t* pTIMER){
    
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
}

void TIM0_Stop (void)
{
    ST_TIMER_config_t S_TIMER0 = {TIMER0, NORMAL_MODE, CLK_1024_PRESCALING};
    TIMER_Stop (&S_TIMER0);
}

void TIM2_Stop (void)
{
    ST_TIMER_config_t S_TIMER2 = {TIMER2, PWM_MODE_FAST_NON_INVERTED, CLK_1024_PRESCALING};
    TIMER_Stop (&S_TIMER2);
}

void delay_s (uint64_t Time_delay_s)
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
			while ( (TIFR & (1 << 0)) == 0); // Busy wait
			TIFR |= (1 << 0); // Clear the overflow flag
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
			while ( (TIFR & (1 << 0)) == 0); // Busy wait
			TIFR |= (1 << 0); // Clear the overflow flag
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
			while ( (TIFR & (1 << 0)) == 0); // Busy wait
			TIFR |= (1 << 0); // Clear the overflow flag
			overflow_counter++;
		}

        overflow_counter = 0;
        TIM0_Stop();
        
    }
        
}

void PWM_Start(uint8_t dutyCycle)
{   
    TIM2_Init();
    TIM2_Start();
    
	if((dutyCycle <= 100) && (dutyCycle > 0))
	{
		OCR2 = (dutyCycle * 256)/100 - 1;
	}
        
	else if(dutyCycle == 0)
	{
		OCR2 = 0;
	}
    
    TIM2_Stop();
}
