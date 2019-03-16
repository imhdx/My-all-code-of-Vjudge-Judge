#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        if (n==0) return 0;
        long long ans=0;
        long long int x;
        for (int i=0;i<n;i++)
        {
            scanf("%lld",&x);
            ans+=x*x;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
