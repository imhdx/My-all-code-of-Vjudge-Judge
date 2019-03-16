#include<vector>
#include<algorithm>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
using namespace std;
vector<int> v[1010];
int n;
int vis[1010];
int lu[1010];
int flag=0;
void dfs(int fi,int num)
{
    if (flag==1) return ;
    if (num==n)
    {
        flag=1;
        int i;
        for (i=0;i<n;i++)
            printf("%d ",lu[i]);
        printf("\n");
        return ;
    }
    for (int i=0;i<v[fi].size();i++)
    {
        if (vis[v[fi][i]]) continue;
        vis[v[fi][i]]=1;
        lu[num]=v[fi][i];
        dfs(v[fi][i],num+1);
        if (flag==1) return ;
         vis[v[fi][i]]=0;
    }

}
int main()
{
    flag=0;
    for (int i=0;i<1010;i++)
        v[i].clear();
    memset(vis,0,sizeof(vis));
    memset(lu,0,sizeof(lu));
    scanf("%d",&n);
    int j;
    getchar();
    for (int i=0;i<n;i++)
    {
        char str[1010];
        scanf("%s",str);
        for (j=0;str[j];j++)
        {
            if (i>j) continue;
            if (i==j) continue;
            if (str[j]=='+')
            {
                v[i].push_back(j);
            }
            else
                v[j].push_back(i);
        }
    }
    vis[0]=1;
    lu[0]=0;
    printf("YES\n");
    dfs(0,1);
    return 0;
}
