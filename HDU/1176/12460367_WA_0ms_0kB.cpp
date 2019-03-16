#include<stdio.h>
int MAX,maxx=-1,j,x,t,i,n,dp[100008][12],a[100008][12];
int max(int a,int b)
{
    if (a<b) return b;
    return a;
}
int main()
{
    while (scanf("%d",&n)!=EOF&&n!=0)
    {
        MAX=-1;
        maxx=-1;
        for (i=0;i<100008;i++)
            for (j=0;j<12;j++)
            dp[i][j]=0;
        for (i=0;i<n;i++)
        {
            scanf("%d%d",&x,&t);
            if (maxx<t) maxx=t;
            a[t][x]=a[t][x]+1;
        }
        dp[1][4]=a[1][4];
        dp[1][5]=a[1][5];
        dp[1][6]=a[1][6];
        for (t=2;t<=maxx;t++)
        {
            for (x=0;x<=10;x++)
            {
                if (x==0)
                    dp[t][x]=max(dp[t-1][x],dp[t-1][x+1])+a[t][x];
                else if (x==10)
                    dp[t][x]=max(dp[t-1][x],dp[t-1][x-1])+a[t][x];
                else
                    dp[t][x]=max(max(dp[t-1][x],dp[t-1][x-1]),dp[t-1][x+1])+a[t][x];
                if (MAX<dp[t][x]) MAX=dp[t][x];
            }
        }
        printf("%d\n",MAX);
    }
    return 0;
}
