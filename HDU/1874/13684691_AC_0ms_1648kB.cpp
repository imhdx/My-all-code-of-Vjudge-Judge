#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
int map[300][300];
int dis[300];
int book[300];
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
                i==j?map[i][j]=0:map[i][j]=(1<<29);
            }
        }
        for (i=1;i<=m;i++)
        {
            scanf("%d%d%d",&x,&y,&l);
            map[x+1][y+1]=min(map[x+1][y+1],l);
            map[y+1][x+1]=min(map[y+1][x+1],l);
        }

        scanf("%d%d",&x,&y);
        x++;
        y++;
        for (i=1;i<=n;i++)
        {
            dis[i]=(1<<29);
            book[i]=0;
        }
        dis[x]=0;
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
        if (dis[y]==536870912) printf("-1\n");
        else
        printf("%d\n",dis[y]);
    }
    return 0;
}
