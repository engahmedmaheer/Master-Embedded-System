#include <stdio.h>

int main() {

	int number , counter , sum =0 ;
	float average ;
	printf("Enter Your Number of elements");
	fflush(stdin); fflush(stdout);
	scanf("%d",&number);
	int Array[number];

	for (counter = 0 ; counter <number ; counter++)
	{
		printf("Enter Your  elements");
			fflush(stdin); fflush(stdout);
			scanf("%d",&Array[counter]);
			sum+=Array[counter];

	}
	average = sum/number ;
	printf("Your average is %.2f", average);




    return 0;
}
