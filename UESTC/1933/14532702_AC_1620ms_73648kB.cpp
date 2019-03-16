#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=1000010;
long long int tree[N<<2];
long long int lazy[N<<2];

void down(int l,int r,int rt)
{
    if (lazy[rt])
    {
        lazy[rt*2]+=lazy[rt];
        lazy[rt*2+1]+=lazy[rt];
        int mid =(l+r)>>1;
        tree[rt*2]+=lazy[rt]*(mid-l+1);
        tree[rt*2+1]+=lazy[rt]*(r-mid);
        lazy[rt]=0;
    }
}

void change(int l,int r,int rt,int ll,int rr,int x)
{
    if(ll<=l&&r<=rr)///到达最区间内的最上层节点
    {
        tree[rt]+=x*(r-l+1);
        lazy[rt]+=x;
        return;
    }
    down(l,r,rt);
    int mid=(l+r)/2;
    if(ll<=mid)change(l,mid,rt*2,ll,rr,x);///左边需要修改
    if(rr>mid)change(mid+1,r,rt*2+1,ll,rr,x);///右边需要修改
    tree[rt]=tree[rt*2]+tree[rt*2+1];///合并答案
}

long long int query(int l,int r,int rt,int ll,int rr)
{
    if(ll<=l&&r<=rr)return tree[rt];///到达最区间内的最上层节点，不用再往下找了
    down(l,r,rt);///向下推动lazy标记
    int mid=(l+r)/2;
    long long int ans=0;
    if(ll<=mid)ans+=query(l,mid,rt*2,ll,rr);///左边有答案
    if(rr>mid)ans+=query(mid+1,r,rt*2+1,ll,rr);///右边有答案
    return ans;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int i;
    memset(tree,0,sizeof(tree));
    memset(lazy,0,sizeof(lazy));
    for (i=0;i<m;i++)
    {
        int o,l,r,v;
        scanf("%d%d%d%d",&o,&l,&r,&v);
        if (o==0)
        {
            change(1,n,1,l,r,v);
        }
        else
        {
            printf("%lld\n",query(1,n,1,l,r));
        }
    }
    return 0;
}
