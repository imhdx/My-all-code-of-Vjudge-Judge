#include<bits/stdc++.h>
using namespace std;
double a[103][103];
int main()
{
    int t=1;
    int T;
    scanf("%d",&T);
    while (T--){
        memset(a,0,sizeof(a));
        int n,m,s,k;
        scanf("%d%d%d%d",&n,&m,&s,&k);
        for (int i=0;i<m;i++){
            int u,v;
            double w;
            scanf("%d%d%lf",&u,&v,&w);
            a[u][v]=a[v][u]=1.0*w/100;
        }
        for (int k=0;k<n;k++){
            for (int i=0;i<n;i++){
                for (int j=0;j<n;j++)
                {
                    if (a[i][k]*a[k][j]>a[i][j]) a[i][j]=a[i][k]*a[k][j];
                }
            }
        }
        double p=a[0][n-1];
        double ans=2.0*k*s/p;
        printf("Case %d: ",t++);
        printf("%.7f\n",ans);
    }
    return 0;
}
