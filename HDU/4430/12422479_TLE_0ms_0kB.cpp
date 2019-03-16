#include<math.h>
#include<stdio.h>
long long int n;
long long int r,k;
long long int f(long long int k)
{
    if ((long long int)(log10(n*(k-1)+k)/log10(k))==(log10(n*(k-1)+k)/log10(k)))
        return k*((log10(n*(k-1)+k)/log10(k))-1);
    else if ((long long int)(log10((n-1)*(k-1)+k)/log10(k))==(log10((n-1)*(k-1)+k)/log10(k)))
        return k*((log10((n-1)*(k-1)+k)/log10(k))-1);
    return -1;
}
int main()
{
    long long int d1,d2,min,t,i,l,r,mid,midmid,tt;
    while (scanf("%lld",&n)!=EOF)
    {
        l=2;
        r=n;
        min=999999999999;
        t=0;
        for (i=2;i<=n;i++)
        {

            tt=f(i);
            if (tt==-1)
                continue;
            if (min>tt) {min=tt;t=i;}
            break;
        }


        printf("%lld %lld\n",f(t)/t,t);
    }
    return 0;
}
