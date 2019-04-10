#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;
double esp=1e-3;
int n;
double x[1003];
double y[1003];
//mt19937 rng((unsigned long long)new char);
double myrand()
{
    //return 0.5*rng()/INT_MAX;
    return 1.0*rand()/RAND_MAX;
}
const double pi=4*atan(1.0);
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int maxx,maxy;
        scanf("%d%d%d",&maxx,&maxy,&n);
        //printf("%d %d %d \n",maxx,maxy,n);
        for (int i=0;i<n;i++) scanf("%lf%lf",&x[i],&y[i]);
        double xx=maxx/2.0;
        double yy=maxy/2.0;
        double t=2*sqrt(1.0*maxx*maxx+1.0*maxy*maxy);
        //double t=1000sqrt00;
        double ans=0;
        while (t>esp)
        {

            //printf("hi\n");
            double p=myrand();
            double a=2*pi*p;
            double tx=xx+1.5*t*p*p*sin(a);
            double ty=yy+1.5*t*p*p*cos(a);

            if (tx<0||tx>maxx||ty<0||ty>maxy) continue;
            //printf("hh= %.10f %.10f\n",tx,ty);
            double tmp=1e30;
            for (int i=0;i<n;i++)
            {
                tmp=min(tmp,sqrt((tx-x[i])*(tx-x[i])+(ty-y[i])*(ty-y[i])));
            }
            double sub=tmp-ans;
            if (sub>=0)
            {
                ans=tmp;
                xx=tx;
                yy=ty;
            }

            t*=0.995;

        }
        //printf("%.10f\n");
        printf("The safest point is (%.1f, %.1f).\n",xx,yy);
    }
    return 0;
}
