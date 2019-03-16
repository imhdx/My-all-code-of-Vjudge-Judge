#include<stdio.h>
long long int a[10000010];
int main()
{
    a[1]=0;
    a[2]=3;
    long long int i;
    for (i=3;i<10000010;i++)
    a[i]=(a[i-1]*2+a[i-2]*3)%1000000007;
    long long int n;
    while (scanf("%lld",&n)!=EOF)
        printf("%lld\n",a[n]);
    return 0;
}