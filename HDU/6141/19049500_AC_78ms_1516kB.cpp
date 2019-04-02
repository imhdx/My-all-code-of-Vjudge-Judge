#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=1010;
const int maxm=10010;
struct edge
{
    int u,v,w;
}edge[maxm];
int pre[maxn],id[maxn],vis[maxn],in[maxn];
int zhuliu(int root,int n,int m)
{
    int res=0,u,v;
    for (;;)
    {
        for (int i=0;i<n;i++) in[i]=inf;
        for (int i=0;i<m;i++)
        {
            if (edge[i].u!=edge[i].v&&edge[i].w<in[edge[i].v])
            {
                pre[edge[i].v]=edge[i].u;
                in[edge[i].v]=edge[i].w;
            }
        }
        for (int i=0;i<n;i++) if (i!=root&&in[i]==inf) return -1;
        int tn=0;
        memset(id,-1,sizeof(id));
        memset(vis,-1,sizeof(vis));
        in[root]=0;
        for (int i=0;i<n;i++)
        {
            res+=in[i];
            v=i;
            while (vis[v]!=i&&id[v]==-1&&v!=root) vis[v]=i,v=pre[v];
            if (v!=root&&id[v]==-1)
            {
                for (int u=pre[v];u!=v;u=pre[u]) id[u]=tn;
                id[v]=tn++;
            }
        }
        if (tn==0) break;
        for (int i=0;i<n;i++) if (id[i]==-1) id[i]=tn++;
        for (int i=0;i<m;)
        {
            v=edge[i].v;
            edge[i].u=id[edge[i].u];
            edge[i].v=id[edge[i].v];
            if (edge[i].u!=edge[i].v) edge[i++].w-=in[v];
            else swap(edge[i],edge[--m]);
        }
        n=tn;
        root=id[root];
    }
    return res;
}
int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
       int n,m,u,v,w;
       scanf("%d%d",&n,&m);
       for (int i=0;i<m;i++)
       {
           scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
           edge[i].u--;
           edge[i].v--;
           edge[i].w=-edge[i].w*1000;
           if (edge[i].v==n-1) edge[i].w+=edge[i].u;
       }
       int res=-zhuliu(0,n,m);
       int ans=(res+999)/1000,pos=(res+999)/1000*1000-res;
       printf("%d %d\n",ans,pos+1);
   }
   return 0;
}
