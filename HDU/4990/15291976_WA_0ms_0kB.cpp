#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include<iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include<vector>
long long int n,m;
long long int poww(long long a,long long b)
{
    long long int res=1;
    while (b>0)
    {
        if (b&1)
            res=(res*a)%m;
        a=(a*a)%m;
        b>>=1;
    }
    return res%m;
}
int main()
{
    while (scanf("%lld%lld",&n,&m)!=EOF)
    {
        m=6*m;
        long long ans=(((poww(2,n+2)-3-poww(-1,n)))%m+m)%m/6;
        printf("%lld\n",ans);
    }
    return 0;
}
