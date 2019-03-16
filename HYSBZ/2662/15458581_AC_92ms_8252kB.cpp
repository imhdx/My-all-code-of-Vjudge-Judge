///Dijkstra 算法 + 堆优化
///使用优先队列优化，复杂度 O (E log E)
/*
 * 使用优先队列优化 Dijkstra 算法
 * 复杂度 O(ElogE)
 * 注意对 vector<Edge>E[MAXN] 进行初始化后加边
*/
#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int MAXN=300010;
struct qnode
{
    int v;
    int c;
    qnode(int _v=0,int _c=0):v(_v),c(_c) {}
    bool operator <(const qnode &r)const
    {
        return c>r.c;
    }
};
struct Edge
{
    int v,cost;
    Edge(int _v=0,int _cost=0):v(_v),cost(_cost) {}
};
vector<Edge>E[MAXN];
bool vis[MAXN];
int dist[MAXN];
//点的编号从 1 开始
void Dijkstra(int n,int start)
{
    memset(vis,false,sizeof(vis));
    for(int i=1; i<=n; i++)
        dist[i]=INF;
    priority_queue<qnode>que;
    while(!que.empty())
        que.pop();
    dist[start]=0;
    que.push(qnode(start,0));
    qnode tmp;
    while(!que.empty())
    {
        tmp=que.top();
        que.pop();
        int u=tmp.v;
        if(vis[u])
            continue;
        vis[u]=true;
        for(int i=0; i<E[u].size(); i++)
        {
            int v=E[tmp.v][i].v;
            int cost=E[u][i].cost;
            if(!vis[v]&&dist[v]>dist[u]+cost)
            {
                dist[v]=dist[u]+cost;
                que.push(qnode(v,dist[v]));
            }
        }
    }
}
void addedge(int u,int v,int w)
{
    E[u].push_back(Edge(v,w));
}

int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    int i,j;
    for (i=0; i<=(k+1)*n; i++)
    {
        E[i].clear();
    }
    for (i=1; i<=m; i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        addedge(u,v,w);
        addedge(v,u,w);
        for (j=1;j<=k;j++)
        {
            addedge(u+j*n,v+j*n,w);
            addedge(v+j*n,u+j*n,w);
            addedge(u+(j-1)*n,v+j*n,w>>1);
            addedge(v+(j-1)*n,u+j*n,w>>1);
        }
    }
    Dijkstra((k+1)*n,1);
    int ans=INF;
    for (i=0;i<=k;i++)
    {
        ans=min(ans,dist[n+i*n]);
    }
    printf("%d\n",ans);
    return 0;
}

