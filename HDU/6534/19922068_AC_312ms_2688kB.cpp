//
// Created by mhdx on 2019/5/20.
//

#include<bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
int a[27003];
vector<int> v;
long long bit[27003];
int get(int x)
{
    return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}
int unit;
struct node{
    int l,r,pos;
    bool operator<(const node &b)const{
        if (l/unit!=b.l/unit) return l/unit<b.l/unit;
        return r<b.r;
    }
}que[27003];
int n,m,k;
long long ans[27003];
void add(int x,int val)
{
    while (x<=v.size()+1)
    {
        bit[x]+=val;
        x+=x&(-x);
    }
}
long long ask(int x)
{
    long long ans=0;
    while (x)
    {
        ans+=bit[x];
        x-=x&(-x);
    }
    return ans;
}
int read()
{
    int s=0;
    char c=getchar();
    while (c<'0'||c>'9') c=getchar();
    while (c>='0'&&c<='9')
    {
        s=s*10+c-'0';
        c=getchar();
    }
    return s;
}
int gg[27003];
int ggl[27003];
int ggr[27003];
int main()
{
    n=read();
    m=read();
    k=read();
    unit=sqrt(n);
    for (int i=1;i<=n;i++) a[i]=read(),v.push_back(a[i]);
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for (int i=1;i<=n;i++)
    {
        gg[i]=get(a[i]);
        ggr[i]=upper_bound(v.begin(),v.end(),a[i]+k)-v.begin()-1+1;
        ggl[i]=get(a[i]-k)-1;
    }
    for (int i=0;i<m;i++)
    {
        que[i].l=read();
        que[i].r=read();
        que[i].pos=i;
    }
    sort(que,que+m);
    int L=1;
    int R=0;
    long long tmp=0;
    for (int i=0;i<m;i++)
    {
        while (R<que[i].r){
            R++;
            tmp+=ask(ggr[R])-ask(ggl[R]);
            add(gg[R],1);
        }
        while (R>que[i].r)
        {
            add(gg[R],-1);
            tmp-=ask(ggr[R])-ask(ggl[R]);
            R--;
        }
        while (L<que[i].l)
        {
            add(gg[L],-1);
            tmp-=ask(ggr[L])-ask(ggl[L]);
            L++;
        }
        while (L>que[i].l)
        {
            L--;
            tmp+=ask(ggr[L])-ask(ggl[L]);
            add(gg[L],1);
        }
        ans[que[i].pos]=tmp;
    }
    for (int i=0;i<m;i++) printf("%lld\n",ans[i]);
    return 0;
}