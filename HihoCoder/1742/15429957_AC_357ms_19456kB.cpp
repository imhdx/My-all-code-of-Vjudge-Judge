#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
vector<int> v[100010];
int pre[100010];
int node[100010];
int son[100010];
int n;
void dfs1(int fa,int now)
{
    int i;
    node[now]=1;
    for (i=0;i<v[now].size();i++)
    {
        int u=v[now][i];
        if (u==fa) continue;
        dfs1(now,u);
        node[now]+=node[u];///指now为根的子树有多少个节点(含now节点)
        son[now]+=son[u]+node[u];///指now为根的子树各节点到now的距离之和
    }
}
void dfs2(int fa,int now)
{
    int i;
    for (i=0;i<v[now].size();i++)
    {
        int u=v[now][i];
        if (u==fa) continue;
        son[u]=son[now]-node[u]+n-node[u];
        dfs2(now,u);
    }
}
int main()
{
    scanf("%d",&n);
    int i,j;
    for (i=0;i<=n;i++) pre[i]=i;
    for (i=0;i<n-1;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs1(0,1);
    dfs2(0,1);
    for (i=1;i<=n;i++)
        printf("%d%c",son[i],'\n');
    return 0;
}
