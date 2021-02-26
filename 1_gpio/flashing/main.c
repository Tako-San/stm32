#include "stm32f0xx_ll_rcc.h"
#include "stm32f0xx_ll_system.h"
#include "stm32f0xx_ll_bus.h"
#include "stm32f0xx_ll_gpio.h"

/* some initial actions */ 
void gpio_config( )
{
  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOC);
 
  /* set 8th pin mode to output (blue lamp) */
  LL_GPIO_SetPinMode(GPIOC, LL_GPIO_PIN_8, LL_GPIO_MODE_OUTPUT);

  /* set 9th pin mode to output (green lamp) */
  LL_GPIO_SetPinMode(GPIOC, LL_GPIO_PIN_9, LL_GPIO_MODE_OUTPUT);

  return;
}

/* cycle for waiting */
void delay( )
{ for(uint32_t i = 0; i < 100000; ++i); }

int main()
{
  gpio_config();

  while(1)
  {
    LL_GPIO_SetOutputPin(GPIOC, LL_GPIO_PIN_8);
    LL_GPIO_ResetOutputPin(GPIOC, LL_GPIO_PIN_9);

    delay();

    LL_GPIO_ResetOutputPin(GPIOC, LL_GPIO_PIN_8);
    LL_GPIO_SetOutputPin(GPIOC, LL_GPIO_PIN_9);

    delay();
  };
}
