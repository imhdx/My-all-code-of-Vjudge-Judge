#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll poww(ll a,ll b)
{
    ll res=1;
    while (b)
    {
        if (b&1) res=res*a;
        a=a*a;
        b>>=1;
    }
    return res;
}
int main()
{
    ll k;
    while (scanf("%lld",&k)!=EOF)
    {
        int i;
        for (i=0;i<16;i++)
        {
            if (poww(i,i)>k) break;
        }
        printf("%d\n",i-1);
    }
    return 0;
}
