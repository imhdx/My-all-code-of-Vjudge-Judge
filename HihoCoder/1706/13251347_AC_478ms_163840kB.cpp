#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int a2[200];
int a5[200];
int dp[200][200][1000];
int main()
{
    int n,m;
    int i,j,k;
    int x,y;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        int sum=0;
        memset(a2,0,200*sizeof(int));
        memset(a5,0,200*sizeof(int));
        for (i=1;i<=n;i++)
        {
            scanf("%d",&x);
            y=x;
            while (x!=0)
            {
                if (x%2==0)
                {
                    a2[i]++;
                    x=x/2;
                }
                else
                    break;
            }
            while (y!=0)
            {
                if (y%5==0)
                {
                    sum++;
                    a5[i]++;
                    y=y/5;
                }
                else
                    break;
            }
        }
        memset(dp,-9999999,200*200*1000*sizeof(int));
        dp[0][0][0]=0;
        for (i=1;i<=n;i++)
        {
            for (j=0;j<=min(i,m);j++)
            {
                for (k=0;k<=sum;k++)
                {
                    dp[i][j][k]=dp[i-1][j][k];
                    if (i-1>=0&&j-1>=0&&k-a5[i]>=0) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k-a5[i]]+a2[i]);
                }
            }
        }
        int maxx=0;
        for (i=0;i<=sum;i++)
        {
            maxx=max(maxx,min(dp[n][m][i],i));
        }
        printf("%d\n",maxx);

    }
    return 0;
}
