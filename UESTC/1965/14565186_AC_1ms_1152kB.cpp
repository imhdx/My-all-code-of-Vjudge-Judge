#include<cstdio>
#include<cstring>
using namespace std;
char a[1010][1010];
struct note
{
    int x,y;
}que[1020100];
int dx[]={0,1,0,-1,1,-1,1,-1};
int dy[]={1,0,-1,0,1,1,-1,-1};
int n,m;
void bfs(int x,int y)
{
    int tou;
    int wei;
    tou=wei=0;
    que[wei].x=x;
    que[wei].y=y;
    wei++;
    while (tou<wei)
    {
        int i;
        for (i=0;i<8;i++)
        {
            int tx=que[tou].x+dx[i];
            int ty=que[tou].y+dy[i];
            if (tx<0||tx>=n||ty<0||ty>=m) continue;
            if (a[tx][ty]=='.') continue;
            que[wei].x=tx;
            que[wei].y=ty;
            wei++;
            a[tx][ty]='.';
        }
        tou++;
    }
}
int main()
{
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        getchar();
        int i,j;
        for (i=0;i<n;i++)
        {
            scanf("%s",&a[i]);
        }
        int ans=0;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                if (a[i][j]=='@')
                {
                    a[i][j]='.';
                    ans++;
                    bfs(i,j);
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
