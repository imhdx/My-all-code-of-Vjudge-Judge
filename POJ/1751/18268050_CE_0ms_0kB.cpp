#include<bits/stdc++.h>
using namespace std;
struct ac
{
    int x,y;
    long long w;
}q[562510];
bool cmp(ac q,ac p)
{
    return q.w<p.w;
}
int pre[760];
int getx(int x)
{
    if (pre[x]==x) return x;
    return pre[x]=getx(pre[x]);
}
int x[760];
int y[760];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
    int cnt=0;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (i==j) continue;
            q[cnt].x=i;
            q[cnt].y=j;
            q[cnt++].w=1ll*(x[i]-x[j])*(x[i]-x[j])+1ll*(y[i]-y[j])*(y[i]-y[j]);
        }
    }
    sort(q,q+cnt,cmp);
    int m;
    scanf("%d",&m);
    for (int i=0;i<=n;i++) pre[i]=i;
    for (int i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        int xx=getx(x);
        int yy=getx(y);
        if (xx!=yy) pre[xx]=yy;
    }
    for (int i=0;i<cnt;i++)
    {
        int xx=getx(q[i].x);
        int yy=getx(q[i].y);
        if (xx!=yy)
        {
            printf("%d %d\n",q[i].x,q[i].y);
            pre[xx]=yy;
        }
    }
    return 0;
}
