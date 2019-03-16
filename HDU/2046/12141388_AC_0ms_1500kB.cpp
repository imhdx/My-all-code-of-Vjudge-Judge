#include<stdio.h>
int main()
{
	long long int a[54];
	int i;
	a[0]=1;
	a[1]=1;
	a[2]=2;
	for (i=3;i<54;i++)
	{
		a[i]=a[i-1]+a[i-2];
	}
	while (scanf("%d",&i)!=EOF)
	{
		printf("%lld\n",a[i]);
	}
	
	return 0;
}