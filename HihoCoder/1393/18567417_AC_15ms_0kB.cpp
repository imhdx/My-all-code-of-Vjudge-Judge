#include<bits/stdc++.h>
using namespace std;
const int maxn=505;
const int maxm=100005;
const int INF=0x3f3f3f3f;
int e,head[maxn],cur[maxn],pre[maxn],d[maxn],vd[maxn];
int nexte[maxm],eu[maxm],ev[maxm],c[maxm];
void init(){e=0;memset(head,-1,sizeof(head));}
void add(int u,int v,int w)
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
int main()
{
    int T,k,n,m,mn,a,b;
    scanf("%d",&T);
    while (T--){
        init();///链式前向星的初始化
        scanf("%d%d",&n,&m);
        int s=0,t=n+m+1;///源点，汇点
        int total=0;
        for (int i=1;i<=m;i++)
        {
            scanf("%d",&mn);
            total+=mn;
            add(n+i,t,mn);
        }
        for (int i=1;i<=n;i++)
        {
            scanf("%d%d",&a,&b);
            add(s,i,a);
            for (int j=0;j<b;j++)
            {
                scanf("%d",&k);
                add(i,n+k,1);
            }
        }
        if (total==sap(s,t,t+1)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
