ENTRY(Reset_Handler)

MEMORY
{
	FLASH(RX):ORIGIN =0x08000000,LENGTH =1024K
	SRAM1(RWX):ORIGIN =0x20000000,LENGTH =128K
}

SECTIONS
{
	.text :
	{
		*(.vector)
		*(.text)
		*(.rodata)
		. = ALIGN(4);
		_etext = .;
	}>FLASH AT> FLASH

	.data :
	{
		_sdata = .;
		*(.data)
		. = ALIGN(4);
		_edata = .;
	}>SRAM1 AT> FLASH

	.bss :
	{
		_sbss = .;
		*(.bss)
		*(COMMON)
		. = ALIGN(4);
		_ebss = .;
	}>SRAM1 AT> SRAM1
}
