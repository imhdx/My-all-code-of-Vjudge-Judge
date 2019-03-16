#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<random>

using namespace std;
mt19937 rng(20000205);
double a[1000006][5];
//int r[1000006];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++) for (int j=0;j<5;j++) scanf("%lf",&a[i][j]);
    //for (int i=0;i<n;i++) r[i]=i;
    //random_shuffle(r,r+n);
    //for (int i=0;i<n;i++) printf("%d\n",r[i]);
    //for (int i=0;i<n;i++)
    //    for (int j=0;j<5;j++)
    //    printf("%.10f\n",a[i][j]);
    int cnt=4;
    int l=rng()%n,r=rng()%n;
    double ans=0;
    while (cnt--)
    {
        if (cnt&1)
        {
            int pos=0;
            for (int i=0;i<n;i++)
            {
                double tmp=0;
                for (int j=0;j<5;j++)
                    tmp+=fabs(a[i][j]-a[l][j]);
                if (ans<tmp)
                {
                    ans=tmp;
                    pos=i;
                }
            }
            r=pos;
        }
        else
        {
            int pos=0;
            for (int i=0;i<n;i++)
            {
                double tmp=0;
                for (int j=0;j<5;j++)
                    tmp+=fabs(a[i][j]-a[r][j]);
                if (ans<tmp)
                {
                    ans=tmp;
                    pos=i;
                }
            }
            l=pos;
        }
    }
    printf("%.2f\n",ans);
    return 0;
}
