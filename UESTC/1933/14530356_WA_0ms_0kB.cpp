#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

const int N=1000010;
int a[N];
int tree[N*4],lazy[N*4],num[N*4];

void maketree(int l,int r,int rt)
{
    lazy[rt]=0;
    if(l==r){tree[rt]=a[l];return;}
    int mid=(l+r)/2;
    maketree(l,mid,rt*2);
    maketree(mid+1,r,rt*2+1);
    tree[rt]=tree[rt*2]+tree[rt*2+1];
}


void down(int l,int r,int rt)
{
    if(lazy[rt]==0)return;
    int mid=(l+r)/2;

    lazy[rt*2]=1;
    tree[rt*2]=tree[rt*2]+num[rt]*(mid-l+1);
    num[rt*2]=num[rt];

    lazy[rt*2+1]=1;
    tree[rt*2+1]=tree[rt*2+1]+num[rt]*(r-mid);
    num[rt*2+1]=num[rt];
    lazy[rt]=0;
}


void gai(int l,int r,int rt,int ll,int rr,int x)
{

    if(ll<=l&&r<=rr)
    {
        tree[rt]=tree[rt]+x*(r-l+1);
        lazy[rt]=1;
        num[rt]=x;
        return;
    }
    down(l,r,rt);
    int mid=(l+r)/2;
    if(ll<=mid)gai(l,mid,rt*2,ll,rr,x);
    if(rr>mid)gai(mid+1,r,rt*2+1,ll,rr,x);
    tree[rt]=tree[rt*2]+tree[rt*2+1];
}


int query(int l,int r,int rt,int ll,int rr)
{
    if(ll<=l&&r<=rr)return tree[rt];
    down(l,r,rt);
    int mid=(l+r)/2;
    int ans=0;
    if(ll<=mid)ans+=query(l,mid,rt*2,ll,rr);
    if(rr>mid)ans+=query(mid+1,r,rt*2+1,ll,rr);
    return ans;
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(a,0,sizeof(a));
        maketree(1,n,1);
        int m;
        scanf("%d",&m);
        while(m--)
        {
            int q,l,r,x;
            scanf("%d",&q);
            if(q!=0)
            {
                scanf("%d%d%d",&l,&r,&x);
                printf("%d\n",query(1,n,1,l,r));
            }
            else
            {
                scanf("%d%d%d",&l,&r,&x);
                gai(1,n,1,l,r,x);
            }
        }
    }
    return 0;
}
