#include<bits/stdc++.h>
using namespace std;

int n,m;
int mmp[310][310];
int nxt[310];
int vis[310];
bool getx(int x)
{
    int i;
    for (i=1;i<=m;i++)
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
        memset(mmp,0,sizeof(mmp));
        memset(nxt,0,sizeof(nxt));
        for (i=1;i<=n;i++)
        {
            int cnt;
            scanf("%d",&cnt);
            for (j=1;j<=cnt;j++)
            {
                int x;
                scanf("%d",&x);
                mmp[i][x]=1;
            }
        }
        int ans=0;
        for (i=1;i<=n;i++)
        {
            memset(vis,0,sizeof(vis));
            if (getx(i)) ans++;
        }
        if (ans==n)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
