#include<bits/stdc++.h>
using namespace std;
int c1[300];
int c2[300];
int a[300];
int c[300];
int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        int i;
        memset(c1,0,sizeof(c1));
        memset(c2,0,sizeof(c2));
        for (i=1;i<=n;i++)
        {
            scanf("%d%d",&a[i],&c[i]);
        }
        for (i=a[1];i<=c[1];i++)
        {
            c1[i]=1;
        }
        int j,k;
        for (i=2;i<=n;i++)
        {
            for (j=0;j<=m;j++)
            {
                for (k=a[i];k<=c[i]&&k+j<=m;k++)
                {
                    c2[j+k]+=c1[j];
                }
            }
            for (j=0;j<=m;j++)
            {
                c1[j]=c2[j];
                c2[j]=0;
            }
        }
        printf("%d\n",c1[m]);

    }
    return 0;
}
