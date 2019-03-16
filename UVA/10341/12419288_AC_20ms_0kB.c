#include<stdio.h>
#include<math.h>
int p,q,r,s,t,u;
double l,R,x;
double f(double x)
{
    double y;
    y=p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
    return y;
}
int main()
{
    int i;
    while (scanf("%d%d%d%d%d%d",&p,&q,&r,&s,&t,&u)!=EOF)
    {
        x=0;
        l=0;
        R=1;
        if (f(0)*f(1)>0) printf("No solution\n");
        else
        {
            for (i=0;i<100;i++)
            {
                x=(l+R)/2.00;
                if (f(x)<1e-9) R=x;
                else  l=x;
            }
            printf("%.4f\n",x);
        }
    }
    return 0;
}
