#include<stdio.h>
#define PI 3.1415927
int main()
{
	double a;
	while (scanf("%lf",&a)!=EOF)
	{
		printf("%.3lf\n",4.0/3*PI*a*a*a);
	}
	return 0;
}