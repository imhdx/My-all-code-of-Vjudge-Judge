#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
int ans=0;
int vis[1000010];
struct note
{
    int x;
    int s;
} que[1000010];
int m;
int bfs(int x)
{
    int tou=0,wei=0;
    que[wei].x=x;
    que[wei].s=0;
    wei++;
    if (que[wei-1].x==m)
        return que[wei-1].s;
    while (tou<wei)
    {
        for (int i=0; i<3; i++)
        {
            int tx=que[tou].x;
            if (i==0) tx++;
            if (i==1) tx--;
            if (i==2) tx=tx*2;
            if (tx<0||tx>1000000)
                continue;
            if (vis[tx])
                continue;
            vis[tx]=1;
            que[wei].x=tx;
            que[wei].s=que[tou].s+1;
            wei++;
            if (que[wei-1].x==m)
                return que[wei-1].s;
        }
        tou++;
    }
}
int main()
{
    int n;
    memset(vis,0,sizeof(vis));
    scanf("%d%d",&n,&m);
    printf("%d\n",bfs(n));
    return 0;
}
