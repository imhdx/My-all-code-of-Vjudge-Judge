#include<bits/stdc++.h>
using namespace std;
const int MAXN=(1<<17)+6;
const int INF=1e9+7;
struct node
{
    int mid,l,r,mi,ma;
}que[MAXN<<2];
int a[MAXN];
int maxx;
int minn;
void build(int l,int r,int rt)
{
    int mid=l+r>>1;
    que[rt].mid=mid;
    que[rt].l=l;
    que[rt].r=r;
    if (l==r)
    {
        que[rt].mi=que[rt].ma=a[l];
        return ;
    }
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
    que[rt].mi=min(que[rt<<1].mi,que[rt<<1|1].mi);
    que[rt].ma=max(que[rt<<1].ma,que[rt<<1|1].ma);
}
void gai(int rt,int pos,int x)
{
    if (que[rt].l==que[rt].r)
    {
        que[rt].mi=que[rt].ma=x;
        return ;
    }
    if (pos<=que[rt].mid) gai(rt<<1,pos,x);
    else gai(rt<<1|1,pos,x);

}
void query(int rt,int l,int r)
{
    if (l<=que[rt].l&&que[rt].r<=r)
    {
        maxx=max(maxx,que[rt].ma);
        minn=min(minn,que[rt].mi);
        return ;
    }
    if (l<=que[rt].mid) query(rt<<1,l,r);
    if (r>que[rt].mid) query(rt<<1|1,l,r);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        n=(1<<n);
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        build(1,n,1);
        int m;
        scanf("%d",&m);
        for (int i=0;i<m;i++)
        {
            int op,l,r;
            scanf("%d%d%d",&op,&l,&r);
            if (op==1)
            {
                maxx=-INF;
                minn=INF;
                query(1,l+1,r+1);
                long long ans=min(1ll*maxx*minn,min(1ll*minn*minn,1ll*maxx*maxx));
                printf("%lld\n",ans);
            }
            else
                gai(1,l+1,r);
        }
    }
    return 0;
}
