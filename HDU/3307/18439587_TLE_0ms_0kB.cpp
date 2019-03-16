#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll phi(ll x)
{
    ll ans=x;
    for (ll i=2;i<=x;i++)
    {
        if (x%i==0)
        {
            ans=ans/i*(i-1);
            while (x%i==0) x=x/i;
        }
    }
    if (x!=1) ans=ans/x*(x-1);
    return ans;
}
ll gcd(ll a,ll b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}
ll mod;
ll poww(ll a,ll b)
{
    ll res=1;
    while (b)
    {
        if (b&1) res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
int main()
{
    ll x,y,a0;
    cout<<phi(13)<<endl;
    while (scanf("%lld%lld%lld",&x,&y,&a0)!=EOF)
    {
        ll t=y/(x-1);
        ll g=gcd(t,a0);
        t=t/g;
        a0=a0/g;
        if (gcd(x,a0)!=1)
        {
            printf("Impossible!\n");
            continue;
        }
        mod=a0;
        ll ans=phi(a0);
        //printf("ans=%lld\n",ans);
        ll aaa=-1;
        for (ll i=2;i*i<=ans;i++)
        {
            if (ans%i==0)
            {
                if (poww(x,i)%a0==1)
                {
                    if (aaa==-1) aaa=i;
                    else aaa=min(aaa,i);
                }
                ll j=ans/i;
                if (poww(x,j)%a0==1)
                {
                    if (aaa==-1) aaa=j;
                    else aaa=min(aaa,j);
                }
            }

        }
        if (aaa==-1) printf("-1\n");
        else
        printf("%lld\n",aaa);
    }
    return 0;
}
