#include<stdio.h>
int main()
{
	double a=1,i=0,s=0;
	printf("n e\n");
	printf("- -----------\n");
	for (i=0;i<=9;i++)
	{
		if (i==0) a=1;
		else
		a=a*i;
		s=s+1/a;
		printf("%.lf %.10lg\n",i,s);
	}
	
	
	return 0;
}