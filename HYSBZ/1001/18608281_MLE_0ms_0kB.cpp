/*
#include<bits/stdc++.h>
using namespace std;
const int maxn=1002*1002;
const int maxm=6*1005*1005;
const int INF=0x3f3f3f3f;
int e,head[maxn],cur[maxn],pre[maxn],d[maxn],vd[maxn];
int nexte[maxm],eu[maxm],ev[maxm],c[maxm];
void init(){e=0;memset(head,-1,sizeof(head));}
void addY(int u,int v,int w)
{
    eu[e]=u;ev[e]=v;c[e]=w;nexte[e]=head[u];head[u]=e++;
    eu[e]=v;ev[e]=u;c[e]=0;nexte[e]=head[v];head[v]=e++;
}
void addW(int u,int v,int w)
{
    eu[e]=u;ev[e]=v;c[e]=w;nexte[e]=head[u];head[u]=e++;
    eu[e]=v;ev[e]=u;c[e]=w;nexte[e]=head[v];head[v]=e++;
}
int sap(int s,int t ,int n)
{
    int i,u;
    memset(d,0,sizeof(d));
    memset(vd,0,sizeof(vd));
    vd[0]=n;
    cur[u=s]=head[s];
    pre[s]=-1;
    int temp,ans=0;
    while(d[s]<n)
    {
        if(u==t)
        {
            for(temp=INF,i=pre[u];~i;i=pre[eu[i]])
             temp=min(temp,c[i]);
            for(i=pre[u];~i;i=pre[eu[i]])
            {
                 c[i]-=temp;c[i^1]+=temp;
            }
            ans+=temp; u=s;
        }
        for(i=cur[u];~i;i=nexte[i])
        {
            if(c[i]>0&&d[u]==d[ev[i]]+1)
            {
                cur[u]=i;
                pre[u=ev[i]]=i;
                break;
            }
        }
        if(i==-1)
        {
            cur[u]=head[u];
            if(--vd[d[u]]==0) break;
            vd[++d[u]]++;
            if(u!=s) u=eu[pre[u]];
        }
    }
    return ans;
}
int main()
{
    init();
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++){
        for (int j=1;j<m;j++){
            int w;scanf("%d",&w);
            addW((i-1)*m+j,(i-1)*m+j+1,w);
        }
    }
    for (int i=1;i<n;i++){
        for (int j=1;j<=m;j++){
            int w;scanf("%d",&w);
            addW((i-1)*m+j,i*m+j,w);
        }
    }
    for (int i=1;i<n;i++){
        for (int j=1;j<m;j++){
            int w;scanf("%d",&w);
            addW((i-1)*m+j,i*m+j+1,w);
        }
    }
    printf("%d\n",sap(1,n*m,n*m+1));
    return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=1e18;
struct Graph
{
    struct Vertex
    {
        vector<int> o;
    };
    struct Edge:pair<int,int>
    {
        ll cap;
    };
    vector<Vertex> v;
    vector<Edge> e;
    Graph(int n):v(n){}
    void add(const Edge &ed)
    {
        v[ed.first].o.push_back(e.size());
        e.push_back(ed);
    }
};
struct ISAP:Graph
{
	ll flow;
	vector<ll> f;
	vector<int> h,cur,gap;
	ISAP(int n):Graph(n) {}
	void addY(Edge ed)
	{
		Graph::add(ed);
		swap(ed.first,ed.second),ed.cap=0;
		Graph::add(ed);
	}
	void addW(Edge ed)
	{
	    Graph::add(ed);
		swap(ed.first,ed.second);
		Graph::add(ed);
	}
	ll dfs(int s,int u,int t,ll r)
	{
		if(r==0||u==t)return r;
		ll _f,_r=0;
		for(int &i=cur[u],k; i<v[u].o.size(); ++i)
			if(k=v[u].o[i],h[u]==h[e[k].second]+1)
			{
				_f=dfs(s,e[k].second,t,min(r-_r,e[k].cap-f[k]));
				f[k]+=_f,f[k^1]-=_f,_r+=_f;
				if(_r==r||h[s]>=v.size())return _r;
			}
		if(!--gap[h[u]])h[s]=v.size();
		return ++gap[++h[u]],cur[u]=0,_r;
	}
	void ask(int s,int t)
	{
		h.assign(v.size(),0);
		cur.assign(v.size(),0);
		gap.assign(v.size()+2,0);
		for(deque<int> q(h[t]=gap[t]=1,t); !q.empty(); q.pop_front())
			for(int i=0,u=q.front(),k,to; i<v[u].o.size(); ++i)
				if(to=e[v[u].o[i]].second,!h[to])
					++gap[h[to]=h[u]+1],q.push_back(to);///加了快一点点
		for(f.assign(e.size(),flow=0); h[s]<v.size();)
			flow+=dfs(s,s,t,INF);
	}
};
void insert(ISAP &g,int u,int v,int w)
{
    Graph::Edge ed;
    ed.first=u;ed.second=v;ed.cap=w;
    g.addW(ed);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    ISAP g(n*m+1);

    for (int i=1;i<=n;i++){
        for (int j=1;j<m;j++){
            int w;scanf("%d",&w);
            insert(g,(i-1)*m+j,(i-1)*m+j+1,w);
        }
    }
    for (int i=1;i<n;i++){
        for (int j=1;j<=m;j++){
            int w;scanf("%d",&w);
            insert(g,(i-1)*m+j,i*m+j,w);
        }
    }
    for (int i=1;i<n;i++){
        for (int j=1;j<m;j++){
            int w;scanf("%d",&w);
            insert(g,(i-1)*m+j,i*m+j+1,w);
        }
    }
    g.ask(1,n*m);
    printf("%lld\n",g.flow);
    return 0;
}
