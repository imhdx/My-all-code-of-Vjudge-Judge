#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[50][50];
const int INF=0x3f3f3f3f;
int dp[22][22][22][22];
int dfs(int l1,int r1,int l2,int r2)
{
    int &minn=dp[l1][r1][l2][r2];
    if (minn!=-1) return minn;
    int cnt=0;
    for (int i=l1;i<=l2;i++)
    {
        for (int j=r1;j<=r2;j++)
        {
            if (a[i][j]) cnt++;
        }
    }
    if (cnt<=1) return 0;
    minn=INF;
    for (int i=0;l1+i+1<=l2;i++)
    {
        minn=min(minn,dfs(l1,r1,l1+i,r2)+dfs(l1+i+1,r1,l2,r2)+r2-r1+1);
    }
    for (int i=0;r1+i+1<=r2;i++)
    {
        minn=min(minn,dfs(l1,r1,l2,r1+i)+dfs(l1,r1+i+1,l2,r2)+l2-l1+1);
    }
    return minn;
}
int main()
{
    int t=1;
    int k;
    while (scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
        memset(a,0,sizeof(a));
        for (int i=0;i<k;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            a[x][y]=1;
        }
        memset(dp,-1,sizeof(dp));
        printf("Case %d: ",t++);
        printf("%d\n",dfs(1,1,n,m));
    }
    return 0;
}
