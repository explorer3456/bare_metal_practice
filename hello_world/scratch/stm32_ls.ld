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
		_etext = .;
	}>FLASH AT> FLASH

	.data :
	{
		_sdata = .;
		*(.data)
		_edata = .;
	}>SRAM1 AT> FLASH

	.bss :
	{
		_sbss = .;
		*(.bss)
		_ebss = .;
	}>SRAM1 AT> SRAM1
}
