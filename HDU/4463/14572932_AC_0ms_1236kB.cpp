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
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        if (n==0) return 0;
        int i;
        int j;
        for (i=0;i<=n;i++)
        {
            map[i]=i;
        }
        int aa,bb;
        scanf("%d%d",&aa,&bb);
        aa--;
        bb--;
        for (i=0;i<n;i++)
        {
            scanf("%d%d",&a[i],&b[i]);
        }
        int cnt=0;
        for (i=0;i<n;i++)
        {
            for (j=0;j<n;j++)
            {
                if (i==j) continue;
                if (i==aa&&j==bb) continue;
                int dis=(a[i]-a[j])*(a[i]-a[j])+(b[i]-b[j])*(b[i]-b[j]);
                que[cnt].x=i;
                que[cnt].y=j;
                que[cnt].len=sqrt(dis);
                cnt++;
            }
        }
        sort(que,que+cnt,cmp);
        double ans=sqrt((a[aa]-a[bb])*(a[aa]-a[bb])+(b[aa]-b[bb])*(b[aa]-b[bb]));
        int cc=0;
        map[aa]=bb;
        for (i=0;i<cnt;i++)
        {
            if (nian(que[i].x,que[i].y))
            {
                ans+=que[i].len;
            }
        }
        printf("%.2f\n",ans);
    }
    return 0;
}
