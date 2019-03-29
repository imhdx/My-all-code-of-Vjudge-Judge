#include<bits/stdc++.h>
using namespace std;
char buf[16 * 1024 * 1024 + 5]; // 10 MiB Buffer
int curpos = 0, iseof;
int read()
{
    int ret = 0;
    if (iseof) return 0;
    while (!('0' <= buf[curpos] && buf[curpos] <= '9'))
    {
        if (buf[curpos] == 0)
        {
            if (fgets(buf, 16 * 1024 * 1024, stdin) == NULL) iseof = true;
            curpos = 0;
            continue;
        }
        curpos++;
    }
    int flg = 0;
    if (curpos && buf[curpos - 1] == '-') flg = -1;
    else flg = 1;
    while ('0' <= buf[curpos] && buf[curpos] <= '9')
    {
        ret = ret * 10 + (buf[curpos] - '0');
        curpos++;
    }
    return ret * flg;
}
int cnt=0;
int head[200005];
int to[200005];
int _next[200005];
int tot=0;
void add(int u,int v)
{
    tot++;
    to[tot]=v;
    _next[tot]=head[u];
    head[u]=tot;
}
bool dfs(int x,int fa)
{
    int flag=0;
    for (int i=head[x];i!=-1;i=_next[i])
    {
        int u=to[i];
        if (u==fa) continue;
        if (dfs(u,x)==0) flag=1;
    }
    cnt+=flag;
    return flag;
}
int main()
{
    int T;
    T=read();
    while (T--)
    {
        tot=0;
        memset(head,-1,sizeof(head));
        int n,m,a;
        n=read();
        m=read();
        for (int i=1;i<n;i++)
        {
            a=read();
            add(a,i+1);
            add(i+1,a);
        }
        cnt=0;
        dfs(1,-1);
        //printf("%d\n",cnt);
        if (2*cnt>=m) printf("%d\n",(m+1)/2);
        else printf("%d\n",cnt+m-2*cnt);
    }
    return 0;
}
