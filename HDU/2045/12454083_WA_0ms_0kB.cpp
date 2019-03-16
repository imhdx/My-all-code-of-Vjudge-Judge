#include<stdio.h>
int main()
{
    long long int a[52];
    long long int i;
    a[1]=3;
    a[2]=6;
    for (i=3;i<52;i++)
        a[i]=2*a[i-2]+a[i-1];
    for (i=1;i<52;i++)
        printf("%lld\n",a[i]);
        while (scanf("%lld",&i)!=EOF)
        {
            printf("%lld\n",a[i]);
        }
    return 0;
}
