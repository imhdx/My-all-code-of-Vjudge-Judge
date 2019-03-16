#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n,m,k;
char a[110][110];
int ss[110][110];
int vis[110][110];
int flag=0;
void dfs(int x,int y,int s)
{
    if (flag==1) return ;
    if (vis[x][y]==1)
    {
        flag=1;
        printf("%d step(s) before a loop of %d step(s)\n",ss[x][y],s-ss[x][y]);
    }
    if (flag==1) return ;
    vis[x][y]=1;
    ss[x][y]=s;
    if (x<0||x>=n||y<0||y>=m)
    {
        flag=1;
        printf("%d step(s) to exit\n",s);
        return ;
    }
    if (flag==1) return ;
    if (a[x][y]=='N')
    {
        dfs(x-1,y,s+1);
    }
    else if (a[x][y]=='S')
    {
        dfs(x+1,y,s+1);
    }
    else if (a[x][y]=='W')
    {
        dfs(x,y-1,s+1);
    }
    else if (a[x][y]=='E')
    {
        dfs(x,y+1,s+1);
    }
    return ;
}
int main()
{
    while (scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
        if (n==0) return 0;
        getchar();
        flag=0;
        int i;
        memset(vis,0,sizeof(vis));
        for (i=0;i<n;i++) scanf("%s",a[i]);
        ss[0][k-1]=1;
        dfs(0,k-1,0);

    }

    return 0;
}
