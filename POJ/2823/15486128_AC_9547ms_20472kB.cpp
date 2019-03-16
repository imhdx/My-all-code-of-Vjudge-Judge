#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1000010;
int tMAX[MAXN<<2];
int tMIN[MAXN<<2];
int a[MAXN];
void build(int l,int r,int rt)
{
    if (l==r)
    {
        tMAX[rt]=tMIN[rt]=a[l];
        return ;
    }
    int mid=l+r>>1;
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
    tMAX[rt]=max(tMAX[rt<<1],tMAX[rt<<1|1]);
    tMIN[rt]=min(tMIN[rt<<1],tMIN[rt<<1|1]);
}
int askMIN(int l,int r,int ll,int rr,int rt)
{
    if (ll<=l&&r<=rr)
    {
        return tMIN[rt];
    }
    int mid=l+r>>1;
    int ans=(int)2e9;
    if (ll<=mid) ans=min(ans,askMIN(l,mid,ll,rr,rt<<1));
    if (rr>mid) ans=min(ans,askMIN(mid+1,r,ll,rr,rt<<1|1));
    return ans;
}
int askMAX(int l,int r,int ll,int rr,int rt)
{
    if (ll<=l&&r<=rr)
    {
        return tMAX[rt];
    }
    int mid=l+r>>1;
    int ans=-(int)2e9;
    if (ll<=mid) ans=max(ans,askMAX(l,mid,ll,rr,rt<<1));
    if (rr>mid) ans=max(ans,askMAX(mid+1,r,ll,rr,rt<<1|1));
    return ans;
}
int main()
{
    int k;
    int n;
    scanf("%d%d",&n,&k);
    int i,j;
    for (i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    build(1,n,1);
    if (k>=n)
    {
        printf("%d\n%d\n",askMIN(1,n,1,n,1),askMAX(1,n,1,n,1));
        return 0;
    }
    for (i=1;i+k-1<=n;i++)
    {
        printf("%d%c",askMIN(1,n,i,i+k-1,1)," \n"[i+k-1==n]);
    }
    for (i=1;i+k-1<=n;i++)
    {
        printf("%d%c",askMAX(1,n,i,i+k-1,1)," \n"[i+k-1==n]);
    }

    return 0;
}
