#include<bits/stdc++.h>
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
inline int read()
{
    int ans(0);char w=getchar();
    while (w<'0'||'9'<w) w=getchar();
    while (w>='0'&&w<='9'){ans=ans*10+w-'0';w=getchar();}
    return ans;
}
int main()
{
    int T;T=read();
    while (T--){
        init();
        int n;n=read();
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                int x;x=read();
                if (x) addY(i,n+j,1);
            }
        }
        for (int i=1;i<=n;i++){
            addY(0,i,1);
            addY(i+n,n+n+1,1);
        }
        int ans=sap(0,n+n+1,n+n+2);
        if (ans>=n) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
