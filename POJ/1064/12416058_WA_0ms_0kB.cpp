#include<stdio.h>
#include<math.h>
double esp=1e-9;
double man(double a,double b)
{
    if (a<b) return b;
    return a;
}
int  main()
{
    int n,k;
    int i,j;
    double kk;
    int s=0;
    double max=-100;
    double a[20000];
    double mid;
    while (scanf("%d%d",&n,&k)!=EOF)
    {
        max=-100;
        for (i=0;i<n;i++)
        {
          scanf("%lf",&a[i]);
          max=man(max,a[i]);
        }
        kk=0.0;
        for (j=0;j<300;j++)
        {
            s=0;
            mid=(kk+max)/2.0;
            for (i=0;i<n;i++)
            {
                s=s+(int)(a[i]/mid);
            }
            if (s>=k) kk=mid;
            else max=mid;
        }
        printf("%.2f\n",kk);
    }
    return 0;
}
