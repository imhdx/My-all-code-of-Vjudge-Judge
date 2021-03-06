#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=100005;
int a[N];
int tree[N*4];

void maketree(int l,int r,int rt)
{
    if(l==r){tree[rt]=a[l];return;}
    int mid=(l+r)/2;
    maketree(l,mid,rt*2);
    maketree(mid+1,r,rt*2+1);
    tree[rt]=tree[rt*2]+tree[rt*2+1];
}
void gai(int l,int r,int rt,int p,int x)
{
    if(l==r){tree[rt]=(int)sqrt(tree[rt]);return;}
    int mid=(l+r)/2;
    if(mid>=p) gai(l,mid,rt*2,p,x);
    if(mid+1<=x) gai(mid+1,r,rt*2+1,p,x);
    tree[rt]=tree[rt*2]+tree[rt*2+1];
}


int query(int l,int r,int rt,int ll,int rr)
{

    if(ll<=l&&r<=rr)return tree[rt];
    int mid=(l+r)/2;
    int ans=0;
    if(ll<=mid)ans+=query(l,mid,rt*2,ll,rr);
    if(rr>mid)ans+=query(mid+1,r,rt*2+1,ll,rr);
    return ans;
}

int main()
{
    int n;
    int kkk=1;
    while(scanf("%d",&n)!=EOF)
    {
        printf("Case #%d:\n",kkk);
        kkk++;
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        maketree(1,n,1);
        int m;
        scanf("%d",&m);
        while(m--)
        {
            int q,l,r,ans;
            scanf("%d%d%d",&q,&l,&r);
            if (l>r) swap(l,r);
            if(q==1)printf("%d\n",query(1,n,1,l,r));
            else gai(1,n,1,l,r);
        }
    }
    return 0;
}
