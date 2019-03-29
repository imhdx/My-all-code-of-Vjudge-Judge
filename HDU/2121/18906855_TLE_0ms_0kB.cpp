#include<bits/stdc++.h>
using namespace std;
const int inf=INT_MAX;
const int maxn=1010;
const int maxm=40010;
struct Edge
{
    int u,v,cost;
};
Edge edge[maxm];
int pre[maxn],id[maxn],visit[maxn],in[maxn];
int ROOT=-1;
int zhuliu(int root,int n,int m,Edge edge[])
{
    int res=0,u,v;
    while (1)
    {
        for (int i=0;i<n;i++) in[i]=inf;
        for (int i=0;i<m;i++)
        {
            if (edge[i].u!=edge[i].v&&edge[i].cost<in[edge[i].v])
            {
                pre[edge[i].v]=edge[i].u;
                in[edge[i].v]=edge[i].cost;
            }
        }
        for (int i=0;i<n;i++)
            if (i!=root&&in[i]==inf)
            return -1;
        int tn=0;
        memset(id,-1,sizeof(id));
        memset(visit,-1,sizeof(visit));
        in[root]=0;
        for (int i=0;i<n;i++)
        {
            res+=in[i];
            v=i;
            while (visit[v]!=i&&id[v]==-1&&v!=root)
            {
                visit[v]=i;
                v=pre[v];
            }
            if (v!=root&&id[v]==-1)
            {
                for (int u=pre[v];u!=v;u=pre[u])
                    id[u]=tn;
                id[v]=tn++;
            }
        }
        if (tn==0) break;
        for (int i=0;i<n;i++)
            if (id[i]==-1)
            id[i]=tn++;
        for (int i=0;i<m;)
        {
            v=edge[i].v;
            edge[i].u=id[edge[i].u];
            edge[i].v=id[edge[i].v];
            if (edge[i].u!=edge[i].v)
                edge[i++].cost-=in[v];
            //else swap(edge[i],edge[--m]);
        }
        n=tn;
        root=id[root];
    }
    return res;
}
int g[maxn][maxn];
int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        for (int i=0;i<=n;i++)
            for (int j=0;j<=n;j++)
            g[i][j]=inf;
        int u,v,cost;
        int sum=0;
        while (m--)
        {
            scanf("%d%d%d",&u,&v,&cost);
            if (u==v) continue;
            sum+=cost;
            g[u][v]=min(g[u][v],cost);
        }
        sum++;
        //printf("sum=%d\n",sum);
        ///  n是虚拟的
        for (int i=0;i<n;i++)
        {
            g[n][i]=sum;
        }

        int L=0;
        for (int i=0;i<=n;i++)
        {
            for (int j=0;j<=n;j++)
            {
                if (g[i][j]<inf)
                {
                    edge[L].u=i;
                    edge[L].v=j;
                    edge[L++].cost=g[i][j];
                }
            }
        }

        //for (int i=0;i<L;i++) printf("%d %d %d\n",edge[i].u,edge[i].v,edge[i].cost);
        int ans=zhuliu(n,n+1,L,edge);
        //printf("ans=%d\n",ans);
        if (ans>=2*sum) printf("impossible\n\n");
        else{
            for (int i=0;i<n;i++)
            {
                if (pre[i]==n)
                {
                    ROOT=i;
                    break;
                }
            }
            printf("%d %d\n\n",ans-sum,ROOT);
        }

    }

    return 0;
}
