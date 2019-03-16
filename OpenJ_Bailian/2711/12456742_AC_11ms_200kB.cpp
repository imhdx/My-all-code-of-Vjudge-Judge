#include<stdio.h>
int main()
{
    int i,j,m,max,min,n,k;
    int a[105],dp[105];
    while (scanf("%d",&n)!=EOF)
    {
        min=999999;
        for (i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for (k=1;k<=n;k++)
        {
            for (i=1;i<=k;i++) dp[i]=1;
            for (i=2;i<=k;i++)
            {
                max=0;
                for (j=1;j<i;j++)
                {
                    if (a[j]<a[i])
                    {
                        if (max<dp[j])
                            max=dp[j];
                    }
                }
                dp[i]=max+1;
            }
            m=k-dp[k];
            for (i=k;i<=n;i++) dp[i]=1;
            for (i=n-1;i>=k;i--)
            {
                max=0;
                for (j=n;j>i;j--)
                {
                    if (a[j]<a[i])
                    {
                        if (max<dp[j])
                            max=dp[j];
                    }
                }
                dp[i]=max+1;
            }
            m=m+n-k+1-dp[k];

            if (min>m) min=m;
        }
        printf("%d\n",min);
    }
    return 0;
}
