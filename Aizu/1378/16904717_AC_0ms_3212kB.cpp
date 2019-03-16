#include<bits/stdc++.h>
using namespace std;
long long int dp[120][5];
int main()
{
    long long int l,k;
    while (scanf("%lld%lld",&l,&k)!=EOF)
    {
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for (int i=1;i<=l;i++)
        {
            dp[i][0]+=(dp[i-1][1]+dp[i-1][2]);
            dp[i][1]+=dp[i-1][0];
            if (i-k>=0) dp[i][2]+=dp[i-k][0];
        }
        long long int ans=0;
        for (int i=0;i<=l;i++) ans+=(dp[i][1]+dp[i][2]);
        printf("%lld\n",ans);
    }

    return 0;
}
