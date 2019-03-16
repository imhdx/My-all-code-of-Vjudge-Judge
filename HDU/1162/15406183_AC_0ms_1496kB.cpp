#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;
int pre[103];
struct point
{
    double x;
    double y;
} p[102];
struct node
{
    int x,y;
    double l;
} que[10100];
int getx(int x)
{
    if (pre[x]==x)
        return x;
    return pre[x]=getx(pre[x]);
}
bool cmp(struct node q,struct node p)
{
    return q.l<p.l;
}
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        int i,j;
        for (i=0; i<=n; i++)
            pre[i]=i;
        for (i=0; i<n; i++)
        {
            scanf("%lf%lf",&p[i].x,&p[i].y);
        }
        int cnt=0;
        for (i=0; i<n; i++)
        {
            for (j=i+1; j<n; j++)
            {
                que[cnt].x=i;
                que[cnt].y=j;
                que[cnt].l=sqrt((p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y));
                cnt++;
            }
        }
        double ans=0;
        sort(que,que+cnt,cmp);
        for (i=0; i<cnt; i++)
        {
            int xx=getx(que[i].x);
            int yy=getx(que[i].y);
            if (xx!=yy)
            {
                pre[min(xx,yy)]=max(xx,yy);
                ans+=que[i].l;
            }
        }
        printf("%.2f\n",ans);
    }

    return 0;
}
