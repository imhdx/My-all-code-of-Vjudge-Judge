#include<bits/stdc++.h>
using namespace std;
int a[10011];
struct note
{
    int s;
    int num;
}que[10010];
int sum[10010];
bool cmp(struct note q,struct note p)
{
    if (q.s==p.s) return q.num>p.num;
    return q.s<p.s;
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int q,n;
        scanf("%d%d",&q,&n);
        int i,j;
        int ss=0;
        for (i=0;i<n;i++)
        {
            scanf("%d",&que[i].s);
            que[i].num=i;
            ss+=que[i].s;
        }
        if (ss<q)
        {
            printf("IMPOSSIBLE\n");
            continue;
        }
        memset(sum,0,sizeof(sum));
        sort(que,que+n,cmp);
        int k=n;
        for (i=0;i<n;i++)
        {
            if (que[i].s<=q/k)
            {
                sum[que[i].num]=que[i].s;
                q=q-que[i].s;
                k--;
            }
            else
            {
                sum[que[i].num]=q/k;
                q=q-q/k;
                k--;
            }
        }
        for (i=0;i<n-1;i++)
            printf("%d ",sum[i]);
        printf("%d\n",sum[n-1]);
    }
    return 0;
}
