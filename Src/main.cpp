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
extern pin_struct_TypeDef nss_pin;
extern pin_struct_TypeDef sck_pin;
extern pin_struct_TypeDef miso_pin;
extern pin_struct_TypeDef mosi_pin;
/********************/

// Functions
void clock_init()
{
  spi1_clock_init();
}
void pin_init()
{
  spi1_pin_init();
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