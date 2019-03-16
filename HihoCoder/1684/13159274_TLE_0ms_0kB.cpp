#include<stdio.h>
int main()
{
    int i,j,m,max,n,k;
    int a[200000],dp[200000];
    while (scanf("%d",&n)!=EOF)
    {
        for (i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for (i=1;i<=n;i++) dp[i]=1;
        for (i=2;i<=n;i++)
        {
            max=0;
            for (j=1;j<i;j++)
            {
                if (a[j]>=a[i])
                {
                    if (max<dp[j])
                        max=dp[j];
                }
            }
            dp[i]=max+1;
        }
        max=0;
        for (i=1;i<=n;i++)
        {
            if (max<dp[i]) max=dp[i];
        }
        printf("%d\n",n-max);
    }
    return 0;
}
