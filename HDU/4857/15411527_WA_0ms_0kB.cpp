#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v[30010];
vector<int> ans;
int in[30010];
int out[30010];
bool vis[30010];
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
            in[i]=0;
            out[i]=0;
        }
        ans.clear();
        for (i=0;i<m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            in[y]++;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        for (i=1;i<=n;i++)
        {
            if (vis[i]==0&&in[i]==0)
            {
                vis[i]=1;
                ans.push_back(i);
                for (int j=0;j<v[i].size();j++)
                {
                    in[v[i][j]]--;
                }
                v[i].clear();
            }
        }
        for (i=0;i<ans.size()-1;i++)
            printf("%d ",ans[i]);
        printf("%d\n",ans[i]);
    }
    return 0;
}
