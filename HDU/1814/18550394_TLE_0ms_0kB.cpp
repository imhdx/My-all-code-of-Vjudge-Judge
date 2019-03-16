#include<bits/stdc++.h>
using namespace std;
const int maxn=20020;
const int maxm=100010;
struct edge
{
    int to,next;
}edge[maxn];
int head[maxn],tot;
void init()
{
    tot=0;
    memset(head,-1,sizeof(head));
}
void ins(int u,int v)
{
    edge[tot].to=v;edge[tot].next=head[u];head[u]=tot++;
}
bool vis[maxn];;
int s[maxn],top;
bool dfs(int u)
{
    if (vis[u^1]) return false;
    if (vis[u]) return true;
    vis[u]=true;
    s[top++]=u;
    for (int i=head[u];i!=-1;i=edge[i].next){
        if (!dfs(edge[i].to))
            return false;
    }
    return true;
}
bool twosat(int n)
{
    memset(vis,0,sizeof(vis));
    for (int i=0;i<n;i+=2){
        if (vis[i]||vis[i^1]) continue;///一对夫妻中有选中的
        top=0;///初始化栈
        if (!dfs(i)){
            while (top) vis[s[--top]]=false;///如果选i无法满足条件，那么选了i后一定选的那些，后面不一定选，需要重置为0
            if (!dfs(i^1)) return false;
        }
    }
    return true;
}
int main()
{
    int n,m;
    int u,v;
    while (scanf("%d%d",&n,&m)!=EOF){
        init();
        while (m--){
            scanf("%d%d",&u,&v);
            u--;v--;
            ins(u,v^1);
            ins(v,u^1);
        }
        if (twosat(2*n)){
            for (int i=0;i<2*n;i++)
                if (vis[i])
                    printf("%d\n",i+1);
        }
        else printf("NIE\n");
    }
    return 0;
}
