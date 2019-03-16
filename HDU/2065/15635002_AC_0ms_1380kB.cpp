#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=100;
ll poww(ll a,ll b)
{
    ll res=1;
    while (b>0)
    {
        if (b&1)
            res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
int main()
{
    int T;
    int flag=0;
    while (scanf("%d",&T)!=EOF)
    {
        if (T==0) break;
        //if (flag!=0) printf("\n");
        //flag=1;
        for (int i=1;i<=T;i++)
        {
            long long int n;
            scanf("%lld",&n);
            printf("Case %d: %lld\n",i,(poww(4,n-1)+poww(2,n-1))%mod);
        }
        printf("\n");
    }
    return 0;
}
