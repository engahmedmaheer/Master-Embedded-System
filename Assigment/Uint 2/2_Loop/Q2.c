#include <stdio.h>

int main() {

	int i , product, num ;
	for(i=1 , product=1 ; i<5 ; i++)
	{
		printf("Enter your %d value", i);
		fflush(stdout);
		scanf("%d",&num);
		if(num==0)
			continue ;
		product*=num ;
	}
	printf("produect = %d", product);

	return 0;
}
