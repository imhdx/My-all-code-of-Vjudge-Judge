#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n;
double x[10005];
double y[10005];
double w[10005];
double dis(double xx,double yy,int i)
{
    return sqrt((xx-x[i])*(xx-x[i])+(yy-y[i])*(yy-y[i]));
}
int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%lf%lf%lf",&x[i],&y[i],&w[i]);
    double t=1000;
    double xx=0,yy=0;
    for (int i=0;i<n;i++) xx+=x[i],yy+=y[i];
    xx/=n;yy/=n;
    while (t>0.00000001)
    {
        double tx,ty;
        tx=ty=0;
        for (int i=0;i<n;i++)
        {
            tx+=(x[i]-xx)*w[i]/dis(xx,yy,i);
            ty+=(y[i]-yy)*w[i]/dis(xx,yy,i);
        }
        xx+=tx*t;
        yy+=ty*t;
        if (t>0.5) t*=0.5;
        else t*=0.97;
    }
    printf("%.3lf %.3lf\n",xx,yy);
    return 0;
}
