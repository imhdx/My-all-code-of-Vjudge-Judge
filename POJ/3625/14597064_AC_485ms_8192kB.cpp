#include<cmath>
#include<stdio.h>
#include<algorithm>
using namespace std;
int map[1010];
long long int aa[1010];
long long int bb[1010];
struct note
{
    int x;
    int y;
    double len;
}que[1000000];
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
    if (xx<yy) map[yy]=xx;
    else
        map[xx]=yy;
    return true;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int i,j;
    for (i=0;i<=n+1;i++)
        map[i]=i;
    for (i=0;i<n;i++)
    {
        scanf("%lld%lld",&aa[i],&bb[i]);
    }
    for (i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        x--;
        y--;
        int xx=getx(x);
        int yy=getx(y);
        if (xx<yy)
            map[yy]=xx;
        else
            map[xx]=yy;
    }
    int cnt=0;
    for (i=0;i<n;i++)
    {
        for (j=i+1;j<n;j++)
        {
                que[cnt].x=i;
                que[cnt].y=j;
                que[cnt].len=sqrt((aa[i]-aa[j])*(aa[i]-aa[j])+(bb[i]-bb[j])*(bb[i]-bb[j]));
                cnt++;
        }
    }
    sort(que,que+cnt,cmp);
    double ans=0;
    for (i=0;i<cnt;i++)
    {
        if (nian(que[i].x,que[i].y))
        {
            ans+=que[i].len;
        }
    }
    printf("%.2f\n",ans);
    return 0;
}
