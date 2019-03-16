#include<stdio.h>
int main()
{
	long int i,a[99999];
	a[0]=7;
	a[1]=11;
	for (i=2;i<99999;i++)
		a[i]=a[i-1]+a[i-2];
	while (scanf("%ld",&i)!=EOF)
	{
		if (a[i]%3==0) printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}