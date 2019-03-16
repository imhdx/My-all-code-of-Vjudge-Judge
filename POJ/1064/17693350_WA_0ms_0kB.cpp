#include<stdio.h>
//const double eps=1e-8;
int k,n;
double a[20000];
int f(int ave)
{
	int i,sum=0,x;
	for(i=0;i<n;i++)
	{
		x=(int)(a[i]*100)/ave;
		sum=sum+x;
	}
	return sum;
//	if(sum<k)
//	return 0;
//	else
//	return 1;
}
int cum(int l,int r,int k)
{
	int mid;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(f(mid)<k)
		r=mid-1;
		else
		l=mid+1;
	}
	return r;
}
int main()
{
	while(~scanf("%d%d",&n,&k))
	{
		int i;
		double t;
		double sum=0;
		int ave=0;
		for(i=0;i<n;i++)
		{
				scanf("%lf",&a[i]);
		        sum=sum+a[i]*100;
		}
		ave=sum/k;
	   t=cum(0,ave,k);
		printf("%.2f\n",t/100.0);

	}
	return 0;
}
