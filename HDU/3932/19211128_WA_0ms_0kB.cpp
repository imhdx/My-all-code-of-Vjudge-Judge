#include<bits/stdc++.h>
using namespace std;
struct node
{
    double x,y;
    double s;
}p[1003],tmp[12];
double dis(node q,node p)
{
    return sqrt((q.x-p.x)*(q.x-p.x)+(q.y-p.y)*(q.y-p.y));
}
double rng()
{
    return (1.0*rand()+1.0)/RAND_MAX;
}
int main()
{
    double maxx,maxy;
    int n;
    while (scanf("%lf%lf%d",&maxx,&maxy,&n)!=EOF)
    {
        double sumx=0,sumy=0;
        for (int i=0;i<n;i++)
        {
             scanf("%lf%lf",&p[i].x,&p[i].y);
             sumx+=p[i].x;
             sumy+=p[i].y;
        }
        sumx/=n;
        sumy/=n;
        int cc=10;
        tmp[0].x=sumx;
        tmp[0].y=sumy;
        tmp[0].s=0;
        for (int i=1;i<10;i++)
        {
            tmp[i].x=rng()*maxx;
            tmp[i].y=rng()*maxy;
            tmp[i].s=0;
        }
        for (int i=0;i<10;i++)
        {
            for (int j=0;j<n;j++)
            {
                tmp[i].s=max(tmp[i].s,dis(p[j],tmp[i]));
            }
        }
        double t=10000;
        while (t>0.001)
        {
            for (int j=0;j<10;j++)
            {
                double dd=0;
                int s=-1;
                for (int i=0;i<n;i++)
                {
                    if (dis(tmp[j],p[i])>dd)
                    {
                        dd=dis(tmp[j],p[i]);
                        s=i;
                    }
                }
                if (s!=-1)
                {
                    if (tmp[j].s>dd)
                    {
                        tmp[j].s=dd;
                        tmp[j].x=(p[s].x-tmp[j].x)/dd*t;
                        tmp[j].y=(p[s].y-tmp[j].y)/dd*t;
                    }
                }
            }
            t*=0.99;
        }
        double xx=0,yy=0,ans=1e30;
        for (int i=0;i<10;i++)
        {
            if (tmp[i].s<ans)
            {
                ans=tmp[i].s;
                xx=tmp[i].x;
                yy=tmp[i].y;
            }
        }
        printf("(%.1f,%.1f).\n",xx,yy);
        printf("%.1f\n",ans);
    }
    return 0;
}
