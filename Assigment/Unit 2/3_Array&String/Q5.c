#include <stdio.h>

int main() {
	char c[50];
	int counter ,count=0;
	printf("Enter Your String");
			fflush(stdout);
			fflush(stdin);
	gets(c);

				for(counter=0 ; c[counter]!='\0' ; counter++)
				{
						count++ ;
				}
				printf("freq is %d",count);



    return 0;
}
