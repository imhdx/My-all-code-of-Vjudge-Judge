#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a,b;
    while (scanf("%lld%lld",&a,&b)!=EOF)
    {
        for (int i=0;i<63;i++)
        {
            if (((a>>i)&1)==0)
            {
                if ((((a>>i)+1)<<i)<=b)
                {
                    a+=(1ll<<i);
                }
                else break;
            }
        }
        printf("%lld\n",a);
    }
    return 0;
}
