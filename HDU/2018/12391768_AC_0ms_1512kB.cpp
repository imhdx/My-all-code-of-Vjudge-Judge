#include<stdio.h>
int main()
{
	int i;
	long long int a[100];
	a[1]=1;
	a[2]=2;
	a[3]=3;
	for (i=4;i<=99;i++)
	a[i]=a[i-1]+a[i-3];
	while (scanf("%d",&i)!=EOF)
	{
		if (i==0)break;
		printf("%lld\n",a[i]);
	}
	return 0;
}