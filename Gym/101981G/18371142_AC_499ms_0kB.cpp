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
    long long inv=poww(24,mod-2);
    int T;scanf("%d",&T);
    while (T--)
    {
        long long n;
        scanf("%I64d",&n);
        n+=3;
        long long ans=n*(n-1)%mod*(n-2)%mod*(n-3)%mod*inv%mod;
        printf("%I64d\n",ans);
    }
    return 0;
}
