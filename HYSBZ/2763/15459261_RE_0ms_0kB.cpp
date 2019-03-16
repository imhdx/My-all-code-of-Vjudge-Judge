/*
///Dijkstra 算法 + 堆优化
///使用优先队列优化，复杂度 O (E log E)
/*
 * 使用优先队列优化 Dijkstra 算法
 * 复杂度 O(ElogE)
 * 注意对 vector<Edge>E[MAXN] 进行初始化后加边

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
    for(int i=0; i<=n; i++)///注意此处是从0开始还是1开始！！
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
    int st,la;
    scanf("%d%d",&st,&la);
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
            addedge(u+(j-1)*n,v+j*n,0);
            addedge(v+(j-1)*n,u+j*n,0);
        }
    }
    Dijkstra((k+1)*n,st);
    int ans=INF;
    for (i=0;i<=k;i++)
    {
        ans=min(ans,dist[la+i*n]);
    }
    printf("%d\n",ans);
    return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;
#define MAXN 60
#define MAXM 1010
#define INF 1e9
struct node
{
    int begin,end,value,next;
}edge[MAXM*MAXN*4];
int cnt,Head[MAXN*MAXN],N,U[MAXM],V[MAXM],VAL[MAXM],dis[MAXN*MAXN],Heap[MAXN*MAXN],pos[MAXN*MAXN],SIZE;
void addedge(int bb,int ee,int vv)
{
    edge[++cnt].begin=bb;edge[cnt].end=ee;edge[cnt].value=vv;edge[cnt].next=Head[bb];Head[bb]=cnt;
}
void addedge1(int bb,int ee,int vv)
{
    addedge(bb,ee,vv);addedge(ee,bb,vv);
}
int read()
{
    int s=0,fh=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')fh=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){s=s*10+(ch-'0');ch=getchar();}
    return s*fh;
}
void Push1(int k)
{
    int now=k,root;
    while(now>1)
    {
        root=now/2;
        if(dis[Heap[root]]<=dis[Heap[now]])return;
        swap(Heap[root],Heap[now]);
        swap(pos[Heap[root]],pos[Heap[now]]);
        now=root;
    }
}
void Insert(int k)
{
    Heap[++SIZE]=k;pos[k]=SIZE;Push1(SIZE);
}
void Pop1(int k)
{
    int now,root=k;
    pos[Heap[k]]=0;Heap[1]=Heap[SIZE--];if(SIZE>0)pos[Heap[k]]=k;
    while(root<=SIZE/2)
    {
        now=root*2;
        if(now<SIZE&&dis[Heap[now+1]]<dis[Heap[now]])now++;
        if(dis[Heap[root]]<dis[Heap[now]])return;
        swap(Heap[root],Heap[now]);
        swap(pos[Heap[root]],pos[Heap[now]]);
        root=now;
    }
}
void dijkstra(int start)
{
    int i,u,v;
    for(i=0;i<=N;i++)dis[i]=INF;dis[start]=0;
    for(i=0;i<=N;i++)Insert(i);
    while(SIZE>0)
    {
        u=Heap[1];Pop1(pos[u]);
        for(i=Head[u];i!=-1;i=edge[i].next)
        {
            v=edge[i].end;
            if(dis[v]>dis[u]+edge[i].value){dis[v]=dis[u]+edge[i].value;Push1(pos[v]);}
        }
    }
}
int main()
{
    int n,m,k,i,j,MN;
    n=read();m=read();k=read();
    int st=read(),la=read();
    for(i=1;i<=m;i++)
    {
        U[i]=read();V[i]=read();VAL[i]=read();
    }
    memset(Head,-1,sizeof(Head));cnt=1;
    N=(k+1)*n;
    for(i=0;i<=k;i++)
    {
        for(j=1;j<=m;j++)addedge1(i*n+U[j],i*n+V[j],VAL[j]);
        if(i!=k)
        {
            for(j=1;j<=m;j++){addedge(i*n+U[j],(i+1)*n+V[j],0);addedge(i*n+V[j],(i+1)*n+U[j],0);}
        }
    }
    dijkstra(st);
    MN=INF;
    for(i=0;i<=k;i++)MN=min(MN,dis[i*n+la]);
    printf("%d",MN);
    return 0;
}
