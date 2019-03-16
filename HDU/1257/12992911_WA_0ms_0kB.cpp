#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[999999];
int dp[999999];
int main()
{
	int n;
	while (scanf("%d",&n)!=EOF)
	{
		int i,j,k;
		for (i=0;i<n;i++)
		scanf("%d",&a[i]);
		j=0;
		k=0;
		dp[j]=a[0];
		for (i=1;i<n;i++)
		{
			for (j=k;j>=0;j--)
			{
				if (dp[j]>=a[i])
				{
					dp[j]=a[i];
					sort(dp,dp+k+1);
					break;
				}
			}
			if (j<0)
			{
				dp[++k]=a[i];
				sort(dp,dp+k+1);
			}
		}
		printf("%d\n",k+1);
	}
	return 0;
}