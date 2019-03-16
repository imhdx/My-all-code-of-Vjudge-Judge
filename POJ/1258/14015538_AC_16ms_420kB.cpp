#include<algorithm>
#include<cstdio>
using namespace std;
int n,m;
int pre[101];
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
}que[10010];
bool cmp(struct note a,struct note b)
{
    return a.len<b.len;
}
int main()
{
    while (scanf("%d",&n)!=EOF)
    {
        int i,j;
        for (i=0;i<101;i++)
            pre[i]=i;
        int k=0;
        for (i=0;i<n;i++)
        {
            for (j=0;j<n;j++)
            {
                int l;
                scanf("%d",&l);
                if (i<j)
                {
                    que[k].from=i;
                    que[k].to=j;
                    que[k].len=l;
                    ++k;
                }
            }
        }


        sort(que,que+k,cmp);
        int ans=0;
        int cc=0;
        for (i=0;i<k;i++)
        {
            if (jie(que[i].from,que[i].to)) {cc++;ans=ans+que[i].len;}
        }
        printf("%d\n",ans);

    }
    return 0;
}
