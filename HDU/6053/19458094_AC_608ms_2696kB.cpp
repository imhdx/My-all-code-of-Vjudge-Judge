#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int a[maxn];
int sum[maxn];
int mu[maxn];
bool check[maxn];
int prime[maxn];
const int mod=1e9+7;
long long poww(long long a,long long b)
{
    long long res=1;
    while (b)
    {
        if (b&1) res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
void init()
{
    mu[1]=1;
    int tot=0;
    for (int i=2;i<maxn;i++)
    {
        if (check[i]==0)
        {
            prime[tot++]=i;
            mu[i]=-1;
        }
        for (int j=0;j<tot;j++)
        {
            if (i*prime[j]>maxn) break;
            check[i*prime[j]]=1;
            if (i%prime[j]==0)
            {
                mu[i*prime[j]]=0;
                break;
            }
            else mu[i*prime[j]]=-mu[i];
        }
    }

}
int main()
{
    init();
    int tt=1;
    int T;scanf("%d",&T);
    while (T--)
    {
        memset(sum,0,sizeof(sum));
        int minn=1e9+7;
        int n;scanf("%d",&n);
        for (int i=1;i<=n;i++) scanf("%d",&a[i]),minn=min(minn,a[i]);
        for (int i=1;i<=n;i++) sum[a[i]]++;
        for (int i=1;i<maxn;i++) sum[i]+=sum[i-1];
        long long ans=0;
        for (int i=2;i<=minn;i++)
        {
            long long tmp=1;
            for (int j=i;j<maxn;j+=i) tmp=tmp*poww(j/i,sum[min(maxn-1,j+i-1)]-sum[j-1])%mod;
            ans-=mu[i]*tmp;
            ans%=mod;
            ans+=mod;
            ans%=mod;
        }
        printf("Case #%d: ",tt++);
        printf("%lld\n",ans);

    }
    return 0;
}
//