//
// Created by mhdx on 2019/5/28.
//

#include<bits/stdc++.h>
using namespace std;
#define int long long
int digit[30];
int dp[30][12];
int dfs(int pos,int limit,int pre)///lead
{
    if (pos<=0) return 1;
    if (!limit&&pre>=0&&dp[pos][pre]!=-1) return dp[pos][pre];
    int up=limit?digit[pos]:9;
    int ans=0;
    for (int i=0;i<=up;i++)
    {
        if (i==4||pre==6&&i==2) continue;
        ans += dfs(pos - 1, limit && i == up, pre == -1 && i == 0 ? -1 : i);
    }
    if (!limit&&pre>=0) dp[pos][pre]=ans;
    return ans;
}
int solve(int n)
{
    int len=0;
    while (n)
    {
        digit[++len]=n%10;
        n/=10;
    }
    return dfs(len,1,-1);
}
signed main()
{
    memset(dp,-1,sizeof(dp));
    int a,b;
    while (scanf("%lld%lld",&a,&b)!=EOF)
    {
        if (a==0&&b==0) return 0;
        printf("%lld\n",solve(b)-solve(a-1));
    }
    return 0;
}
//