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
        while (l-R<=(1e-7))
        {
            x=(l+R)/2.00;
 //           printf("x=%.5f\n",x);
            if ((p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u)<1e-7) R=x;
            else if((p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u)>1e-7) l=x;
            if ((-(1e-7))<=(p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u)&&(p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u)<=1e-7) break;
        }
        if ((-(1e-7))<=(p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u)&&(p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u)<=1e-7) printf("%.4f\n",x);
        else
            printf("No solution\n");
    }
    return 0;
}
