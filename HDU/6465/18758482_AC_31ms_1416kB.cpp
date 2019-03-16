#include<bits/stdc++.h>
using namespace std;
double a[10];
double b[10];
int main()
{
    int T;

    scanf("%d",&T);
    while (T--)
    {
        for (int i=0;i<6;i++) scanf("%lf",&a[i]);
        for (int i=0;i<6;i++) scanf("%lf",&b[i]);

        double qx=a[2]-a[0];
        double qy=a[3]-a[1];
        double px=a[4]-a[0];
        double py=a[5]-a[1];

        double qx2=b[2]-b[0];
        double qy2=b[3]-b[1];
        double px2=b[4]-b[0];
        double py2=b[5]-b[1];


        int tt;
        scanf("%d",&tt);
        while (tt--)
        {
            double x,y;
            scanf("%lf%lf",&x,&y);
            x-=a[0];
            y-=a[1];
          //  printf("%.10f %.10f %.10f %.10f\n",qx,qy,px,py);

           // printf("%.10f %.10f %.10f %.10f\n",qx2,qy2,px2,py2);

            double xx=(y*px-x*py)/(qy*px-qx*py);
            double yy=(x-xx*qx)/px;

       //     printf("%.10f %.10f\n",xx,yy);
            double ans1=xx*qx2+yy*px2;
            double ans2=xx*qy2+yy*py2;
            ans1+=b[0];
            ans2+=b[1];
            printf("%.2f %.2f\n",ans1,ans2);
        }

    }
    return 0;
}