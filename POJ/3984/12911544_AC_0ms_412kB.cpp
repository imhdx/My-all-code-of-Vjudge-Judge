#include<stdio.h>
int a[10][10];
int book[10][10]={0};
int tx[]={0,-1,0,1};
int ty[]={1,0,-1,0};
struct note
{
    int x;
    int y;
    int f;
    int s;
}que[9999];
void Printf(int kk)
{
    if (que[kk].f==0) return ;
    Printf(que[kk].f);
    printf("(%d, %d)\n",que[kk].x-1,que[kk].y-1);
    return ;
}
int tou=1,wei=1;
void dfs()
{
    book[1][1]=1;
    que[wei].x=1;
    que[wei].y=1;
    que[wei].f=0;
    que[wei].s=0;
    wei++;
    while (tou<wei)
    {
        int i;
        for (i=0;i<4;i++)
        {
            int dx=que[tou].x+tx[i];
            int dy=que[tou].y+ty[i];
            if (dx<1||dx>5||dy<1||dy>5) continue;
            if (book[dx][dy]==1) continue;
            if (a[dx][dy]==1) continue;
            que[wei].x=dx;
            que[wei].y=dy;
            que[wei].s=que[tou].s+1;
            que[wei].f=tou;
            wei++;
            book[dx][dy]=1;
            if (dx==5&&dy==5) return ;
        }
        tou++;
    }
}
int main()
{
    int i,j;
    while (scanf("%d",&a[1][1])!=EOF)
    {
        for (j=2;j<=5;j++)
            scanf("%d",&a[1][j]);
        for (i=2;i<=5;i++)
            for (j=1;j<=5;j++)
            scanf("%d",&a[i][j]);
        for (i=0;i<10;i++)
            for (j=0;j<10;j++)
            book[i][j]=0;
        tou=1;
        wei=1;
        dfs();
        printf("(0, 0)\n");
        Printf(que[wei-1].f);
        printf("(4, 4)\n");
    }
    return 0;
}
