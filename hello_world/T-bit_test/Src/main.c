/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
#include <stdint.h>

void generate_interrupt(void)
{
       uint32_t *pSTIR = (uint32_t *)0xE000EF00;
       uint32_t *pISER0 = (uint32_t *)0xE000E100;

       // enable IRQ3
       *pISER0 |= (1<<3);

       // generate SWI
       *pSTIR = (0x3);

}

void change_access_level_unpriv(void)
{
	int control_reg;

	__asm__ ("MRS %0, CONTROL":"=r"(control_reg));

	control_reg |= 0x1;

	__asm__ ("MSR CONTROL, %0"::"r"(control_reg));
}

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	void (*func_ptr)(void);
    /* Loop forever */
	printf("heeee\n");

	// when you assign function pointer, compiler auto matcially assign LSB of "change_access_level_unpriv"
	// to 1. You can see that change access_level_unpriv function's address is even number such as 0x800700.
	// However, when you assign the address value of change_..x to func_ptr, the compiler put one bit to the address
	// Hence the func_ptr = 0x800701.
	// This is because Cortex M4 always run in thumb state.
	func_ptr = change_access_level_unpriv;

	//change_access_level_unpriv();
	func_ptr();

	//generate_interrupt();

	printf("hooooo\n");
	for(;;);
}

void RTC_WKUP_IRQHandler(void)
{
	printf("in handler mode\n");
}

void HardFault_Handler(void)
{
	printf("hard fault detected");
	while(1);

}
