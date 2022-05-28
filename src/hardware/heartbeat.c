/*!
 * @file
 * @brief
 */

#include <stddef.h>
#include <stdbool.h>
#include "heartbeat.h"
#include "fsl_gpio.h"

enum {
  port = 1,
  pin = 6,

  half_period_in_msec = 500,
};

static struct {
  tiny_timer_t timer;
} self;

static void blink(void* context)
{
  (void)context;
  GPIO_PortToggle(GPIO, port, 1 << pin);
}

void heartbeat_init(tiny_timer_group_t* timer_group)
{
  GPIO_PinInit(GPIO, port, pin, &(gpio_pin_config_t){ kGPIO_DigitalOutput, 0 });
  tiny_timer_start_periodic(timer_group, &self.timer, half_period_in_msec, NULL, blink);
}
