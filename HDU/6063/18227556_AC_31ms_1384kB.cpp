#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
ll poww(ll a,ll b)
{
    a%=mod;
    ll res=1;
    while (b)
    {
        if (b&1) res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
int main()
{
    int t=1;
    long long n,k;
    while (scanf("%lld%lld",&n,&k)!=EOF)
    {
        printf("Case #%d: ",t++);
        k%=(mod-1);
        printf("%lld\n",poww(n,k));
    }
    return 0;
}
