#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<cstring>
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
vector<int> st;
vector<int> la;
vector<int> len;
int main()
{
    int n,p,t;
    scanf("%d%d%d",&n,&p,&t);
    for (int i=0;i<p;i++){
        int x,y,l;
        scanf("%d%d%d",&x,&y,&l);
        st.push_back(x);
        la.push_back(y);
        len.push_back(l);
    }
    int l=0;
    int r=1000000;
    int ans=-1;
    while (l<=r){
        int mid=l+r>>1;
        ISAP g(n+1);
        for (int i=0;i<st.size();i++)
        {
            if (len[i]<=mid)///最小化（t条不相交的最短路中最长的那段路）
                            ///二分使得我们要找的那条路不加到图中，这样就无法找到那t条路
            {
                insert(g,st[i],la[i],1);
                insert(g,la[i],st[i],1);
            }
        }
        g.ask(1,n);///最大流保证t条路不相交，因为每条路经只有流量1，只能走一次
        if (g.flow>=t)
        {
            ans=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    printf("%d\n",ans);
    return 0;
}
