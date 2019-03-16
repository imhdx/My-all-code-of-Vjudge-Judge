#include<string.h>
#include<stdio.h>
int main()
{
	long long int t,i;
	char s[300];
	long double  a[202];
	a[1]=1;
	a[2]=2;
	for (i=3;i<=200;i++)
	{
		a[i]=a[i-1]*10000/10000+a[i-2]*10000/10000;
	}

	scanf("%lld",&t);
	getchar();
	while (t--)
	{
		gets(s);
		printf("%.llf\n",a[strlen(s)]);
	}
	return 0;
}