//
// Created by mhdx on 2019/5/27.
//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<vector>
#include<algorithm>

using namespace std;
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
const int mod=100000000;
int dp[(1<<12)+2][13];
void dfs(int k)
{
    if (k==0)
    {
        for (int i=0;i<v[0].size();i++)
        {
            dp[v[0][i]][0]=1;
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
                    (dp[v[k][i]][k]+=dp[v[k-1][j]][k-1])%=mod;
            }
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++)
    {
        int s=0;
        for (int j=0;j<m;j++)
        {
            int x;scanf("%d",&x);
            s=s*2+(1-x);
        }
        oo(i,s);

    }
    for (int i=0;i<n;i++) dfs(i);
    long long ans=0;
    for (int i=0;i<v[n-1].size();i++)
    {
        (ans+=dp[v[n-1][i]][n-1])%=mod;
    }
    printf("%lld\n",ans);
    return 0;
}