#include<bits/stdc++.h>
using namespace std;

int n,m;
int mmp[150][150];
int nxt[150];
int vis[150];
bool getx(int x)
{
    int i;
    for (i=1;i<=n;i++)
    {
        if (mmp[x][i]&&!vis[i])
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
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&n,&m);
        int i;
        int j;
        for (i=0;i<=n;i++)
        {
            for (j=0;j<=n;j++)
                mmp[i][j]=0;
            nxt[i]=0;
        }
        for (i=0;i<m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            mmp[x][y]=1;
        }
        int ans=n;
        for (i=1;i<=n;i++)
        {
            memset(vis,0,sizeof(vis));
            if (getx(i)) ans--;
        }
        printf("%d\n",ans);
    }
    return 0;
}
