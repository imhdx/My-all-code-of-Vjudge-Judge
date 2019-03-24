#include<bits/stdc++.h>
using namespace std;
int dp[33][33];
void init()
{
    dp[0][0]=1;
    dp[1][0]=1;
    dp[1][1]=1;
    for (int i=2;i<33;i++)
    {
        for (int j=0;j<33;j++)
        {
            dp[i][j]+=dp[i-1][j];
            if (j-1>=0) dp[i][j]+=dp[i-1][j-1];
        }
    }
}
int digit[33];
int solve(int n,int k,int b)
{
    int len=0;
    while (n)
    {
        digit[len++]=n%b;
        n/=b;
    }
    //printf("%d\n",len);
    //for (int i=len-1;i>=0;i--) printf("%d ",digit[i]);
    int ans=0;
    int cnt=0;
    for (int i=len-1;i>=0;i--)
    {
        if (digit[i]>1)
        {
            if (k-cnt>=0) ans+=dp[i][k-cnt];
            if (k-cnt-1>=0) ans+=dp[i][k-cnt-1];
        }
        else if (digit[i]==1)
        {
            if (k-cnt>=0) ans+=dp[i][k-cnt];
        }
        if (digit[i]==1) cnt++;
    }
    return ans;
}
int main()
{
    init();
    int l,r,k,b;scanf("%d%d%d%d",&l,&r,&k,&b);
    printf("%d\n",solve(r+1,k,b)-solve(l,k,b));
    return 0;
}
