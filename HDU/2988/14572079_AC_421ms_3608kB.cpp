#include<cstdio>
#include<algorithm>

using namespace std;
int map[200010];
struct note
{
    int x;
    int y;
    int len;
}que[1200010];
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
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        if (n==0&&m==0) return 0;
        int i,j;
        for (i=0;i<=n+1;i++)
            map[i]=i;
        int anss=0;
        for (i=0;i<m;i++)
        {
            scanf("%d%d%d",&que[i].x,&que[i].y,&que[i].len);
            anss+=que[i].len;
        }
        sort(que,que+m,cmp);
        int cc=0;
        int ans=0;
        for (i=0;i<m;i++)
        {
            if (nian(que[i].x,que[i].y))
            {
                cc++;
                ans+=que[i].len;
            }
        }
        printf("%d\n",anss-ans);
    }
    return 0;
}
