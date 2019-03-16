#include<bits/stdc++.h>
using namespace std;
int n,k;
const int MAX=50004;
vector<int> v[MAX];
int dp[MAX][502];
long long ans=0;
void dfs(int fa,int now)
{
    for (int i=0;i<=k;i++) dp[now][k]=0;
    dp[now][0]=1;
    for (int i=0;i<v[now].size();i++)
    {
        int son=v[now][i];
        if (son==fa) continue;
        dfs(now,son);
        for (int j=0;j<k;j++)
            ans+=1ll*dp[now][j]*dp[son][k-j-1];///这个先后顺序不能颠倒  这个顺序保证了最短距离的两个点来自两个不同的子树
        for (int j=0;j<=k;j++)             ///或一个来自子树 一个来自本节点
            dp[now][j]+=dp[son][j-1];
    }
}
int main()
{
    scanf("%d%d",&n,&k);
    int i,j;
    for (i=0;i<n-1;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    ans=0;
    dfs(0,1);
    printf("%lld\n",ans);
    return 0;
}
