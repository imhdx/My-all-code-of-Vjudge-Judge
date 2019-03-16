#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
using namespace std;
int pre[2010];
char a[2010][20];
int cal(int x,int y)
{
    int cnt=0;
    int i,j;
    for (i=0;i<7;i++)
    {
        if (a[x][i]!=a[y][i])
            cnt++;
    }
    return cnt;
}
struct note
{
    int x,y;
    int l;
}que[2040100];
bool cmp(struct note q,struct note p)
{
    return q.l<p.l;
}
int getx(int x)
{
    if (pre[x]==x) return x;
    return pre[x]=getx(pre[x]);
}

int main()
{
    int n;
    while (scanf("%d",&n)!=EOF&&n)
    {
        int i;
        getchar();
        for (i=1;i<=n;i++)
        {
            scanf("%s",a[i]);
        }
        int j;
        int cnt=0;
        for (i=1;i<=n;i++)
        {
            for (j=i+1;j<=n;j++)
            {
                que[cnt].x=i;
                que[cnt].y=j;
                que[cnt].l=cal(i,j);
                cnt++;
            }
        }
        for (i=1;i<=n;i++)
            pre[i]=i;
        sort(que,que+cnt,cmp);
        int ans=0;
        for (i=0;i<cnt;i++)
        {
            int xx=getx(que[i].x);
            int yy=getx(que[i].y);
            if (xx!=yy)
            {
                if (xx<yy)
                {
                    ans+=que[i].l;
                    pre[xx]=yy;
                }
                else
                {
                    ans+=que[i].l;
                    pre[xx]=yy;
                }
            }
        }
        printf("The highest possible quality is 1/%d.\n",ans);
    }
    return 0;
}
