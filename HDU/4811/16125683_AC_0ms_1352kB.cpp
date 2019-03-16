#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a[4];
    while (scanf("%lld%lld%lld",&a[0],&a[1],&a[2])!=EOF)
    {
        long long int cnt=min(2ll,a[0])+min(2ll,a[1])+min(2ll,a[2]);

        long long ans=cnt*(cnt-1)/2+cnt*(a[0]+a[1]+a[2]-cnt);
        printf("%lld\n",ans);
    }
    return 0;
}
