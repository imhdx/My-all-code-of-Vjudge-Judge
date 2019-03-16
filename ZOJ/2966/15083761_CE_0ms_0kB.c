#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;
struct note
{
    int x,y,len;
} que[125010];
int pre[560];
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
        int n,m;
        scanf("%d%d",&n,&m);
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
        printf("%d\n",ans);
    }
    return 0;
}
