#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e6+3;
ll mod=1000003;
ll jie[MAXN];
ll poww(ll a,ll b)
{
    ll res=1;
    while (b)
    {
        if (b&1)
            res=(res*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return res;
}
ll com(ll x,ll y)
{
    if (y>x/2)
        y=x-y;
    ll ans=jie[x];
    ll aaa=(jie[y]*jie[x-y])%mod;
    ans=(ans*poww(aaa,mod-2))%mod;
    return ans;
}

///a/b=a/b*(b*b^(M-2))=a*(b^(M-2))(mod M)

int main()
{
    int T;
    scanf("%d",&T);
    int i;
    jie[0]=1;
    jie[1]=1;
    for (i=2;i<MAXN;i++)
        jie[i]=(jie[i-1]*i)%mod;
    for (i=1;i<=T;i++)
    {
        printf("Case %d: ",i);
        long long int x,y;
        scanf("%lld%lld",&x,&y);
        printf("%lld\n",com(x,y));
    }
    return 0;
}
