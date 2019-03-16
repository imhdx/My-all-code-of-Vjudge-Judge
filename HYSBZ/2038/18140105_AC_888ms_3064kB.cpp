#include<bits/stdc++.h>
using namespace std;
struct ac
{
    int l,r,id;
}que[50004];
int block;
long long gcd(long long a,long long b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}
bool cmp(ac q,ac p)
{
    if (q.l/block!=p.l/block)  return q.l/block<p.l/block;
    if ((q.l/block)&1)
    return q.r<p.r;
    else return q.r>p.r;
}
int cnt[50004];
int a[50004];
long long ans1[50004];
long long ans2[50004];
long long tmp=0;
void add(int x)
{
    tmp-=cnt[a[x]]*(cnt[a[x]]-1);
    cnt[a[x]]++;
    tmp+=cnt[a[x]]*(cnt[a[x]]-1);
}
void del(int x)
{
    tmp-=cnt[a[x]]*(cnt[a[x]]-1);
    cnt[a[x]]--;
    tmp+=cnt[a[x]]*(cnt[a[x]]-1);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    block=sqrt(n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);

    for (int i=0;i<m;i++)
    {
        scanf("%d%d",&que[i].l,&que[i].r);
        que[i].id=i;
    }
    sort(que,que+m,cmp);
    memset(cnt,0,sizeof(cnt));
    int L=1,R=0;
    tmp=0;
    for (int i=0;i<m;i++)
    {
        while (R<que[i].r) add(++R);
        while (R>que[i].r) del(R--);
        while (L>que[i].l) add(--L);
        while (L<que[i].l) del(L++);
        ans1[que[i].id]=tmp;
        ans2[que[i].id]=1ll*(R-L+1)*(R-L);
    }
    for (int i=0;i<m;i++)
    {
        long long tmp=gcd(ans1[i],ans2[i]);
        ans1[i]/=tmp;
        ans2[i]/=tmp;
        if (ans1[i]==0) printf("0/1\n");
        else printf("%lld/%lld\n",ans1[i],ans2[i]);
    }
    return 0;
}
