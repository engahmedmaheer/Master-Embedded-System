/*Implement Sbark functuin |  Prepared by Eng Ahmed Maher*/
void* _sbark (int incr)
{
	/*Sbark Function For Dynamicallocation */
	 static unsigned char* heap_ptr = NULL ;
	  /*Local Var To Detect Prev Ptr Every Time Calling / Reseve */
	 unsigned char* prev_ptr = NULL ;

	 /*Go To Linker To Get End Of BSS it's a symbol*/

	 extern unsigned int _E_bss ;  
	 extern unsigned int _heap_End ;  


	 /*if first time initalized*/
	 if (heap_ptr == NULL)
	 	/*Point heap to end of bss to start loction for heap*/
	 	heap_ptr = (unsigned char*)&_E_bss ;
	 prev_ptr = heap_ptr ;

	 /*Protect Stack*/
	 if ((heap_ptr + incr ) > (unsigned char * ) &_heap_End)
	 return (void *) NULL ; 

	 /*Booking Increment Size*/
	 heap_ptr += incr ;

	 return (void*) prev_ptr ;
}