#include<stdio.h>
int map[200010];
int k;
int ans=0;
void dfs(int x)
{
    if (x==k)
    {
        ans++;
        return ;
    }
    if (map[x]==x) return ;
    dfs(map[x]);
    return ;
}
int main()
{
    int n;
    int m;
    while (scanf("%d%d%d",&n,&k,&m)!=EOF)
    {
        ans=0;
        int i;
        for (i=1;i<=n;i++)
        {
            map[i]=i;
        }
        for (i=0;i<m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            map[x]=y;
        }
        for (i=1;i<=n;i++)
        {
            dfs(i);
        }
        printf("%d\n",ans);
    }
    return 0;
}
