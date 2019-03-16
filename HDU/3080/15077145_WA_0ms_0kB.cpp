#include<bits/stdc++.h>
using namespace std;

struct note
{
    int x,y;
    int len;
}que[20010];
int pre[250];
int getx(int x)
{
    if (pre[x]==x) return x;
    return pre[x]=getx(pre[x]);
}
set<int>s;
bool cmp(struct note q,struct note p)
{
    return q.len<p.len;
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        s.clear();
        int l,e1;
        scanf("%d%d",&l,&e1);
        int i,j;
        for (i=0;i<250;i++) pre[i]=i;
        int cnt=0;
        for (i=0;i<e1;i++)
        {
            scanf("%d%d%d",&que[cnt].x,&que[cnt].y,&que[cnt].len);
            cnt++;
        }
        int n,e2;
        scanf("%d%d",&n,&e2);
        for (i=0;i<e2;i++)
        {
            scanf("%d%d%d",&que[cnt].x,&que[cnt].y,&que[cnt].len);
            cnt++;
        }
        int m;
        scanf("%d",&m);
        for (i=0;i<m;i++)
        {
            int x;
            scanf("%d",&x);
            s.insert(x);
        }
        sort(que,que+cnt,cmp);
        int xx=0;
        int ans=0;
        for (i=0;i<cnt;i++)
        {
            if (s.count(que[i].x)!=0||s.count(que[i].y)!=0) continue;
            if (getx(que[i].x)!=getx(que[i].y))
            {
                ans+=que[i].len;
                xx++;
            }
        }
        if (xx+1==n+l-m)
        {
            printf("%d\n",ans);
        }
        else
            printf("what a pity!\n");

    }

    return 0;
}
