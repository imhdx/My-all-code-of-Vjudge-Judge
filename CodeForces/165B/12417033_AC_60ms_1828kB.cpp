#include<stdio.h>
int main()
{
    long long int n,k;
    long long int l=0,r=999999999,s=0,mid;
    long long int i,j,f;
    scanf("%lld%lld",&n,&k);
    for (j=0;j<3000;j++)
    {
        mid=(l+r)/2;
        f=mid;
        s=0;
        while (!(f==0))
        {
            s=s+f;
            f=f/k;
        }
        if (s>=n) r=mid;
        else l=mid;
    }
    printf("%lld\n",r);
    return 0;
}
