#include<cstdio>
#include<cstring>
using namespace std;
int sz,t[100010][12];
bool vis[100010];
bool insert(char str[])
{
    int flag=0;
    int len=strlen(str),now=0;
    for (int i=0;i<len;i++)
    {
        int k=str[i]-'0';
        if (t[now][k]==0) t[now][k]=++sz;
        now=t[now][k];
        if (vis[now]) flag=1;
    }
    if (vis[now]!=0) flag=1;
    vis[now]=1;///标记此节点为某一个串的结尾
    return flag;
}
char str[20];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        memset(vis,0,sizeof(vis));
        sz=0;
        memset(t,0,sizeof(t));
        int n;
        scanf("%d",&n);
        int flag=0;
        for (int i=0;i<n;i++)
        {
            scanf("%s",str);
            flag|=insert(str);
        }
        if (flag) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
