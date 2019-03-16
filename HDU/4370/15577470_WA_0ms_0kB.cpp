#include<bits/stdc++.h>
using namespace std;
long long int a[320][320];
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        int i,j;
        for (i=1;i<=n;i++)
        {
            for (j=1;j<=n;j++)
            {
                scanf("%lld",&a[i][j]);
            }
        }
        long long int minn=a[1][n];
        for (i=2;i<=n-1;i++)
        {
            minn=min(minn,a[1][i]+a[i][n]);
        }
        printf("%lld\n",minn);
    }
    return 0;
}
