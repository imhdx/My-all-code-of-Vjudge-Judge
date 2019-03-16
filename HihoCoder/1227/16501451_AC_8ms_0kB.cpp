#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
double ma[103][103];
double a[103];
double b[103];
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int n,m;
        scanf("%d%d",&m,&n);
        for (int i=0;i<m;i++) scanf("%lf%lf",&a[i],&b[i]);
        if (n>m)
        {
            printf("-1\n");
            continue;
        }
        int ans=INF;
        for (int i=0;i<m;i++)
        {
            for (int j=0;j<=i;j++)
            {
                ma[i][j]=ma[j][i]=sqrt((a[i]-a[j])*(a[i]-a[j])+(b[i]-b[j])*(b[i]-b[j]));
            }
        }
        for (int i=0;i<m;i++)
        {
            sort(ma[i],ma[i]+m);
            ma[i][m]=INF;
            if ((int)(ma[i][n-1])+1<ma[i][n])
            {
                ans=min(ans,(int)(ma[i][n-1])+1);
            }
        }
        if (ans>=INF) printf("-1\n");
        else
        printf("%d\n",ans);


    }
    return 0;
}
