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
            b-=a;
            long long k=b%(a-1);
            if (k==0){
                if ((b/(a-1))&1) printf("%lld\n",a-1);
                else printf("%lld\n",a);
            }
            else printf("%lld\n",k);
        }
    }
    return 0;
}//