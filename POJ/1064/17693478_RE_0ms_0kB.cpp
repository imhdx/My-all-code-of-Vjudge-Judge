#include<stdio.h>
//const double eps=1e-8;
int k,n;
int a[20000];
int max(int x,int y)
{
    if (x<y) return y;
    return x;
}
int f(int ave)
{
	int i,sum=0,x;
	for(i=0;i<n;i++)
	{
		x=(a[i])/ave;
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
		int sum=0;
		for(i=0;i<n;i++)
		{
		    double tmp;
				scanf("%lf",&tmp);
				a[i]=(int)100*tmp;
		        sum=max(sum,a[i]);
		}
		printf("%.2f\n",(double)cum(0,sum,k)/100.0);

	}
	return 0;
}
