
#include<bits/stdc++.h>
using namespace std;
const int maxn=10010;
const int maxm=50010;
const int INF=1e9+7;
struct Edge
{
    int to,next;
}edge[maxm];
int head[maxn],tot;
int low[maxn],dfn[maxn],Stack[maxn],belong[maxn];
int index,top;
int scc;
bool instack[maxn];
int num[maxn];
void ins(int u,int v)
{
    edge[tot].to=v;edge[tot].next=head[u];head[u]=tot++;
}
void targan(int u)
{
    int v;
    low[u]=dfn[u]=++index;
    Stack[top++]=u;
    instack[u]=1;
    for (int i=head[u];i!=-1;i=edge[i].next){
        v=edge[i].to;
        if (!dfn[v]){
            targan(v);
            low[u]=min(low[u],low[v]);
        }
        else if (instack[v])
            low[u]=min(low[u],dfn[v]);
    }
    if (low[u]==dfn[u]){
        scc++;
        do{
            v=Stack[--top];
            instack[v]=0;
            belong[v]=scc;
            num[scc]++;
        }
        while (v!=u);
    }
}
void solve(int n)
{
    memset(dfn,0,sizeof(dfn));
    memset(instack,0,sizeof(instack));
    memset(num,0,sizeof(num));
    index=scc=top=0;
    for (int i=1;i<=n;i++)
        if (!dfn[i])
        targan(i);
}
void init()
{
    tot=0;
    memset(head,-1,sizeof(head));
}
int out[maxn];
void rebuild(int n)
{
    memset(out,0,sizeof(out));
    for (int u=1;u<=n;u++){
        for (int i=head[u];i!=-1;i=edge[i].next){
            int v=edge[i].to;
            if (belong[u]!=belong[v]){
                out[belong[u]]++;
            }
        }
    }
}
int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF){
        init();
        for (int i=0;i<m;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            ins(u,v);
        }
        solve(n);

        rebuild(n);
        long long aaa=0;
        int cc=0;
        for (int i=1;i<=scc;i++){
            if (out[i]==0){
                cc++;
                aaa=num[i];
            }
        }
        if (cc!=1)
            printf("0\n");
        else printf("%lld\n",aaa);
    }
    return 0;
}
