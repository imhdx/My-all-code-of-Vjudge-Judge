#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<cmath>

using namespace std;
int n,m;
int book[51][51];
int bian[51][51];
char str[51][51];
int kk=0;
int tx[]={0,1,0,-1};
int ty[]={1,0,-1,0};
struct ma
{
    int x,y;
    int s;
}qq[2510];
struct note
{
    int from;
    int to;
    int len;
}que[10300];
int pre[110];
int get(int x)
{
    if (pre[x]==x) return x;
    return pre[x]=get(pre[x]);
}
bool jie(int a,int b)
{
    int x=get(a);
    int y=get(b);
    if (x==y) return false;
    if (x>y) pre[x]=y;
    else
        pre[y]=x;
    return true;
}
bool cmp(struct note a,struct note b)
{
    return a.len<b.len;
}
void bfs(int dx,int dy)
{
    int tou,wei;
    tou=wei=0;
    qq[wei].x=dx;
    qq[wei].y=dy;
    qq[wei].s=0;
    wei++;
    int i,j;
    for (i=0;i<51;i++)
    {
        for (j=0;j<51;j++)
            book[i][j]=0;
    }
    book[dx][dy]=1;
    while (tou<wei)
    {
        for (i=0;i<4;i++)
        {
            int xx=qq[tou].x+tx[i];
            int yy=qq[tou].y+ty[i];
            if (xx<0||xx>=n||yy<0||yy>=m||str[xx][yy]=='#'||book[xx][yy]==1) continue;
            book[xx][yy]=1;
            qq[wei].x=xx;
            qq[wei].y=yy;
            qq[wei].s=qq[tou].s+1;
            wei++;
            if (str[xx][yy]=='A')
            {
                que[kk].from=bian[dx][dy];
                que[kk].to=bian[xx][yy];
                que[kk].len=qq[wei-1].s;
                kk++;
            }
        }
        tou++;
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int i,j;
        for (i=0;i<110;i++) pre[i]=i;
        scanf("%d%d",&m,&n);
        getchar();
        for (i=0;i<n;i++)
        {
            gets(str[i]);
        }
        kk=0;
        int tyf=0;
        for (i=0;i<n;i++)
        {
            for (j=0;j<m;j++)
            {
                if (str[i][j]=='S'||str[i][j]=='A')
                {
                   bian[i][j]=tyf++;
                }
            }
        }
        for (i=0;i<n;i++)
        {
            for (j=0;j<m;j++)
            {
                if (str[i][j]=='A'||str[i][j]=='S')
                {
                    bfs(i,j);
                }
            }
        }
        sort(que,que+kk,cmp);
        int ans=0;
        int cc=0;
        for (i=0;i<kk;i++)
        {
            if (jie(que[i].from,que[i].to)) {cc++;ans=ans+que[i].len;}
        }
        printf("%d\n",ans);

    }

    return 0;
}
