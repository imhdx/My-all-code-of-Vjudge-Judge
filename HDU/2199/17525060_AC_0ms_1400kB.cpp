#include<bits/stdc++.h>
using namespace std;
const double eps=1e-7;
double f(double x)
{
    return 8*x*x*x*x+7*x*x*x+2*x*x+3*x+6;
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        double y;
        scanf("%lf",&y);
        double l=0;
        double r=100;
        if ((f(l)-y)*(f(r)-y)>0)
            printf("No solution!\n");
        else
        {
            while (r-l>eps)
            {
                double mid=(l+r)/2.0;
                if (f(mid)<y)
                    l=mid;
                else if (f(mid)>y)
                    r=mid;
                else
                    break;
            }
            printf("%.4f\n",(l+r)/2);
        }
    }
    return 0;
}
