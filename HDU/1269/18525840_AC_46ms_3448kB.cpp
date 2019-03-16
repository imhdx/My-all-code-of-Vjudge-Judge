#include<bits/stdc++.h>
using namespace std;
const int maxn=10010;
const int maxm=100010;
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
int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF){
        if (n==0&&m==0) return 0;
        init();
        for (int i=0;i<m;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            ins(u,v);
        }
        solve(n);
        if (scc==1) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
