#include<stdio.h>
int main()
{
	long int i,a,b,n,c,t,d;
	while (scanf("%ld%ld%ld",&a,&b,&n)!=EOF)
	{
		if (a==0&&b==0&&n==0) break;
		c=1;
		d=1;
		for (i=2;i<=n;i++)
		{
			t=c;
			c=d;
			d=(d*a+b*t)%7;

		}
		printf("%ld\n",c);
	}
	return 0;
}