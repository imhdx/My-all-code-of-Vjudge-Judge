#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
int map[1001][1001];
int dis[1001];
int main()
{
    int i,j,t,n;
    int x,y,l;
    while (scanf("%d%d",&t,&n)!=EOF)
    {
        for (i=1;i<=n;i++)
            dis[i]=999999999;

        dis[1]=0;
        for (i=1;i<=n;i++)
        {
            for (j=1;j<=n;j++)
            {
                map[i][j]=999999999;
                if (i==j) map[i][i]=0;
            }
        }
        for (i=1;i<=t;i++)
        {
            scanf("%d%d%d",&x,&y,&l);
            map[x][y]=min(map[x][y],l);
            if (x==1) dis[j]=min(dis[j],l);
        }

        for (i=1;i<=n;i++)
        {
            for (j=1;j<=n;j++)
            {
                if (dis[i]>dis[j]+map[j][i]) dis[i]=dis[j]+map[j][i];
            }
        }
        printf("%d\n",dis[n]);
    }
    return 0;
}