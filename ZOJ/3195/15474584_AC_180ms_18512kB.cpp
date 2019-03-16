#include<bits/stdc++.h>
using namespace std;
int pre[50010];
bool vis[50010];
int pos1[210010];
int pos2[210010];
int pos3[210010];
long long int aaa[50010]= {0};
long long int daan[210010]= {0};
vector<pair<int,int> > v[50010];
vector<pair<int,int> > cha[210010];
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
            daan[abs(cha[now][i].second)]=aaa[root];
        }
    }
}
int main()
{
    int t=0;
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        if (t) printf("\n");
        t=1;
        int i,j;
        for (i=0; i<=n; i++)
        {
            vis[i]=0;
            aaa[i]=0;
            v[i].clear();
            pre[i]=i;
        }
        for (i=0; i<n-1; i++)
        {
            int x,y;
            int w;
            scanf("%d%d%d",&x,&y,&w);
            x++;
            y++;
            v[x].push_back({y,w});
            v[y].push_back({x,w});
        }
        int x,y,z;
        int m;
        scanf("%d",&m);
        for (i=0;i<=3*m;i++)
        {
            daan[i]=0;
            cha[i].clear();
        }
        for (i=1; i<=m; i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            x++;
            y++;
            z++;
            pos1[i]=x;
            pos2[i]=y;
            pos3[i]=z;
            cha[x].push_back({y,i});
            cha[y].push_back({x,i});
            cha[x].push_back({z,i+m});
            cha[z].push_back({x,i+m});
            cha[y].push_back({z,i+2*m});
            cha[z].push_back({y,i+2*m});
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
            //cout<<aaa[pos1[i]]<<aaa[pos2[i]]<<aaa[pos3[i]]<<daan[i]<<daan[i+m]<<daan[i+2*m]<<endl;
            printf("%lld\n",aaa[pos1[i]]+aaa[pos2[i]]+aaa[pos3[i]]-daan[i]-daan[i+m]-daan[i+2*m]);
        }
    }
    return 0;
}
