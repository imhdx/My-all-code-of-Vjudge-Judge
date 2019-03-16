#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b)
{
    return b==0?a:gcd(b,a%b);
}
int main()
{
    long long n,m;
    while (scanf("%lld%lld",&n,&m)!=EOF)
    {
        n--;
        m--;
        long long ans=n*m/gcd(n,m)+1-(n/gcd(n,m)-1)*(m/gcd(n,m)-1);
        printf("%lld\n",ans);

    }

    return 0;
}
