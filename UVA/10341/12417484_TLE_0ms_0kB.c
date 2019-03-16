#include<stdio.h>
#include<math.h>
int main()
{
    int p,q,r,s,t,u;
    double x;
    while (scanf("%d%d%d%d%d%d",&p,&q,&r,&s,&t,&u)!=EOF)
    {
        x=0;
        for (x=0;x<=1;x=x+0.00001)
        {
            if ((-(1e-9))<=(p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u)<=1e-9) break;
        }
        if (x<=1) printf("%.4f\n",x);
        else
            printf("No solution\n");
    }
    return 0;
}
