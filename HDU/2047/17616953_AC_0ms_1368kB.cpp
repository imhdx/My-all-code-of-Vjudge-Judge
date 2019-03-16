#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int a,b;
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        a=1;
        b=2;
        for (int i=1;i<n;i++)
        {
            long long tmp=a;
            a=b;
            b=(tmp+b)*2;
        }
        printf("%lld\n",a+b);
    }
    return 0;
}
