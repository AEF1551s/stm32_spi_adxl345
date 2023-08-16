// System includes
#include <stm32f410rx.h>
#include <stm32f4xx.h>

// User includes
#include <stdint.h>
#include <user_types.h>
#include <user_functions.h>
#include <spi1.h>

// DEBUG
#include <debug_functons.h>
#include <stdio.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

// Pin declaration
/******SPI1 pins******/
pin_struct_TypeDef nss_pin;
pin_struct_TypeDef sck_pin;
pin_struct_TypeDef miso_pin;
pin_struct_TypeDef mosi_pin;
/********************/
// Functions
void clock_init()
{
  // GPIOA clock enable for PA4 - PA7 SPI pins
  SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOAEN);

  // SPI1 clock enable
  SET_BIT(RCC->APB2ENR, RCC_APB2ENR_SPI1EN);
}
void pin_init()
{
  /******SPI1 pins******/
  nss_pin = pin_setup(GPIOA, PIN4, ALTERNATE);
  sck_pin = pin_setup(GPIOA, PIN5, ALTERNATE);
  miso_pin = pin_setup(GPIOA, PIN6, ALTERNATE);
  mosi_pin = pin_setup(GPIOA, PIN7, ALTERNATE);

  // Set AF mode
  SET_BIT(GPIOA->AFR[0], GPIO_AFRL_AFRL4_0 | GPIO_AFRL_AFRL4_3);
  SET_BIT(GPIOA->AFR[0], GPIO_AFRL_AFRL5_0 | GPIO_AFRL_AFRL5_3);
  SET_BIT(GPIOA->AFR[0], GPIO_AFRL_AFRL6_0 | GPIO_AFRL_AFRL6_3);
  SET_BIT(GPIOA->AFR[0], GPIO_AFRL_AFRL7_0 | GPIO_AFRL_AFRL7_3);
  /*********************/
}

int main(void)
{
  clock_init();
  pin_init();

  /* Loop forever */
  while (true)
  {
  }
}