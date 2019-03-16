#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    int t;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%lld",&n);
        long double a=n*(long double)log10(n);
        a=a-(long long)a;
        long long ans=pow(10,a);
        printf("%lld\n",ans);
    }
    return 0;
}
