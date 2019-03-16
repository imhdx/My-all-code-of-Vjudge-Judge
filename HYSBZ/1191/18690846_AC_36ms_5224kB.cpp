#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1003][1003];
//a[m][n]
bool vis[1003];
int nxt[1003];
bool dfs(int now)
{
    for (int i=1;i<=n;i++)
    {
        if (!vis[i]&&a[now][i]){
            vis[i]=1;
            if (nxt[i]==0||dfs(nxt[i])){
                nxt[i]=now;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        a[i][x+1]=1;
        a[i][y+1]=1;
    }
    int ans=0;
    memset(nxt,0,sizeof(nxt));
    for (int i=1;i<=m;i++)
    {
        memset(vis,0,sizeof(vis));
        if (dfs(i)) ans++;
        else break;
    }
    printf("%d\n",ans);
    return 0;
}
