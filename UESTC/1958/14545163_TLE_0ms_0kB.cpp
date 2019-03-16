#include<bits/stdc++.h>

using namespace std;

vector<int> v[200000];
int k;
int minn=200000;
void dfs(int x,int num)
{
    if (v[x].size()==0)
    {
        minn=min(minn,num);
    }
    int i=0;
    for (i=0;i<(v[x].size());i++)
    {
        dfs(v[x][i],num+1);
    }
}
int main()
{
    int n,m;
    scanf("%d%d%d",&n,&k,&m);
    int i;
    for (i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        v[y].push_back(x);
    }
    dfs(k,0);
    printf("%d\n",minn+1);

    return 0;
}
