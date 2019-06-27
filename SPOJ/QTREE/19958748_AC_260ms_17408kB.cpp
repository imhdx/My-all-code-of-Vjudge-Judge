#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
int a[10004];
vector<pair<int,int> > edge[10004];
int son[10004],sz[10004],top[10004],pos[10004],fa[10004],deep[10004];
/*
 * 数据结构部分
 */

struct node
{
    int l,r,mid;
    int ma;
}t[10004<<2];
void pushup(int rt)
{
    t[rt].ma=t[rt<<1].ma;
    if (t[rt].ma<t[rt<<1|1].ma) t[rt].ma=t[rt<<1|1].ma;
}
void build(int l,int r,int rt=1)
{
    t[rt].l=l;
    t[rt].r=r;
    int mid=l+r>>1;
    t[rt].mid=mid;
    t[rt].ma=-1;
    if (l==r) return ;
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
}
int range_ask(int l,int r,int rt=1)
{
    if (l>r) return 0;
    if (l<=t[rt].l&&t[rt].r<=r) return t[rt].ma;
    int ans=0;
    if (l<=t[rt].mid)
    {
        int tmp=range_ask(l,r,rt<<1);
        if (ans<tmp) ans=tmp;
    }
    if (r>t[rt].mid)
    {
        int tmp=range_ask(l,r,rt<<1|1);
        if (ans<tmp) ans=tmp;
    }
    return ans;
}
void dan_change(int p,int val,int rt=1)
{
    if (t[rt].l==t[rt].r){
        t[rt].ma=val;
        return ;
    }
    if (p<=t[rt].mid) dan_change(p,val,rt<<1);
    else dan_change(p,val,rt<<1|1);
    pushup(rt);
}
void dfs1(int x)
{
    sz[x]=1;son[x]=0;
    for (int i=0;i<(int)edge[x].size();i++)
    {
        int y=edge[x][i].first;
        if (y==fa[x]) continue;
        a[y]=edge[x][i].second;
        fa[y]=x;deep[y]=deep[x]+1;
        dfs1(y);
        sz[x]+=sz[y];
        if (sz[y]>=sz[son[x]]) son[x]=y;
    }
}
void dfs2(int x,int now_top)
{
    pos[x]=++cnt;top[x]=now_top;
    if (son[x]) dfs2(son[x],now_top);
    for (int i=0;i<(int)edge[x].size();i++)
    {
        int y=edge[x][i].first;
        if (y!=fa[x]&&y!=son[x]) dfs2(y,y);
    }
}
int query(int x,int y)
{
    int ans=0;
    while (top[x]!=top[y])
    {
        if (deep[top[x]]<deep[top[y]]) swap(x,y);
        int tmp=range_ask(pos[top[x]],pos[x]);
        if (ans<tmp) ans=tmp;
        x=fa[top[x]];
    }
    if (deep[x]<deep[y]) swap(x,y);
    int tmp=range_ask(pos[son[y]],pos[x]);
    if (ans<tmp) ans=tmp;
    return ans;
}
int bian[10004][3];
void rd(int &x)
{
    x=0;
    int f=1;
    char c=getchar();
    while (c<'0'||c>'9')
    {
        if (c=='-') f=-1;
        c=getchar();
    }
    while (c>='0'&&c<='9')
    {
        x=x*10+c-'0';
        c=getchar();
    }
    x*=f;
}
void rdc(char &c)
{
    c=getchar();
    while (c<'A'||c>'Z') c=getchar();
}
signed main()
{
    int T;
    rd(T);
    while (T--)
    {
        cnt=0;
        rd(n);
        build(1,n);
        for (int i=0;i<=n;i++) edge[i].clear();
        for (int i=1;i<n;i++)
        {
            rd(bian[i][0]);
            rd(bian[i][1]);
            rd(bian[i][2]);
            edge[bian[i][0]].push_back(make_pair(bian[i][1],bian[i][2]));
            edge[bian[i][1]].push_back(make_pair(bian[i][0],bian[i][2]));
        }
        dfs1(1);
        dfs2(1,1);
        for (int i=2;i<=n;i++)
        {
            dan_change(pos[i],a[i]);
        }
        char op;
        int x,y,z;
        while (1)
        {
            rdc(op);
            if (op=='D') break;
            else if (op=='Q')
            {
                rd(x);rd(y);
                printf("%d\n",query(x,y));
            }
            else if (op=='C')
            {
                rd(x);rd(y);
                if (deep[bian[x][0]]<deep[bian[x][1]])
                    dan_change(pos[bian[x][1]],y);
                else dan_change(pos[bian[x][0]],y);
            }
        }
    }
    return 0;
}//