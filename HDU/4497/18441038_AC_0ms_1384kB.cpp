#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int T;scanf("%d",&T);
    while (T--)
    {
        ll a,b;
        scanf("%lld%lld",&a,&b);
        if (b%a!=0)
        {
            printf("0\n");
            continue;
        }
        a=b/a;
        ll ans=1;
        for (ll i=2;i*i<=a;i++)
        {
            if (a%i==0)
            {
                int cnt=0;
                while (a%i==0) cnt++,a/=i;
                ans=ans*6*cnt;
            }
        }
        if (a!=1) ans=ans*6;
        printf("%lld\n",ans);
    }
    return 0;
}
