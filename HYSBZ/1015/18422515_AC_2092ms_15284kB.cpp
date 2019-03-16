#include<bits/stdc++.h>
using namespace std;
const int maxn=400090;
int pre[maxn];
int op[maxn];
int aaa[maxn];
bool vis[maxn];
vector<int> v[maxn];
int getx(int x)
{
    if (pre[x]==x) return x;
    return pre[x]=getx(pre[x]);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=0;i<=n;i++) pre[i]=i;
    for (int i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        x++;
        y++;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    int k;
    scanf("%d",&k);
    for (int i=0;i<k;i++)
    {
        scanf("%d",&op[i]);
        op[i]++;
        vis[op[i]]=1;
    }
    int ans=n-k;
    for (int i=1;i<=n;i++)
    {
        if (vis[i]==0)
        {
            for (int j=0;j<v[i].size();j++)
            {
                int u=v[i][j];
                if (vis[u]) continue;
                int xx=getx(i);
                int yy=getx(u);
                if (xx!=yy)
                {
                    ans--;
                    pre[xx]=yy;
                }
            }
        }
    }
    for (int i=k-1;i>=0;i--)
    {
        aaa[i]=ans;
        int q=op[i];
        vis[op[i]]=0;
        ans++;
        int flag=0;
        for (int j=0;j<v[q].size();j++)
            {
                int u=v[q][j];
                if (vis[u]) continue;
                int xx=getx(q);
                int yy=getx(u);
                if (xx!=yy)
                {
                    ans--;
                    pre[xx]=yy;
                }
            }

    }
    printf("%d\n",ans);
    for(int i=0;i<k;i++)
        printf("%d\n",aaa[i]);
    return 0;
}
