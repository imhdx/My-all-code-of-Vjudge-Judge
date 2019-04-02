#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int poww(int a,int b)
{
    int res=1;
    while (b)
    {
        if (b&1) res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
int c[2002][2002];
int s2[2002][2002];
int fac[2002];
void init()
{
    fac[0]=1;
    for (int i=1;i<2002;i++) fac[i]=fac[i-1]*i%mod;
    c[0][0]=1;
    for (int i=1;i<2002;i++)
    {
        c[i][0]=c[i][i]=1;
        for (int j=1;j<i;j++) c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
    }
    s2[1][1]=1;
    for (int i=2;i<2002;i++)
        for (int j=1;j<2002;j++)
        s2[i][j]=(s2[i-1][j-1]+j*s2[i-1][j]%mod)%mod;
}
signed main()
{
    init();
    int T;
    scanf("%lld",&T);
    while (T--)
    {
        int n,m;
        scanf("%lld%lld",&n,&m);
        int ans=0;
        for (int i=1;i<=min(n,m-1);i++)
        {
            ans+=c[m][i]*fac[i]%mod*s2[n][i]%mod*poww(m-i,n)%mod;
            ans%=mod;
        }
        ans%=mod;
        ans+=mod;
        ans%=mod;
        printf("%lld\n",ans);
    }
    return 0;
}
