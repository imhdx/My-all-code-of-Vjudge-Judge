#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
bool check[maxn];
int pri[maxn];
int tot=0;
void init()
{
    tot=0;
    for (int i=2;i<maxn;i++)
    {
        if (check[i]==0)
        {
            pri[tot++]=i;
            for (long long j=1ll*i*i;j<maxn;j+=i)
                check[j]=1;
        }
    }
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,d;
        scanf("%d%d",&n,&d);
        int ans=0;
        for (int i=0;1ll*pri[i]*d<=n&&i<tot;i++)
        {
            ans++;
            if (d%pri[i]==0) break;
        }
        printf("%d\n",ans);
    }
    return 0;
}
