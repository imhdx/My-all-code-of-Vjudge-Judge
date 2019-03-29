#include<bits/stdc++.h>
using namespace std;
bool vis[100005];
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
int main()
{
    int T;
    T=read();
    while (T--)
    {
        int n,m,a,cnt=0;
        n=read();
        m=read();
        for (int i=0;i<=n;i++) vis[i]=0;
        for (int i=1;i<n;i++)
        {
            a=read();
            if (vis[a]||vis[i+1]) continue;
            cnt++;
            vis[a]=1;
            vis[i+1]=1;
        }
        if (2*cnt>=m) printf("%d\n",(m+1)/2);
        else printf("%d\n",cnt+m-2*cnt);
    }
    return 0;
}
