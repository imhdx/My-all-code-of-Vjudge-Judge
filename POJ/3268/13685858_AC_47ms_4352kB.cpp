#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
int map[1010][1010];
int dis[1010];
int dis1[1010];
int book[1010];
int main()
{
    int i,j,t,n,m;
    int x,y,l;
    int xw;
    while (scanf("%d%d%d",&n,&m,&xw)!=EOF)
    {
        for (i=1;i<=n;i++)
        {
            for (j=1;j<=n;j++)
            {
                i==j?map[i][j]=0:map[i][j]=(1<<29);
            }
        }
        for (i=1;i<=m;i++)
        {
            scanf("%d%d%d",&x,&y,&l);
            map[x][y]=min(map[x][y],l);
        }

        for (i=1;i<=n;i++)
        {
            dis[i]=(1<<29);
            book[i]=0;
        }
        dis[xw]=0;
        for (i=1;i<=n;i++)
        {
            int u=1;
            int minn=(1<<29);
            for (j=1;j<=n;j++)
            {
                if (book[j]==0)
                {
                    if (minn>=dis[j])
                    {
                        minn=dis[j];
                        u=j;
                    }
                }
            }
            book[u]=1;
            for (j=1;j<=n;j++)
            {
                if (map[u][j]==536870912) continue;
                if (dis[j]>dis[u]+map[u][j]) dis[j]=dis[u]+map[u][j];
            }
        }



        for (i=1;i<=n;i++)
        {
            for (j=i;j<=n;j++)
            {
                int cnt=map[i][j];
                map[i][j]=map[j][i];
                map[j][i]=cnt;
            }
        }


        for (i=1;i<=n;i++)
        {
            dis1[i]=(1<<29);
            book[i]=0;
        }
        dis1[xw]=0;
        for (i=1;i<=n;i++)
        {
            int u=1;
            int minn=(1<<29);
            for (j=1;j<=n;j++)
            {
                if (book[j]==0)
                {
                    if (minn>=dis1[j])
                    {
                        minn=dis1[j];
                        u=j;
                    }
                }
            }
            book[u]=1;
            for (j=1;j<=n;j++)
            {
                if (map[u][j]==536870912) continue;
                if (dis1[j]>dis1[u]+map[u][j]) dis1[j]=dis1[u]+map[u][j];
            }
        }




        int dd=-1;
        for (i=1;i<=n;i++)
        {
                if (dd<dis[i]+dis1[i])
                    dd=dis[i]+dis1[i];
        }
        printf("%d\n",dd);
    }
    return 0;
}
