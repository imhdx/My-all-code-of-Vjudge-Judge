#include<cstdio>
#include<algorithm>
using namespace std;
int pre[105];
struct ac
{
    int x,y;
    long long w;
}q[10100];
int w[105][105];
int getx(int x){if (pre[x]==x) return x;return pre[x]=getx(pre[x]);}
bool cmp(ac q,ac p){return q.w<p.w;}
int main()
{
    int n;scanf("%d",&n);
    for (int i=0;i<=n;i++) pre[i]=i;
    for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) scanf("%d",&w[i][j]);
    int m;scanf("%d",&m);
    for (int i=0;i<m;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        int xx=getx(x);int yy=getx(y);
        if (xx!=yy) pre[xx]=yy;
    }
    int cnt=0;
    for (int i=1;i<=n;i++)for (int j=i+1;j<=n;j++)
    q[cnt++]=ac{i,j,w[i][j]};
    sort(q,q+cnt,cmp);
    long long ans=0;
    for (int i=0;i<cnt;i++)
    {
        int xx=getx(q[i].x),yy=getx(q[i].y);
        if (xx!=yy) pre[xx]=yy,ans+=q[i].w;
    }
    printf("%lld\n",ans);
    return 0;
}
