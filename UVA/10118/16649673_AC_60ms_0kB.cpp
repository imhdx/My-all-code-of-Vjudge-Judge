#include<bits/stdc++.h>
using namespace std;
int n;
int a[10][42];
int dp[42][42][42][42];
int vis[42];
int top[10];
int dfs(int count)
{
    int &ans=dp[top[0]][top[1]][top[2]][top[3]];
    if (ans!=-1) return ans;
    ans=0;
    if (count>=5) return 0;
    for (int i=0;i<4;i++)
    {
        //printf("hi\n");
        if (top[i]>=n) continue;
        if (vis[a[i][top[i]]])
        {
            vis[a[i][top[i]]]=0;
            top[i]++;
            ans=max(ans,1+dfs(count-1));
            top[i]--;
            vis[a[i][top[i]]]=1;
        }
        else
        {
            vis[a[i][top[i]]]=1;
            top[i]++;
            ans=max(ans,dfs(count+1));
            top[i]--;
            vis[a[i][top[i]]]=0;
        }

    }
    return ans;
}
int main()
{
    while (scanf("%d",&n)!=EOF)
    {
        if (n==0) return 0;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<4;j++)
            {
                scanf("%d",&a[j][i]);
            }
        }
        memset(top,0,sizeof(top));
        memset(dp,-1,sizeof(dp));
        memset(vis,0,sizeof(vis));
        printf("%d\n",dfs(0));

    }
    return 0;
}
