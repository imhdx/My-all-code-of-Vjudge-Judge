#include<bits/stdc++.h>
using namespace std;
int a[900];
int dp[900];
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for (int j=0;j<n;j++)
        {
            a[n+j]=a[j];
        }
        int t=0;
        dp[0]=0;
        for (int i=1;i<2*n;i++)
        {
            if (a[i]>a[i-1]) dp[i]=dp[i-1]+1;
            else
                dp[i]=0;
            t=max(t,dp[i]);
        }
        dp[0]=0;
        for (int i=1;i<2*n;i++)
        {
            if (a[i]<a[i-1]) dp[i]=dp[i-1]+1;
            else
                dp[i]=0;
            t=max(t,dp[i]);
        }
        printf("%d\n",t);
    }

    return 0;
}
