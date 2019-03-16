#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn=100010;
int head[maxn],to[maxn],_next[maxn];
int wei[maxn];///为这条边的权
int cost[maxn];///cost为从根节点到该节点所消耗的权

int d[maxn];///深度
int cnt=0;
int st[maxn<<1][20];///ST表
void ins(int u,int v,int w)
{
    to[++cnt]=v;
    wei[cnt]=w;
    _next[cnt]=head[u];
    head[u]=cnt;
}
int dfsx[maxn<<1];///记录dfs序
int fi[maxn];///记录每个节点在dfs序中第一次出现的位置
int cc;///cc记录dfs序中个数
int n;
void dfs(int x,int fa)
{
    d[x]=d[fa]+1;
    dfsx[++cc]=x;
    for (int i=head[x];i;i=_next[i])
    {
        if (to[i]==fa) continue;
        cost[to[i]]=cost[x]+wei[i];
        dfs(to[i],x);
        dfsx[++cc]=x;
    }
}
int cmp(int a,int b)
{
    if (d[a]<d[b]) return a;
    return b;
}
void init()
{
    for (int i=1;i<=cc;i++)
        st[i][0]=dfsx[i];
    for (int i=1;(1<<i)<=cc;i++)
    {
        for (int j=1;j+(1<<i)-1<=cc;j++)
            st[j][i]=cmp(st[j][i-1],st[j+(1<<(i-1))][i-1]);
    }
}
int ask(int s,int t)///此时为s节点和t号节点
{
    int l=fi[s];
    int r=fi[t];
    if (l>r) swap(l,r);
    int len=(int)(log(r-l+1.0)/log(2.0));
    return cmp(st[l][len],st[r-(1<<len)+1][len]);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        memset(head,0,sizeof(head));
        cc=0;
        cnt=0;
        scanf("%d",&n);
        int m;
        scanf("%d",&m);
        for (int i=0;i<n-1;i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            ins(u,v,w);
            ins(v,u,w);
        }
        dfs(1,0);
        for (int i=1;i<=cc;i++) if (fi[dfsx[i]]==0) fi[dfsx[i]]=i;
        init();
        for (int i=0;i<m;i++)
        {
            int s,t;
            scanf("%d%d",&s,&t);
            int lca=ask(s,t);
            int ans=cost[s]+cost[t]-2*cost[lca];
            printf("%d\n",ans);
        }
    }
    return 0;
}
