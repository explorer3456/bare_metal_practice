#include <stdint.h>

#define SRAM_START	(0x20000000U)
#define SRAM_SIZE	(128 * 1024U) // 128 KB
#define SRAM_END	((SRAM_START) + (SRAM_SIZE))

#define STACK_START	SRAM_END

void Reset_Handler(void);
void Default_Handler(void);
void NMI_Handler(void) __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler(void) __attribute__((weak, alias("Default_Handler")));

uint32_t vectors[] __attribute__ ((section(".vector"))) = {

	STACK_START, // MSP
	(uint32_t *)Reset_Handler,
	(uint32_t *)NMI_Handler,
	(uint32_t *)HardFault_Handler
};

void Default_Handler(void)
{
	while(1);
}

void Reset_Handler(void)
{
}
