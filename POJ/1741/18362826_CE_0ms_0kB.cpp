#include<bits/stdc++.h>
using namespace std;
const int inf=1e9+7;
int n,K,cnt,sum,ans,root;
int head[10004],deep[10004],d[10004],f[10004],son[10004];
bool vis[10004];
struct data
{
    int to,next,w;
}e[20005];
void ins(int u,int v,int w)
{
    e[++cnt].to=v;
    e[cnt].next=head[u];
    head[u]=cnt;
    e[cnt].w=w;
}
void insert(int u,int v,int w)
{
    ins(u,v,w);ins(v,u,w);
}
void getroot(int x,int fa)
{
    son[x]=1;f[x]=0;
    for (int i=head[x];i;i=e[i].next)
    {
        int u=e[i].to;
        if (u==fa||vis[u]) continue;
        getroot(u,x);
        son[x]+=son[u];
        f[x]=max(f[x],son[u]);
    }
    f[x]=max(f[x],sum-son[x]);
    if (f[x]<f[root]) root=x;
}
void getdeep(int x,int fa)
{
    deep[++deep[0]]=d[x];
    for (int i=head[x];i;i=e[i].next)
    {
        int u=e[i].to;
        if (u==fa||vis[u]) continue;
        d[u]=d[x]+e[i].w;
        getdeep(u,x);
    }
}
int cal(int x,int now)
{
    d[x]=now;deep[0]=0;
    getdeep(x,0);
    sort(deep+1,deep+deep[0]+1);
    int t=0,l=1,r=deep[0];
    while (l<r)
    {
        if (deep[l]+deep[r]<=K)
        {
            t+=r-l;
            l++;
        }
        else r--;
    }
    return t;
}
void work(int x)
{
    ans+=cal(x,0);
    vis[x]=1;
    for (int i=head[x];i;i=e[i].next)
    {
        int u=e[i].to;
        if (vis[u]) continue;
        ans-=cal(u,e[i].w);
        sum=son[u];
        root=0;
        getroot(e[i].to,root);
        work(root);
    }
}
int main()
{
    while (scanf("%d%d",&n,&K)!=EOF)
    {
        if (n+K==0) return 0;
        ans=0;root=0;cnt=0;
        memset(vis,0,sizeof(vis));
        memset(head,0,sizeof(head));
        for (int i=1;i<n;i++)
        {
            int u,v,w;scanf("%d%d%d",&u,&v,&w);
            insert(u,v,w);
        }
        sum=n;f[0]=inf;
        getroot(1,0);
        work(root);
        printf("%d\n",ans);
    }

    return 0;
}
