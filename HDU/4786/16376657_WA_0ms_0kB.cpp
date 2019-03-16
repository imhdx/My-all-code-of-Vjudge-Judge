#include<bits/stdc++.h>
using namespace std;
struct node
{
    int x,y,z;
}que[100005];
int pre[100005];
int fib[100];
int getx(int x)
{
    if (pre[x]==x) return x;
    return pre[x]=getx(pre[x]);
}
bool cmp(struct node q,struct node p)
{
    return q.z>p.z;
}
int main()
{
    fib[0]=1;
    fib[1]=2;
    for (int i=2;i<100;i++) fib[i]=fib[i-1]+fib[i-2];
    int T;
    int t=1;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++) pre[i]=i;
        for (int i=0;i<m;i++)
        {
            scanf("%d%d%d",&que[i].x,&que[i].y,&que[i].z);
        }
        int cnt=0;
        sort(que,que+m,cmp);
        for (int i=0;i<m;i++)
        {
            int x=getx(que[i].x);
            int y=getx(que[i].y);
            if (x!=y)
            {
                pre[min(x,y)]=max(x,y);
                if (que[i].z==1) cnt++;
            }
        }
        int flag=0;
        for (int i=0;i<100;i++)
        {
            if (fib[i]==cnt)
            {
                flag=1;
                break;
            }
            else if (fib[i]>cnt) break;
        }
        printf("Case #%d: ",t++);
        if (flag==1)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
