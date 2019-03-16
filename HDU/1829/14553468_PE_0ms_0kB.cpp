#include<cstdio>
using namespace std;

int map[2010*3];
int getx(int x)
{
    if (map[x]==x) return x;
    return map[x]=getx(map[x]);
}

void nian(int x,int y)
{
    int xx=getx(x);
    int yy=getx(y);
    if (xx!=yy)
    {
        map[xx]=yy;
    }
}

int main()
{
    int t;
    int k;
    scanf("%d",&t);
    for (k=1;k<=t;k++)
    {
        int i;
        printf("Scenario #%d:\n",k);
        int n,m;
        scanf("%d%d",&n,&m);
        int flag=0;
        for (i=1;i<=3*n;i++)
        {
            map[i]=i;
        }
        for (i=0;i<m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            if (getx(x)==getx(y))
            {
                flag=1;
            }
            else
            {
                nian(x,y+n);
                nian(y,x+n);
            }
        }
        if (flag)
        {
            printf("Suspicious bugs found!\n");
        }
        else
        {
            printf("No suspicious bugs found!\n");
        }
        if (k!=t)
            printf("\n");
    }

    return 0;
}
