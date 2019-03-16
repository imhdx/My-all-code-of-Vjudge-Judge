#include<bits/stdc++.h>
using namespace std;
int n;
int ji[602][603];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int vis[602*2];
int mmp[602*2][602*2];
char a[602][602];
int nxt[602*2];
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
    int T;
    scanf("%d",&T);
    int t=1;
    while (T--)
    {

        //int n;
        memset(ji,0,sizeof(ji));
        memset(nxt,0,sizeof(nxt));
        memset(ji,0,sizeof(ji));
        memset(mmp,0,sizeof(mmp));
        scanf("%d",&n);
        getchar();
        int i,j;
        for (i=0;i<n;i++)
            scanf("%s",a[i]);
        cnt=1;
        for (i=0;i<n;i++)
            for (j=0;j<n;j++)
                if (a[i][j]=='#')
                    ji[i][j]=cnt++;
        int ccc=0;
        for (i=0;i<n;i++)
            for (j=0;j<n;j++)
                if (a[i][j]=='#')
                {
                    for (int k=0;k<4;k++)
                    {
                        int tx=i+dx[k];
                        int ty=j+dy[k];
                        if (tx<0||tx>=n||ty<0||ty>=n) continue;
                        if (ji[tx][ty]==0) continue;
                        mmp[ji[i][j]][ji[tx][ty]]=1;
                        ccc++;
                    }
                }
        int ans=0;
        for (i=1;i<cnt;i++)
        {
            memset(vis,0,sizeof(vis));
            if (getx(i))
                ans++;
        }
        printf("Case %d: ",t++);
        printf("%d\n",ans/2);
    }
    return 0;
}
