#include <stdio.h>
main()
{
	int i,num,a[1000];
	long int c=1000000000,n=1;
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<num;i++)	
	{
	    n=(n*a[i])%(c+7);
	}
	printf("%ld",n);
}
