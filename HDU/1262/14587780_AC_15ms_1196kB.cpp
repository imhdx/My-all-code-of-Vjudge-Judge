#include<math.h>
#include<stdio.h>
int prime(int n)
{
    if (n<2) return 0;
    for (int i=2;i<=(int)sqrt(n);i++)
    {
        if (n%i==0) return 0;
    }
    return 1;
}
int main()
{
    int i;
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=n/2;i>=2;i--)
        {
            if (prime(i)==1&&prime(n-i)==1)
            {
                printf("%d %d\n",i,n-i);
                break;
            }
        }
    }
    return 0;
}

