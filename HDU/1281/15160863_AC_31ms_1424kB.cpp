#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int mmp[120][120];
int nxt[120];
int vis[120];
int a[220];
int b[220];
bool getx(int x)
{
    int i;
    for (i=1; i<=m; i++)
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
    int T=1;
    while (scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
        int i,j;
        memset(mmp,0,sizeof(mmp));
        memset(nxt,0,sizeof(nxt));
        for (i=0; i<k; i++)
        {
            int x,y;
            scanf("%d%d",&a[i],&b[i]);
            mmp[a[i]][b[i]]=1;
        }
        int ans=0;
        int cc=0;
        for (i=1; i<=n; i++)
        {
            memset(vis,0,sizeof(vis));
            if (getx(i))
                ans++;
        }
        for (i=0; i<k; i++)
        {
            memset(nxt,0,sizeof(nxt));
            mmp[a[i]][b[i]]=0;
            int kk=0;
            for (j=1; j<=n; j++)
            {
                memset(vis,0,sizeof(vis));
                if (getx(j))
                    kk++;
            }
            mmp[a[i]][b[i]]=1;
            if (kk<ans) cc++;
        }
        printf("Board %d have %d important blanks for %d chessmen.\n",T++,cc,ans);
    }
    return 0;
}
