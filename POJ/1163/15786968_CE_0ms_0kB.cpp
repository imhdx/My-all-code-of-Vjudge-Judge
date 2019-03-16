#include<bits/stdc++.h>
using namespace std;
int a[120][120];
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        memset(a,0,sizeof(a));
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<=i;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        for (int i=n-2;i>=0;i--)
        {
            for (int j=0;j<=i;j++)
            {
                a[i][j]+=max(a[i+1][j],a[i+1][j+1]);
            }
        }
        printf("%d\n",a[0][0]);

    }

    return 0;
}
