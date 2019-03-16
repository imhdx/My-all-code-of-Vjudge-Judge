#include<stdio.h>
int a[2000];
int t;
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        int i,j;
        int ans=0;
        for (i=0;i<n;i++) scanf("%d",&a[i]);
        for (i=1;i<n;i++)
        {
            for (j=0;j<n-i;j++)
            {
                if (a[j]>a[j+1])
                {
                    t=a[j];
                    a[j]=a[j+1];
                    a[j+1]=t;
                    ans++;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
