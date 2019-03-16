#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1000005;
long long int tree[N*4];
int MAX[N*4];
int MIN[N*4];


void gai(int l,int r,int rt,int p,int x)
{
    if(l==r)
    {
        tree[rt]=x;
        MAX[rt]=x;
        MIN[rt]=x;
        return;
    }
    int mid=(l+r)/2;
    if(p<=mid)gai(l,mid,rt*2,p,x);
    else gai(mid+1,r,rt*2+1,p,x);
    tree[rt]=tree[rt*2]+tree[rt*2+1];
    MAX[rt]=max(MAX[rt*2],MAX[rt*2+1]);
    MIN[rt]=min(MIN[rt*2],MIN[rt*2+1]);
}


long long int query(int l,int r,int rt,int ll,int rr)
{

    if(ll<=l&&r<=rr)return tree[rt];
    int mid=(l+r)/2;
    int ans=0;
    if(ll<=mid)
    {
        ans+=query(l,mid,rt*2,ll,rr);
    }
    if(rr>mid)
    {
        ans+=query(mid+1,r,rt*2+1,ll,rr);
    }
    return ans;
}
int minnn(int l,int r,int rt,int ll,int rr)
{

    if(ll<=l&&r<=rr)return MIN[rt];
    int mid=(l+r)/2;
    int minn=1000*1000*1000+1;
    if(ll<=mid)
    {
        minn=min(minn,minnn(l,mid,rt*2,ll,rr));
    }
    if(rr>mid)
    {
        minn=min(minn,minnn(mid+1,r,rt*2+1,ll,rr));
    }
    return minn;
}

int maxxx(int l,int r,int rt,int ll,int rr)
{

    if(ll<=l&&r<=rr)return MAX[rt];
    int mid=(l+r)/2;
    int maxx=-1000*1000*1000-1;
    if(ll<=mid)
    {
        maxx=max(maxx,maxxx(l,mid,rt*2,ll,rr));
    }
    if(rr>mid)
    {
        maxx=max(maxx,maxxx(mid+1,r,rt*2+1,ll,rr));
    }
    return maxx;
}


int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(MAX,0,sizeof(MAX));
        memset(MIN,0,sizeof(MIN));
        memset(tree,0,sizeof(tree));
        int m;
        scanf("%d",&m);
        while(m--)
        {
            int q,l,r,ans;
            scanf("%d%d%d",&q,&l,&r);
            if(q==1)printf("%lld\n",query(1,n,1,l,r)-minnn(1,n,1,l,r)-maxxx(1,n,1,l,r));
            else gai(1,n,1,l,r);
        }
    }
    return 0;
}
