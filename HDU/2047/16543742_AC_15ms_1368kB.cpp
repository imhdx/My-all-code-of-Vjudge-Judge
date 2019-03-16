#include<bits/stdc++.h>
long long a[42];
long long b[42];
int main()
{
    a[1]=2;
    b[1]=1;
    for (int i=2;i<42;i++)
    {
        a[i]=2*(a[i-1]+b[i-1]);
        b[i]=a[i-1];
    }
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        printf("%lld\n",a[n]+b[n]);
    }
    return 0;
}
