#include<stdio.h>
int main()
{
	int i,n;
	double a[200];
	double s,k;
	while (scanf("%d",&n)!=EOF)
	{
		s=0;
		for (i=0;i<n;i++)
		{
			scanf("%lf",&a[i]);
			s=s+1/a[i];
		}
		scanf("%lf",&k);
		printf("%.2lf\n",k/s);
		
	}
	return 0;
}