#include<stdio.h>
int main()
{
	double a,b,c,d,e,f;
	while (scanf("%*s%lf%lf",&a,&b)!=EOF)
	{
	scanf("%*s%lf%lf",&c,&d);
	scanf("%*s%lf%lf",&e,&f);
			printf("%.1lf\n",a*b+c*d+e*f);
	}
	return 0;
}