#include<bits/stdc++.h>
using namespace std;
int m;
int ans;
int a[20];
int b[20];
int aa[20];
int bb[20];
bool vis[20];
void dfs(int t,int num)
{
    if (t>m) return ;
    if (num>=m/2)
    {
        int cnt=0;
        for (int i=1;i<=num;i++)
        {
            for (int j=i+1;j<=num;j++)
            {
                if (aa[i]*bb[j]==aa[j]*bb[i])
                    cnt++;
            }
        }
        ans=max(ans,cnt);
        return ;
    }
    if (vis[t]) dfs(t+1,num);
    else
    {
        for (int i=1;i<=m;i++)
        {
            if (vis[i]||t==i) continue;
            vis[i]=vis[t]=1;
            aa[num+1]=a[i]-a[t];
            bb[num+1]=b[i]-b[t];
            dfs(t+1,num+1);
            vis[i]=vis[t]=0;
        }
    }
}
int main()
{
    while (scanf("%d",&m)!=EOF)
    {
        memset(vis,0,sizeof(vis));
        for (int i=1;i<=m;i++)
        {
            scanf("%d%d",&a[i],&b[i]);
        }
        ans=0;
        dfs(1,0);
        printf("%d\n",ans);
    }

    return 0;
}
