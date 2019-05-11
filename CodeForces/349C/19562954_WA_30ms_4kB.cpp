#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    long long sum=0;
    for (int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        sum+=x;
    }
    printf("%lld\n",(long long)ceil(1.0*sum/(n-1)));
    return 0;
}
