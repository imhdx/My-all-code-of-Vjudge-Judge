#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
using namespace std;

int map[110];
double a[110];
double b[110];
struct note
{
    double x;
    double y;
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
    int kkkk=1;
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        if (kkkk!=1) printf("\n");
        if (n==0) return 0;
        int i;
        int j;
        for (i=0;i<=n+1;i++)
        {
            map[i]=i;
        }
        for (i=0;i<n;i++)
        {
            scanf("%lf%lf",&a[i],&b[i]);
        }
        int cnt=0;
        for (i=0;i<n;i++)
        {
            for (j=0;j<n;j++)
            {
                if (i==j) continue;
                double dis=(a[i]-a[j])*(a[i]-a[j])+(b[i]-b[j])*(b[i]-b[j]);
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
        ans=(int)(ans*100+0.5)/100.0;
        printf("Case #%d:\n",kkkk++);
        printf("The minimal distance is: %.2f\n",ans);
    }

    return 0;
}
