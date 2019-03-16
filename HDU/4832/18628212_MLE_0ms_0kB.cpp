#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<map>
using namespace std;
map<int,map<int,map<int,int>>> dp;
int tx[]={0,0,1,-1,0,0,2,-2};
int ty[]={1,-1,0,0,2,-2,0,0};
int nn,mm;
const int mod=9999991;
int f(int n,int m,int k)
{
    if (k==0) return 1;
    if (dp[n][m][k]!=0) return dp[n][m][k];
    int &ans=dp[n][m][k];
    ans=0;
    for (int i=0;i<8;i++)
    {
        int xx=n+tx[i];
        int yy=m+ty[i];
        if (xx<1||xx>nn||yy<1||yy>mm) continue;
        ans+=f(xx,yy,k-1);
        if (ans>=mod) ans-=mod;
    }
    return ans;
}
int main()
{
    int tt=1;
    int T;scanf("%d",&T);
    while (T--){
        dp.clear();
        scanf("%d%d",&nn,&mm);
        int k;scanf("%d",&k);
        int x,y;scanf("%d%d",&x,&y);
        printf("Case #%d:\n",tt++);
        printf("%d\n",f(x,y,k));
    }
    return 0;
}
