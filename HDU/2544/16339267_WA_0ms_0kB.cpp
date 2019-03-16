#include<bits/stdc++.h>
using namespace std;
const int inf=1e9;
int a[105][105];
int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        if (n==0&&m==0) return 0;
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)a[i][j]=inf;
            a[i][i]=0;///注意此处a[i][i]=0;
        }
        for (int i=0;i<m;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            a[x][y]=min(a[x][y],z);
        }
        for (int k=1;k<=n;k++)
        {
            for (int i=1;i<=n;i++)
            {
                for (int j=1;j<=n;j++)
                {
                    a[i][j]=min(a[i][j],a[i][k]+a[j][k]);
                }
            }
        }
        printf("%d\n",a[1][n]);
    }

    return 0;
}
