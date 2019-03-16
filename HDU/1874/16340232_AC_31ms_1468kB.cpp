#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int a[208][208];
int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++) a[i][j]=inf;
            a[i][i]=0;
        }
        for (int i=0;i<m;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            a[x][y]=min(a[x][y],z);
            a[y][x]=min(a[y][x],z);
        }
        for (int k=0;k<n;k++)
        {
            for (int i=0;i<n;i++)
            {
                for (int j=0;j<n;j++)
                    a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
            }
        }
        int st,la;
        scanf("%d%d",&st,&la);
        if (a[st][la]>=inf) printf("-1\n");
        else
            printf("%d\n",a[st][la]);
    }
    return 0;
}
