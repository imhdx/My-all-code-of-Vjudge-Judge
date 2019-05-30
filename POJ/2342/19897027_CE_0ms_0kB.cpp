//
// Created by mhdx on 2019/5/26.
//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
int dp[6003][2];
vector<int> v[6003];
int lian[6003];
void dfs(int now)
{
    dp[now][0]=0;
    dp[now][1]=lian[now];
    for (int u:v[now])
    {
        dfs(u);
        dp[now][0]+=max(0,max(dp[u][0],dp[u][1]));
        dp[now][1]+=max(0,dp[u][0]);
    }
}
int in[6003];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&lian[i]);
    for (int i=0;i<n-1;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        v[y].push_back(x);
        in[x]++;
    }
    int root=-1;
    for (int i=1;i<=n;i++)
    {
        if (in[i]==0) root=i;
    }
    //printf("%d\n",root);
    dfs(root);
    printf("%d\n",max(dp[root][0],dp[root][1]));
    return 0;
}