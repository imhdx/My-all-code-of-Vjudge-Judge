#include<bits/stdc++.h>
using namespace std;
long long dp[83*83][83][83];
int main()
{
    int T;scanf("%d",&T);
    while (T--)
    {
        int n,m,mod;scanf("%d%d%d",&n,&m,&mod);
        for (int w=0;w<=n*m;w++) for (int i=0;i<=n;i++) for (int j=0;j<=m;j++) dp[w][i][j]=0;
        dp[1][1][1]=n*m%mod;
        for (int w=1;w<=n*m;w++)
        {
            for (int i=1;i<=n;i++)
            {
                for (int j=1;j<=m;j++)
                {
                    if (dp[w][i][j])
                    {
                        (dp[w+1][i][j]+=dp[w][i][j]*(i*j-w)%mod)%=mod;
                        (dp[w+1][i+1][j]+=dp[w][i][j]*j*(n-i)%mod)%=mod;
                        (dp[w+1][i][j+1]+=dp[w][i][j]*i*(m-j)%mod)%=mod;
                    }
                }
            }
        }
        printf("%lld\n",dp[n*m][n][m]);
    }
//
    return 0;
}