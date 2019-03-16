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
		if (i==0||i==1)
		printf("%d %d\n",(int)i,(int)s);
		else if (i==2)
		printf("%d %.1lf\n",(int)i,s);
		else
		printf("%d %.9lf\n",(int)i,s);
	}
	
	
	return 0;
}