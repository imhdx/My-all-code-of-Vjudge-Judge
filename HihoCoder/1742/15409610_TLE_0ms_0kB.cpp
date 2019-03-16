#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<stack>
#include<iostream>
#include<map>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> v[100010];
long long int ans=0;
int tou;
void dfs(int last,int x,long long int sum)
{
    ans+=sum;
    if (x!=tou&&v[x].size()==1)
    {
        return ;
    }
    for (int i=0;i<v[x].size();i++)
    {
        if (v[x][i]==last) continue;
        dfs(x,v[x][i],sum+1);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int i,j;
    for (i=0;i<n-1;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (i=1;i<=n;i++)
    {
        ans=0;
        tou=i;
        dfs(0,i,0);
        printf("%lld\n",ans);
    }

    return 0;
}
