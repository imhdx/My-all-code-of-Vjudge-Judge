#include<bits/stdc++.h>
using namespace std;
const int maxn=1000006;
int pre[maxn],a[maxn],ran[maxn];
vector<int> v[maxn];
int getx(int x)
{
    if (pre[x]==x) return x;
    return pre[x]=getx(pre[x]);
}
bool merge(int x,int y)
{
    x=getx(x);
    y=getx(y);
    if (x==y) return 0;
    if (ran[x] <= ran[x])
    {
        pre[x]=y;
        ran[y]=max(ran[x]+1,ran[y]);
    }
    else
    {
        pre[y]=x;
        ran[x]=max(ran[x],ran[y]+1);
    }
    return 1;
}
pair<int,int> huan[maxn];
int root1=-1,root2=-1;
long long dp[maxn][2];
void dfs(int now,int fa)
{
    dp[now][0]=0;
    dp[now][1]=a[now];
    for (int i=0;i<v[now].size();i++)
    {
        int u=v[now][i];
        if (u==fa) continue;
        dfs(u,now);
        dp[now][1]+=dp[u][0];
        dp[now][0]+=max(dp[u][1],dp[u][0]);
    }
}
int main()
{
    int cnt=0;
    int n;
    scanf("%d",&n);for (int i=0;i<=n;i++) pre[i]=i;
    for (int i=1;i<=n;i++)
    {
        int x;
        scanf("%d%d",&a[i],&x);
        if (merge(i,x))
        {
            v[i].push_back(x);
            v[x].push_back(i);
        }
        else{
            huan[cnt++]={i,x};
        }
    }
    long long ans=0;
    for (int i=0;i<cnt;i++)
    {
        root1=huan[i].first;
        root2=huan[i].second;
        //printf("root=%d %d\n",root1,root2);
        dfs(root1,-1);
        long long tmp=dp[root1][0];
        dfs(root2,-1);
        ans+=max(tmp,dp[root2][0]);
    }
    printf("%lld\n",ans);
    return 0;
}