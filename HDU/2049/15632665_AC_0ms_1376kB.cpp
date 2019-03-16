#include<bits/stdc++.h>
using namespace std;
long long F[100010];
const int mod=1e9+7;
void init(long long p)///p=max(min(n,m)p)
{
    F[0]=1;
    for (int i=1;i<=p;i++)
        F[i]=F[i-1]*i%mod;
}
long long inv(long long a,long long m)
{
    if (a==1) return 1;
    return inv(m%a,m)*(m-m/a)%m;
}
long long Lucas(long long n,long long m,long long p=1e9+7)
{
    long long ans=1;
    while (n&&m)
    {
        long long a=n%p;
        long long b=m%p;
        if (a<b) return 0;
        ans=ans*F[a]%p*inv(F[b]*F[a-b]%p,p)%p;
        n/=p;
        m/=p;
    }
    return ans;
}
long long cuo[30];
void cuopai(int m)
{
    cuo[1]=0;
    cuo[2]=1;
    for (int i=3;i<=m;i++)
        cuo[i]=(i-1)*(cuo[i-1]+cuo[i-2]);
}
int main()
{
    init(20);
    cuopai(20);
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        printf("%lld\n",cuo[m]*Lucas(n,m));
    }
    return 0;
}
