#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        long long ans=0;
        long long x;
        scanf("%d",&n);
        for (int i=0;i<n;i++)
        {
            scanf("%lld",&x);
            ans+=x;
        }
        printf("%lld\n\n",ans);
    }
    return 0;
}
