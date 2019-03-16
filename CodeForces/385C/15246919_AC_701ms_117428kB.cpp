#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e7+7;
int prim[MAXN];
int vis[MAXN];
int dp[MAXN];
void init()
{
    int i;
    long long int j;
    for (i=2;i<MAXN;i++)
    {
        if (prim[i]==0)
        {
            if (vis[i]) dp[i]+=vis[i];
            for (j=2;i*j<MAXN;j++)
            {
                prim[i*j]=1;
                dp[i]+=vis[i*j];
            }
        }
    }
    for (i=1;i<MAXN;i++)
        dp[i]+=dp[i-1];
}
int main()
{
    int n;
    scanf("%d",&n);
    int i;
    int x;
    for (i=0;i<n;i++)
        scanf("%d",&x),vis[x]++;
    init();
    int m;
    scanf("%d",&m);
    for (i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",dp[min(MAXN-1,y)]-dp[min(MAXN-1,x-1)]);
    }
    return 0;
}
