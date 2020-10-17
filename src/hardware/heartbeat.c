/*!
 * @file
 * @brief
 */

#include <stddef.h>
#include <stdbool.h>
#include "LPC55S16.h"
#include "heartbeat.h"

enum {
  port = 1,
  pin = 6,

  half_period_in_msec = 500,
};

static struct {
  tiny_timer_t timer;
} self;

static void blink(tiny_timer_group_t* group, void* context)
{
  (void)context;
  GPIO->NOT[port] = (1 << pin);
}

void heartbeat_init(tiny_timer_group_t* timer_group)
{
  GPIO->DIR[port] |= (1 << pin);

  tiny_timer_start_periodic(timer_group, &self.timer, half_period_in_msec, blink, NULL);
}
