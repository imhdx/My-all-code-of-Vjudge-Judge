#include<stdio.h>
int main()
{
    long long int a[99],b[99],c[99];
    long long int i,j;
    a[1]=2;
    b[1]=1;
    a[2]=2*a[1]+2*b[1];
    b[2]=a[1];
    for (i=3;i<40;i++)
    {
        a[i]=2*a[i-1]+2*b[i-1];
        b[i]=a[i-1];
    }
    while (scanf("%lld",&i)!=EOF)
    {
        printf("%lld\n",a[i]+b[i]);
    }
    return 0;
}
