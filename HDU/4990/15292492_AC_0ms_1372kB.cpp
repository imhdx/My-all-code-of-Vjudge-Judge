#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
long long pow_mod(long long a,long long n,long long m)
{
    long long ans=1;
    while(n)
    {
        if(n&1) ans=ans*a%m;
        a=a*a%m;
        n>>=1;
    }
    return ans;
}
int main()
{
    long long n,m;
    while(~scanf("%lld %lld",&n,&m))
    {
        if(n==1&&m==1) {
            printf("0\n");
            continue;
        }
        long long ans;
        if(n&1)
            ans=(pow_mod(4,n/2+1,3*m)-1)%(3*m)/3;
        else
            {
                ans=(pow_mod(4,(n-1)/2+1,3*m)-1)%(3*m)/3;
                ans=ans*2%m;
            }
            printf("%lld\n",ans);
    }
    return 0;
}
