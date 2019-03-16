#include<bits/stdc++.h>
using namespace std;
int dp[1010][1010];
int main()
{
    int n,k;scanf("%d%d",&n,&k);
    dp[1][0]=1;for (int i=1;i<=k;i++) dp[1][k]=0;
    for (int i=2;i<=n;i++){
        for (int j=0;j<=k;j++){
            for (int p=0;p<i&&j-p>=0;p++){
                dp[i][j]=dp[i][j]+dp[i-1][j-p];
                if (dp[i][j]>=10000) dp[i][j]-=10000;
            }
        }
    }
    printf("%d\n",dp[n][k]);
    return 0;
}
