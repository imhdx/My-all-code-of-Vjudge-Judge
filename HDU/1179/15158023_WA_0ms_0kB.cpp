#include<bits/stdc++.h>
using namespace std;
int n,m;
int mmp[110][110];
int vis[110];
int nxt[110];
bool getx(int x)
{
    int i,j;
    for (i=1; i<=m; i++)
    {
        if (mmp[x][i]&&!vis[i])
        {
            vis[i]=1;
            if (nxt[i]==0||getx(nxt[i]))
            {
                nxt[x]=i;
                return true;
            }
        }
    }
    return false;
}


int main()
{
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        int i,j;
        memset(mmp,0,sizeof(mmp));
        memset(nxt,0,sizeof(nxt));
        for (i=1; i<=m; i++)
        {
            int t;
            scanf("%d",&t);
            for (j=1; j<=t; j++)
            {
                int x;
                scanf("%d",&x);
                mmp[x][i]=1;
            }
        }
        int ans=0;
        for (i=1; i<=n; i++)
        {
            memset(vis,0,sizeof(vis));
            if (getx(i))
                ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
