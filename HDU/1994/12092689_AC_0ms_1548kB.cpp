#include<stdio.h>
int main()
{
	int t;
	double a,b,c,d,e;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%lf%lf%lf%lf%lf",&a,&b,&c,&d,&e);
		printf("%.1lf\n",(a+a*(c/100*b/365))*(1+e/100));
		printf("%.1lf\n",(a+a*(d/100*(365+b)/365)));
	}
	
	
	return 0;
}