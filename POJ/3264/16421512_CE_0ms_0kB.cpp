#include<bits/stdc++.h>
#define lson rt<<1
#define rson rt<<1|1
using namespace std;
const int INF=1e9+7;
const int MAXN=50005;
int ans1,ans2;
int a[MAXN];
struct node
{
    int l,r,mid;
    int ma,mi;
}t[MAXN<<2];
void pushup(int rt)
{
    t[rt].mi=min(t[lson].mi,t[rson].mi);
    t[rt].ma=max(t[lson].ma,t[rson].ma);
}
void build(int l,int r,int rt)
{
    int mid=l+r>>1;
    t[rt].l=l;t[rt].r=r;t[rt].mid=mid;
    if (l==r)
    {
        t[rt].ma=t[rt].mi=a[l];
        return ;
    }
    build(l,mid,lson);
    build(mid+1,r,rson);
    pushup(rt);
}
void query(int l,int r,int rt)
{
    if (l<=t[rt].l&&t[rt].r<=r)
    {
        ans1=max(ans1,t[rt].ma);
        ans2=min(ans2,t[rt].mi);
        return ;
    }
    if (l<=t[rt].mid) query(l,r,lson);
    if (r>t[rt].mid) query(l,r,rson);
}

int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        build(1,n,1);
        for (int i=0;i<m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            ans1=-INF;
            ans2=INF;
            query(x,y,1);
            printf("%d\n",ans1-ans2);
        }
    }

    return 0;
}
