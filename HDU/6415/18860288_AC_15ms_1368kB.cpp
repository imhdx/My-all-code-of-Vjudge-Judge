#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int ans=1;
        int n,m,mod;scanf("%d%d%d",&n,&m,&mod);
        for (int i=1;i<=n;i++) ans=1ll*ans*i%mod;
        for (int i=1;i<=m;i++) ans=1ll*ans*i%mod;
        for (int i=n+m;i<=n*m;i++) ans=1ll*ans*i%mod;
        printf("%d\n",ans);
    }
    return 0;
}
