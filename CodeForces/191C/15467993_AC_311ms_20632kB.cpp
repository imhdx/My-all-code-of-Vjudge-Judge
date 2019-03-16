#include<bits/stdc++.h>
using namespace std;
int pre[100010];
vector<int> v[100010];
map<pair<int,int>,int> M;
vector<int> cha[100010];
bool vis[100010];
int ans[100010];
int aaa[100010];
int getx(int x){if (pre[x]==x)return x;return pre[x]=getx(pre[x]);}
void nian(int x,int y){int xx=getx(x),yy=getx(y);if(xx!=yy)pre[xx]=yy;}
void Tar(int fa,int now)
{
    //printf("2525\n");
    for (int i=0;i<v[now].size();i++)
    {
        int u=v[now][i];
        if (u==fa) continue;
        Tar(now,u);
        nian(u,now);
        vis[u]=1;
    }
    for (int i=0;i<cha[now].size();i++)
    {
        int u=cha[now][i];
        if (vis[u])
        {
            int root=getx(u);
            ans[root]-=2;
            ans[now]++;
            ans[u]++;
        }
    }
}
int dfs(int fa,int now)
{
    for (int i=0;i<v[now].size();i++)
    {
        int u=v[now][i];
        if (u==fa) continue;
        dfs(now,u);
        ans[now]+=ans[u];
    }
    //printf("%d %d %d\n",fa,now,ans[now]);
    if (fa!=0) aaa[M[{fa,now}]]=ans[now];
}
int main()
{
    int n;
    scanf("%d",&n);
    int i,j;
    for (i=0;i<n-1;i++)
    {
        pre[i]=i;
        int x,y;
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        M[{x,y}]=i;
        v[y].push_back(x);
        M[{y,x}]=i;
    }
    pre[n-1]=n-1;
    pre[n]=n;
    int m;
    scanf("%d",&m);
    while (m--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        cha[x].push_back(y);
        cha[y].push_back(x);
    }
    //printf("123\n");
    Tar(0,1);
    //printf("hi\n");

    dfs(0,1);
    for (int i=0;i<n-1;i++)
        printf("%d%c",aaa[i]," \n"[i==n-2]);
    return 0;
}
