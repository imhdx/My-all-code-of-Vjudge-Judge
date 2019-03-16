#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
int dp[25][16000];
int c[25],w[25];
int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        for (int i=1;i<=n;i++) scanf("%d",&c[i]);
        for (int i=1;i<=m;i++) scanf("%d",&w[i]);
        memset(dp,0,sizeof(dp));
        dp[0][7500]=1;
        for (int i=1;i<=m;i++)
        {
            for (int j=1;j<=n;j++)
            {
                for (int k=0;k<16000;k++)
                dp[i][k+w[i]*c[j]]+=dp[i-1][k];
            }
        }
        printf("%d\n",dp[m][7500]);
    }

    return 0;
}
