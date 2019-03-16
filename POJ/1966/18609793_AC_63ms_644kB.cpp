#include<set>
#include<map>
#include<cmath>
#include<ctime>
#include<queue>
#include<cstdio>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define mod 1000000007
#define inf 1000000000
#define pi acos(-1)
#define ll long long
using namespace std;
int n,m,S,T,cnt;
struct edge{
	int to,next,v;
}e[5005];
int last[105],q[205],h[205],u[5005],v[5005];
void init()
{
    cnt=1;memset(last,0,sizeof(last));
}
void insertY(int u,int v,int w)
{
	e[++cnt]=(edge){v,last[u],w};last[u]=cnt;
	e[++cnt]=(edge){u,last[v],0};last[v]=cnt;
}
void insertW(int u,int v,int w)
{
    e[++cnt]=(edge){v,last[u],w};last[u]=cnt;
	e[++cnt]=(edge){u,last[v],w};last[v]=cnt;
}
bool bfs()
{
	int head=0,tail=1;
	q[0]=S;memset(h,-1,sizeof(h));
	h[S]=0;
	while(head!=tail)
	{
		int now=q[head];head++;
		for(int i=last[now];i;i=e[i].next)
			if(e[i].v&&h[e[i].to]==-1)
			{
				h[e[i].to]=h[now]+1;
				q[tail++]=e[i].to;
			}
	}
	return h[T]!=-1;
}
int dfs(int x,int f)
{
	if(x==T)return f;
	int w,used=0;
	for(int i=last[x];i;i=e[i].next)
		if(h[e[i].to]==h[x]+1)
		{
			w=dfs(e[i].to,min(e[i].v,f-used));
			e[i].v-=w;e[i^1].v+=w;
			used+=w;if(used==f)return f;
		}
	if(!used)h[x]=-1;
	return used;
}
int dinic()
{
	int ans=0;
	while(bfs())ans+=dfs(S,inf);
	return ans;
}
int xx[5005];
int yy[5005];
void build(int x,int y)
{
    init();
    ///点内 从i->i+n
    ///点外 x->(i ->  i+n)->y
    insertY(S,x,inf);
    insertY(y+n,T,inf);
    for (int i=0;i<n;i++)
    {
        if (x==i||y==i){
            insertY(i,i+n,inf);
        }
        else{
            insertY(i,i+n,1);
        }
    }
    for (int i=0;i<m;i++){
        insertY(xx[i]+n,yy[i],inf);
        insertY(yy[i]+n,xx[i],inf);
    }
}
int main()
{
    while (scanf("%d%d",&n,&m)!=EOF){
        S=2*n;T=2*n+1;
        for (int i=0;i<m;i++){
            scanf(" (%d,%d)",&xx[i],&yy[i]);
            if (xx[i]>yy[i]) swap(xx[i],yy[i]);
        }
        int minn=inf;
        for (int i=0;i<n;i++){
            for (int j=i+1;j<n;j++){
                build(i,j);
                minn=min(minn,dinic());
            }
        }
        if (minn==inf) printf("%d\n",n);
        else printf("%d\n",minn);
    }
    return 0;
}
