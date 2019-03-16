#include<math.h>
#include<stdio.h>
//#define PI 3.1415927
int main()
{
	double a;
	while (scanf("%lf",&a)!=EOF)
	{
		printf("%.2lf\n",fabs(a));
	}
	return 0;
}