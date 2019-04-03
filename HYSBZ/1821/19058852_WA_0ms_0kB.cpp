#include<bits/stdc++.h>
using namespace std;
int pre[1010];
int getx(int x)
{
    if (pre[x]==x) return x;
    return pre[x];
}
struct ac
{
    int x,y;
    double w;
}edge[1000010];
bool cmp(ac q,ac p)
{
    return q.w<p.w;
}
int x[1010];
int y[1010];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for (int i=0;i<=n;i++) pre[i]=i;
    for (int i=0;i<n;i++)
    {
        scanf("%d%d",&x[i],&y[i]);
    }
    int cnt=0;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (i!=j)
            {
                edge[cnt++]=ac{i,j,sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]))};
            }
        }
    }
    sort(edge,edge+cnt,cmp);
    for (int i=0;i<cnt;i++)
    {
        int xx=getx(edge[i].x);
        int yy=getx(edge[i].y);
        if (xx!=yy)
        {
            if (n>k)
            {
                n--;
                pre[xx]=yy;
            }
            else{printf("%.2f\n",edge[i].w);return 0;}
        }
    }
    return 0;
}
