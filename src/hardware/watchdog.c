/*!
 * @file
 * @brief
 */

#include "watchdog.h"
#include "LPC55S16.h"

void watchdog_init(void)
{
  // WDOG->CNT = WDOG_UPDATE_KEY1;
  // WDOG->CNT = WDOG_UPDATE_KEY2;
  // WDOG->TOVAL = 0xFFFFU;
  // WDOG->CS1 = (uint8_t)((WDOG->CS1) & ~WDOG_CS1_EN_MASK) | WDOG_CS1_UPDATE_MASK;
  // WDOG->CS2 |= 0;
}

void watchdog_kick(void)
{
  // WDT disabled for now
}
