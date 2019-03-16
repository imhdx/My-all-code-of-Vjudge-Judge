#include<bits/stdc++.h>
using namespace std;
int dp[503][503];
int a[503];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) dp[i][j]=n,dp[i][i]=1;

    for (int len=2;len<=n;len++)
    {
        for (int i=1;i+len-1<=n;i++)
        {
            int j=i+len-1;
            if (a[i]==a[j])
            {
                if (len==2) dp[i][j]=1;
                else dp[i][j]=dp[i+1][j-1];
            }
            for (int k=i;k<j;k++)
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
        }
    }
    printf("%d\n",dp[1][n]);
    return 0;
}
