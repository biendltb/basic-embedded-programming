#include "lm4f120h5qr.h"

#define LED_RED         (1U << 1)
#define LED_BLUE        (1U << 2)
#define LED_GREEN       (1U << 3)

void delay();
void delay()
{
    unsigned int volatile counter = 0;
    while (counter < 500000)
        counter++;
}

int main()
{
  SYSCTL_RCGCGPIO_R |= (1U << 5); // enable clock for GPIOF
  SYSCTL_GPIOHBCTL_R |= (1U << 5); // enable AHB for GPIOF
  GPIO_PORTF_AHB_DIR_R = (LED_RED | LED_BLUE | LED_GREEN); // set pin 1, 2, 3 as output
  GPIO_PORTF_AHB_DEN_R = (LED_RED | LED_BLUE | LED_GREEN);
  while (1)
  {
      GPIO_PORTF_AHB_DATA_R = LED_BLUE;
      //GPIO_PORTF_AHB_DATA_BITS_R[LED_BLUE] = LED_BLUE;
      
      delay();
      
      //GPIO_PORTF_DATA_R |= LED_RED;
      //*((volatile unsigned long *)(0x40025000 + (LED_RED << 2))) = LED_RED;
      //*(GPIO_PORTF_DATA_BITS_R + LED_RED) = LED_RED;
      GPIO_PORTF_AHB_DATA_BITS_R[LED_RED] = LED_RED;
      
      delay();
      
      //GPIO_PORTF_DATA_R |= LED_GREEN;
      GPIO_PORTF_AHB_DATA_BITS_R[LED_GREEN] = LED_GREEN;
      
      delay();
  }
  
  
  return 0;
}
