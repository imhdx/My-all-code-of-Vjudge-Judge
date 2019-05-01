#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > v[1000006];
int sz[1000006];
long long ans=0;
int n,k;
void dfs(int now,int fa)
{
    sz[now]=1;
    for (int i=0;i<v[now].size();i++)
    {
        int u=v[now][i].first;
        if (u==fa) continue;
        dfs(u,now);
        sz[now]+=sz[u];
        ans+=1ll*min(sz[u],k)*v[now][i].second;
    }
}
int main()
{
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        ans=0;
        for (int i=0;i<=n;i++) v[i].clear();
        for (int i=0;i<n-1;i++)
        {
            int x,y,w;scanf("%d%d%d",&x,&y,&w);
            v[x].push_back({y,w});
            v[y].push_back({x,w});
        }
        dfs(1,-1);
        printf("%lld\n",ans);
    }
    return 0;
}//
