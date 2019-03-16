#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        long long ans=1;
        long long x;
        for (int i=0;i<n;i++)
        {
            scanf("%lld",&x);
            ans=ans/gcd(ans,x)*x;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
