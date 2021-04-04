/*!
 * @file
 * @brief
 */

#include "fsl_common.h"
#include "systick.h"

static struct {
  i_tiny_time_source_t interface;
  volatile unsigned ticks;
} self;

void SysTick_Handler(void)
{
  self.ticks++;
}

static tiny_time_source_ticks_t ticks(i_tiny_time_source_t* _self)
{
  (void)_self;
  return (tiny_time_source_ticks_t)self.ticks;
}

static const i_tiny_time_source_api_t api = { ticks };

i_tiny_time_source_t* systick_init(void)
{
  if(SysTick_Config(SystemCoreClock / 1000)) {
    NVIC_SystemReset();
  }

  NVIC_SetPriority(SysTick_IRQn, 7);

  self.interface.api = &api;

  return &self.interface;
}
