#include<bits/stdc++.h>
using namespace std;
int n,m;
int ji[1111][1111];
int vis[1111];
int mmp[1111][1111];
int nxt[1111];
int cnt;
bool getx(int x)
{
    int i;
    for (i=1;i<cnt;i++)
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
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        if (n==0&&m==0) break;
        memset(ji,0,sizeof(ji));
        memset(nxt,0,sizeof(nxt));
        memset(mmp,0,sizeof(mmp));
        int i,j;
        cnt=1;
        for (i=0;i<n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            if (ji[x][y]==0)
            {
                ji[x][y]=cnt++;
            }
            if (ji[x+1][y]==0)
            {
                ji[x+1][y]=cnt++;
            }
            mmp[ji[x+1][y]][ji[x][y]]=1;
            mmp[ji[x][y]][ji[x+1][y]]=1;
        }
        for (i=0;i<m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            if (ji[x][y]==0)
            {
                ji[x][y]=cnt++;
            }
            if (ji[x][y+1]==0)
            {
                ji[x][y+1]=cnt++;
            }
            mmp[ji[x][y+1]][ji[x][y]]=1;
            mmp[ji[x][y]][ji[x][y+1]]=1;
        }
        int ans=0;
        for (i=1;i<cnt;i++)
        {
            memset(vis,0,sizeof(vis));
            if (getx(i))
                ans++;
        }
        printf("%d\n",ans/2);
    }
    return 0;
}

