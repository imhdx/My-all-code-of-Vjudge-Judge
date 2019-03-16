#include<stdio.h>
int main()
{
	int i,s,n;
	int min,max,a[999];
	while (scanf("%d",&n)!=EOF)
	{
		s=0;
		scanf("%d",&a[0]);
		min=a[0];
		max=a[0];
		s=s+a[0];
		for (i=1;i<n;i++)
		{
			scanf("%d",&a[i]);
			if (min>a[i]) min=a[i];
			if (max<a[i]) max=a[i];
			s=s+a[i];
		}
		printf("%.2lf\n",(double)(s-min-max)/(n-2));
	}
	return 0;
}