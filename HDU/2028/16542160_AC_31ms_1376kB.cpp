#include<bits/stdc++.h>
using namespace std;
long long int gcd(long long int x,long long int y)
{
    return y==0?x:gcd(y,x%y);
}
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        long long int x;
        long long int y;
        scanf("%lld",&x);
        for (int i=1;i<n;i++)
        {
            scanf("%lld",&y);
            x=x/gcd(x,y)*y;
        }
        printf("%lld\n",x);
    }
    return 0;
}
