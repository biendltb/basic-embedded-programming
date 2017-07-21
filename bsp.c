/* Board Support Package */

#include "tm4c_cmsis.h"
#include "bsp.h"

void assert_failed (char const *file, int line) {
  /* TBD: damage control */
    NVIC_SystemReset();
}

void SysTick_Handler(void) {
    GPIOF_HS->DATA_Bits[LED_RED] ^= LED_RED;
}