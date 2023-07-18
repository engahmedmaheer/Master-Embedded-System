void main()
{
	char alpha[27];
	int counter ;
	char* ptr = alpha ; //  &alpha[0]
	/*Sort alphapet in array */
	for(counter = 0 ; counter < 26 ; counter ++)
	{
		*ptr=counter +'A' ;
				ptr ++;
	}
	/*Make pointer reutrn poin to start of array*/
	ptr = alpha;

	printf("The alphapet Are \n:");
	for(counter =0 ; counter < 26 ; counter ++)
	{
		printf("%c", *ptr);
		ptr++;
	}
}