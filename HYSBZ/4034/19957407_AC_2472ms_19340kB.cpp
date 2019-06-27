//
// Created by mhdx on 2019/6/1.
//

#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
int a[300005];
vector<int> edge[300005];
int son[300005],sz[300005],top[300005],pos[300005],fa[300005],deep[300005];
/*
 * 数据结构部分
 */

long long sum1[100005];
long long sum2[100005];
#define ll long long
void add(ll p, ll x) {
    for (int i = p; i < 100005; i += i & -i) sum1[i] += x, sum2[i] += x * p;
}
void range_add(ll l, ll r, ll x) { add(l, x), add(r + 1, -x); }
ll ask(ll p) {
    ll res = 0;
    for (int i = p; i; i -= i & -i) res += (p + 1) * sum1[i] - sum2[i];
    return res;
}
ll range_ask(ll l, ll r) { return ask(r) - ask(l - 1); }
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
ll query(int x,int y)
{
    ll ans=0;
    while (top[x]!=top[y])
    {
        if (deep[top[x]]<deep[top[y]]) swap(x,y);
        ans+=range_ask(pos[top[x]],pos[x]);
        x=fa[top[x]];
    }
    if (deep[x]<deep[y]) swap(x,y);
    ans+=range_ask(pos[y],pos[x]);
    return ans;
}
signed main()
{
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        cnt=0;
        for (int i=0;i<=n;i++) edge[i].clear();
        //memset(son,0,sizeof(son));
        /*
         * 数据结构初始化
         */
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        int x,y,z;
        for (int i=1;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            edge[x].push_back(y);
            edge[y].push_back(x);
        }
        dfs1(1);
        dfs2(1,1);
        for (int i=1;i<=n;i++) range_add(pos[i],pos[i],a[i]);
        int op;
        while (m--)
        {
            scanf("%d",&op);
            if (op==1)
            {
                scanf("%d%d",&x,&y);
                range_add(pos[x],pos[x],y);
            }
            else if (op==2)
            {
                scanf("%d%d",&x,&y);
                range_add(pos[x],pos[x]+sz[x]-1,y);
            }
            else{
                scanf("%d",&x);
                printf("%lld\n",query(1,x));
            }
        }
    }
    return 0;
}