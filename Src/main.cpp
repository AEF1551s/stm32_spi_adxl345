// System includes
#include <stm32f410rx.h>
#include <stm32f4xx.h>

// User includes
#include <stdint.h>
#include <user_types.h>
#include <user_functions.h>
#include <spi1.h>
#include <adxl345_spi.h>

// DEBUG
#include <debug_functons.h>
#include <stdio.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

// Pin declaration

// Functions
void clock_init()
{
}
void pin_init()
{
}

int main(void)
{
  clock_init();
  pin_init();
  adxl_init();
  /* Loop forever */
  uint8_t rxdata[6];
  uint16_t x, y, z;
  while (true)
  {
    adxl_read(0x32U, rxdata);
    x = ((rxdata[1] << 8) | rxdata[0]);
    y = ((rxdata[3] << 8) | rxdata[2]);
    z = ((rxdata[5] << 8) | rxdata[4]);
  }
}