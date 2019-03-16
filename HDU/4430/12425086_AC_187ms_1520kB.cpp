#include<stdio.h>
#include<math.h>
int main()
{
    long long int s,ss,mid,ll,rr,n,k,i,j,oo,r;
    while (scanf("%lld",&n)!=EOF)
    {
        r=1;
        k=n;
        for (oo=1;oo<=60;oo++)
        {
            ll=2;
            rr=(long long int)pow(n,1.0/oo);
            while (ll<=rr)
            {
                mid=(ll+rr)/2;
                s=0;
                ss=1;
                for (i=0;i<oo;i++)
                {
                    ss=ss*mid;
                    s=s+ss;
                }
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
