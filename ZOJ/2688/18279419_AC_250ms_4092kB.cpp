#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
double a[100005][5];
double INF=1e9;
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF&&n)
    {
        for (int i=0;i<n;i++)
            for (int j=0;j<5;j++) scanf("%lf",&a[i][j]);
        double ans=0;
        for (int i=0;i<(1<<5);i++)
        {
            double minn=INF;
            double maxx=-INF;
            for (int k=0;k<n;k++)
            {
                double sum=0;
                for (int j=0;j<5;j++)
                {
                    if ((i>>j)&1) sum+=a[k][j];
                    else sum-=a[k][j];
                }
                minn=min(minn,sum);
                maxx=max(maxx,sum);
            }
            ans=max(ans,maxx-minn);
        }
        printf("%.2f\n",ans);
    }
    return 0;
}
