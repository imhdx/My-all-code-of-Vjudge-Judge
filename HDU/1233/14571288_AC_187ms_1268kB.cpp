#include<cstdio>
#include<algorithm>

using namespace std;
int map[200];
struct note
{
    int x;
    int y;
    int len;
}que[5010];
bool cmp(struct note q,struct note p)
{
    return q.len<p.len;
}
int getx(int x)
{
    if (map[x]==x) return x;
    return map[x]=getx(map[x]);
}
bool nian(int x,int y)
{
    int xx=getx(x);
    int yy=getx(y);
    if (xx==yy) return false;
    if (xx<yy)
        map[xx]=yy;
    else
        map[yy]=xx;
    return true;
}
int main()
{
    int n,m;
    while (scanf("%d",&n)!=EOF)
    {
        m=n*(n-1)/2;
        if (n==0) return 0;
        int i,j;
        for (i=1;i<=n;i++)
            map[i]=i;
        for (i=0;i<m;i++)
        {
            scanf("%d%d%d",&que[i].x,&que[i].y,&que[i].len);
        }
        sort(que,que+m,cmp);
        int ans=0;
        for (i=0;i<m;i++)
        {
            if (nian(que[i].x,que[i].y))
            {
                ans+=que[i].len;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

