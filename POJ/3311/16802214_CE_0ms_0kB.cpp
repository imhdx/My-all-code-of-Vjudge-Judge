#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
int dp[1<<12][12];
int a[12][12];
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=0;i<=n;i++) for (int j=0;j<=n;j++) scanf("%d",&a[i][j]);
        for (int k=0;k<=n;k++)
            for (int i=0;i<=n;i++)
                for (int j=0;j<=n;j++)
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
        /*
        for (int i=0;i<=n;i++)
        {
            for (int j=0;j<=n;j++)
                printf("%d%c",a[i][j]," \n"[j==n]);
        }
        */
        for (int i=0;i<(1<<n);i++)
            for (int j=0;j<=n;j++)
                dp[i][j]=INF;
        for (int i=1;i<=n;i++) dp[1<<(i-1)][i]=a[0][i];
        int ans=INF;
        for (int i=0;i<(1<<n);i++)
        {
            for (int j=1;j<=n;j++)
            {
                if ((i>>(j-1))&1)
                {
                    for (int k=1;k<=n;k++)
                    {
                        if (j==k) continue;
                        dp[i|(1<<(k-1))][k]=min(dp[i|(1<<(k-1))][k],dp[i][j]+a[j][k]);
                    }
                }
                ans=min(ans,dp[(1<<n)-1][j]+a[j][0]);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
