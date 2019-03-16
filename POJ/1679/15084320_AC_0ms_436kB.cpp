#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
using namespace std;
int n;
int pre[121];
struct note
{
    int x;
    int y;
    long long int len;
} que[6000];
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
        int m;
        scanf("%d%d",&n,&m);
        int i,j;
        for (i=0; i<=n; i++)
            pre[i]=i;
        for (i=0; i<m; i++)
        {
            scanf("%d%d%lld",&que[i].x,&que[i].y,&que[i].len);
        }
        sort(que,que+m,cmp);
        int cnt1=0;
        int cnt2=0;
        int kkk;
        long long int ans=0;
        for (i=0; i<m; i=kkk)
        {
            kkk=i;
            for (j=i; j<m; j++)
            {
                if (que[i].len==que[j].len)
                {
                    int xx=getx(que[j].x);
                    int yy=getx(que[j].y);
                    if (xx!=yy)
                    {
                        cnt1++;
                    }
                }
                else
                    break;
            }
            kkk=j;
            for (j=i; j<m; j++)
            {
                if (que[i].len==que[j].len)
                {
                    int xx=getx(que[j].x);
                    int yy=getx(que[j].y);
                    if (xx!=yy)
                    {
                        ans+=que[i].len;
                        cnt2++;
                        pre[xx]=yy;
                    }
                }
                else
                    break;
            }
        }
        if (cnt1<=cnt2)
            printf("%d\n",ans);
        else
            printf("Not Unique!\n");


    }
    return 0;
}
