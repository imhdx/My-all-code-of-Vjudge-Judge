#include<stdio.h>
int main()
{
	int a[200],b[200];
	int min,max,t,i,j,n,count;
	while (scanf("%d",&n)!=EOF&&n!=0)
	{
		count=1;
		for (i=1;i<=n;i++)
		scanf("%d%d",&a[i],&b[i]);
		for (i=1;i<=n;i++)
		{
			for (j=1;j+1<=n;j++)
			{
				if (b[j]>b[j+1]) {t=b[j];b[j]=b[j+1];b[j+1]=t;t=a[j];a[j]=a[j+1];a[j+1]=t;}
				if (b[j]==b[j+1])
				{
					if (a[j]>a[j+1]){t=a[j];a[j]=a[j+1];a[j+1]=t;}
				}
			}
		}
		min=1;
		while (1)
		{
			for (j=min+1;j<=n;j++)
			{
				if (a[j]>=b[min]) {min=j;break;}
			}
			if (j<=n) count++;
			if (j==n+1) break;

		}
		printf("%d\n",count);
	}
	return 0;
}