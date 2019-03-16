#include<bits/stdc++.h>
using namespace std;
long long a[1000][1000];
const long long inf=4e10;
int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        if (m==0&&n==0) return 0;
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
            {
                a[i][j]=inf;
            }
            a[i][i]=0;
        }
        for (int i=0;i<m;i++)
        {
            int x,y;
            long long int z;
            scanf("%d%d%lld",&x,&y,&z);
            a[x][y]=min(a[x][y],z);
            a[y][x]=min(a[y][x],z);
        }
        for (int k=1;k<=n;k++)
        {
            for (int i=1;i<=n;i++)
            {
                for (int j=1;j<=n;j++)
                    a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
            }
        }
        printf("%lld\n",a[1][n]);
    }

    return 0;
}
