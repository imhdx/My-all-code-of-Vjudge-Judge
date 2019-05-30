//
// Created by mhdx on 2019/5/27.
//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<vector>
using namespace std;
int n;
vector<int> v[10004];
int dp[10004];
int ans[10004];
void dfs(int now,int fa)
{
    dp[now]=1;
    for (int i=0;i<v[now].size();i++)
    {
        int u=v[now][i];
        if (u==fa) continue;
        dfs(u,now);
        dp[now]+=dp[u];
    }
    int flag=0;
    for (int i=0;i<v[now].size();i++)
    {
        int u=v[now][i];
        if (u==fa) continue;
        if (dp[u]>n/2) flag=1;
    }
    if (n-dp[now]>n/2) flag=1;
    if (flag==0) ans[now]=1;
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1,0);
    for (int i=1;i<=n;i++)
        if (ans[i]==1) printf("%d\n",i);
    return 0;
}