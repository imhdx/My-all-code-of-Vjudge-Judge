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
    long long n;
    while (scanf("%lld",&n)!=EOF)
    {
        long long ans=0;
        ans=(n+1)%mod*(poww(2,n)-1)%mod-(poww(2,n+1)-n-2)%mod;
        ans%=mod;
        ans+=mod;
        ans%=mod;
        printf("%lld\n",ans);
    }
    return 0;
}