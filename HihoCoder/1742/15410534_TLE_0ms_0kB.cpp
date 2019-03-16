#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<stack>
#include<iostream>
#include<map>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> v[100010];
long long int ans=0;
int tou;
struct node
{
    int x;
    long long s=0;
} que[100010];
bool vis[100010];
void bfs(int last,int x)
{
    int tou=0,wei=0;
    que[wei].x=x;
    que[wei].s=0;
    wei++;
    while (tou<wei)
    {
        //printf("hi\n");
        //printf("last=%d x=%d\n",last,que[tou].x);
        for (int i=0; i<v[que[tou].x].size(); i++)
        {
            if (vis[v[que[tou].x][i]]==0&&v[que[tou].x][i]!=last)
            {
                vis[v[que[tou].x][i]]=1;
                que[wei].x=v[que[tou].x][i];
                que[wei].s=que[tou].s+1;
                wei++;
                ans+=que[wei-1].s;
            }
        }
        last=que[tou].x;
        tou++;
    }
}
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        int i,j;
        for (i=0;i<=n;i++) v[i].clear();
        for (i=0; i<n-1; i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
        }
        for (i=1; i<=n; i++)
        {
            memset(vis,0,sizeof(vis));
            ans=0;
            tou=i;
            vis[i]=1;
            bfs(0,i);
            printf("%lld\n",ans);
        }
    }
    return 0;
}
