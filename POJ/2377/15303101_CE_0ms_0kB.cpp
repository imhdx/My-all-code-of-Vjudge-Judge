#include<bits/stdc++.h>
using namespace std;
struct node
{
    int x,y;
    int l;
} que[20010];
int pre[1010];
int getx(int x)
{
    if (pre[x]==x)
        return x;
    return pre[x]=getx(pre[x]);
}
bool cmp(struct node q,struct node p)
{
    return q.l<p.l;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int i,j;
    for (i=0; i<=n; i++)
        pre[i]=i;
    for (i=0; i<m; i++)
        scanf("%d%d%d",&que[i].x,&que[i].y,&que[i].l);
    sort(que,que+m,cmp);
    long long int ans2=0;
    int cc=0;
    for (i=m-1; i>=0; i--)
    {
        int xx=getx(que[i].x);
        int yy=getx(que[i].y);
        if (xx!=yy)
        {
            pre[min(xx,yy)]=max(xx,yy);
            ans2+=que[i].l;
            cc++;
        }
    }
    if (cc!=n-1)
        printf("-1\n");
    else
        printf("%lld\n",ans2);


    return 0;
}
