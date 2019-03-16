#include<cstdio>
using namespace std;
int main()
{
    int n;
    long long int a[52];
    int i;
    a[0]=1;
    a[1]=1;
    for (i=2;i<=50;i++)
    {
        a[i]=a[i-1]+a[i-2];
    }
    while (scanf("%d",&n)!=EOF)
    {
        printf("%lld\n",a[n]);
    }
    return 0;
}
