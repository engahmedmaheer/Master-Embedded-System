/*Linker Script For Cortex M3 | Prebeard By Eng.Ahmed Maher*/

MEMORY
{
  sram    (xrw)    : ORIGIN = 0x20000000,   LENGTH = 128K
  flash    (rx)    : ORIGIN = 0x8000000,   LENGTH = 512K
}

SECTIONS
{
	.text :{

		*(.vectors*)
		*(.text*)
		*(.rodata*)

	}>flash

	.data :{
	*(.data)
	}>flash


	.bss :{
	*(.bss)
	}>sram

}