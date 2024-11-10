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
		*(.init)
		*(.fini)
		*(.rodata)
		. = ALIGN(4);
		_etext = .;
	}>FLASH AT> FLASH

	_la_data = LOADADDR(.data);
	.data :
	{
		_sdata = .;
		*(.data)
		*(.init_array)
		*(.fini_array)
		. = ALIGN(4);
		_edata = .;
	}>SRAM1 AT> FLASH

	.bss :
	{
		_sbss = .;
		__bss_start__ = _sbss;
		*(.bss)
		*(COMMON)
		. = ALIGN(4);
		_ebss = .;
		__bss_end__ = _ebss;
		. = ALIGN(4);
		end = .;
		__end__ = .;
	}>SRAM1 AT> SRAM1
}
