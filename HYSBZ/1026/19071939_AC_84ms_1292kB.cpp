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
        if (abs(i-pre)>=2)
        {
            ans+=dfs(pos-1,limit&&i==up,pre==-3&&i==0?-3:i);
        }
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
    return dfs(len,1,-3);
}
signed main()
{
    memset(dp,-1,sizeof(dp));
    int a,b;
    scanf("%lld%lld",&a,&b);
    printf("%lld\n",solve(b)-solve(a-1));
    return 0;
}
