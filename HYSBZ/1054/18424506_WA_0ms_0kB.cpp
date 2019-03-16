#include<bits/stdc++.h>
using namespace std;
int a[5][5];
bool vis[70000];
struct ac
{
    int num;
    int s;
}que[140000];
int tmp1,tmp2;
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
        for (int i=15;i>=0;i--)
        {
            if ((t>>i)&1)
            {
                int j=i-1;
                if (j>=0&&j<=15&&((t>>j)&1)==0)
                {
                    int tmp=t;
                    tmp-=(1<<i);
                    tmp+=(1<<j);
                    if (vis[tmp]==0)
                    {
                        vis[tmp]=1;
                        que[wei].num=tmp;
                        que[wei].s=que[tou].s+1;
                        wei++;
                        if (que[wei-1].num==tmp2) return que[wei-1].s;
                    }

                }
                j=i+1;
                if (j>=0&&j<=15&&((t>>j)&1)==0)
                {
                    int tmp=t;
                    tmp-=(1<<i);
                    tmp+=(1<<j);
                    if (vis[tmp]==0)
                    {
                        vis[tmp]=1;
                        que[wei].num=tmp;
                        que[wei].s=que[tou].s+1;
                        wei++;
                        if (que[wei-1].num==tmp2) return que[wei-1].s;
                    }

                }
                j=i+4;
                if (j>=0&&j<=15&&((t>>j)&1)==0)
                {
                    int tmp=t;
                    tmp-=(1<<i);
                    tmp+=(1<<j);
                    if (vis[tmp]==0)
                    {
                        vis[tmp]=1;
                        que[wei].num=tmp;
                        que[wei].s=que[tou].s+1;
                        wei++;
                        if (que[wei-1].num==tmp2) return que[wei-1].s;
                    }

                }
                j=i-4;
                if (j>=0&&j<=15&&((t>>j)&1)==0)
                {
                    int tmp=t;
                    tmp-=(1<<i);
                    tmp+=(1<<j);
                    if (vis[tmp]==0)
                    {
                        vis[tmp]=1;
                        que[wei].num=tmp;
                        que[wei].s=que[tou].s+1;
                        wei++;
                        if (que[wei-1].num==tmp2) return que[wei-1].s;
                    }

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
