#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;
vector<pair<int,int> > v;
int b[500010];
int dp[500010];
int main()
{
    int t=1;
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        int i;
        v.clear();
        for (i=0;i<n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            v.push_back({x,y});
            b[i+1]=0;
            dp[i+1]=0;
        }
        sort(v.begin(),v.end());
        int minn=v[0].second;
        int maxx=v[0].second;
        dp[v[0].second]=1;
        int ans=1;
        for (i=0;i<n;i++)
        {
            if (v[i].second>maxx)
            {
                maxx=v[i].second;
            }
            if (v[i].second<minn)
            {
                minn=v[i].second;
                dp[v[i].second]=1;
            }
            else
                for (int j=minn;j<v[i].second;j++)
                    dp[v[i].second]=max(dp[v[i].second],dp[j]+1);
            ans=max(ans,dp[v[i].second]);
        }


        printf("Case %d:\n",t++);
        printf("My king, at most %d road can be built.\n\n",ans);
    }

    return 0;
}
