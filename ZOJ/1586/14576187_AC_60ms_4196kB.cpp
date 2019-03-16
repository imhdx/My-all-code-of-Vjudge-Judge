#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
struct note
{
    int x,y;
    int cost;
} que[200010];
int map[200010];
int a[200010];
bool cmp(struct note q,struct note p)
{
    return q.cost<p.cost;
}
int getx(int x)
{
    if (map[x]==x)
        return x;
    map[x]=getx(map[x]);
    return map[x];
}
bool nian(int x,int y)
{
    int xx=getx(x);
    int yy=getx(y);
    if (xx==yy) return false;
    if (xx>yy) map[xx]=yy;
    else
        map[yy]=xx;
    return true;
}
int main()
{
    int n,m;
    int T;
    cin>>T;
    while (T--)
    {
        cin>>n;
        int i,j;
        int ans=0;
        for (i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for (i=0; i<=n+1; i++)
            map[i]=i;
        int cnt=0;
        for (i=0;i<n;i++)
        {
            for (j=0;j<n;j++)
            {
                int hhh;
                scanf("%d",&hhh);
                if (i>j)
                {
                    que[cnt].x=i;
                    que[cnt].y=j;
                    que[cnt].cost=a[i]+a[j]+hhh;
                    cnt++;
                }
            }
        }
        sort(que,que+cnt,cmp);
        for (i=0;i<cnt;i++)
        {
            if (nian(que[i].x,que[i].y))
            {
                ans+=que[i].cost;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
