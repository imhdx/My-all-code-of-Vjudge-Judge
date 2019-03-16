#include<bits/stdc++.h>
using namespace std;
const double PI=4*atan(1.0);
int main()
{
    int T;
    double x1,x2,y1,y2;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
        double ans=acos((x1*x2+y1*y2)/(sqrt(x1*x1+y1*y1)*sqrt(x2*x2+y2*y2)));
        ans=ans*180/PI;
        printf("%.2f\n",ans);
    }

    return 0;
}
