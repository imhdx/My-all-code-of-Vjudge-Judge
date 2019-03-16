#include<stdio.h>
int main()
{
	long long int xmax,xmin,ymax,ymin;
	long long int a,b;
	while (scanf("%lld%lld",&a,&b)!=EOF)
	{
		if (a==0&&b==0) break;
		xmin=xmax=a;
		ymin=ymax=b;
		while (scanf("%lld%lld",&a,&b)!=EOF&&a!=0&&b!=0)
		{
			if (a>=xmax) xmax=a;
			if (a<=xmin) xmin=a;
			if (b>=ymax) ymax=b;
			if (b<=ymin) ymin=b;
		}
		printf("%lld %lld %lld %lld\n",xmin,ymin,xmax,ymax);
		
	}
	return 0;
}