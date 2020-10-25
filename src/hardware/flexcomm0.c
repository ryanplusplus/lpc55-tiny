/*!
 * @file
 * @brief
 */

#include "fsl_common.h"
#include "fsl_iocon.h"
#include "fsl_usart.h"
#include "fsl_clock.h"
#include "flexcomm0.h"
#include "tiny_event.h"

enum {
  rx_port = 0,
  rx_pin = 29,

  tx_port = 0,
  tx_pin = 30
};

static tiny_event_t send_complete;
static tiny_event_t receive;
static i_tiny_uart_t instance;

void FLEXCOMM0_IRQHandler(void)
{
  if((kUSART_RxFifoNotEmptyFlag | kUSART_RxError) & USART_GetStatusFlags(USART0)) {
    tiny_event_publish(&receive, &(tiny_uart_on_receive_args_t){ USART_ReadByte(USART0) });
  }
  else if(kUSART_TxFifoEmptyFlag & USART_GetStatusFlags(USART0)) {
    tiny_event_publish(&send_complete, NULL);
  }
}

static void send(i_tiny_uart_t* self, uint8_t byte)
{
  (void)self;
  USART_WriteByte(USART0, byte);
}

static i_tiny_event_t* on_send_complete(i_tiny_uart_t* self)
{
  (void)self;
  return &send_complete.interface;
}

static i_tiny_event_t* on_receive(i_tiny_uart_t* self)
{
  (void)self;
  return &receive.interface;
}

static const i_tiny_uart_api_t api = { send, on_send_complete, on_receive };

static inline void init_pins(void)
{
  CLOCK_EnableClock(kCLOCK_Iocon);

  IOCON_PinMuxSet(
    IOCON,
    rx_port,
    rx_pin,
    IOCON_PIO_FUNC(1) |
      IOCON_PIO_MODE(0) |
      IOCON_PIO_INVERT(0) |
      IOCON_PIO_DIGIMODE(1) |
      IOCON_PIO_SLEW(0) |
      IOCON_PIO_OD(0));

  IOCON_PinMuxSet(
    IOCON,
    tx_port,
    tx_pin,
    IOCON_PIO_FUNC(1) |
      IOCON_PIO_MODE(0) |
      IOCON_PIO_INVERT(0) |
      IOCON_PIO_DIGIMODE(1) |
      IOCON_PIO_SLEW(0) |
      IOCON_PIO_OD(0));
}

static inline void init_usart(void)
{
  CLOCK_AttachClk(kFRO12M_to_FLEXCOMM0);
  CLOCK_EnableClock(kCLOCK_FlexComm0);

  usart_config_t config = {
    .baudRate_Bps = 230400,
    .parityMode = kUSART_ParityDisabled,
    .stopBitCount = kUSART_OneStopBit,
    .bitCountPerChar = kUSART_8BitsPerChar,
    .loopback = false,
    .enableRx = true,
    .enableTx = true,
    .enableContinuousSCLK = false,
    .enableMode32k = false,
    .txWatermark = kUSART_TxFifo0,
    .rxWatermark = kUSART_RxFifo1,
    .syncMode = kUSART_SyncModeDisabled,
    .clockPolarity = kUSART_RxSampleOnFallingEdge
  };
  USART_Init(USART0, &config, CLOCK_GetFlexCommClkFreq(0));

  USART_EnableInterrupts(USART0, kUSART_RxLevelInterruptEnable | kUSART_RxErrorInterruptEnable | kUSART_TxLevelInterruptEnable);
  EnableIRQ(FLEXCOMM0_IRQn);
}

i_tiny_uart_t* flexcomm0_init(void)
{
  init_pins();
  init_usart();

  tiny_event_init(&send_complete);
  tiny_event_init(&receive);
  instance.api = &api;

  return &instance;
}
