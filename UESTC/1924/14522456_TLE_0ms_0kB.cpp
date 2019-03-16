#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>

using namespace std;

int map[100010];

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
            map[i]=i;
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
            int ans=0;
            for (j=1;j<=n;j++)
            {
                if(getx(j)==getx(x))
                    ans++;
            }
            printf("%d\n",ans );
        }


    }


    return 0;
}
