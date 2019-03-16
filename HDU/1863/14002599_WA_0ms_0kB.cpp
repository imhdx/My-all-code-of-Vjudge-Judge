#include<algorithm>
#include<cstdio>
using namespace std;
int n,m;
int pre[200];
int get(int x)
{
    if (pre[x]==x) return x;
    return pre[x]=get(pre[x]);
}
bool jie(int a,int b)
{
    int x=get(a);
    int y=get(b);
    if (x==y) return false;
    if (x>y) pre[x]=y;
    else
        pre[y]=x;
    return true;
}
struct note
{
    int len;
    int from;
    int to;
}que[200];
bool cmp(struct note a,struct note b)
{
    return a.len<b.len;
}
int main()
{
    while (scanf("%d%d",&m,&n)!=EOF)
    {
        if (n==0) break;
        int i,j;
        for (i=0;i<200;i++)
            pre[i]=i;
        for (i=0;i<n;i++)
        {
            scanf("%d%d%d",&que[i].from,&que[i].to,&que[i].len);
        }
        sort(que,que+m,cmp);
        int ans=0;
        int cc=0;
        for (i=0;i<m;i++)
        {
            if (jie(que[i].from,que[i].to)) {cc++;ans=ans+que[i].len;}
        }
        if (cc==n-1)
        printf("%d\n",ans);
        else
            printf("?\n");
    }
    return 0;
}
