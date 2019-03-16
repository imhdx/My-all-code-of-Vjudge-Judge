#include<stdio.h>
int main()
{
	int t,n,a[200][200],i,j;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);	
		for (i=1;i<=n;i++)
		for (j=1;j<=i;j++)
			scanf("%d",&a[i][j]);
		for (i=n-1;i>=1;i--)
		{
			for (j=i;j>=1;j--)
			{
				if (a[i+1][j]<a[i+1][j+1])
				a[i][j]=a[i][j]+a[i+1][j+1];
				else
				a[i][j]=a[i][j]+a[i+1][j];
			}
		}
		printf("%d\n",a[1][1]);		
	}
	return 0;
}