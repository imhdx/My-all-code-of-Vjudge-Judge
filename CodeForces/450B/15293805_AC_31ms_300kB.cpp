#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
long long int ju[4];
long long int res[4];
void jupoww(long long int ju[],int b)
{
    res[0]=1;
    res[1]=0;
    res[2]=0;
    res[3]=1;
    while (b>0)
    {
        if (b&1)
        {
            long long int tmp[4];
            tmp[0]=((res[0]*ju[0])%mod+(res[1]*ju[2])%mod)%mod;
            tmp[1]=((res[0]*ju[1])%mod+(res[1]*ju[3])%mod)%mod;
            tmp[2]=((res[2]*ju[0])%mod+(res[3]*ju[2])%mod)%mod;
            tmp[3]=((res[2]*ju[1])%mod+(res[3]*ju[3])%mod)%mod;
            for (int i=0; i<4; i++)
                res[i]=tmp[i];
        }
        long long int tmp[4];
        tmp[0]=((ju[0]*ju[0])%mod+(ju[1]*ju[2])%mod)%mod;
        tmp[1]=((ju[0]*ju[1])%mod+(ju[1]*ju[3])%mod)%mod;
        tmp[2]=((ju[2]*ju[0])%mod+(ju[3]*ju[2])%mod)%mod;
        tmp[3]=((ju[2]*ju[1])%mod+(ju[3]*ju[3])%mod)%mod;
        for (int i=0; i<4; i++)
            ju[i]=tmp[i];
        b=b>>1;
    }
}

int main()
{
    int n;
    long long int a,b;
    scanf("%lld%lld",&a,&b);
    scanf("%d",&n);
    if (n==1)
        printf("%d\n",(a%mod+mod)%mod);
    else if (n==2)
        printf("%d\n",(b%mod+mod)%mod);
    else
    {
        ju[0]=1;
        ju[1]=-1;
        ju[2]=1;
        ju[3]=0;
        jupoww(ju,n-2);
        long long int ans=((res[0]*b)%mod+(res[1]*a)%mod)%mod;
        ans=(ans+mod)%mod;
        printf("%lld\n",ans);

    }


    return 0;
}
