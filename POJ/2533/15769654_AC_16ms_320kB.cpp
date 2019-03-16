#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int a[1010];
int dp[1010];
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=0;i<n;i++) dp[i]=1;
        int ans=0;
        for (int i=0;i<n;i++) scanf("%d",&a[i]);
        for (int i=0;i<n;i++)
        {
            int maxx=0;
            for (int j=0;j<i;j++)
            {
                if (a[j]<a[i])
                {
                    maxx=max(dp[j],maxx);
                }
            }
            dp[i]+=maxx;
            ans=max(ans,dp[i]);
        }
        printf("%d\n",ans);

    }

    return 0;
}
