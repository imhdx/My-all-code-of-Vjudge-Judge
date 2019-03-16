#include<bits/stdc++.h>
using namespace std;
int a[102][102];
int dp[102][102];
int tx[]={0,1,0,-1};
int ty[]={1,0,-1,0};
int n,m;
void dfs(int x,int y)
{
    //printf("n=%d m=%d\n",n,m);
    for (int i=0;i<4;i++)
    {
        int dx=x+tx[i];
        int dy=y+ty[i];
        if (dx<0||dx>=n||dy<0||dy>=m) continue;
        if (a[dx][dy]>=a[x][y]) continue;

        dfs(dx,dy);

        dp[x][y]=max(dp[x][y],dp[dx][dy]+1);

    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        char s[100];
        scanf("%s%d%d",s,&n,&m);
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
                scanf("%d",&a[i][j]);
        }
        memset(dp,0,sizeof(dp));
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                dfs(i,j);
            }
        }
        int ans=0;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                ans=max(ans,dp[i][j]);
            }
        }
        printf("%s: ",s);
        printf("%d\n",1+ans);

    }
    return 0;
}
