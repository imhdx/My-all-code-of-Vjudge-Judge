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

int main()
{
	while(scanf("%d %d", &n, &k) != EOF)
	{
		int i;
		int sum=0;
		for(i=0;i<n;i++)
		{
		    double tmp;
				scanf("%lf",&tmp);
				a[i]=100*tmp;
		        sum=max(sum,a[i]);
		}
		int l=1;
		int r=sum;
		int mid;
		while(l<=r)
	{
		mid=(l+r)/2;
		if(f(mid)<k)
		r=mid-1;
		else
		l=mid+1;
	}
		printf("%.2f\n",(double)r/100.0);

	}
	return 0;
}
