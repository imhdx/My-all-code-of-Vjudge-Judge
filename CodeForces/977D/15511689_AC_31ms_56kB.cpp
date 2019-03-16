#include<bits/stdc++.h>
using namespace std;
long long int a[200];
long long int c[200];
bool vis[200];
int nxt[200];
int hhh[200];
bool mmp[200][200];
int n;
bool getx(int x)
{
    int i;
    for (i=1; i<=n; i++)
    {
        if (vis[i]==0&&mmp[x][i])
        {
            vis[i]=1;
            if (nxt[i]==0||getx(nxt[i]))
            {
                nxt[i]=x;
                hhh[x]=i;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    scanf("%d",&n);
    int i,j;
    for (i=1; i<=n; i++)
    {
        nxt[i]=0;
        for (j=1; j<=n; j++)
            mmp[i][j]=0;
        scanf("%lld",&a[i]);
    }
    for (i=1; i<=n; i++)
    {
        for (j=1; j<=n; j++)
        {
            if (i==j)
                continue;
            if (a[j]%2==0&&a[j]/2==a[i])
                mmp[i][j]=1;
            if (a[i]%3==0&&a[i]/3==a[j])
                mmp[i][j]=1;
        }
    }
    for (i=1; i<=n; i++)
    {
        memset(vis,0,sizeof(vis));
        getx(i);
    }
    for (i=1; i<=n; i++)
    {
        if (hhh[i])
            break;
    }
    int cnt;
    for (int j=1; j<=n; j++)
    {
        i=j;
        for (cnt=1; cnt<=n; cnt++)
        {
            if (i==0) break;
            c[cnt]=a[i];
            i=hhh[i];
        }
        if (cnt>n) break;
    }
    for (i=1;i<=n;i++)
        printf("%lld%c",c[i]," \n"[i==n]);
    return 0;
}
