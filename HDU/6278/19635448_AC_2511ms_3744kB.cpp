//
// Created by mhdx on 2019/5/7.
//

#include<bits/stdc++.h>
using namespace std;
int n,m;
const int maxn=100005;
int a[maxn];
int bit[maxn];
void add(int x,int val)
{
    while (x)
    {
        bit[x]+=val;
        x-=x&(-x);
    }
}
int ask(int x)
{
    int ans=0;
    while (x<=n)
    {
        ans+=bit[x];
        x+=x&(-x);
    }
    return ans;
}
struct node
{
    int l,r;
    int now;
}v[maxn];
int unit;
bool cmp(struct node q,struct node p)
{
    if (q.l/unit!=p.l/unit) return q.l/unit<p.l/unit;
    return q.r<p.r;
}
int ans[maxn];
int main()
{
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        unit=(int)sqrt(n);
        for (int i=0;i<m;i++)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            v[i].l=l;
            v[i].r=r;
            v[i].now=i;
        }
        sort(v,v+m,cmp);
        for (int i=0;i<=n;i++) bit[i]=0;
        int L=1;
        int R=0;
        for (int i=0;i<m;i++)
        {
            while (R<v[i].r)
            {
                R++;
                add(a[R],1);
            }
            while (R>v[i].r)
            {
                add(a[R],-1);
                R--;
            }
            while (L<v[i].l)
            {
                add(a[L],-1);
                L++;
            }
            while (L>v[i].l)
            {
                L--;
                add(a[L],1);
            }
            int l=1;
            int r=n;
            int tmp=-1;
            while (l<=r)
            {
                int mid=l+r>>1;
                if (ask(mid)>=mid)
                {
                    tmp=mid;
                    l=mid+1;
                }
                else r=mid-1;
            }
            ans[v[i].now]=tmp;
        }
        for (int i=0;i<m;i++)
        {
            printf("%d\n",ans[i]);
        }


    }

    return 0;
}//