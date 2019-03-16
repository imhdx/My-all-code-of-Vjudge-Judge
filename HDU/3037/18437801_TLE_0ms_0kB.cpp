#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod;
#define mul(a,b,c) ((a)*(b)%c)
struct Factorial//预处理阶乘及对应的逆元
{
	vector<ll> fac,ifac;
	ll M;
	Factorial(int N,ll M):fac(N,1),ifac(N,1),M(M)
	{
		for(int i=2; i<N; ++i)
			fac[i]=mul(fac[i-1],i,M),ifac[i]=mul(M-M/i,ifac[M%i],M);
		for(int i=2; i<N; ++i)ifac[i]=mul(ifac[i],ifac[i-1],M);
	}
	ll c(int n,int m)
	{
		return mul(mul(fac[n],ifac[m],M),ifac[n-m],M);
	}
	ll lucas(ll n,ll m)//卢卡斯定理求C(n,m)%M，适用于模数M小于N的情况，或者m较小的时候也可以暴力求
	{
		return !m?1:
		       n<m||n%M<m%M?0:
		       n<M&&m<M?c(n,m):
		       mul(lucas(n/M,m/M),lucas(n%M,m%M),M);
	}
};
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        ll n,m;
        scanf("%lld%lld%d",&n,&m,&mod);
        Factorial ac(200000,mod);
        ll ans=ac.lucas(n+m,m);
        printf("%lld\n",ans);
    }

    return 0;
}
