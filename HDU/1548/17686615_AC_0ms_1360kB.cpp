#include<bits/stdc++.h>
using namespace std;
const int MAXN=300;
int k[MAXN];
bool vis[MAXN];
int a,b,n;
struct node
{
    int x;
    int f;
}que[MAXN];
int bfs(int st,int la)
{
    int tou=0,wei=0;
    que[wei].x=st;
    que[wei++].f=0;
    vis[st]=1;
    if (que[wei-1].x==la) return que[wei-1].f;
    while (tou<wei)
    {
        int xx=que[tou].x+k[que[tou].x];
        if (xx<=n&&vis[xx]==0)
        {
            vis[xx]=1;
            que[wei].x=xx;
            que[wei++].f=que[tou].f+1;
            if (que[wei-1].x==la) return que[wei-1].f;
        }
        xx=que[tou].x-k[que[tou].x];
        if (xx>=1&&vis[xx]==0)
        {
            vis[xx]=1;
            que[wei].x=xx;
            que[wei++].f=que[tou].f+1;
            if (que[wei-1].x==la) return que[wei-1].f;
        }
        tou++;
    }
    return -1;
}
int main()
{
    while (scanf("%d",&n)!=EOF)
    {
        if (n==0) return 0;
        scanf("%d%d",&a,&b);
        memset(vis,0,sizeof(vis));
        memset(k,0,sizeof(k));
        for (int i=1;i<=n;i++) scanf("%d",&k[i]);
    printf("%d\n",bfs(a,b));




    }

    return 0;
}
