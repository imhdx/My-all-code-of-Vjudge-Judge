#include<bits/stdc++.h>
using namespace std;
const int N=1000010,INF=2147483647;
struct E{int to,flow,back;};
vector<E> edge[N];
int n,m,s,t,d[N],l[N],v[N],num[N];
priority_queue<pair<int,int> > Q;
inline void push(int x){Q.push(make_pair(d[x],x));}
inline int hlpp(int s,int t)
{
	d[s]=n;l[s]=INF;v[s]=1;push(s);num[0]=n-1;
	while(!Q.empty())
	{
		int x=Q.top().second;Q.pop();
		if(!l[x]||x==t)continue;
		vector<E>&e=edge[x];
		for(int i=0;i<edge[x].size()&&l[x];i++)if(e[i].flow&&(x==s||d[x]==d[e[i].to]+1))
		{
			int tmp=min(e[i].flow,l[x]);if(!tmp)continue;
			if(x!=s)l[x]-=tmp;l[e[i].to]+=tmp;e[i].flow-=tmp;edge[e[i].to][e[i].back].flow+=tmp;
			if(e[i].to!=s&&!v[e[i].to])v[e[i].to]=1,push(e[i].to);
		}
		if(x!=s&&l[x])
		{
			if(!--num[d[x]])
			{
				int a=d[x];
				for(int i=1;i<=n;i++)if(d[i]>=a&&i!=s&&i!=t)d[i]=n,l[i]=0;
				continue;
			}
			int tmp=n;
			for(int i=0;i<edge[x].size();i++)if(e[i].flow)tmp=min(tmp,d[e[i].to]+1);
			num[d[x]=tmp]++;
			push(x);
		}
		v[x]=0;
	}
	return l[t];
}
void insertY(int u,int v,int w)
{
    edge[u].push_back((E){v,w,edge[v].size()});
    edge[v].push_back((E){u,0,edge[u].size()-1});
}
void insertW(int u,int v,int w)
{
    edge[u].push_back((E){v,w,edge[v].size()});
    edge[v].push_back((E){u,w,edge[u].size()-1});
}
int main()
{
    scanf("%d%d",&n,&m);
    s=1;t=n*m;
	for (int i=1;i<=n;i++){
        for (int j=1;j<m;j++){
            int w;scanf("%d",&w);
            insertW((i-1)*m+j,(i-1)*m+j+1,w);
        }
    }
    for (int i=1;i<n;i++){
        for (int j=1;j<=m;j++){
            int w;scanf("%d",&w);
            insertW((i-1)*m+j,i*m+j,w);
        }
    }
    for (int i=1;i<n;i++){
        for (int j=1;j<m;j++){
            int w;scanf("%d",&w);
            insertW((i-1)*m+j,i*m+j+1,w);
        }
    }
    n*=m;
	printf("%d\n",hlpp(s,t));
	return 0;
}
