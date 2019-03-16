#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
using namespace std;

int map[110];
int a[110];
int b[110];
struct note
{
    int x;
    int y;
    double len;
}que[20000];
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
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        int i;
        int j;
        for (i=1;i<=n;i++)
        {
            map[i]=i;
        }
        for (i=0;i<n;i++)
        {
            scanf("%d%d",&a[i],&b[i]);
        }
        int cnt=0;
        for (i=0;i<n;i++)
        {
            for (j=0;j<n;j++)
            {
                int dis=(a[i]-a[j])*(a[i]-a[j])+(b[i]-b[j])*(b[i]-b[j]);
                if (dis<100||dis>1000000) continue;
                que[cnt].x=i;
                que[cnt].y=j;
                que[cnt].len=sqrt(dis);
                cnt++;
            }
        }
        sort(que,que+cnt,cmp);
        double ans=0;
        int cc=0;
        for (i=0;i<cnt;i++)
        {
            if (nian(que[i].x,que[i].y))
            {
                ans+=que[i].len;
                cc++;
            }
        }
        ans=ans*100.0;
        if (cc!=n-1)
            printf("oh!\n");
        else
            printf("%.1f\n",ans);

    }

    return 0;
}
