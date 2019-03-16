#include<stdio.h>
int main()
{
	int k,i;
	long long int a[20000];
	long long int b[10000];
	a[1]=2;
	for (i=2;i<=20000;i++)
	a[i]=a[i-1]+i;
	for (i=1;i<=10000;i++)
	{
		b[i]=a[2*i]-2*i;
	}
	scanf("%d",&i);
	while (i--)
	{
		scanf("%d",&k);
		printf("%lld\n",b[k]);
	}
	return 0;
}