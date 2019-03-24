#include<bits/stdc++.h>
using namespace std;
long long dp[81][81][6410];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        dp[1][1][1]=n*m;
        for (int w=2;w<=n*m;w++)
        {
            for (int i=1;i<=n;i++)
            {
                for (int j=1;j<=m;j++)
                {
                    dp[i][j][w]=0;
                    if (i*j-w+1>0)
                    dp[i][j][w]+=dp[i][j][w-1]*(i*j-w+1)%k;
                    if (dp[i][j][w]>=k) dp[i][j][w]-=k;
                    dp[i][j][w]+=dp[i-1][j][w-1]*(n-i+1)%k*j%k;
                    if (dp[i][j][w]>=k) dp[i][j][w]-=k;
                    dp[i][j][w]+=dp[i][j-1][w-1]*(m-j+1)%k*i%k;
                    if (dp[i][j][w]>=k) dp[i][j][w]-=k;
                }
            }
        }
        dp[n][m][n*m]%=k;
        if (dp[n][m][n*m]<0) dp[n][m][n*m]+=k;
        printf("%lld\n",dp[n][m][n*m]);
    }
    return 0;
}
