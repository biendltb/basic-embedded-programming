#include <stdint.h>
#include "tm4c_cmsis.h"
#include "delay.h"

#define LED_RED         (1U << 1)
#define LED_BLUE        (1U << 2)
#define LED_GREEN       (1U << 3)

typedef struct {
    uint8_t y;
    uint16_t x;
} Point;

typedef struct {
    Point top_left;
    Point bottom_right;
} Window;

typedef struct {
    Point corners[3];
} Triangle;

Point p1, p2;
Window w, w1;
Triangle t;

Point* pp;
Window* wp;

int main()
{
    p1.x = sizeof(Point);
    p1.y = 0xAAU;
    
    w.top_left.x = 1U;
    w.bottom_right.y = 2U;
    
    t.corners[0].x = 1U;
    t.corners[0].y = 2U;
    
    p2 = p1;
    w1 = w;
    
    pp = &p1;
    wp = &w1;
    
    (*pp).x = 1U;
    wp->top_left = *pp;
    
    SYSCTL->RCGC2 |= (1U << 5); // enable clock for GPIOF
    SYSCTL->GPIOHSCTL |= (1U << 5); // enable AHB for GPIOF
    
    GPIOF_HS->DIR = (LED_RED | LED_BLUE | LED_GREEN); // set pin 1, 2, 3 as output
    GPIOF_HS->DEN = (LED_RED | LED_BLUE | LED_GREEN);
    while (1)
    {
        GPIOF_HS->DATA = LED_BLUE;
        //GPIO_PORTF_AHB_DATA_BITS_R[LED_BLUE] = LED_BLUE;
      
        delay(500000);
      
        GPIOF_HS->DATA_Bits[LED_RED] = LED_RED;
      
        delay(500000);
      
        GPIOF_HS->DATA_Bits[LED_GREEN] = LED_GREEN;
      
        delay(500000);
    }
  
    return 0;
}
