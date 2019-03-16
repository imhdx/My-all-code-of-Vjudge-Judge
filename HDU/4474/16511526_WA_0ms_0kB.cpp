#include<bits/stdc++.h>
using namespace std;
bool vis[15];
int main()
{
    int n,m;
    int t=1;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        memset(vis,0,sizeof(vis));
        for (int i=0;i<m;i++)
        {
            int x;
            scanf("%d",&x);
            vis[x]=1;
        }
        int i;
        printf("Case %d: ",t++);
        for (i=1;i<=20000;i++)
        {
            int t=n*i;
            while (t)
            {
                if (vis[t%10]==1)
                    break;
                t=t/10;
            }
            if (t==0)
            {
                printf("%d\n",n*i);
                break;
            }
        }
        if (i>20000)
            printf("-1\n");


    }
    return 0;
}
