#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t[100100][13];
bool vis[100100];
char str[20];
int sz=0;
bool insert(char str[])
{
    int flag=0;
    int now=0,len=strlen(str);
    for (int i=0;i<len;i++)
    {
        int k=str[i]-'0';
        if (t[now][k]==0) t[now][k]=++sz,flag=1;
        now=t[now][k];
        if (vis[now])
            return 1;
    }
    vis[now]=1;
    return flag^1;
}
int main()
{
    int T;scanf("%d",&T);
    while (T--)
    {
        int flag=0;
        int n;scanf("%d",&n);
        for (int i=0;i<n;i++)
        {
            scanf("%s",str);
            if (flag==0) flag=insert(str);
        }
        if (flag) printf("NO\n");
        else printf("YES\n");
    }

    return 0;
}
