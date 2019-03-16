#include<bits/stdc++.h>
using namespace std;
int a[6010];
vector<int> v[6010];
int du[6010];
int dp[6010][2];
void dfs(int fa,int now)
{
    dp[now][0]=0;
    dp[now][1]=a[now];
    int maxx=0;
    int maxx2=0;
    for (int i=0;i<v[now].size();i++)
    {
        int u=v[now][i];
        dfs(now,u);
        dp[now][0]+=max(dp[u][0],dp[u][1]);
        dp[now][1]+=dp[u][0];
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    int l,r;
    while (scanf("%d%d",&l,&r)!=EOF)
    {
        if (l==0&&r==0) break;
        v[r].push_back(l);
        du[l]++;
    }
    int i;
    for (i=1;i<=n;i++)
    {
        if (du[i]==0) break;
    }
    dfs(0,i);
    printf("%d\n",max(dp[i][0],dp[i][1]));

    return 0;
}
