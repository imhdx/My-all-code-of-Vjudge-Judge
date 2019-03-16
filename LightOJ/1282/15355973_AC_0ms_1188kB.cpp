#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
long long poww(long long a,long long b)
{
    long long res=1;
    while (b)
    {
        if (b&1)
            res=(res*a)%1000;
        a=(a*a)%1000;
        b>>=1;
    }
    return res;
}
int main()
{
    int t=1;
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        long double ans=1.0*k*log10((long long)n);
        ans-=(long long)ans;
        long long kk=100*pow(10,ans);
        printf("Case %d: ",t++);
        printf("%lld %03d\n",kk,poww(n,k));
    }
    return 0;
}
