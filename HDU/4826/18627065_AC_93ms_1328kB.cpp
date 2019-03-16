#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int a[102][102];
int s[102][102];
int dp[102][102];
int read()
{
    int f=1,x=0;
    char c=getchar();
    while (c<'0'||c>'9'){
        if (c=='-') f=-1;
        c=getchar();
    }
    while (c>='0'&&c<='9')
    {
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}
int main()
{
    int tt=1;
    int T;T=read();
    while (T--)
    {
        int n,m;
        n=read();m=read();
        for (int i=0;i<=n;i++) for (int j=0;j<=m;j++) dp[i][j]=-1000010;
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++) a[i][j]=read();
        }
        for (int j=1;j<=m;j++)
        {
            s[0][j]=0;
            for (int i=1;i<=n;i++)
                s[i][j]=s[i-1][j]+a[i][j];
        }
        for (int i=1;i<=n;i++) dp[i][1]=s[i][1];
        for (int j=2;j<=m;j++)
        {
            for (int i=1;i<=n;i++)
            {
                for (int k=1;k<=n;k++)
                {
                    dp[i][j]=max(dp[i][j],dp[k][j-1]+s[max(i,k)][j]-s[min(i,k)-1][j]);
                }
            }
        }
        printf("Case #%d:\n",tt++);
        printf("%d\n",dp[1][m]);
    }
    return 0;
}
