#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;
long long w[100011];
long long dfn[100010];
int in[100010];
int out[100010];
int time;
int n,m;
vector<int> son[100010];
long long tree[400040];
long long lazy[400040];
void dfs(int pre,int now)
{
    in[now]=++time;
    dfn[in[now]]=dfn[in[pre]]+w[now];
    for (int i=0;i<son[now].size();i++)
        if (son[now][i]!=pre)
            dfs(now,son[now][i]);
    out[now]=time;
}
void build(int l,int r,int rt)
{
    lazy[rt]=0;
    if (l==r)
    {
        tree[rt]=dfn[l];
        return ;
    }
    int mid=(l+r)>>1;
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
    tree[rt]=max(tree[rt<<1],tree[rt<<1|1]);
}
void pushdown(int rt)
{
    if (lazy[rt]==0) return ;
    tree[rt<<1]+=lazy[rt];
    tree[rt<<1|1]+=lazy[rt];
    lazy[rt<<1]+=lazy[rt];
    lazy[rt<<1|1]+=lazy[rt];
    lazy[rt]=0;
}
void updata(int l,int r,int rt,int ll,int rr,int x)
{
    if (l>rr||r<ll) return ;
    if (ll<=l&&r<=rr)
    {
        tree[rt]+=x;
        lazy[rt]+=x;
        return ;
    }
    pushdown(rt);
    int mid=(l+r)>>1;
    updata(l,mid,rt<<1,ll,rr,x);
    updata(mid+1,r,rt<<1|1,ll,rr,x);
    tree[rt]=max(tree[rt<<1],tree[rt<<1|1]);
}
long long query(int l,int r,int rt,int ll,int rr)
{
    if (l>rr||r<ll) return -1ll*1e18;
    if (ll<=l&&r<=rr) return tree[rt];
    pushdown(rt);
    int mid=(l+r)>>1;
    long long maxx=max(query(l,mid,rt<<1,ll,rr),query(mid+1,r,rt<<1|1,ll,rr));
    return maxx;
}
int main()
{
    int t=1;
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&n,&m);
        int i,j;
        for (i=0;i<=n+1;i++)
        {
            son[i].clear();
        }
        for (i=0;i<n-1;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            x++;y++;
            son[x].push_back(y);
            son[y].push_back(x);
        }
        for (i=1;i<=n;i++)
            scanf("%lld",&w[i]);
        time=in[0]=out[0]=0;
        dfs(0,1);
        build(1,n,1);
        printf("Case #%d:\n",t++);
        while (m--)
        {
            int type;
            int x;
            int y;
            scanf("%d",&type);
            if (type==0)
            {
                scanf("%d%d",&x,&y);
                x++;
                updata(1,n,1,in[x],out[x],y-w[x]);
                w[x]=y;
            }
            else if (type==1)
            {
                scanf("%d",&x);
                x++;
                printf("%lld\n",query(1,n,1,in[x],out[x]));
            }
        }
    }
    return 0;
}
