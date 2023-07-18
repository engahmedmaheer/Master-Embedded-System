#include <stdio.h>
				// Generat Factory of function

#define functiongenerator(name,var) int func_##name(int x)\
{ return x*var; }



void main()
{
	/*Make Function*/
	functiongenerator(Quadra,4);
	functiongenerator(double,2);
	/*Try it*/
	printf("%d\n",func_Quadra(13));
	printf("%d",func_double(21));


}