#include<queue>
#include<stdio.h>
#include<string.h>
using namespace std;
int vis[12][12];
int mov[8][2]={-1,2,-1,-2,1,2,1,-2,2,1,2,-1,-2,1,-2,-1};
int x1,y1,x2,y2,jump;
struct point
{
    int x,y,step;
};
int bfs(int x,int y)
{
    point p,tmp;
    p.x=x,p.y=y,p.step=0;
    int i;
    queue<point>q;
    for(q.push(p);!q.empty();q.pop())
    {
        p=q.front();
        if(p.x==x2&&p.y==y2)
        {
            printf("To get from %c%d to %c%d takes %d knight moves.\n",x1-1+'a',y1,x2-1+'a',y2,p.step);
            return 0;
        }
        for(i=0;i<8;i++)
        {
            tmp.x=p.x+mov[i][0],tmp.y=p.y+mov[i][1];
            if(tmp.x>=1&&tmp.x<=8&&tmp.y>=1&&tmp.y<=8&&!vis[tmp.x][tmp.y])
            {
                vis[tmp.x][tmp.y]=1;
                tmp.step=p.step+1;
                q.push(tmp);
            }
        }
    }
    return 0;
}
int main()
{
    char a[3],b[3];
    while(scanf("%s %s",a,b)==2)
    {
        memset(vis,0,sizeof(vis));
        x1=a[0]-'a'+1,x2=b[0]-'a'+1;
        y1=a[1]-'0';
        y2=b[1]-'0';
        vis[x1][y1]=1;
        jump=100000;
        bfs(x1,y1);

    }
    return 0;
}
