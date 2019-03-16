#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
struct note
{
    int x,y;
}a[101];
int pre[101];
struct qwe
{
    int from;
    int to;
    double len;
}que[10001];
bool cmp(struct qwe a,struct qwe b)
{
    return a.len<b.len;
}
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
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        int i,j;
        for (i=0;i<101;i++)
            pre[i]=i;
        scanf("%d",&n);
        for (i=0;i<n;i++)
        {
            scanf("%d%d",&a[i].x,&a[i].y);
        }
        int k=0;
        for (i=0;i<n;i++)
        {
            for (j=0;j<n;j++)
            {
                if (i==j) continue;
                int kk=(a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y);
                if (kk>=100&&kk<=1000000)
                {
                    que[k].from=i;
                    que[k].to=j;
                    que[k].len=sqrt(kk);
                    ++k;
                }
            }
        }
        sort(que,que+k,cmp);
        double ans=0;
        int cc=0;
        for (i=0;i<k;i++)
        {
            if (jie(que[i].from,que[i].to)) {cc++;ans=ans+que[i].len;}
        }
        ans=ans*100;
        if (cc==n-1)
        printf("%.1f\n",ans);
        else
            printf("oh!\n");

    }
    return 0;
}
