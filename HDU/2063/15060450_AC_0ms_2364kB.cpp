#include<bits/stdc++.h>
using namespace std;

int n,m;
int mmp[503][504];
int nxt[503];
int vis[503];
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
    while (scanf("%d",&T)!=EOF&&T!=0)
    {
        scanf("%d%d",&n,&m);
        int i;
        int j;
        memset(mmp,0,sizeof(mmp));
        memset(nxt,0,sizeof(nxt));
        for (i=0;i<T;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            mmp[x][y]=1;
        }
        int ans=0;
        for (i=1;i<=n;i++)
        {
            memset(vis,0,sizeof(vis));
            if (getx(i)) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
