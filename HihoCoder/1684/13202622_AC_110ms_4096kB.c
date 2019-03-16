#include<stdio.h>
int a[100010];
int b[100010];
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        int i;
        for (i=0;i<n;i++) scanf("%d",&a[i]);
        int t=0;
        b[t++]=a[n-1];
        for (i=n-2;i>=0;i--)
        {
            if (a[i]>b[t-1]) b[t++]=a[i];
            else
            {
                int qq=0;
                int ww=t-1;
                int mid=(qq+ww)/2;
                while (qq<ww)
                {
                    mid=(qq+ww)/2;
                    if (b[mid]>a[i])
                        ww=mid;
                    else
                        qq=mid+1;
                }
                b[qq]=a[i];
            }
        }
        printf("%d\n",n-t);
    }
    return 0;
}
