#include<cstdio>
using namespace std;
int map[200010];
int num[200010];
int getx(int x)
{
    if (map[x]==x)
    {
        return map[x];
    }
    else
    {
        int tmp=map[x];
        map[x]=getx(map[x]);
        num[x]+=num[tmp];
        return map[x];
    }
}
int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        int i,j;
        for (i=0;i<=n;i++)
        {
            map[i]=i;
            num[i]=0;
        }
        int ans=0;
        for (i=0;i<m;i++)
        {
            int l,r,s;
            scanf("%d%d%d",&l,&r,&s);
            l--;
            int xx=getx(l);
            int yy=getx(r);
            if (xx==yy)
            {
                if (num[r]-num[l]!=s) ans++;
            }
            else
            {
                if (xx<yy)
                {
                    map[yy]=xx;
                    num[yy]=num[l]+s-num[r];
                }
                else
                {
                    map[xx]=yy;
                    num[xx]=num[r]-s-num[l];
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
