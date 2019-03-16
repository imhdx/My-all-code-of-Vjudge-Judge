#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
long long f(long long n)
{
    long long ans=0;
    while (n)
    {
        ans+=n/5;
        n=n/5;
    }
    return ans;
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        long long n;
        scanf("%lld",&n);
        printf("%lld\n",f(n));
    }
    return 0;
}
