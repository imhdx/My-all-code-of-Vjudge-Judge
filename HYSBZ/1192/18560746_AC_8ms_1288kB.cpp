#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n;scanf("%lld",&n);
    long long a=1;
    int k=0;
    while (a<=n) a=a*2,k++;
    printf("%d\n",k);

    return 0;
}
