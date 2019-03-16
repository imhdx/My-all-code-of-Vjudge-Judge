#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v[30010];
vector<int> ans;
bool vis[30010];
bool dfs(int u)
{
    vis[u]=-1;
    for (int i=0;i<v[u].size();i++)
    {
        if (vis[v[u][i]]<0) return false;
        else if (!vis[v[u][i]]&&!dfs(v[u][i]))
            return true;
    }
    vis[u]=1;
    ans.push_back(u);
    return true;
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        int i,j;
        for (i=0;i<=n;i++)
        {
            vis[i]=0;
            v[i].clear();
        }
        ans.clear();
        for (i=0;i<m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            v[y].push_back(x);
        }
        for (int i=1;i<=n;i++)
        {
            if (!vis[i]) dfs(i);
        }
        printf("%d",ans[0]);
        for (i=1;i<ans.size();i++)
            printf(" %d",ans[i]);
        printf("\n");
    }
    return 0;
}
