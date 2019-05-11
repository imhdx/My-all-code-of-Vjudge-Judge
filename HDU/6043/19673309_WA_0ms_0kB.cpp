//
// Created by mhdx on 2019/5/10.
//

#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a,b;
    int tt=1;
    while (scanf("%lld%lld",&a,&b)!=EOF)
    {
        printf("Case #%d: ",tt++);
        if (b<=a) printf("%lld\n",b);
        else{
            long long k=(b-1)%(a-1);
            if (k) printf("%lld\n",k);
            else{
                if ((b/(a-1))&1) printf("%lld\n",a);
                else printf("%lld\n",a-1);
            }
        }
    }
    return 0;
}