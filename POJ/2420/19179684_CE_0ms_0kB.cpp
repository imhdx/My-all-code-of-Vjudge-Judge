///POJ-2420
///求一个点，使得这个点到n个点的距离之和最小
#include<bits/stdc++.h>
using namespace std;
const double esp=1e-3;
const double pi=atan(1.0)*4;
int n;
mt19937 rng((unsigned long long)new char);
double myrand()
{
    return 1.0*rng()/INT_MAX;
}
double x[103];
double y[103];
double getsum(double xx,double yy)
{
    double ans=0;
    for (int i=0;i<n;i++)
    {
        ans+=sqrt((x[i]-xx)*(x[i]-xx)+(y[i]-yy)*(y[i]-yy));
    }
    return ans;
}
int main()
{
    scanf("%d",&n);
    double xx=0,yy=0;
    for (int i=0;i<n;i++)
    {
        scanf("%lf%lf",&x[i],&y[i]);
        xx+=x[i];
        yy+=y[i];
    }
    xx/=n;
    yy/=n;
    //printf("%.10f %.10f\n",xx,yy);
    double ans=getsum(xx,yy);

    double tmp;
    double t=100000;
    while (t>esp)
    {
        double a=myrand()*2*pi;
        double tx=xx+t*cos(a);
        double ty=yy+t*sin(a);
        double sub=ans-getsum(tx,ty);
        if (sub>=0||exp(sub/t)>=myrand())
        {
            ans=getsum(tx,ty);
            xx=tx;
            yy=ty;
        }
        t*=0.99;
    }
    printf("%.0f\n",ans);
    return 0;
}
