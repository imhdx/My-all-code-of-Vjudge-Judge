#include<stdio.h>
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        printf("%04d\n",(n%10000*n%10000*(n+1)%10000*(n+1)%10000/4)%10000);
    }
    return 0;
}
