#include<stdio.h>
int main()
{
	int j,max,i,n,a[99999],t;
	scanf("%d",&t);
	while (t--)
	{
		max=0;
		scanf("%d",&n);
		for (i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			if (a[i]>max) max=a[i];
		}
		for (i=max;;i=i+max)
		{
			for (j=0;j<n;j++)
			{
				if (i%a[j]!=0) break;
			}
			if (j==n) {printf("%d\n",i);break;}
		}
	}
	
	return 0;
	
}