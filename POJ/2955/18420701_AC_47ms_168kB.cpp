#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
string str;
int a[103];
int dp[103][103];
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    while (cin>>str&&str!="end")
    {
        for (int i=0;str[i];i++)
            if (str[i]=='(') a[i+1]=1;
            else if (str[i]==')') a[i+1]=-1;
            else if (str[i]=='[') a[i+1]=2;
            else if (str[i]==']') a[i+1]=-2;
            else if (str[i]=='{') a[i+1]=3;
            else if (str[i]=='}') a[i+1]=-3;
        int n=str.size();
        memset(dp,0,sizeof(dp));
        for (int len=2;len<=n;len++)
        {
            for (int i=1;i+len-1<=n;i++)
            {
                int j=i+len-1;
                if (a[i]+a[j]==0&&a[i]>0)
                    dp[i][j]=dp[i+1][j-1]+2;
                else dp[i][j]=max(dp[i+1][j],dp[i][j-1]);

                for (int k=i;k<j;k++)
                    dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]);

            }
        }

        printf("%d\n",dp[1][n]);
    }
    return 0*1;
}
