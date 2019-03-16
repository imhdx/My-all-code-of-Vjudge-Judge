#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>

using namespace std;

int map[200010];

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
    int k;
    while (scanf("%d%d%d",&n,&k,&m)!=EOF)
    {
        int i;
        int j;
        for (i=0;i<=n;i++)
        {
            map[i]=i;
        }
        for (i=0;i<m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            if (x!=k)
            {
                nian(x,y);
            }
        }

        int ans=0;
        for (i=1;i<=n;i++)
        {
            if (getx(i)==k)
                ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
