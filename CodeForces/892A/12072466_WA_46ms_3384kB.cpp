#include<stdio.h>
int main()
{
	int i,j,n,s,max,cmax;
	long long int a[100003],b[100003];
	while (~scanf("%d",&n))
	{
		s=0;
		for (i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			s=s+a[i];
		}
		for (i=1;i<=n;i++)
		scanf("%lld",&b[i]);
		max=b[0];
		j=0;
		for (i=1;i<=n;i++)
		{
			if (b[i]>=max) {max=b[i];j=i;}
		}
		b[j]=-1;
		cmax=b[0];
		for (i=1;i<=n;i++)
		{
			if (b[i]>=cmax) cmax=b[i];
		}
		if (s<=(max+cmax))
		printf("YES\n");
		else
		printf("NO\n");
	}
	
	
	return 0;
	
	
}