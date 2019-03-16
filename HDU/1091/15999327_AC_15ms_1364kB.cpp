#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int a,b;
    while (scanf("%lld%lld",&a,&b)!=EOF)
    {
        if (a==0&&b==0) return 0;
        printf("%lld\n",a+b);
    }


    return 0;
}
