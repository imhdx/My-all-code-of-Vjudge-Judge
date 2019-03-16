#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    int flag=0;
    while (T--)
    {
        if (flag!=0) printf("\n");
        flag=1;
        int n;
        long long ans=0;
        long long x;
        scanf("%d",&n);
        for (int i=0;i<n;i++)
        {
            scanf("%lld",&x);
            ans+=x;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
