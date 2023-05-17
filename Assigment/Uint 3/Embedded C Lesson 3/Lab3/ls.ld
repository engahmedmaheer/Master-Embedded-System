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
		. =ALIGN(4);
		_E_text = .;


	}>flash

	.data :{
	_S_DATA=.;
	*(.data)
 _E_DATA=.;
	}>sram AT>flash  


	.bss :{
	_S_BSS = .;
	*(.bss)
	_E_BSS_=.;
	. =ALIGN(4);
	. = . + 0x1000 ; 
	_stack_top = . ;
	}>sram

}