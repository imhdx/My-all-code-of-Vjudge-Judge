#include<bits/stdc++.h>
using namespace std;
struct note
{
    int x,y,len;
}que[5011];
int pre[120];
int getx(int x)
{
    if (pre[x]==x) return x;
    return pre[x]=getx(pre[x]);
}
vector<pair<int,int> > v;
bool cmp(struct note q,struct note p)
{
    if (q.len==p.len) return q.x<p.x;
    return q.len<p.len;
}
bool cmp1(pair<int,int> a1,pair<int,int> a2)
{
    if (a1.first!=a2.first)
        return a1.first<a2.first;
    return a1.second<a2.second;
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        int i,j;
        for (i=0;i<=n;i++) pre[i]=i;
        int cnt=0;
        for (i=0;i<n;i++)
        {
            for (j=0;j<n;j++)
            {
                int x;
                scanf("%d",&x);
                if (i<j&&x!=0)
                {
                    que[cnt].x=i+1;
                    que[cnt].y=j+1;
                    que[cnt].len=x;
                    cnt++;
                }
            }
        }
        sort(que,que+cnt,cmp);
        v.clear();
        int cc=0;
        for (i=0;i<cnt;i++)
        {
            int xx=getx(que[i].x);
            int yy=getx(que[i].y);
            if (xx!=yy)
            {
                cc++;
                if (xx<yy)
                {
                    pre[xx]=yy;
                    v.push_back(make_pair(que[i].x,que[i].y));
                }
                else
                {
                    pre[yy]=xx;
                    v.push_back(make_pair(que[i].x,que[i].y));
                }
            }
        }
        if (cc==n-1)
        {
            sort(v.begin(),v.end(),cmp1);
            printf("%d %d",v[0].first,v[0].second);
            for (i=1;i<v.size();i++)
            {
                printf(" %d %d",v[i].first,v[i].second);
            }
            printf("\n");
        }
        else
            printf("-1\n");
    }
    return 0;
}
