#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
long long poww(long long a,long long b)
{
    long long res=1;
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
    int T;
    scanf("%d",&T);
    while (T--)
    {
        long long n,m;
        scanf("%lld%lld",&n,&m);
        m--;
        long long ans;
        if (n&1)
        {
            ans=(2*poww(poww(2,n)-1,m)%mod+1)*poww(3,mod-2)%mod;
        }
        else ans=2*poww(poww(2,n)-1,m)%mod*poww(3,mod-2)%mod;
        ans%=mod;
        ans+=mod;
        ans%=mod;
        printf("%lld\n",ans);
    }
    return 0;
}
//