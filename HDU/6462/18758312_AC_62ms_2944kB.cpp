#include<bits/stdc++.h>
using namespace std;
const int mod=192600817;
long long f[100000];
long long a[100000];
int main()
{
    f[0]=1;
    f[1]=1;

    a[0]=1;
    a[1]=1;

    for (int i=2;i<100000;i++)
    {
        f[i]=f[i-1]+f[i-2];
        f[i]%=mod;
        a[i]=f[i]*f[i]%mod;
        a[i]%=mod;
    }

    for (int i=1;i<100000;i++)
    {
        a[i]+=a[i-1];
        a[i]%=mod;
    }
    int T;
    while (scanf("%d",&T)!=EOF)
    {
        while (T--)
        {
            int aa,b,c,d;
            scanf("%d%d%d%d",&aa,&b,&c,&d);
            aa=aa*4+b;
            c=c*4+d;
            if (aa>c) swap(aa,c);
            long long ans=0;
            if (aa==0) ans=a[c];
            else ans=a[c]-a[aa-1];
            ans%=mod;
            ans+=mod;
            ans%=mod;
            printf("%lld\n",ans);
        }
    }
    return 0;
}