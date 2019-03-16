#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}
int main()
{
    //printf("%d\n",-1/3);
    int T;
    int t=1;
    scanf("%d",&T);
    while (T--)
    {
        long long a,b,c,d,p,m;
        scanf("%lld%lld%lld%lld%lld%lld",&a,&b,&c,&d,&p,&m);
        long long summ=(b-a+1)*(d-c+1);
        if (a>c)
        {
            swap(a,c);
            swap(b,d);
        }

        m=m-(a+c)/p*p;
        m=m-p;

        long long p1=a+c,p2=min(a+d,b+c),p3=max(a+d,b+c),p4=b+d;
        //printf("%lld %lld %lld %lld\n",p1,p2,p3,p4);
        long long ge=(p2-m)/p-(p1-1-m)/p;
        //printf("ge=%lld  ",ge);
        long long shou=(p1-m)/p;
        while (shou*p+m<p1) shou++;

        shou=shou*p+m-p1+1;
        //printf("shou=%lld  ",shou);
        long long ans=0;


        if (p1<=p2-1) ans+=(ge)*(shou+shou+ge*p-p)/2;
        //printf("ans=%lld\n",ans);
        if (p2<=p3) ans+=(p2-p1+1)*((p3-m)/p-(p2-1-m)/p);
        //printf("ans=%lld\n",ans);
        ge=(p4-m)/p-(p3-m)/p;
        //printf("ge=%lld  ",ge);

        shou=(p3-m)/p;
        while (shou*p+m<=p3) shou++;
        shou=p4-(shou*p+m)+1;

        //printf("shou=%lld  ",shou);

        printf("Case #%d: ",t++);
        if (p3+1<=p4) ans+=(ge)*(shou+shou-ge*p+p)/2;
        printf("%lld/%lld\n",ans/gcd(ans,summ),summ/gcd(ans,summ));
        //printf("%lld\n",ans);
        //printf("%lld\n",summ);
    }
    return 0;
}
