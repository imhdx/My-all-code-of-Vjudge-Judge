#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=50010;
int a[N];
int tree[N*4];

///建树
void maketree(int l,int r,int rt)
{
    if(l==r){tree[rt]=a[l];return;}///到达叶子节点
    int mid=(l+r)/2;
    maketree(l,mid,rt*2);
    maketree(mid+1,r,rt*2+1);
    tree[rt]=tree[rt*2]+tree[rt*2+1];///合并答案
}

///单点修改，a[p]=x
void gai(int l,int r,int rt,int p,int x)
{
    if(l==r){tree[rt]=x;return;}///到达叶子节点
    int mid=(l+r)/2;
    if(p<=mid)gai(l,mid,rt*2,p,x);///p在左边
    else gai(mid+1,r,rt*2+1,p,x);///p在右边
    tree[rt]=tree[rt*2]+tree[rt*2+1];///合并答案
}

///查询区间[l, r]的答案
int query(int l,int r,int rt,int ll,int rr)
{

    if(ll<=l&&r<=rr)return tree[rt];///不用再往下找了
    int mid=(l+r)/2;
    int ans=0;
    if(ll<=mid)ans+=query(l,mid,rt*2,ll,rr);///左边有答案
    if(rr>mid)ans+=query(mid+1,r,rt*2+1,ll,rr);///右边有答案
    return ans;
}

int main()
{
    int n;
    int T;
    scanf("%d",&T);
    for (int j=1;j<=T;j++)
    {

        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        maketree(1,n,1);
        char m[100];
        printf("Case %d:\n",j);
        while (scanf("%s",m)!=EOF&&m[0]!='E')
        {
            int l,r,ans;
            if(m[0]=='Q') {scanf("%d%d",&l,&r);printf("%d\n",query(1,n,1,l,r));}
            else if(m[0]=='A') {scanf("%d%d",&l,&r);gai(1,n,1,l,r+a[l]);}
            else if(m[0]=='S') {scanf("%d%d",&l,&r);gai(1,n,1,l,a[l]-r);}
        }
    }
    return 0;
}
