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
double ans=0;
vector<int> v[100010];
void dfs(int last,int x,double p,double sum)
{
    if (v[x].size()==1)
    {
        ans+=sum*p;
        return ;
    }
    if (x==1)
        p=p/v[x].size();
    else
        p=p/(v[x].size()-1);
    for (int i=0;i<v[x].size();i++)
    {
        if (v[x][i]==last) continue;
        dfs(x,v[x][i],p,sum+1);
    }
}
int main()
{
    int i,j;
    int n;
    scanf("%d",&n);
    for (i=0;i<n-1;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(0,1,1,0);
    printf("%.10f\n",ans);
    return 0;
}
