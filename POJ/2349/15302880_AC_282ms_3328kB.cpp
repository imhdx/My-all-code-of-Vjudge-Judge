#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<cstring>
using namespace std;
struct qwe
{
    int x,y;
}a[502];
int tyf[501];
struct note
{
    int from;
    int to;
    int len;
}que[250010];
bool cmp(struct note a,struct note b)
{
    return a.len<b.len;
}
int pre[501];
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
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int i,j;
        for (i=0;i<501;i++)
            pre[i]=i;
        int n,m;
        scanf("%d%d",&m,&n);
        for (i=0;i<n;i++)
        {
            int x,y;
            scanf("%d%d",&a[i].x,&a[i].y);
        }
        int k=0;
        for (i=0;i<n;i++)
        {
            for (j=0;j<n;j++)
            {
                que[k].from=i;
                que[k].to=j;
                que[k].len=(a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y);
                ++k;
            }
        }
        sort(que,que+k,cmp);
        int ans=0;
        int cc=0;
        for (i=0;i<k;i++)
        {
            if (jie(que[i].from,que[i].to))
            {
                tyf[cc++]=que[i].len;
            }
        }
        printf("%.2f\n",sqrt(tyf[cc-m]));
    }
    return 0;
}