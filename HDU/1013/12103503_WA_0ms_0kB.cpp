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
	int i;
	long long int a[99999];
	for (i=0;;i++)
	{
		scanf("%lld",&a[i]);
		if (a[i]==0) break;
	}
	for (i=0;;i++)
	{
		if (a[i]==0) break;
		printf("%d\n",f(a[i]));
	}
	return 0;
}