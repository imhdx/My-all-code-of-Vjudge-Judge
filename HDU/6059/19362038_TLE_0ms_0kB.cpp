#include<bits/stdc++.h>
using namespace std;
int a[500005];
const int maxn=31*(5e5+10);
int t[maxn][2];
int cnt[maxn][2];
int sz[maxn];
int ext[maxn];
int tot;
void init()
{
    tot=0;
    memset(cnt,0,sizeof(cnt));
    memset(t,0,sizeof(t));
    memset(sz,0,sizeof(sz));
    memset(ext,0,sizeof(ext));
}
long long insert(int x)
{
    long long ans=0;
    int root=0;
    for (int i=31;i>=0;i--)
    {
        int k=(x>>i)&1;
        if (t[root][k]==0) t[root][k]=++tot;
        cnt[i][k]++;
        if (t[root][1-k])
        {
            int now=t[root][1-k];
            ans+=1ll*sz[now]*(sz[now]-1)/2;
            ans+=1ll*(cnt[i][1-k]-sz[now])*sz[now]-ext[now];
        }
        root=t[root][k];
        sz[root]++;
        ext[root]+=cnt[i][k]-sz[root];
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
