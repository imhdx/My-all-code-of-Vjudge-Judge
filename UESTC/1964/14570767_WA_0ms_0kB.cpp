#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<queue>

using namespace std;
int m;
int dis[500010];
int bfs(int x)
{
    queue<int> que;
    que.push(x);
    dis[x]=0;
    while (!que.empty())
    {
        int x=que.front();
        que.pop();
        for (int i=1;i<=2;i++)
        {
            if (i==1)
            {
                int tx=x*2;
                if (tx>500000||tx<=0) continue;
                if (dis[x]+2<dis[tx])
                {
                    dis[tx]=dis[x]+2;
                    que.push(tx);
                    if (tx==m) return dis[m];
                }
            }
            else if (i==2)
            {
                int tx=x-3;
                if (tx>500000||tx<=0) continue;
                if (dis[x]+3<dis[tx])
                {
                    dis[tx]=dis[x]+3;
                    que.push(tx);
                    if (tx==m) return dis[m];
                }
            }
        }
    }
    return -1;
}
int main()
{
    int n;
    scanf("%d%d",&n,&m);
    memset(dis,0x7F,sizeof(dis));
    printf("%d\n",bfs(n));
    return 0;
}
