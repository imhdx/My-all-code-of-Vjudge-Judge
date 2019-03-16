#include<bits/stdc++.h>
using namespace std;
char str[60][3];
bool vis[60];
vector<int> v[60];
int flag;
int n;
void dfs(int num,int fa,int now)
{
    if (flag==1)
        return ;
    if (num==n-1)
    {
        flag=1;
        return ;
    }
    for (int i=0; i<v[now].size(); i++)
    {
        if (flag==1)
            return ;
        int u=v[now][i];
        if (u==fa)
            continue;
        if (vis[u])
            continue;
        vis[u]=1;
        dfs(num+1,now,u);
        vis[u]=0;
    }
}
int main()
{
    while (scanf("%d",&n)!=EOF)
    {
        //memset(vis,0,sizeof(vis));
        for (int i=0; i<n; i++)
            scanf("%s",str[i]);
        for (int i=0;i<60;i++) v[i].clear();
        for (int i=0; i<n; i++)
        {
            for (int j=i+1; j<n; j++)
            {
                if (str[i][0]==str[j][0]||str[i][1]==str[j][1])
                {
                    v[i].push_back(j);
                    v[j].push_back(i);
                }
            }
        }
        flag=0;
        for (int i=0; i<n; i++)
        {
            memset(vis,0,sizeof(vis));
            vis[i]=1;
            dfs(0,-1,i);
            if (flag==1) break;
        }
        if (flag==1)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
