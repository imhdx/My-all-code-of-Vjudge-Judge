#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        long long a,b;
        scanf("%lld%lld",&a,&b);
        long long sum=b;
        for (int i=63;i>=0;i--)
        {
            if (((a>>i)&1)!=((b>>i)&1))
            {
                sum=(b>>i)<<i;
                //printf("%lld\n",sum);
                sum|=((1ull<<(i+1))-1);
                break;
            }
        }
        printf("%lld\n",sum);
    }
    return 0;
}
