#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<map>
using namespace std;
struct note
{
    int x;
    int y;
    int f;
}que[10010];
map<int,int> M;
int pre[2*10010];
int getx(int x)
{
    if (pre[x]==x) return x;
    return pre[x]=getx(pre[x]);
}
bool nian(int x,int y)
{
    int xx=getx(x);
    int yy=getx(y);
    if (xx!=yy)
    {
        pre[xx]=yy;
        return true;
    }
    return false;
}
int main()
{
    int n;
    scanf("%d",&n);
    int q;
    int i;
    scanf("%d",&q);
    int cnt=1;
    M.clear();
    for (i=0;i<q;i++)
    {
        int x,y;
        char s[6];
        scanf("%d%d%s",&x,&y,s);
        x--;
        que[i].x=x;
        que[i].y=y;
        if (s[0]=='o')
            que[i].f=1;
        else
            que[i].f=0;
        if (M[x]==0) M[x]=cnt++;
        if (M[y]==0) M[y]=cnt++;
    }
    for (i=0;i<2*10010;i++)
        pre[i]=i;
    n=cnt;
    for (i=0;i<q;i++)
    {
        int x=M[que[i].x];
        int y=M[que[i].y];
        if (que[i].f==0)
        {
            if (getx(x)==getx(y+n)||getx(y)==getx(x+n))
            {
                printf("%d\n",i);
                return 0;
            }
            else
            {
                nian(x,y);
                nian(x+n,y+n);
            }
        }
        else
        {
            if (getx(x)==getx(y)||getx(x+n)==getx(y+n))
            {
                printf("%d\n",i);
                return 0;

            }
            else
            {
                nian(x,y+n);
                nian(y,x+n);
            }
        }
    }
    printf("%d\n",q);
    return 0;
}
