#include<bits/stdc++.h>
using namespace std;
const int maxn=110;///点数
const int maxm=20*110;///边数
int head[maxn],cnt;
struct edge
{
    int to,next,w;
}edge[maxm];
void ins(int u,int v,int w)
{
    edge[++cnt].to=v;
    edge[cnt].w=w;
    edge[cnt].next=head[u];
    head[u]=cnt;
}
void init()
{
    cnt=0;
    memset(head,-1,sizeof(head));
}
bool flag[25][102];///flag[i][j] i号码头，在第j天是否可以访问
int n,m;///n天，m个码头
int k,e;///每次改变花费k元，e条路径
const int INF=1e9+7;
bool vis[25];
int dist[maxn];
struct qnode
{
    int v,c;///dis[v]=c;
    qnode(int _v=0,int _c=0):v(_v),c(_c){}
    bool operator<(const qnode &r)const{
        return c>r.c;
    }
};
int dij(int st,int la) ///从第st天到la天，从1-m的最短路
{
    memset(dist,0x3f,sizeof(dist));
    memset(vis,0,sizeof(vis));
    for (int i=1;i<=m;i++){
        for (int j=st;j<=la;j++){
            if (flag[i][j]) vis[i]=1;
        }
    }
    //for (int i=1;i<=m;i++) dist[i]=INF;///m个码头
    priority_queue<qnode> que;
    while (!que.empty()) que.pop();
    dist[1]=0;
    que.push(qnode(1,0));
    qnode tmp;
    while (!que.empty()){
        tmp=que.top();que.pop();
        int u=tmp.v;
        if (vis[u]) continue;
        vis[u]=true;
        for (int i=head[u];i!=-1;i=edge[i].next){
            int v=edge[i].to;
            int w=edge[i].w;
            if (!vis[v]&&dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                que.push(qnode(v,dist[v]));
            }
        }
    }
    return dist[m];
}
long long t[maxn][maxn];
long long dp[102];
int main()
{
    init();
    scanf("%d%d%d%d",&n,&m,&k,&e);
    for (int i=0;i<e;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        ins(u,v,w);
        ins(v,u,w);
    }
    int p;scanf("%d",&p);
    for (int i=0;i<p;i++){
        int a,b,c;scanf("%d%d%d",&a,&b,&c);
        for (int j=b;j<=c;j++)
            flag[a][j]=1;
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            t[i][j]=dij(i,j);
        }
    }
    for (int i=1;i<=n;i++)
    {
        dp[i]=t[1][i]*i;
        for (int j=0;j<i;j++){
            dp[i]=min(dp[i],dp[j]+t[j+1][i]*(i-j)+k);
        }
    }
    printf("%lld\n",dp[n]);
    return 0;
}
