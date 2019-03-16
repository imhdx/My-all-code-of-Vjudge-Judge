#include<bits/stdc++.h>
using namespace std;
bool vis[52];
int nxt[52];
int a[52][52];
int n,m;
bool getx(int x)
{
    for (int i=0;i<m;i++)
    {
        if (!vis[i]&&a[x][i])
        {
            vis[i]=1;
            if (nxt[i]==-1||getx(nxt[i]))
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
    int t=1;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&n,&m);
        memset(a,0,sizeof(a));
        memset(nxt,-1,sizeof(nxt));
        int i,j;
        for (i=0;i<n;i++)
        {
            for (j=0;j<m;j++)
            {
                int x;
                scanf("%1d",&x);
                if (x==0)
                    a[i][j]=1;
            }
        }
        int ans=0;
        for (int i=0;i<n;i++)
        {
            memset(vis,0,sizeof(vis));
            if (getx(i))
                ans++;
        }
        printf("Case %d: ",t++);
        printf("%d\n",n+m-ans);
    }
    return 0;
}
