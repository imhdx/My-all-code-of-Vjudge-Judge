#include<bits/stdc++.h>
using namespace std;
int ans[100005];
bool vis[100005];
int a[100005];
int cnt=0;
int gethas(int x)
{
    long long tmp=x*x%100005;
    x=(1ll*x*x%100005+5416ll*x%100005)%100005;
    return x;
}
int main()
{
    int T;scanf("%d",&T);
    while (T--)
    {
        memset(vis,0,sizeof(vis));
        cnt=0;
        int n;scanf("%d",&n);
        for (int i=0;i<n;i++) scanf("%d",&a[i]);
        for (int i=0;i<n;i++)
        {
            if (vis[gethas(a[i])]==0)
                ans[cnt++]=a[i];
            vis[gethas(a[i])]=1;

        }
        for (int i=0;i<cnt;i++)
            printf("%d%c",ans[i]," \n"[i==cnt-1]);

    }
    return 0;
}
