#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        ll a,b;
        scanf("%lld%lld",&a,&b);
        if (b%a!=0)
        {
            printf("0\n");
            continue;
        }
        ll ans=1;
        for (ll i=2;i*i<=b;i++)
        {
            if (b%i==0)
            {
                int cnt1=0,cnt2=0;
                while (a%i==0)
                {
                    cnt1++;
                    cnt2++;
                    b=b/i;
                    a=a/i;
                }
                while (b%i==0)
                {
                    b=b/i;
                    cnt2++;
                }
                ans=ans*6*(cnt2-cnt1);
            }
        }
        if (b!=1)
        {
            if (a==1) ans=ans*6;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
