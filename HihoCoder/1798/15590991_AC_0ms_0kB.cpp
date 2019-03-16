#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
long long int dp[1010][5];
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        int i;
        dp[1][0]=9;
        dp[1][1]=1;
        dp[1][2]=0;
        for (i=2;i<=n;i++)
        {
            dp[i][0]=9ll*(dp[i-1][0]+dp[i-1][1]+dp[i-1][2])%mod;
            dp[i][1]=dp[i-1][0];
            dp[i][2]=dp[i-1][1];
        }
        long long ans=0;
        for (i=1;i<=n-1;i++)
        {
            if (dp[i][1]>0&&dp[n-i][2]>0)
                ans=(ans+dp[i][1]*dp[n-i][2]%mod)%mod;
        }
        printf("%lld\n",ans);
    }

    return 0;
}
