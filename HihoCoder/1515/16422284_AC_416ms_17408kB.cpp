#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
using namespace std;
const int MAXN=100005;
int pre[MAXN];
int fa[MAXN];///他祖先-他的分数查

int getx(int x)
{
    if (pre[x]==x) return x;
    int f=pre[x];
    pre[x]=getx(f);
    fa[x]+=fa[f];
    return pre[x];
}

void nian(int x,int y,int z)
{
    int xx=getx(x);
    int yy=getx(y);
    pre[yy]=xx;
    fa[yy]=z+fa[x]-fa[y];
}
int main()
{
    int n,m,k;
    while (scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
        for (int i=1;i<=n;i++)
        {
            pre[i]=i;
            fa[i]=0;
        }
        for (int i=0;i<m;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            nian(x,y,z);
        }
        for (int i=0;i<k;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            int xx=getx(x);
            int yy=getx(y);
            if (xx!=yy)
            {
                printf("-1\n");
            }
            else
                printf("%d\n",fa[y]-fa[x]);
        }
    }
    return 0;
}
