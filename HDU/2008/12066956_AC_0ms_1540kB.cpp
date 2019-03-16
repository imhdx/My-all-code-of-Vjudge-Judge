#include<stdio.h>
int main()
{
	double a;
	int q,w,e,n;
	while (scanf("%d",&n)!=EOF&&n!=0)
	{
		q=w=e=0;
		for (int i=1;i<=n;i++)
		{
			scanf("%lf",&a);
			if (a>0) q++;
			else if (a==0) w++;
			else e++;
		}
		printf("%d %d %d\n",e,w,q);
	}
	return 0;
}