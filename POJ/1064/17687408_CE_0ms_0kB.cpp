#include<stdio.h>
#include<math.h>
double esp=1e-9;
int  main()
{
    int n,k;
    int i,j;
    double kk;
    int s=0;
    double max;
    double a[20000];
    double mid;
    while (scanf("%d%d",&n,&k)!=EOF)
    {
        max=100100;
        for (i=0;i<n;i++)
          scanf("%lf",&a[i]);
        kk=0.0;
        while(kk<max)
        {
            s=0;
            mid=(kk+max)/2.0;
            for (i=0;i<n;i++)
            {
                s=s+(int)(a[i]/mid);
            }
            if (s>=k) kk=mid;
            else max=mid-eps;
        }
        printf("%.2f\n",floor(max*100)/100);
    }
    return 0;
}
