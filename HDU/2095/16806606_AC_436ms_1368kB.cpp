#include<bits/stdc++.h>
using namespace std;
const double PI=4*atan(1.0);
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF&&n)
    {
        long long x;
        scanf("%lld",&x);
        long long ans=x;
        for (int i=1;i<n;i++)
        {
            scanf("%lld",&x);
            ans=ans^x;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
