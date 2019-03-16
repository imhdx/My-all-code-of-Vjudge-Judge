
#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
int n,m,tot;
int a[25][25];
int dp[25][25][25][25];
int Dp(int i,int j,int k,int l)
{
    if(dp[i][j][k][l]==-1)
    {
        int cnt=0;
        for(int x=i;x<=k;x++)
        {
            for(int y=j;y<=l;y++)
            {
                if(a[x][y]==1)cnt++;
            }
        }
        if(cnt<=1)
        {
            dp[i][j][k][l]=0;
            return dp[i][j][k][l];
        }
        int minn=0x3f3f3f3f;
        for(int tmp=i;tmp<k;tmp++)
        {
            minn=min(minn,Dp(i,j,tmp,l)+Dp(tmp+1,j,k,l)+(l-j+1));
        }
        for(int tmp=j;tmp<l;tmp++)
        {
            minn=min(minn,Dp(i,j,k,tmp)+Dp(i,tmp+1,k,l)+(k-i+1));
        }
        dp[i][j][k][l]=minn;
        return dp[i][j][k][l];
    }
    else return dp[i][j][k][l];
}
int main()
{
    int kase=0;
    while(~scanf("%d%d%d",&n,&m,&tot))
    {
        memset(dp,-1,sizeof(dp));
        memset(a,0,sizeof(a));
        for(int i=0;i<tot;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            a[x][y]=1;
        }
        Dp(1,1,n,m);
        printf("Case %d: ",++kase);
        printf("%d\n",dp[1][1][n][m]);
    }

}