#include<bits/stdc++.h>
using namespace std;
const int maxn=50010;
const int maxm=100010;
struct ac
{
    int x,y,w;
    bool col;
    int id;
}que[maxm];
vector<int> bai;
bool cmp1(struct ac q,struct ac p)
{
    if (q.w==p.w) return q.col<p.col;
    return q.w<p.w;
}
bool cmp2(struct ac q,struct ac p)
{
    return q.id<p.id;
}
int pre[maxn];
int getx(int x)
{
    if (pre[x]==x) return x;
    return pre[x]=getx(pre[x]);
}
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for (int i=0;i<m;i++)
    {
        int s,t,v,col;
        scanf("%d%d%d%d",&s,&t,&v,&col);
        que[i].x=s;
        que[i].y=t;
        que[i].w=v;
        que[i].col=col;
        que[i].id=i;
        if (col==0) bai.push_back(i);
    }
    ///二分白色边权加上某个值
    int l=-1e9;
    int r=1e9;
    long long ans=-1;
    while (l<=r)
    {
        long long sum=0;
        int mid=l+r>>1;
        for (int i=0;i<bai.size();i++)
        {
            que[i].w+=mid;
        }
        int cc=0;
        sort(que,que+m,cmp1);
        for (int i=0;i<=n;i++) pre[i]=i;
        for (int i=0;i<m;i++)
        {
            int xx=getx(que[i].x);
            int yy=getx(que[i].y);
            if (xx!=yy)
            {
                sum+=que[i].w;
                if (que[i].col==0) cc++;
                pre[xx]=yy;
            }
        }
        if (cc>=k)
        {
            ans=sum;
            l=mid+1;
        }
        else r=mid-1;
        sort(que,que+m,cmp2);
    }
    printf("%lld\n",ans);
    return 0;
}
