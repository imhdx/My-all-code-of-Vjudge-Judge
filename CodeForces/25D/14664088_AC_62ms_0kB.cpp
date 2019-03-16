#include<cstdio>
#include<algorithm>

using namespace std;
int pre[1010];
int getx(int x)
{
    if (x==pre[x])
        return x;
    return pre[x]=getx(pre[x]);
}
struct note
{
    int x;
    int y;
}que[1010];
int res[1010];
int ans[1010];
void nian(int x,int y)
{
    int xx=getx(x);
    int yy=getx(y);
    if (xx!=yy)
    {
        if (xx<yy)
            pre[xx]=yy;
        else
            pre[yy]=xx;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int i;
    for (i=0;i<=n+1;i++)
        pre[i]=i;
    int cnt=0;
    for (i=0;i<n-1;i++)
    {
        scanf("%d%d",&que[i].x,&que[i].y);
        if (getx(que[i].x)!=getx(que[i].y))
        {
            nian(getx(que[i].x),getx(que[i].y));
        }
        else
        {
            res[cnt++]=i;
        }
    }

    printf("%d\n",cnt);
    int cc=0;
    for (i=1;i<=n;i++)
    {
        if (getx(i)==i)
        {
            ans[cc++]=i;
        }
    }
    for (i=0;i<cc-1;i++)
    {
        printf("%d %d %d %d\n",que[res[i]].x,que[res[i]].y,ans[i+1],ans[i]);
    }
    return 0;
}
