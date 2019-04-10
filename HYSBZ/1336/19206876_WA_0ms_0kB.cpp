#include<bits/stdc++.h>
using namespace std;
double esp=1e-5;
struct node
{
    double x,y,z;
}p[100005];
double dis(node q,node p)
{
    return sqrt((q.x-p.x)*(q.x-p.x)+(q.y-p.y)*(q.y-p.y)+(q.z-p.z)*(q.z-p.z));
}
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=0;i<n;i++) scanf("%lf%lf",&p[i].x,&p[i].y),p[i].z=0;
        double t=10000;
        double ans=1e30;
        double x=0,y=0,z=0;
        while (t>esp)
        {
            int s=0;
            for (int i=0;i<n;i++)
            {
                if (dis(p[i],node{x,y,0})>dis(p[s],node{x,y,0})) s=i;
            }
            double dd=dis(p[s],node{x,y,z});
            ans=min(ans,dd);
            x=x+(p[s].x-x)/dd*t;
            y=y+(p[s].y-y)/dd*t;
            z=z+(p[s].z-z)/dd*t;;
            t*=0.99;
        }
        printf("%.2f\n",ans);
        printf("%.2f %.2f\n",x,y);
    }
    return 0;
}
