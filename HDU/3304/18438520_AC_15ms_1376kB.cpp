#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t=1;
    long long p,n;
    while (scanf("%lld%lld",&p,&n)!=EOF)
    {
        if (n==0&&p==0) return 0;
        long long ans=1;
        while (n)
        {
            ans=ans*(n%p+1)%10000;
            n=n/p;
        }
        
        printf("Case %d: ",t++);
        printf("%04lld\n",ans);
    }

    return 0;
}
