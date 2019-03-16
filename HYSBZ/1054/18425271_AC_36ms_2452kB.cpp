#include<bits/stdc++.h>
using namespace std;
bool vis[70000];
struct ac
{
    int num;
    int s;
}que[140000];
int a[10][10];
void hash1(int tmp)
{
    int t=15;
    for (int i=0;i<4;i++)
    {
        for (int j=0;j<4;j++)
        {
            a[i][j]=(tmp>>t)&1;
            t--;
        }
    }
}
int hash2()
{
    int tmp=0;
    for (int i=0;i<4;i++)
    {
        for (int j=0;j<4;j++)
        {
            tmp=tmp*2+a[i][j];
        }
    }
    return tmp;
}
int tmp1,tmp2;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int bfs()
{
    int tou=0,wei=0;
    que[wei].num=tmp1;
    que[wei].s=0;
    wei++;
    if (que[wei-1].num==tmp2) return que[wei-1].s;
    while (tou<=wei)
    {
        int t=que[tou].num;
        hash1(t);
        for (int i=0;i<4;i++)
        {
            for (int j=0;j<4;j++)
            {
                if (a[i][j]==1)
                for (int k=0;k<4;k++)
                {
                    int xx=i+dx[k];
                    int yy=j+dy[k];
                    if (xx<0||xx>3||yy<0||yy>3) continue;
                    if (a[xx][yy]==1) continue;
                    swap(a[i][j],a[xx][yy]);
                    int ttt=hash2();
                    if (vis[ttt])
                    {
                        swap(a[i][j],a[xx][yy]);
                        continue;
                    }
                    vis[ttt]=1;
                    que[wei].num=ttt;
                    que[wei++].s=que[tou].s+1;
                    if (que[wei-1].num==tmp2) return que[wei-1].s;
                    swap(a[i][j],a[xx][yy]);
                }
            }
        }
        tou++;
    }
    return -1;
}
int main()
{
    for (int i=0;i<16;i++)
    {
        int x;
        scanf("%1d",&x);
        tmp1=tmp1*2+x;
    }
    vis[tmp1]=1;
    tmp2=0;
    for (int i=0;i<16;i++)
    {
        int x;
        scanf("%1d",&x);
        tmp2=tmp2*2+x;
    }
    printf("%d\n",bfs());



    return 0;
}
