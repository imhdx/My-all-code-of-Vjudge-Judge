#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a[1002];
    long long b[1002];
    b[1]=2;
    b[2]=4;
    b[3]=7;
    a[1]=2;
    a[2]=4;
    a[3]=8;
    for (int i=4;i<1002;i++)
        b[i]=b[i-1]+i,a[i]=a[i-1]+b[i-1];
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        printf("%lld\n",a[n]);
    }
    return 0;
}
