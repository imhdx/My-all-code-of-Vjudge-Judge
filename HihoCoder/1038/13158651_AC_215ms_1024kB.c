#include<stdio.h>
struct note
{
    long long int w;
    long long int mon;
}a[1000];
long long int dp[300000];
long long int max(long long int a,long long int b)
{
    if (a<b) return b;
    return a;
}
int main()
{
    long long int n,m;
    while (scanf("%lld%lld",&n,&m)!=EOF)
    {
        long long int i,j,k;
        for (i=0;i<n;i++)
            scanf("%lld%lld",&a[i].w,&a[i].mon);
        for (i=0;i<3000;i++) dp[i]=0;
        for (j=0;j<n;j++)
        {
            for (i=m;i>=0;i--)
            {
                if (i>=a[j].w)
                {
                    dp[i]=max(dp[i],dp[i-a[j].w]+a[j].mon);
                }
            }
        }
        printf("%lld\n",dp[m]);
    }
    return 0;
}
