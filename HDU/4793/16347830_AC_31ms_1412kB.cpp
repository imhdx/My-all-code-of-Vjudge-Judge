#include<bits/stdc++.h>
using namespace std;
int main()
{
    double Rm,R,r,x,y,vx,vy;
    while (scanf("%lf%lf%lf%lf%lf%lf%lf",&Rm,&R,&r,&x,&y,&vx,&vy)!=EOF)
    {
        double a=vx*vx+vy*vy;
        double b=2*x*vx+2*y*vy;
        double c=x*x+y*y-(R+r)*(R+r);
        double d=b*b-4*a*c;
        if (d<=0)
        {
            printf("0\n");
        }
        else
        {
            d=sqrt(d);
            double t1=(-b+d)/(2*a);
            double t2=(-b-d)/(2*a);
            if (t1<0||t2<0)
            {
                printf("0\n");
            }
            else
            {
                c=x*x+y*y-(Rm+r)*(Rm+r);
                d=b*b-4*a*c;
                if (d<=0)
                    printf("%.10f\n",fabs(t1-t2));
                else
                {
                    d=sqrt(d);
                    double t3=(-b+d)/(2*a);
                    double t4=(-b-d)/(2*a);
                    if (t3<0||t4<0)
                    {
                        printf("%.10f\n",fabs(t1-t2));
                    }
                    else
                    {
                        printf("%.10f\n",2*fabs(min(t1,t2)-min(t3,t4)));
                    }
                }
            }
        }

    }

    return 0;
}
