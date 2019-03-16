#include<bits/stdc++.h>
using namespace std;
int mmp[503][503];
int nxt[503];
int vis[503];
int n;
bool getx(int x)
{
    int i;
    for (i=1;i<=n;i++)
    {
        if (!vis[i]&&mmp[x][i])
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
    int m;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        if (n==0&&m==0) return 0;
        int i,j;
        for (i=1;i<=n;i++)
        {
            for (j=1;j<=n;j++)
                mmp[i][j]=0;
            nxt[i]=0;
        }
        for (i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            mmp[x][y]=1;
        }
        int k;
        for (i=1;i<=n;i++)
        {
            for (j=1;j<=n;j++)
            {
                for (k=1;k<=n;k++)
                {
                    if (mmp[i][k]&&mmp[k][j])
                    {
                        mmp[i][j]=1;
                        break;
                    }
                }
            }
        }
        int ans=0;
        for (i=1;i<=n;i++)
        {
            memset(vis,0,sizeof(vis));
            if (getx(i)) ans++;
        }
        printf("%d\n",n-ans);
    }

    return 0;
}
