#include<stdio.h>
int a[1200][1200];
int main()
{
    int t;
    int n;
    while (scanf("%d%d",&t,&n)!=EOF)
    {
        int i;
        int qq,pp,len;
        int j,k;
        for (i=0;i<1200;i++)
            for (j=0;j<1200;j++)
        {
            a[i][j]=999999;
            if (i==j) a[i][j]=0;
        }
        for (i=0;i<t;i++)
        {
            scanf("%d%d%d",&qq,&pp,&len);
            a[qq][pp]=len;
            a[pp][qq]=len;
        }
        for (k=1;k<=n;k++)
            for (i=1;i<=n;i++)
            for (j=1;j<=n;j++)
        {
            if (a[i][j]>a[i][k]+a[k][j]) a[i][j]=a[i][k]+a[k][j];
        }
        printf("%d\n",a[1][n]);
    }
    return 0;
}
