#include<stdio.h>
struct note
{
	int ii,jj,kk;
	int s;
}que[999999];
int tou,wei;
int dx[]={0,0,0,0,1,-1};
int dy[]={0,0,1,-1,0,0};
int dz[]={1,-1,0,0,0,0};
int st1,st2,st3,la1,la2,la3;
int a,b,c;
char aa[32][32][32];
int book[32][32][32];
int flag=0;
void dfs(int st1,int st2,int st3)
{
	flag=0;
	if (aa[st1][st2][st3]=='E') return ;
	tou=0;
	wei=0;
	que[wei].ii=st1;
	que[wei].jj=st2;
	que[wei].kk=st3;
	que[wei].s=0;
	wei++;
	while (tou<wei)
	{
		int i;
		for (i=0;i<6;i++)
		{
			int tx=que[tou].ii+dx[i];
			int ty=que[tou].jj+dy[i];
			int tz=que[tou].kk+dz[i];
			if (tx<0||tx>=a||ty<0||ty>=b||tz<0||tz>=c) continue;
			if (book[tx][ty][tz]==1) continue;
			if (aa[tx][ty][tz]=='#') continue;
			book[tx][ty][tz]=1;
			que[wei].ii=tx;
			que[wei].jj=ty;
			que[wei].kk=tz;
			que[wei].s=que[tou].s+1;
			wei++;
			if (aa[tx][ty][tz]=='E') flag=1;
		}
		tou++;
		if (flag==1) return ;
	}
	return ;
}
int main()
{
	while (scanf("%d%d%d",&a,&b,&c)!=EOF)
	{
		if (a==0&&b==0&&c==0) break;
		getchar();
		int i,j,k;
		for (i=0;i<a;i++)
		{
			for (j=0;j<b;j++)
			gets(aa[i][j]);
			getchar();
		}
		for (i=0;i<32;i++)
		for (j=0;j<32;j++)
		for (k=0;k<32;k++)
			book[i][j][k]=0;
		for (i=0;i<a;i++)
		for (j=0;j<b;j++)
		for (k=0;k<c;k++)
		{
			if (aa[i][j][k]=='S')
			{
				st1=i;
				st2=j;
				st3=k;
			}
			if (aa[i][j][k]=='E')
			{
				la1=i;
				la2=j;
				la3=k;
			}
		}
		book[st1][st2][st3]=1;
		flag=0;
		dfs(st1,st2,st3);
		if (flag==0) printf("Trapped!\n");
		else
		printf("Escaped in %d minute(s).\n",que[wei-1].s);
	}
	return 0;
}