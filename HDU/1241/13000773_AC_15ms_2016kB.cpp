#include<stdio.h>
int n,m;
int ans;
int dx[]={1,-1,1,-1,0,1,0,-1};
int dy[]={1,-1,-1,1,1,0,-1,0};
int a[1010][1010];
void bfs(int x,int y)
{
    int i;
    int tx,ty;
    a[x][y]=0;
    for (i=0;i<8;i++)
    {
        tx=x+dx[i];
        ty=y+dy[i];
        if (tx<1||tx>n||ty<1||ty>m) continue;
        if (a[tx][ty]!=0)
        bfs(tx,ty);
    }
}
int main()
{
    int i,j;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
    	getchar();
    	if (n==0&&m==0) break;
        ans=0;
        for (i=1;i<=n;i++)
        {
            for (j=1;j<=m;j++)
            {
            	char ccc=getchar();
            	if (ccc=='@') a[i][j]=1;
            	else
            	a[i][j]=0;
            }
            getchar();
        }
        for (i=1;i<=n;i++)
        {
            for (j=1;j<=m;j++)
            {
                if (a[i][j]!=0)
                {
                    ans++;
                    bfs(i,j);
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
