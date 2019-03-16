#include<stdio.h>
int f(long long a)
{
	if (a/10==0) return a;
	long long c=0;
	while (a!=0)
	{
		c=c+a%10;
		a=a/10;
	}
	return f(c);
}
int main()
{
	long long int a;
	while (scanf("%lld",&a)!=EOF&&a!=0)
	{
		printf("%d\n",f(a));
	}
	return 0;
}