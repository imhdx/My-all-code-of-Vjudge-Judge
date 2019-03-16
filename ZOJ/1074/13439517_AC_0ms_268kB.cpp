#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int a[101][101];
int sum[101][101];
int dp[101];
int main()
{
    int n;
    int i,j,k,w;
    while (scanf("%d",&n)!=EOF)
    {
        for (i=0;i<n;i++)
        {
            for (j=0;j<n;j++)
                scanf("%d",&a[i][j]);
        }
        int maxx=-999999999;
        for (i=0;i<n;i++)
        {
            memset(sum,0,sizeof(sum));
            for (j=i;j<n;j++)
            {
                memset(dp,0,sizeof(dp));
                for (k=0;k<n;k++)
                {
                    if (j-1<0) sum[j][k]=a[j][k];
                    sum[j][k]=sum[j-1][k]+a[j][k];
                    if (k-1<0) dp[k]=sum[j][k];
                    else
                    {
                        if (dp[k-1]<0) dp[k]=sum[j][k];
                        else
                            dp[k]=sum[j][k]+dp[k-1];
                    }
                    if (maxx<dp[k]) maxx=dp[k];
                }
            }
        }
        printf("%d\n",maxx);
    }
    return 0;
}
