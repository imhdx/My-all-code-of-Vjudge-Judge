#include<bits/stdc++.h>
using namespace std;
bool vis[100005];
int read()
{
    char c=getchar();
    int s=0,f=1;
    while (c<'0'||c>'9')
    {
        if (c=='-') f=-1;
        c=getchar();
    }
    while (c>='0'&&c<='9')
    {
        s=s*10+c-'0';
        c=getchar();
    }
    return s*f;
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
