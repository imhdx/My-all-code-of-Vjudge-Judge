#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>

using namespace std;

int map[100010];
int num[100010];

int getx(int pp)
{
    if (map[pp]==pp)
        return pp;
    else
        return map[pp]=getx(map[pp]);
}

bool nian(int qq,int pp)
{
    int xx=getx(qq);
    int yy=getx(pp);
    if (xx==yy)
    {
        return true;
    }
    else
    {
        num[yy]=num[yy]+num[xx];
        map[xx]=yy;
        return false;
    }
}


int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        int i;
        int j;
        for (i=0;i<=n;i++)
        {
            map[i]=i;
            num[i]=1;
        }
        for (i=0;i<m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            nian(x,y);
        }
        int q;
        scanf("%d",&q);
        for (i=0;i<q;i++)
        {
            int x;
            scanf("%d",&x);
            printf("%d\n",num[getx(x)]);
        }
    }
    return 0;
}
