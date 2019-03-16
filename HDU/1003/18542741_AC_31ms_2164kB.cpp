#include<bits/stdc++.h>
using namespace std;
int dp[100010];
int a[100010];
const int INF=1e9+7;
int main()
{
    int t=1;
    int T;scanf("%d",&T);
    while (T--){
        int n;scanf("%d",&n);
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        for (int i=0;i<=n;i++) dp[i]=-INF;
        int st=1,la=1;
        int s=1;
        int maxx=-INF;
        for (int i=1;i<=n;i++){
            dp[i]=max(dp[i-1]+a[i],a[i]);
            if (dp[i-1]+a[i]<a[i]) s=i;
            if (dp[i]>maxx){
                maxx=dp[i];
                la=i;
                st=s;
            }
        }
        printf("Case %d:\n",t++);
        printf("%d %d %d\n",maxx,st,la);
        if (T) printf("\n");
    }
    return 0;
}
