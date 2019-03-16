#include<bits/stdc++.h>
using namespace std;
int a[100010];
int vis[2][200010];
int main()
{
    int k;
    int n;scanf("%d",&n);
    scanf("%d",&k);
    int pos;
    for (int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if (a[i]==k) pos=i;
    }
    for (int i=1;i<=n;i++){
        if (a[i]==k) a[i]=0;
        else if (a[i]<k) a[i]=-1;
        else a[i]=1;
    }
    long long ans=0;
    int sum=0;
    vis[0][100000]=1;
    for (int i=1;i<pos;i++){
        sum+=a[i];
        vis[i&1][sum+100000]++;
    }
    for (int i=pos;i<=n;i++){
        sum+=a[i];
        ans+=vis[(i&1)^1][sum+100000];
        //vis[i&1][sum]++;
    }
    printf("%lld\n",ans);
    return 0;
}
