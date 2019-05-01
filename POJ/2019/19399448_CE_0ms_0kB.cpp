#include<bits/stdc++.h>
using namespace std;
const int inf=1e9+7;
int a[252][252];
int c[252][252];
int main()
{
    memset(c,-1,sizeof(c));
    int n,k,b;
    scanf("%d%d%d",&n,&b,&k);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        scanf("%d",&a[i][j]);
    while (k--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if (c[x][y]==-1)
        {
            int maxx=-inf;
            int minn=inf;
            for (int i=x;i<x+b;i++)
            {
                for (int j=y;j<y+b;j++)
                {
                    maxx=max(maxx,a[i][j]);
                    minn=min(minn,a[i][j]);
                }
            }
            c[x][y]=maxx-minn;
        }
        printf("%d\n",c[x][y]);
    }
    return 0;
}
