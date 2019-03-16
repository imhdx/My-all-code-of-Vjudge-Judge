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
    for(i=1;i<=N;i++)dis[i]=INF;dis[start]=0;
    for(i=1;i<=N;i++)Insert(i);
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
            for(j=1;j<=m;j++){addedge(i*n+U[j],(i+1)*n+V[j],VAL[j]/2);addedge(i*n+V[j],(i+1)*n+U[j],VAL[j]/2);}
        }
    }
    dijkstra(1);
    MN=INF;
    for(i=0;i<=k;i++)MN=min(MN,dis[i*n+n]);
    printf("%d",MN);
    return 0;
}