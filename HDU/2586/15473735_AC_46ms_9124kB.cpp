#include<bits/stdc++.h>
using namespace std;
int pre[40010];
bool vis[40010];
long long int aaa[40010]= {0};
long long int daan[210]= {0};
vector<pair<int,int> > v[40010];
vector<pair<int,int> > cha[210];
int getx(int x)
{
    if(pre[x]==x)
        return x;
    return pre[x]=getx(pre[x]);
}
void nian(int x,int y)
{
    x=getx(x);
    y=getx(y);
    if(x!=y)
        pre[x]=y;
}
void dfs(int fa,int now)
{
    for (int i=0; i<v[now].size(); i++)
    {
        int u=v[now][i].first;
        if (u==fa)
            continue;
        aaa[u]=aaa[now]+v[now][i].second;
        dfs(now,u);
    }
}
void Tar(int fa,int now)
{
    for (int i=0; i<v[now].size(); i++)
    {
        int u=v[now][i].first;
        if (u==fa)
            continue;
        Tar(now,u);
        nian(u,now);
        vis[u]=1;
    }
    for (int i=0; i<cha[now].size(); i++)
    {
        int u=cha[now][i].first;
        if (vis[u])
        {
            int root=getx(u);
            //printf("%d %d %d\n",now,u,root);
            if (root==u||root==now)
            {
                daan[abs(cha[now][i].second)]=abs(aaa[u]-aaa[now]);
            }
            else
                daan[abs(cha[now][i].second)]=aaa[u]-aaa[root]+aaa[now]-aaa[root];
        }
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        int m;
        scanf("%d",&m);
        int i,j;
        for (i=0; i<=n; i++)
        {
            vis[i]=0;
            aaa[i]=0;
            v[i].clear();
            pre[i]=i;
        }
        for (i=0;i<=m;i++)
        {
            daan[i]=0;
            cha[i].clear();
        }
        for (i=0; i<n-1; i++)
        {
            int x,y;
            int w;
            scanf("%d%d%d",&x,&y,&w);
            v[x].push_back({y,w});
            v[y].push_back({x,w});
        }
        int x,y;
        for (i=1; i<=m; i++)
        {
            scanf("%d%d",&x,&y);
            cha[x].push_back({y,i});
            cha[y].push_back({x,i});
        }
        dfs(0,1);
        //for (i=1;i<=n;i++)
        //    printf("%d ",aaa[i]);
        //printf("\n");
        Tar(0,1);
        long long summ=0;
        int cnt=0;
        for (i=1; i<=m; i++)
        {
            printf("%lld\n",daan[i]);
        }
    }
    return 0;
}
