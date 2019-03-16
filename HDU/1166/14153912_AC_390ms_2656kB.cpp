#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=50010;
int a[N];
int tree[N*4];
char m[100];

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
    if(l==r)
    {
        if (m[0]=='A')
            tree[rt]+=x;
        else if (m[0]=='S')
            tree[rt]-=x;
        return;
    }
    int mid=(l+r)/2;
    if(p<=mid)gai(l,mid,rt*2,p,x);
    else gai(mid+1,r,rt*2+1,p,x);
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
    int T;
    scanf("%d",&T);
    for (int j=1;j<=T;j++)
    {

        memset(a,0,sizeof(a));
        memset(tree,0,sizeof(tree));
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        maketree(1,n,1);
        printf("Case %d:\n",j);
        while (scanf("%s",&m)!=EOF&&m[0]!='E')
        {
            int l,r,ans;
            if(m[0]=='Q') {scanf("%d%d",&l,&r);printf("%d\n",query(1,n,1,l,r));}
            else if(m[0]=='A'||m[0]=='S') {scanf("%d%d",&l,&r);gai(1,n,1,l,r);}
        }
    }
    return 0;
}
