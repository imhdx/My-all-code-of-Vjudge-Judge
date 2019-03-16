#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int n;
        scanf("%d",&n);
        int i,j;
        for (i=1;i<=n;i++)
        {
            printf("%d",i);
            for (j=2;j<=n;j++)
            {
                printf(" %d",i*j);

            }
            printf("\n");
        }
    }
    return 0;
}
