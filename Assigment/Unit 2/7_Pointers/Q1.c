void main()
{
		int m , *ab ;
		m=29 ;

		printf("Value Of m=%d\n",m);
		printf("Address Of m=%p\n",&m);
		ab=&m;
		printf("Address Of ab=%p\n",ab);
		printf("Value Of ab=%d\n",*ab);
		m=34 ;
		printf("The Value Of m assigned to ab\n");
		printf("The address Of ab =%p\n",ab);
		printf("The value Of ab =%d\n",*ab);
		*ab=7;
		printf("The address Of m =%p\n",&m);
		printf("The value Of m =%d\n",m);


}
