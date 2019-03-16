#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
int dis[205][205];
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        if (n==0) return 0;
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
            {
                dis[i][j]=0;
            }
        }
        int x,y;
        char str[3000];
        while (scanf("%d%d",&x,&y,str)!=EOF)
        {
            if (x==0&&y==0) break;
            scanf("%s",str);
            for (int i=0;str[i];i++)
            {
                dis[x][y]|=(1<<(str[i]-'a'));
            }
        }
        for (int k=1;k<=n;k++)
        {
            for (int i=1;i<=n;i++)
            {
                for (int j=1;j<=n;j++)
                {
                    dis[i][j]|=(dis[i][k]&dis[k][j]);
                }
            }
        }
        while (scanf("%d%d",&x,&y)!=EOF)
        {
            if (x==0&&y==0) break;
            if (dis[x][y])
            {
                for (int i=0;i<26;i++)
                {
                    if ((dis[x][y]>>i)&1)
                        printf("%c",'a'+i);
                }
                printf("\n");
            }
            else
                printf("-\n");
        }
        printf("\n");
    }

    return 0;
}
