#include<bits/stdc++.h>
using namespace std;
const double esp=1e-7;
int x[1010];
int y[1010];
int n;
int pre[1010];
struct ac
{
    int x,y;
    double w;
}edge[1000010];
int cnt=0;
bool cmp(ac q,ac p)
{
    return q.w<p.w;
}
int getx(int x)
{
    if (pre[x]==x) return x;
    return pre[x];
}
int check(double mid)///返回 部落数
{
    //printf("%d\n",n);
    for (int i=0;i<=n;i++) pre[i]=i;
    int ans=n;
    for (int i=0;i<cnt;i++)
    {
        if (edge[i].w<=mid)
        {
            int xx=getx(edge[i].x);
            int yy=getx(edge[i].y);
            if (xx!=yy)
            {
                ans--;
                pre[xx]=yy;
            }
        }
    }
    return ans;
}
int main()
{
    int m;
    scanf("%d%d",&n,&m);
    int k=m;
    for (int i=0;i<n;i++)
    {
        scanf("%d%d",&x[i],&y[i]);
    }
    cnt=0;
    for (int i=0;i<n;i++)
    {
        for (int j=i+1;j<n;j++)
        {
            edge[cnt++]=ac{i,j,sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]))};
        }
    }
    sort(edge,edge+cnt,cmp);
    double l=0,r=1e9;
    double ans=-1;
    while (l<=r)
    {
        //printf("hi\n");
        double mid=(l+r)/2;
        if (check(mid)>=k)
        {
            ans=mid;
            l=mid+esp;
        }
        else r=mid-esp;
    }
    printf("%.2f\n",ans);
    return 0;
}
