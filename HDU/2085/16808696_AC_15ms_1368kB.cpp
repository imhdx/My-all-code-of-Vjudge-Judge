#include<bits/stdc++.h>
using namespace std;
long long a[35];
long long b[35];
int main()
{
    a[0]=1;
    b[0]=0;
    for (int i=1;i<35;i++)
    {
        a[i]=a[i-1]*3+b[i-1]*2;
        b[i]=a[i-1]+b[i-1];
    }
    int n;
    while (scanf("%d",&n)!=EOF&&n!=-1)
    {
        printf("%lld, %lld\n",a[n],b[n]);
    }
    return 0;
}
