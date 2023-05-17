#include <stdio.h>

int main() {

	int number, counter ,element,re ;
	printf("Enter Number of elements");
	fflush(stdin); fflush(stdout);
	scanf("%d", &number);
	int Array[number];
	/*Insert elements*/
	for (counter=0 ; counter<number ; counter++)
	{
		printf("Enter  elements");
			fflush(stdin); fflush(stdout);
			scanf("%d", &Array[counter]);
	}
	printf("Enter  elements that want to search");
				fflush(stdin); fflush(stdout);
				scanf("%d", &element);
				for (counter=0 ; counter<number ; counter++)
				{
					if (Array[counter]==element)
						re=counter;
					else
						counter++ ;

				}
				printf("Your Elemnt was in %d", re+1);



    return 0;
}
/*Or */
/*
#include <stdio.h>

int main() {
	int number, counter ,element ;
	printf("Enter Number of elements");
	fflush(stdin); fflush(stdout);
	scanf("%d", &number);
	int Array[number];
	
	for (counter=0 ; counter<number ; counter++)
	{
		printf("Enter  elements");
			fflush(stdin); fflush(stdout);
			scanf("%d", &Array[counter]);
	}
	printf("Enter  elements that want to search");
				fflush(stdin); fflush(stdout);
				scanf("%d", &element);
				counter=0 ;
				while(counter < number && element !=Array[counter])
				{
					counter++ ;
				}
				if (counter < number )
				{
					printf("Location is %d", counter+1);
				}
				else
					printf("Not Found");

    return 0;
}
*/