/*!
 * @file
 * @brief
 */

#include "watchdog.h"
#include "fsl_wwdt.h"

enum {
  fixed_prescalar = 4,
  clock_frequency = 100 * 1000,
  timeout_seconds = 1,

  kick_period_msec = 100
};

static struct {
  tiny_timer_t timer;
} self;

static void kick(tiny_timer_group_t* group, void* context)
{
  (void)context;
  (void)group;
  WWDT_Refresh(WWDT);
}

void watchdog_init(tiny_timer_group_t* timer_group)
{
  wwdt_config_t config = {
    .enableWwdt = true,
    .enableWatchdogReset = true,
    .enableWatchdogProtect = false,
    .windowValue = 0xFFFFFF,
    .timeoutValue = (timeout_seconds * clock_frequency) / fixed_prescalar,
    .warningValue = 0,
    .clockFreq_Hz = clock_frequency
  };
  WWDT_Init(WWDT, &config);

  tiny_timer_start_periodic(timer_group, &self.timer, kick_period_msec, kick, NULL);
}
