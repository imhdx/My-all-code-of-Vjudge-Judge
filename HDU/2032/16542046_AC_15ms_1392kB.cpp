#include<bits/stdc++.h>
long long int a[40][40];
int main()
{
    a[0][0]=1;
    for (int i=1;i<40;i++)
    {
        a[i][0]=1;
        for (int j=1;j<=i;j++)
        {
            a[i][j]=a[i-1][j-1]+a[i-1][j];
        }
    }
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<=i;j++)
            {
                printf("%lld%c",a[i][j]," \n"[j==i]);
            }
        }
        printf("\n");
    }
    return 0;
}
