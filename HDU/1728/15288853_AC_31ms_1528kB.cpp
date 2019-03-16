#include<bits/stdc++.h>
using namespace std;
int n,m;
int k;
int xx,xxx,yy,yyy;
struct Node
{
    int x,y;
    int s;
} que[14400];
int tx[]= {0,1,0,-1};
int ty[]= {1,0,-1,0};
int vis[120][120];
char a[120][120];
bool check(int x,int y)
{
    if (x>=0&&x<m&&y>=0&&y<n&&a[x][y]=='.')
        return true;
    return false;
}
void bfs(int x,int y)
{
    int tou=0,wei=0;
    vis[x][y]=1;
    que[wei].x=x;
    que[wei].y=y;
    que[wei].s=-1;
    wei++;
    if (que[wei-1].x==xxx&&que[wei-1].y==yyy&&que[wei-1].s<=k)
    {
        printf("yes\n");
        return ;
    }
    while (tou<wei)
    {
        int i;
        for (i=0; i<4; i++)
        {
            int dx=que[tou].x+tx[i];
            int dy=que[tou].y+ty[i];
            while (check(dx,dy))
            {
                if (vis[dx][dy]==0)
                {
                    vis[dx][dy]=1;
                    que[wei].x=dx;
                    que[wei].y=dy;
                    que[wei].s=que[tou].s+1;
                    wei++;
                    //printf("%d %d\n",que[wei-1].x,que[wei-1].y);
                    if (que[wei-1].x==xxx&&que[wei-1].y==yyy&&que[wei-1].s<=k)
                    {
                        printf("yes\n");
                        return ;
                    }
                }
                dx+=tx[i];
                dy+=ty[i];
            }
        }
        tou++;
    }
    printf("no\n");
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        memset(vis,0,sizeof(vis));
        int i,j;
        scanf("%d%d",&m,&n);
        for (i=0; i<m; i++)
        {
            scanf("%s",a[i]);
        }
        scanf("%d%d%d%d%d",&k,&yy,&xx,&yyy,&xxx);
        xx--;
        xxx--;
        yy--;
        yyy--;
        if (xx==xxx&&yy==yyy)
        {
            printf("yes\n");
            continue;
        }
        else if (a[xxx][yyy]=='*')
        {
            printf("no\n");
            continue;
        }
        bfs(xx,yy);
    }
    return 0;
}
