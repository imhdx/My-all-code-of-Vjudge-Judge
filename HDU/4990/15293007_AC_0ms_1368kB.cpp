#include<bits/stdc++.h>
using namespace std;
long long poww(int x,int y)
{
    int tmp=x;

    long long mod=3ll*y;
    long long ans=1ll,a=2;
    while (x)
    {
        if (x&1)
        {
            ans=(ans*a)%mod;
        }
        a=(a*a)%mod;
        x>>=1;
    }
    if (tmp%2==0) return (ans-1%mod+mod)%mod;
    else
        return (ans-2%mod+mod)%mod;
}
int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        printf("%lld\n",poww(n+1,m)/3);
    }
    return 0;
}
