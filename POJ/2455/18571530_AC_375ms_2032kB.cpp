#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=505;
const int maxm=80020;
const int INF=0x3f3f3f3f;
int e,head[maxn],cur[maxn],pre[maxn],d[maxn],vd[maxn];
int nexte[maxm],eu[maxm],ev[maxm],c[maxm];
void init(){e=0;memset(head,-1,sizeof(head));}
void addW(int u,int v,int w)
{
    eu[e]=u;ev[e]=v;c[e]=w;nexte[e]=head[u];head[u]=e++;
    eu[e]=v;ev[e]=u;c[e]=w;nexte[e]=head[v];head[v]=e++;
}
void addY(int u,int v,int w)
{
    eu[e]=u;ev[e]=v;c[e]=w;nexte[e]=head[u];head[u]=e++;
    eu[e]=v;ev[e]=u;c[e]=0;nexte[e]=head[v];head[v]=e++;
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
int st[40010];
int la[40010];
int len[40010];
int main()
{
    int n,p,t;
    scanf("%d%d%d",&n,&p,&t);
    for (int i=0;i<p;i++) scanf("%d%d%d",&st[i],&la[i],&len[i]);
    int l=0;
    int r=1000000;
    int ans=-1;
    while (l<=r){
        int mid=l+r>>1;
        init();
        for (int i=0;i<p;i++)
        {
            if (len[i]<=mid)///最小化（t条不相交的最短路中最长的那段路）
                            ///二分使得我们要找的那条路不加到图中，这样就无法找到那t条路
                addW(st[i],la[i],1);
        }
        if (sap(1,n,n+1)>=t)///最大流保证t条路不相交，因为每条路经只有流量1，只能走一次
        {
            ans=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    printf("%d\n",ans);
    return 0;
}
