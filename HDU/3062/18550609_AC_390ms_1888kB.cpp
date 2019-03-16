#include<bits/stdc++.h>
using namespace std;
const int maxn=2010;
const int maxm=2000100;
struct edge
{
    int to,next;
}edge[maxm];
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
            int a1,a2,c1,c2;
            scanf("%d%d%d%d",&a1,&a2,&c1,&c2);
            ins(2*a1+c1,2*a2+(c2^1));
            ins(2*a2+c2,2*a1+(c1^1));
        }
        if (twosat(2*n)){
            printf("YES\n");
        }
        else printf("NO\n");
    }
    return 0;
}
