#include<bits/stdc++.h>
using namespace std;
int dp[20][10][15];
int digit[20];
int dfs(int pos,int status,int limit,int mod)
{
    if (pos<=0) return status==2&&!mod;
    if (!limit&&dp[pos][status][mod]!=-1) return dp[pos][status][mod];
    int up=limit?digit[pos]:9;
    int ans=0;
    for (int i=0;i<=up;i++)
    {
        int nmod=(mod*10+i)%13;
        if (status==2||(status==1&&i==3))
            ans+=dfs(pos-1,2,limit&&(i==up),nmod);
        else if (i==1)
            ans+=dfs(pos-1,1,limit&&(i==up),nmod);
        else
            ans+=dfs(pos-1,0,limit&&(i==up),nmod);
    }
    if (!limit) dp[pos][status][mod]=ans;
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
    return dfs(len,0,1,0);
}
int main()
{
    memset(dp,-1,sizeof(dp));
    int n;
    while (scanf("%d",&n)!=EOF)
        printf("%d\n",solve(n));
    return 0;
}