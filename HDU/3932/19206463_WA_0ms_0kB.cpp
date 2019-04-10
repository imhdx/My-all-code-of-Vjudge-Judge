#include<bits/stdc++.h>
using namespace std;
double x[100010];
double y[100010];
double rng()
{
    return 1.0*rand()/RAND_MAX;
}
int main()
{
    int n;
    double maxx,maxy;
    while (scanf("%lf%lf",&maxx,&maxy)!=EOF){
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%lf%lf",&x[i],&y[i]);
    double xx=0;
    double yy=0;
    double ans=1e30;
    double t=10000;
    double pi=4.0*atan(1.0);
    //printf("%.10f\n",pi);

    while (t>0.001)
    {
        double a=2*pi*rng();
        //printf("a=%.10f\n",a);
        double tx=xx+t*sin(a);
        double ty=yy+t*cos(a);
        //printf("%.10f %.10f\n",tx,ty);
        if (tx<0||tx>maxx||ty<0||ty>maxy)
        {
            t*=0.999;
            continue;
        }
        double tmp=0;
        for (int i=0;i<n;i++)
        {
            tmp=max(tmp,sqrt((x[i]-tx)*(x[i]-tx)+(y[i]-ty)*(y[i]-ty)));
        }
        if (tmp<=ans)
        {
            //printf("%.10f %.10f\n",tx,ty);
            ans=tmp;
            xx=tx;
            yy=ty;
        }
        t*=0.99;
    }
    printf("(%.1f,%.1f).\n",xx,yy);
    printf("%.1f\n",ans);
    }
    return 0;
}
