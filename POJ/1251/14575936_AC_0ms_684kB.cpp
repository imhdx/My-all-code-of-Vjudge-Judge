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
    while (cin>>n)
    {
        if (n==0) return 0;
        int i,j;
        for (i=0; i<=30; i++)
            map[i]=i;
        int cnt=0;
        for (i=0;i<n-1;i++)
        {
            char ch;
            int kk;
            cin>>ch>>kk;
            for (j=0;j<kk;j++)
            {
                int kkk;
                char chh;
                cin>>chh>>kkk;
                que[cnt].x=ch-'A';
                que[cnt].y=chh-'A';
                que[cnt].cost=kkk;
                cnt++;
            }
        }
        sort(que,que+cnt,cmp);
        int ans=0;
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
