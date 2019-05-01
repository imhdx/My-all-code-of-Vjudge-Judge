#include<bits/stdc++.h>
using namespace std;
int a[500005];
const int maxn=31*(5e5+10);
int t[maxn][2];
int cnt[maxn][2];
int tot;
void init()
{
    tot=0;
    memset(cnt,0,sizeof(cnt));
    memset(t,0,sizeof(t));
}
long long insert(int x)
{
    long long ans=0;
    int root=0;
    for (int i=31;i>=0;i--)
    {
        int k=(x>>i)&1;
        if (t[root][k]==0)
        {
            t[root][k]=++tot;
        }
        cnt[root][k]++;
        ans+=1ll*cnt[root][1-k]*(cnt[root][1-k]-1)/2;
        root=t[root][k];
    }
    return ans;
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        init();
        scanf("%d",&n);
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        long long ans=0;
        for (int i=1;i<=n;i++)
        {
            long long tmp=insert(a[i]);
            ans+=tmp;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
