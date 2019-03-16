#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > v[1000006];
long long ans[1000006];
void dfs(int now,int sum)
{
    ans[now]=sum;
    for (int i=0;i<v[now].size();i++)
    {
        int u=v[now][i].first;
        int w=v[now][i].second;
        dfs(u,sum+w);
    } 
}
int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        for (int i=0;i<=n;i++) v[i].clear();
    for (int i=0;i<m;i++)
    {
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
        v[x].push_back({y,w});
    }
    dfs(1,0);
    long long tmp=0;
    for (int i=1;i<=n;i++) tmp+=ans[i];
    printf("%lld\n",tmp);
    }
    return 0;
}