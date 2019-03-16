#include<stdio.h>
int a[6000];
int main()
{
    int n;
    int t;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&n);
        int i,j,k;
        for (i=0;i<6000;i++)
            a[i]=i;
        int sum=n;
        while (sum>=4)
        {
            k=1;
            for (i=1;i<=sum;i++)
            {
                if (i%2!=0) {a[k++]=a[i];}
            }
            sum=k-1;
            if (k<=4) break;
            k=1;
            for (i=1;i<=sum;i++)
            {
                if (i%3!=0) {a[k++]=a[i];}
            }
            sum=k-1;
            if (k<=4) break;
        }
        printf("%d",a[1]);
        for (i=2;i<=sum;i++)
            printf(" %d ",a[i]);
        printf("\n");
    }
    return 0;
}
