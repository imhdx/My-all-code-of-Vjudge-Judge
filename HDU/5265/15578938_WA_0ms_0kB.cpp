#include<cstdio>
#include<algorithm>
using namespace std;
int a[100010];
int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        int i,j;
        for (i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            a[i]=a[i]%m;
        }
        sort(a,a+n);
        int ans=(a[n-1]+a[n-2])%m;
        j=n-2;
        for (i=n-1;i>=1;i--)
        {
            while (j>=0&&a[j]+a[i]>=m)
            {
                j--;
            }
            if (j>=0) ans=max(ans,(a[j]+a[i])%m);
        }
        printf("%d\n",ans);
    }
    return 0;
}
