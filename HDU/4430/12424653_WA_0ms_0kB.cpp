#include<stdio.h>
long long int pow(long long int a,long long int b)
{
    long long s=1,i;
    for (i=0;i<b;i++)
        s=s*a;
    return s;
}
int main()
{
    long long int s,mid,ll,rr,n,k,i,j,oo,r;
    while (scanf("%lld",&n)!=EOF)
    {
        r=1;
        k=999999999999;
        for (oo=1;oo<=50;oo++)
        {
            ll=2;
            rr=n;
            while (ll<=rr)
            {
                mid=(ll+rr)/2;
                s=mid*(pow(mid,oo)-1)/(mid-1);
                if (s==n||s==n-1)
                {
                    if (oo*mid<r*k)
                    {
                        r=oo;
                        k=mid;
                    }
                    break;
                }
                else if (s>n) rr=mid-1;
                else ll=mid+1;
            }
        }
        printf("%lld %lld\n",r,k);
    }
    return 0;
}
