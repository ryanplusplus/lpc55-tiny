/*!
 * @file
 * @brief
 */

#include "interrupts.h"
#include "clock.h"
#include "watchdog.h"
#include "systick.h"
#include "tiny_timer.h"
#include "heartbeat.h"

static tiny_timer_group_t timer_group;

int main(void)
{
  interrupts_disable();
  {
    clock_init();
    tiny_timer_group_init(&timer_group, systick_init());
    watchdog_init(&timer_group);
    heartbeat_init(&timer_group);
  }
  interrupts_enable();

  while(1) {
    tiny_timer_group_run(&timer_group);
  }
}
