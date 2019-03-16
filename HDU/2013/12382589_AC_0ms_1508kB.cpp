#include<stdio.h>
int main()
{
	long long int s;
	long long int a;
	while (scanf("%lld",&a)!=EOF)
	{
		s=1;
		for (;a>1;a--)
		s=s*2+2;
		printf("%lld\n",s);
	}
	return 0;
}