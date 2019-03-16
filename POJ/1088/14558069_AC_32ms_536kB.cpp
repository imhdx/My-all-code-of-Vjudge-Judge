#include<algorithm>
#include<stdio.h>
using namespace std;
int maxx=1;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int n,m;
int a[110][110];
struct note
{
    int x,y;
    int h;
}que[10010];
bool cmp(struct note q,struct note p)
{
    return q.h<p.h;
}
int dp[110][110];
void dfs(int x,int y)
{
    int i;
    for (i=0;i<4;i++)
    {
        int tx=x+dx[i];
        int ty=y+dy[i];
        if (tx<1||tx>n||ty<1||ty>m) continue;
        if (a[x][y]<=a[tx][ty]) continue;
        dp[x][y]=max(dp[x][y],dp[tx][ty]+1);
        maxx=max(maxx,dp[x][y]);
    }
}
int main()
{
    int i,j;
    scanf("%d%d",&n,&m);
    for (i=0;i<101;i++)
    {
        for (j=0;j<110;j++)
            dp[i][j]=1;
    }
    int cnt=0;
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            scanf("%d",&a[i][j]);
            que[cnt].x=i;
            que[cnt].y=j;
            que[cnt].h=a[i][j];
            cnt++;
        }
    }
    sort(que,que+cnt,cmp);
    for (i=0;i<cnt;i++)
    {
        dfs(que[i].x,que[i].y);
    }
    printf("%d\n",maxx);

    return 0;
}
