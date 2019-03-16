#include<stdio.h>
const double eps=1e-8;
int k,n;
double a[20000];
double f(double ave)
{
	int i,sum=0,x;
	for(i=0;i<n;i++)
	{
		x=a[i]/ave;
		sum=sum+x;
	}
	return sum;
//	if(sum<k)
//	return 0;
//	else
//	return 1;
}
double cum(double l,double r,int k)
{
	double mid;
	while(l<=r)
	{
		mid=(l+r)/2.0;
		if(f(mid)<k)
		r=mid;
		else
		l=mid;
	}
	return l;
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
		        sum=sum+a[i];
		}
		ave=sum/k;
		printf("%.2f\n",((int)(cum(1,ave,k)*100))/100.0);

	}
	return 0;
}

