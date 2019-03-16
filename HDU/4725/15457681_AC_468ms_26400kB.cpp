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
    for(int i=1; i<=n; i++) dist[i]=INF;
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
        if(vis[u]) continue;
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
int lay[100010];
bool viss[100010];

int main()
{
    int T;
    int t=1;
    scanf("%d",&T);
    while (T--)
    {
        int n,m,c;
        scanf("%d%d%d",&n,&m,&c);
        int i,j;
        for (i=0;i<=3*n;i++)
        {
            E[i].clear();
        }
        for (i=0;i<=n;i++)
        {
            lay[i]=0;
            viss[i]=0;
        }
        for (i=1;i<=n;i++)
        {
            scanf("%d",&lay[i]);
            viss[lay[i]]=1;
        }
        for (i=2;i<=n;i++)
        {
            if (viss[i-1]&&viss[i])
            {
                addedge(i-1+n,i+n,c);
                addedge(i+n,i-1+n,c);
            }
        }
        for (i=1;i<=n;i++)
        {
            //addedge(n+lay[i],i,0);
            addedge(i,n+lay[i],0);
            if (lay[i]>1) addedge(n+lay[i]-1,i,c);
            if (lay[i]<n) addedge(n+lay[i]+1,i,c);
        }
        for (i=1;i<=m;i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            addedge(u,v,w);
            addedge(v,u,w);
        }
        Dijkstra(3*n,1);
        printf("Case #%d: ",t++);
        if (dist[n]>=INF) printf("-1\n");
        else
            printf("%d\n",dist[n]);
    }
    return 0;
}
