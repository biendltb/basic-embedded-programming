#include <stdint.h>
#include "TM4C123GH6PM.h"
#include "bsp.h"

int main()
{
    SYSCTL->RCGC2 |= (1U << 5); // enable clock for GPIOF
    SYSCTL->GPIOHBCTL |= (1U << 5); // enable AHB for GPIOF
    
    GPIOF_AHB->DIR = (LED_RED | LED_BLUE | LED_GREEN); // set pin 1, 2, 3 as output
    GPIOF_AHB->DEN = (LED_RED | LED_BLUE | LED_GREEN);
    
    SysTick->LOAD       = SYS_CLOCK_HZ / 2U - 1U;
    SysTick->VAL        = 0U;
    SysTick->CTRL       = (1U << 2) | (1U << 1) | 1U;
    
    //SysTick_Handler();
    
    __enable_interrupt();
    
    while (1)
    {
        GPIOF_AHB->DATA_Bits[LED_GREEN] = LED_GREEN;
        GPIOF_AHB->DATA_Bits[LED_GREEN] = 0U;
        
//        __disable_irq();
//        GPIOF_AHB->DATA |= LED_GREEN;
//        __enable_irq();
//        
//        __disable_irq();
//        GPIOF_AHB->DATA &= ~LED_GREEN;
//        __enable_irq();
        
    }
  
    //return 0;
}
