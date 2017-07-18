#include "lm4f120h5qr.h"

#define LED_RED         (1U << 1)
#define LED_BLUE        (1U << 2)
#define LED_GREEN       (1U << 3)

int main()
{
  SYSCTL_RCGCGPIO_R = (1 << 5); // enable clock for GPIOF
  GPIO_PORTF_DIR_R = (LED_RED | LED_BLUE | LED_GREEN); // set pin 1, 2, 3 as output
  GPIO_PORTF_DEN_R = (LED_RED | LED_BLUE | LED_GREEN);
  while (1)
  {
      GPIO_PORTF_DATA_R = LED_BLUE;
      
      unsigned int volatile counter = 0;
      while (counter < 500000)
        counter++;
      
      GPIO_PORTF_DATA_R |= LED_RED;
      
      counter = 0;
      while (counter < 500000)
        counter++;
      
      GPIO_PORTF_DATA_R |= LED_GREEN;
      
      counter = 0;
      while (counter < 500000)
        counter++;
  }
  
  
  return 0;
}
