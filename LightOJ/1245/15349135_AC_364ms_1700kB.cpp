#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
using namespace std;

int main()
{
    int T;
    int t=1;
    scanf("%d",&T);
    while (T--)
    {
        printf("Case %d: ",t++);
        int n;
        scanf("%d",&n);
        long long int ans=0;
        int q=sqrt(n);
        for (int i=1;i<=q;i++)
        {
            ans+=n/i;
            ans+=(n/i-n/(i+1))*i;
        }
        if (n/q==q) ans-=q;
        printf("%lld\n",ans);
    }
    return 0;
}
