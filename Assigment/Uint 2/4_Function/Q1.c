#include <stdio.h>

int checknumber(int i );

int main()
{

	/*
	 * Prime number is number div only n/n | n/1
	 */
	int startnumber, endnumber , counter ;
	printf("Enter Your Start & End Number\n");
	fflush(stdout);	fflush(stdin);
	scanf("%d,%d",&startnumber,&endnumber);

	for (counter = startnumber+1 ; counter<endnumber ; counter++)
	{
		//
		int result = checknumber(counter);
		if (result ==1 )
			printf("number is prime ");
		else
			printf("number is not prime ");


	}
	return 0;
}
int checknumber(int num )
{
	int flag = 0 ;
	for (int j = 2 ; j <=num/2; j++)
		if (num%j == 0)
			flag=1 ;
		else
			flag=0;

	return flag ;
}
