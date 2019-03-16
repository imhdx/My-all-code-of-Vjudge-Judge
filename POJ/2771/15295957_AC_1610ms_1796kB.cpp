#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<queue>
#include<stack>
#include<string>
using namespace std;
int n;
struct point
{
    int l;
    string sex;
    string music;
    string sport;
}q[506];
int vis[506];
int nxt[506];
int mmp[506][506];
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
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        int i;
        int j,k;
        for (i=1;i<=n;i++)
        {
            for (j=1;j<=n;j++)
                mmp[i][j]=0;
            nxt[i]=0;
        }
        for (i=1;i<=n;i++)
        {
            cin>>q[i].l>>q[i].sex>>q[i].music>>q[i].sport;
        }
        for (i=1;i<=n;i++)
        {
            for (j=1;j<=n;j++)
            {
                if (!(abs(q[i].l-q[j].l)>40||q[i].sex==q[j].sex||q[i].music!=q[j].music||q[i].sport==q[j].sport))
                    mmp[i][j]=1;
            }
        }
        int ans=0;
        for (i=1;i<=n;i++)
        {
            memset(vis,0,sizeof(vis));
            if (getx(i)) ans++;
        }
        printf("%d\n",n-ans/2);

    }
    return 0;
}
