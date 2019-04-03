#include<bits/stdc++.h>
using namespace std;
int digit[30];
int dp[30][12];
int dfs(int pos,int lead,int limit,int pre)///lead
{
    if (pos==-1) return 1;
    if (!limit&&!lead&&dp[pos][pre]!=-1) return dp[pos][pre];
    int up=limit?digit[pos]:9;
    int ans=0;
    for (int i=0;i<=up;i++)
    {
        if (lead||abs(i-pre)>=2)
        {
            ans+=dfs(pos-1,lead&&i==0,limit&&i==digit[pos],i);
        }
    }
    if (!limit&&!lead&&dp[pos][pre]!=-1) dp[pos][pre]=ans;
    return ans;
}
int solve(int n)
{
    int len=0;
    while (n)
    {
        digit[len++]=n%10;
        n/=10;
    }
    return dfs(len,1,1,0);
}
int main()
{
    memset(dp,-1,sizeof(dp));
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d\n",solve(b)-solve(a-1));
    return 0;
}
