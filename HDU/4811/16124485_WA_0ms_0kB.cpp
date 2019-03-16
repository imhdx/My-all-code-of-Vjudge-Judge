#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int a[4];
    while (scanf("%lld%lld%lld",&a[0],&a[1],&a[2])!=EOF)
    {
        long long int ans=0;
        sort(a,a+3);
        if (a[0]>=2)
        {
            ans=15+6ll*(a[0]+a[1]+a[2]-6);
        }
        else
        {
            ans=(a[0]+a[1]+a[2])*(a[0]+a[1]+a[2]-1)/2;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
