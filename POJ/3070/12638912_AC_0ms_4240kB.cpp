#include<stdio.h>
int main()
{
	long long int i,n;
	int a[1000000];
	a[0]=0;
	a[1]=1;
	for (i=2;;i++)
	{
		a[i]=(a[i-1]+a[i-2])%10000;
		if (a[i]==1&&a[i-1]==0) break;
	}
	i--;
	while (scanf("%lld",&n)!=EOF)
	{
		if (n==-1) break;
		printf("%d\n",a[n%i]);
	}
	return 0;
}