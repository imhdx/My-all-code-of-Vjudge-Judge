//
// Created by mhdx on 2019/5/26.
//

#include<bits/stdc++.h>
using namespace std;
struct node
{
    int x,y,w;
    bool operator<(const node &b)const{
        return w<b.w;
    }
}que[4000006];
int pre[2003];
int getx(int x)
{
    if (pre[x]==x) return x;
    return pre[x]=getx(pre[x]);
}
int read()
{
    int s=0;
    char c=getchar();
    while (c<'0'||c>'9') c=getchar();
    while (c>='0'&&c<='9')
    {
        s=s*10+c-'0';
        c=getchar();
    }
    return s;
}
int main()
{
    int n;n=read();
    for (int i=0;i<=n;i++) pre[i]=i;
    int cnt=0;
    for (int i=1;i<=n;i++)
    {
        for (int j=i;j<=n;j++)
        {
            int x;x=read();
            que[cnt++]=node{i,j,x};
        }
    }
    sort(que,que+cnt);
    int ans=0;
    for (int i=0;i<cnt;i++)
    {
        int xx=getx(que[i].x);
        int yy=getx(que[i].y);
        if (xx!=yy)
        {
            ans+=que[i].w;
            pre[xx]=yy;
        }
    }
    printf("%d\n",ans);
    return 0;
}