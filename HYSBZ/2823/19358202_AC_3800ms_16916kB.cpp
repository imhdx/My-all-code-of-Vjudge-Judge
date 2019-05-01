#include<bits/stdc++.h>
using namespace std;
struct P
{
    double x,y;
}p[1000006];
const double esp=1e-6;
double dis(P a,P b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
bool cmp(double a,double b)
{
    return fabs(a-b)<esp;
}
P geto(P a,P b,P c)///由三点的外接圆圆心
{
    double a1,a2,b1,b2,c1,c2;
    P ans;
    a1=2*(b.x-a.x);
    b1=2*(b.y-a.y);
    c1=b.x*b.x-a.x*a.x+b.y*b.y-a.y*a.y;
    a2=2*(c.x-a.x);
    b2=2*(c.y-a.y);
    c2=c.x*c.x-a.x*a.x+c.y*c.y-a.y*a.y;
    if (cmp(a1,0))
    {
        ans.y=c1/b1;
        ans.x=(c2-ans.y*b2)/a2;
    }
    else if (cmp(b1,0))
    {
        ans.x=c1/a1;
        ans.y=(c2-ans.x*a2)/b2;
    }
    else
    {
        ans.x=(c2*b1-c1*b2)/(a2*b1-a1*b2);
        ans.y=(c2*a1-c1*a2)/(b2*a1-b1*a2);
    }
    return ans;
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%lf%lf",&p[i].x,&p[i].y);
    for (int i=1;i<=n;i++) swap(p[i],p[rand()%n+1]);
    P o=p[1];
    double r=0;
    for (int i=1;i<=n;i++)
    {
        if (dis(p[i],o)<=r+esp) continue;
        o.x=(p[i].x+p[1].x)/2;
        o.y=(p[i].y+p[1].y)/2;
        r=dis(p[i],p[1])/2;
        for (int j=2;j<i;j++)
        {
            if (dis(o,p[j])<=r+esp) continue;
            o.x=(p[i].x+p[j].x)/2;
            o.y=(p[i].y+p[j].y)/2;
            r=dis(p[i],p[j])/2;
            for (int k=1;k<j;k++)
            {
                if (dis(o,p[k])<=r+esp) continue;
                o=geto(p[i],p[j],p[k]);
                r=dis(o,p[i]);
            }
        }
    }
    printf("%.2f %.2f %.2f\n",o.x,o.y,r);
    return 0;
}
