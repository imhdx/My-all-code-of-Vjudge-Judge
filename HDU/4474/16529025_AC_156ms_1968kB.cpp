#include<bits/stdc++.h>
using namespace std;
bool f[12];
bool vis[10006];
struct node
{
    int c;
    int mo;
    int fu;
}que[10005];
int n,m;
int bfs()
{
    memset(vis,0,sizeof(vis));
    int tou=0,wei=0;
    que[wei].c=-1;
    que[wei].mo=0;
    que[wei].fu=-1;
    wei++;
    for (int i=1;i<10;i++)
    {
        if (f[i]) continue;
        int dx=(que[tou].mo*10+i)%n;
        if (vis[dx]) continue;
        vis[dx]=1;
        que[wei].c=i;
        que[wei].fu=tou;
        que[wei].mo=dx;
        wei++;
        if (que[wei-1].mo==0) return wei-1;
    }
    tou++;
    while (tou<wei)
    {
        for (int i=0;i<10;i++)
        {
            if (f[i]) continue;
            int dx=(que[tou].mo*10+i)%n;
            if (vis[dx]) continue;
            vis[dx]=1;
            que[wei].c=i;
            que[wei].fu=tou;
            que[wei].mo=dx;
            wei++;
            if (que[wei-1].mo==0) return wei-1;
        }
        tou++;
    }
    return -1;
}
void print(int wei)
{
    if (que[wei].fu==-1) return ;
    print(que[wei].fu);
    printf("%d",que[wei].c);
}
int main()
{
    int t=1;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        memset(f,0,sizeof(f));
        for (int i=0;i<m;i++)
        {
            int x;
            scanf("%d",&x);
            f[x]=1;
        }
        printf("Case %d: ",t++);
        if (n==0)
        {
            if (f[0]) printf("-1\n");
            else
                printf("0\n");
            continue;
        }
        
        int ans=bfs();
        if (ans==-1)
            printf("-1");
        else
            print(ans);
        printf("\n");
    }
    return 0;
}
