#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod;
ll poww(ll a,ll b)
{
    ll res=1;
    while (b)
    {
        if (b&1) res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
ll c(ll n,ll m)
{
    if (n<m) return 0;
    ll a=1,b=1;
    while (m)
    {
        a=a*n%mod;
        b=b*m%mod;
        n--;
        m--;
    }
    return a*poww(b,mod-2)%mod;
}
ll lucas(ll n,ll m)//卢卡斯定理求C(n,m)%M，适用于模数M小于N的情况，或者m较小的时候也可以暴力求
{
    if (m==0) return 1;
    return lucas(n/mod,m/mod)*c(n%mod,m%mod)%mod;
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        ll n,m;
        scanf("%lld%lld%lld",&n,&m,&mod);
        ll ans=lucas(n+m,m);
        printf("%lld\n",ans);
    }

    return 0;
}
