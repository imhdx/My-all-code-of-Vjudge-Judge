#include<bits/stdc++.h>
using namespace std;
int a[12][12];
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF&&n)
    {
        memset(a,0,sizeof(a));
        int i=1,j=1;
        int cnt=1;
        while (j<=n)
        {
            a[i][j]=cnt++;
            j++;
        }
        j--;
        i++;
        while (i<=n)
        {
            a[i][j]=cnt++;
            i++;
        }
        j--;
        i--;
        while (j>=1)
        {
            a[i][j]=cnt++;
            j--;
        }
        i--;
        j++;
        while (i>1)
        {
            a[i][j]=cnt++;
            i--;
        }
        for (i=1;i<=n;i++)
        {
            for (j=1;j<=n;j++)
            {
                if (a[i][j]==0)
                    printf("   ");
                else
                    printf("%3d",a[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
