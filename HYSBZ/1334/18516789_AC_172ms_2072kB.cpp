#include<bits/stdc++.h>
using namespace std;
int a[100005];
bool cmp(int q,int p){return q>p;}
int dp[100010];
int main()
{
    int sum=0;
    int n;scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&a[i]),sum+=a[i];
    sort(a,a+n,cmp);
    dp[0]=1;
    int ans=0;
    for (int i=0;i<n;i++){
        for (int j=sum/2+a[i];j>=a[i];j--)
            if (dp[j-a[i]]){
                dp[j]=1;
                ans=max(j,ans);
            }
    }
    printf("%d\n",ans);
    return 0;
}
