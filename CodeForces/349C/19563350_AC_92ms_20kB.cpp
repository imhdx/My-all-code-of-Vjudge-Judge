#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    long long sum=0;
    int maxx=-1e9;
    for (int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        sum+=x;
        maxx=max(maxx,x);
    }
    printf("%lld\n",max(1ll*maxx,(long long)ceil(1.0*sum/(n-1))));
    return 0;
}
