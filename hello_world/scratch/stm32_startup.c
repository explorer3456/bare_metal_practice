#include <stdint.h>

#define SRAM_START	(0x20000000U)
#define SRAM_SIZE	(128 * 1024U) // 128 KB
#define SRAM_END	((SRAM_START) + (SRAM_SIZE))

#define STACK_START	SRAM_END

void Reset_Handler(void);
void NMI_Handler(void);

uint32_t vectors[] __attribute__ ((section(".vector"))) = {

	STACK_START, // MSP
	(uint32_t *)Reset_Handler,
};

void Reset_Handler(void)
{
}

void NMI_Handler(void)
{
}
