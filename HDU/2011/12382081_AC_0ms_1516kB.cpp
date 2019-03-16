#include<stdio.h>
int main()
{
	int n;
	int i,t;
	double s;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		s=0;
		for (i=1;i<=n;i++)
		{
			if (i%2==0)
			s=s-1.0/i;
			else
			s=s+1.0/i;
		}
		printf("%.2lf\n",s);
	}
	return 0;
}