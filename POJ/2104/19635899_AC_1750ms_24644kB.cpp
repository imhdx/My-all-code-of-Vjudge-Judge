//
// Created by mhdx on 2019/5/7.
//

#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=100010;
const int M=maxn*30;
int n,q,m,tot;
int a[maxn],t[maxn];
int T[maxn],lson[M],rson[M],c[M];
void init()
{
    for (int i=1;i<=n;i++)
        t[i]=a[i];
    sort(t+1,t+1+n);
    m=unique(t+1,t+1+n)-t-1;
}
int build(int l,int r)
{
    int root=tot++;
    c[root]=0;
    if (l!=r)
    {
        int mid=l+r>>1;
        lson[root]=build(l,mid);
        rson[root]=build(mid+1,r);

    }
    return root;
}
int hash(int x)
{
    return lower_bound(t+1,t+1+m,x)-t;
}
int update(int root,int pos,int val)
{
    int newroot=tot++,tmp=newroot;
    c[newroot]=c[root]+val;
    int l=1,r=m;
    while (l<r)
    {
        int mid=l+r>>1;
        if (pos<=mid)
        {
            lson[newroot]=tot++;rson[newroot]=rson[root];
            newroot=lson[newroot];root=lson[root];
            r=mid;
        }
        else
        {
            rson[newroot]=tot++;lson[newroot]=lson[root];
            newroot=rson[newroot];root=rson[root];
            l=mid+1;
        }
        c[newroot]=c[root]+val;
    }
    return tmp;
}
int query(int left_root,int right_root,int k)
{
    int l=1,r=m;
    while (l<r)
    {
        int mid=l+r>>1;
        if (c[lson[left_root]]-c[lson[right_root]]>=k)
        {
            r=mid;
            left_root=lson[left_root];
            right_root=lson[right_root];
        } else{
            l=mid+1;
            k-=c[lson[left_root]]-c[lson[right_root]];
            left_root=rson[left_root];
            right_root=rson[right_root];
        }
    }
    return l;
}
int main()
{
    while (scanf("%d%d",&n,&q)!=EOF)
    {
        tot=0;
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        init();
        T[n+1]=build(1,m);
        for (int i=n;i;i--)
        {
            int pos=hash(a[i]);
            T[i]=update(T[i+1],pos,1);
        }
        while (q--)
        {
            int l,r,k;
            scanf("%d%d%d",&l,&r,&k);
            printf("%d\n",t[query(T[l],T[r+1],k)]);
        }
    }

    return 0;
}