#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int a[N];
int tree[N<<2][23];
int lazy[N<<2];
void updown(int l,int r,int rt)
{
    if (lazy[rt])
    {
        lazy[rt<<1]^=lazy[rt];
        lazy[rt<<1|1]^=lazy[rt];
        for (int i=0;i<22;i++)
        {
            if (lazy[rt]&(1<<i))
            {
                tree[rt<<1][i]=((l+r)/2-l+1)-tree[rt<<1][i];
                tree[rt<<1|1][i]=(r-(l+r)/2)-tree[rt<<1|1][i];
            }
        }
        lazy[rt]=0;
    }
}
void build(int l,int r,int rt)
{
    if (l==r)
    {
        for (int i=0;i<22;i++)
        {
            if (a[l]&(1<<i))
            tree[rt][i]=1;
            //printf("%d %d %d %d\n",l,r,rt,tree[rt][i]);
        }

        return ;
    }
    int mid=l+r>>1;
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
    for (int i=0;i<22;i++)
    {
        tree[rt][i]=tree[rt<<1][i]+tree[rt<<1|1][i];
    }
}
long long ask(int l,int r,int rt,int ll,int rr)
{
    long long int ans=0;
    if (ll<=l&&r<=rr)
    {
        for (int i=0;i<22;i++)
        {
            ans+=(long long)tree[rt][i]*1ll*(1<<i);
        }
        //printf("ans1=%lld\n",ans);
        return ans;
    }
    int mid=l+r>>1;
    updown(l,r,rt);
    if (ll<=mid) ans+=ask(l,mid,rt<<1,ll,rr);
    //printf("ans1=%lld\n",ans);
    if (rr>mid) ans+=ask(mid+1,r,rt<<1|1,ll,rr);
    //printf("ans1=%lld\n",ans);
    return ans;
}
void change(int l,int r,int rt,int ll,int rr,int x)
{
    if (ll<=l&&r<=rr)
    {
        lazy[rt]^=x;

        for (int i=0;i<22;i++)
        {
            if(x&(1<<i))
            {
                tree[rt][i]=(r-l+1)-tree[rt][i];
            }
        }
        return ;
    }
    updown(l,r,rt);
    int mid=l+r>>1;
    if (ll<=mid) change(l,mid,rt<<1,ll,rr,x);
    if (rr>mid) change(mid+1,r,rt<<1|1,ll,rr,x);
    for (int i=0;i<22;i++)
    {
        tree[rt][i]=tree[rt<<1][i]+tree[rt<<1|1][i];
    }
}
int main()
{
    int n,m;
    scanf("%d",&n);
    int i,j;
    for (i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    build(1,n,1);
    scanf("%d",&m);
    for (int i=0;i<m;i++)
    {
        int o,l,r,x;
        scanf("%d%d%d",&o,&l,&r);
        if (o==1)
        {
            printf("%lld\n",ask(1,n,1,l,r));
        }
        else
        {
            scanf("%d",&x);
            change(1,n,1,l,r,x);
        }
    }
    return 0;
}
