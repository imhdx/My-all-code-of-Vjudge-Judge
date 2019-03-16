#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int in[30010];
vector<int> v[30010];
vector<int> ans;
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
            in[i]=0;
            v[i].clear();
        }
        ans.clear();
        for (i=0;i<m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            in[x]++;
            v[y].push_back(x);
        }
        int tou=0;
        int wei=0;
        priority_queue<int> que;
        for (i=1;i<=n;i++)
        {
            if (in[i]==0)
            {
                que.push(i);
            }
        }
        while (!que.empty())
        {
            ans.push_back(que.top());
            for (i=0;i<v[que.top()].size();i++)
            {
                in[v[que.top()][i]]--;
                if (in[v[que.top()][i]]==0)
                    que.push(v[que.top()][i]);
            }
            que.pop();
        }
        for (i=ans.size()-1;i>0;i--)
            printf("%d ",ans[i]);
        printf("%d\n",ans[0]);
    }

    return 0;
}
