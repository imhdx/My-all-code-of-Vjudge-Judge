#include<bits/stdc++.h>
using namespace std;
struct note
{
    int cost;
    int in;
}que[12];
int dp[1050*40];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        memset(dp,0,sizeof(dp));
        int n,t;
        scanf("%d%d",&n,&t);
        int m;
        scanf("%d",&m);
        int i,j;
        for (i=1;i<=m;i++)
        {
            scanf("%d%d",&que[i].cost,&que[i].in);
            que[i].cost=que[i].cost/1000;
        }
        while (t--)
        {
            int s=n/1000;
 memset(dp,0,sizeof(dp));
            for (i=1;i<=m;i++)
            {
                for (j=que[i].cost;j<=s;j++)
                {
                    dp[j]=max(dp[j],dp[j-que[i].cost]+que[i].in);
                }
            }
            n+=dp[s];
        }
        printf("%d\n",n);
    }
    return 0;
}
