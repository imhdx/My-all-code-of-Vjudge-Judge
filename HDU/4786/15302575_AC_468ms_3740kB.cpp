#include<bits/stdc++.h>
using namespace std;
struct node
{
    int x,y;
    int l;
}que[100010];
int pre[100010];
int getx(int x)
{
    if (pre[x]==x) return x;
    return pre[x]=getx(pre[x]);
}
bool cmp(struct node q,struct node p)
{
    return q.l<p.l;
}
long long int fib[100010];
int main()
{
    int t=1;
    int T;
    scanf("%d",&T);
    fib[0]=1;
    fib[1]=1;
    for (int i=2;i<100010;i++) fib[i]=fib[i-1]+fib[i-2];
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        int i,j;
        for (i=0;i<=n;i++) pre[i]=i;
        for (i=0;i<m;i++)
            scanf("%d%d%d",&que[i].x,&que[i].y,&que[i].l);
        printf("Case #%d: ",t++);
        sort(que,que+m,cmp);
        int ans1=0;
        int ans2=0;
        int cc=0;
        for (i=0;i<m;i++)
        {
            int xx=getx(que[i].x);
            int yy=getx(que[i].y);
            if (xx!=yy)
            {
                pre[min(xx,yy)]=max(xx,yy);
                ans1+=que[i].l;
                cc++;
            }
        }
        if (cc!=n-1)
        {
            printf("No\n");
            continue;
        }
        for (i=0;i<=n;i++) pre[i]=i;
        for (i=m-1;i>=0;i--)
        {
            int xx=getx(que[i].x);
            int yy=getx(que[i].y);
            if (xx!=yy)
            {
                pre[min(xx,yy)]=max(xx,yy);
                ans2+=que[i].l;
            }
        }
        for (i=0;i<100010;i++)
        {
            if (fib[i]<=ans2&&fib[i]>=ans1)
                break;
        }
        if (i<100010)
            printf("Yes\n");
        else
            printf("No\n");




    }
    return 0;
}
