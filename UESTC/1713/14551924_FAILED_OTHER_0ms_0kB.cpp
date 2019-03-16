#include<cmath>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int PI=4.0*atan(1.0);
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int x1,y1,r1,x2,y2,r2;
        scanf("%d%d%d%d%d%d",&x1,&y1,&r1,&x2,&y2,&r2);
        if ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)<=(r1-r2)*(r1-r2))
        {
            double ans;
            int r=min(r1,r2);
            ans=PI*r*r;
            printf("%.6f\n",ans);
        }
        else if ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)>=(r1+r2)*(r1+r2))
        {
            printf("0.000000\n");
        }
        else
        {
            double d=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
            double A1=2.0*acos((((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))+r1*r1-r2*r2)/(2.0*d*r1)); //求以圆心为顶点与两圆交点连线的角
            double A2=2.0*acos((((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))+r2*r2-r1*r1)/(2.0*d*r2));
            double s1=0.5*r1*r1*sin(A1)+0.5*r2*r2*sin(A2);
            double s2=A1/2.0*r1*r1+A2/2.0*r2*r2;
            double s=s2-s1;
            printf("%.6f\n",s);
        }
    }
    return 0;
}
