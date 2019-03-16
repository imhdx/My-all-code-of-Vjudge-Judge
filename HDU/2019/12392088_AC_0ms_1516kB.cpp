#include<stdio.h>
int main()
{
	int a[999];
	int j,i,n,m;
	while (scanf("%d%d",&n,&m)!=EOF)
	{
		if (n==0&&m==0) break;
		for (i=0;i<n;i++)
		scanf("%d",&a[i]);
		for (i=0;i+1<n;i++)
		{
			if (a[i]<=m&&m<=a[i+1])
			{
				for (j=n;j>i+1;j--)
				a[j]=a[j-1];
				a[i+1]=m;
				break;
			}
		}
		if (i+1<n)
		{
			printf("%d",a[0]);
			for (i=1;i<=n;i++)
			printf(" %d",a[i]);
			printf("\n");
		}
		else
		{
			printf("%d",a[0]);
			for (i=1;i<n;i++)
			printf(" %d",a[i]);
			printf(" %d\n",m);
		}
	}
	return 0;
}