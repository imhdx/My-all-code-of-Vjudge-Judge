#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int mod=1e9+7;
const double PI=3.141592653598793;
typedef long long ll;
ll poww(ll a,ll b){ll res=1;while(b){if(b&1)res=res*a%mod;a=a*a%mod;b>>=1;}return res;}
ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
long long int a[100010];
int main()
{
    long long int n,m;
    while (scanf("%lld%lld",&n,&m)!=EOF)
    {
        int i;
        for (i=0;i<n;i++)
        {
            long long int x;
            scanf("%lld",&x);
            x=x%m;
            a[i]=x;
        }
        sort(a,a+n);
        long long int maxx=-100;
        int st=0;
        int la=n-1;
        int j,k;
        for (la=n-1;la>=1;la--)
        {
            st=0;
            long long int pos=upper_bound(a,a+n,m-a[la])-a;
            //printf("la=%d pos=%d  a[la]==%lld\n",la,pos,a[la]);
            maxx=max(maxx,(a[max(pos-1,0ll)]+a[la])%m);
            maxx=max(maxx,(a[min(pos,n-1)]+a[la])%m);
            if (maxx==m-1)
                break;
        }
        printf("%lld\n",maxx);
    }
    return 0;
}
