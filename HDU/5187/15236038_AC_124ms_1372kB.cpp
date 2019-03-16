#include<bits/stdc++.h>
using namespace std;
long long int p;
long long mul(long long a,long long b)
{
    long long res=0;
    if (a<b)
    {
        res=a;
        a=b;
        b=res;
        res=0;
    }
    while (b>0)
    {
        if (b&1)
            res=(res+a)%p;
        a=(a+a)%p;
        b>>=1;
    }
    return res;
}
long long int poww(long long a,long long b)
{
    long long int res=1;
    while (b>0)
    {
        if (b&1)
            res=mul(a,res)%p;
        a=mul(a,a)%p;
        b>>=1;
    }
    return res;
}
int main()
{
    long long int n;
    while (scanf("%lld%lld",&n,&p)!=EOF)
    {
        if (p==1)
            printf("0\n");
        else if (n==1)
            printf("1\n");
        else
        {
            long long int ans=((poww(2,n)-2)%p+p)%p;
            printf("%lld\n",ans);
        }
    }

    return 0;
}
