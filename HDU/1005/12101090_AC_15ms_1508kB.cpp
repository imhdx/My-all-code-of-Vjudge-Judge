#include<stdio.h>
int main()
{
	long int i,a,b,n,c[55],t;
	while (scanf("%ld%ld%ld",&a,&b,&n)!=EOF)
	{
		if (a==0&&b==0&&n==0) break;
		c[0]=0;
		c[1]=1;
		c[2]=1;
		a=a%7;
		b=b%7;
		for (i=3;i<55;i++)
		c[i]=(a*c[i-1]+b*c[i-2])%7;
		printf("%ld\n",c[n%49]);

	}
	return 0;
}