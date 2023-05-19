/*Linker Script For Cortex M3 | Prebeard By Eng.Ahmed Maher | With Dynamic MemoryAllocation*/

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
	*(.data.*)  /*For .data malloc*/
 _E_DATA=.;

	}>sram AT>flash  


	.bss :{

	_S_BSS = .;
	*(.bss)
	_E_BSS_=.;
	. =ALIGN(4);
	. = . + 0x1000 ; 
	_heap_End = . ;
	. =ALIGN(4);
	. = . + 0x1000 ;
	_stack_top = . ;

	}>sram

}

/*
							Image For RAM
 -> Stack_Top
 -> Stack 		/*1000*/
 -> Heap      /*1000*/
 -> .bss
 -> .data
*/