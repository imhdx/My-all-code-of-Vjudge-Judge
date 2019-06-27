//
// Created by mhdx on 2019/6/1.
//


#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
int a[300005];
vector<int> edge[300005];
int sz[300005],top[300005],pos[300005],fa[300005],deep[300005];

struct tree
{
    int l,r,mid;
    int ma;
    int lazy;
}t[100005<<2];

int cmax(int x,int y)
{
	if (x==-1) return y;
	if (y==-1) return x;
	if (x==0) return y;
	if (y==0) return x;
	if (deep[x]<deep[y]) return y;
	return x;
}
void pushup(int rt)
{
    t[rt].ma=cmax(t[rt<<1].ma,t[rt<<1|1].ma);
}
void pushdown(int rt)
{
    if (t[rt].lazy!=-1)
    {
    	
        t[rt<<1].ma=cmax(t[rt<<1].ma,t[rt].lazy);
        t[rt<<1|1].ma=cmax(t[rt<<1|1].ma,t[rt].lazy);
        t[rt<<1].lazy=cmax(t[rt<<1].lazy,t[rt].lazy);
        t[rt<<1|1].lazy=cmax(t[rt<<1|1].lazy,t[rt].lazy);
        t[rt].lazy=-1;
    }
}
void build(int l,int r,int rt=1)
{
    int mid=l+r>>1;
    t[rt].l=l;
    t[rt].r=r;
    t[rt].mid=mid;
    t[rt].lazy=-1;
    if (l==r)
    {
        t[rt].ma=1;
        return ;
    }
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
    pushup(rt);
}
void range_change(int l,int r,int val,int rt=1)
{
    if (l<=t[rt].l&&t[rt].r<=r)
    {
        t[rt].ma=cmax(t[rt].ma,val);
        t[rt].lazy=cmax(t[rt].lazy,val);
        return ;
    }
    pushdown(rt);
    if (l<=t[rt].mid) range_change(l,r,val,rt<<1);
    if (r>t[rt].mid) range_change(l,r,val,rt<<1|1);
    pushup(rt);
}
int dan_ask(int p,int rt=1)
{
    if (t[rt].l==t[rt].r) return t[rt].ma;
    int ans=0;
    pushdown(rt);
    if (p<=t[rt].mid) ans=cmax(ans,dan_ask(p,rt<<1));
    else ans=cmax(ans,dan_ask(p,rt<<1|1));
    return ans;
}
void dfs1(int x)
{
	pos[x]=++cnt;
    sz[x]=1;
    for (int i=0;i<(int)edge[x].size();i++)
    {
        int y=edge[x][i];
        if (y==fa[x]) continue;
        fa[y]=x;deep[y]=deep[x]+1;
        dfs1(y);
        sz[x]+=sz[y];
    }
}
signed main()
{
    scanf("%d%d",&n,&m);
    cnt=0;
    for (int i=0;i<=n;i++) edge[i].clear();
    int x,y,z;
    for (int i=1;i<n;i++)
	{
        scanf("%d%d",&x,&y);
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    dfs1(1);
    build(1,n);
    char op[10];
    while (m--)
    {
        scanf("%s%d",op,&x);
        if (op[0]=='Q') printf("%d\n",dan_ask(pos[x]));
        else range_change(pos[x],pos[x]+sz[x]-1,x);
    }
    return 0;
}//