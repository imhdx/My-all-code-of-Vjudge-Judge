#include<bits/stdc++.h>
using namespace std;
long long dp[83][83][83*83];
int main()
{
    int T;scanf("%d",&T);
    while (T--)
    {
        int n,m,mod;scanf("%d%d%d",&n,&m,&mod);
        for (int w=0;w<=n*m;w++) for (int i=0;i<=n;i++) for (int j=0;j<=m;j++) dp[i][j][w]=0;
        dp[1][1][1]=n*m%mod;
        for (int w=1;w<=n*m;w++)
        {
            for (int i=1;i<=n;i++)
            {
                for (int j=1;j<=m;j++)
                {
                    if (dp[i][j][w])
                    {
                        (dp[i][j][w+1]+=dp[i][j][w]*(i*j-w)%mod)%=mod;
                        (dp[i+1][j][w+1]+=dp[i][j][w]*j*(n-i)%mod)%=mod;
                        (dp[i][j+1][w+1]+=dp[i][j][w]*i*(m-j)%mod)%=mod;
                    }
                }
            }
        }
        printf("%lld\n",dp[n][m][n*m]);
    }
    return 0;
}
