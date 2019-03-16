#include<stdio.h>
int main()
{
	long long int i,a[1000003];
	a[0]=7;
	a[1]=11;
	for (i=2;i<1000003;i++)
		a[i]=a[i-1]+a[i-2];
	while (scanf("%lld",&i)!=EOF)
	{
		if (a[i]%3==0) printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}