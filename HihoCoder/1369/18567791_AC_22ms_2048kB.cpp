#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=1e9+7;
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
	void add(Edge ed)
	{
		Graph::add(ed);
		swap(ed.first,ed.second),ed.cap=0;
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
		/*for(deque<int> q(h[t]=gap[t]=1,t); !q.empty(); q.pop_front())
			for(int i=0,u=q.front(),k,to; i<v[u].o.size(); ++i)
				if(to=e[v[u].o[i]].second,!h[to])
					++gap[h[to]=h[u]+1],q.push_back(to);*////加了快一点点
		for(f.assign(e.size(),flow=0); h[s]<v.size();)
			flow+=dfs(s,s,t,INF);
	}
};
void insert(ISAP &g,int u,int v,int w)
{
    Graph::Edge ed;
    ed.first=u;ed.second=v;ed.cap=w;
    g.add(ed);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    ISAP g(n+1);
    for (int i=0;i<m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        insert(g,u,v,w);
    }
    g.ask(1,n);
    printf("%lld\n",g.flow);
    return 0;
}
