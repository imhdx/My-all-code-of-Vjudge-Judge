#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;
struct note
{
    int x,y,len;
} que[25041];
int pre[561];
int getx(int x)
{
    if (pre[x]==x)
        return x;
    return pre[x]=getx(pre[x]);
}
bool cmp(struct note q,struct note p)
{
    return q.len<p.len;
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        int i,j;
        for (i=0; i<560; i++)
            pre[i]=i;
        int cnt=0;
        for (i=0; i<m; i++)
        {
            scanf("%d%d%d",&que[i].x,&que[i].y,&que[i].len);
            cnt++;
        }
        sort(que,que+cnt,cmp);
        for (i=0; i<k; i++)
        {
            int t,x;
            scanf("%d%d",&t,&x);
            while (--t)
            {
                int y;
                scanf("%d",&y);
                int xx=getx(x);
                int yy=getx(y);
                if (xx!=yy)
                {
                    if (xx<yy)
                        pre[xx]=yy;
                    else
                        pre[yy]=xx;
                }
            }
        }
        int ans=0;
        int cc=0;
        for (i=0; i<cnt; i++)
        {
            int xx=getx(que[i].x);
            int yy=getx(que[i].y);
            if (xx!=yy)
            {
                if (xx<yy)
                    pre[xx]=yy;
                else
                    pre[yy]=xx;
                ans+=que[i].len;
            }
        }
        for (i=1; i<=n; i++)
        {
            if (getx(i)==i)
                cc++;
        }
        if (cc>1)
            printf("-1\n");
        else
            printf("%d\n",ans);
    }
    return 0;
}