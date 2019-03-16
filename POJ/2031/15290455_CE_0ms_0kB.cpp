#include<bits/stdc++.h>
using namespace std;
struct note
{
    double x,y,z,r;
}a[110];
struct node
{
    int x,y;
    double len;
}que[12100];
double sqr(double a,double b)
{
    double ans=(a-b)*(a-b);
    return ans;
}
bool cmp(struct node q,struct node p)
{
    return q.len<p.len;
}
int pre[110];
int getx(int x)
{
    if (pre[x]==x) return x;
    return pre[x]=getx(pre[x]);
}
int main()
{
    int i;
    int n;
    while (scanf("%d",&n)!=EOF&&n)
    {
        for (i=0;i<=n;i++) pre[i]=i;
        int i,j;
        for (i=0;i<n;i++)
        {
            scanf("%lf%lf%lf%lf",&a[i].x,&a[i].y,&a[i].z,&a[i].r);
        }
        int cnt=0;
        for (i=0;i<n;i++)
        {
            for (j=i+1;j<n;j++)
            {
                if (sqr(a[i].x,a[j].x)+sqr(a[i].y,a[j].y)+sqr(a[i].z,a[j].z)<=sqr(a[i].r+a[j].r,0))
                {
                    int xx=getx(i);
                    int yy=getx(j);
                    pre[min(xx,yy)]=max(xx,yy);
                }
                else
                {
                    que[cnt].x=i;
                    que[cnt].y=j;
                    que[cnt].len=sqrt(sqr(a[i].x,a[j].x)+sqr(a[i].y,a[j].y)+sqr(a[i].z,a[j].z))-(a[i].r+a[j].r);
                    cnt++;
                }
            }
        }
        sort(que,que+cnt,cmp);
        double ans=0;
        for (i=0;i<cnt;i++)
        {
            int xx=getx(que[i].x);
            int yy=getx(que[i].y);
            if (xx!=yy)
            {
                pre[min(xx,yy)]=max(xx,yy);
                ans+=que[i].len;
            }
        }
        printf("%.3f\n",ans);

    }

    return 0;
}
