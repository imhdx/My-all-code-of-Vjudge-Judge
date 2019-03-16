#include<cstdio>
#include<algorithm>
using namespace std;
long long int a[100010];
int main()
{
    int n;
    long long m;
    while (scanf("%d%lld",&n,&m)!=EOF)
    {
        int i,j;
        for (i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
            a[i]=a[i]%m;
        }
        sort(a,a+n);
        long long int ans=(a[n-1]+a[n-2])%m;
        j=n-1;
        for (i=0;i<n;i++)
        {
            while (i<j&&a[j]+a[i]>=m)
            {
                j--;
            }
            if (i<j) ans=max(ans,(a[j]+a[i])%m);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
