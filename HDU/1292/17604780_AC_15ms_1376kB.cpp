#include<bits/stdc++.h>
using namespace std;
long long dp[30][30];
int main()
{
    dp[1][0]=0;
    dp[1][1]=1;
    dp[2][1]=1;
    dp[2][2]=1;

    for (int i=3;i<30;i++)
    {
        dp[i][i]=1;
        dp[i][1]=1;
        dp[i][0]=0;
        for (int j=2;j<i;j++)
        {
            dp[i][j]=dp[i-1][j-1]+dp[i-1][j]*j;
        }
    }

    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        long long ans=0;
        for (int i=0;i<=n;i++) ans+=dp[n][i];
        printf("%lld\n",ans);
    }
    return 0;
}
