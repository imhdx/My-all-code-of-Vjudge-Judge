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
        /*
        m=m-(a+c)/p*p;
        m=m-p;
        long long p1=a+c,p2=min(a+d,b+c),p3=max(a+d,b+c),p4=b+d;
        long long ge=(p2-m)/p-(p1-1-m)/p;
        long long shou=(p1-m)/p;
        while (shou*p+m<p1) shou++;

        shou=shou*p+m-p1+1;
        long long ans=0;


        if (p1<=p2-1) ans+=(ge)*(shou+shou+ge*p-p)/2;
        if (p2<=p3) ans+=(p2-p1+1)*((p3-m)/p-(p2-1-m)/p);
        ge=(p4-m)/p-(p3-m)/p;

        shou=(p3-m)/p;
        while (shou*p+m<=p3) shou++;
        shou=p4-(shou*p+m)+1;


        printf("Case #%d: ",t++);
        if (p3+1<=p4) ans+=(ge)*(shou+shou-ge*p+p)/2;
        printf("%lld/%lld\n",ans/gcd(ans,summ),summ/gcd(ans,summ));
        */
        long long p1=a+c,p2=min(a+d,b+c),p3=max(a+d,b+c),p4=b+d;
        //printf("p1=%lld p2=%lld p3=%lld p4=%lld \n",p1,p2,p3,p4);
        long long ans=0;
        long long tou=(((p1-m)%p+p)%p);
        long long p11,p22,p33,p44;
        if (tou!=0) p11+=p1-tou;
        else
            p11=p1;
        //printf("%lld\n",p11);
        tou=((p2-m)%p+p)%p;
        if (tou==0)
            p22=p2-p;
        else
            p22=p2-tou;
        //printf("%lld\n",p22);
        if (p11<=p22&&p11>=p1&&p22<p2)
            ans+=(p22-p1+p11-p1+2)*((p22-p11)/p+1)/2;

        //printf("ans1=%lld\n",ans);
        //printf("p22=%lld\n",p22);
        p22+=p;
        tou=((p3-m)%p+p)%p;
        if (tou==0)
            p33=p3;
        else
            p33=p3-tou;
        //printf("%lld %lld",p22,p33);
        if (p22<=p33&&p22>=p2&&p33<=p3)
            ans+=(p2-p1+1)*((p22-p11)/p+1);
        //printf("ans2=%lld\n",(p2-p1+1)*((p22-p11)/p+1));
        //printf("ans=%lld\n",ans);
        p33+=p;
        tou=((p4-m)%p+p)%p;
        if (tou==0) p44=p4;
        else
            p44=p4-tou;
        //printf("p33=%lld p44=%lld\n",p33,p44);
        if (p33<=p44&&p33>=p3+1&&p44<=p4)
        {
            ans+=(p4-p44+1+p4-p33+1)*((p44-p33)/p+1)/2;
            //printf(" %lld\n",(p4-p44+1+p4-p33+1)*((p44-p33)/p+1)/2);
        }
        //printf("%lld\n",ans);
        printf("Case #%d: ",t++);
        printf("%lld/%lld\n",ans/gcd(ans,summ),summ/gcd(ans,summ));
    }
    return 0;
}
