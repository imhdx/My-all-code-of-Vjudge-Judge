#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,root=1;
int a[300005];
vector<int> edge[300005];
int son[300005],sz[300005],top[300005],pos[300005],fa[300005],deep[300005];
/*
 * 数据结构部分
 */
struct tree
{
    int l,r,mid;
    int ma,su;
}t[100005<<2];
void pushup(int rt)
{
    t[rt].ma=max(t[rt<<1].ma,t[rt<<1|1].ma);
    t[rt].su=t[rt<<1].su+t[rt<<1|1].su;
}
void build(int l,int r,int rt=1)
{
    t[rt].l=l;
    t[rt].r=r;
    int mid=l+r>>1;
    t[rt].mid=mid;
    if (l==r) return ;
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
}
void add(int x,int val,int rt=1)
{
    if (t[rt].l==t[rt].r)
    {
        t[rt].ma=val;
        t[rt].su=val;
        return ;
    }
    if (x<=t[rt].mid) add(x,val,rt<<1);
    else add(x,val,rt<<1|1);
    pushup(rt);
}
long long range_max(int l,int r,int rt=1)
{
    if (l<=t[rt].l&&t[rt].r<=r) return t[rt].ma;
    long long ans=-1e9;
    if (l<=t[rt].mid) ans=max(ans,range_max(l,r,rt<<1));
    if (r>t[rt].mid) ans=max(ans,range_max(l,r,rt<<1|1));
    return ans;
}
long long range_sum(int l,int r,int rt=1)
{
    if (l<=t[rt].l&&t[rt].r<=r) return t[rt].su;
    long long ans=0;
    if (l<=t[rt].mid) ans+=range_sum(l,r,rt<<1);
    if (r>t[rt].mid) ans+=range_sum(l,r,rt<<1|1);
    return ans;
}
void dfs1(int x)
{
    sz[x]=1;son[x]=0;
    for (int i=0;i<(int)edge[x].size();i++)
    {
        int y=edge[x][i];
        if (y==fa[x]) continue;
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
        int y=edge[x][i];
        if (y!=fa[x]&&y!=son[x]) dfs2(y,y);
    }
}

long long ask_sum(int x,int y)
{
    long long ans=0;
    while (top[x]!=top[y])
    {
        if (deep[top[x]]<deep[top[y]]) swap(x,y);
        ans+=range_sum(pos[top[x]],pos[x]);
        x=fa[top[x]];
    }
    if (deep[x]<deep[y]) swap(x,y);
    ans+=range_sum(pos[y],pos[x]);
    return ans;
}

long long ask_max(int x,int y)
{
    long long ans=-1e9;
    while (top[x]!=top[y])
    {
        if (deep[top[x]]<deep[top[y]]) swap(x,y);
        ans=max(ans,range_max(pos[top[x]],pos[x]));
        x=fa[top[x]];
    }
    if (deep[x]<deep[y]) swap(x,y);
    ans=max(ans,range_max(pos[y],pos[x]));
    return ans;
}
signed main()
{
    scanf("%d",&n);
    build(1,n);
    for (int i=1;i<=n-1;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        edge[y].push_back(x);
        edge[x].push_back(y);
    }
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    dfs1(1);
    dfs2(1,1);
    for (int i=1;i<=n;i++) add(pos[i],a[i]);
    int x,y,z;
    char op[10];
    scanf("%d",&m);
    while (m--)
    {
        scanf("%s",op);
        if (op[3]=='X')
        {
            scanf("%d%d",&x,&y);
            printf("%lld\n",ask_max(x,y));
        }
        else if (op[3]=='M')
        {
            scanf("%d%d",&x,&y);
            printf("%lld\n",ask_sum(x,y));
        }
        else if (op[3]=='N')
        {
            scanf("%d%d",&x,&y);
            add(pos[x],y);
        }
    }
    return 0;
}