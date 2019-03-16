#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+7;
int belong[MAXN],num,block,l[MAXN],r[MAXN];
long long int a[MAXN];
int n;
long long int lazy[MAXN];
vector<long long int>v[MAXN];
void build()
{
    block=sqrt(n);
    num=n/block; if (n%block) num++;
    int i;
    for (i=1;i<=num;i++)
        l[i]=(i-1)*block+1,r[i]=i*block;
    r[num]=n;
    for (i=1;i<=n;i++)
        belong[i]=(i-1)/block+1;
}
void updata(int tl)///更新a[tl]所在的块
{
    v[belong[tl]].clear();
    int i;
    for (i=l[belong[tl]];i<=r[belong[tl]];i++)
        v[belong[tl]].push_back(a[i]);
    sort(v[belong[tl]].begin(),v[belong[tl]].end());
}
void add(int tl,int tr,int x)
{
    if (belong[tl]==belong[tr])
    {
        for (int i=tl;i<=tr;i++)
            a[i]+=x;
        updata(tl);
        return ;
    }
    for (int i=tl;i<=r[belong[tl]];i++)
        a[i]+=x;
    updata(tl);
    for (int i=belong[tl]+1;i<belong[tr];i++)
        lazy[i]+=x;
    for (int i=l[belong[tr]];i<=tr;i++)
        a[i]+=x;
    updata(tr);
}
long long int ask(int tl,int tr,int x)
{
    int i;
    long long int ans=-1;
    if (belong[tl]==belong[tr])
    {
        for (i=tl;i<=tr;i++)
        {
            if (a[i]+lazy[belong[i]]<x) ans=max(ans,a[i]+lazy[belong[i]]);
        }
        return ans;
    }
    for (i=tl;i<=r[belong[tl]];i++)
        if (a[i]+lazy[belong[i]]<x) ans=max(ans,a[i]+lazy[belong[i]]);
    for (i=belong[tl]+1;i<belong[tr];i++)
    {
        int index=lower_bound(v[i].begin(),v[i].end(),x-lazy[i])-v[i].begin();
        if (index>0) ans=max(ans,v[i][index-1]+lazy[i]);
    }
    for (i=l[belong[tr]];i<=tr;i++)
        if (a[i]+lazy[belong[i]]<x) ans=max(ans,a[i]+lazy[belong[i]]);
    return ans;
}
int main()
{
    memset(lazy,0,sizeof(lazy));
    int i;
    scanf("%d",&n);
    build();
    for (int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        v[belong[i]].push_back(a[i]);
    }
    for (i=1;i<=num;i++)
        sort(v[i].begin(),v[i].end());
    for (int i=0;i<n;i++)
    {
        int op,tl,tr,x;
        scanf("%d%d%d%d",&op,&tl,&tr,&x);
        if (op==1)
            printf("%lld\n",ask(tl,tr,x));
        else
            add(tl,tr,x);
    }
    return 0;
}
