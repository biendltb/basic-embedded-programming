#include "delay.h"
void delay(int iter)
{
    unsigned int volatile counter = 0;
    while (counter < iter)
        counter++;
}