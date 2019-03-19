#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int maxn=10000;
const int maxm=100000;
const int inf=2147483647;
struct Edge
{
    int to,next,cap,flow,cost;
}edge[maxm];
int head[maxn],tol;
int pre[maxn],dis[maxn];
bool vis[maxn];
int N;///节点总个数，节点编号从0~N-1
void init(int n)
{
    N=n;
    tol=0;
    memset(head,-1,sizeof(head));
}
void addedge(int u,int v,int cap,int cost)///单向边
{
    edge[tol].to=v;
    edge[tol].cap=cap;
    edge[tol].cost=cost;
    edge[tol].flow=0;
    edge[tol].next=head[u];
    head[u]=tol++;
    edge[tol].to=u;
    edge[tol].cap=0;
    edge[tol].cost=-cost;
    edge[tol].flow=0;
    edge[tol].next=head[v];
    head[v]=tol++;
}
bool spfa(int s,int t)
{
    queue<int> q;
    for (int i=0;i<N;i++){
        dis[i]=inf;
        vis[i]=0;
        pre[i]=-1;
    }
    dis[s]=0;
    vis[s]=1;
    q.push(s);
    while (!q.empty())
    {
        int u=q.front();
        q.pop();
        vis[u]=0;
        for (int i=head[u];i!=-1;i=edge[i].next){
            int v=edge[i].to;
            if (edge[i].cap>edge[i].flow&&dis[v]>dis[u]+edge[i].cost){
                dis[v]=dis[u]+edge[i].cost;
                pre[v]=i;
                if (!vis[v]){
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
    }
    if (pre[t]==-1) return 0;
    return 1;
}
///返回的是最大流，cost存的是最小费用
int minCostMaxflow(int s,int t,int &cost)
{
    int flow=0;
    cost=0;
    while (spfa(s,t)){
        int minn=inf;
        for (int i=pre[t];i!=-1;i=pre[edge[i^1].to]){
            if (minn>edge[i].cap-edge[i].flow)
                minn=edge[i].cap-edge[i].flow;
        }
        for (int i=pre[t];i!=-1;i=pre[edge[i^1].to]){
            edge[i].flow+=minn;
            edge[i^1].flow-=minn;
            cost+=edge[i].cost*minn;
        }
        flow+=minn;
    }
    return flow;
}
/*
signed main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    init(n+1);
    for (int i=0;i<m;i++)
    {
        int s,t,f,c;
        scanf("%d%d%d%d",&s,&t,&f,&c);
        addedge(s,t,f,c);///加单向边
    }
    int cost;
    int ans=minCostMaxflow(1,n,cost);
    printf("%d %d\n",ans,cost);
    return 0;
}
*/
struct ac
{
    int s,t,w,op;
}que[maxm];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m,k,W;scanf("%d%d%d%d",&n,&m,&k,&W);
        init(2*m+5);
        int SS=2*m+2,TT=2*m+3;
        for (int i=1;i<=m;i++) scanf("%d%d%d%d",&que[i].s,&que[i].t,&que[i].w,&que[i].op);
        addedge(SS,0,k,0);
        addedge(2*m+1,TT,k,0);
        for (int i=1;i<=m;i++)
        {
            addedge(0,i,1,0);
            addedge(i+m,2*m+1,1,0);
            addedge(i,i+m,1,-que[i].w);
            for (int j=1;j<=m;j++)
            {
                if (que[i].t<=que[j].s)
                {
                    if (que[i].op==que[j].op) addedge(i+m,j,inf,W);
                    else addedge(i+m,j,inf,0);
                }
            }
        }
        int cost;
        minCostMaxflow(SS,TT,cost);
        printf("%d\n",-cost);
    }
    return 0;
}
