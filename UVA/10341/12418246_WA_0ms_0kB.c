#include<stdio.h>
#include<math.h>
int main()
{
    int p,q,r,s,t,u;
    double l,R,x;
    while (scanf("%d%d%d%d%d%d",&p,&q,&r,&s,&t,&u)!=EOF)
    {
        x=0;
        l=0;
        R=1;
        while (fabs(l-R)<=1e-6)
        {
            x=(l+R)/2.00;
            if ((p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u)<1e-6) R=x;
            else if((p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u)>1e-6) l=x;
            if ((-(1e-6))<=(p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u)&&(p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u)<=1e-6) break;
        }
        if (l-R<=1e-6) printf("%.4f\n",x);
        else
            printf("No solution\n");
    }
    return 0;
}
