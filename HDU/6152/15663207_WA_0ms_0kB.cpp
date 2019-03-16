#include<bits/stdc++.h>
using namespace std;
bool a[3002][3002];
bool flag=0;
int n;
void solve()
{
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            if (a[i][j]==1)
            {
                for (int k=1;k<=n;k++)
                {
                    if (a[i][k]==1||a[j][k]==1)
                    {
                        flag=1;
                        return ;
                    }
                }
            }
        }
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            if (a[i][j]==0)
            for (int k=1;k<=n;k++)
            {
                if (a[i][k]==0&&a[j][k]==0)
                {
                    flag=1;
                    return ;
                }
            }
        }
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        memset(a,0,sizeof(a));
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        {
            for (int j=i+1;j<=n;j++)
            {
                int w;
                scanf("%d",&w);
                a[i][j]=w;
                a[j][i]=w;
            }
        }
        flag=0;
        solve();
        if (flag==1)
            printf("Bad Team!\n");
        else
            printf("Great Team!\n");
    }
    return 0;
}
