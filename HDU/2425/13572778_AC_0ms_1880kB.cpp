#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
struct node
{
	int x,y,step;
	bool operator <(const node &c)const{
	   return c.step<step;
	}
};
char ma[22][22];
int sx,sy,ex,ey,m,n,vp,vs,vt;
bool vis[22][22];
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
void bfs()
{
   memset(vis,0,sizeof(vis));
   priority_queue <node> Q;
   node now,next;
   now.x=sx;now.y=sy;now.step=0;
   vis[now.x][now.y]=1;
   Q.push(now);
   while(!Q.empty())
   {
   	  now=Q.top();Q.pop();
   	  if(now.x==ex&&now.y==ey)
	  {
	  	printf("%d\n",now.step);
	  	return ;
	  }
	  for(int i=0;i<4;i++)
	  {
	  	next.x=now.x+dir[i][0];
	  	next.y=now.y+dir[i][1];
	  	if(next.x>=0&&next.x<m&&next.y>=0&&next.y<n&&!vis[next.x][next.y]&&ma[next.x][next.y]!='@')
		{
			if(ma[next.x][next.y]=='T')
			{
				next.step=now.step+vt;
				vis[next.x][next.y]=1;
				Q.push(next);
			}
			else if(ma[next.x][next.y]=='.')
			{
				next.step=now.step+vs;
				vis[next.x][next.y]=1;
				Q.push(next);
			}
			else if(ma[next.x][next.y]=='#')
			{
				next.step=now.step+vp;
				vis[next.x][next.y]=1;
				Q.push(next);
			}
		}
	  }
   }
   printf("-1\n");
}
int main()
{
	int cas=1;
	while(scanf("%d %d",&m,&n)!=EOF)
	{
		scanf("%d %d %d",&vp,&vs,&vt);
		for(int i=0;i<m;i++)
			scanf("%s",ma[i]);
		scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
		printf("Case %d: ",cas++);
		bfs();
	}
	return 0;
}