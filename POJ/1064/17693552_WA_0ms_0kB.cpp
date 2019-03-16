#include<stdio.h>
//const double eps=1e-8;
int k,n;
double a[20000];
double f(double ave)
{
	int i,sum=0,x;
	for(i=0;i<n;i++)
	{
		x=(a[i]*100)/ave;
		sum=sum+x;
	}
	return sum;
//	if(sum<k)
//	return 0;
//	else
//	return 1;
}

int main()
{
	while(~scanf("%d%d",&n,&k))
	{
		int i;
		double t;
		double sum=0;
		double ave=0;
		for(i=0;i<n;i++)
		{
				scanf("%lf",&a[i]);
		        sum=sum+a[i]*100;
		}
		ave=sum/k;
		double l=0;
		double r=ave;
		double mid;
	while(l<=r)
	{
		mid=(l+r)/2.0;
		if(f(mid)<k)
		r=mid-1;
		else
		l=mid+1;
	}

		printf("%.2f\n",r/100.0);

	}
	return 0;
}
