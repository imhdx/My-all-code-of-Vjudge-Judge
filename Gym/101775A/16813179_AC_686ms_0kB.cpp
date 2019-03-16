#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const ll INF=0x3f3f3f3f;
const ll INFll=2*INF*INF;
const double PI=4*atan(1.0);
ll poww(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
int main()
{
    int kk=1;
    int T;
    scanf("%d",&T);
    while (T--)
    {
        ll n,k;
        scanf("%lld%lld",&n,&k);
        ll ans=0;
        ll ret=1;
        for (int i=1;i<k;i++)
        {
            ret=ret*(n-i+1)%mod;
            ret=ret*poww(i,mod-2)%mod;
            ans+=ret;
            ans=ans%mod;
        }
        printf("Case #%d: %lld\n",kk++,((poww(2,n)-1-ans)%mod+mod)%mod);
    }
    return 0;
}
