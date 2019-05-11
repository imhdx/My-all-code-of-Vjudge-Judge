#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    while (scanf("%d%d",&m,&n)!=EOF)
    {
        int ans=(m+1)*(n-1);
        for (int x=1;x<=m;x++)
        {
            for (int y=x;y<=m;y++)
            {
                for (int z=y;z<=m;z++)
                {
                    if (x*x+y*y==z*z) ans++;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
