#include<stdio.h>
const double eps=1e-9;
double D,H,h;
double mid,midmid;
double d1,d2,l,r;
double f(double x)
{
    return D-x+H-(H-h)*D/x;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf%lf%lf",&H,&h,&D);
        l=(H-h)*D/H;
        r=D;
        mid=(l+r)/2;
        midmid=(mid+r)/2;
        d1=f(mid);
        d2=f(midmid);
        while(r-l>=eps)
        {
            mid=(l+r)/2;
            midmid=(mid+r)/2;
            d1=f(mid);
            d2=f(midmid);
            if(d1>=d2) r=midmid;
            else l=mid;
        }
        printf("%.3lf\n",d1);
    }
    return 0;
}
