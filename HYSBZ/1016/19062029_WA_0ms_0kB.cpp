#include<bits/stdc++.h>
using namespace std;
const int mod=31011;
int n,m;
int pre[110];
int getx(int x){if (pre[x]==x) return x;return getx(pre[x]);}
///不能用压缩路径，否则无法还原
struct Edge
{
    int u,v;
    long long w;
}edge[1010];
bool cmp(Edge q,Edge p)
{
    return q.w<p.w;
}
struct data
{
    int l,r,s;
    ///l该块的起点
    ///r该块的终点
    ///s为该块应该贡献多少边
}a[1010];
long long tmp=0;
void dfs(int x,int now,int k)
/// x为进行到第几块
/// now为在块中哪一个
/// k为该块应该又几条边相连
{
    if (now==a[x].r+1)
    {
        if (k==a[x].s) tmp++;
        return ;
    }
    int xx=getx(edge[now].u);
    int yy=getx(edge[now].v);
    if (xx!=yy)
    {
        pre[xx]=yy;
        dfs(x,now+1,k+1);
        pre[xx]=xx;
        pre[yy]=yy;
    }
    dfs(x,now+1,k);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=0;i<=n;i++) pre[i]=i;
    for (int i=0;i<m;i++)
    {
        scanf("%d%d%lld",&edge[i].u,&edge[i].v,&edge[i].w);
    }
    sort(edge,edge+m,cmp);
    int j;
    int cnt=0;
    for (int i=0;i<m;i=j)
    {
        j=i;
        a[cnt].l=i;
        int cc=0;
        while (edge[i].w==edge[j].w)
        {
            int xx=getx(edge[j].u);
            int yy=getx(edge[j].v);
            if (xx!=yy)
            {
                pre[xx]=yy;
                cc++;
            }
            j++;
        }
        a[cnt].r=j-1;
        a[cnt].s=cc;
        cnt++;
    }
    for (int i=0;i<=n;i++) pre[i]=i;
    //for (int i=0;i<cnt;i++) printf("%d %d %d\n",a[i].l,a[i].r,a[i].s);
    long long ans=1;
    for (int i=0;i<cnt;i++)
    {
        tmp=0;
        dfs(i,a[i].l,0);
        //printf("%lld\n",tmp);
        ans*=tmp;
        ans%=mod;
        for (int j=a[i].l;j<=a[i].r;j++)
        {
            int xx=getx(edge[j].u);
            int yy=getx(edge[j].v);
            if (xx!=yy) pre[xx]=yy;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
