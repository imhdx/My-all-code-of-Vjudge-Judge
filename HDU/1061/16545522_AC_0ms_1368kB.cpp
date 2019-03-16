#include<bits/stdc++.h>
using namespace std;
const int mod=10;
long long poww(long long a,long long b)
{
    long long res=1;
    while (b)
    {
        if (b&1)
            res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int n;
        scanf("%d",&n);
        printf("%d\n",poww(n,n));
    }
    return 0;
}
