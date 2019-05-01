#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int st[maxn][20];
int lo[maxn];
int a[maxn];
void init()
{
    lo[1]=0;
    for (int i=2;i<maxn;i++) lo[i]=lo[i/2]+1;
}
int n;
void rmq()
{
    for (int i=1;i<=n;i++) st[i][0]=a[i];
    for (int j=1;j<20;j++)
    {
        for (int i=1;i+(1<<j)<n;i++)
        {
            st[i][j]=min(st[i][j-1],st[i+(1<<j-1)][j-1]);
        }
    }
}
int ask(int l,int r)
{
    int len=lo[r-l+1];
    return min(st[l][len],st[r-(1<<len)+1][len]);
}
int find(int ll,int rr)
{
    int l=ll;
    int r=rr;
    int ans=-1;
    while (l<=r)
    {
        int mid=l+r>>1;
        if (ask(ll,mid)<a[ll])
        {
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    return ans;
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        rmq();
        int m;
        scanf("%d",&m);
        while (m--)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            int ans=a[l];
            while (l<=r)
            {
                int pos=find(l,r);
                if (pos==-1) break;
                ans%=a[pos];
                l=pos;
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
