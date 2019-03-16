#include<bits/stdc++.h>
using namespace std;
const int maxn=1002*1002;
const int maxm=6*1005*1005;
const int INF=0x3f3f3f3f;
int e,head[maxn],cur[maxn],pre[maxn],d[maxn],vd[maxn];
int nexte[maxm],eu[maxm],ev[maxm],c[maxm];
void init(){e=0;memset(head,-1,sizeof(head));}
void addY(int u,int v,int w)
{
    eu[e]=u;ev[e]=v;c[e]=w;nexte[e]=head[u];head[u]=e++;
    eu[e]=v;ev[e]=u;c[e]=0;nexte[e]=head[v];head[v]=e++;
}
void addW(int u,int v,int w)
{
    eu[e]=u;ev[e]=v;c[e]=w;nexte[e]=head[u];head[u]=e++;
    eu[e]=v;ev[e]=u;c[e]=w;nexte[e]=head[v];head[v]=e++;
}
int sap(int s,int t ,int n)
{
    int i,u;
    memset(d,0,sizeof(d));
    memset(vd,0,sizeof(vd));
    vd[0]=n;
    cur[u=s]=head[s];
    pre[s]=-1;
    int temp,ans=0;
    while(d[s]<n)
    {
        if(u==t)
        {
            for(temp=INF,i=pre[u];~i;i=pre[eu[i]])
             temp=min(temp,c[i]);
            for(i=pre[u];~i;i=pre[eu[i]])
            {
                 c[i]-=temp;c[i^1]+=temp;
            }
            ans+=temp; u=s;
        }
        for(i=cur[u];~i;i=nexte[i])
        {
            if(c[i]>0&&d[u]==d[ev[i]]+1)
            {
                cur[u]=i;
                pre[u=ev[i]]=i;
                break;
            }
        }
        if(i==-1)
        {
            cur[u]=head[u];
            if(--vd[d[u]]==0) break;
            vd[++d[u]]++;
            if(u!=s) u=eu[pre[u]];
        }
    }
    return ans;
}
int main()
{
    init();
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++){
        for (int j=1;j<m;j++){
            int w;scanf("%d",&w);
            addW((i-1)*m+j,(i-1)*m+j+1,w);
        }
    }
    for (int i=1;i<n;i++){
        for (int j=1;j<=m;j++){
            int w;scanf("%d",&w);
            addW((i-1)*m+j,i*m+j,w);
        }
    }
    for (int i=1;i<n;i++){
        for (int j=1;j<m;j++){
            int w;scanf("%d",&w);
            addW((i-1)*m+j,i*m+j+1,w);
        }
    }
    printf("%d\n",sap(1,n*m,n*m+1));
    return 0;
}
