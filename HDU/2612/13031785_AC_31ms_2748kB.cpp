#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int book[300][300];
int bu1[300][300];
int bu2[300][300];
struct note1
{
	int x;
	int y;
	int s;
}que[99999];
struct note
{
	int xx;
	int yy;
}kfc[40010];
char a[300][300];
int n,m;
int kk;
int Yx,Yy,Mx,My;
void dfs(int stx,int sty)
{
	int tou,wei;
	tou=wei=0;
	que[wei].x=stx;
	que[wei].y=sty;
	que[wei].s=0;
	wei++;
	book[stx][sty]=1;
	while (tou<wei)
	{
		int i;
		for (i=0;i<4;i++)
		{
			int tx=que[tou].x+dx[i];
			int ty=que[tou].y+dy[i];
			if (tx<0|tx>=n||ty<0||ty>=m) continue;
			if (book[tx][ty]==1) continue;
			if (a[tx][ty]=='#') continue;
			que[wei].x=tx;
			que[wei].y=ty;
			que[wei].s=que[tou].s+1;
			wei++;
			book[tx][ty]=1;
			if (stx==Mx&&sty==My) bu1[tx][ty]=que[tou].s+1;
			else
			bu2[tx][ty]=que[tou].s+1;
		}
		tou++;
	}
	return ;
}
int main()
{
	int i,j;
	while (scanf("%d%d",&n,&m)!=EOF)
	{
		int k=0;
		getchar();
		for (i=0;i<n;i++)
		gets(a[i]);
 		for (i=0;i<n;i++)
		{
			for (j=0;j<m;j++)
			{
				if (a[i][j]=='@')
				{
					kfc[k].xx=i;
					kfc[k].yy=j;
					k++;
				}
				else if (a[i][j]=='Y')
				{
					Yx=i;
					Yy=j;
				}
				else if (a[i][j]=='M')
				{
					Mx=i;
					My=j;
				} 
			}
		}
		int minn=9999999;
		memset(book,0,sizeof(int)*300*300);
		dfs(Mx,My);
			memset(book,0,sizeof(int)*300*300);
		dfs(Yx,Yy);
		for (kk=0;kk<k;kk++)
		{
			if (bu1[kfc[kk].xx][kfc[kk].yy]+bu2[kfc[kk].xx][kfc[kk].yy]<minn)
			 minn=(bu1[kfc[kk].xx][kfc[kk].yy]+bu2[kfc[kk].xx][kfc[kk].yy]);
		}
		printf("%d\n",11*minn);
	}
	
	return 0;
}