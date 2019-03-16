#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=440;
const int maxm=50005;
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
int st[20010];
int la[20010];
int len[20010];
int chu[220];
int shi[220];
int n,m;
int get(int mid)
{
    init();
    for (int i=1;i<=n;i++){
        addY(0,i,chu[i]);
        addY(i,n+1,shi[i]);
    }
    for (int i=0;i<m;i++){
        if (len[i]<=mid) addW(st[i],la[i],INF);
    }
    return sap(0,n+1,n+2);
}
int main()
{
    while (scanf("%d",&n)!=EOF&&n)
    {
        int s=0,t=n+1;
        int tot=0;
        for (int i=1;i<=n;i++){
            scanf("%d",&chu[i]);
            tot+=chu[i];
        }
        for (int i=1;i<=n;i++){
            scanf("%d",&shi[i]);
        }
        scanf("%d",&m);
        for (int i=0;i<m;i++){
            scanf("%d%d%d",&st[i],&la[i],&len[i]);
        }
        int l=0;
        int r=INF;
        int ans=-1;
        while (l<=r){
            int mid=l+r>>1;
            if (get(mid)==tot){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
