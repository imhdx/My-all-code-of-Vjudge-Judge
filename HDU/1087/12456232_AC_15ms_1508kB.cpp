#include<stdio.h>
int main()
{
    int n,a[1010],sum[1010],i,j,max;
    while (scanf("%d",&n)!=EOF&&n!=0)
    {
        for (i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            sum[i]=a[i];
        }
        for (i=1;i<n;i++)
        {
            max=0;
            for (j=0;j<i;j++)
            {
                if (a[j]<a[i])
                {
                    if (max<sum[j]) max=sum[j];
                }
            }
            sum[i]=a[i]+max;
        }
        max=0;
        for (i=0;i<n;i++)
            if (max<sum[i]) max=sum[i];
        printf("%d\n",max);
    }
    return 0;
}
