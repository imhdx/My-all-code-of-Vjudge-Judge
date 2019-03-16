#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
using namespace std;
const int MAXN=13;
int a[MAXN];
long long ans=0;
const int mod=1e8;
long long dp[(1<<13)][13]; ///dp[i][j] 第j行状态为i的个数
int n,m;
vector<int> v[13];
void oo(int k,int temp)
{
    for (int i=0;i<(1<<m);i++)
    {
        if (i<<1&i||i>>1&i) continue;
        if (i&temp) continue;
        v[k].push_back(i);
    }
}
void dfs(int k)
{
    if (k==0)
    {
        for (int i=0;i<v[k].size();i++)
        {
            dp[v[k][i]][k]=1;
        }
        return ;
    }
    for (int i=0;i<v[k].size();i++)
    {
        for (int j=0;j<v[k-1].size();j++)
        {
            if (dp[v[k-1][j]][k-1])
            {
                if (!(v[k-1][j]&v[k][i]))
                {
                    //printf("hi\n");
                    dp[v[k][i]][k]=(dp[v[k][i]][k]+dp[v[k-1][j]][k-1])%mod;
                }
            }
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    int i,j;
    for (i=0;i<n;i++)
    {
        int s=0;
        for (j=0;j<m;j++)
        {
            int x;
            scanf("%d",&x);
            x=1-x;
            s=s*2+x;
            a[i]=s;
        }
        oo(i,a[i]);
    }
    for (int i=0;i<n;i++) dfs(i);
    ans=0;
    for (i=0;i<v[n-1].size();i++)
    {
        ans=(ans+dp[v[n-1][i]][n-1])%mod;
    }
    printf("%lld\n",ans);
    return 0;

}
