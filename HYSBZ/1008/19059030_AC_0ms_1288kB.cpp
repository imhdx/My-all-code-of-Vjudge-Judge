#include<bits/stdc++.h>
using namespace std;
const int mod=100003;
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
    long long n,m;
    scanf("%lld%lld",&m,&n);
    long long ans=m;
    ans=ans*poww(m-1,n-1)%mod;
    ans=poww(m,n)-ans;
    ans%=mod;
    ans+=mod;
    ans%=mod;
    printf("%lld\n",ans);
    return 0;
}
