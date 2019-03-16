#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int ans;
int n;
int a[1000];
int vis[100];
bool dfs(int len,int num)
{
    if (num>=n&&len==0)
        return true;
    int last=-1;
    for (int i=n-1;i>=0;i--)
    {
        if (vis[i]||a[i]==last)
            continue;
        vis[i]=1;
        if (len+a[i]==ans)
        {
            if (dfs(0,num+1))
                return true;
            else
                last=a[i];
        }
        else if (len+a[i]<ans)
        {
            if (dfs(len+a[i],num+1))
                return true;
            else last=a[i];
        }
        vis[i]=0;
        if (len==0)
            break;
    }
    return false;
}
int main()
{
    while (scanf("%d",&n)!=EOF&&n)
    {
        memset(vis,0,sizeof(vis));
        int i;
        int sum=0;
        for (i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        sort(a,a+n);
        for (ans=a[n-1];ans<=sum;ans++)
        {
            if (sum%ans==0&&dfs(0,0))
                break;
        }
        printf("%d\n",ans);
    }
    return 0;
}
