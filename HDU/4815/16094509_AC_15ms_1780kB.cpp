#include<bits/stdc++.h>
using namespace std;
int a[55];
double dp[50200];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        memset(dp,0,sizeof(dp));
        int n;
        double p;
        scanf("%d%lf",&n,&p);
        int s=0;
        for (int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            s+=a[i];
        }
        dp[0]=1;
        for (int i=0;i<n;i++)
        {
            for (int j=s;j>=a[i];j--)
            {
                dp[j]+=dp[j-a[i]];
            }
        }
        double ss=0;
        for (int i=0;i<50200;i++)
        {
            ss+=(dp[i]/(1ll<<n));
            if (ss>=p)
            {
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}
