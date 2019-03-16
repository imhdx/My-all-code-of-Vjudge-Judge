#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn=1e6+7;
int head[maxn],to[maxn],_next[maxn];
int d[maxn];///深度
int cnt=0;
int st[maxn<<1][26];///ST表
void ins(int u,int v)
{
    to[++cnt]=v;
    _next[cnt]=head[u];
    head[u]=cnt;
}
int dfsx[maxn<<1];///记录dfs序
int fi[maxn];///记录每个节点在dfs序中第一次出现的位置
int cc;///cc记录dfs序中个数
int n,m;
void dfs(int x,int fa,int dep)
{
    d[x]=dep;
    dfsx[++cc]=x;
    for (int i=head[x];i;i=_next[i])
    {
        if (to[i]==fa) continue;
        printf("dfs %d\n",x);
        dfs(to[i],x,dep+1);
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
    int len=(int)log2(r-l+1);
    return cmp(st[l][len],st[r-(1<<len)+1][len]);
}
int du[maxn];
int main()
{
    int T;scanf("%d",&T);
    while (T--)
    {
        memset(head,0,sizeof(head));
        memset(to,0,sizeof(to));
        memset(_next,0,sizeof(_next));
        memset(fi,0,sizeof(fi));
        cc=0;
        cnt=0;
        scanf("%d",&n);
        m=1;
        memset(du,0,sizeof(du));
        for (int i=0;i<n-1;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            du[v]++;
            ins(u,v);
        }
        int sss;
        for (int i=1;i<=n;i++) if (du[i]==0)  sss=i;
        dfs(sss,0,0);
        for (int i=1;i<=cc;i++) if (fi[dfsx[i]]==0) fi[dfsx[i]]=i;
        init();
        for (int i=0;i<m;i++)
        {
            int s,t;
            scanf("%d%d",&s,&t);
            printf("%d\n",ask(s,t));
        }
    }
    return 0;
}
