#include<bits/stdc++.h>

using namespace std;
int n,m;
int vis[30][30];
vector<pair<int,int>> v;
int dx[]={-1,1,-2,2,-2,2,-1,1};
int dy[]={-2,-2,-1,-1,1,1,2,2};
int flag=0;
void dfs(int x,int y,int s)
{
    if (flag==1) return ;
    if (s==n*m)
    {
        flag=1;
        for (int i=0;i<v.size();i++)
        {
            printf("%c%d",v[i].second+'A',v[i].first+1);
        }
        printf("\n\n");
        return ;
    }
    int i;
    for (i=0;i<8;i++)
    {
        int tx=x+dx[i];
        int ty=y+dy[i];
        if (tx<0||tx>=n||ty<0||ty>=m) continue;
        if (vis[tx][ty]==1) continue;
        vis[tx][ty]=1;
        v.push_back(make_pair(tx,ty));
        dfs(tx,ty,s+1);
        vis[tx][ty]=0;
        if (flag==1) return ;
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    int kkk=1;
    while (t--)
    {
        flag=0;
        memset(vis,0,sizeof(vis));
        scanf("%d%d",&n,&m);
        printf("Scenario #1%d:\n",kkk++);
        v.clear();
        v.push_back(make_pair(0,0));
        vis[0][0]=1;
        dfs(0,0,1);
        if (flag==0)
        printf("impossible\n\n");
    }
    return 0;
}
