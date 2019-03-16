#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[150][150];
int dp[150][150];
int n,k;
int dfs(int x,int y)
{
    int i,j;
    int dx,dy;
    int ans;
    int maxx=0;
    if (dp[x][y]==0)
    {
        for (i=max(0,x-k);i<=min(n-1,x+k);i++)
        {
            dx=i;
            dy=y;
            if (dx==x&&dy==y) continue;
            if (a[dx][dy]>a[x][y])
            {
                ans=dfs(dx,dy);
                if (ans>maxx) maxx=ans;
            }
        }
        for (i=max(0,y-k);i<=min(n-1,y+k);i++)
        {
            dx=x;
            dy=i;
            if (dx==x&&dy==y) continue;
            if (a[dx][dy]>a[x][y])
            {
                ans=dfs(dx,dy);
                if (ans>maxx) maxx=ans;
            }
        }
        dp[x][y]=maxx+a[x][y];
    }
    return dp[x][y];
}
int main()
{
    int i,j;
    while (scanf("%d%d",&n,&k)!=EOF)
    {
        if (n==-1&&k==-1) break;
        memset(dp,0,sizeof(dp));
        for (i=0;i<n;i++)
        {
            for (j=0;j<n;j++)
                scanf("%d",&a[i][j]);
        }
        printf("%d\n",dfs(0,0));
    }
    return 0;
}

