#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1000010;
int a[N];
int tree[N*4],lazy[N*4],num[N*4];


///向下推动lazy标记
void down(int l,int r,int rt)
{
    if(lazy[rt]==0)return;
    int mid=(l+r)/2;
    ///左儿子
    lazy[rt*2]=1;
    tree[rt*2]=num[rt]*(mid-l+1);
    num[rt*2]=num[rt];
    ///右儿子
    lazy[rt*2+1]=1;
    tree[rt*2+1]=num[rt]*(r-mid);
    num[rt*2+1]=num[rt];
    lazy[rt]=0;
}

///单点修改，a[p]=x
void gai(int l,int r,int rt,int ll,int rr,int x)
{
    ///cout<<l<<" "<<r<<" "<<ll<<" "<<rr<<endl;
    if(ll<=l&&r<=rr)///到达最区间内的最上层节点
    {
        tree[rt]=tree[rt]+x*(r-l+1);
        lazy[rt]=1;
        num[rt]=x;
        return;
    }
    down(l,r,rt);///向下推动lazy标记
    int mid=(l+r)/2;
    if(ll<=mid)gai(l,mid,rt*2,ll,rr,x);///左边需要修改
    if(rr>mid)gai(mid+1,r,rt*2+1,ll,rr,x);///右边需要修改
    tree[rt]=tree[rt*2]+tree[rt*2+1];///合并答案
}

///查询区间[l, r]的答案
int query(int l,int r,int rt,int ll,int rr)
{
    if(ll<=l&&r<=rr)return tree[rt];///到达最区间内的最上层节点，不用再往下找了
    down(l,r,rt);///向下推动lazy标记
    int mid=(l+r)/2;
    int ans=0;
    if(ll<=mid)ans+=query(l,mid,rt*2,ll,rr);///左边有答案
    if(rr>mid)ans+=query(mid+1,r,rt*2+1,ll,rr);///右边有答案
    return ans;
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int i;
        memset(tree,0,sizeof(tree));
        int m;
        scanf("%d",&m);
        while(m--)
        {
            int q,l,r,x;
            scanf("%d",&q);
            if(q==1)
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