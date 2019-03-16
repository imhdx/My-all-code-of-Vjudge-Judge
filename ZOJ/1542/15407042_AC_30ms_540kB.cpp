#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
using namespace std;
struct node
{
    int x;
    int y;
    int l;
}que[15010];
struct nodd
{
    int x;
    int y;
    int l;
}ans[15010];
int pre[1010];
int getx(int x)
{
    if (pre[x]==x) return x;
    return pre[x]=getx(pre[x]);
}
bool cmp(struct node q,struct node p)
{
    return q.l<p.l;
}
int main()
{
    int n;
    int m;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        int i,j;
        for (i=0;i<=n;i++) pre[i]=i;
        for (i=0;i<m;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            que[i].x=x;
            que[i].y=y;
            que[i].l=z;
        }
        sort(que,que+m,cmp);
        int cc=0;
        int ccc=0;
        int jj=0;
        for (i=0;i<m;i++)
        {
            int xx=getx(que[i].x);
            int yy=getx(que[i].y);
            if (xx!=yy)
            {
                ans[cc].x=que[i].x;
                ans[cc].y=que[i].y;
                ans[cc++].l=que[i].l;
                pre[min(xx,yy)]=max(xx,yy);
            }
        }
        printf("%d\n%d\n",ans[cc-1].l,cc);
        for (i=0;i<cc;i++)
            printf("%d %d\n",ans[i].x,ans[i].y);
    }
    return 0;
}
