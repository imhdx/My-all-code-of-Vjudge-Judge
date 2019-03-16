#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b)
{
    return b==0?a:gcd(b,a%b);
}
int main()
{
    int T;
    int t=1;
    scanf("%d",&T);
    while (T--)
    {
        long long a,b,n;
        scanf("%lld%lld%lld",&n,&a,&b);
        long long ggg=gcd(a,b);
        long long ans=((1-a)%ggg+ggg)%ggg;
        //printf("ans=%lld\n",ans);
        //printf("ggg=%lld\n",ggg);
        long long a1;
        if (ans==0) a1=1;
        else a1=1+(ggg-ans);
        long long a2;
        ans=((n-a)%ggg+ggg)%ggg;
        if (ans==0) a2=n;
        else a2=n-ans;
        printf("Case #%d: ",t++);
        //printf("a1=%lld a2=%lld\n",a1,a2);
        if (((a2-a1)/ggg)&1)
            printf("Iaka\n");
        else
            printf("Yuwgna\n");
    }
    return 0;
}
