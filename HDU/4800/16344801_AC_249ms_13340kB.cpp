#include<bits/stdc++.h>
using namespace std;
double a[150][150];
double dp[10004][150];
int k[10004];
int main()
{
    int m;
    while (scanf("%d",&m)!=EOF)
    {
        int mm=m*(m-1)*(m-2)/6;
        for (int i=0; i<mm; i++)
        {
            for (int j=0; j<mm; j++)
                scanf("%lf",&a[i][j]);
        }
        int n;
        scanf("%d",&n);
        for (int i=0; i<n; i++)
            scanf("%d",&k[i]);
        //printf("123123\n");
        for (int i=0; i<mm; i++)
            dp[n-1][i]=a[i][k[n-1]];
        double maxx=-100;
        if (n==1)
        {

            for (int j=0;j<mm;j++)
                maxx=max(maxx,dp[0][j]);
        }
        else
        for (int i=n-2; i>=0; i--)
        {
            for (int j=0; j<mm; j++)
            {
                dp[i][j]=a[j][k[i]]*max(dp[i+1][j],dp[i+1][k[i]]);
                if (i==0)
                {
                    maxx=max(maxx,dp[i][j]);
                }
            }
        }
        printf("%.10f\n",maxx);
    }
    return 0;
}
