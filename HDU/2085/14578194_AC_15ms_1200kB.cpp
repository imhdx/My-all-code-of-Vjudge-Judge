#include<stdio.h>
int main()
{
	long long int x,y,t;
	int k;
	while (scanf("%d",&k)!=EOF)
	{
		x=1;
		y=0;
		if (k==-1) break;
		while (k--)
		{
			t=x;
			x=3*t+2*y;
			y=t+y;
		}
		printf("%lld, %lld\n",x,y);
	}
	return 0;
}