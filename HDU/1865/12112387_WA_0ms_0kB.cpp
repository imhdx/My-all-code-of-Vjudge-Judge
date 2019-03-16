#include<string.h>
#include<stdio.h>
int main()
{
	long long int t,i;
	char s[300];
	long long  a[202];
	a[1]=1;
	a[2]=2;
	for (i=3;i<=200;i++)
	{
		a[i]=a[i-1]+a[i-2];
	}

	scanf("%lld",&t);
	getchar();
	while (t--)
	{
		gets(s);
		printf("%lld\n",a[strlen(s)]);
	}
	return 0;
}