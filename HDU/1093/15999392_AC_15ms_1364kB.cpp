#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    while (n--)
    {
        long long ans=0;
        long long x;
        int m;
        scanf("%d",&m);
        for (int i=0;i<m;i++)
        {
            scanf("%lld",&x);
            ans+=x;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
