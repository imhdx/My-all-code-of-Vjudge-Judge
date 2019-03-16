#include<cstdlib>
#include<cstring>
#include<cmath>
#include<stdio.h>
using namespace std;
int n;
bool pri(int n)
{
    if (n<2) return false;
    for (int i=2;i<=(int)sqrt(n);i++)
    {
        if (n%i==0) return false;
    }
    return true;
}
int vis[30];
int aa[30];
int ans=0;
void dfs(int num,int last)
{
    if (num==n+1)
    {
        if (pri(last+1))
        {
            ans++;
            for (int i=1;i<n;i++)
                printf("%d ",aa[i]);
            printf("%d\n",aa[n]);
        }
        return ;
    }
    int i;
    for (i=2;i<=n;i++)
    {
        if (!pri(i+last)) continue;
        if (vis[i]) continue;
        vis[i]=1;
        aa[num]=i;
        dfs(num+1,i);
        vis[i]=0;
    }
}
int main()
{
    int cnt=1;
    while (scanf("%d",&n)!=EOF)
    {
        printf("Case %d:\n",cnt++
               );
        memset(vis,0,sizeof(vis));
        ans=0;
        vis[1]=1;
        aa[1]=1;
        dfs(2,1);
        printf("\n");
    }

    return 0;
}
