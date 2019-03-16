#include<stdio.h>
int main()
{
    long long int n;
    while (scanf("%lld",&n)!=EOF)
    {
        printf("%04lld\n",(((n*(n+1)/2)%10000)*((n*(n+1)/2)%10000))%10000);
    }
    return 0;
}
