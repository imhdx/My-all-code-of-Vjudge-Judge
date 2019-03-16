#include<bits/stdc++.h>
using namespace std;
double x[1000010];
double y[1000010];
int n;
const double eps=1e-8;
double f(double k)
{
    double maxx=0;
    for (int i=0;i<n;i++)
    {
        if (maxx<y[i]-k*x[i])
        {
            maxx=y[i]-k*x[i];
        }
    }
    double ans=maxx*maxx+(maxx/k)*(maxx/k);
    return ans;
}
int main()
{
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=0;i<n;i++)
        {
            scanf("%lf%lf",&x[i],&y[i]);
        }
        double l=-1e6;
        double r=0;
        double minn=1e9;
        int cnt=2000;
        while (cnt--)
        {
            double m1=(l+r)/2;
            double m2=(m1+r)/2;
            double f1=f(m1);
            double f2=f(m2);
            minn=min(minn,f1);
            minn=min(minn,f2);
            if (f1-f2>eps)
            {
                l=m1;
            }
            else if (f1-f2<eps)
            {
                r=m2;
            }
            //else
            //    break;
        }
        printf("%.3f\n",sqrt(minn));

    }


    return 0;
}
