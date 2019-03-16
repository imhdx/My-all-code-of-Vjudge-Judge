#include<stdio.h>
#define esp 1e-6
int  main()
{
    int n,k;
    int i,j;
    double kk;
    int s=0;
    double max=-100;
    double a[20000];
    scanf("%d%d",&n,&k);
    for (i=0;i<n;i++)
    {
      scanf("%lf",&a[i]);
      if (max-a[i]<esp) max=a[i];
    }
 //   for (i=0;i<n;i++)
 //   {
 //       printf("%lf ",a[i]);
 //   }
 //   printf("   %lf\n",max);
    kk=0.01;
    while (kk-max<=esp)
    {
        s=0;
        for (i=0;i<n;i++)
        {
            s=s+(int)(a[i]/kk);
        }
 //       printf("kk=%.2lf  s=%d\n",kk,s);
        if (s==k) break;
        kk=kk+0.01;
    }
    if (kk-max<=esp) printf("%.2lf\n",((double)(int)(kk+0.5)));
    else
    printf("0.00\n");
    return 0;
}
