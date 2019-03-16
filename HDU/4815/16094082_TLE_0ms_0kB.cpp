#include<bits/stdc++.h>
using namespace std;
int a[50];
int dp[5020];
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
        sort(a,a+n);
        dp[0]=1;
        for (int i=0;i<n;i++)
        {
            for (int j=s;j>=a[i];j--)
            {
                dp[j]+=dp[j-a[i]];
            }
        }
        int ss=0;
        int kk=p*(1<<n);
        for (int i=0;i<5020;i++)
        {
            ss+=dp[i];
            if (ss>=kk)
            {
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}
