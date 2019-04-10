///POJ-2420
///求一个点，使得这个点到n个点的距离之和最小
#include<bits/stdc++.h>
using namespace std;
const double esp=1e-3;
const double pi=atan(1.0)*4;
int n;
/// mt19937 rng((unsigned long long)new char);
double myrand()
{
    return (rand() % 1000 + 1) / 1000.0;
}
double x[10003];
double y[10003];
double w[10003];
double getsum(double xx,double yy)
{
    double ans=0;
    for (int i=0;i<n;i++)
    {
        ans+=w[i]*sqrt((x[i]-xx)*(x[i]-xx)+(y[i]-yy)*(y[i]-yy));
    }
    return ans;
}
int main()
{
srand(0);
    scanf("%d",&n);
    double xx=0,yy=0;
    for (int i=0;i<n;i++)
    {
        scanf("%lf%lf%lf",&x[i],&y[i],&w[i]);
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
        double sum=getsum(tx,ty);
        double sub=ans-sum;
        if (sub>=0||exp(sub/t)>=myrand())
        {
            ans=sum;
            xx=tx;
            yy=ty;
        }
        t*=0.99;
    }
    for (int i=0;i<10000;i++)
    {
        double a=myrand()*2*pi;
        double tx=xx+t*cos(a);
        double ty=yy+t*sin(a);
        double sum=getsum(tx,ty);
        if (sum<ans)
        {
            ans=sum;
            xx=tx;
            yy=ty;
        }
    }
    printf("%.3f %.3f\n",xx,yy);
    return 0;
}
