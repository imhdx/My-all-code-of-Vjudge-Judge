#include<stdio.h>
int main()
{
	double s=0;
	double x,y;
	while (scanf("%*s%lf%lf",&x,&y)!=EOF)
	{
		s=s+x*y;
	}
	printf("%.1lf\n",s);
	return 0;
}