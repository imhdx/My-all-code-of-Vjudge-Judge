///POJ-2420
///求一个点，使得这个点到n个点的距离之和最小
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<algorithm>
using namespace std;
const double esp=1e-3;
const double pi=atan(1.0)*4;
int n;
/// mt19937 rng((unsigned long long)new char);
double myrand()
{
    return 1.0*(rand()%1000)/1000;
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
    //srand(time(0));
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
        double tmp=1e18;
        double tmpx;
        double tmpy;
        for (int i=0;i<50;i++)
        {
            double a=myrand()*2*pi;
            double tx=xx+t*cos(a);
            double ty=yy+t*sin(a);
            double sum=getsum(tx,ty);
            if (tmp>sum)
            {
                tmp=sum;
                tmpx=tx;
                tmpy=ty;
            };
        }
        double sub=ans-tmp;
        if (sub>=0||exp(-sub/t)>=myrand())
        {
            ans=tmp;
            xx=tmpx;
            yy=tmpy;
        }
        t*=0.99;
    }
    printf("%.0f\n",ans);
    return 0;
}