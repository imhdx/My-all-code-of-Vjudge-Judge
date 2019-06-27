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
    int lazy;
    int su;
}t[100005<<2];
void pushup(int rt)
{
    t[rt].su=t[rt<<1].su+t[rt<<1|1].su;
}
void pushdown(int rt)
{
    if (t[rt].lazy==1)
    {
        t[rt<<1].su=(t[rt<<1].r-t[rt<<1].l+1);
        t[rt<<1].lazy=1;
        t[rt<<1|1].su=(t[rt<<1|1].r-t[rt<<1|1].l+1);
        t[rt<<1|1].lazy=1;
    }
    else if (t[rt].lazy==0)
    {
        t[rt<<1].su=0;
        t[rt<<1].lazy=0;
        t[rt<<1|1].su=0;
        t[rt<<1|1].lazy=0;
    }
    t[rt].lazy=2;
}
void build(int l,int r,int rt=1)
{
    t[rt].l=l;
    t[rt].r=r;
    int mid=l+r>>1;
    t[rt].mid=mid;
    t[rt].su=0;
    t[rt].lazy=2;
    if (l==r) return ;
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
    pushup(rt);
}
int range_change(int l,int r,int val,int rt=1)
{
    int ans=0;
    if (l<=t[rt].l&&t[rt].r<=r)
    {
        ans+=abs((t[rt].r-t[rt].l+1)*val-t[rt].su);
        t[rt].su=(t[rt].r-t[rt].l+1)*val;
        t[rt].lazy=val;
        return ans;
    }
    pushdown(rt);
    if (l<=t[rt].mid) ans+=range_change(l,r,val,rt<<1);
    if (r>t[rt].mid) ans+=range_change(l,r,val,rt<<1|1);
    pushup(rt);
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

int update(int x,int y,int val)
{
    int ans=0;
    while (top[x]!=top[y])
    {
        if (deep[top[x]]<deep[top[y]]) swap(x,y);
        ans+=range_change(pos[top[x]],pos[x],val);
        x=fa[top[x]];
    }
    if (deep[x]<deep[y]) swap(x,y);
    ans+=range_change(pos[y],pos[x],val);
    return ans;
}
void rd(int &x) {
    x = 0;
    int f = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    x *= f;
}
int main()
{
    rd(n);
    build(1,n);
    for (int i=2;i<=n;i++)
    {
        int x;rd(x);
        edge[x+1].push_back(i);
        edge[i].push_back(x+1);
    }
    dfs1(1);
    dfs2(1,1);

    int x,y,z;
    char op[10];
    rd(m);
    while (m--)
    {
        scanf("%s",op);
        if (op[0]=='i')
        {
            rd(x);x++;

            //printf("%d %d \n",deep[x]+1,ask_sum(1,x));
            printf("%d\n",update(1,x,1));
            //printf("%d %d \n",deep[x]+1,ask_sum(1,x));
        }
        else if (op[0]=='u')
        {
            rd(x);x++;
            printf("%d\n",range_change(pos[x],pos[x]+sz[x]-1,0));
        }
    }
    return 0;
}
//