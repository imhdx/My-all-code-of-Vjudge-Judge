#include<bits/stdc++.h>
using namespace std;
int a[220][220];
int vis[220];
int nxt[220];
int n;
bool getx(int x)
{
    for (int i=1;i<=n;i++){
        if (a[x][i]&&vis[i]==0){
            vis[i]=1;
            if (nxt[i]==0||getx(nxt[i])){
                nxt[i]=x;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int T;scanf("%d",&T);
    while (T--){
        memset(nxt,0,sizeof(nxt));
        scanf("%d",&n);
        int ans=0;
        for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) scanf("%d",&a[i][j]);
        for (int i=1;i<=n;i++){
            memset(vis,0,sizeof(vis));
            if (getx(i))
                ans++;
        }
        if (ans==n){
            printf("Yes\n");
        }
        else printf("No\n");


    }
    return 0;
}
