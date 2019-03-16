#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>

using namespace std;
int in[30010];
vector<int> v[30010];
vector<int> ans;
int que[40010];
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
            in[y]++;
            v[x].push_back(y);
        }
        int tou=0;
        int wei=0;
        for (i=1;i<=n;i++)
        {
            if (in[i]==0)
            {
                que[wei++]=i;
            }
        }
        while (tou<wei)
        {
            sort(que+tou,que+wei);
            ans.push_back(que[tou]);
            for (i=0;i<v[que[tou]].size();i++)
            {
                in[v[que[tou]][i]]--;
                if (in[v[que[tou]][i]]==0)
                    que[wei++]=v[que[tou]][i];
            }
            tou++;
        }
        printf("%d",ans[0]);
        for (i=1;i<ans.size();i++)
            printf(" %d",ans[i]);
        printf("\n");
    }

    return 0;
}
