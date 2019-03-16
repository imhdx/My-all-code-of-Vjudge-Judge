#include<bits/stdc++.h>
using namespace std;
int n,m;
int mmp[200][200];
int vis[200];
int nxt[200];
bool getx(int x)
{
    int i,j;
    for (i=1; i<=m; i++)
    {
        if (mmp[x][i]&&vis[i]==0)
        {
            vis[i]=1;
            if (nxt[i]==0||getx(nxt[i]))
            {
                nxt[i]=x;
                return true;
            }
        }
    }
    return false;
}


int main()
{
    while (scanf("%d",&n)!=EOF&&n)
    {
        scanf("%d",&m);
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
