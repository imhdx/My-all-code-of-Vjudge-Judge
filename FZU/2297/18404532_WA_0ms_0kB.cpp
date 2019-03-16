#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;
const int maxn=1e5+7;
struct ac
{
    int l,r,mid;
    long long val;
}t[maxn<<2];
long long mod;
void pushup(int rt)
{
    t[rt].val=t[rt<<1].val*t[rt<<1|1].val%mod;
}
void build(int l,int r,int rt=1)
{
    int mid=l+r>>1;
    t[rt].l=l;
    t[rt].r=r;
    t[rt].mid=mid;
    t[rt].val=1;
    if (l==r)
        return ;
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
}
void change(int x,long long val,int rt=1)
{
    if (t[rt].l==t[rt].r)
    {
        t[rt].val=val;
        return ;
    }
    if (x<=t[rt].mid)
        change(x,val,rt<<1);
    else
        change(x,val,rt<<1|1);
    pushup(rt);
}
int main()
{
    int T;scanf("%d",&T);
    while (T--)
    {
        int q;
        scanf("%d%lld",&q,&mod);
        build(1,q);
        for (int i=1;i<=q;i++)
        {
            char op[10];
            long long int x;
            scanf("%s%lld",op,&x);
            if (op[0]=='M')
            {
                change(i,x);
                //t[1].val%=mod;
                printf("%lld\n",t[1].val);
            }
            else
            {
                change(x,1);
                //t[1].val%=mod;
                printf("%lld\n",t[1].val);
            }
        }
    }
    return 0;
}
