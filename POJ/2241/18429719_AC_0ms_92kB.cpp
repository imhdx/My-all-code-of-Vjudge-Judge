#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
struct note
{
    int x,y,z;
}que[102];
bool cmp(struct note q,struct note p)
{
    if (q.x!=p.x)
        return q.x<p.x;
    return q.y<p.y;
}
int dp[100];
int main()
{
    int T=1;
    int n;
    while (scanf("%d",&n)!=EOF&&n)
    {
        int i;
        int cnt=0;
        for (i=0;i<n;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            que[cnt].x=min(x,y);
            que[cnt].y=max(x,y);
            que[cnt].z=z;
            cnt++;
            que[cnt].x=min(z,y);
            que[cnt].y=max(z,y);
            que[cnt].z=x;
            cnt++;
            que[cnt].x=min(x,z);
            que[cnt].y=max(x,z);
            que[cnt].z=y;
            cnt++;
        }
        sort(que,que+cnt,cmp);
        memset(dp,0,sizeof(dp));
        int maxx=0;
        int j;

        for (i=0;i<cnt;i++)
        {
            dp[i]=que[i].z;
            for (j=0;j<i;j++)
            {
                if (que[i].x>que[j].x&&que[i].y>que[j].y)
                {
                    //if (que[i].x==que[j].x&&que[i].y==que[j].y) continue;
                    dp[i]=max(dp[i],que[i].z+dp[j]);
                    maxx=max(dp[i],maxx);
                }
            }
        }
        printf("Case %d: maximum height = %d\n",T++,maxx);

    }

    return 0;
}