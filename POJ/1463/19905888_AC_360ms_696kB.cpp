//
// Created by mhdx on 2019/5/27.
//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;

int n;
vector<int> v[1503];
int dp[1503][2];
void dfs(int now,int fa)
{
    dp[now][0]=0;
    dp[now][1]=1;
    for (int i=0;i<v[now].size();i++)
    {
        int u=v[now][i];
        if (u==fa) continue;
        dfs(u,now);
        dp[now][0]+=dp[u][1];
        dp[now][1]+=min(dp[u][1],dp[u][0]);
    }
}
int main()
{
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=0;i<=n;i++) v[i].clear();
        for (int i=0;i<n;i++)
        {
            int x,y,k;
            scanf("%d:(%d)",&x,&k);
            for (int j=0;j<k;j++)
            {
                scanf("%d",&y);
                v[x+1].push_back(y+1);
                v[y+1].push_back(x+1);
            }
        }
        dfs(1,0);
        // for (int i=1;i<=n;i++) printf("%d %d\n",dp[i][1],dp[i][0]);
        printf("%d\n",min(dp[1][1],dp[1][0]));
    }
    return 0;
}