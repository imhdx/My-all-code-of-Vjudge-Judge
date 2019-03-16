#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
int map[1010][1010];
int dis[1010];
int book[1010];
int i,j,t,n;
int x,y,l;
void D()
{
    int u;
    for (i=1;i<=n;i++)
    {
        int minn=99999999;
        for (j=1;j<=n;j++)
        {
            if (book[j]==0)
            {
                if (minn>dis[j])
                {
                    minn=dis[j];
                    u=j;
                }
            }
        }
        book[u]=1;
        for (j=1;j<=n;j++)
        {
            if (dis[j]>dis[u]+map[u][j]) dis[j]=dis[u]+map[u][j];
        }
    }
}
int main()
{
    while (scanf("%d%d",&t,&n)!=EOF)
    {
        if (t==0&&n==0) break;
        for (i=1;i<=n;i++)
        {
            for (j=1;j<=n;j++)
            {
                map[i][j]=99999999;
                if (i==j) map[i][i]=0;
            }
        }
        for (i=1;i<=t;i++)
        {
            scanf("%d%d%d",&x,&y,&l);
            map[x][y]=min(map[x][y],l);
            map[y][x]=map[x][y];
        }

        for (i=1;i<=n;i++)
        {
            dis[i]=map[1][i];
            book[i]=0;
        }
        dis[1]=0;
        D();
        printf("%d\n",dis[n]);
    }
    return 0;
}
