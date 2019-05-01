#include<bits/stdc++.h>
using namespace std;
int n;
const int maxn=50004;
struct ac
{
    int l,r,mid;
    int ma,mi;
}t[maxn<<2];
int a[maxn];
const int inf=1e9+7;
void pushup(int rt)
{
    t[rt].mi=min(t[rt<<1].mi,t[rt<<1|1].mi);
    t[rt].ma=max(t[rt<<1].ma,t[rt<<1|1].ma);
}
void build(int l,int r,int rt=1)
{
    int mid=l+r>>1;
    t[rt].l=l;
    t[rt].r=r;
    t[rt].mid=mid;
    if (l==r)
    {
        t[rt].ma=a[l];
        t[rt].mi=a[l];
        return ;
    }
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
    pushup(rt);
}
int maxx,minn;
void ask(int l,int r,int rt=1)
{
    if (l<=t[rt].l&&t[rt].r<=r)
    {
        maxx=max(maxx,t[rt].ma);
        minn=min(minn,t[rt].mi);
        return ;
    }
    if (l<=t[rt].mid) ask(l,r,rt<<1);
    if (r>t[rt].mid) ask(l,r,rt<<1|1);
}
int main()
{
    int q;
    scanf("%d%d",&n,&q);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    build(1,n);
    while (q--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        maxx=-inf;
        minn=inf;
        ask(l,r);
        printf("%d\n",maxx-minn);
    }
    return 0;
}
