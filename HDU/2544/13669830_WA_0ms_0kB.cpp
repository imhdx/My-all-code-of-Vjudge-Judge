#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
int map[101][101];
int dis[101];
int book[101];
int main()
{
    int i,j,t,n,m;
    int x,y,l;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        if (n==0&&m==0) break;
        for (i=1;i<=n;i++)
        {
            for (j=1;j<=n;j++)
            {
                map[i][j]=99999999;
                if (i==j) map[i][i]=0;
            }
        }
        for (i=1;i<=m;i++)
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
        int u;
        for (i=1;i<=n;i++)
        {
            int minn=100000000;
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
        }

        printf("%d\n",dis[n]);
    }
    return 0;
}
