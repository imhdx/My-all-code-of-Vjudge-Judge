#include<bits/stdc++.h>
using namespace std;
double F[400005];
long long n;
double p;
void init()
{
    F[0]=log(1);
    for (int i=1;i<400005;i++)
    {
        F[i]=F[i-1]+log(i);
    }
}
double f(int i)
{
    double ans1=(F[2*n-i]-F[n-i]-F[n])+(n-i)*log(p)+(n+1)*log(1-p);
    double ans2=(F[2*n-i]-F[n-i]-F[n])+(n-i)*log(1-p)+(n+1)*log(p);
    double ans=i*(exp(ans1)+exp(ans2));
    return ans;
}
int main()
{
    int t=1;
    init();
    while (scanf("%lld%lf",&n,&p)!=EOF)
    {
        double ans=0;
        for (int i=1;i<=n;i++)
        {
            ans+=f(i);
        }
        printf("Case %d: ",t++);
        printf("%.6f\n",ans);
    }
    return 0;
}
