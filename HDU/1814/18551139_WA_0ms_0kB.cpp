#include<bits/stdc++.h>
using namespace std;
const int maxn=16010;
const int maxm=40010;
struct Edge
{
    int to,next;
}edge[maxm];
int head[maxn],tot;
int low[maxn],dfn[maxn],Stack[maxn],belong[maxn];
int pos,top;
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
    low[u]=dfn[u]=++pos;
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
    pos=scc=top=0;
    for (int i=1;i<=n;i++)
        if (!dfn[i])
        targan(i);
}
void init()
{
    tot=0;
    memset(head,-1,sizeof(head));
}
int ans[maxn];
bool cmp1()
{

}
int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF){
        init();
        for (int i=0;i<m;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            ins(u,((v-1)^1)+1);
            ins(v,((u-1)^1)+1);
        }
        solve(2*n);
        int flag=0;
        if (belong[1]<belong[2]){
            for (int i=1;i<=n;i++){
                if (belong[i*2]==belong[i*2-1]){
                    flag=1;
                    break;
                }
                else if (belong[i*2]>belong[i*2-1]){
                    ans[i]=i*2-1;
                }
                else ans[i]=i*2;
            }
        }
        else{
            for (int i=1;i<=n;i++){
                if (belong[i*2]==belong[i*2-1]){
                    flag=1;
                    break;
                }
                else if (belong[i*2]<belong[i*2-1]){
                    ans[i]=i*2-1;
                }
                else ans[i]=i*2;
            }
        }
        if (flag) printf("NIE\n");
        else{
            for (int i=1;i<=n;i++){
                printf("%d\n",ans[i]);
            }
        }
    }
    return 0;
}
