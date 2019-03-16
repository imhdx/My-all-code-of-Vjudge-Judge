#include<bits/stdc++.h>

using namespace std;

vector<int> v[200000];
int k;
int minn=200000;
struct note
{
    int num;
    int s;
}que[200010];
int vis[200010];
void bfs(int k)
{
    int tou=0;
    int wei=0;
    que[wei].num=k;
    que[wei].s=1;
    wei++;
    while (tou<wei)
    {
        int i;
        for (i=0;i<v[que[tou].num].size();i++)
        {

            if (vis[v[que[tou].num][i]]==1) continue;
            que[wei].num=v[que[tou].num][i];
            que[wei].s=que[tou].s+1;
            vis[v[que[tou].num][i]]=1;
            wei++;
            if (v[que[wei-1].num].size()==0)
            {
                minn=min(minn,que[wei-1].s);
            }
        }
        tou++;
    }
}
int main()
{
    int n,m;
    scanf("%d%d%d",&n,&k,&m);
    int i;
    for (i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        v[y].push_back(x);
    }
    vis[k]=1;
    bfs(k);
    printf("%d\n",minn);

    return 0;
}
