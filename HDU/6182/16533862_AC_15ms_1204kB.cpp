#include<stdio.h>
using namespace std;
long long poww(long long a,long long b)
{
    long long res=1;
    while (b)
    {
        if (b&1)
            res=res*a;
        a=a*a;
        b>>=1;
    }
    return res;
}
int main()
{
    long long n;
    while (scanf("%lld",&n)!=EOF)
    {
        int i;
        for (i=1;i<=15;i++)
        {
            if (poww(i,i)>n)
                break;
        }
        printf("%d\n",i-1);
    }

    return 0;
}
