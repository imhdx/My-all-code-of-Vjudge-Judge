#include<stdio.h>
long long int max(long long int qq,long long int pp)
{
    if (qq<pp) return pp;
    return qq;
}
struct note
{
    long long int w;
    long long int mon;
}a[600];
long long int mon[300000];
int main()
{
    long long int n,m;
    while (scanf("%lld%lld",&n,&m)!=EOF)
    {
        int i,j;
        for (i=0;i<n;i++)
            scanf("%lld%lld",&a[i].w,&a[i].mon);
        for (i=0;i<=m;i++) mon[i]=0;
        for (j=1;j<=m;j++)
        {
            for (i=0;i<n;i++)
            {
                if (j>=a[i].w)
                {
                    mon[j]=max(mon[j],a[i].mon+mon[j-a[i].w]);
                }
            }
        }
        printf("%lld\n",mon[m]);
    }
    return 0;
}
