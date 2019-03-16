#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const ll INF=0x3f3f3f3f;
const ll INFll=2*INF*INF;
const double PI=4*atan(1.0);
ll poww(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll inv[100005];
ll jie[100005];
int main()
{
    inv[0]=1;
    for (int i=1;i<100005;i++) inv[i]=poww(i,mod-2);
    int T;
    scanf("%d",&T);
    while (T--)
    {
        ll n,k;
        scanf("%lld%lld",&n,&k);
        ll ans=0;
        jie[0]=1;
        jie[1]=n;
        int m=n-1;
        for (int i=2;i<=k;i++) jie[i]=(jie[i-1]*m--)%mod;
        for (int i=0;i<k;i++)
        {
            ans+=jie[i]*inv[i]%mod;
            ans=ans%mod;
        }
        ans=((poww(2,n)-ans)%mod+mod)%mod;
        printf("%lld\n",ans);
    }
    return 0;
}
