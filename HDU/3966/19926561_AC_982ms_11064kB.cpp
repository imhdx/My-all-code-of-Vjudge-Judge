#include<bits/stdc++.h>
///HDU-3966
using namespace std;
int n,m,p,cnt;
int a[50010],bit[50010];
vector<int> edge[50010];
int son[50010],sz[50010],top[50010],pos[50010],fa[50010],deep[50010];
void add(int x,int val)
{
    while (x<=n)
    {
        bit[x]+=val;
        x+=x&(-x);
    }
}
int sum(int x)
{
    int ans=0;
    while (x>0)
    {
        ans+=bit[x];
        x-=x&(-x);
    }
    return ans;
}
void dfs1(int x)
{
    sz[x]=1;son[x]=0;
    for (int i=0;i<edge[x].size();i++)
    {
        int y=edge[x][i];
        if (y==fa[x]) continue;
        fa[y]=x;deep[y]=deep[x]+1;
        dfs1(y);
        sz[x]+=sz[y];
        if (sz[y]>=sz[son[x]]) son[x]=y;
    }
}
void dfs2(int x,int now_top)
{
    pos[x]=++cnt;top[x]=now_top;
    if (son[x]) dfs2(son[x],now_top);
    for (int i=0;i<edge[x].size();i++)
    {
        int y=edge[x][i];
        if (y!=fa[x]&&y!=son[x]) dfs2(y,y);
    }
}
void update(int x,int y,int z)///将x-y的链分成了如下区间
{
    while (top[x]!=top[y])
    {
        if (deep[top[x]]<deep[top[y]]) swap(x,y);
        /// 区间 pos[top[x]],pos[x]
        add(pos[top[x]],z);add(pos[x]+1,-z);
        x=fa[top[x]];
    }
    if (deep[x]<deep[y]) swap(x,y);
    /// 区间 pos[y],pos[x]
    add(pos[y],z);add(pos[x]+1,-z);
}
int main()
{
    while (scanf("%d%d%d",&n,&m,&p)!=EOF)
    {
        cnt=0;
        for (int i=0;i<=n;i++) edge[i].clear();
        memset(son,0,sizeof(son));
        memset(bit,0,sizeof(bit));
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        for (int i=1;i<n;i++)
        {
            int x,y;scanf("%d%d",&x,&y);
            edge[x].push_back(y);
            edge[y].push_back(x);
        }
        dfs1(1);
        dfs2(1,1);
        for (int i=1;i<=n;i++) /// 节点i对应在数据结构
                               /// 上的下标为pos[i]
        {
            add(pos[i],a[i]);
            add(pos[i]+1,-a[i]);
        }
        char op[10];
        while (p--)
        {
            scanf("%s",op);
            if (op[0]=='I')
            {
                int x,y,z;
                scanf("%d%d%d",&x,&y,&z);
                update(x,y,z);
            }
            else if (op[0]=='D')
            {
                int x,y,z;
                scanf("%d%d%d",&x,&y,&z);
                update(x,y,-z);
            }
            else if (op[0]=='Q')
            {
                int x;scanf("%d",&x);
                printf("%d\n",sum(pos[x]));
            }
        }
    }
    return 0;
}