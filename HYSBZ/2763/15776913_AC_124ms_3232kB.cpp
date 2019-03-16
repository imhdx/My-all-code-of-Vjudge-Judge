#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=5e4+5;
inline int read()
{
    int x=0,c=getchar();
    for (;c<'0'||c>'9';c=getchar());
    for (;c>='0'&&c<='9';c=getchar()) x=x*10+c-48;
    return x;
}
struct edge
{
    int v,nxt,w;
}e[M<<1];
int h[N],s,t,n,m,k,cnt,u,v,w;
inline void ins(int u,int v,int w)
{
    e[++cnt]=(edge){v,h[u],w};h[u]=cnt;
    e[++cnt]=(edge){u,h[v],w};h[v]=cnt;
}
struct hn
{
    int u,d,f;
    hn(int u=0,int d=0,int f=0):u(u),d(d),f(f){}
    inline bool operator<(const hn&r)const{return d>r.d;}
};
priority_queue<hn> q;
int d[N][11];bool done[N][11];
int main()
{
    n=read();m=read();k=read();s=read();t=read();
    for (int i=1;i<=m;i++) u=read(),v=read(),w=read(),ins(u,v,w);
    memset(d,127,sizeof(d));d[s][0]=0;q.push(hn(s,0,0));
    while (!q.empty())
    {
        int u=q.top().u;
        int dis=q.top().d;
        int f=q.top().f;
        q.pop();
        if (done[u][f]) continue;
        done[u][f]=1;
        if (u==t)
        {
            printf("%d",dis);
            return 0;
        }
        for (int i=h[u];i;i=e[i].nxt)
        {
            v=e[i].v;
            w=e[i].w;
            if (f<k&&!done[v][f+1]&&d[v][f+1]>dis)
            {
                d[v][f+1]=dis;
                q.push(hn(v,dis,f+1));
            }
            if (!done[v][f]&&d[v][f]>dis+w)
            {
                d[v][f]=dis+w;
                q.push(hn(v,d[v][f],f));
            }
        }
    }
    return 0;
}
