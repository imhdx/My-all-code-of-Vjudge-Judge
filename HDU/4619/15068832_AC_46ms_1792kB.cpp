#include<bits/stdc++.h>
using namespace std;
int n,m;
int ji[104][103];
int vis[10010];
vector<int> v[10010];
int nxt[10010];
int cnt;
bool getx(int x)
{
    int i;
    for (i=0;i<v[x].size();i++)
    {
        if (vis[v[x][i]]==0)
        {
            vis[v[x][i]]=1;
            if (nxt[v[x][i]]==0||getx(nxt[v[x][i]]))
            {
                nxt[v[x][i]]=x;
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
        for (int i=0;i<10010;i++)
            v[i].clear();
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
            v[ji[x+1][y]].push_back(ji[x][y]);
            v[ji[x][y]].push_back(ji[x+1][y]);
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
            v[ji[x][y]].push_back(ji[x][y+1]);
            v[ji[x][y+1]].push_back(ji[x][y]);
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

