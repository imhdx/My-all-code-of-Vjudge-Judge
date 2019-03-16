#include<cstdio>
#include<algorithm>
using namespace std;
long long c[1000010];
const int mod=1000000007;
long long poww(long long a,long long b)
{
    long long res=1;
    while (b){
        if (b&1) res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
}
long long inv[1000010];
int main()
{
    inv[1]=1;
    for (int i=2;i<1000010;i++)
    {
        inv[i]=mod/i*(mod-inv[mod%i])%mod;
    }
    c[0]=1;

    for (int i=1;i<1000010;i++)
    {
        c[i]=c[i-1]*(4*i%mod-2)%mod*inv[i+1]%mod;

    }
    int t=1;
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        printf("Case #%d:\n",t++);
        printf("%lld\n",c[n]);
    }
    return 0;
}
