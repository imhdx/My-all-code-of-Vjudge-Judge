#include<bits/stdc++.h>
using namespace std;
int a[30004];
int cnt[30004];
const long long mod=1000000007;
struct ac
{
    int l,r;
    int id;
}que[30004];
int unit;
bool cmp1(ac a,ac b)
{
    if (a.l/unit!=b.l/unit) return a.l/unit<b.l/unit;
    return a.r<b.r;
}
long long inv[30004];
void init()
{
    inv[1]=1;
    for (int i=2;i<=30000;i++)
        inv[i]=(long long)mod/i*(mod-inv[mod%i])%mod;
}
long long ans[30004];
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        unit=(int)sqrt(n);
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        for (int i=0;i<m;i++)
        {
            scanf("%d%d",&que[i].l,&que[i].r);
            que[i].id=i;
        }
        sort(que,que+m,cmp1);
        long long tmp=1;
        long long sum=que[0].r-que[0].l+1;
        memset(cnt,0,sizeof(cnt));
        for (int i=que[0].l;i<=que[0].r;i++)
        {
            tmp=tmp*(i-que[0].l+1)%mod;

            cnt[a[i]]++;
            tmp=tmp*inv[cnt[a[i]]]%mod;
        }
        ans[que[0].id]=tmp;

        int L=que[0].l;
        int R=que[0].r;
        for (int i=1;i<m;i++)
        {
            int l=que[i].l;
            int r=que[i].r;
            while (l<L)
            {
                sum++;
                L--;
                cnt[a[L]]++;
                tmp=tmp*inv[cnt[a[L]]]%mod;
                tmp=tmp*sum%mod;
            }
            while (l>L)
            {
                tmp=tmp*inv[sum]%mod;
                cnt[a[L]]--;
                tmp=tmp*cnt[a[L]]%mod;
                sum--;
                L++;
            }
            while (r<R)
            {
                tmp=tmp*inv[sum]%mod;
                cnt[a[R]]--;
                tmp=tmp*cnt[a[R]]%mod;
                sum--;
                R--;
            }
            while (r>R)
            {
                sum++;
                R++;
                cnt[a[R]]++;
                tmp=tmp*inv[cnt[a[R]]]%mod;
                tmp=tmp*sum%mod;
            }
            ans[que[i].id]=tmp;
        }
        for (int i=0;i<m;i++)
            printf("%lld\n",(ans[i]%mod+mod)%mod);
    }
    return 0;
}
